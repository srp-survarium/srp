void __userpurge btContinuousConvexCollision::btContinuousConvexCollision(
        btContinuousConvexCollision *this@<eax>,
        const btConvexShape *convexA@<edx>,
        const btStaticPlaneShape *plane)
{
  this->m_simplexSolver = 0;
  this->m_penetrationDepthSolver = 0;
  this->m_convexB1 = 0;
  this->__vftable = (btContinuousConvexCollision_vtbl *)&btContinuousConvexCollision::`vftable';
  this->m_convexA = convexA;
  this->m_planeShape = plane;
}
