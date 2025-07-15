btDefaultSoftBodySolver *__thiscall btDefaultSoftBodySolver::`scalar deleting destructor'(
        btDefaultSoftBodySolver *this,
        char a2)
{
  btDefaultSoftBodySolver::~btDefaultSoftBodySolver(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
