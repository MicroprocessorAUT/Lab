PIO_PER_OFF equ 0x0000
PIO_OER_OFF equ 0x0010
PIO_SODR_OFF equ 0x0030
PIO_CODR_OFF equ 0x0034
PIOA_BASE equ 0x400E0E00
	
	area	main_program, code, readonly 
	export __main
__main
	bl enable_pio
	
main_loop

	bl set_pin
	bl delay
	
	bl clear_pin
	bl delay
	
	b main_loop
	
clear_pin
	mov r4, #1

	ldr r5, =(PIOA_BASE+PIO_CODR_OFF)
	str r4, [r5]
	
	bx lr

set_pin
	mov r4, #1

	ldr r5, =(PIOA_BASE+PIO_SODR_OFF)
	str r4, [r5]
	
	bx lr

enable_pio
	mov r4, #1

	ldr r5, =(PIOA_BASE+PIO_PER_OFF)
	str r4, [r5]
	
	ldr r5, =(PIOA_BASE+PIO_OER_OFF)
	str r4, [r5]
	
	bx lr

delay
	mov r4, #0
	ldr r5, =0x000FFFFF
	;mov r5, #0
delay_inner_loop
	add r4, r4, #1
	
	cmp r4, r5
	bne delay_inner_loop
	bx lr
	END


	