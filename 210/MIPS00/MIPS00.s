.set noreorder

.global _start
_start:

	addi		$t0, $0, 0			# i = 0
		
	DO:
		addi		$v0, $0, 1		# $v0 = print_int system call code
		addi		$a0, $t0, 0		# $a0 = i
		syscall					# print $a0/i
		
		addi		$t0, $t0, 1		# i++
		slti		$t1, $t0, 10		# if i < 10, $t1 = 1/true; slti makes it so that
							# the end loop register from the original code
							# is no longer necessary								
		bne		$t1, $0, DO		# while i < 10, continue loop
	
END:
	j	END
