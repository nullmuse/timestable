#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 


int transmute_char(char *subject); 
char *transmute_int(int subject); 

int main(int argc, char *argv[]) { 
   char *min = "1";
   char *max = "10";
    if(--argc) {   
      if(strstr(argv[1],"-h")) {
         printf("You need help or what?\n");
         exit(0);
      } 
      else if(argv[2]) {
         min = argv[1]; 
         max = argv[2];  
      }
      else {
         max = argv[1];  
       
      }
  }
   int maxer = transmute_char(max); 
   printf("%i\n",transmute_char(max)); 
   printf("%s\n",transmute_int(maxer));
   return 0; 

}


int transmute_char(char *subject) {
   int len = strlen(subject) - 1;
   int i,new = 0; 
   for(i = 1;len >= 0;--len,i *= 10) { 
      new += (subject[len] - 0x30) * i;
   } 
   return new; 
}  

char *transmute_int(int subject) { 
   char *new = malloc(5);
   memset(new,0,5); 
   int container = 0;   
   int count = 5; 
   while(subject) { 
      container = subject % 10; 
      subject /= 10; 
      new[--count] = container + 0x30; 
      if (count < 0)
         break;       
   }
   new += count;   
   return new; 
}



