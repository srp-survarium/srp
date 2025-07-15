double __thiscall btClosestNotMeConvexResultCallback::addSingleResult(
        btClosestNotMeConvexResultCallback *this,
        btCollisionWorld::LocalConvexResult *convexResult,
        bool normalInWorldSpace)
{
  if ( convexResult->m_hitCollisionObject == this->m_me
    || (convexResult->m_hitCollisionObject->m_collisionFlags & 4) != 0
    || (float)((float)((float)(convexResult->m_hitNormalLocal.mVec128.m128_f32[2]
                             * (float)(this->m_convexToWorld.mVec128.m128_f32[2]
                                     - this->m_convexFromWorld.mVec128.m128_f32[2]))
                     + (float)(convexResult->m_hitNormalLocal.mVec128.m128_f32[1]
                             * (float)(this->m_convexToWorld.mVec128.m128_f32[1]
                                     - this->m_convexFromWorld.mVec128.m128_f32[1])))
             + (float)(convexResult->m_hitNormalLocal.mVec128.m128_f32[0]
                     * (float)(this->m_convexToWorld.mVec128.m128_f32[0] - this->m_convexFromWorld.mVec128.m128_f32[0]))) >= COERCE_FLOAT(LODWORD(this->m_allowedPenetration) ^ _mask__NegFloat_) )
  {
    return 1.0;
  }
  else
  {
    return btCollisionWorld::ClosestConvexResultCallback::addSingleResult(this, convexResult, normalInWorldSpace);
  }
}
