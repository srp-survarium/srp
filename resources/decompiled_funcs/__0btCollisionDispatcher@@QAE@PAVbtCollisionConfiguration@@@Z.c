void __usercall btCollisionDispatcher::btCollisionDispatcher(
        btCollisionDispatcher *this@<esi>,
        btCollisionConfiguration *collisionConfiguration@<eax>)
{
  int v3; // ebp
  btCollisionAlgorithmCreateFunc **v4; // ebx
  int i; // edi

  this->__vftable = (btCollisionDispatcher_vtbl *)&btCollisionDispatcher::`vftable';
  this->m_dispatcherFlags = 2;
  this->m_manifoldsPtr.m_ownsMemory = 1;
  v3 = 0;
  this->m_manifoldsPtr.m_data = 0;
  this->m_manifoldsPtr.m_size = 0;
  this->m_manifoldsPtr.m_capacity = 0;
  this->m_defaultManifoldResult.__vftable = (btManifoldResult_vtbl *)&btManifoldResult::`vftable';
  this->m_defaultManifoldResult.m_partId0 = -1;
  this->m_defaultManifoldResult.m_partId1 = -1;
  this->m_defaultManifoldResult.m_index0 = -1;
  this->m_defaultManifoldResult.m_index1 = -1;
  this->m_collisionConfiguration = collisionConfiguration;
  this->m_nearCallback = btCollisionDispatcher::defaultNearCallback;
  this->m_collisionAlgorithmPoolAllocator = collisionConfiguration->getCollisionAlgorithmPool(collisionConfiguration);
  this->m_persistentManifoldPoolAllocator = collisionConfiguration->getPersistentManifoldPool(collisionConfiguration);
  v4 = this->m_doubleDispatch[0];
  do
  {
    for ( i = 0; i < 36; ++i )
      *v4++ = this->m_collisionConfiguration->getCollisionAlgorithmCreateFunc(this->m_collisionConfiguration, v3, i);
    ++v3;
  }
  while ( v3 < 36 );
}
