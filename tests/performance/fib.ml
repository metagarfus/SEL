let rec fat x = 
              if x <= 1 
              then 1 
              else fat (x-1) 
                    + fat (x -2)
in
print_int (fat 45) ;; print_string "\n"