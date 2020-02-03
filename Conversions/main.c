#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

bool isValidInput(const int numArgsNeeded, const int numArgsRead, const bool isLastElementOnLine) {

  char lastCharacterOnLine;

  // did we read everything we needed to read?
  bool correctFormat = (numArgsRead == numArgsNeeded);

  if (isLastElementOnLine) {  // if this is supposed to be the last thing on the line
    // check that it was by reading one more character
    // and seeing it it a newline (the end of the line)
    scanf("%c", &lastCharacterOnLine);
    correctFormat = correctFormat && lastCharacterOnLine == '\n';
  }
  return correctFormat;
}

double getValidDouble(const bool isLastElementOnLine) {
  const int numArgsNeeded = 1;
  int numArgsRead;
  double num;

  numArgsRead = scanf(" %lf", &num);
  if (isValidInput(numArgsNeeded, numArgsRead, isLastElementOnLine)) {
    return num;
  } else {
    printf("Format Error\n");
    exit(0);
  }
}

char getValidChar(const bool isLastElementOnLine) {
  const int numArgsNeeded = 1;
  int numArgsRead;
  char theCharacter;

  numArgsRead = scanf(" %c", &theCharacter);
  if (isValidInput(numArgsNeeded, numArgsRead, isLastElementOnLine)) {

    return theCharacter;

  } else {
    printf("Format Error\n");
    exit(0);
  }
}


void TempCalc(double temperature,char tempUnit,char newTemperature){
  double temperature2=temperature;
  char tempUnit2=tempUnit;
  char newTemperature2 = newTemperature;
  double final;

  tempUnit2=toupper(tempUnit2);
  newTemperature2=toupper(newTemperature2);

  if(tempUnit2=='C'&& newTemperature2=='F') {
    final = (1.8 * temperature2) + 32;
    printf("%0.2lf%c is %0.2lf%c", temperature2, tempUnit2, final, newTemperature2);
  }

  else if(tempUnit2=='C' && newTemperature2=='K'){
    final = temperature2+273;
    printf("%0.2lf%c is %0.2lf%c", temperature2, tempUnit2, final, newTemperature2);
  }

  else if(tempUnit2=='F' && newTemperature2=='C'){
    final = (temperature2-32)/1.8;
    printf("%0.2lf%c is %0.2lf%c", temperature2, tempUnit2, final, newTemperature2);
  }

  else if(tempUnit2=='F' && newTemperature2=='K'){
    final = ((temperature2-32)/1.8)+273;
    printf("%0.2lf%c is %0.2lf%c", temperature2, tempUnit2, final, newTemperature2);
  }

  else if(tempUnit2=='K' && newTemperature2=='C'){
    final = (temperature2-273);
    printf("%0.2lf%c is %0.2lf%c", temperature2, tempUnit2, final, newTemperature2);
  }

  else if(tempUnit2=='K' && newTemperature2=='F'){
    final = (1.8*(temperature2-273))+32;
    printf("%0.2lf%c is %0.2lf%c", temperature2, tempUnit2, final, newTemperature2);
  }


}


void DistCalc(double distance, char distUnit, char newDistUnit){
  double distance2 = distance;
  char distUnit2 = distUnit;
  char newDistUnit2 = newDistUnit;
  double final;

  distUnit2=toupper(distUnit2);
  newDistUnit2=toupper(newDistUnit2);


  if(distUnit2=='I' && newDistUnit2=='F') {
    final = distance2/12;
    printf("%0.2lf%c is %0.2lf%c", distance2, distUnit2, final, newDistUnit2);
  }

  else if(distUnit2=='I'&& newDistUnit2=='Y') {
    final = distance2/36;
    printf("%0.2lf%c is %0.2lf%c", distance2, distUnit2, final, newDistUnit2);
  }

  else if(distUnit2=='I'&& newDistUnit2=='M') {
    final = distance2/63360;
    printf("%0.2lf%c is %0.2lf%c", distance2, distUnit2, final, newDistUnit2);
  }

  else if(distUnit2=='F' && newDistUnit2=='I') {
    final = distance2*12;
    printf("%0.2lf%c is %0.2lf%c", distance2, distUnit2, final, newDistUnit2);
  }

  else if(distUnit2=='F'&& newDistUnit2=='Y') {
    final = distance2/3;
    printf("%0.2lf%c is %0.2lf%c", distance2, distUnit2, final, newDistUnit2);
  }

  else if(distUnit2=='F'&& newDistUnit2=='M') {
    final = distance2/5280;
    printf("%0.2lf%c is %0.2lf%c", distance2, distUnit2, final, newDistUnit2);
  }

  else if(distUnit2=='Y'&& newDistUnit2=='I') {
    final = distance2*36;
    printf("%0.2lf%c is %0.2lf%c", distance2, distUnit2, final, newDistUnit2);
  }

  else if(distUnit2=='Y'&& newDistUnit2=='F') {
    final = distance2*3;
    printf("%0.2lf%c is %0.2lf%c", distance2, distUnit2, final, newDistUnit2);
  }

  else if(distUnit2=='Y'&& newDistUnit2=='M') {
    final = distance2/1760;
    printf("%0.2lf%c is %0.2lf%c", distance2, distUnit2, final, newDistUnit2);
  }

  else if(distUnit2=='M'&& newDistUnit2=='I') {
    final = distance2*63360;
    printf("%0.2lf%c is %0.2lf%c", distance2, distUnit2, final, newDistUnit2);
  }

  else if(distUnit2=='M'&& newDistUnit2=='F') {
    final = distance2*5280;
    printf("%0.2lf%c is %0.2lf%c", distance2, distUnit2, final, newDistUnit2);
  }

  else if(distUnit2=='M'&& newDistUnit2=='Y') {
    final = distance2*1760;
    printf("%0.2lf%c is %0.2lf%c", distance2, distUnit2, final, newDistUnit2);
  }




}




void newTemp(double temperature, char tempUnit) {
  double temperature2 = temperature;
  char tempUnit2 = tempUnit;
  char newTemperature;

  printf("Enter the new unit type (F, C, or K): ");
  newTemperature = getValidChar(true);

  if (newTemperature == 'K' || newTemperature == 'k' || newTemperature == 'C' || newTemperature == 'c'
      || newTemperature == 'F' ||
      newTemperature == 'f') {

    TempCalc(temperature2, tempUnit2, newTemperature);
  }

  else {
    printf("%c is not a valid temperature type. Ending program", newTemperature);
    exit(0);
  }
}



void newDist(double distance, char distUnit) {
  double distance2 = distance;
  char distUnit2 = distUnit;
  char newDistUnit;

  printf("Enter the new unit type (I,F,Y,M): ");
  newDistUnit = getValidChar(true);

  if (distUnit == 'I' || distUnit == 'F' || distUnit == 'Y' || distUnit == 'M' || distUnit=='m' || distUnit=='i' || distUnit=='f' || distUnit=='y') {
    DistCalc(distance2, distUnit2, newDistUnit);
  }

  else {
    printf("%c is not a valid distance type. Ending program", newDistUnit);
    exit(0);
  }
}









void TempInput(){

  double temperature;
  char tempUnit;

  printf("Enter the temperature followed by its suffix (F, C, or K): ");

  temperature = getValidDouble(false);
  tempUnit = getValidChar(true);

  if(tempUnit=='K'||tempUnit=='k'||tempUnit=='C'||tempUnit=='c'||tempUnit=='F'||
      tempUnit=='f'){

    newTemp(temperature,tempUnit);
  }

  else{

    printf("%c is not a valid temperature type. Ending program",tempUnit);
    exit(0);
  }

}

void DistInput(){

  double distance;
  double distUnit;

  printf("Enter the distance followed by its suffix (I,F,Y,M): ");

  distance = getValidDouble(false);
  distUnit = getValidChar(true);


  if (distUnit == 'I' || distUnit == 'F' || distUnit == 'Y' || distUnit == 'M' || distUnit=='m' || distUnit=='i'
      || distUnit=='f' || distUnit=='y'){
    newDist(distance,distUnit);
  }

  else {

    printf("%c is not a valid distance type. Ending program", distUnit);
    exit(0);
  }
}




void userChoice(char input){
  if(input=='T' || input=='t') {
    TempInput();
  }

  else if(input=='D' || input=='d') {
    DistInput();
  }

  else{
    printf("Unknown conversion type %c chosen. Ending program.",input);
    exit(0);
  }
}



int main() {

  char input;

  printf("Pick the type of conversion that you would like to do.\n"
             "T or t for temperature\n"
             "D or d for distance\n"
             "Enter your choice:");



  input = getValidChar(true);
  userChoice(input);


  return 0;




}


