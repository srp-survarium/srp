void __thiscall btTriangleShape::getVertex(btTriangleShape *this, int index, btVector3 *vert)
{
  *vert = this->m_vertices1[index];
}
