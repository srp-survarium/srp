btTetrahedronShapeEx *__thiscall GIM_ShapeRetriever::TetraShapeRetriever::getChildShape(
        GIM_ShapeRetriever::TetraShapeRetriever *this,
        int index)
{
  ((void (__stdcall *)(int, btTetrahedronShapeEx *))this->m_parent->m_gim_shape->getBulletTetrahedron)(
    index,
    &this->m_parent->m_tetrashape);
  return &this->m_parent->m_tetrashape;
}
