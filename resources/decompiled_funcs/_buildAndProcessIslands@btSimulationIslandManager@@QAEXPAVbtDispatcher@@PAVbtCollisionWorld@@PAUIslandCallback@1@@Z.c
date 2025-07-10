void __userpurge btSimulationIslandManager::buildAndProcessIslands(
        btSimulationIslandManager *this@<ecx>,
        int a2@<eax>,
        btDispatcher *dispatcher,
        btCollisionWorld *collisionWorld,
        btSimulationIslandManager::IslandCallback *callback)
{
  const char *v6; // ecx
  CProfileNode *v7; // edi
  CProfileNode *v8; // eax
  int RecursionCounter; // eax
  btPersistentManifold **v10; // esi
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  _DWORD *v14; // eax
  btCollisionObject *v15; // ebx
  int v16; // ecx
  int v17; // eax
  int v18; // edi
  _DWORD *v19; // ebp
  int v20; // edx
  int v21; // eax
  _DWORD *v22; // ecx
  void *v23; // eax
  btCollisionObject **v24; // eax
  int m_activationState1; // eax
  int v26; // ebp
  btPersistentManifold **v27; // ebx
  int v28; // edi
  int v29; // edx
  int v30; // ebp
  int v31; // edx
  int v32; // edi
  void *v33; // eax
  btAlignedAllocator<btPersistentManifold *,16> *v34; // eax
  bool v35; // zf
  int *p_RecursionCounter; // ebp
  CProfileNode *v37; // esi
  int endManifoldIndex; // [esp+14h] [ebp-1Ch]
  int islandId; // [esp+18h] [ebp-18h]
  int startManifoldIndex; // [esp+1Ch] [ebp-14h]
  int numElem; // [esp+20h] [ebp-10h]
  int numManifolds; // [esp+24h] [ebp-Ch]
  int endIslandIndex; // [esp+28h] [ebp-8h]
  char islandSleeping; // [esp+34h] [ebp+4h]
  btCollisionWorld *collisionWorlda; // [esp+38h] [ebp+8h]

  btSimulationIslandManager::buildIslands(this, (btPersistentManifold *)a2, dispatcher, (int)collisionWorld);
  v7 = CProfileManager::CurrentNode;
  numElem = *(_DWORD *)(a2 + 8);
  if ( CProfileManager::CurrentNode->Name != "processIslands" )
  {
    CProfileNode::Get_Sub_Node(v6, "processIslands");
    v7 = v8;
    CProfileManager::CurrentNode = v8;
  }
  RecursionCounter = v7->RecursionCounter;
  ++v7->TotalCalls;
  v7->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
  {
    v7->StartTime = btClock::getTimeMicroseconds((btClock *)1);
    v7 = CProfileManager::CurrentNode;
  }
  if ( !*(_BYTE *)(a2 + 64) )
  {
    v10 = dispatcher->getInternalManifoldPointer(dispatcher);
    v11 = dispatcher->getNumManifolds(dispatcher);
    callback->ProcessIsland(
      callback,
      collisionWorld->m_collisionObjects.m_data,
      collisionWorld->m_collisionObjects.m_size,
      v10,
      v11,
      -1);
LABEL_65:
    v7 = CProfileManager::CurrentNode;
    goto LABEL_66;
  }
  v12 = a2 + 24;
  numManifolds = *(_DWORD *)(a2 + 28);
  if ( numManifolds > 1 )
    btAlignedObjectArray<btPersistentManifold *>::quickSortInternal<btPersistentManifoldSortPredicate>(
      (btAlignedObjectArray<btPersistentManifold *> *)v12,
      0,
      0,
      numManifolds - 1);
  v13 = 0;
  startManifoldIndex = 0;
  endManifoldIndex = 1;
  if ( numElem > 0 )
  {
    do
    {
      islandId = *(_DWORD *)(*(_DWORD *)(a2 + 16) + 8 * v13);
      v12 = v13;
      islandSleeping = 1;
      for ( endIslandIndex = v13; endIslandIndex < numElem; v12 = ++endIslandIndex )
      {
        v14 = (_DWORD *)(*(_DWORD *)(a2 + 16) + 8 * v12);
        v12 = islandId;
        if ( *v14 != islandId )
          break;
        v15 = collisionWorld->m_collisionObjects.m_data[v14[1]];
        v16 = *(_DWORD *)(a2 + 52);
        v17 = *(_DWORD *)(a2 + 48);
        if ( v17 == v16 )
        {
          v18 = 2 * v17;
          if ( !v17 )
            v18 = 1;
          if ( v16 < v18 )
          {
            if ( v18 )
            {
              ++gNumAlignedAllocs;
              v19 = sAlignedAllocFunc(4 * v18, 16);
            }
            else
            {
              v19 = 0;
            }
            v20 = *(_DWORD *)(a2 + 48);
            v21 = 0;
            if ( v20 > 0 )
            {
              v22 = v19;
              do
              {
                if ( v22 )
                  *v22 = *(_DWORD *)(*(_DWORD *)(a2 + 56) + 4 * v21);
                ++v21;
                ++v22;
              }
              while ( v21 < v20 );
            }
            v23 = *(void **)(a2 + 56);
            if ( v23 )
            {
              if ( *(_BYTE *)(a2 + 60) )
              {
                ++gNumAlignedFree;
                sAlignedFreeFunc(v23);
              }
              *(_DWORD *)(a2 + 56) = 0;
            }
            *(_BYTE *)(a2 + 60) = 1;
            *(_DWORD *)(a2 + 56) = v19;
            *(_DWORD *)(a2 + 52) = v18;
          }
        }
        v24 = (btCollisionObject **)(*(_DWORD *)(a2 + 56) + 4 * *(_DWORD *)(a2 + 48));
        if ( v24 )
          *v24 = v15;
        ++*(_DWORD *)(a2 + 48);
        m_activationState1 = v15->m_activationState1;
        if ( m_activationState1 != 2 && m_activationState1 != 5 )
          islandSleeping = 0;
      }
      v26 = 0;
      v27 = 0;
      if ( startManifoldIndex < numManifolds )
      {
        v28 = *(_DWORD *)(a2 + 36);
        v12 = *(_DWORD *)(v28 + 4 * startManifoldIndex);
        v29 = *(_DWORD *)(*(_DWORD *)(v12 + 1168) + 220);
        if ( v29 < 0 )
          v29 = *(_DWORD *)(*(_DWORD *)(v12 + 1172) + 220);
        if ( v29 == islandId )
        {
          v30 = startManifoldIndex + 1;
          v27 = (btPersistentManifold **)(v28 + 4 * startManifoldIndex);
          endManifoldIndex = startManifoldIndex + 1;
          if ( startManifoldIndex + 1 < numManifolds )
          {
            v31 = v28 + 4 * v30;
            do
            {
              v12 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v31 + 1168) + 220);
              if ( v12 < 0 )
                v12 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v31 + 1172) + 220);
              if ( islandId != v12 )
                break;
              v31 += 4;
              ++endManifoldIndex;
            }
            while ( endManifoldIndex < numManifolds );
            v30 = endManifoldIndex;
          }
          v26 = v30 - startManifoldIndex;
        }
      }
      if ( !islandSleeping )
        callback->ProcessIsland(callback, *(btCollisionObject ***)(a2 + 56), *(_DWORD *)(a2 + 48), v27, v26, islandId);
      if ( v26 )
        startManifoldIndex = endManifoldIndex;
      v32 = *(_DWORD *)(a2 + 48);
      if ( v32 <= 0 )
      {
        if ( v32 < 0 && *(int *)(a2 + 52) < 0 )
        {
          v33 = *(void **)(a2 + 56);
          if ( v33 )
          {
            if ( *(_BYTE *)(a2 + 60) )
            {
              ++gNumAlignedFree;
              sAlignedFreeFunc(v33);
            }
            *(_DWORD *)(a2 + 56) = 0;
          }
          *(_BYTE *)(a2 + 60) = 1;
          *(_DWORD *)(a2 + 56) = 0;
          *(_DWORD *)(a2 + 52) = 0;
        }
        if ( v32 < 0 )
        {
          v12 = 4 * v32;
          do
          {
            v34 = (btAlignedAllocator<btPersistentManifold *,16> *)(v12 + *(_DWORD *)(a2 + 56));
            if ( v34 )
              *(_DWORD *)v34 = 0;
            v12 += 4;
          }
          while ( v12 < 0 );
        }
      }
      v13 = endIslandIndex;
      *(_DWORD *)(a2 + 48) = 0;
    }
    while ( endIslandIndex < numElem );
    goto LABEL_65;
  }
LABEL_66:
  v35 = v7->RecursionCounter-- == 1;
  p_RecursionCounter = &v7->RecursionCounter;
  v37 = v7;
  if ( v35 && v7->TotalCalls )
  {
    collisionWorlda = (btCollisionWorld *)(btClock::getTimeMicroseconds((btClock *)v12) - v7->StartTime);
    v7 = CProfileManager::CurrentNode;
    v37->TotalTime = (double)(unsigned int)collisionWorlda * 0.001 + v37->TotalTime;
  }
  if ( !*p_RecursionCounter )
    CProfileManager::CurrentNode = v7->Parent;
}
