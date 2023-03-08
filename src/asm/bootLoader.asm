; runs the exturnal code that boots it into 32 bit
%include "src/asm/OS/32_bit.asm"

; declares custom rng librairy
%include "src/asm/components/rand.asm"

; calls the c code
halt:

	mov esp, kernel_stack_top

	extern cmain
	call cmain

	extern cppmain
	call cppmain

	cli
	hlt

section .bss
align 4
kernel_stack_bottom: equ $
	resb 16384 ; 16 KB
kernel_stack_top: