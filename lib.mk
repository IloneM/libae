#### Binaries ####
MD = mkdir -p
CP = cp

CPPFLAGS += -Wall -shared -fPIC
NAME = $(strip lib$(EXEC))
#EXEC += .so
#HPP_FILES = $(foreach ext,$(HPP_EXTENSIONS),$(wildcard *.$(ext)))

install: all
	$(MD) $(PATH_INCLUDE)/$(NAME)
	$(CP) $(HPP_FILES) $(PATH_INCLUDE)/$(NAME)
	$(MD) $(PATH_LIB)/$(NAME)
	$(CP) $(EXEC) $(PATH_LIB)/$(NAME)/$(NAME).so
