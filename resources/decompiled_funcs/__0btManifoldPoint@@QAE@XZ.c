btManifoldPoint *__thiscall btManifoldPoint::btManifoldPoint(btManifoldPoint *this)
{
  btManifoldPoint *result; // eax

  result = this;
  this->m_index0 = -1;
  this->m_index1 = -1;
  this->m_userPersistentData = 0;
  this->m_appliedImpulse = 0.0;
  this->m_lateralFrictionInitialized = 0;
  this->m_appliedImpulseLateral1 = 0.0;
  this->m_appliedImpulseLateral2 = 0.0;
  this->m_contactMotion1 = 0.0;
  this->m_contactMotion2 = 0.0;
  this->m_contactCFM1 = 0.0;
  this->m_contactCFM2 = 0.0;
  this->m_lifeTime = 0;
  return result;
}
