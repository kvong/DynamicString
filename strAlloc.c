#include <stdio.h>
#include <stdlib.h>

int main (){
  int buffer = 10;
  char *string = malloc(buffer * sizeof(char));;
  if (!string){
    printf("Error allocating string.\n");
    exit(EXIT_FAILURE);
  }
  int c,  count = 0;
  printf("Please enter a string: ");
  while (1){
    c = getchar();
    if (c == EOF || c == '\n'){
      string[count] = '\0';
      break;
    }
    else{
      string[count] = c;
    }
    count++;
    if (count >= buffer){
      buffer = buffer * 2;
      string = realloc(string, buffer);
     if (!buffer){
       printf("Error reallocating buffer.");
       exit(EXIT_FAILURE);
     }
    }
  }
  printf("%s\n",string);
  free(string);
  return 0;
}
