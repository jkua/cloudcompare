//##########################################################################
//#                                                                        #
//#                               CCLIB                                    #
//#                                                                        #
//#  This program is free software; you can redistribute it and/or modify  #
//#  it under the terms of the GNU Library General Public License as       #
//#  published by the Free Software Foundation; version 2 of the License.  #
//#                                                                        #
//#  This program is distributed in the hope that it will be useful,       #
//#  but WITHOUT ANY WARRANTY; without even the implied warranty of        #
//#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         #
//#  GNU General Public License for more details.                          #
//#                                                                        #
//#          COPYRIGHT: EDF R&D / TELECOM ParisTech (ENST-TSI)             #
//#                                                                        #
//##########################################################################

#ifndef CC_TYPES_HEADER
#define CC_TYPES_HEADER

//system
#include <stdio.h>

//'uchar' shortcut
#ifndef uchar
typedef unsigned char uchar;
#endif

//! Type of the coordinates of a (N-D) point
typedef float PointCoordinateType;

//! Type of a distance value (or more generally of any scalar value)
typedef float DistanceType;

#endif //CC_TYPES_HEADER
