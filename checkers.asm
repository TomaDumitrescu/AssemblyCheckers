section .data

section .text
	global checkers

checkers:
    push ebp
    mov ebp, esp
    pusha

    mov eax, [ebp + 8]	; x
    mov ebx, [ebp + 12]	; y
    mov ecx, [ebp + 16] ; table

	mov edx, eax
	imul edx, edx, 8
	add edx, ebx
	add ecx, edx ; moving to (x, y)
	mov edx, 1
	jmp n_w
n_w:
	cmp eax, 6 ; checking limits
	jg s_e
	cmp ebx, 1
	jl n_e
	sub ecx, 1 ; y axis left
	add ecx, 8 ; x axis up
	mov byte [ecx], dl
	sub ecx, 7 ; move to (x, y)
	jmp n_e
n_e:
	cmp eax, 6
	jg s_e
	cmp ebx, 6
	jg s_w
	add ecx, 1 ; y axis right
	add ecx, 8 ; x axis up
	mov byte [ecx], dl
	sub ecx, 9 ; move to initial position
s_e:
	cmp eax, 1
	jl stop
	cmp ebx, 6
	jg s_w
	add ecx, 1 ; y axis right
	sub ecx, 8 ; x axis down
	mov byte [ecx], dl
	add ecx, 7 ; move to init
s_w:
	cmp eax, 1
	jl stop
	cmp ebx, 1
	jl stop
	sub ecx, 1 ; y axis left
	sub ecx, 8 ; x axis down
	mov byte [ecx], dl
	add ecx, 9 ; move to init
stop:
    popa
    leave
    ret
