void __userpurge btGjkConvexCast::btGjkConvexCast(
        btGjkConvexCast *this@<eax>,
        btVoronoiSimplexSolver *simplexSolver@<ecx>,
        const btConvexShape *convexA,
        const btConvexShape *convexB)
{
  this->m_simplexSolver = simplexSolver;
  this->__vftable = (btGjkConvexCast_vtbl *)&btGjkConvexCast::`vftable';
  this->m_convexA = convexA;
  this->m_convexB = convexB;
}
