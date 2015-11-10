	.globl rindexa
	.text
rindexa:
	movl	4(%esp),%ecx	/* placer l'argument (p) dans %ecx */
	movl	$0,%eax		/* renvoyer NULL par defaut */
loop:
	cmpb	$'a',(%ecx)	/* *p == 'a' ? */
	jne	non
	movl	%ecx,%eax	/*   si oui, garder p dans %eax */
non:	
	cmpb	$0,(%ecx)	/* *p == 0 ? */
	je	fin		/*   oui : on s'arrete */
	incl	%ecx		/* p++ */
	jmp	loop
fin:
	ret
