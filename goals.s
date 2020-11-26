global _objectives
section .text

_objectives:
  mov rcx, rdi
  lea rdx, [rel _goals]
  mov rax, [rdx + 8*rcx]
  ret
  
_goals:
  dq _goal1
  dq _goal2
  dq _goal3


_goal1:
  db `into your opponent's goal zone net basket.\0`
  
_goal2:
  db `over the nearest evergreen tree.\0`
  
_goal3:
  db `while you read Tolstoy.\0`
