void __thiscall btCollisionWorld::addCollisionObject(
        btCollisionWorld *this,
        btCollisionObject *collisionObject,
        int collisionFilterGroup,
        int collisionFilterMask)
{
  int m_capacity; // ecx
  int m_size; // eax
  int v7; // esi
  int v8; // edx
  int v9; // ecx
  btCollisionObject **v10; // eax
  btCollisionObject **v11; // eax
  btCollisionShape *m_collisionShape; // ecx
  btCollisionObject **v13; // [esp+Ch] [ebp-64h]
  btVector3 v14; // [esp+10h] [ebp-60h] BYREF
  btVector3 v15; // [esp+20h] [ebp-50h] BYREF
  _QWORD v16[2]; // [esp+30h] [ebp-40h] BYREF
  btVector3 v17; // [esp+40h] [ebp-30h]
  unsigned __int64 v18; // [esp+50h] [ebp-20h]
  unsigned __int64 v19; // [esp+58h] [ebp-18h]
  btVector3 v20; // [esp+60h] [ebp-10h]

  m_capacity = this->m_collisionObjects.m_capacity;
  m_size = this->m_collisionObjects.m_size;
  if ( m_size == m_capacity )
  {
    v7 = m_size ? 2 * m_size : 1;
    if ( m_capacity < v7 )
    {
      if ( v7 )
        v13 = (btCollisionObject **)btAlignedAllocInternal(4 * v7);
      else
        v13 = 0;
      v8 = this->m_collisionObjects.m_size;
      v9 = 0;
      if ( v8 > 0 )
      {
        v10 = v13;
        do
        {
          if ( v10 )
            *v10 = this->m_collisionObjects.m_data[v9];
          ++v9;
          ++v10;
        }
        while ( v9 < v8 );
      }
      if ( this->m_collisionObjects.m_data )
      {
        if ( this->m_collisionObjects.m_ownsMemory )
          btAlignedFreeInternal(this->m_collisionObjects.m_data);
        this->m_collisionObjects.m_data = 0;
      }
      this->m_collisionObjects.m_ownsMemory = 1;
      this->m_collisionObjects.m_data = v13;
      this->m_collisionObjects.m_capacity = v7;
    }
  }
  v11 = &this->m_collisionObjects.m_data[this->m_collisionObjects.m_size];
  if ( v11 )
    *v11 = collisionObject;
  ++this->m_collisionObjects.m_size;
  v16[0] = collisionObject->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
  v16[1] = collisionObject->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
  v17.mVec128 = (__m128)collisionObject->m_worldTransform.m_basis.m_el[1];
  v18 = collisionObject->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[0];
  m_collisionShape = collisionObject->m_collisionShape;
  v19 = collisionObject->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[1];
  v20.mVec128 = (__m128)collisionObject->m_worldTransform.m_origin;
  m_collisionShape->getAabb(m_collisionShape, (const btTransform *)v16, &v15, &v14);
  collisionObject->m_broadphaseHandle = this->m_broadphasePairCache->createProxy(
                                          this->m_broadphasePairCache,
                                          &v15,
                                          &v14,
                                          collisionObject->m_collisionShape->m_shapeType,
                                          collisionObject,
                                          collisionFilterGroup,
                                          collisionFilterMask,
                                          this->m_dispatcher1,
                                          0);
}
