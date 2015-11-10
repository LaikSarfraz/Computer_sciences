	.text
fact:
	movl	4(%esp),%ecx
	movl	$1,%eax
	movl	$1,%edx
loop:
	cmpl	%ecx,%edx
	jne	encore
	imull	%edx,%eax
	ret
encore:	
	imull	%edx,%eax
	incl	%edx
	jmp	loop
	.globl	fact

