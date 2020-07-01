section .data
	db0 db 0
	db1	db 0
	db2	db 0
	db3	db 8
section .bss
section .text
	global _start
_start:
	mov var, 120
	mov	eax, 1
	int	0x80
.start:
