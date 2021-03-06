//----------------------------------------------------------------------------
//
// Project      : Call To Power 2
// File type    : C++ source
// Description  : Base actor class
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
// _ACTOR_DRAW_OPTIMIZATION
//
//----------------------------------------------------------------------------
//
// Modifications from the original Activision code:
//
// - Merged constructors and initialised all members.
//
//----------------------------------------------------------------------------
///
/// \file   Actor.cpp
/// \brief  Base actor class

#include "c3.h"
#include "Actor.h"
#include "colorset.h"

Actor::Actor(SpriteState * ss)
:
#if defined(_ACTOR_DRAW_OPTIMIZATION)
    m_paintTwice    (0),
    m_oldOffsetX    (-1),
    m_oldOffsetY    (-1),
    m_oldFrame      (-1),
#endif
    m_isactive      (false),
    m_x             (0),
    m_y             (0),
    m_spriteState   (ss),
    m_morphing      (false)
{ }

Pixel16 Actor::GetHealthBarColor(double healthPercentage)
{
	Pixel16 color = g_colorSet->GetColor(COLOR_GREEN);
	if (healthPercentage < 0.25) {
		color = g_colorSet->GetColor(COLOR_RED);
	} else if (healthPercentage < 0.50) {
		color = g_colorSet->GetColor(COLOR_ORANGE);
	} else if (healthPercentage < 0.75) {
		color = g_colorSet->GetColor(COLOR_YELLOW);
	}
	return color;
}