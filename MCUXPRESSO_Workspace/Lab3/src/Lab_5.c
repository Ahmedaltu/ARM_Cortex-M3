/*
===============================================================================
 Name        : lab5.c
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
#include <string.h>
// TODO: insert other definitions and declarations here

__attribute__(( naked )) int prt(const char *a)
{
	// the pointer to a character array is passed to the
	// subroutine in R0
	// remember to follow AAPCS:
	// push any register above r3 at the beginning and pop same them at the end
	// note: lr needs to be pushed and popped so that bx lr returns to right address
	asm volatile
	(
			"push { r4, r5, lr } \n"
			"mov r4, r0 \n"
			"mov r5, #0 \n"
			"print_loop:"
			"ldrb r0, [r4] \n" // ldrb is needed because char = 1 byte
			"cmp r0, #0 \n"
			"beq Loc \n"

			"bl Board_UARTPutChar \n"
			// change offset, jump to beginning of loop
			// r0 - r3 can (and will be) modified by Board_UARTPutChar
			"add r4, r4, #1 \n"
			"add r5, r5, #1 \n"
			"b print_loop \n"

			"Loc:"

			"cmp r5, #0 \n"
			"beq print_stop \n"

			"sub r4, r4, #1 \n"

			"bl Board_UARTPutChar \n"

			"sub r5, r5, #1 \n"
			"b Loc \n"

			"print_stop:"
			"pop { r4, r5, lr } \n"
			"bx lr \n"
	);
}

int main(void) {

#if defined (__USE_LPCOPEN)
	// Read clock settings and update SystemCoreClock variable
	SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
	// Set up and initialize all required blocks and
	// functions related to the board hardware
	Board_Init();
	// Set the LED to the state of "On"
	Board_LED_Set(0, true);
#endif
#endif

	// TODO: insert code here
	Board_UARTPutSTR("\r\nHello, World\r\n");

	//char test1[] = "Computer Architecture\r\n";
	char test1[] = "Comr Arch\r\n";
	char test2[] = "Computer Architecture\r\n";
	prt(test1);
	if(strcmp(test1, test2)) {
		while(1); // error - string modified
	}
	char test3[] = "Johnny Ca$h:Live @Folsom\r\n";
	char test4[] = "Johnny Ca$h:Live @Folsom\r\n";
	prt(test3);
	if(strcmp(test3, test4)) {
		while(1); // error - string modified
	}

	// Force the counter to be placed into memory
	volatile static int i = 0 ;
	// Enter an infinite loop, just incrementing a counter
	while(1) {
		i++ ;
		// "Dummy" NOP to allow source level single
		// stepping of tight while() loop
		__asm volatile ("nop");
	}
	return 0 ;
}
