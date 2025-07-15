btSphereShape *__thiscall btSphereShape::btSphereShape(btSphereShape *this, float radius)
{
  btSphereShape *result; // eax

  result = (btSphereShape *)btConvexInternalShape::btConvexInternalShape(this);
  result->__vftable = (btSphereShape_vtbl *)&btSphereShape::`vftable';
  result->m_shapeType = 8;
  result->m_implicitShapeDimensions.mVec128.m128_f32[0] = radius;
  result->m_collisionMargin = radius;
  return result;
}
