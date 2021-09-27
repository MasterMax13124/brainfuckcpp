# brainfuck interpreter

## Installation

Clone the repository and enter it:

```sh
git clone git@github.com:MasterMax13124/brainfuckcpp.git && cd brainfuckcpp
```

Then use your C++ compiler of choice to compile `brainfuck.cpp`. Examples:

```sh
g++ brainfuck.cpp -o brainfuck
# or
clang++ brainfuck.cpp -o brainfuck
```

Finally you can move the compiled brainfuck binary to some folder that's in
your PATH, for example:

```sh
sudo cp brainfuck /usr/local/bin/
```

## Usage

Simply run the brainfuck binary and use the file name of your brainfuck code as
the first command line argument, like this:

```sh
./brainfuck helloworld.b
```
