void __thiscall btTriangleShapeEx::getAabb(
        btTriangleShapeEx *this,
        const btTransform *t,
        btVector3 *aabbMin,
        btVector3 *aabbMax)
{
  btAABB v4; // [esp+120h] [ebp-20h] BYREF

  btAABB::btAABB(&v4, this->m_collisionMargin);
  *aabbMin = v4.m_min;
  *aabbMax = v4.m_max;
}
