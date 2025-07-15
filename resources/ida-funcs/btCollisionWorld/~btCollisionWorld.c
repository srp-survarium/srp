void __thiscall btCollisionWorld::~btCollisionWorld(btCollisionWorld *this)
{
  btCollisionWorld *v1; // esi
  bool v2; // cc
  btCollisionObject *v3; // edi
  btBroadphaseProxy *m_broadphaseHandle; // ebx
  int v5; // eax
  int v6; // [esp+4h] [ebp-4h]

  v6 = 0;
  v1 = this;
  v2 = this->m_collisionObjects.m_size <= 0;
  this->__vftable = (btCollisionWorld_vtbl *)&btCollisionWorld::`vftable';
  if ( !v2 )
  {
    do
    {
      this = (btCollisionWorld *)v6;
      v3 = v1->m_collisionObjects.m_data[v6];
      m_broadphaseHandle = v3->m_broadphaseHandle;
      if ( m_broadphaseHandle )
      {
        v5 = (int)v1->m_broadphasePairCache->getOverlappingPairCache(v1->m_broadphasePairCache);
        (*(void (__thiscall **)(int, btBroadphaseProxy *, btDispatcher *))(*(_DWORD *)v5 + 36))(
          v5,
          m_broadphaseHandle,
          v1->m_dispatcher1);
        v1->m_broadphasePairCache->destroyProxy(v1->m_broadphasePairCache, m_broadphaseHandle, v1->m_dispatcher1);
        v3->m_broadphaseHandle = 0;
      }
      ++v6;
    }
    while ( v6 < v1->m_collisionObjects.m_size );
  }
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)this,
    (int)&v1->m_collisionObjects);
}
