.set noreorder

.global _start
_start:
main:
	li		$t0, 0				      	# i = 0
	li		$t1, 0				      	# sum = 0
	la		$t9, A				      	# place array in $t9
	
	FOR:
		slti		$t2, $t0, 10			# if i < 10, $t2 = true
		bne		$t2, 1, END		    	# exit loop when i = 10
		lw		$t8, 0($t9)		    	# load A[i] into $t8
		add		$t1, $t1, $t8		  	# sum += A[i]
		addi		$t0, $t0, 1		  	# i++
		addi		$t9, $t9, 4		  	# A[i+1]
		j		FOR
		
END:
	j	END

.data
A:	.word	4, 3, 6, 7, 10, 34, 9, -3, 4, 1
