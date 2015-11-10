	.globl min2
	.text
min2:
	movl 4(%esp),%eax /* premier argument : a */
	cmpl 8(%esp),%eax /* a - second argument b */
	jle  ok           /* a - b <= 0 */
	movl 8(%esp),%eax /* b est plus petit que a */
ok:
	ret
