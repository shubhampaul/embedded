# Name: Makefile
# Author: Shubham Paul
# License: GPLv3

DEVICE     = atmega328p
CLOCK      = 16000000UL
BAUD       = 115200
PORT       = /dev/ttyACM1
UFLAGS     = -V -c arduino

HEX        = debouncing.hex
TARGETPATH = $(shell pwd)

# Add source directoy for make to look in and add the project includes
INCS      += -I$(TARGETPATH)/src
VPATH      = $(TARGETPATH)/src

# Defaults sources, headers and objects (in the VPATH)
SOURCES    = $(wildcard src/*.c)
HEADERS    = $(wildcard src/*.h)
OBJECTS    = $(SOURCES:.c=.o)
ELF        = $(OBJECTS:.o=.elf)

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
	$(LINKER) $(LFLAGS) $< -o $@

$(OBJECTS): $(SOURCES) $(HEADERS)
	$(COMPILER) -c $(CFLAGS) $< -o $@

flash: $(HEX)
	$(UPLOADER) $(UFLAGS) -p $(DEVICE) -P $(PORT) -b $(BAUD) -U flash:w:$<

clean:
	rm -rf $(OBJECTS) $(ELF) $(HEX)


