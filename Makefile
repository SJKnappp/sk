start:
	
	nasm -f elf ass.asm
	ld -m elf_i386 -s -o ass ass.o

t:
	
	nasm -f elf test.asm
	ld -m elf_i386 -s -o test test.o


py:
	python brainfuck.py
	nasm -f elf main.asm
	ld -m elf_i386 -s -o main main.o

clean:
	rm main.o
	rm main