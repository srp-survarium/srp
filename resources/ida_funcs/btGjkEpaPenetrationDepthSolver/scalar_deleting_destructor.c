btMinkowskiPenetrationDepthSolver *__thiscall btGjkEpaPenetrationDepthSolver::`scalar deleting destructor'(
        btMinkowskiPenetrationDepthSolver *this,
        char a2)
{
  this->__vftable = (btMinkowskiPenetrationDepthSolver_vtbl *)&btConvexPenetrationDepthSolver::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
