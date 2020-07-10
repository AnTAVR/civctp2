//----------------------------------------------------------------------------
//
// Project      : Call To Power 2
// File type    : C++ source
// Description  : The primitive rectabgles for painting
// Id           : $Id$
//
//----------------------------------------------------------------------------
//
// Disclaimer
//
// THIS FILE IS NOT GENERATED OR SUPPORTED BY ACTIVISION.
//
// This material has been developed at apolyton.net by the Apolyton CtP2
// Source Code Project. Contact the authors at ctp2source@apolyton.net.
//
//----------------------------------------------------------------------------
//
// Compiler flags
//
// - None
//
//----------------------------------------------------------------------------
//
// Modifications from the original Activision code:
//
// - Initialized local variables. (Sep 9th 2005 Martin Gühmann)
// - Standardized code (May 21st 2006 Martin Gühmann)
// - Added primitives_GetScreenAdjustedRectCopy function. (3-Mar-2007 Martin Gühmann)
//
//----------------------------------------------------------------------------

#ifdef HAVE_PRAGMA_ONCE
#pragma once
#endif
#ifndef __PRIMITIVES_H__
#define __PRIMITIVES_H__

#include "pixelutils.h"

#ifndef __AUI_USE_DIRECTX__
#include "aui_textbase.h"
#include "aui_stringtable.h"

class aui_StringTable;
class aui_Surface;
#endif
class aui_Image;
class Pattern;
//enum AUI_TABGROUP_ALIGNMENT;
#include "aui_tabgroup.h"

enum PRIMITIVES_ERRCODE
{
	PRIMITIVES_ERRCODE_OK,
	PRIMITIVES_ERRCODE_INVALIDPARAM,
	PRIMITIVES_ERRCODE_SURFACELOCKFAILED,
	PRIMITIVES_ERRCODE_SURFACEUNLOCKFAILED,
	PRIMITIVES_ERRCODE_DSGETDCFAILED,
	PRIMITIVES_ERRCODE_DSRELEASEDCFAILED
};

struct fRect
{
	float left, top, right, bottom;
};

#ifndef __AUI_USE_DIRECTX__
#include "c3ui.h"
extern C3UI			*g_c3ui;

inline aui_BitmapFont * getBitmapFont()
    {
    aui_BitmapFont *font= NULL;

    font = g_c3ui->LoadBitmapFont("arialbd.ttf"); // using hard coded font name (from TiledMapFontStringTable) because this is needed in the debug version before DB initialization
    Assert(font);
    font->SetPointSize(9); // size set for TiledMapFontStringTable

    return font;
    }
#endif

PRIMITIVES_ERRCODE	primitives_SetRect(RECT *rect,sint32 left,sint32 top,sint32 right,sint32 bottom);
PRIMITIVES_ERRCODE	primitives_FrameRect16(aui_Surface *pSurface,RECT *pRect,Pixel16 color);
PRIMITIVES_ERRCODE	primitives_PaintRect16(aui_Surface *pSurface,RECT *pRect,Pixel16 color);
PRIMITIVES_ERRCODE	primitives_OldBevelRect16(aui_Surface *pSurface, RECT *pRect,sint32 level,BOOL flag);
PRIMITIVES_ERRCODE  primitives_Scale16(aui_Surface *pSrc, aui_Surface *pDst, const fRect &sRect, const fRect &dRect, bool bFilter);

PRIMITIVES_ERRCODE	primitives_DrawLine16(aui_Surface *pSurface,
			  sint32 x1,sint32 y1,sint32 x2,sint32 y2,Pixel16 color);
PRIMITIVES_ERRCODE	primitives_DrawDashedLine16(aui_Surface *pSurface,
			  sint32 x1,sint32 y1,sint32 x2,sint32 y2,Pixel16 color, sint32 length = 0);

PRIMITIVES_ERRCODE	primitives_DrawText(aui_Surface *pDirectSurface,
				sint32 x, sint32 y, const MBCHAR *pString,COLORREF color, bool bg);
PRIMITIVES_ERRCODE	primitives_DrawBoundedText(aui_Surface *pDirectSurface,
				RECT *bound, const MBCHAR *pString,COLORREF color,BOOL bg);
PRIMITIVES_ERRCODE	primitives_DrawTextBatch(aui_Surface *pDirectSurface,sint32 x,sint32 y,
				const MBCHAR **pString,sint32 numStrings,COLORREF color,BOOL bg);
PRIMITIVES_ERRCODE	primitives_DropText(aui_Surface *pDirectSurface,
				sint32 x,sint32 y,const MBCHAR *pString,COLORREF color,BOOL bg);
PRIMITIVES_ERRCODE	primitives_ColoredDropText(aui_Surface *pDirectSurface,
				sint32 x,sint32 y,const MBCHAR *pString,COLORREF textColor,COLORREF dropColor,BOOL bg);
PRIMITIVES_ERRCODE primitives_DropTextCentered(
	aui_Surface *pDirectSurface,
	RECT *destRect,
	const MBCHAR *pString,
	COLORREF color,
	BOOL bg
	);
PRIMITIVES_ERRCODE primitives_ColoredDropTextCentered(
	aui_Surface *pDirectSurface,
	RECT *destRect,
	const MBCHAR *pString,
	COLORREF textColor,
	COLORREF dropColor,
	BOOL bg
	);
PRIMITIVES_ERRCODE	primitives_DropTextBatch(aui_Surface *pDirectSurface,sint32 x,sint32 y,
				const MBCHAR **pString,sint32 numStrings,COLORREF color,BOOL bg);

PRIMITIVES_ERRCODE	primitives_OldBevelPane16(aui_Surface *pSurface, RECT *pRect,sint32 level,BOOL flag);
PRIMITIVES_ERRCODE	primitives_OldBevelTabSelected16(aui_Surface *pSurface, RECT *pRect,sint32 level,BOOL flag);
PRIMITIVES_ERRCODE	primitives_OldBevelTabDeselected16(aui_Surface *pSurface, RECT *pRect,sint32 level,BOOL flag);
PRIMITIVES_ERRCODE	primitives_OldBevelLeftPiece16(aui_Surface *pSurface, sint32 xStart, sint32 xEnd, sint32 y, sint32 level,BOOL flag);
PRIMITIVES_ERRCODE	primitives_OldBevelRightPiece16(aui_Surface *pSurface, sint32 xStart, sint32 xEnd, sint32 y, sint32 level,BOOL flag);

PRIMITIVES_ERRCODE	primitives_BevelPane16(
	aui_Surface *pSurface, RECT *pRect, sint32 level, BOOL flag,
	sint32 blendLight, sint32 blendDark, AUI_TABGROUP_ALIGNMENT a);
PRIMITIVES_ERRCODE	primitives_BevelTabSelected16(
	aui_Surface *pSurface, RECT *pRect, sint32 level, BOOL flag,
	sint32 blendLight, sint32 blendDark, AUI_TABGROUP_ALIGNMENT a);
PRIMITIVES_ERRCODE	primitives_BevelTabDeselected16(
	aui_Surface *pSurface, RECT *pRect, sint32 level, BOOL flag,
	sint32 blendLight, sint32 blendDark, AUI_TABGROUP_ALIGNMENT a);
PRIMITIVES_ERRCODE	primitives_BevelLeftPiece16(
	aui_Surface *pSurface, RECT *tab, RECT *pane, sint32 level,
	BOOL flag, sint32 blendLight, sint32 blendDark, AUI_TABGROUP_ALIGNMENT a);
PRIMITIVES_ERRCODE	primitives_BevelRightPiece16(
	aui_Surface *pSurface, RECT *tab, RECT *pane, sint32 level,
	BOOL flag, sint32 blendLight, sint32 blendDark, AUI_TABGROUP_ALIGNMENT a);

PRIMITIVES_ERRCODE	primitives_BevelRect16(aui_Surface *pSurface, RECT *pRect, sint32 level, BOOL flag, sint32 blendLight, sint32 blendDark);
PRIMITIVES_ERRCODE	primitives_FrameThickRect16(aui_Surface *pSurface, RECT *pRect, Pixel16 color, sint32 level );

PRIMITIVES_ERRCODE	primitives_DrawFrame16(aui_Surface *pSurface,
				aui_Image *pImageUpperLeft, aui_Image *pImageUpperRight, aui_Image *pImageLowerLeft, aui_Image *pImageLowerRight,
				Pattern *pPatternLeft, Pattern *pPatternTop, Pattern *pPatternRight, Pattern *pPatternBottom,
				RECT *pDestRect);

void	primitives_DrawAALine16(aui_Surface *pSurface, sint32 x1, sint32 y1, sint32 x2, sint32 y2, Pixel16 color);
void	primitives_DrawDashedAALine16(aui_Surface *pSurface, sint32 x1, sint32 y1, sint32 x2, sint32 y2, Pixel16 color, sint32 length = 0);

void	primitives_HackStencilDraw(aui_Surface *pSurface);

void	primitives_BlendSurfaces( aui_Surface *pOldSurface, aui_Surface *pNewSurface, aui_Surface *pDstSurface, RECT *pDstRect, sint32 blend );
void	primitives_LightenSurface( aui_Surface *pSurface, sint32 percentLighten );
void	primitives_LightenRect(aui_Surface *pSurface, RECT &rect, sint32 percentLighten);
RECT	primitives_GetScreenAdjustedRectCopy(aui_Surface *surf, RECT &clipRect);

// Clipped primitives
void primitives_ClippedPaintRect16(aui_Surface & surf, const RECT & rect, Pixel16 color,
		uint8 alpha = pixelutils_OPAQUE);
void primitives_ClippedFrameRect16(aui_Surface & surf, const RECT & rect, Pixel16 color,
		uint8 alpha = pixelutils_OPAQUE);
void primitives_ClippedShadowRect16(aui_Surface & surf, const RECT & rect);
void primitives_ClippedAntiAliasedLine16(aui_Surface & surf, sint32 x1, sint32 y1, sint32 x2, sint32 y2, Pixel16 color);

#endif
