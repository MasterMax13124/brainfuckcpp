#include <iostream>
#include <fstream>
#include <string>
#define SIZE 1000

int main(int argc, char *argv[]) {

  // Read the source file 
  //https://stackoverflow.com/questions/2912520/read-file-contents-into-a-string-in-c
  std::ifstream ifs(argv[1]);
  std::string code( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );

  // Initialize variables for later use
  int arr[SIZE]; // Array that stores memory cell values
  int *p = &arr[0]; // Pointer to access memory cell values
  char *inpptr = &code.at(0); // Pointer to iterate through brainfuck code

  for ( int i = 0; i < 1000; i++ ) { // Initialize memory values with zeroes
    arr[i] = 0;
  }

  // Actual processing of bf code starts here and ends when code pointer reaches end of code string
  while (inpptr != &code.at(code.length() -1)) {
    switch (*inpptr) {
      // >
      case 62:
        if ( p == &arr[SIZE -1] )
          p = &arr[0];
        else
          p++;
        break;

      // <
      case 60:
        if ( p == &arr[0] )
          p = &arr[SIZE -1];
        else
          p--;
        break;

      // +
      case 43:
        if (*p >= 255) {
          *p = 0;
        }
        else {
          *p += 1;
        }
        break;

      // -
      case 45:
        if (*p <= 0) {
          *p = 255;
        }
        else {
          *p -= 1;
        }
        break;

      // .
      case 46:
        std::cout << (char) *p;
        break;

      // ,
      case 44:
        std::cout << "\n";
        *p = getchar();
        getchar();
        break;

      // [
      case 91:
        if (*p == 0){
          int counter = 1;
          while (counter > 0) {
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
            inpptr--;
            if (*inpptr == ']')
              counter++;
            else if (*inpptr == '[')
              counter--;
          }
        }
        break;
    }
    inpptr++;
  }
  std::cout << "\n";
  return 0;
}
