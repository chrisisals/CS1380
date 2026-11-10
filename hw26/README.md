Homework 26 — File I/O
What does this project do?
This project demonstrates text and binary file input/output in C. It includes programs that write and read files, copy text files, and store structured records in binary format.
Why should I care?
File I/O allows programs to save information permanently, read existing data, and process records without requiring users to enter everything manually.
How do I use it?
Run the programs from the terminal:
./basic_file_ops
./text_copy
./binary_records
The text copy program reads input.txt and creates copy.txt. The binary-record program creates and reads records.bin.
How do I build it?
Use the provided Makefile:
make
To remove compiled programs:
make clean
Requirements
* GCC compiler supporting C23
* Make utility
* macOS or another compatible terminal environment
