void __stdcall btManifoldPoint::btManifoldPoint(btManifoldPoint *this, float distance)
{
  const btVector3 *pointB; // edx
  const btVector3 *normal; // ecx
  const btVector3 *pointA; // esi

  this->m_localPointA = (btVector3)pointA->mVec128;
  this->m_localPointB = (btVector3)pointB->mVec128;
  this->m_normalWorldOnB = (btVector3)normal->mVec128;
  this->m_index0 = -1;
  this->m_index1 = -1;
  this->m_distance1 = distance;
  this->m_combinedFriction = 0.0;
  this->m_combinedRestitution = 0.0;
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
  this->mConstraintRow[0].m_accumImpulse = 0.0;
  this->mConstraintRow[1].m_accumImpulse = 0.0;
  this->mConstraintRow[2].m_accumImpulse = 0.0;
}
