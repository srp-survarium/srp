btTriangleShapeEx *__thiscall GIM_ShapeRetriever::TriangleShapeRetriever::getChildShape(
        GIM_ShapeRetriever::TriangleShapeRetriever *this,
        int index)
{
  ((void (__stdcall *)(int, btTriangleShapeEx *))this->m_parent->m_gim_shape->getBulletTriangle)(
    index,
    &this->m_parent->m_trishape);
  return &this->m_parent->m_trishape;
}
