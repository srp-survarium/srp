void __thiscall btDbvtBroadphase::getAabb(
        btAxisSweep3Internal<unsigned short> *this,
        btBroadphaseProxy *proxy,
        btVector3 *aabbMin,
        btVector3 *aabbMax)
{
  *aabbMin = proxy->m_aabbMin;
  *aabbMax = proxy->m_aabbMax;
}
