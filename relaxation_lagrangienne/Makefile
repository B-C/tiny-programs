CC       = gcc
CFLAGS   = -I. -Wall -Wno-unused-result -g -std=c99 -O3

LD       = gcc
LDLIBS   = -lm

TARGET   = tsp

##################################################

SRC      = $(wildcard *.c)
OBJ      = $(patsubst %.c,%.o,$(SRC))

all:: $(TARGET)

$(TARGET): $(OBJ) Makefile
	$(LD) $(LDFLAGS) $(OBJ)  $(OUTPUT_OPTION) $(LDLIBS)

clean::
	@rm -f $(TARGET) $(OBJ) *.d

##################################################
# Gestion des dépendances
ifneq "$(MAKECMDGOALS)" "clean"
-include $(patsubst %.c,%.d,$(SRC))
endif

%.d : %.c Makefile
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -MM -MF $@ -MP -MT $(patsubst %.c, %.o,$<) $<