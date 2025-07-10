void __usercall btCollisionWorld::AllHitsRayResultCallback::AllHitsRayResultCallback(
        btCollisionWorld::AllHitsRayResultCallback *this@<eax>,
        const btVector3 *rayFromWorld@<edi>,
        const btVector3 *rayToWorld@<esi>)
{
  LODWORD(this->m_closestHitFraction) = clear_value;
  this->__vftable = (btCollisionWorld::AllHitsRayResultCallback_vtbl *)&btCollisionWorld::AllHitsRayResultCallback::`vftable';
  this->m_collisionObject = 0;
  this->m_flags = 0;
  this->m_collisionFilterGroup = 1;
  this->m_collisionFilterMask = -1;
  this->m_shape_id = -1;
  this->m_collisionObjects.m_ownsMemory = 1;
  this->m_collisionObjects.m_data = 0;
  this->m_collisionObjects.m_size = 0;
  this->m_collisionObjects.m_capacity = 0;
  this->m_rayFromWorld = (btVector3)rayFromWorld->mVec128;
  this->m_rayToWorld = (btVector3)rayToWorld->mVec128;
  this->m_hitNormalWorld.m_ownsMemory = 1;
  this->m_hitNormalWorld.m_data = 0;
  this->m_hitNormalWorld.m_size = 0;
  this->m_hitNormalWorld.m_capacity = 0;
  this->m_hitPointWorld.m_ownsMemory = 1;
  this->m_hitPointWorld.m_data = 0;
  this->m_hitPointWorld.m_size = 0;
  this->m_hitPointWorld.m_capacity = 0;
  this->m_hitFractions.m_ownsMemory = 1;
  this->m_hitFractions.m_data = 0;
  this->m_hitFractions.m_size = 0;
  this->m_hitFractions.m_capacity = 0;
  this->m_triangleIndex.m_ownsMemory = 1;
  this->m_triangleIndex.m_data = 0;
  this->m_triangleIndex.m_size = 0;
  this->m_triangleIndex.m_capacity = 0;
  this->m_is_shape_index.m_ownsMemory = 1;
  this->m_is_shape_index.m_data = 0;
  this->m_is_shape_index.m_size = 0;
  this->m_is_shape_index.m_capacity = 0;
}
