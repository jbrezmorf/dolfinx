// Copyright (C) 2003 Johan Hoffman and Anders Logg.
// Licensed under the GNU GPL Version 2.
//
// Updates by Johan Jansson 2003.

#include <dolfin/dolfin_log.h>
#include <dolfin/Regulator.h>

using namespace dolfin;

//-----------------------------------------------------------------------------
Regulator::Regulator()
{
  k = 0.0;
}
//-----------------------------------------------------------------------------
Regulator::Regulator(real k)
{
  this->k = k;
}
//-----------------------------------------------------------------------------
Regulator::~Regulator()
{
  // Do nothing
}
//-----------------------------------------------------------------------------
void Regulator::init(real k)
{
  cout << "Initializing regulator, k = " << k << endl;
  this->k = k;
}
//-----------------------------------------------------------------------------
void Regulator::update(real k, real kmax, bool kfixed)
{
  if ( kfixed )
    cout << "Choosing fixed time step" << endl;

  cout << "k0 = " << k << endl;

  // Old time step
  real k0 = this->k;

  // Desired time step
  real k1 = k;

  // Compute new time step
  this->k = 2.0 * k0 * k1 / (k0 + k1);

  // Check if we should use a fixed time step
  if ( kfixed )
    this->k = k0;

  // Check kmax
  if(this->k > kmax )
    this->k = kmax;

  cout << "k1 = " << this->k << endl;
  cout << "kmax = " << kmax << endl;
}
//-----------------------------------------------------------------------------
real Regulator::timestep() const
{
  return k;
}
//-----------------------------------------------------------------------------
