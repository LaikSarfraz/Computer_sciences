	.text
	.globl fib
fib:				/* pile: ... n @retour */
	movl	4(%esp),%eax	/* copier n dans eax */
	cmpl	$2,%eax		/* n-2 */
	jge	calcule		/* si n < 2 */
	ret			/*   renvoyer n */
calcule:	
	decl	%eax		/* eax = n-1 */
	
	pushl	%eax		/* calculer fib(n-1) */
	call	fib
	add	$4,%esp
	/* eax vaut fib(n-1) */
	
	pushl	%eax		/* pile : ... n @retour fib(n-1) */
	movl	8(%esp),%eax	/* copier n dans eax */
	subl	$2,%eax		/* eax = n-2 */
	
	pushl	%eax		/* calculer fib(n-2) */
	call	fib
	add	$4,%esp
	/* eax vaut fib(n-2), pile : ... n @retour fib(n-1) */
	
	popl	%ecx		/* pile: ... n @retour */
	addl	%ecx,%eax
	ret
	
	
