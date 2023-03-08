
global middle_square
middle_square:
  mov eax, [seed] ; sets eax to seed

  mov edx, 10 ; number to divide by
  mov ecx, 0 ; set's ecx to zero 
  call middle_square_loop ; calls the loop that see's what the last digit in a number is 

  mov [seed], eax ; sets seed to result

middle_square_loop:

  mov ecx, eax ; set's ecx to eax

  div edx ; eax / 10

  cmp eax, 0 ; chea

end:
  ret ; returns to last scope