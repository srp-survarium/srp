void __userpurge btSimulationIslandManager::buildAndProcessIslands(
        btSimulationIslandManager *this@<ecx>,
        btDispatcher *dispatcher@<eax>,
        btCollisionWorld *collisionWorld,
        btSimulationIslandManager::IslandCallback *callback)
{
  btCollisionWorld *v4; // ebx
  btPersistentManifold **v7; // esi
  int v8; // eax
  int v9; // eax
  btElement *v10; // eax
  btCollisionObject *v11; // ebx
  int m_capacity; // ecx
  int v13; // eax
  int v14; // edi
  int v15; // edx
  int v16; // eax
  btCollisionObject **v17; // ecx
  btCollisionObject **v18; // eax
  int m_activationState1; // eax
  btPersistentManifold **m_data; // ebx
  int v21; // edi
  const btPersistentManifold **v22; // ebx
  int v23; // edi
  int v24; // ecx
  btCollisionObject **v25; // eax
  btPersistentManifoldSortPredicate CompareFunc[4]; // [esp+Ch] [ebp-24h]
  btPersistentManifold **CompareFunca; // [esp+Ch] [ebp-24h]
  int v28; // [esp+10h] [ebp-20h]
  int v29; // [esp+14h] [ebp-1Ch]
  btCollisionObject **v30; // [esp+18h] [ebp-18h]
  int v31; // [esp+18h] [ebp-18h]
  int m_size; // [esp+1Ch] [ebp-14h]
  int v33; // [esp+20h] [ebp-10h]
  int m_id; // [esp+24h] [ebp-Ch]
  int v35; // [esp+28h] [ebp-8h]
  char v36; // [esp+2Fh] [ebp-1h]

  v4 = collisionWorld;
  btSimulationIslandManager::buildIslands(this, (int)this, dispatcher, collisionWorld);
  m_size = this->m_unionFind.m_elements.m_size;
  if ( this->m_splitIslands )
  {
    v29 = this->m_islandmanifold.m_size;
    if ( v29 > 1 )
      btAlignedObjectArray<btPersistentManifold *>::quickSortInternal<btPersistentManifoldSortPredicate>(
        &this->m_islandmanifold,
        0,
        0,
        v29 - 1);
    v9 = 0;
    v33 = 0;
    v28 = 1;
    if ( m_size > 0 )
    {
      while ( 1 )
      {
        m_id = this->m_unionFind.m_elements.m_data[v9].m_id;
        v36 = 1;
        v35 = v9;
        if ( v9 < m_size )
        {
          while ( 1 )
          {
            v10 = &this->m_unionFind.m_elements.m_data[v35];
            if ( v10->m_id != m_id )
              break;
            v11 = v4->m_collisionObjects.m_data[v10->m_sz];
            m_capacity = this->m_islandBodies.m_capacity;
            v13 = this->m_islandBodies.m_size;
            *(_DWORD *)CompareFunc = v11;
            if ( v13 == m_capacity )
            {
              v14 = v13 ? 2 * v13 : 1;
              if ( m_capacity < v14 )
              {
                if ( v14 )
                  v30 = (btCollisionObject **)btAlignedAllocInternal(4 * v14);
                else
                  v30 = 0;
                v15 = this->m_islandBodies.m_size;
                v16 = 0;
                if ( v15 > 0 )
                {
                  v17 = v30;
                  do
                  {
                    if ( v17 )
                    {
                      *v17 = this->m_islandBodies.m_data[v16];
                      v11 = *(btCollisionObject **)CompareFunc;
                    }
                    ++v16;
                    ++v17;
                  }
                  while ( v16 < v15 );
                }
                if ( this->m_islandBodies.m_data )
                {
                  if ( this->m_islandBodies.m_ownsMemory )
                    btAlignedFreeInternal(this->m_islandBodies.m_data);
                  this->m_islandBodies.m_data = 0;
                }
                this->m_islandBodies.m_ownsMemory = 1;
                this->m_islandBodies.m_data = v30;
                this->m_islandBodies.m_capacity = v14;
              }
            }
            v18 = &this->m_islandBodies.m_data[this->m_islandBodies.m_size];
            if ( v18 )
              *v18 = v11;
            ++this->m_islandBodies.m_size;
            m_activationState1 = v11->m_activationState1;
            if ( m_activationState1 != 2 && m_activationState1 != 5 )
              v36 = 0;
            if ( ++v35 >= m_size )
              break;
            v4 = collisionWorld;
          }
        }
        v31 = 0;
        CompareFunca = 0;
        if ( v33 < v29 )
        {
          m_data = this->m_islandmanifold.m_data;
          if ( getIslandId(m_data[v33]) == m_id )
          {
            CompareFunca = &m_data[v33];
            v21 = v33 + 1;
            v28 = v33 + 1;
            if ( v33 + 1 < v29 )
            {
              v22 = (const btPersistentManifold **)&m_data[v21];
              do
              {
                if ( m_id != getIslandId(*v22) )
                  break;
                ++v21;
                ++v22;
                v28 = v21;
              }
              while ( v21 < v29 );
            }
            v31 = v21 - v33;
          }
        }
        if ( !v36 )
          callback->ProcessIsland(
            callback,
            this->m_islandBodies.m_data,
            this->m_islandBodies.m_size,
            CompareFunca,
            v31,
            m_id);
        if ( v31 )
          v33 = v28;
        v23 = this->m_islandBodies.m_size;
        if ( v23 <= 0 )
        {
          if ( v23 < 0 && this->m_islandBodies.m_capacity < 0 )
          {
            if ( this->m_islandBodies.m_data )
            {
              if ( this->m_islandBodies.m_ownsMemory )
                btAlignedFreeInternal(this->m_islandBodies.m_data);
              this->m_islandBodies.m_data = 0;
            }
            this->m_islandBodies.m_ownsMemory = 1;
            this->m_islandBodies.m_data = 0;
            this->m_islandBodies.m_capacity = 0;
          }
          if ( v23 < 0 )
          {
            v24 = v23;
            do
            {
              v25 = &this->m_islandBodies.m_data[v24];
              if ( v25 )
                *v25 = 0;
              ++v24;
            }
            while ( v24 < 0 );
          }
        }
        v9 = v35;
        this->m_islandBodies.m_size = 0;
        if ( v35 >= m_size )
          break;
        v4 = collisionWorld;
      }
    }
  }
  else
  {
    v7 = dispatcher->getInternalManifoldPointer(dispatcher);
    v8 = dispatcher->getNumManifolds(dispatcher);
    callback->ProcessIsland(
      callback,
      collisionWorld->m_collisionObjects.m_data,
      collisionWorld->m_collisionObjects.m_size,
      v7,
      v8,
      -1);
  }
}
