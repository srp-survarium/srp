void __thiscall btTriangleIndexVertexArray::setPremadeAabb(
        btTriangleIndexVertexArray *this,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax)
{
  this->m_aabbMin = (btVector3)aabbMin->mVec128;
  this->m_aabbMax = (btVector3)aabbMax->mVec128;
  this->m_hasAabb = 1;
}
