C_FLAG_main = -Wl,-Map=main.map
C_FLAG_func1 = -Wl,-Map=func1.map

test.exe : main.o func1.o func2.o
	gcc -o test.exe main.o func1.o func2.o 
	gcc $^ --output $@ $(C_FLAG_main)
	gcc $^ -o $@ $(C_FLAG_func1)
 
	
main.o : func1.h func2.h main.c
	gcc -c main.c
func2.o : func2.h func2.c
	gcc -c func2.c
func1.o : func1.h func1.c
	gcc -c func1.c
clean : 
	del *.exe *.o *.map