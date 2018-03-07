OUT = bin

EXEC := uva-10327 \
	    uva-10810 \
		uva-10107
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
