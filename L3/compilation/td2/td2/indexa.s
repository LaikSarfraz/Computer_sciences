	.globl indexa
	.text
indexa:	movl	4(%esp),%eax	/* placer l'argument (p) dans %eax */
	decl	%eax	  	/* p-- */
loop:
	incl	%eax		/* p++ */
	cmpb	$'a',(%eax)	/* *p == 'a' ? */
	je	fin		/*   alors on s'arrete */
	cmpb	$0,(%eax)	/* *p == 0 ? */
	jne	loop		/*   non */
	movl	$0,%eax		/*   oui : renvoyer NULL */
fin:
	ret
