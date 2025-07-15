void __thiscall btTriangleShape::getAabb(
        btTriangleShape *this,
        const btTransform *t,
        btVector3 *aabbMin,
        btVector3 *aabbMax)
{
  this->getAabbSlow(this, t, aabbMin, aabbMax);
}
