CFLAGS = -g -lm

all: perceptron

perceptron: perceptron.c
	@echo "Compiling..."
	@gcc perceptron.c -o perceptron $(CFLAGS)
	@echo "Done."

clear:	
	@rm -f perceptron perf.data perf.data.old
	@echo "Removed the compiled binary & perf reports (if existed)."
