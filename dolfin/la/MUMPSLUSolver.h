// Copyright (C) 2011 Garth N. Wells
//
// This file is part of DOLFIN.
//
// DOLFIN is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// DOLFIN is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with DOLFIN. If not, see <http://www.gnu.org/licenses/>.
//
// Modified by Garth N. Wells, 2009-2010.
//
// First added:  2011-10-16
// Last changed:

#ifndef __DOLFIN_MUMPS_LU_SOLVER_H
#define __DOLFIN_MUMPS_LU_SOLVER_H

#include <boost/shared_ptr.hpp>

#ifdef PETSC_HAVE_MUMPS

extern "C"
{
#include "dmumps_c.h"
}

namespace dolfin
{
  /// Forward declarations
  class CoordinateMatrix;
  class GenericVector;

  /// This class implements the direct solution (LU factorization) for
  /// linear systems of the form Ax = b. It is a wrapper for the MUMPS
  /// LU solver.

  class MUMPSLUSolver
  {
  public:

    /// Constructor
    MUMPSLUSolver(const CoordinateMatrix& A);

    /// Constructor
    MUMPSLUSolver(boost::shared_ptr<const CoordinateMatrix> A);

    /// Destructor
    ~MUMPSLUSolver();

    /// Solve linear system Ax = b
    unsigned int solve(GenericVector& x, const GenericVector& b);

  private:

    // Operator (the matrix)
    boost::shared_ptr<const CoordinateMatrix> A;

  };

}

#endif

#endif