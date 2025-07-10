btSequentialImpulseConstraintSolver *__thiscall btSequentialImpulseConstraintSolver::`scalar deleting destructor'(
        btSequentialImpulseConstraintSolver *this,
        char a2)
{
  btSequentialImpulseConstraintSolver::~btSequentialImpulseConstraintSolver(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
