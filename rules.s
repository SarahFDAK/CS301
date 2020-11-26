global _verbs

section .text

_verbs:
    mov rcx, rdi
    lea rdx, [rel _verb]
    
    mov rax, [rdx + 8*rcx]

    ret


_verb:
    dq _action1
    dq _action2
    dq _action3
    dq _action4
    dq _action5
    dq _action6

_action1:
   db `Hit\0`

_action2:
   db `Throw\0`

_action3:
   db `Knock\0`

_action4:
   db `Bounce\0`
  
_action5:
   db `Hold\0`
   
_action6:
   db `Hop over\0`

_action7:
   db `Hop\0`
