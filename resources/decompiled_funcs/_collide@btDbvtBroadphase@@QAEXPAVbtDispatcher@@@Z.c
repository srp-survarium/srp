void __thiscall btDbvtBroadphase::collide(btDbvtBroadphase *this, btDbvtNode *dispatcher, btDispatcher *dispatchera)
{
  int v3; // esi
  btDispatcher_vtbl **v4; // eax
  int v5; // eax
  btDispatcher_vtbl *v6; // esi
  void (__thiscall *freeCollisionAlgorithm)(btDispatcher *, void *); // eax
  btDispatcher *v8; // edx
  void *(__thiscall *allocateCollisionAlgorithm)(btDispatcher *, int); // ecx
  void (__thiscall *v10)(btDispatcher *, void *); // eax
  btDispatcher_vtbl *v11; // eax
  btDispatcher_vtbl *v12; // eax
  btDbvt *v13; // ecx
  bool v14; // zf
  btDbvtNode *v15; // eax
  btDbvtNode *m_root; // edi
  bool v17; // cc
  int v18; // esi
  btDbvt **p_getInternalManifoldPool; // eax
  int v20; // ecx
  int v21; // esi
  int *v22; // edx
  int v23; // eax
  btDbvt *v24; // edx
  __m128 *m_lkhd; // ecx
  __m128 v26; // xmm0
  __m128 v27; // xmm2
  int v28; // edi
  btDbvtNode *parent; // eax
  double v30; // st7
  btDispatcher_vtbl *v31; // [esp+10Ch] [ebp-30h] BYREF
  btDbvt *getInternalManifoldPool; // [esp+110h] [ebp-2Ch] BYREF
  btDbvt policy; // [esp+114h] [ebp-28h] BYREF

  btDbvt::optimizeIncremental(
    (btDbvt *)(dispatcher->volume.mx.mVec128.m128_i32[0] * dispatcher[2].volume.mx.mVec128.m128_i32[0] / 100 + 1),
    (int)&dispatcher->volume.mi.mVec128.m128_i32[1]);
  if ( dispatcher[2].volume.mx.mVec128.m128_i32[3] )
  {
    v3 = dispatcher[1].volume.mi.mVec128.m128_i32[2] * dispatcher[2].volume.mi.mVec128.m128_i32[3] / 100 + 1;
    btDbvt::optimizeIncremental((btDbvt *)(&dispatcher->36 + 1), (int)(&dispatcher->36 + 1));
    getInternalManifoldPool = (btDbvt *)(dispatcher[2].volume.mx.mVec128.m128_i32[3] - v3);
    v31 = 0;
    v4 = &v31;
    if ( (int)getInternalManifoldPool >= 0 )
      v4 = (btDispatcher_vtbl **)&getInternalManifoldPool;
    dispatcher[2].volume.mx.mVec128.m128_i32[3] = (int)*v4;
  }
  v5 = (dispatcher[2].volume.mi.mVec128.m128_i32[2] + 1) % 2;
  dispatcher[2].volume.mi.mVec128.m128_i32[2] = v5;
  v6 = (btDispatcher_vtbl *)dispatcher[1].childs[v5];
  if ( v6 )
  {
    do
    {
      freeCollisionAlgorithm = v6->freeCollisionAlgorithm;
      v8 = (btDispatcher *)&dispatcher[1].childs[(int)v6[1].~btDispatcher];
      allocateCollisionAlgorithm = v6->allocateCollisionAlgorithm;
      v31 = (btDispatcher_vtbl *)freeCollisionAlgorithm;
      if ( allocateCollisionAlgorithm )
        *((_DWORD *)allocateCollisionAlgorithm + 14) = freeCollisionAlgorithm;
      else
        v8->__vftable = (btDispatcher_vtbl *)freeCollisionAlgorithm;
      v10 = v6->freeCollisionAlgorithm;
      if ( v10 )
        *((_DWORD *)v10 + 13) = v6->allocateCollisionAlgorithm;
      v6->allocateCollisionAlgorithm = 0;
      v6->freeCollisionAlgorithm = (void (__thiscall *)(btDispatcher *, void *))*((_DWORD *)&dispatcher[1].36 + 2);
      v11 = (btDispatcher_vtbl *)*((_DWORD *)&dispatcher[1].36 + 2);
      if ( v11 )
        v11->allocateCollisionAlgorithm = (void *(__thiscall *)(btDispatcher *, int))v6;
      *((_DWORD *)&dispatcher[1].36 + 2) = v6;
      getInternalManifoldPool = (btDbvt *)v6->getInternalManifoldPool;
      removeleaf((btDbvt *)&dispatcher->volume.mi.m_floats[1], (btDbvtNode *)getInternalManifoldPool);
      v12 = (btDispatcher_vtbl *)dispatcher->volume.mi.mVec128.m128_i32[2];
      if ( v12 )
      {
        ++gNumAlignedFree;
        sAlignedFreeFunc(v12);
      }
      --dispatcher->volume.mx.mVec128.m128_i32[0];
      v13 = getInternalManifoldPool;
      dispatcher->volume.mi.mVec128.m128_i32[2] = (int)getInternalManifoldPool;
      *(_QWORD *)&policy.m_lkhd = *(_QWORD *)&v6->clearManifold;
      *(_QWORD *)&policy.m_opath = *(_QWORD *)&v6->needsResponse;
      *(_QWORD *)&policy.m_stkStack.m_size = *(_QWORD *)&v6->getNumManifolds;
      *(_QWORD *)&policy.m_stkStack.m_data = *(_QWORD *)&v6->getInternalManifoldPointer;
      v6->getInternalManifoldPool = (btPoolAllocator *(__thiscall *)(btDispatcher *))btDbvt::insert(
                                                                                       v13,
                                                                                       (const btDbvtAabbMm *)&policy.m_lkhd,
                                                                                       v6);
      v6[1].~btDispatcher = (void (__thiscall *)(btDispatcher *))2;
      v6 = v31;
    }
    while ( v31 );
    dispatcher[2].volume.mx.mVec128.m128_i32[3] = dispatcher[1].volume.mi.mVec128.m128_i32[2];
    dispatcher[3].volume.mi.mVec128.m128_i8[10] = 1;
  }
  v14 = dispatcher[3].volume.mi.mVec128.m128_i8[9] == 0;
  policy.m_root = dispatcher;
  if ( !v14 )
  {
    btDbvt::collideTTpersistentStack<btDbvtTreeCollider>(
      &policy,
      (int)&dispatcher->volume.mi.mVec128.m128_i32[1],
      (const btDbvtNode *)dispatcher->volume.mi.mVec128.m128_i32[1],
      *((const btDbvtNode **)&dispatcher->36 + 2),
      (btDbvtTreeCollider *)&policy);
    if ( dispatcher[3].volume.mi.mVec128.m128_i8[9] )
      btDbvt::collideTTpersistentStack<btDbvtTreeCollider>(
        &policy,
        (int)&dispatcher->volume.mi.mVec128.m128_i32[1],
        (const btDbvtNode *)dispatcher->volume.mi.mVec128.m128_i32[1],
        (const btDbvtNode *)dispatcher->volume.mi.mVec128.m128_i32[1],
        (btDbvtTreeCollider *)&policy);
  }
  if ( dispatcher[3].volume.mi.mVec128.m128_i8[10] )
  {
    v15 = (btDbvtNode *)(*(int (__thiscall **)(int))(*(_DWORD *)dispatcher[2].volume.mi.mVec128.m128_i32[0] + 24))(dispatcher[2].volume.mi.mVec128.m128_i32[0]);
    m_root = v15;
    v17 = v15->volume.mi.mVec128.m128_i32[1] <= 0;
    policy.m_root = v15;
    if ( !v17 )
    {
      v18 = v15->volume.mi.mVec128.m128_i32[1];
      v17 = dispatcher[2].volume.mx.mVec128.m128_i32[2] <= v18 * dispatcher[2].volume.mx.mVec128.m128_i32[1] / 100;
      getInternalManifoldPool = (btDbvt *)(v18 * dispatcher[2].volume.mx.mVec128.m128_i32[1] / 100);
      v31 = (btDispatcher_vtbl *)v18;
      p_getInternalManifoldPool = (btDbvt **)&dispatcher[2].volume.mx.mVec128.m128_i32[2];
      if ( v17 )
        p_getInternalManifoldPool = &getInternalManifoldPool;
      if ( v18 < (int)*p_getInternalManifoldPool )
        p_getInternalManifoldPool = (btDbvt **)&v31;
      v20 = (int)*p_getInternalManifoldPool;
      v21 = 0;
      v31 = (btDispatcher_vtbl *)v20;
      if ( v20 > 0 )
      {
        do
        {
          v22 = (int *)(m_root->volume.mi.mVec128.m128_i32[3]
                      + 16
                      * ((v21 + dispatcher[3].volume.mi.mVec128.m128_i32[0]) % m_root->volume.mi.mVec128.m128_i32[1]));
          v23 = *v22;
          v24 = (btDbvt *)v22[1];
          m_lkhd = (__m128 *)v24[1].m_lkhd;
          v26 = m_lkhd[1];
          v27 = *m_lkhd;
          getInternalManifoldPool = v24;
          *(__m128 *)&policy.m_lkhd = _mm_or_ps(
                                        _mm_cmplt_ps(v26, *(__m128 *)*(_DWORD *)(v23 + 48)),
                                        _mm_cmplt_ps(*(__m128 *)(*(_DWORD *)(v23 + 48) + 16), v27));
          if ( policy.m_opath | policy.m_leaves | policy.m_lkhd )
          {
            (*(void (__thiscall **)(int, int, btDbvt *, btDispatcher *))(*(_DWORD *)dispatcher[2].volume.mi.mVec128.m128_i32[0]
                                                                       + 8))(
              dispatcher[2].volume.mi.mVec128.m128_i32[0],
              v23,
              getInternalManifoldPool,
              dispatchera);
            v31 = (btDispatcher_vtbl *)((char *)v31 - 1);
            m_root = policy.m_root;
            --v21;
          }
          ++v21;
        }
        while ( v21 < (int)v31 );
        v20 = (int)v31;
      }
      v28 = m_root->volume.mi.mVec128.m128_i32[1];
      if ( v28 <= 0 )
        dispatcher[3].volume.mi.mVec128.m128_i32[0] = 0;
      else
        dispatcher[3].volume.mi.mVec128.m128_i32[0] = (v20 + dispatcher[3].volume.mi.mVec128.m128_i32[0]) % v28;
    }
  }
  ++*((_DWORD *)&dispatcher[2].36 + 2);
  dispatcher[2].volume.mx.mVec128.m128_i32[2] = 1;
  parent = dispatcher[2].parent;
  dispatcher[3].volume.mi.mVec128.m128_i8[10] = 0;
  if ( parent )
  {
    v30 = (double)(unsigned int)dispatcher[2].childs[0];
    policy.m_root = parent;
    *(float *)&dispatcher[2].childs[1] = v30 / (double)(unsigned int)parent;
  }
  else
  {
    dispatcher[2].childs[1] = 0;
  }
  dispatcher[2].dataAsInt = (unsigned int)dispatcher[2].dataAsInt >> 1;
  dispatcher[2].parent = (btDbvtNode *)((unsigned int)parent >> 1);
}
