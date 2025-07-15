void __thiscall btTriangleConvexcastCallback::processTriangle(
        btTriangleConvexcastCallback *this,
        btVector3 *triangle,
        int partId,
        int triangleIndex)
{
  float m_triangleCollisionMargin; // xmm0_4
  const btConvexShape *m_convexShape; // edx
  float m_allowedPenetration; // xmm0_4
  long double v8; // st7
  float (__thiscall *reportHit)(btTriangleConvexcastCallback *, const btVector3 *, const btVector3 *, float, int, int); // edx
  void **v10; // [esp+C58h] [ebp-2F0h] BYREF
  float _X; // [esp+C5Ch] [ebp-2ECh]
  btContinuousConvexCollision v12; // [esp+C60h] [ebp-2E8h] BYREF
  btConvexCast::CastResult result; // [esp+C78h] [ebp-2D0h] BYREF
  btTriangleShape v14; // [esp+D38h] [ebp-210h] BYREF
  char v15; // [esp+DB8h] [ebp-190h] BYREF
  float v16; // [esp+EF8h] [ebp-50h]
  __int16 v17; // [esp+F18h] [ebp-30h]

  btTriangleShape::btTriangleShape(&v14);
  m_triangleCollisionMargin = this->m_triangleCollisionMargin;
  m_convexShape = this->m_convexShape;
  v17 &= 0xFFF0u;
  v12.m_simplexSolver = (btVoronoiSimplexSolver *)&v15;
  v12.m_penetrationDepthSolver = (btConvexPenetrationDepthSolver *)&v10;
  v12.m_convexB1 = &v14;
  v14.m_collisionMargin = m_triangleCollisionMargin;
  v12.m_convexA = m_convexShape;
  v16 = FLOAT_0_000099999997;
  LODWORD(result.m_fraction) = clear_value;
  m_allowedPenetration = this->m_allowedPenetration;
  v10 = &btGjkEpaPenetrationDepthSolver::`vftable';
  v12.__vftable = (btContinuousConvexCollision_vtbl *)&btContinuousConvexCollision::`vftable';
  v12.m_planeShape = 0;
  result.__vftable = (btConvexCast::CastResult_vtbl *)&btConvexCast::CastResult::`vftable';
  result.m_debugDrawer = 0;
  result.m_allowedPenetration = m_allowedPenetration;
  if ( btContinuousConvexCollision::calcTimeOfImpact(
         &v12,
         &this->m_convexShapeFrom,
         &this->m_convexShapeTo,
         &this->m_triangleToWorld,
         &this->m_triangleToWorld,
         &result) )
  {
    _X = (float)((float)(result.m_normal.mVec128.m128_f32[1] * result.m_normal.mVec128.m128_f32[1])
               + (float)(result.m_normal.mVec128.m128_f32[2] * result.m_normal.mVec128.m128_f32[2]))
       + (float)(result.m_normal.mVec128.m128_f32[0] * result.m_normal.mVec128.m128_f32[0]);
    if ( _X > 0.000099999997 && this->m_hitFraction > result.m_fraction )
    {
      v8 = 1.0 / sqrtf(_X);
      reportHit = this->reportHit;
      result.m_normal.mVec128.m128_f32[0] = result.m_normal.mVec128.m128_f32[0] * v8;
      result.m_normal.mVec128.m128_f32[1] = result.m_normal.mVec128.m128_f32[1] * v8;
      result.m_normal.mVec128.m128_f32[2] = v8 * result.m_normal.mVec128.m128_f32[2];
      ((void (__thiscall *)(btTriangleConvexcastCallback *, btVector3 *, btVector3 *, _DWORD, int, int))reportHit)(
        this,
        &result.m_normal,
        &result.m_hitPoint,
        LODWORD(result.m_fraction),
        partId,
        triangleIndex);
    }
  }
  result.__vftable = (btConvexCast::CastResult_vtbl *)&btConvexCast::CastResult::`vftable';
  v10 = &btConvexPenetrationDepthSolver::`vftable';
  v14.__vftable = (btTriangleShape_vtbl *)&btPolyhedralConvexShape::`vftable';
  if ( v14.m_polyhedron )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(v14.m_polyhedron);
  }
}
