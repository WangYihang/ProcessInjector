all:main evil
main:main.c
	gcc -o main main.c
evil:evil.c
	gcc -fPIC -shared -o evil.so evil.c -ldl
clean:
	rm -rf ./evil.so
	rm -rf ./main
