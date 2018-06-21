TARGET = all clean

SUBDIRS = hw1 \
		  hw2 \
		  hw3 \
		  hw4 \
		  hw5 \
		  hw6 \
		  hw7 \
		  hw8 \
		  hw9 \
		  hw10 \
		  hw11 \
		  hw12

.PHONY: $(TARGET) $(SUBDIRS)

$(TARGET): $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

