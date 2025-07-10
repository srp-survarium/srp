void __thiscall btCollisionWorld::addCollisionObject(
        btCollisionWorld *this,
        btCollisionObject *collisionObject,
        int collisionFilterGroup,
        int collisionFilterMask)
{
  int m_capacity; // ecx
  int m_size; // eax
  int v7; // esi
  btCollisionObject **v8; // ebx
  int v9; // edx
  int v10; // eax
  btCollisionObject **v11; // ecx
  btCollisionObject **m_data; // eax
  btCollisionObject **v13; // eax
  btCollisionShape *m_collisionShape; // ecx
  btCollisionObject **v15; // [esp+FCh] [ebp-64h]
  btVector3 v16; // [esp+100h] [ebp-60h] BYREF
  btVector3 v17; // [esp+110h] [ebp-50h] BYREF
  btTransform m_worldTransform; // [esp+120h] [ebp-40h] BYREF

  m_capacity = this->m_collisionObjects.m_capacity;
  m_size = this->m_collisionObjects.m_size;
  if ( m_size == m_capacity )
  {
    v7 = 2 * m_size;
    if ( !m_size )
      v7 = 1;
    if ( m_capacity < v7 )
    {
      if ( v7 )
      {
        ++gNumAlignedAllocs;
        v8 = (btCollisionObject **)sAlignedAllocFunc(4 * v7, 16);
        v15 = v8;
      }
      else
      {
        v8 = 0;
        v15 = 0;
      }
      v9 = this->m_collisionObjects.m_size;
      v10 = 0;
      if ( v9 > 0 )
      {
        v11 = v8;
        do
        {
          if ( v11 )
            *v11 = this->m_collisionObjects.m_data[v10];
          ++v10;
          ++v11;
        }
        while ( v10 < v9 );
        v8 = v15;
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
      this->m_collisionObjects.m_data = v8;
      this->m_collisionObjects.m_capacity = v7;
    }
  }
  v13 = &this->m_collisionObjects.m_data[this->m_collisionObjects.m_size];
  if ( v13 )
    *v13 = collisionObject;
  ++this->m_collisionObjects.m_size;
  m_collisionShape = collisionObject->m_collisionShape;
  m_worldTransform = collisionObject->m_worldTransform;
  m_collisionShape->getAabb(m_collisionShape, &m_worldTransform, &v17, &v16);
  collisionObject->m_broadphaseHandle = this->m_broadphasePairCache->createProxy(
                                          this->m_broadphasePairCache,
                                          &v17,
                                          &v16,
                                          collisionObject->m_collisionShape->m_shapeType,
                                          collisionObject,
                                          collisionFilterGroup,
                                          collisionFilterMask,
                                          this->m_dispatcher1,
                                          0);
}
