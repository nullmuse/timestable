#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 


int transmute_char(char *subject); 
char *transmute_int(int subject); 
void draw(char *min, char *max); 


int main(int argc,char *argv[]) { 
   char *min = "1";
   char *max = "10";
    if(--argc) {   
      if(strstr(argv[1],"-h")) {
         printf("%s [ [<min>] <max> ]\n",argv[0]);
         exit(0);
      } 
      else if(argv[2]) {
         min = argv[1]; 
         max = argv[2];
          
         if(transmute_char(min) > transmute_char(max)) { 
           printf("Error: max less than min\n"); 
           exit(1);    
      }
      }
      else {
         max = argv[1];
       
      }

  }

   if(transmute_char(min) <= 0 || transmute_char(max) <= 0) {
            printf("Error: range numbers zero or less\n");
            exit(1);
         }
   if(transmute_char(max) > 100) { 
      printf("Error: max range of 100 exceeded\n"); 
      exit(1); 
     }


   draw(min,max); 
   return 0; 

}


int transmute_char(char *subject) {
   int len = strlen(subject) - 1;
   int i,new = 0; 
   for(i = 1;len >= 0;--len,i *= 10) {
      if(subject[len] > 0x39 || subject[len] < 0x30) { 
         printf("Error: Non-integer\n"); 
         exit(2); 
      } 
      new += (subject[len] - 0x30) * i;
   } 
   return new; 
}  

char *transmute_int(int subject) { 
   int container = 0;
   int count = 5;
   int check = 0;
   char *new = malloc(5);
   memset(new,0,5);  
   while(subject) {
      container = subject % 10; 
      subject /= 10; 
      new[--count] = container + 0x30;
      check++;        
   } 
   if(count) { 
   memcpy(new,new + count,6 - count);      
   }
   return new;
}
  


int string_graft(char *patient,char *graft,int step) {
   int len = strlen(graft); 
   int i = 0; 
   int index = 0; 
   for(;i < len;++i) {  
      patient[index++] = graft[i];  
   }  
   return step > (len + 1) ? step + 1 : (step + 1);   
}    
   

void draw(char *min,char *max) { 
   int start = transmute_char(min); 
   int stop = transmute_char(max); 
   int tmp,placer,i,step = 0;
   char *intbuf;
   char *placement;   
   int size = stop * stop;
   intbuf = transmute_int(size + 1);
   step = strlen(intbuf);  
   free(intbuf); 
   placement = malloc(size + 1);
   memset(placement,' ',size);
   placement[size + 1] = '\0';
   placer = 0;
   placer += string_graft((placement + placer),"*",step);
   for(i = start; i <= stop; ++i) {
      intbuf = transmute_int(i);
      placer += string_graft((placement + placer),intbuf,step);
      free(intbuf); 
   }
   placement[placer] = '\0';
   printf("%s\n",placement);
   for(i = start;i <= stop;++i) {
      placer = 0; 
      memset(placement,' ',size - 1);
      intbuf = transmute_int(i);
      placer += string_graft((placement + placer),intbuf,step);
      free(intbuf); 
      for(tmp = start; tmp <= stop; ++tmp) {
         intbuf = transmute_int(tmp * i);
         placer += string_graft((placement + placer),intbuf,step);
         free(intbuf); 
      } 
      placement[placer] = '\0';
      printf("%s\n",placement); 
      }


   free(placement);  

}
          


