# GNU Make project makefile autogenerated by Premake
ifndef config
  config=server
endif

ifndef verbose
  SILENT = @
endif

ifndef CC
  CC = gcc
endif

ifndef CXX
  CXX = g++
endif

ifndef AR
  AR = ar
endif

ifeq ($(config),server)
  OBJDIR     = obj/Server/LuaOO
  TARGETDIR  = bin
  TARGET     = $(TARGETDIR)/libLuaOO.a
  DEFINES   += -DNDEBUG -DSERVER -DLINUX -DGMMODULE
  INCLUDES  += -I../../include -I../../source/LuaOO/include
  CPPFLAGS  += -std=c++11 -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -msse -O2 -ffast-math -fPIC
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -fPIC
  LIBS      += 
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),client)
  OBJDIR     = obj/Client/LuaOO
  TARGETDIR  = bin
  TARGET     = $(TARGETDIR)/libLuaOO.a
  DEFINES   += -DNDEBUG -DCLIENT -DLINUX -DGMMODULE
  INCLUDES  += -I../../include -I../../source/LuaOO/include
  CPPFLAGS  += -std=c++11 -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -msse -O2 -ffast-math -fPIC
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -fPIC
  LIBS      += 
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),server32)
  OBJDIR     = obj/x32/Server/LuaOO
  TARGETDIR  = bin
  TARGET     = $(TARGETDIR)/libLuaOO.a
  DEFINES   += -DNDEBUG -DSERVER -DLINUX -DGMMODULE
  INCLUDES  += -I../../include -I../../source/LuaOO/include
  CPPFLAGS  += -std=c++11 -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -msse -O2 -ffast-math -m32 -fPIC
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m32 -L/usr/lib32 -fPIC
  LIBS      += 
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),client32)
  OBJDIR     = obj/x32/Client/LuaOO
  TARGETDIR  = bin
  TARGET     = $(TARGETDIR)/libLuaOO.a
  DEFINES   += -DNDEBUG -DCLIENT -DLINUX -DGMMODULE
  INCLUDES  += -I../../include -I../../source/LuaOO/include
  CPPFLAGS  += -std=c++11 -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -msse -O2 -ffast-math -m32 -fPIC
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m32 -L/usr/lib32 -fPIC
  LIBS      += 
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

OBJECTS := \
	$(OBJDIR)/CLASS_LuaBoundFunction.o \
	$(OBJDIR)/CLASS_LuaClassInfo.o \
	$(OBJDIR)/CLASS_LuaObjectBase.o \
	$(OBJDIR)/CLASS_LuaOO.o \

RESOURCES := \

SHELLTYPE := msdos
ifeq (,$(ComSpec)$(COMSPEC))
  SHELLTYPE := posix
endif
ifeq (/bin,$(findstring /bin,$(SHELL)))
  SHELLTYPE := posix
endif

.PHONY: clean prebuild prelink

all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)
	@:

$(TARGET): $(GCH) $(OBJECTS) $(LDDEPS) $(RESOURCES)
	@echo Linking LuaOO
	$(SILENT) $(LINKCMD)
	$(POSTBUILDCMDS)

$(TARGETDIR):
	@echo Creating $(TARGETDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(TARGETDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(TARGETDIR))
endif

$(OBJDIR):
	@echo Creating $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(OBJDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(OBJDIR))
endif

clean:
	@echo Cleaning LuaOO
ifeq (posix,$(SHELLTYPE))
	$(SILENT) rm -f  $(TARGET)
	$(SILENT) rm -rf $(OBJDIR)
else
	$(SILENT) if exist $(subst /,\\,$(TARGET)) del $(subst /,\\,$(TARGET))
	$(SILENT) if exist $(subst /,\\,$(OBJDIR)) rmdir /s /q $(subst /,\\,$(OBJDIR))
endif

prebuild:
	$(PREBUILDCMDS)

prelink:
	$(PRELINKCMDS)

ifneq (,$(PCH))
$(GCH): $(PCH)
	@echo $(notdir $<)
	-$(SILENT) cp $< $(OBJDIR)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
endif

$(OBJDIR)/CLASS_LuaBoundFunction.o: ../../source/LuaOO/source/CLASS_LuaBoundFunction.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/CLASS_LuaClassInfo.o: ../../source/LuaOO/source/CLASS_LuaClassInfo.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/CLASS_LuaObjectBase.o: ../../source/LuaOO/source/CLASS_LuaObjectBase.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/CLASS_LuaOO.o: ../../source/LuaOO/source/CLASS_LuaOO.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
