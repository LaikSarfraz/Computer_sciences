	.file	"registres.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	foo
	.type	foo, @function
foo:
.LFB0:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	movl	$100000, 12(%rsp)
.L2:
	movl	$100000, 8(%rsp)
.L16:
	movl	$100000, %r12d
.L14:
	movl	$100000, %r13d
.L12:
	movl	$100000, %r14d
.L10:
	movl	$100000, %r15d
.L8:
	movl	$100000, %ebp
	.p2align 4,,10
	.p2align 3
.L6:
	movl	$100000, %ebx
	.p2align 4,,10
	.p2align 3
.L3:
	xorl	%eax, %eax
	call	bar
	subl	$1, %ebx
	jne	.L3
	subl	$1, %ebp
	jne	.L6
	subl	$1, %r15d
	jne	.L8
	subl	$1, %r14d
	jne	.L10
	subl	$1, %r13d
	jne	.L12
	subl	$1, %r12d
	jne	.L14
	subl	$1, 8(%rsp)
	jne	.L16
	subl	$1, 12(%rsp)
	jne	.L2
	addq	$24, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE0:
	.size	foo, .-foo
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.ident	"GCC: (Ubuntu 5.2.1-22ubuntu2) 5.2.1 20151010"
	.section	.note.GNU-stack,"",@progbits
