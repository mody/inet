//
// Copyright (C) 2016 OpenSim Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


#ifndef __INET_FIGUREUTIL_H
#define __INET_FIGUREUTIL_H

#include "inet/common/INETDefs.h"

namespace inet {

inline int getFontPointSize(const cFigure::Font& font)
{
    static const int DEFAULT_POINT_SIZE = 12;
    return font.pointSize > 0 ? font.pointSize : DEFAULT_POINT_SIZE;
}

}

#endif
