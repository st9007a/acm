OUT = bin

EXEC := UVA-10327 \
	    UVA-10810 \
		UVA-10107 \
		UVA-10026 \
		UVA-10420 \
		POJ-3067

EXEC := $(addprefix $(OUT)/,$(EXEC))

target ?= uva-10327

.PHONY: all test clean

all: $(OUT) $(EXEC)

$(OUT):
	mkdir -p $@

$(OUT)/%: %.c
	gcc -o $@ $^

test: $(EXEC)
	@cat in.txt | ./$(OUT)/$(target) > out.txt

clean:
	rm -rf $(EXEC)
