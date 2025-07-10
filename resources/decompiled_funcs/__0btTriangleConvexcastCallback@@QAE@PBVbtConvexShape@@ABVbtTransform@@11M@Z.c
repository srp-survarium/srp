void __stdcall btTriangleConvexcastCallback::btTriangleConvexcastCallback(
        btTriangleConvexcastCallback *this,
        const btTransform *convexShapeFrom,
        float triangleCollisionMargin)
{
  const btTransform *convexShapeTo; // edx
  const btTransform *triangleToWorld; // ecx
  const btConvexShape *convexShape; // edi

  this->__vftable = (btTriangleConvexcastCallback_vtbl *)&btTriangleConvexcastCallback::`vftable';
  this->m_convexShape = convexShape;
  this->m_convexShapeFrom = *convexShapeFrom;
  this->m_convexShapeTo = *convexShapeTo;
  this->m_triangleToWorld = *triangleToWorld;
  LODWORD(this->m_hitFraction) = clear_value;
  this->m_triangleCollisionMargin = triangleCollisionMargin;
  this->m_allowedPenetration = 0.0;
}
