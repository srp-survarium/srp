void __thiscall btSoftBody::getAabb(btSoftBody *this, btVector3 *aabbMin, btVector3 *aabbMax)
{
  *aabbMin = this->m_bounds[0];
  *aabbMax = this->m_bounds[1];
}
