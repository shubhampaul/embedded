/* Test this code at https://cpulator.01xz.net/?sys=arm */


.text /* start of the code section */

.global _start

_start:
        adr r5, dat_in
	adr r6, dat_out
	mov r3, #4
	mov r2, #0
		
loop:
	ldr r4, [r5], #4
	ldr r1, [r5], #4
	sub r3, r3, #1
	add r0, r4, r1
	str r0, [r6], #4
	cmp r2, r3
	bne loop


dat_in: .word 1, 2, 3, 4, 5, 6, 7, 8
dat_out: .word              
