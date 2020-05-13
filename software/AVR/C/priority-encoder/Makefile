# Name: Makefile
# Author: Shubham Paul
# License: GPLv3

DEVICE     = atmega328p
CLOCK      = 16000000UL
BAUD       = 115200
PORT       = /dev/ttyACM0
UFLAGS     = -V -c arduino

TARGET     = priority-encoder

TARGETPATH = $(shell pwd)
HEX        = $(TARGET).hex
ELF        = $(TARGET).elf

# Add source directoy for make to look in and add the project includes
INCS      += -I$(TARGETPATH)/src
VPATH      = $(TARGETPATH)/src

# Defaults sources, headers and objects (in the VPATH)
SOURCES    = $(wildcard src/*.c)
HEADERS    = $(wildcard src/*.h)
OBJECTS    = $(SOURCES:.c=.o)

# Compiler/linker and flags
COMPILER   =  avr-gcc
LINKER     =  avr-gcc
OBJCOPY    =  avr-objcopy
UPLOADER   =  avrdude

# add -I$(avr_DIR)/include if required

CFLAGS     =  -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE)
CFLAGS    +=  $(INCS)

# add -L$(avr_DIR)/lib if required

LFLAGS       = -mmcu=$(DEVICE)

OBJCOPYFLAGS = -O ihex -R .eeprom

# "Phonies"
.PHONY: all clean flash

# Rules
all: $(HEX)

$(HEX): $(ELF)
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

$(ELF): $(OBJECTS)
	$(LINKER) $(LFLAGS) $(OBJECTS) -o $@

$(OBJECTS): %.o:%.c $(HEADERS)
	$(COMPILER) -c $(CFLAGS) $< -o $@

flash: $(HEX)
	$(UPLOADER) $(UFLAGS) -p $(DEVICE) -P $(PORT) -b $(BAUD) -U flash:w:$<

clean:
	rm -rf $(OBJECTS) $(ELF) $(HEX)


