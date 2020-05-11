/* Demonstrating Memory operations */
/* Test this code at https://cpulator.01xz.net/?sys=arm */

.global _start

_start:
	/* Generate data */
	mov r4, #100     /* Store adress to register */
	mov r2, #0       /* init counter */
	mov r3, #6       /* set limit

loop1:
	add r2, r2, #1   /* increment */
	str r2, [r4], #4 /* store and increment address */
	cmp r2, r3       /* check if end
	bne loop1        /* loop if not equal */

	mov r2, #0       /* init counter */
	sub r4, r4, #4   /* prepare adress of last element */
	mov r5, #172     /* store new adress to register */

loop2:
	ldr r6, [r4]     /* load element from old location */
	sub r4, r4, #4   /* decrement load adress */
	str r6, [r5], #4 /* store on new location and inc store add */
	subs r3, r3, #1  /* decrement counter */
	cmp r3, #0       /* check if counter is 0;
	bne loop2

