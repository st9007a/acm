TARGET = all clean

SUBDIRS = week1 \
		  week2 \
		  week3 \
		  week4 \
		  week5 \
		  week6 \
		  week7 \
		  week8

.PHONY: $(TARGET) $(SUBDIRS)

$(TARGET): $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

