section .text

global _equip

_equip:
	mov rcx, rdi
	lea rdx, [rel _equipment]

	mov rax, [rdx + 8*rcx]

	ret

_equipment:
	dq birdie
	dq mallet
	dq soccer
	dq pinecone
	dq wicket
	dq balloon
	dq bucket
	dq racket
	dq horse
	dq bat
	dq softball
	dq hose
	dq rake

birdie:
	db `a badminton birdie\0`
mallet:
	db `a croquet mallet\0`
soccer:
	db `a soccer ball\0`
pinecone:
	db `pinecones\0`
wicket:
	db `wickets\0`
balloon:
	db `water balloons\0`
bucket:
	db `buckets\0`
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
