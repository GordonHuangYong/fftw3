/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


#include "fftw/fftw_api.h"
#include "simd-common.h"

#if HAVE_SIMD

FFTW_REAL_TYPE *fftw_taint(FFTW_REAL_TYPE *p, INT s)
{
     if (((unsigned)s * sizeof(FFTW_REAL_TYPE)) % ALIGNMENT)
	  p = (FFTW_REAL_TYPE *) (PTRINT(p) | TAINT_BIT);
     if (((unsigned)s * sizeof(FFTW_REAL_TYPE)) % ALIGNMENTA)
	  p = (FFTW_REAL_TYPE *) (PTRINT(p) | TAINT_BITA);
     return p;
}

/* join the taint of two pointers that are supposed to be
   the same modulo the taint */
FFTW_REAL_TYPE *fftw_join_taint(FFTW_REAL_TYPE *p1, FFTW_REAL_TYPE *p2)
{
     A(UNTAINT(p1) == UNTAINT(p2));
     return (FFTW_REAL_TYPE *)(PTRINT(p1) | PTRINT(p2));
}
#endif
