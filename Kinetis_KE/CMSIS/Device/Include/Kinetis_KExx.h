/*****************************************************************************
 *                   SEGGER Microcontroller GmbH & Co. KG                    *
 *            Solutions for real time microcontroller applications           *
 *****************************************************************************
 *                                                                           *
 *               (c) 2017 SEGGER Microcontroller GmbH & Co. KG               *
 *                                                                           *
 *           Internet: www.segger.com   Support: support@segger.com          *
 *                                                                           *
 *****************************************************************************/

#ifndef __Kinetis_KExx_h
#define __Kinetis_KExx_h

#if defined(MKE02Z16xxx2) || defined(MKE02Z32xxx2) || defined(MKE02Z64xxx2)

#include "MKE02Z2.h"

#elif defined(MKE02Z64xxx4) || defined(MKE02Z32xxx4) || defined(MKE02Z16xxx4)

#include "MKE02Z4.h"

#elif defined(MKE04Z8xxx4)

#include "MKE04Z4.h"

#elif defined(MKE04Z64xxx4) || defined(MKE04Z128xxx4)

#include "MKE04Z1284.h"

#elif defined(MKE06Z64xxx4) || defined(MKE06Z128xxx4)

#include "MKE06Z4.h"

#elif defined(MKE14Z128xxx7) || defined(MKE14Z256xxx7)

#include "MKE14Z7.h"

#elif defined(MKE15Z128xxx7) || defined(MKE15Z256xxx7)

#include "MKE15Z7.h"

#elif defined(MKE14F256xxx16) || defined(MKE14F512xxx16)

#include "MKE14F16.h"

#elif defined(MKE16F256xxx16) || defined(MKE16F512xxx16)

#include "MKE16F16.h"

#elif defined(MKE18F256xxx16) || defined(MKE18F512xxx16)

#include "MKE18F16.h"

#endif

#endif
