#
# $Id$
#

include $(ctp2_code)/os/autoconf/Makefile.common

noinst_LTLIBRARIES = libgsutility.la

if WIN32
CTP2_WIN32_FREETYPE_INC=\
	-I$(ctp2_code)/ui/freetype
CTP2_WIN32_MILES_INC=\
	-I$(ctp2_code)/libs/miles
CTP2_WIN32_ZLIB_INC=\
	-I$(ctp2_code)/libs/zlib
endif
CTP2_ANET_INC=-I$(ctp2_code)/libs/anet/h

libgsutility_la_LIBADD = \
	../gameobj/libgsgameobj.la

libgsutility_la_SOURCES = \
	AgreementDynArr.cpp \
	checksum.cpp \
	CivDynArr.cpp \
	clock.cpp \
	DataCheck.cpp \
	DiplDynArr.cpp \
	ErrMsg.cpp \
	gameinit.cpp \
	MapFile.cpp \
	MsgDynArr.cpp \
	newturncount.cpp \
	RandGen.cpp \
	stringutils.cpp \
	TradeDynArr.cpp \
	TurnCnt.cpp \
	TurnCntEvent.cpp \
	UnitDynArr.cpp

libgsutility_la_LDFLAGS = -static

AM_CFLAGS=\
	$(CTP2_CFLAGS)

AM_CXXFLAGS=\
	$(CTP2_CXXFLAGS)

AM_CPPFLAGS=\
	$(CTP2_CPPFLAGS)

