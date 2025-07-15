void __thiscall btTriangleConvexcastCallback::processTriangle(
        btTriangleConvexcastCallback *this,
        btTriangleShape *triangle,
        int partId,
        int triangleIndex)
{
  float m_triangleCollisionMargin; // xmm0_4
  float m_allowedPenetration; // xmm0_4
  float v7; // xmm0_4
  btTriangleConvexcastCallback_vtbl *v8; // eax
  float v9; // xmm0_4
  const btVector3 *v10; // [esp+Ch] [ebp-300h]
  void **v11; // [esp+20h] [ebp-2ECh] BYREF
  btContinuousConvexCollision v12; // [esp+24h] [ebp-2E8h] BYREF
  btConvexCast::CastResult result; // [esp+3Ch] [ebp-2D0h] BYREF
  btPolyhedralConvexShape v14; // [esp+FCh] [ebp-210h] BYREF
  char v15; // [esp+17Ch] [ebp-190h] BYREF
  float v16; // [esp+2BCh] [ebp-50h]
  __int16 v17; // [esp+2DCh] [ebp-30h]

  btTriangleShape::btTriangleShape(triangle, &v14, &triangle->m_localScaling, &triangle->m_implicitShapeDimensions, v10);
  m_triangleCollisionMargin = this->m_triangleCollisionMargin;
  v17 &= ~1u;
  v17 &= ~2u;
  v12.m_planeShape = 0;
  result.m_debugDrawer = 0;
  v17 &= ~4u;
  v17 &= ~8u;
  v12.m_simplexSolver = (btVoronoiSimplexSolver *)&v15;
  v12.m_penetrationDepthSolver = (btConvexPenetrationDepthSolver *)&v11;
  v12.m_convexA = this->m_convexShape;
  v12.m_convexB1 = &v14;
  v14.m_collisionMargin = m_triangleCollisionMargin;
  v16 = FLOAT_0_000099999997;
  result.m_fraction = s_bm_current_air_resistance;
  m_allowedPenetration = this->m_allowedPenetration;
  v11 = &btGjkEpaPenetrationDepthSolver::`vftable';
  v12.__vftable = (btContinuousConvexCollision_vtbl *)&btContinuousConvexCollision::`vftable';
  result.__vftable = (btConvexCast::CastResult_vtbl *)&btConvexCast::CastResult::`vftable';
  result.m_allowedPenetration = m_allowedPenetration;
  if ( btContinuousConvexCollision::calcTimeOfImpact(
         &v12,
         &this->m_convexShapeFrom,
         &this->m_convexShapeTo,
         &this->m_triangleToWorld,
         &this->m_triangleToWorld,
         &result) )
  {
    v7 = (float)((float)(result.m_normal.mVec128.m128_f32[1] * result.m_normal.mVec128.m128_f32[1])
               + (float)(result.m_normal.mVec128.m128_f32[2] * result.m_normal.mVec128.m128_f32[2]))
       + (float)(result.m_normal.mVec128.m128_f32[0] * result.m_normal.mVec128.m128_f32[0]);
    if ( v7 > 0.000099999997 && this->m_hitFraction > result.m_fraction )
    {
      v8 = this->__vftable;
      v9 = s_bm_current_air_resistance / fsqrt(v7);
      result.m_normal.mVec128.m128_f32[0] = v9 * result.m_normal.mVec128.m128_f32[0];
      result.m_normal.mVec128.m128_f32[1] = result.m_normal.mVec128.m128_f32[1] * v9;
      result.m_normal.mVec128.m128_f32[2] = result.m_normal.mVec128.m128_f32[2] * v9;
      ((void (__thiscall *)(btTriangleConvexcastCallback *, btVector3 *, btVector3 *, _DWORD, int, int))v8->reportHit)(
        this,
        &result.m_normal,
        &result.m_hitPoint,
        LODWORD(result.m_fraction),
        partId,
        triangleIndex);
    }
  }
  result.__vftable = (btConvexCast::CastResult_vtbl *)&btConvexCast::CastResult::`vftable';
  v11 = &btConvexPenetrationDepthSolver::`vftable';
  btPolyhedralConvexShape::~btPolyhedralConvexShape(&v14);
}
