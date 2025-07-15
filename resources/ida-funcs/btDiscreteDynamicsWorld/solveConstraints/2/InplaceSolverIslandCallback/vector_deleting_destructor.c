btDiscreteDynamicsWorld::solveConstraints::__l2::InplaceSolverIslandCallback *__thiscall `btDiscreteDynamicsWorld::solveConstraints'::`2'::InplaceSolverIslandCallback::`vector deleting destructor'(
        btDiscreteDynamicsWorld::solveConstraints::__l2::InplaceSolverIslandCallback *this,
        char a2)
{
  `btDiscreteDynamicsWorld::solveConstraints'::`2'::InplaceSolverIslandCallback::~InplaceSolverIslandCallback(
    this,
    this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
