.text
	.global useimmiten

lue_tiedostosta:
	movq -0x108(%rbp), %rdi	# Load filepointer into register.
	call fgetc		# Get first byte of input.
	ret			# Return char

kirjoita_taulukkoon:
    addb $1, -0x100(%rbp, %rax, 1)  # Increment byte counter at index %rax
    ret

hae_eniten_kaytetyin:
    movq $-1, %rcx                  # Initialize index
    movb $0, -0x118(%rbp)           # Initialize most used byte count
    movb $0, -0x120(%rbp)           # Initialize most used byte index
haku_silmukka_alku:
    inc %rcx
    cmpq $256, %rcx                 
    jz haku_silmukka_ohi
    movb -0x100(%rbp, %rcx, 1), %al # Load byte count into memory
    cmpb %al, -0x118(%rbp)          # Compare with current most used byte count.
    jnl haku_silmukka_alku         
suurempi:
    movb %al, -0x118(%rbp)          # Store new most used byte count
    movl %ecx, -0x120(%rbp)         # Store index
    jmp haku_silmukka_alku
haku_silmukka_ohi:
	movl -0x120(%rbp), %eax
	ret			# Return most used byte.

alusta_taulukko:
	pushq %rcx		# Store old rcx
	movq $0, %rcx	# Move zero into rcx
alustus_alku:
	movb $0, -288(%rbp, %rcx, 1)	# Format memory
	inc %rcx
	cmpq $288, %rcx
	jne alustus_alku
alustus_ohi:
	popq %rcx	# Restore rcx
	ret

useimmiten:
	enter $288, $0		# Reserve memory for byte counting.
	call alusta_taulukko
	movq %rdi, -0x108(%rbp)	# Load filepointer into stack.
	movl %esi, -0x110(%rbp)	# Load EOF byte into stack.
silmukan_alku:
	call lue_tiedostosta	# Read char at filepointer.
	cmpl %eax, -0x110(%rbp)	# Check if byte is EOF byte.
	jz silmukka_ohi		# Jump to start of loop if not EOF.
	call kirjoita_taulukkoon	# Write byte into array.
	jmp silmukan_alku	# Jump to start of the loop.
silmukka_ohi:
	call hae_eniten_kaytetyin
	leave			# Release the stack.
	ret
