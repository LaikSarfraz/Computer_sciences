
	.text
fact:
	movl 4(%esp),%ebx
	movl $1,%eax

loop:	cmpb $1,%ebx
	je ok
	imull %ebx,%eax
	decl  %ebx
	jmp loop

ok:	ret
.globl fact	
