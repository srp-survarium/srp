void __usercall btCompoundCollisionAlgorithm::preallocateChildAlgorithms(
        btCompoundCollisionAlgorithm *this@<esi>,
        btCollisionObject *body0@<edx>,
        btCollisionObject *body1@<ecx>)
{
  bool m_isSwapped; // al
  btCollisionObject *v4; // ebp
  int m_shapeType; // ebx
  int m_size; // edi
  int v7; // edx
  int v8; // eax
  btCollisionAlgorithm **v9; // ecx
  btCollisionAlgorithm **m_data; // eax
  int i; // eax
  btCollisionAlgorithm **v12; // ecx
  int v13; // edi
  btCollisionShape *m_collisionShape; // ebx
  btCollisionAlgorithm **v15; // ebp
  btCollisionObject *colObj; // [esp+Ch] [ebp-18h]
  btCollisionAlgorithm **v17; // [esp+10h] [ebp-14h]
  int v18; // [esp+10h] [ebp-14h]
  btCollisionObject *otherObj; // [esp+14h] [ebp-10h]
  int v20; // [esp+18h] [ebp-Ch]
  btCompoundShape *compoundShape; // [esp+1Ch] [ebp-8h]
  int numChildren; // [esp+20h] [ebp-4h]

  m_isSwapped = this->m_isSwapped;
  if ( m_isSwapped )
  {
    v4 = body1;
    colObj = body1;
  }
  else
  {
    colObj = body0;
    v4 = body0;
  }
  otherObj = body0;
  if ( !m_isSwapped )
    otherObj = body1;
  m_shapeType = v4->m_collisionShape[1].m_shapeType;
  m_size = this->m_childCollisionAlgorithms.m_size;
  compoundShape = (btCompoundShape *)v4->m_collisionShape;
  numChildren = m_shapeType;
  v20 = m_size;
  if ( m_shapeType >= m_size )
  {
    if ( m_shapeType > m_size && this->m_childCollisionAlgorithms.m_capacity < m_shapeType )
    {
      if ( m_shapeType )
      {
        ++gNumAlignedAllocs;
        v17 = (btCollisionAlgorithm **)sAlignedAllocFunc(4 * m_shapeType, 16);
      }
      else
      {
        v17 = 0;
      }
      v7 = this->m_childCollisionAlgorithms.m_size;
      v8 = 0;
      if ( v7 > 0 )
      {
        v9 = v17;
        do
        {
          if ( v9 )
          {
            *v9 = this->m_childCollisionAlgorithms.m_data[v8];
            m_size = v20;
          }
          ++v8;
          ++v9;
        }
        while ( v8 < v7 );
      }
      m_data = this->m_childCollisionAlgorithms.m_data;
      if ( m_data )
      {
        if ( this->m_childCollisionAlgorithms.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(m_data);
        }
        this->m_childCollisionAlgorithms.m_data = 0;
      }
      this->m_childCollisionAlgorithms.m_ownsMemory = 1;
      this->m_childCollisionAlgorithms.m_data = v17;
      this->m_childCollisionAlgorithms.m_capacity = m_shapeType;
    }
    for ( i = m_size; i < m_shapeType; ++i )
    {
      v12 = &this->m_childCollisionAlgorithms.m_data[i];
      if ( v12 )
        *v12 = 0;
    }
  }
  v13 = 0;
  this->m_childCollisionAlgorithms.m_size = m_shapeType;
  if ( m_shapeType > 0 )
  {
    v18 = 0;
    do
    {
      if ( compoundShape->m_dynamicAabbTree )
      {
        this->m_childCollisionAlgorithms.m_data[v13] = 0;
      }
      else
      {
        m_collisionShape = v4->m_collisionShape;
        v4->m_collisionShape = compoundShape->m_children.m_data[v18].m_childShape;
        v15 = &this->m_childCollisionAlgorithms.m_data[v13];
        *v15 = this->m_dispatcher->findAlgorithm(this->m_dispatcher, colObj, otherObj, this->m_sharedManifold);
        colObj->m_collisionShape = m_collisionShape;
        m_shapeType = numChildren;
        v4 = colObj;
      }
      ++v18;
      ++v13;
    }
    while ( v13 < m_shapeType );
  }
}
