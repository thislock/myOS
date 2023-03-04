
; runs the exturnal code that boots it into 32 bit
%include "src/asm/32_bit.asm"

; calls the c code
halt:

	mov esp, kernel_stack_top
	extern kmain
	call kmain
	cli
	hlt

section .bss
align 4
kernel_stack_bottom: equ $
	resb 16384 ; 16 KB
kernel_stack_top: