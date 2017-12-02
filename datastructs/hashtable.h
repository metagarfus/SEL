#ifndef DATA_STRUCT_HASHTABLE_H
#define DATA_STRUCT_HASHTABLE_H

typedef struct hashtable hashtable;
void hashtable_destroy(hashtable *t);
typedef struct hashtable_entry hashtable_entry;
hashtable_entry *hashtable_body_allocate(unsigned int capacity);
hashtable *hashtable_create();
void hashtable_remove(hashtable *t, const char *key);
void hashtable_resize(hashtable *t,unsigned int capacity);
void hashtable_set(hashtable *t, const char *key,void *value);
void *hashtable_get(hashtable *t, const char *key);
unsigned int hashtable_find_slot(hashtable *t, const char *key);
unsigned long hashtable_hash(const char *str);
struct hashtable {
	unsigned int size;
	unsigned int capacity;
	hashtable_entry* body;
};
struct hashtable_entry {
	const char* key;
	void* value;
};
#define INTERFACE 0
#endif /*DATA_STRUCT_HASHTABLE_H*/ 
