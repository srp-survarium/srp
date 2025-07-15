void __thiscall btDbvtBroadphase::collide(btDbvtBroadphase *this, btDbvtNode *dispatcher, int a3)
{
  btDbvt *v3; // ecx
  int v4; // esi
  bool v5; // sf
  int *p_policy; // eax
  int v7; // eax
  btDbvt *v8; // esi
  int v9; // eax
  btDbvt *v10; // ecx
  btDbvtNode *v11; // eax
  btDbvtNode *m_root; // eax
  bool v13; // zf
  int v14; // eax
  int v15; // esi
  int v16; // eax
  btDbvt *v17; // edx
  bool v18; // cc
  btDbvtNode **v19; // eax
  btDbvtNode *v20; // eax
  int *v21; // edx
  int v22; // edi
  int v23; // edx
  int v24; // esi
  btDbvtNode *parent; // eax
  double v26; // st7
  btDbvt *v27; // [esp+14h] [ebp-2Ch] BYREF
  btDbvt policy; // [esp+18h] [ebp-28h] BYREF

  btDbvt::optimizeIncremental(
    (btDbvt *)&dispatcher->volume.mi.m_floats[1],
    (btDbvt *)&dispatcher->volume.mi.m_floats[1],
    dispatcher->volume.mx.mVec128.m128_i32[0] * dispatcher[2].volume.mx.mVec128.m128_i32[0] / 100 + 1);
  if ( dispatcher[2].volume.mx.mVec128.m128_i32[3] )
  {
    v4 = dispatcher[1].volume.mi.mVec128.m128_i32[2] * dispatcher[2].volume.mi.mVec128.m128_i32[3] / 100 + 1;
    btDbvt::optimizeIncremental((btDbvt *)0x64, (btDbvt *)(&dispatcher->36 + 1), v4);
    v5 = dispatcher[2].volume.mx.mVec128.m128_i32[3] - v4 < 0;
    v27 = (btDbvt *)(dispatcher[2].volume.mx.mVec128.m128_i32[3] - v4);
    policy.m_root = 0;
    p_policy = (int *)&policy;
    if ( !v5 )
      p_policy = (int *)&v27;
    dispatcher[2].volume.mx.mVec128.m128_i32[3] = *p_policy;
  }
  v7 = (dispatcher[2].volume.mi.mVec128.m128_i32[2] + 1) % 2;
  dispatcher[2].volume.mi.mVec128.m128_i32[2] = v7;
  v8 = (btDbvt *)dispatcher[1].childs[v7];
  v27 = v8;
  if ( v8 )
  {
    while ( 1 )
    {
      policy.m_root = (btDbvtNode *)v8[1].m_opath;
      listremove_btDbvtProxy_(
        (btDbvtProxy *)v8,
        (btDbvtProxy **)&dispatcher[1].childs[*(_DWORD *)&v8[1].m_stkStack.m_allocator]);
      v8[1].m_leaves = 0;
      v8[1].m_opath = *((_DWORD *)&dispatcher[1].36 + 2);
      v9 = *((_DWORD *)&dispatcher[1].36 + 2);
      if ( v9 )
        *(_DWORD *)(v9 + 52) = v8;
      *((_DWORD *)&dispatcher[1].36 + 2) = v8;
      btDbvt::remove((btDbvt *)&dispatcher->volume.mi.m_floats[1], (btDbvtNode *)v8[1].m_lkhd);
      *(_QWORD *)&policy.m_lkhd = *(_QWORD *)&v27->m_opath;
      *(_QWORD *)&policy.m_opath = *(_QWORD *)&v27->m_stkStack.m_size;
      policy.m_stkStack.m_size = (int)v27->m_stkStack.m_data;
      policy.m_stkStack.m_capacity = *(_DWORD *)&v27->m_stkStack.m_ownsMemory;
      policy.m_stkStack.m_data = (btDbvt::sStkNN *)v27[1].m_root;
      *(_DWORD *)&policy.m_stkStack.m_ownsMemory = v27[1].m_free;
      v11 = btDbvt::insert(v10, (btDbvt *)(&dispatcher->36 + 1), &policy.m_lkhd, (int)v27);
      v3 = v27;
      v27[1].m_lkhd = (int)v11;
      m_root = policy.m_root;
      *(_DWORD *)&v3[1].m_stkStack.m_allocator = 2;
      v27 = (btDbvt *)m_root;
      if ( !m_root )
        break;
      v8 = v27;
    }
    dispatcher[2].volume.mx.mVec128.m128_i32[3] = dispatcher[1].volume.mi.mVec128.m128_i32[2];
    dispatcher[3].volume.mi.mVec128.m128_i8[10] = 1;
  }
  v13 = dispatcher[3].volume.mi.mVec128.m128_i8[9] == 0;
  policy.m_root = dispatcher;
  if ( !v13 )
  {
    btDbvt::collideTTpersistentStack<btDbvtTreeCollider>(
      v3,
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
    v14 = (*(int (__thiscall **)(int))(*(_DWORD *)dispatcher[2].volume.mi.mVec128.m128_i32[0] + 24))(dispatcher[2].volume.mi.mVec128.m128_i32[0]);
    v15 = v14;
    if ( *(int *)(v14 + 4) > 0 )
    {
      v16 = *(_DWORD *)(v14 + 4) * dispatcher[2].volume.mx.mVec128.m128_i32[1] / 100;
      v17 = *(btDbvt **)(v15 + 4);
      v27 = v17;
      v18 = dispatcher[2].volume.mx.mVec128.m128_i32[2] <= v16;
      policy.m_root = (btDbvtNode *)v16;
      v19 = (btDbvtNode **)&dispatcher[2].volume.mx.mVec128.m128_i32[2];
      if ( v18 )
        v19 = (btDbvtNode **)&policy;
      if ( (int)v17 < (int)*v19 )
        v19 = (btDbvtNode **)&v27;
      v20 = *v19;
      v27 = 0;
      for ( policy.m_root = v20; (int)v27 < (int)policy.m_root; v27 = (btDbvt *)((char *)v27 + 1) )
      {
        v21 = (int *)(*(_DWORD *)(v15 + 12)
                    + 16 * (((int)v27 + dispatcher[3].volume.mi.mVec128.m128_i32[0]) % *(_DWORD *)(v15 + 4)));
        v22 = *v21;
        v23 = v21[1];
        *(__m128 *)&policy.m_lkhd = _mm_or_ps(
                                      _mm_cmplt_ps(
                                        *(__m128 *)(*(_DWORD *)(v23 + 48) + 16),
                                        *(__m128 *)*(_DWORD *)(v22 + 48)),
                                      _mm_cmplt_ps(
                                        *(__m128 *)(*(_DWORD *)(v22 + 48) + 16),
                                        *(__m128 *)*(_DWORD *)(v23 + 48)));
        if ( policy.m_opath | policy.m_leaves | policy.m_lkhd )
        {
          (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)dispatcher[2].volume.mi.mVec128.m128_i32[0] + 8))(
            dispatcher[2].volume.mi.mVec128.m128_i32[0],
            v22,
            v23,
            a3);
          --policy.m_root;
          v27 = (btDbvt *)((char *)v27 - 1);
        }
      }
      v24 = *(_DWORD *)(v15 + 4);
      if ( v24 <= 0 )
        dispatcher[3].volume.mi.mVec128.m128_i32[0] = 0;
      else
        dispatcher[3].volume.mi.mVec128.m128_i32[0] = ((int)policy.m_root + dispatcher[3].volume.mi.mVec128.m128_i32[0])
                                                    % v24;
    }
  }
  parent = dispatcher[2].parent;
  ++*((_DWORD *)&dispatcher[2].36 + 2);
  dispatcher[2].volume.mx.mVec128.m128_i32[2] = 1;
  dispatcher[3].volume.mi.mVec128.m128_i8[10] = 0;
  if ( parent )
  {
    v26 = (double)(unsigned int)dispatcher[2].childs[0];
    policy.m_root = parent;
    *(float *)&dispatcher[2].childs[1] = v26 / (double)(unsigned int)parent;
  }
  else
  {
    dispatcher[2].childs[1] = 0;
  }
  dispatcher[2].dataAsInt = (unsigned int)dispatcher[2].dataAsInt >> 1;
  dispatcher[2].parent = (btDbvtNode *)((unsigned int)parent >> 1);
}
