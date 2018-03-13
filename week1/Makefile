OUT = bin

EXEC := UVA-10327 \
	    UVA-10810 \
		UVA-10107 \
		UVA-10026 \
		UVA-10420 \
		UVA-879 \
		UVA-10583 \
		UVA-10685 \
		UVA-10158 \
		UVA-11987 \
		UVA-260 \
		UVA-336

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
