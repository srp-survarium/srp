void __thiscall btPointCollector::addContactPoint(
        btPointCollector *this,
        const btVector3 *normalOnBInWorld,
        const btVector3 *pointInWorld,
        float depth)
{
  if ( this->m_distance > depth )
  {
    this->m_hasResult = 1;
    this->m_normalOnBInWorld = (btVector3)normalOnBInWorld->mVec128;
    this->m_pointInWorld = (btVector3)pointInWorld->mVec128;
    this->m_distance = depth;
  }
}
