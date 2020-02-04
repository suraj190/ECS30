#include <stdio.h>
#include <ctype.h>

void wordCount(char* file_source) {

  char b;
  char c;
  int count = 0;
  int total = 0;

  FILE *file = fopen(file_source, "r");
  FILE *file1= fopen(file_source,"r");

  if (file == NULL) {
    printf("Error opening file!\n");
    return;
  }

  fscanf(file, "%c", &c);
  fscanf(file1, "%c", &b);

  while (!feof(file)) {

    total++;
    fscanf(file1, "%c", &b);
    if ((isspace(c) || (c == '\n'))) {
      count++;
      if(isspace(b) || b=='\n'){
        count--;
      }
    }
    fscanf(file,"%c",&c);


  }
  if(total>count){
    count++;
  }
  printf("There are %d word(s).\n", count);
}



int main(int argc,char** argv) {

  wordCount(argv[1]);
  return 0;
}
