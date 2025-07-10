btSphereShape *__userpurge btSphereShape::btSphereShape@<eax>(
        btSphereShape *this@<ecx>,
        btSphereShape *result@<eax>,
        float radius)
{
  const vostok::math::float4x4 *v3; // xmm0_4

  v3 = clear_value;
  result->m_userPointer = 0;
  result->m_localScaling.mVec128.m128_i32[0] = (int)v3;
  result->m_localScaling.mVec128.m128_i32[1] = (int)v3;
  result->m_localScaling.mVec128.m128_i32[2] = (int)v3;
  result->m_localScaling.mVec128.m128_i32[3] = 0;
  result->__vftable = (btSphereShape_vtbl *)&btSphereShape::`vftable';
  result->m_shapeType = 8;
  result->m_implicitShapeDimensions.mVec128.m128_f32[0] = radius;
  result->m_collisionMargin = radius;
  return result;
}
