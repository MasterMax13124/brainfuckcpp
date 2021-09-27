#include <iostream>
#define SIZE 1000

int main(int argc, char *argv[]) {
  int c; // stores current character
  int arr[SIZE];
  int *p = &arr[0];
  for ( int i = 0; i < 1000; i++ ) {
    arr[i] = 0;
  }

  std::cout << "start: " << &arr[0] << " end: " << &arr[SIZE-1] << "\n";

  while (( c = getchar()) != EOF ) {
    if ( c != 32 && c != 10 ) {
      //std::cout << "current address: " << p << "\n";
      switch (c) {

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
          //to be implemented
          break;

        // [
        case 91:
          break;

        // ]
        case 93:
          break;
      }
    }
  }


  std::cout << "current address: " << p << "\n";
  return 0;
}
