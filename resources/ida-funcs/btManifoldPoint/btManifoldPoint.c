btManifoldPoint *__userpurge btManifoldPoint::btManifoldPoint@<eax>(
        btManifoldPoint *this@<ecx>,
        btManifoldPoint *result@<eax>,
        float a3@<xmm0>,
        const btVector3 *pointB,
        const struct btVector3 *normal,
        const struct btVector3 *a6,
        float a7)
{
  result->m_localPointA.mVec128.m128_u64[0] = this->m_localPointA.mVec128.m128_u64[0];
  result->m_localPointA.mVec128.m128_u64[1] = this->m_localPointA.mVec128.m128_u64[1];
  result->m_localPointB = (btVector3)pointB->mVec128;
  result->m_normalWorldOnB = (btVector3)normal->mVec128;
  result->m_index0 = -1;
  result->m_index1 = -1;
  result->m_distance1 = a3;
  result->m_combinedFriction = 0.0;
  result->m_combinedRestitution = 0.0;
  result->m_userPersistentData = 0;
  result->m_appliedImpulse = 0.0;
  result->m_lateralFrictionInitialized = 0;
  result->m_appliedImpulseLateral1 = 0.0;
  result->m_appliedImpulseLateral2 = 0.0;
  result->m_contactMotion1 = 0.0;
  result->m_contactMotion2 = 0.0;
  result->m_contactCFM1 = 0.0;
  result->m_contactCFM2 = 0.0;
  result->m_lifeTime = 0;
  result->mConstraintRow[0].m_accumImpulse = 0.0;
  result->mConstraintRow[1].m_accumImpulse = 0.0;
  result->mConstraintRow[2].m_accumImpulse = 0.0;
  return result;
}


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
