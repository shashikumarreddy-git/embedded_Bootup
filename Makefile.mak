CC=arm-none-eabi-gcc		//cross compiler name
MACH=cortex-m4
CFLAGES= -C -mcpu=$(MACH) -mthumb -std=gun11 -O0		//compiler flages
LDFLAGS= -nostdlib -T stm32_ls.ld -wl,-Map=final.map	//linker arguments

all :main.o led.o stm32_startup.o final.elf

main.o:main.c
	$(CC) $(CFLAGS) -O $@(target) $^(dependency)   //$(CC) $(CFLAGS) main.c -O main.o

led.o:led.c
	$(CC) $(CFLAGS) -O $@ $^
	
stm32_startup.o:stm32_startup.c
	$(CC) $(CFLAGS) -O $@ $^
	
final.elf: main.o led.o stm32_startup.o
	$(CC) $(LDFLAGS) -O $@ $^
	
clean:
	rm -rf *.o *.elf