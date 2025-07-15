void __thiscall btSoftBodyConcaveCollisionAlgorithm::calculateTimeOfImpact_::_5_::LocalTriangleSphereCastCallback::processTriangle(
        btSoftBodyConcaveCollisionAlgorithm::calculateTimeOfImpact::__l5::LocalTriangleSphereCastCallback *this,
        btTriangleShape *triangle,
        int partId,
        int triangleIndex)
{
  double m_ccdSphereRadius; // st7
  float m_hitFraction; // xmm0_4
  btSphereShape *v7; // ecx
  float radius; // [esp+0h] [ebp-374h]
  const btVector3 *v9; // [esp+4h] [ebp-370h]
  btSubsimplexConvexCast v10; // [esp+14h] [ebp-360h] BYREF
  btTransform v11; // [esp+24h] [ebp-350h] BYREF
  char v12; // [esp+64h] [ebp-310h] BYREF
  btVoronoiSimplexSolver v13; // [esp+A4h] [ebp-2D0h] BYREF
  float v14; // [esp+2A4h] [ebp-D0h]
  __int16 v15; // [esp+2C4h] [ebp-B0h]
  btPolyhedralConvexShape v16; // [esp+2F4h] [ebp-80h] BYREF

  btMatrix3x3::setIdentity((btMatrix3x3 *)this, (int)&v11);
  m_ccdSphereRadius = this->m_ccdSphereRadius;
  memset(&v11.m_origin, 0, sizeof(v11.m_origin));
  v13.m_simplexPointsQ[0].mVec128.m128_i32[2] = 0;
  m_hitFraction = this->m_hitFraction;
  radius = m_ccdSphereRadius;
  v13.m_numVertices = (int)&btConvexCast::CastResult::`vftable';
  v13.m_simplexPointsQ[0].mVec128.m128_u64[0] = LODWORD(m_hitFraction);
  btSphereShape::btSphereShape(v7, radius);
  btTriangleShape::btTriangleShape(triangle, &v16, &triangle->m_localScaling, &triangle->m_implicitShapeDimensions, v9);
  v15 &= ~1u;
  v15 &= ~2u;
  v15 &= ~4u;
  v15 &= ~8u;
  v10.m_simplexSolver = (btVoronoiSimplexSolver *)&v13.m_simplexPointsQ[1];
  v10.m_convexA = (const btConvexShape *)&v12;
  v10.m_convexB = &v16;
  v14 = FLOAT_0_000099999997;
  v10.__vftable = (btSubsimplexConvexCast_vtbl *)&btSubsimplexConvexCast::`vftable';
  if ( btSubsimplexConvexCast::calcTimeOfImpact(
         &v10,
         &this->m_ccdSphereFromTrans,
         &this->m_ccdSphereToTrans,
         &v11,
         &v11,
         &v13)
    && this->m_hitFraction > v13.m_simplexPointsQ[0].mVec128.m128_f32[0] )
  {
    LODWORD(this->m_hitFraction) = v13.m_simplexPointsQ[0].mVec128.m128_i32[0];
  }
  btPolyhedralConvexShape::~btPolyhedralConvexShape(&v16);
}
