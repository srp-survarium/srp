void __userpurge btSimulationIslandManager::buildIslands(
        btSimulationIslandManager *this@<ecx>,
        int a2@<esi>,
        btDispatcher *dispatcher,
        btCollisionWorld *collisionWorld)
{
  int v4; // ebx
  int v5; // edi
  int v6; // ecx
  _DWORD *v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int *v12; // ecx
  int v13; // ebx
  _DWORD *v14; // eax
  _DWORD *v15; // ecx
  int v16; // eax
  btCollisionObject *v17; // edi
  int m_activationState1; // edi
  btCollisionObject **v19; // ecx
  btCollisionObject *v20; // edi
  btPersistentManifold *v21; // eax
  btCollisionObject *v22; // ecx
  btCollisionObject *m_body0; // edi
  btCollisionObject *m_body1; // ebx
  int v25; // ecx
  int v26; // eax
  int v27; // edi
  btCollisionObject **m_data; // ecx
  int v29; // eax
  int v30; // edx
  int v31; // eax
  _DWORD *v32; // ecx
  btPersistentManifold **v33; // eax
  int *CompareFuncb; // [esp+8h] [ebp-10h]
  btUnionFindElementSortPredicate CompareFunc[4]; // [esp+8h] [ebp-10h]
  _DWORD *CompareFunca; // [esp+8h] [ebp-10h]
  int v37; // [esp+Ch] [ebp-Ch]
  int v38; // [esp+Ch] [ebp-Ch]
  btPersistentManifold *v39; // [esp+Ch] [ebp-Ch]
  int v40; // [esp+10h] [ebp-8h]
  int v41; // [esp+10h] [ebp-8h]
  char v42; // [esp+17h] [ebp-1h]
  int v43; // [esp+24h] [ebp+Ch]

  v4 = *(_DWORD *)(a2 + 28);
  v5 = 0;
  if ( v4 <= 0 )
  {
    if ( v4 < 0 && *(int *)(a2 + 32) < 0 )
    {
      if ( *(_DWORD *)(a2 + 36) )
      {
        if ( *(_BYTE *)(a2 + 40) )
          btAlignedFreeInternal(*(void **)(a2 + 36));
        *(_DWORD *)(a2 + 36) = 0;
      }
      *(_BYTE *)(a2 + 40) = 1;
      *(_DWORD *)(a2 + 36) = 0;
      *(_DWORD *)(a2 + 32) = 0;
    }
    if ( v4 < 0 )
    {
      v6 = 4 * v4;
      do
      {
        v7 = (_DWORD *)(v6 + *(_DWORD *)(a2 + 36));
        if ( v7 )
          *v7 = 0;
        v6 += 4;
      }
      while ( v6 < 0 );
    }
  }
  *(_DWORD *)(a2 + 28) = 0;
  v37 = *(_DWORD *)(a2 + 8);
  if ( v37 > 0 )
  {
    do
    {
      CompareFuncb = (int *)(*(_DWORD *)(a2 + 16) + 8 * v5);
      v8 = btUnionFind::find((btUnionFind *)(a2 + 4), v5++);
      *CompareFuncb = v8;
    }
    while ( v5 < v37 );
  }
  v9 = *(_DWORD *)(a2 + 8);
  if ( v9 > 1 )
    btAlignedObjectArray<btElement>::quickSortInternal<btUnionFindElementSortPredicate>(
      (btAlignedObjectArray<btElement> *)(a2 + 4),
      0,
      0,
      v9 - 1);
  v10 = 0;
  *(_DWORD *)CompareFunc = *(_DWORD *)(a2 + 8);
  if ( *(int *)CompareFunc > 0 )
  {
    do
    {
      v11 = *(_DWORD *)(a2 + 16);
      v12 = (int *)(v11 + 8 * v10);
      v13 = *v12;
      v38 = *v12;
      v40 = v10 + 1;
      if ( v10 + 1 < *(int *)CompareFunc )
      {
        v14 = (_DWORD *)(v11 + 8 * (v10 + 1));
        do
        {
          if ( *v14 != v13 )
            break;
          ++v40;
          v14 += 2;
        }
        while ( v40 < *(int *)CompareFunc );
      }
      v42 = 1;
      if ( v10 >= v40 )
        goto LABEL_56;
      v15 = v12 + 1;
      v16 = v40 - v10;
      do
      {
        v17 = collisionWorld->m_collisionObjects.m_data[*v15];
        v13 = v38;
        if ( v17->m_islandTag1 == v38 )
        {
          m_activationState1 = v17->m_activationState1;
          if ( m_activationState1 == 1 )
            v42 = 0;
          if ( m_activationState1 == 4 )
          {
            v13 = v38;
            v42 = 0;
          }
        }
        v15 += 2;
        --v16;
      }
      while ( v16 );
      if ( v42 )
      {
LABEL_56:
        while ( v10 < v40 )
        {
          m_data = collisionWorld->m_collisionObjects.m_data;
          v29 = (int)m_data[*(_DWORD *)(*(_DWORD *)(a2 + 16) + 8 * v10 + 4)];
          if ( *(_DWORD *)(v29 + 220) == v13 )
            btCollisionObject::setActivationState((btCollisionObject *)m_data, v29, 2);
          ++v10;
        }
      }
      else
      {
        do
        {
          v19 = collisionWorld->m_collisionObjects.m_data;
          v20 = v19[*(_DWORD *)(*(_DWORD *)(a2 + 16) + 8 * v10 + 4)];
          if ( v20->m_islandTag1 == v13 && v20->m_activationState1 == 2 )
          {
            btCollisionObject::setActivationState((btCollisionObject *)v19, (int)v20, 3);
            v20->m_deactivationTime = 0.0;
          }
          ++v10;
        }
        while ( v10 < v40 );
      }
      v10 = v40;
    }
    while ( v40 < *(int *)CompareFunc );
  }
  v43 = 0;
  v41 = dispatcher->getNumManifolds(dispatcher);
  if ( v41 > 0 )
  {
    do
    {
      v21 = dispatcher->getManifoldByIndexInternal(dispatcher, v43);
      m_body0 = (btCollisionObject *)v21->m_body0;
      m_body1 = (btCollisionObject *)v21->m_body1;
      v39 = v21;
      if ( m_body0 && m_body0->m_activationState1 != 2 || m_body1 && m_body1->m_activationState1 != 2 )
      {
        if ( (m_body0->m_collisionFlags & 2) != 0 && m_body0->m_activationState1 != 2 )
          btCollisionObject::activate(v22, (int)m_body1);
        if ( (m_body1->m_collisionFlags & 2) != 0 && m_body1->m_activationState1 != 2 )
          btCollisionObject::activate(v22, (int)m_body0);
        if ( *(_BYTE *)(a2 + 64) && dispatcher->needsResponse(dispatcher, m_body0, m_body1) )
        {
          v25 = *(_DWORD *)(a2 + 32);
          v26 = *(_DWORD *)(a2 + 28);
          if ( v26 == v25 )
          {
            v27 = v26 ? 2 * v26 : 1;
            if ( v25 < v27 )
            {
              if ( v27 )
                CompareFunca = btAlignedAllocInternal(4 * v27);
              else
                CompareFunca = 0;
              v30 = *(_DWORD *)(a2 + 28);
              v31 = 0;
              if ( v30 > 0 )
              {
                v32 = CompareFunca;
                do
                {
                  if ( v32 )
                    *v32 = *(_DWORD *)(*(_DWORD *)(a2 + 36) + 4 * v31);
                  ++v31;
                  ++v32;
                }
                while ( v31 < v30 );
              }
              if ( *(_DWORD *)(a2 + 36) )
              {
                if ( *(_BYTE *)(a2 + 40) )
                  btAlignedFreeInternal(*(void **)(a2 + 36));
                *(_DWORD *)(a2 + 36) = 0;
              }
              *(_BYTE *)(a2 + 40) = 1;
              *(_DWORD *)(a2 + 36) = CompareFunca;
              *(_DWORD *)(a2 + 32) = v27;
            }
          }
          v33 = (btPersistentManifold **)(*(_DWORD *)(a2 + 36) + 4 * *(_DWORD *)(a2 + 28));
          if ( v33 )
            *v33 = v39;
          ++*(_DWORD *)(a2 + 28);
        }
      }
      ++v43;
    }
    while ( v43 < v41 );
  }
}
