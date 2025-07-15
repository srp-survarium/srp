void __thiscall btAxisSweep3Internal<unsigned short>::getBroadphaseAabb(
        btAxisSweep3Internal<unsigned short> *this,
        btVector3 *aabbMin,
        btVector3 *aabbMax)
{
  *aabbMin = this->m_worldAabbMin;
  *aabbMax = this->m_worldAabbMax;
}
