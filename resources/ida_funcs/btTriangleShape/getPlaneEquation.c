void __thiscall btTriangleShape::getPlaneEquation(
        btTriangleShape *this,
        int i,
        btVector3 *planeNormal,
        btVector3 *planeSupport)
{
  btTriangleShape::calcNormal(this, planeNormal);
  *planeSupport = this->m_vertices1[0];
}
