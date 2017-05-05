	.file	"Testing/Semantic/t3-3.p"
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$0, %eax
	call	main1
	popq	%rbp
	ret
	.size	main, .-main
.LC0:
	.string "%d"
.LC0:
	.string "%d"
	.globl	main1
	.type	main1, @function
main1:
	pushq	%rbp
	movq	%rsp, %rbp
	popq	%rbp
	ret
	.size	main1, .-main1
	.ident	"GCC: (Ubuntu 4.8.5-2ubuntu1-14.04.1) 4.8.5"
	.section	.note.GNU-stack,"",@progbits
