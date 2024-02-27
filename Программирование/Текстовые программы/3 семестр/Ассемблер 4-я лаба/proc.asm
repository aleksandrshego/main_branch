.386
PUBLIC _manual_sorting1@8
PUBLIC _manual_sorting2
PUBLIC manual_sorting3
PUBLIC manual_sorting4
PUBLIC @manual_sorting5@8

.model flat
.data
.code
_manual_sorting1@8 proc
	push ebp
	mov ebp, esp
	push [ebp + 12] ; size
	push [ebp + 8] ; ptr array

	call _procedure

	mov esp, ebp
	pop ebp
	ret 8
_manual_sorting1@8 endp

_procedure proc stdcall, a:dword, b:dword
		local n:dword

		xor eax, eax
		mov eax, b
		mov n, eax

		xor ebx, ebx ; массив
		xor ecx, ecx ; количество общих проходов
		xor edx, edx
		xor esi, esi ; проход по циклу для проверки

		mov ebx, a
		mov ecx, eax
		dec n

	start :
		cycle:
			mov eax, [ebx + 4 * esi]
			test eax, 1

			jnz nex
			jz step

		nex :
			inc esi
			mov eax, [ebx + 4 * esi]
			dec esi
			test eax, 1

			jnz step
			jz xchange

		xchange :
			xor edx, edx
			mov eax, [ebx + 4 * esi]
			inc esi
			mov edx, [ebx + 4 * esi]
			dec esi
			xchg eax, edx

			mov[ebx + 4 * esi], eax

			inc esi
			mov[ebx + 4 * esi], edx
			dec esi

		step :
			cmp esi, n
			inc esi 
			jb cycle

			xor esi, esi
			loop start

		xor eax, eax
		mov eax, ebx
		ret
_procedure endp

; *********************************************

_manual_sorting2 proc
		push ebp
		mov ebp, esp
		push [ebp + 12] ; size
		push [ebp + 8] ; ptr array

		call _procedure1

		mov esp, ebp
		pop ebp
		ret
_manual_sorting2 endp

_procedure1 proc stdcall, a:dword, b:dword
		local n:dword

		xor eax, eax
		mov eax, b
		mov n, eax

		xor ebx, ebx ; массив
		xor ecx, ecx ; количество общих проходов
		xor edx, edx
		xor esi, esi ; проход по циклу для проверки

		mov ebx, a
		mov ecx, eax
		dec n

	start :
		cycle:
			mov eax, [ebx + 4 * esi]
			test eax, 1

			jnz nex
			jz step

		nex :
			inc esi
			mov eax, [ebx + 4 * esi]
			dec esi
			test eax, 1

			jnz step
			jz xchange

		xchange :
			xor edx, edx
			mov eax, [ebx + 4 * esi]
			inc esi
			mov edx, [ebx + 4 * esi]
			dec esi
			xchg eax, edx

			mov[ebx + 4 * esi], eax

			inc esi
			mov[ebx + 4 * esi], edx
			dec esi

		step :
			cmp esi, n
			inc esi 
			jb cycle

			xor esi, esi
			loop start

		xor eax, eax
		mov eax, ebx
		ret
_procedure1 endp

; *********************************************

manual_sorting3 proc stdcall, a:dword, b:dword
		local n:dword

		xor eax, eax
		mov eax, b
		mov n, eax

		xor ebx, ebx ; массив
		xor ecx, ecx ; количество общих проходов
		xor edx, edx
		xor esi, esi ; проход по циклу для проверки

		mov ebx, a
		mov ecx, eax
		dec n

	start :
		cycle:
			mov eax, [ebx + 4 * esi]
			test eax, 1

			jnz nex
			jz step

		nex :
			inc esi
			mov eax, [ebx + 4 * esi]
			dec esi
			test eax, 1

			jnz step
			jz xchange

		xchange :
			xor edx, edx
			mov eax, [ebx + 4 * esi]
			inc esi
			mov edx, [ebx + 4 * esi]
			dec esi
			xchg eax, edx

			mov[ebx + 4 * esi], eax

			inc esi
			mov[ebx + 4 * esi], edx
			dec esi

		step :
			cmp esi, n
			inc esi 
			jb cycle

			xor esi, esi
			loop start

		xor eax, eax
		mov eax, ebx
		ret 8
manual_sorting3 endp

; *********************************************

manual_sorting4 proc C, a:dword, b:dword
		local n:dword

		xor eax, eax
		mov eax, b
		mov n, eax

		xor ebx, ebx ; массив
		xor ecx, ecx ; количество общих проходов
		xor edx, edx
		xor esi, esi ; проход по циклу для проверки

		mov ebx, a
		mov ecx, eax
		dec n

	start :
		cycle:
			mov eax, [ebx + 4 * esi]
			test eax, 1

			jnz nex
			jz step

		nex :
			inc esi
			mov eax, [ebx + 4 * esi]
			dec esi
			test eax, 1

			jnz step
			jz xchange

		xchange :
			xor edx, edx
			mov eax, [ebx + 4 * esi]
			inc esi
			mov edx, [ebx + 4 * esi]
			dec esi
			xchg eax, edx

			mov[ebx + 4 * esi], eax

			inc esi
			mov[ebx + 4 * esi], edx
			dec esi

		step :
			cmp esi, n
			inc esi 
			jb cycle

			xor esi, esi
			loop start

		xor eax, eax
		mov eax, ebx
		ret 
manual_sorting4 endp

; *********************************************

@manual_sorting5@8 proc
		local n:dword

		mov ebx, ecx ; a - массив
		xor ecx, ecx
		mov ecx, edx ; b - size, количество общих проходов
		mov eax, edx
		xor edx, edx
		mov n, eax

		xor esi, esi ; проход по циклу для проверки

		dec n

	start :
		cycle:
			mov eax, [ebx + 4 * esi]
			test eax, 1

			jnz nex
			jz step

		nex :
			inc esi
			mov eax, [ebx + 4 * esi]
			dec esi
			test eax, 1

			jnz step
			jz xchange

		xchange :
			xor edx, edx
			mov eax, [ebx + 4 * esi]
			inc esi
			mov edx, [ebx + 4 * esi]
			dec esi
			xchg eax, edx

			mov[ebx + 4 * esi], eax

			inc esi
			mov[ebx + 4 * esi], edx
			dec esi

		step :
			cmp esi, n
			inc esi 
			jb cycle

			xor esi, esi
			loop start

		xor eax, eax
		mov eax, ebx
		ret 
@manual_sorting5@8 endp

end