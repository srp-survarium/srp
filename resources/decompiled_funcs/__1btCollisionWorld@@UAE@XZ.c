void __thiscall btCollisionWorld::~btCollisionWorld(btCollisionWorld *this)
{
  int v2; // ebx
  bool v3; // cc
  btCollisionObject *v4; // ebp
  btBroadphaseProxy *m_broadphaseHandle; // edi
  btOverlappingPairCache *v6; // eax
  btCollisionObject **m_data; // eax

  v2 = 0;
  v3 = this->m_collisionObjects.m_size <= 0;
  this->__vftable = (btCollisionWorld_vtbl *)&btCollisionWorld::`vftable';
  if ( !v3 )
  {
    do
    {
      v4 = this->m_collisionObjects.m_data[v2];
      m_broadphaseHandle = v4->m_broadphaseHandle;
      if ( m_broadphaseHandle )
      {
        v6 = this->m_broadphasePairCache->getOverlappingPairCache(this->m_broadphasePairCache);
        v6->cleanProxyFromPairs(v6, m_broadphaseHandle, this->m_dispatcher1);
        this->m_broadphasePairCache->destroyProxy(this->m_broadphasePairCache, m_broadphaseHandle, this->m_dispatcher1);
        v4->m_broadphaseHandle = 0;
      }
      ++v2;
    }
    while ( v2 < this->m_collisionObjects.m_size );
  }
  m_data = this->m_collisionObjects.m_data;
  if ( m_data )
  {
    if ( this->m_collisionObjects.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_data);
    }
    this->m_collisionObjects.m_data = 0;
  }
  this->m_collisionObjects.m_ownsMemory = 1;
  this->m_collisionObjects.m_data = 0;
  this->m_collisionObjects.m_size = 0;
  this->m_collisionObjects.m_capacity = 0;
}
