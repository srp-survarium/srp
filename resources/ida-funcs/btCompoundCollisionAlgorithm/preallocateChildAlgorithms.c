void __usercall btCompoundCollisionAlgorithm::preallocateChildAlgorithms(
        btCompoundCollisionAlgorithm *this@<esi>,
        btCollisionObject *body0@<edx>,
        btCollisionObject *body1@<ecx>)
{
  bool m_isSwapped; // al
  btCollisionObject *v4; // ebx
  btCollisionShape *m_collisionShape; // edx
  int m_shapeType; // edi
  int m_size; // ecx
  int v8; // ecx
  btCollisionAlgorithm **v9; // eax
  btCollisionAlgorithm **v10; // eax
  btCollisionShape *v11; // edi
  btCollisionAlgorithm **v12; // ebx
  int v13; // [esp+8h] [ebp-1Ch]
  int v14; // [esp+Ch] [ebp-18h]
  btCollisionObject *v15; // [esp+10h] [ebp-14h]
  btCollisionShape *v16; // [esp+14h] [ebp-10h]
  int v17; // [esp+18h] [ebp-Ch]
  int v18; // [esp+18h] [ebp-Ch]
  btCollisionAlgorithm **v19; // [esp+1Ch] [ebp-8h]
  int v20; // [esp+1Ch] [ebp-8h]
  btCollisionObject *v21; // [esp+20h] [ebp-4h]

  m_isSwapped = this->m_isSwapped;
  if ( m_isSwapped )
  {
    v4 = body1;
    v21 = body1;
  }
  else
  {
    v21 = body0;
    v4 = body0;
  }
  v15 = body0;
  if ( !m_isSwapped )
    v15 = body1;
  m_collisionShape = v4->m_collisionShape;
  m_shapeType = m_collisionShape[1].m_shapeType;
  m_size = this->m_childCollisionAlgorithms.m_size;
  v16 = m_collisionShape;
  v13 = m_shapeType;
  v14 = m_size;
  if ( m_shapeType >= m_size )
  {
    if ( m_shapeType > m_size && this->m_childCollisionAlgorithms.m_capacity < m_shapeType )
    {
      if ( m_shapeType )
        v19 = (btCollisionAlgorithm **)btAlignedAllocInternal(4 * m_shapeType);
      else
        v19 = 0;
      v8 = 0;
      v17 = this->m_childCollisionAlgorithms.m_size;
      if ( v17 > 0 )
      {
        v9 = v19;
        do
        {
          if ( v9 )
            *v9 = this->m_childCollisionAlgorithms.m_data[v8];
          ++v8;
          ++v9;
        }
        while ( v8 < v17 );
      }
      if ( this->m_childCollisionAlgorithms.m_data )
      {
        if ( this->m_childCollisionAlgorithms.m_ownsMemory )
          btAlignedFreeInternal(this->m_childCollisionAlgorithms.m_data);
        this->m_childCollisionAlgorithms.m_data = 0;
      }
      m_size = v14;
      m_collisionShape = v16;
      this->m_childCollisionAlgorithms.m_ownsMemory = 1;
      this->m_childCollisionAlgorithms.m_data = v19;
      this->m_childCollisionAlgorithms.m_capacity = m_shapeType;
    }
    while ( m_size < m_shapeType )
    {
      v10 = &this->m_childCollisionAlgorithms.m_data[m_size];
      if ( v10 )
        *v10 = 0;
      ++m_size;
    }
  }
  v20 = 0;
  this->m_childCollisionAlgorithms.m_size = m_shapeType;
  if ( m_shapeType > 0 )
  {
    v18 = 0;
    while ( 1 )
    {
      if ( m_collisionShape[5].m_shapeType )
      {
        this->m_childCollisionAlgorithms.m_data[v20] = 0;
      }
      else
      {
        v11 = v4->m_collisionShape;
        v4->m_collisionShape = *(btCollisionShape **)((char *)&m_collisionShape[2].__vftable[1].getBoundingSphere + v18);
        v12 = &this->m_childCollisionAlgorithms.m_data[v20];
        *v12 = this->m_dispatcher->findAlgorithm(this->m_dispatcher, v21, v15, this->m_sharedManifold);
        v21->m_collisionShape = v11;
        m_shapeType = v13;
        v4 = v21;
      }
      ++v20;
      v18 += 80;
      if ( v20 >= m_shapeType )
        break;
      m_collisionShape = v16;
    }
  }
}
