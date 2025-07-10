void __thiscall btTriangleIndexVertexArray::getPremadeAabb(
        btTriangleIndexVertexArray *this,
        btVector3 *aabbMin,
        btVector3 *aabbMax)
{
  *aabbMin = this->m_aabbMin;
  *aabbMax = this->m_aabbMax;
}
