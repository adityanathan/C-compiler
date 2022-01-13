## LLVM Code Generator for C programs

This is a code generator that emits LLVM code for an input C program. It supports limited features in C. This code generator was built as part of the [Compiler Design course](https://iitd.github.io/col728/labs.html) at IIT Delhi taught by Prof. Sorav Bansal.

Building the project: Use the `cc` target in the Makefile

Usage: `cc <prog.c>`

The binary emits the corresponding LLVM code for the input C program as `cc.ll`

If you wish to look at a sample output, please see [test1.ll](examples/test1.ll) and the corresponding C program [test1.c](examples/test1.c)

