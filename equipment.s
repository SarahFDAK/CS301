global _equip
section .text

_equip:
	mov rcx, rdi
	lea rdx, [rel _equipment]

	mov rax, [rdx + 8*rcx]

	ret

_equipment:
	dq birdie
	dq soccer
	dq pinecone
	dq balloon
	dq racket
	dq horse
	dq bat
	dq softball
	dq hose
	dq rake

birdie:
	db `a badminton birdie\0`
soccer:
	db `a soccer ball\0`
pinecone:
	db `pinecones\0`
balloon:
	db `water balloons\0`
racket:
	db `a tennis racket\0`	
horse:							
	db `a hobby horse\0` 
bat:
	db `a baseball bat\0`
softball:
	db `a softball\0`
hose:
	db `a garden hose\0`
rake:
	db `a rake\0`
