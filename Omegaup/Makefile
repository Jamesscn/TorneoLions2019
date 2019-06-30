inputs := $(wildcard *.in)
outputs := $(inputs:%.in=%.out)

all: $(outputs)

$(outputs):
	cat $*.in | ./program > $@
