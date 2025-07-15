void __thiscall btTriangleShape::getEdge(btTriangleShape *this, int i, btVector3 *pa, btVector3 *pb)
{
  this->getVertex(this, i, pa);
  this->getVertex(this, (i + 1) % 3, pb);
}
