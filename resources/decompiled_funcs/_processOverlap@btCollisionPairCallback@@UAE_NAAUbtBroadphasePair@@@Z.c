bool __thiscall btCollisionPairCallback::processOverlap(btCollisionPairCallback *this, btBroadphasePair *pair)
{
  this->m_dispatcher->m_nearCallback(pair, this->m_dispatcher, this->m_dispatchInfo);
  return 0;
}
