btConstraintSolver *__thiscall btConstraintSolver::`vector deleting destructor'(btConstraintSolver *this, char a2)
{
  this->__vftable = (btConstraintSolver_vtbl *)&btConstraintSolver::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
