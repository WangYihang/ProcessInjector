all:main evil backdoor test_backdoor
main:main.c
	gcc -o main main.c
evil:evil.c
	gcc -fPIC -shared -o evil.so evil.c -ldl
backdoor:backdoor.c
	gcc -fPIC -shared -o backdoor.so backdoor.c -ldl
test_backdoor:test_backdoor.c
	gcc -o test_backdoor test_backdoor.c
clean:
	rm -rf ./evil.so
	rm -rf ./main
