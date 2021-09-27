#include <iostream>
#include <fstream>
#include <string>
#define SIZE 1000

int main(int argc, char *argv[]) {

  // Read the source file, TO-DO: Let user specify filename
  //https://stackoverflow.com/questions/2912520/read-file-contents-into-a-string-in-c
  std::ifstream ifs("tests/5spades.b");
  std::string code( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
  //std::cout << content;

  // Initialize variables for later use
  int arr[SIZE]; // Array that stores memory cell values
  int *p = &arr[0]; // Pointer to access memory cell values
  char *inpptr = &code.at(0); // Pointer to iterate through brainfuck code

  for ( int i = 0; i < 1000; i++ ) { // Initialize memory values with zeroes
    arr[i] = 0;
  }

  //std::cout << "start: " << &arr[0] << " end: " << &arr[SIZE-1] << "\n"; //for debugging

  //if ( c != 32 && c != 10 ) { // probably not needed with the switch case

  // Actual processing of bf code starts here and ends when code pointer reaches end of code string
  while (inpptr != &code.at(code.length() -1)) {
    switch (*inpptr) {
      // >
      case 62:
        if ( p == &arr[SIZE -1] )
          p = &arr[0];
        else
          p++;
        //std::cout << p << " - " << &arr[0] << " - ";
        break;

      // <
      case 60:
        if ( p == &arr[0] )
          p = &arr[SIZE -1];
        else
          p--;
        //std::cout << p << " - " << &arr[0] << " - ";
        break;

      // +
      case 43:
        if (*p >= 255) {
          *p = 0;
        }
        else {
          *p += 1;
        }
        //printf("plus\n");
        break;

      // -
      case 45:
        if (*p <= 0) {
          *p = 255;
        }
        else {
          *p -= 1;
        }
        //printf("minus\n");
        break;

      // .
      case 46:
        //putchar(*p);
        //printf("\n");
        //printf("print: %d\n", *p);
        std::cout << (char) *p;
        break;

      // ,
      case 44:
        //std::cout << getchar();
        break;

      // [
      case 91:
        if (*p == 0){
          int counter = 1;
          while (counter > 0) {
            //std::cout << "counter [ " << counter;
            inpptr++;
            if (*inpptr == '[')
              counter++;
            else if (*inpptr == ']')
              counter--;
          }
        }
        break;

      // ]
      case 93:
        if (*p != 0){
          int counter = 1;
          while (counter > 0){
            //std::cout << "counter ] " << counter << " " /*<< *p << " "*/ << *inpptr << "\n";
            inpptr--;
            if (*inpptr == ']') {
              //std::cout << "increasing counter";
              counter++;
            }
            else if (*inpptr == '[') {
              //std::cout << "decreasing counter";
              counter--;
            }
          }
        }
        break;
    }
    //std::cout << "cells: " << arr[0] << " " << arr [1] << " " << arr[2] << " char: " << *inpptr << "\n";

    inpptr++;
  }

  //std::cout << "current address: " << p << "\n";
  std::cout << "\n";
  return 0;
}
