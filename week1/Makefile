OUT = bin
CFLAGS = -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE

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
		UVA-336 \
		UVA-352 \
		UVA-383 \
		UVA-439

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
	rm -rf $(EXEC)
