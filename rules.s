section .text
global _asmTest

_asmTest:
    mov rcx, rdi
    lea rdx, [rel _daRulz]
    
    mov rax, [rdx + 8*rcx]
;extern _puts
;call _puts

    ret


_daRulz:
    dq _rule1
    dq _rule2
    dq _rule3

_rule1:
   db `check it out\0`

_rule2:
   db `dis rule 2\0`

_rule3:
   db `final COUNTDOWN\0`
