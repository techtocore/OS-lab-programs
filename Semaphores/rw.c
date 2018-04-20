
Writer:

do {      wait(rw_mutex); 
               ...
              /* writing is performed */ 
               ... 
          signal(rw_mutex); 
     } while (true);


Reader:

do {      wait(mutex);
           read_count++;
           if (read_count == 1) 
              wait(rw_mutex); 
           signal(mutex); 
               ...
               /* reading is performed */ 
               ... 
           wait(mutex);           
           read count--;           
           if (read_count == 0) 
                signal(rw_mutex); 
           signal(mutex); 
       } while (true);
