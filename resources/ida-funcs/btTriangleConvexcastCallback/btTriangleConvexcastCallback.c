void __userpurge btTriangleConvexcastCallback::btTriangleConvexcastCallback(
        btTriangleConvexcastCallback *this@<eax>,
        const btTransform *triangleToWorld@<edx>,
        const btConvexShape *convexShape,
        const btTransform *convexShapeFrom,
        const btTransform *convexShapeTo,
        float triangleCollisionMargin)
{
  float v6; // xmm0_4

  this->__vftable = (btTriangleConvexcastCallback_vtbl *)&btTriangleConvexcastCallback::`vftable';
  this->m_convexShape = convexShape;
  this->m_convexShapeFrom = *convexShapeFrom;
  this->m_convexShapeTo = *convexShapeTo;
  this->m_triangleToWorld.m_basis.m_el[0].mVec128.m128_u64[0] = triangleToWorld->m_basis.m_el[0].mVec128.m128_u64[0];
  this->m_triangleToWorld.m_basis.m_el[0].mVec128.m128_u64[1] = triangleToWorld->m_basis.m_el[0].mVec128.m128_u64[1];
  this->m_triangleToWorld.m_basis.m_el[1] = triangleToWorld->m_basis.m_el[1];
  this->m_triangleToWorld.m_basis.m_el[2] = triangleToWorld->m_basis.m_el[2];
  v6 = s_bm_current_air_resistance;
  this->m_triangleToWorld.m_origin = triangleToWorld->m_origin;
  this->m_hitFraction = v6;
  this->m_triangleCollisionMargin = triangleCollisionMargin;
  this->m_allowedPenetration = 0.0;
}
