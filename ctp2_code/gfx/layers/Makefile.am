#
# $Id: Makefile.am 397 2005-06-24 20:58:46Z ctplinuxfan $
#

include $(ctp2_code)/os/autoconf/Makefile.common

noinst_LTLIBRARIES = libgfxlayers.la

if WIN32
CTP2_WIN32_FREETYPE_INC=\
	-I$(ctp2_code)/ui/freetype
CTP2_WIN32_MILES_INC=\
	-I$(ctp2_code)/libs/miles
CTP2_WIN32_ZLIB_INC=\
	-I$(ctp2_code)/libs/zlib
endif
CTP2_ANET_INC=-I$(ctp2_code)/libs/anet/h

libgfxlayers_la_SOURCES = \
	citylayer.cpp

libgfxlayers_la_LDFLAGS = -static

AM_CFLAGS=\
	$(CTP2_CFLAGS)

AM_CXXFLAGS=\
	$(CTP2_CXXFLAGS)

AM_CPPFLAGS=\
	$(CTP2_CPPFLAGS)

