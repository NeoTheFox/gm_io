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
  OBJDIR     = obj/Server/io
  TARGETDIR  = bin
  TARGET     = $(TARGETDIR)/libgmsv_io_win32.so
  DEFINES   += -DNDEBUG -DSERVER -DLINUX -DGMMODULE
  INCLUDES  += -I../../include -I../../source/LuaOO/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -msse -O2 -ffast-math -fPIC -fPIC
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -shared -fPIC -Lbin
  LIBS      += -lLuaOO
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += bin/libLuaOO.a
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(ARCH) $(LIBS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),client)
  OBJDIR     = obj/Client/io
  TARGETDIR  = bin
  TARGET     = $(TARGETDIR)/libgmcl_io_linux.so
  DEFINES   += -DNDEBUG -DCLIENT -DLINUX -DGMMODULE
  INCLUDES  += -I../../include -I../../source/LuaOO/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -msse -O2 -ffast-math -fPIC -fPIC
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -shared -fPIC -Lbin
  LIBS      += -lLuaOO
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += bin/libLuaOO.a
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(ARCH) $(LIBS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),server32)
  OBJDIR     = obj/x32/Server/io
  TARGETDIR  = bin
  TARGET     = $(TARGETDIR)/libgmsv_io_win32.so
  DEFINES   += -DNDEBUG -DSERVER -DLINUX -DGMMODULE
  INCLUDES  += -I../../include -I../../source/LuaOO/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -msse -O2 -ffast-math -m32 -fPIC -fPIC
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -shared -m32 -L/usr/lib32 -fPIC -Lbin
  LIBS      += -lLuaOO
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += bin/libLuaOO.a
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(ARCH) $(LIBS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),client32)
  OBJDIR     = obj/x32/Client/io
  TARGETDIR  = bin
  TARGET     = $(TARGETDIR)/libgmcl_io_linux.so
  DEFINES   += -DNDEBUG -DCLIENT -DLINUX -DGMMODULE
  INCLUDES  += -I../../include -I../../source/LuaOO/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -msse -O2 -ffast-math -m32 -fPIC -fPIC
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -shared -m32 -L/usr/lib32 -fPIC -Lbin
  LIBS      += -lLuaOO
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += bin/libLuaOO.a
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(ARCH) $(LIBS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

OBJECTS := \
	$(OBJDIR)/io.o \
	$(OBJDIR)/file.o \
	$(OBJDIR)/lua.o \
	$(OBJDIR)/fileObject.o \
	$(OBJDIR)/pathObject.o \
	$(OBJDIR)/path.o \

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
	@echo Linking io
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
	@echo Cleaning io
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

$(OBJDIR)/io.o: ../../source/io/io.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/file.o: ../../source/io/file/file.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/lua.o: ../../source/io/lua/lua.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/fileObject.o: ../../source/io/lua/object/fileObject.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/pathObject.o: ../../source/io/lua/object/pathObject.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/path.o: ../../source/io/path/path.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
