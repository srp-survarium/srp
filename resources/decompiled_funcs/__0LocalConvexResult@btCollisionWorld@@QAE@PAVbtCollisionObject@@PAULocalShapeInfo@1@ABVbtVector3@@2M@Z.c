void __fastcall btCollisionWorld::LocalConvexResult::LocalConvexResult(
        const btVector3 *hitPointLocal,
        const btVector3 *hitNormalLocal,
        btCollisionWorld::LocalConvexResult *this,
        btCollisionObject *hitCollisionObject,
        btCollisionWorld::LocalShapeInfo *localShapeInfo,
        float hitFraction)
{
  this->m_hitCollisionObject = hitCollisionObject;
  this->m_localShapeInfo = localShapeInfo;
  this->m_hitNormalLocal = (btVector3)hitNormalLocal->mVec128;
  this->m_hitPointLocal = (btVector3)hitPointLocal->mVec128;
  this->m_hitFraction = hitFraction;
}
