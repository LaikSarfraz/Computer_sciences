	.file	"appel-8.c"
	.text
	.globl	foo
	.type	foo, @function
foo:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	$8901
	pushq	$7890
	movl	$6789, %r9d
	movl	$5678, %r8d
	movl	$4567, %ecx
	movl	$3456, %edx
	movl	$2345, %esi
	movl	$1234, %edi
	movl	$0, %eax
	call	bar
	addq	$16, %rsp
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	foo, .-foo
	.ident	"GCC: (Ubuntu 5.2.1-22ubuntu2) 5.2.1 20151010"
	.section	.note.GNU-stack,"",@progbits
