void __thiscall btConvexConcaveCollisionAlgorithm::calculateTimeOfImpact_::_5_::LocalTriangleSphereCastCallback::processTriangle(
        btConvexConcaveCollisionAlgorithm::calculateTimeOfImpact::__l5::LocalTriangleSphereCastCallback *this,
        btVector3 *triangle,
        int partId,
        int triangleIndex)
{
  float m_ccdSphereRadius; // xmm2_4
  btSubsimplexConvexCast v6; // [esp+1038h] [ebp-360h] BYREF
  btTransform fromB; // [esp+1048h] [ebp-350h] BYREF
  _DWORD v8[16]; // [esp+1088h] [ebp-310h] BYREF
  btConvexCast::CastResult result; // [esp+10C8h] [ebp-2D0h] BYREF
  btTriangleShape v10; // [esp+1188h] [ebp-210h] BYREF
  char v11; // [esp+1208h] [ebp-190h] BYREF
  float v12; // [esp+1348h] [ebp-50h]
  __int16 v13; // [esp+1368h] [ebp-30h]

  result.m_fraction = this->m_hitFraction;
  m_ccdSphereRadius = this->m_ccdSphereRadius;
  fromB.m_basis.m_el[0].mVec128.m128_u64[0] = (unsigned int)clear_value;
  memset(&fromB.m_basis.m_el[0].m_floats[2], 0, 12);
  *(unsigned __int64 *)((char *)fromB.m_basis.m_el[1].mVec128.m128_u64 + 4) = (unsigned int)clear_value;
  memset(&fromB.m_basis.m_el[1].m_floats[3], 0, 12);
  fromB.m_basis.m_el[2].mVec128.m128_u64[1] = (unsigned int)clear_value;
  memset(&fromB.m_origin, 0, sizeof(fromB.m_origin));
  result.__vftable = (btConvexCast::CastResult_vtbl *)&btConvexCast::CastResult::`vftable';
  result.m_debugDrawer = 0;
  result.m_allowedPenetration = 0.0;
  v8[2] = 0;
  v8[4] = clear_value;
  v8[5] = clear_value;
  v8[6] = clear_value;
  v8[7] = 0;
  v8[0] = &btSphereShape::`vftable';
  v8[1] = 8;
  *(float *)&v8[8] = m_ccdSphereRadius;
  *(float *)&v8[12] = m_ccdSphereRadius;
  btTriangleShape::btTriangleShape(&v10);
  v13 &= 0xFFF0u;
  v6.m_simplexSolver = (btVoronoiSimplexSolver *)&v11;
  v6.m_convexA = (const btConvexShape *)v8;
  v6.m_convexB = &v10;
  v12 = FLOAT_0_000099999997;
  v6.__vftable = (btSubsimplexConvexCast_vtbl *)&btSubsimplexConvexCast::`vftable';
  if ( btSubsimplexConvexCast::calcTimeOfImpact(
         &v6,
         &this->m_ccdSphereFromTrans,
         &this->m_ccdSphereToTrans,
         &fromB,
         &fromB,
         &result)
    && this->m_hitFraction > result.m_fraction )
  {
    this->m_hitFraction = result.m_fraction;
  }
  v10.__vftable = (btTriangleShape_vtbl *)&btPolyhedralConvexShape::`vftable';
  if ( v10.m_polyhedron )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(v10.m_polyhedron);
  }
}
