#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 


int transmute_char(char *subject); 


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
   printf("%i\n",transmute_char(max)); 
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
