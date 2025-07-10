void __thiscall btDbvtBroadphase::getAabb(
        btDbvtBroadphase *this,
        btBroadphaseProxy *absproxy,
        btVector3 *aabbMin,
        btVector3 *aabbMax)
{
  *aabbMin = absproxy->m_aabbMin;
  *aabbMax = absproxy->m_aabbMax;
}
