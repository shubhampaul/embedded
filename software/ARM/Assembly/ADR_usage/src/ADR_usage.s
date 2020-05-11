/* ARM assembly for computing x = (a + b) - c */
/* Showing ADR ADR Usage                      */
/* Test this code at https://cpulator.01xz.net/?sys=arm */


.text /* start of the code section */

.global _start

_start:
	ADR r4, a     //get address for a
	LDR r0, [r4]  //get value of a
	ADR r4, b
	LDR r1, [r4]
	ADD r3, r0, r1
	ADR r4, c
	LDR r2, [r4]
	SUB r3, r3, r2
	ADR r4, x
	STR r3, [r4]

a: .word 3
b: .word 4
c: .word 2
x: .word 0
