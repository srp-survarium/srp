void __thiscall btTriangleShape::getPlane(
        btTriangleShape *this,
        btVector3 *planeNormal,
        btVector3 *planeSupport,
        int i)
{
  this->getPlaneEquation(this, i, planeNormal, planeSupport);
}
