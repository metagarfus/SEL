	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$10000000, -8(%rbp)     ## imm = 0x989680
	jge	LBB0_4
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	callq	_random
	movl	%eax, %ecx
	movl	%ecx, -24(%rbp)
	callq	_random
	movl	%eax, %ecx
	movl	%ecx, -20(%rbp)
	callq	_random
	movl	%eax, %ecx
	movl	%ecx, -16(%rbp)
	movl	-24(%rbp), %ecx
	addl	-20(%rbp), %ecx
	addl	-16(%rbp), %ecx
	movl	%ecx, -28(%rbp)
	movl	-28(%rbp), %edi
	callq	_opaque
	movl	%eax, -32(%rbp)         ## 4-byte Spill
## BB#3:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB0_1
LBB0_4:
	movl	-4(%rbp), %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
