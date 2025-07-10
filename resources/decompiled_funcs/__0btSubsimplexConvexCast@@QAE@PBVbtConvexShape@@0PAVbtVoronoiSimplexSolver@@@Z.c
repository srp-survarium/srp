void __userpurge btSubsimplexConvexCast::btSubsimplexConvexCast(
        btSubsimplexConvexCast *this@<eax>,
        btVoronoiSimplexSolver *simplexSolver@<ecx>,
        const btConvexShape *convexA,
        const btConvexShape *convexB)
{
  this->m_simplexSolver = simplexSolver;
  this->__vftable = (btSubsimplexConvexCast_vtbl *)&btSubsimplexConvexCast::`vftable';
  this->m_convexA = convexA;
  this->m_convexB = convexB;
}
