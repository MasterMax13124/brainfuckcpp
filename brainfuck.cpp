#include <iostream>
#include <fstream>
#include <string>
#define SIZE 1000

int main(int argc, char *argv[]) {

  // Read the source file, TO-DO: Let user specify filename
  //https://stackoverflow.com/questions/2912520/read-file-contents-into-a-string-in-c
  std::ifstream ifs("tests/outputtest.b");
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
        *p += 1;
        //printf("plus\n");
        break;

      // -
      case 45:
        *p -= 1;
        //printf("minus\n");
        break;

      // .
      case 46:
        putchar(*p);
        printf("\n");
        //printf("print: %d\n", *p);
        break;

      // ,
      case 44:
        //std::cout << getchar();
        break;

      // [
      case 91:
        break;

      // ]
      case 93:
        break;
    }

    inpptr++;
  }

  //std::cout << "current address: " << p << "\n";
  return 0;
}
