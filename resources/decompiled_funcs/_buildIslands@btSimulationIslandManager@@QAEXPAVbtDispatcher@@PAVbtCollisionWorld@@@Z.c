void __thiscall btSimulationIslandManager::buildIslands(
        btSimulationIslandManager *this,
        btPersistentManifold *dispatcher,
        btDispatcher *collisionWorld,
        int i)
{
  CProfileNode *v4; // eax
  int RecursionCounter; // ecx
  int v6; // esi
  btDispatcher_vtbl *v7; // eax
  int v8; // ecx
  _DWORD *v9; // eax
  int v10; // edx
  btDispatcher_vtbl *v11; // esi
  int v12; // ecx
  void (__thiscall **v13)(btDispatcher *); // eax
  _DWORD *v14; // edi
  int v15; // esi
  int v16; // eax
  int v17; // ebp
  int v18; // eax
  int v19; // esi
  _DWORD *v20; // eax
  btCollisionWorld *v21; // ebx
  int v22; // eax
  btClock *v23; // ecx
  int v25; // ebp
  _DWORD *v26; // eax
  int v27; // ecx
  int v28; // edx
  int v29; // edx
  btDispatcher_vtbl *v30; // ecx
  btDispatcher_vtbl *v31; // eax
  int v32; // edi
  btDispatcher_vtbl *v33; // ebx
  btDispatcher_vtbl *v34; // edx
  int v35; // eax
  btDispatcher_vtbl *v36; // ecx
  btDispatcher_vtbl *v37; // eax
  int *v38; // eax
  CProfileNode *v39; // esi
  bool v40; // zf
  int *p_RecursionCounter; // edi
  bool allSleeping; // [esp+13h] [ebp-9h]
  int islandId; // [esp+14h] [ebp-8h]
  btDispatcher_vtbl *numElem; // [esp+18h] [ebp-4h]
  int numElema; // [esp+18h] [ebp-4h]
  btPersistentManifold *manifold; // [esp+20h] [ebp+4h]
  int ia; // [esp+28h] [ebp+Ch]

  v4 = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "islandUnionFindAndQuickSort" )
  {
    CProfileNode::Get_Sub_Node((const char *)this, "islandUnionFindAndQuickSort");
    CProfileManager::CurrentNode = v4;
  }
  RecursionCounter = v4->RecursionCounter;
  ++v4->TotalCalls;
  v4->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
    v4->StartTime = btClock::getTimeMicroseconds(0);
  v6 = dispatcher->m_pointCache[0].m_localPointA.mVec128.m128_i32[3];
  if ( v6 <= 0 )
  {
    if ( v6 < 0 && dispatcher->m_pointCache[0].m_localPointB.mVec128.m128_i32[0] < 0 )
    {
      v7 = (btDispatcher_vtbl *)dispatcher->m_pointCache[0].m_localPointB.mVec128.m128_i32[1];
      if ( v7 )
      {
        if ( dispatcher->m_pointCache[0].m_localPointB.mVec128.m128_i8[8] )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v7);
        }
        dispatcher->m_pointCache[0].m_localPointB.mVec128.m128_i32[1] = 0;
      }
      dispatcher->m_pointCache[0].m_localPointB.mVec128.m128_i8[8] = 1;
      dispatcher->m_pointCache[0].m_localPointB.mVec128.m128_i32[1] = 0;
      dispatcher->m_pointCache[0].m_localPointB.mVec128.m128_i32[0] = 0;
    }
    if ( v6 < 0 )
    {
      v8 = 4 * v6;
      do
      {
        v9 = (_DWORD *)(v8 + dispatcher->m_pointCache[0].m_localPointB.mVec128.m128_i32[1]);
        if ( v9 )
          *v9 = 0;
        v8 += 4;
      }
      while ( v8 < 0 );
    }
  }
  dispatcher->m_pointCache[0].m_localPointA.mVec128.m128_i32[3] = 0;
  btUnionFind::sortIslands((btUnionFind *)(&dispatcher->btTypedObject + 1));
  v10 = 0;
  numElem = (btDispatcher_vtbl *)*((_DWORD *)&dispatcher->btTypedObject + 2);
  if ( (int)numElem > 0 )
  {
    do
    {
      v11 = (btDispatcher_vtbl *)dispatcher->m_pointCache[0].m_localPointA.mVec128.m128_i32[0];
      v12 = v10 + 1;
      islandId = *((_DWORD *)&v11->~btDispatcher + 2 * v10);
      if ( v10 + 1 < (int)numElem )
      {
        v13 = &v11->~btDispatcher + 2 * v12;
        do
        {
          if ( *v13 != *(&v11->~btDispatcher + 2 * v10) )
            break;
          ++v12;
          v13 += 2;
        }
        while ( v12 < (int)numElem );
      }
      allSleeping = 1;
      if ( v10 < v12 )
      {
        v14 = &v11->findAlgorithm + 2 * v10;
        v15 = v12 - v10;
        do
        {
          v16 = *(_DWORD *)(*(_DWORD *)(i + 16) + 4 * *v14);
          if ( *(_DWORD *)(v16 + 220) == islandId )
          {
            v17 = *(_DWORD *)(v16 + 228);
            if ( v17 == 1 )
              allSleeping = 0;
            if ( v17 == 4 )
              allSleeping = 0;
          }
          v14 += 2;
          --v15;
        }
        while ( v15 );
        if ( allSleeping )
        {
          for ( ; v10 < v12; ++v10 )
          {
            v18 = *(_DWORD *)(*(_DWORD *)(i + 16)
                            + 4
                            * *(_DWORD *)(dispatcher->m_pointCache[0].m_localPointA.mVec128.m128_i32[0] + 8 * v10 + 4));
            if ( *(_DWORD *)(v18 + 220) == islandId )
            {
              v19 = *(_DWORD *)(v18 + 228);
              if ( v19 != 4 && v19 != 5 )
                *(_DWORD *)(v18 + 228) = 2;
            }
          }
        }
        else
        {
          do
          {
            v20 = *(_DWORD **)(*(_DWORD *)(i + 16)
                             + 4
                             * *(_DWORD *)(dispatcher->m_pointCache[0].m_localPointA.mVec128.m128_i32[0] + 8 * v10 + 4));
            if ( v20[55] == islandId && v20[57] == 2 )
            {
              v20[57] = 3;
              v20[58] = 0;
            }
            ++v10;
          }
          while ( v10 < v12 );
        }
      }
      v10 = v12;
    }
    while ( v12 < (int)numElem );
  }
  v21 = (btCollisionWorld *)collisionWorld;
  v22 = collisionWorld->getNumManifolds(collisionWorld);
  v23 = 0;
  numElema = v22;
  for ( ia = 0; ia < numElema; ++ia )
  {
    v25 = ((int (__thiscall *)(btCollisionWorld *, btClock *))v21->performDiscreteCollisionDetection)(v21, v23);
    v26 = *(_DWORD **)(v25 + 1168);
    v27 = *(_DWORD *)(v25 + 1172);
    manifold = (btPersistentManifold *)v25;
    if ( v26 && v26[57] != 2 || v27 && *(_DWORD *)(v27 + 228) != 2 )
    {
      if ( (v26[54] & 2) != 0 && v26[57] != 2 && (*(_BYTE *)(v27 + 216) & 3) == 0 )
      {
        v28 = *(_DWORD *)(v27 + 228);
        if ( v28 != 4 && v28 != 5 )
          *(_DWORD *)(v27 + 228) = 1;
        *(_DWORD *)(v27 + 232) = 0;
      }
      if ( (*(_DWORD *)(v27 + 216) & 2) != 0 && *(_DWORD *)(v27 + 228) != 2 && (v26[54] & 3) == 0 )
      {
        v29 = v26[57];
        if ( v29 != 4 && v29 != 5 )
          v26[57] = 1;
        v26[58] = 0;
      }
      if ( dispatcher->m_pointCache[0].m_positionWorldOnA.mVec128.m128_i8[0]
        && ((unsigned __int8 (__thiscall *)(btCollisionWorld *, _DWORD *, int))v21->rayTest)(v21, v26, v27) )
      {
        v30 = (btDispatcher_vtbl *)dispatcher->m_pointCache[0].m_localPointB.mVec128.m128_i32[0];
        v31 = (btDispatcher_vtbl *)dispatcher->m_pointCache[0].m_localPointA.mVec128.m128_i32[3];
        if ( v31 == v30 )
        {
          v32 = 2 * (_DWORD)v31;
          if ( !v31 )
            v32 = 1;
          if ( (int)v30 < v32 )
          {
            if ( v32 )
            {
              ++gNumAlignedAllocs;
              v33 = (btDispatcher_vtbl *)sAlignedAllocFunc(4 * v32, 16);
            }
            else
            {
              v33 = 0;
            }
            v34 = (btDispatcher_vtbl *)dispatcher->m_pointCache[0].m_localPointA.mVec128.m128_i32[3];
            v35 = 0;
            if ( (int)v34 > 0 )
            {
              v36 = v33;
              do
              {
                if ( v36 )
                {
                  v36->~btDispatcher = *(void (__thiscall **)(btDispatcher *))(dispatcher->m_pointCache[0].m_localPointB.mVec128.m128_i32[1]
                                                                             + 4 * v35);
                  v25 = (int)manifold;
                }
                ++v35;
                v36 = (btDispatcher_vtbl *)((char *)v36 + 4);
              }
              while ( v35 < (int)v34 );
            }
            v37 = (btDispatcher_vtbl *)dispatcher->m_pointCache[0].m_localPointB.mVec128.m128_i32[1];
            if ( v37 )
            {
              if ( dispatcher->m_pointCache[0].m_localPointB.mVec128.m128_i8[8] )
              {
                ++gNumAlignedFree;
                sAlignedFreeFunc(v37);
              }
              dispatcher->m_pointCache[0].m_localPointB.mVec128.m128_i32[1] = 0;
            }
            dispatcher->m_pointCache[0].m_localPointB.mVec128.m128_i32[1] = (int)v33;
            v21 = (btCollisionWorld *)collisionWorld;
            dispatcher->m_pointCache[0].m_localPointB.mVec128.m128_i8[8] = 1;
            dispatcher->m_pointCache[0].m_localPointB.mVec128.m128_i32[0] = v32;
          }
        }
        v38 = (int *)(dispatcher->m_pointCache[0].m_localPointB.mVec128.m128_i32[1]
                    + 4 * dispatcher->m_pointCache[0].m_localPointA.mVec128.m128_i32[3]);
        if ( v38 )
          *v38 = v25;
        ++dispatcher->m_pointCache[0].m_localPointA.mVec128.m128_i32[3];
      }
    }
    v23 = (btClock *)(ia + 1);
  }
  v39 = CProfileManager::CurrentNode;
  v40 = CProfileManager::CurrentNode->RecursionCounter-- == 1;
  p_RecursionCounter = &v39->RecursionCounter;
  if ( v40 && v39->TotalCalls )
  {
    v39->TotalTime = (double)((unsigned int)btClock::getTimeMicroseconds(v23) - v39->StartTime) * 0.001 + v39->TotalTime;
    v39 = CProfileManager::CurrentNode;
  }
  if ( !*p_RecursionCounter )
    CProfileManager::CurrentNode = v39->Parent;
}
