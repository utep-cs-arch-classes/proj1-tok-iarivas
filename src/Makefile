run: main.o tokenizer.o history.o
	cc -o run main.o tokenizer.o history.o

main.o: main.c tokenizer.c tokenizer.h

tokenizer.o: tokenizer.c tokenizer.h

history.o: history.h history.c tokenizer.h

clean:
	rm -f *.o run
