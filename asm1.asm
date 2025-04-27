

section .data
    prompt      db "Введите число:", 10, 0
    err_msg     db "Ошибка: введите положительное число!", 10, 0
    result_msg  db "Количество конечных нулей: %d", 10, 0
    fmt         db "%d", 0

section .bss
    ; Никаких глобальных переменных не требуется, все переменные для ввода выделим на стеке в main

section .text
    global main
    extern printf, scanf

;--------------------------------------------
; Функция: count_zeros
; Принимает параметр n в регистре EDI (32-битное число);
; возвращает результат (количество конечных нулей) в EAX.
; Алгоритм: zeros = 0;
;   while(n > 0) {
;       n /= 5;
;       zeros += n;
;   }
count_zeros:
    push rbp
    mov  rbp, rsp
    xor  r8d, r8d     ; r8d = 0 (накопитель для результата)
count_loop:
    cmp  edi, 0      ; если n <= 0, выйти из цикла
    jle  count_end
    mov  eax, edi
    xor  edx, edx
    mov  ecx, 5
    idiv ecx        ; EAX := edi / 5, EDX := остаток 
    add  r8d, eax   ; прибавляем частное к аккумулятору
    mov  edi, eax  ; обновляем n = n / 5
    jmp  count_loop
count_end:
    mov  eax, r8d  ; возвращаем результат в eax
    pop  rbp
    ret

;--------------------------------------------
; Функция main
; Используем локальную переменную N, выделенную на стеке.
main:
    push rbp
    mov  rbp, rsp
    sub  rsp, 16         ; выделяем место для локальной переменной N
    
    ; Вывод приглашения "Введите число:"
    lea  rdi, [rel prompt]
    xor  eax, eax
    call printf
    
    ; Считываем число через scanf("%d", &N)
    lea  rsi, [rbp-4]
    lea  rdi, [rel fmt]
    xor  eax, eax
    call scanf
    
    ; Проверка, что N не отрицательное
    mov  eax, dword [rbp-4]
    cmp  eax, 0
    jge  positive_input
    ; Если отрицательное, выводим сообщение об ошибке
    lea  rdi, [rel err_msg]
    xor  eax, eax
    call printf
    mov  eax, 1
    jmp  end_main

positive_input:
    mov  eax, dword [rbp-4]
    mov  edi, eax        ; передаем N в count_zeros
    call count_zeros
    
    ; Вывод результата "Количество конечных нулей: %d"
    lea  rdi, [rel result_msg]
    mov  esi, eax
    xor  eax, eax
    call printf
    
    mov  eax, 0          ; код возврата 0

end_main:
    leave
    ret

section .note.GNU-stack
