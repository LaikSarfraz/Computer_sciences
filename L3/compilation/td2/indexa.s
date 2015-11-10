	.globl indexa
	.text
indexa:
	movl 4(%esp),%eax
	decl %eax

loop:	incl %eax
	cmpb 'a',(%eax)
	je fin
	cmpb $0,%eax
	je fin
	



fin:	ret
	

	
	
	
	
