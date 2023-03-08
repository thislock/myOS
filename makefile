# define variables
AS=nasm
CC=tcc
CCPP=tcc
LD=ld
ASFLAGS=-f elf32
CFLAGS=-m32 -w -nostdlib -c
CPPFLAGS=-m32 -w -nostdlib -x c++ -c
LDFLAGS=-m elf_i386 -T linker.ld -s

# define targets
all: build/lochOS.bin



# x86 asembly
build/start.o: src/asm/bootLoader.asm
	$(AS) $(ASFLAGS) $< -o $@

# all includes for the files for generalized linking and smaller code size
build/include.o: src/include.c
	tcc -m32 -w -c $< -o $@

# c++ code
build/cpp_code.o: src/cpp_main.cpp
	$(CCPP) $(CPPFLAGS) $< -o $@

# c code
build/c_code.o: src/c_main.c
	$(CC) $(CFLAGS) $< -o $@

# linking
build/lochOS.bin: build/include.o build/cpp_code.o build/c_code.o build/start.o
	$(LD) $(LDFLAGS) -o $@ $^

# runs the software in qemu
run: build/lochOS.bin
	qemu-system-x86_64 -fda $<

clean:
	clear
	rm -f build/*.o build/lochOS.bin
