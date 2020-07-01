	.file	"test.cpp"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -36(%rbp)
.L3:
	cmpl	$4, -36(%rbp)
	jg	.L2
	movl	-36(%rbp), %eax
	cltq
	movl	$0, -32(%rbp,%rax,4)
	addl	$1, -36(%rbp)
	jmp	.L3
.L2:
	movl	-24(%rbp), %eax
	testl	%eax, %eax
	jne	.L4
	movl	$5, -24(%rbp)
.L4:
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L6
	call	__stack_chk_fail@PLT
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Arch Linux 9.3.0-1) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
