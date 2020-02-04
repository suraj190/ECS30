//
// Created by Suraj M on 11/27/17.
//

#include "read_lines.h"
#include  <stdlib.h>
#include  <stdbool.h>

char *read_a_line(FILE *fp) {

  char *line = NULL;
  int num_chars = 0;
  char c;

  fscanf(fp, "%c", &c);

  while (!feof(fp)) {

    num_chars++;

    line = (char *) realloc(line, num_chars * sizeof(char));
    line[num_chars - 1] = c;

    if (c == '\n') {
      break;
    }
    fscanf(fp, "%c", &c);
  }

  if (line != NULL) {
    line = realloc(line, (num_chars + 1) * sizeof(char));
    line[num_chars] = '\0';
  }

  return line;
}

void read_lines(FILE *fp, char ***lines, int *num_lines) {

  char *line = NULL;
  while (true) {
    line = read_a_line(fp);
    if (line == NULL) {
      break;
    }
    *num_lines = (*num_lines) + 1;
    *lines = (char **) realloc(*lines, (*num_lines) * sizeof(char *));
    (*lines)[*num_lines - 1] = line;

  }
}