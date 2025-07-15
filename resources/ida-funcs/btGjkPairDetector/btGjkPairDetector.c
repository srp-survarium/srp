void __userpurge btGjkPairDetector::btGjkPairDetector(
        btGjkPairDetector *this@<esi>,
        btConvexShape *objectA@<ecx>,
        btConvexShape *objectB@<edi>,
        btConvexPenetrationDepthSolver *penetrationDepthSolver@<eax>,
        btVoronoiSimplexSolver *simplexSolver)
{
  float v5; // xmm1_4

  v5 = s_bm_current_air_resistance;
  this->__vftable = (btGjkPairDetector_vtbl *)&btGjkPairDetector::`vftable';
  this->m_cachedSeparatingAxis.mVec128.m128_i32[0] = 0;
  *(unsigned __int64 *)((char *)this->m_cachedSeparatingAxis.mVec128.m128_u64 + 4) = LODWORD(v5);
  this->m_cachedSeparatingAxis.mVec128.m128_i32[3] = 0;
  this->m_penetrationDepthSolver = penetrationDepthSolver;
  this->m_simplexSolver = simplexSolver;
  this->m_minkowskiA = objectA;
  this->m_minkowskiB = objectB;
  this->m_shapeTypeA = objectA->m_shapeType;
  this->m_shapeTypeB = objectB->m_shapeType;
  this->m_marginA = objectA->getMargin(objectA);
  this->m_marginB = objectB->getMargin(objectB);
  this->m_lastUsedMethod = -1;
  this->m_ignoreMargin = 0;
  this->m_catchDegeneracies = 1;
}
