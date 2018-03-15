OUT = bin

EXEC := UVA-10392 \
		UVA-10106 \
		UVA-408 \
		UVA-10104 \
		UVA-906 \
		UVA-136

EXEC := $(addprefix $(OUT)/,$(EXEC))

target ?= uva-10327

.PHONY: all test clean

all: $(OUT) $(EXEC)

$(OUT):
	mkdir -p $@

$(OUT)/%: %.c
	gcc -o $@ $^

$(OUT)/%: %.cpp
	g++ -o $@ $^ -std=c++11

test: $(EXEC)
	cat in.txt | ./$(OUT)/$(target) > out.txt

clean:
	rm -rf $(EXEC)
