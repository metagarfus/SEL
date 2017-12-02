#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define INI_LINE_MAX 2048

typedef void (*on_ini_open_error_f) (void *opaque, const char *filename);
typedef void (*on_ini_open_f) (void *opaque, const char *filename);
typedef void (*on_ini_close_f) (void *opaque, const char *filename);
typedef void (*on_ini_format_error_f) (void *opaque, const char *filename, int line);
typedef void (*on_ini_section_start_f) (void *opaque, const char *section);
typedef void (*on_ini_property_read_f) (void *opaque, const char *property, const char *value);

typedef struct {
    void *opaque;
    on_ini_open_error_f on_open_error;
    on_ini_open_f on_open;
    on_ini_close_f on_close;
    on_ini_format_error_f on_format_error;
    on_ini_section_start_f on_section_start;
    on_ini_property_read_f on_property_read;
} ini_read_events_t;

#define CALL_EVENT(SOURCE, EVENT, ...) { \
    if (SOURCE.EVENT != NULL)\
        SOURCE.EVENT(SOURCE.opaque, __VA_ARGS__);\
}

#define IS_WHITE_SPACE(C) ((C) == ' ' || (C) == '\t' || (C) == '\n' || (C) == '\r') 

static char *consume_white_space(char *line) {
    int i;
    for(i = 0; IS_WHITE_SPACE(line[i]); i++)
        ;
    return line + i;
}

static void consume_white_space_r(char *start, char *end) {
    for(; IS_WHITE_SPACE(*end) && end >= start; end--)
        ;
    *(end + 1) = '\0';
}

static int file_ini_read_section_start(const char *filename, int line_number, char *line_ptr, ini_read_events_t events) {
    line_ptr = consume_white_space(line_ptr + 1);
    char *ptr = strchr(line_ptr, ']');
    if (ptr == NULL || consume_white_space(ptr + 1)[0] != '\0') {
        CALL_EVENT(events, on_format_error, filename, line_number);
        return 0;
    }
    consume_white_space_r(line_ptr, ptr - 1);
    CALL_EVENT(events, on_section_start, line_ptr);
    return 1;
}

static int file_ini_read_line(const char *filename, int line_number, char *line_ptr, ini_read_events_t events) {
    char *ptr = strchr(line_ptr, ':');
    if (ptr == NULL) {
        CALL_EVENT(events, on_format_error, filename, line_number);
        return 0;
    }
    consume_white_space_r(line_ptr, ptr - 1);
    ptr = consume_white_space(ptr + 1);
    consume_white_space_r(ptr, ptr + strlen(ptr) - 1);
    CALL_EVENT(events, on_property_read, line_ptr, ptr);
    return 1;
}

static void file_ini_read(const char *filename, FILE *fp, ini_read_events_t events) {
    char line[INI_LINE_MAX], *line_ptr;
    int line_number;
    for (line_number = 1; fgets(line, INI_LINE_MAX, fp) != NULL; line_number++) {
        line_ptr = consume_white_space(line);
        //Ignore empty lines
        if (line_ptr[0] == '\0')
            continue;
        if (line_ptr[0] == '[') {
            if (!file_ini_read_section_start(filename, line_number, line_ptr, events))
                return;
        } else {
            if (!file_ini_read_line(filename, line_number, line_ptr, events))
                return;
        }
    }
}

void file_ini_reader(const char *filename, ini_read_events_t events) {
    FILE * const fp = fopen(filename, "r");    
    if (fp == NULL) {
        CALL_EVENT(events, on_open_error, filename);
        return;
    } 
    CALL_EVENT(events, on_open, filename);
    file_ini_read(filename, fp, events);
    fclose(fp);
    CALL_EVENT(events, on_close, filename);
}




void on_ini_open_error (void *opaque, const char *filename) {
    printf("Error opening file %s\n", filename);
}

void on_ini_open(void *opaque, const char *filename) {
    printf("Opened file %s\n", filename);
}

void on_ini_close (void *opaque, const char *filename) {
    printf("Closed file %s\n", filename);
}

void on_ini_format_error (void *opaque, const char *filename, int line) {
    printf("Format error %s %d\n", filename, line);
}

void on_ini_section_start (void *opaque, const char *section) {
    printf("Section start |%s|\n", section);
}

void on_ini_property_read (void *opaque, const char *property, const char *value) {
    printf("Porperty |%s| = |%s|\n", property, value);
}



int main(int argc, char **argv) {
    ini_read_events_t events = {
        NULL,
        on_ini_open_error,
        on_ini_open,
        on_ini_close,
        on_ini_format_error,
        on_ini_section_start,
        on_ini_property_read
    };   
    file_ini_reader(argv[1], events);
}