OUT = bin
CFLAGS = -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE

EXEC := UVA-10080 \
		UVA-259 \
		UVA-663 \
		POJ-1486

EXEC := $(addprefix $(OUT)/,$(EXEC))

target ?= uva-10327

.PHONY: all test clean

all: $(OUT) $(EXEC)

$(OUT):
	mkdir -p $@

$(OUT)/%: %.c
	gcc -o $@ $^ $(CFLAGS)

$(OUT)/%: %.cpp
	g++ -o $@ $^ $(CFLAGS)

test: $(EXEC)
	cat in.txt | ./$(OUT)/$(target) > out.txt

clean:
	rm -rf $(OUT)
