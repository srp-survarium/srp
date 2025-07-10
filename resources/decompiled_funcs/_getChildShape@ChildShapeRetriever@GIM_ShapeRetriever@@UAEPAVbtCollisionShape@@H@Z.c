btCollisionShape *__thiscall GIM_ShapeRetriever::ChildShapeRetriever::getChildShape(
        GIM_ShapeRetriever::ChildShapeRetriever *this,
        int index)
{
  return this->m_parent->m_gim_shape->getChildShape(this->m_parent->m_gim_shape, index);
}
