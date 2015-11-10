	.globl fact
	.text
	
fact:	movl 4(%esp),%ecx
	movl $1,%eax

loop:	cmpl $1,%ecx
	je fin
	imull %ecx,%eax
	decl %ecx
	jmp loop

fin:	ret
	
