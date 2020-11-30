global _objectives
section .text

_objectives:
  mov rcx, rdi           ;put game.cpp random int input into rcx
  lea rdx, [rel _goals]  ;create pointer to goal pointers
  mov rax, [rdx + 8*rcx] ;access goal text
  ret
  
_goals:
  dq _goal1
  dq _goal2
  dq _goal3
  dq _goal4
  dq _goal5
  dq _goal6



_goal1:
  db `into opponent goal zone net basket.\0`
  
_goal2:
  db `over the nearest evergreen tree.\0`
  
_goal3:
  db `while you read Tolstoy.\0`

_goal4:
  db `after you touch the 30-yard base wicket.\0`

_goal5:
  db `for exactly 34.25 seconds starting NOW.\0`

_goal6:
  db `when you hear that one screeching bird. No, not THAT one, THAT ONE!\0`

_goal7:
  db `while you sing the Lumberjack Song.\0`

_goal8:
  db `backward on one foot.\0`


