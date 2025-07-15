void __userpurge btCollisionWorld::ClosestConvexResultCallback::ClosestConvexResultCallback(
        btCollisionWorld::ClosestConvexResultCallback *this@<eax>,
        const btVector3 *convexFromWorld@<edx>,
        const btVector3 *convexToWorld)
{
  this->m_closestHitFraction = s_bm_current_air_resistance;
  this->__vftable = (btCollisionWorld::ClosestConvexResultCallback_vtbl *)&btCollisionWorld::ClosestConvexResultCallback::`vftable';
  this->m_collisionFilterGroup = 1;
  this->m_collisionFilterMask = -1;
  this->m_convexFromWorld = (btVector3)convexFromWorld->mVec128;
  this->m_convexToWorld = (btVector3)convexToWorld->mVec128;
  this->m_hitCollisionObject = 0;
}
