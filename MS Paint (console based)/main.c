#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quit(struct canvas *structPointer) {

  for (int i = 0; i < structPointer->row; i++) {
    free(structPointer->board[i]);                // frees the rows of pointers in paint.board
  }
  free(structPointer->board);                     // frees the double pointer paint.board
  structPointer->board = NULL;
  exit(0);
}

void printCurrentCanvas(struct canvas *structPointer) {

  for (int i = 0; i < structPointer->row; i++) {
    structPointer->board[i] = (char *) malloc(structPointer->col * sizeof(char));
  }

  for (int i = 0; i < structPointer->row; i++) {  // printing board

    printf("\n");
    printf("%d ", structPointer->row - i - 1);

    for (int j = 0; j < structPointer->col; j++) {

      structPointer->board[i][j] = 42;
      printf("%c ", structPointer->board[i][j]);

    }

  }
  printf("\n");
  printf("  ");
  for (int i = 0; i < structPointer->col; i++) {

    printf("%d ", i);
  }
  printf("\n");

}

void deleteColumn(struct canvas *structPointer, int colDelete) {

  int num_row = structPointer->row;
  int num_col = structPointer->col;

  if (colDelete == num_col - 1) {  //checks whether column selected is last column

    structPointer->col = (structPointer->col) - 1;

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             qvf      structPointer->board[i] =
          realloc(structPointer->board[i], sizeof(char) * structPointer->col);  //shrinking board after delete
    }
  } else {

    for (int i = 0; i < num_row; i++) {                //sets all elements of the selected column to NULL
      structPointer->board[i][colDelete] == NULL;
    }

    for (int i = 0; i < num_row; i++) {
      for (int j = colDelete; j >= 0; j--) {

        structPointer->board[i][colDelete] =
            structPointer->board[i][abs(colDelete - 1)]; //moves elements of cols by 1 to right
        structPointer->board[i][0] = NULL; //sets first column to NULL after moving everything to right
      }
    }

    for (int i = 0; i < num_row; i++) {
      structPointer->board[i] = realloc(structPointer->board[i], sizeof(char) * structPointer->col);
    }

  }

  printCurrentCanvas(structPointer);

}

void deleteRow(struct canvas *structPointer, int rowDelete) {

  int num_rows = structPointer->row;
  int convertRow =
      abs(rowDelete - num_rows) - 1;  // converts row input to 2d array index(rowDelete=4 then convertRow=5)

  if (rowDelete == num_rows - 1) {
    free(structPointer->board[abs(rowDelete - num_rows) - 1]); //deletes row if row chosen to be deleted is on top
    structPointer->row = (structPointer->row) - 1;          // updates total number of rows in paint struct
    num_rows--;
  } else {
    for (int i = convertRow; i >= 0; i--) {
      structPointer->board[convertRow - 1] =
          structPointer->board[convertRow];   //moves down all rows above rowDelete by 1
    }

    free(structPointer->board[0]); //  delete the top most row and use realloc

    structPointer->row = (structPointer->row) - 1;       // updating total number of rows in paint struct
  }

  //updateCanvas(structPointer);    // we can either use updateCanvas to keep updating or return it back to makeCanvas

}

void deleteTemp(struct canvas *structPointer, char temp1, int temp2) {

  int selected = temp2;

  if (temp1 == 'r') {
    deleteRow(structPointer, selected);
  } else {
    deleteColumn(structPointer, selected);
  }
}

void getInput(struct canvas *structPointer) {
  char s[50];
  printf("Enter your command: ");
  scanf("%10[0-9a-zA-Z ]", s);
  printf("size: %s\n", s);

  char temp[50];
  int j = 0;
  //copies contents to new list
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] != ' ') {
      temp[j] = s[i];
      j++;

    }

  }
  deleteTemp(structPointer, temp[1], temp[2] - '0');

  while (temp[0] != 'q') {
    if (j == 5 && temp[0] == 'w') {
      write(temp[1] - '0', temp[2] - '0', temp[3] - '0', temp[4] - '0');
    } else if (j == 3 && temp[0] == 'e') {
      erase(temp[1] - '0', temp[2] - '0');
    } else if (j == 3 && temp[0] == 'r') {
      resize(temp[1] - '0', temp[2] - '0');
    } else if (j == 3 && temp[0] == 'a') {
      add(temp[1], temp[2] - '0');
    } else if (j == 3 && temp[0] == 'd') {
      deleteTemp(structPointer, temp[1], temp[2] - '0');
    } else {
      printf("Invalid Input");
    }
  }

  quit(structPointer);

  void write(int row1, int col1, int row2, int col2) {
    printf("writing\n");
    printf("row1: %d\n", row1);
    printf("col1: %d\n", col1);
    printf("row2: %d\n", row2);
    printf("col2: %d\n", col2);
  }
  void erase(int row1, int col1) {
    printf("erasing\n");
    printf("row1: %d\n", row1);
    printf("col1: %d\n", col1);
  }

  void resize(int row, int col) {
    printf("resizing\n");
    printf("row %d\n", row);
    printf("col %d\n", col);
  }
  void add(char cr, int num) {
    printf("adding\n");
    printf("char %c\n", cr);
    printf("num %d\n", num);
  }
  void deleteTemp(char cr, int num) {
    printf("deleting\n");
    printf("char %c\n", cr);
    printf("num %d\n", num);
  }
}

  void makeCanvas(int num_row, int num_col) {

    typedef struct canvas_struct {  // making struct for canvas

      char **board;
      int row;
      int col;
    } canvas;

    canvas paint;          // initializing paint variable of "canvas" struct
    paint.row = num_row;
    paint.col = num_col;
    paint.board = (char **) malloc(paint.row * sizeof(char *)); // initializing board


    printf("No of rows = %d", paint.row);
    canvas *structPointer = (canvas *) malloc(sizeof(canvas));   // initializing a struct pointer to canvas
    structPointer = &paint; //making structPointer point to paint



    for (int i = 0; i < paint.row; i++) {
      paint.board[i] = (char *) malloc(paint.col * sizeof(char));
    }

    for (int i = 0; i < paint.row; i++) {  // printing board

      printf("\n");
      printf("%d ", paint.row - i - 1);

      for (int j = 0; j < paint.col; j++) {

        paint.board[i][j] = 42;
        printf("%c ", paint.board[i][j]);

      }

    }
    printf("\n");
    printf("  ");
    for (int i = 0; i < paint.col; i++) {

      printf("%d ", i);
    }
    printf("\n");

    getInput(structPointer);

  }

  void save_file(struct canvas *structPointer, char *file_name) {

    FILE *fp = NULL;
    int num_row = structPointer->row;
    int num_col = structPointer->col;
    char **board = structPointer->board;
    char *fileName = file_name;
    fp = fopen("%s", "w");

    for (int i = 0; i < num_row; i++) {  // printing board

      printf("\n");
      printf("%d ", num_row - i - 1);

      for (int j = 0; j < num_col; j++) {

        board[i][j] = 42;
        printf("%c ", board[i][j]);

      }

    }
    printf("\n");
    printf("  ");
    for (int i = 0; i < num_col; i++) {

      printf("%d ", i);
    }
    printf("\n");

    fclose(fp);

  }

  void load_file(char *file_name) {

    typedef struct load_struct {
      int row;
      int col;
      char **board;
    } load;

    FILE *fp = fopen(file_name, "r");

  }

  void print_help() {

    printf("Commands:\n");
    printf("Help: h\n");
    printf("Quit: q\n");
    printf("Draw line: w row_start col_start row_end col_end\n");
    printf("Resize: r num_rows num_cols\n");
    printf("Add row or column: a [r | c] pos\n");
    printf("Delete row or column: d [r | c] pos\n");
    printf("Erase: e row col\n");
    printf("Save: s file_name\n");
    printf("Load: l file_name\n");
  }

  void commandLineValidation(int argc, char *argv1, char *argv2) {  // checking whether Command line args are valid

    int row, col;                      // this function passes directly to makeCanvas which creates board (makeCanvas.h)

    if (argc > 3 || argc < 3) {
      printf("Wrong number of command line arguements entered.\n");
      printf("Usage: ./paint.out [num_rows num_cols]\n");
      makeCanvas(10, 10);
    } else if (argv1 < 49 || argv1 > 57) {     // checking whether argv[1] is a digit character
      printf("The number of rows is not an integer.\n");
      makeCanvas(10, 10);
    } else if (argv2 < 49 || argv2 > 57) {     // checking whether argv[1] is a digit character
      printf("The number of columns is not an integer.\n");
      makeCanvas(10, 10);
    } else {
      sscanf(argv1, "%d", &row);
      sscanf(argv2, "%d", &col);

      if (row < 1) {
        printf("The number of rows is less than 1.\n");
        makeCanvas(10, 10);
      } else if (col < 1) {
        printf("The number of columns is less than 1.\n");
        makeCanvas(10, 10);
      } else {
        makeCanvas(row, col);
      }
    }
  }

  int main(int argc, char **argv) {

    commandLineValidation(argc, argv[1], argv[2]); // validation for optional command line arguments


    return 0;
  }