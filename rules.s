global _asmTest

section .text

_asmTest:
    mov rcx, rdi
    lea rdx, [rel _daRulz]
    
    mov rax, [rdx + 8*rcx]

    ret


_daRulz:
    dq _rule1
    dq _rule2
    dq _rule3
    dq _rule4

_rule1:
   db `Hit this through a wicket with a cricket bat.\0`

_rule2:
   db `Throw this into a bucket.\0`

_rule3:
   db `Knock this into the Master Tree using a croquet mallet.\0`

_rule4:
   db `Bounce this on a tennis racket while jumping on one leg.\0`
