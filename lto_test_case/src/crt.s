	.global	_start
	.type _start, @function
	.extern G_MY_GLOBAL
	
_start:
	#initialize Interrupt handler base
	la t0, G_MY_GLOBAL
	csrrw zero, 0xbc8, t0 #meivt
	

    j my_main


