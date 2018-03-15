TARGET = all clean

SUBDIRS = week1 \
		  week2

.PHONY: $(TARGET) $(SUBDIRS)

$(TARGET): $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

