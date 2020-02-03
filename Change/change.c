#include <stdio.h>

int main() {

  int withDraw;
  int hundred = 0;
  int fifty = 0;
  int twenty = 0;
  int ten = 0;
  int five = 0;
  int one = 0;

  printf("Please enter the amount of money you wish to withdraw:  ");
  scanf("%d", &withDraw);

  if (withDraw >= 100) {
    hundred = withDraw / 100;
    withDraw = withDraw - hundred * 100;
  }

  if (withDraw >= 50) {
    fifty = withDraw / 50;
    withDraw = withDraw - fifty * 50;
  }

  if (withDraw >= 20) {
    twenty = withDraw / 20;
    withDraw = withDraw - twenty * 20;
  }

  if (withDraw >= 10) {
    ten = withDraw / 10;
    withDraw = withDraw - ten * 10;
  }

  if (withDraw >= 5) {
    five = withDraw / 5;
    withDraw = withDraw - five * 5;
  }

  if (withDraw >= 1) {
    one = withDraw / 1;
  }

  printf("You received %d hundred(s)\n", hundred);
  printf("You received %d fifty(s)\n", fifty);
  printf("You received %d twenty(s)\n", twenty);
  printf("You received %d ten(s)\n", ten);
  printf("You received %d five(s)\n", five);
  printf("You received %d one(s)\n", one);

}





