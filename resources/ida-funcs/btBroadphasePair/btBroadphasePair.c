void __stdcall btBroadphasePair::btBroadphasePair(btBroadphasePair *this)
{
  btBroadphaseProxy *v1; // edx
  btBroadphaseProxy *v2; // ecx

  if ( v1->m_uniqueId >= v2->m_uniqueId )
  {
    this->m_pProxy0 = v2;
    this->m_pProxy1 = v1;
  }
  else
  {
    this->m_pProxy0 = v1;
    this->m_pProxy1 = v2;
  }
  this->m_algorithm = 0;
  this->m_internalTmpValue = 0;
}
