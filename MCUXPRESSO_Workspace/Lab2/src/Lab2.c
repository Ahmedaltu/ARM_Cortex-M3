/*
===============================================================================
 Name        : Lab2.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

__attribute__(( naked )) int asm_test(int v0, int v1, int v2, int v3)
{
  // write your code between push and pop instructions
  asm volatile
  (
	"push {r4, r5, r6, r7} \n" // do not remove
	// do not add any code before this comment
	//"mov r7, r4 \n" // example assembly code - replace with your own code
	//"adds r4, r7, r2 \n" // example assembly code replace with your own code
	// add more code here

	"mul r4, r1, r3 \n"
    "adds r5, r4, r2 \n"
	"adds r6, r0, r1 \n"
	"mul r7, r5, r6 \n"
	"mov r0, r7 \n"

	// do not add any code after this comment
	"pop {r4, r5, r6, r7} \n" // do not remove
	"bx lr \n" // do not remove
  );
}

void fail() {
	printf("Failed\n"); // set a break point here
	while(1);
}

void ok() {
	printf("All ok\n"); // set a break point here
	while(1);
}


int main()
{
    int m0;
    int m1;
    int m2;
    int m3;

    m0 = 1; m1 = 2; m2 = 3; m3 = 4;
    m0 = asm_test(m0, m1, m2, m3);
    if(m0 != 33) fail();

    m0 = 8; m1 = 5; m2 = 6; m3 = 21;
    m0 = asm_test(m0, m1, m2, m3);
    if(m0 != 1443) fail();

    m0 = 3; m1 = 4; m2 = 5; m3 = 1;
    m0 = asm_test(m0, m1, m2, m3);
    if(m0 != 63) fail();

    m0 = 3; m1 = 5; m2 = 7; m3 = 8;
    m0 = asm_test(m0, m1, m2, m3);
    if(m0 != 376) fail();

    m0 = 33; m1 = 22; m2 = 11; m3 = 0;
    m0 = asm_test(m0, m1, m2, m3);
    if(m0 != 605) fail();

    m0 = 42; m1 = 55; m2 = 12; m3 = 1;
    m0 = asm_test(m0, m1, m2, m3);
    if(m0 != 6499) fail();

	ok();

    return 0;
}
