.set noreorder

.global _start
_start:
main:
	li		$t0, 1				# i = 1
	la		$t7, A				# place array in $t7
	
	FOR:
		slti		$t1, $t0, 10		# if i < 10, $t1 = true
		beq		$t1, $0, END		# terminate loop if i >= 10
		lw		$t8, 4($t7)		# $t8 = A[i]
		lw		$t9, 0($t7)		# $t9 = A[i-1]
		slt		$t2, $t9, $t8		# check if A[i] > A[i-1]
		bne		$t2, $0, IF		# branch to IF when $t2 = true
		
		ELSE:
			li		$v0, 1		# print_int syscall code
			addi		$a0, $t0, 0	# $a0 = i
			syscall
			
			li		$v0, 11		# print_char syscall code
			li		$a0, 32		# 32 = value for space in ASCII
			syscall
			
			addi	$t7, $t7, 4		# traverse array
			addi	$t0, $t0, 1		# i++
			j		FOR		# jump back to the top of the for loop
		
		IF:
			li		$v0, 1		# print_int syscall code
			addi	$a0, $t8, 0		# $a0 = A[i]
			syscall
			
			li		$v0, 11		# print_char syscall code
			li		$a0, 32		# 32 = ASCII value for space
			syscall
			
			addi	$t7, $t7, 4		# traverse array
			addi	$t0, $t0, 1		# i++
			j		FOR		# jump back to the top of the for loop
		
END:
	j	END
	
.data
A:	.word	4, 3, 6, 7, 10, 34, 9, -3, 4, 1
