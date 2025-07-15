btSoftBodySolver *__thiscall btSoftBodySolver::`scalar deleting destructor'(btSoftBodySolver *this, char a2)
{
  this->__vftable = (btSoftBodySolver_vtbl *)&btSoftBodySolver::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
