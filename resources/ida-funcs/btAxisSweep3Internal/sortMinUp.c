void __userpurge btAxisSweep3Internal<unsigned short>::sortMinUp(
        unsigned __int16 edge@<ax>,
        btAxisSweep3Internal<unsigned short>::Handle *this,
        int axis,
        btDispatcher *dispatcher,
        bool updateOverlaps)
{
  btAxisSweep3Internal<unsigned short>::Edge *v6; // edi
  btAxisSweep3Internal<unsigned short>::Handle *v7; // esi
  btAxisSweep3Internal<unsigned short>::Edge *v8; // edx
  int v9; // ecx
  btAxisSweep3Internal<unsigned short>::Handle *v10; // eax
  btAxisSweep3Internal<unsigned short>::Handle *v11; // esi
  int v12; // eax
  char *v14; // eax
  btAxisSweep3Internal<unsigned short>::Edge v15; // eax
  btAxisSweep3Internal<unsigned short>::Handle *v16; // [esp+Ch] [ebp-Ch]
  char *v17; // [esp+10h] [ebp-8h]
  btAxisSweep3Internal<unsigned short>::Edge *v18; // [esp+14h] [ebp-4h]
  btAxisSweep3Internal<unsigned short>::Handle *pHandleB; // [esp+20h] [ebp+8h]

  v6 = (btAxisSweep3Internal<unsigned short>::Edge *)(*(&this[1].m_uniqueId + axis) + 4 * edge);
  v7 = (btAxisSweep3Internal<unsigned short>::Handle *)(*(_DWORD *)&this[1].m_collisionFilterGroup + (v6->m_handle << 6));
  v8 = v6 + 1;
  v16 = v7;
  while ( 1 )
  {
    v18 = v8;
    if ( !v8->m_handle || v6->m_pos < v8->m_pos )
      break;
    v9 = v8->m_handle << 6;
    v17 = (char *)(v9 + *(_DWORD *)&this[1].m_collisionFilterGroup);
    if ( (v8->m_pos & 1) != 0 )
    {
      v10 = *(btAxisSweep3Internal<unsigned short>::Handle **)&this[1].m_collisionFilterGroup;
      v11 = &v10[v6->m_handle];
      pHandleB = (btAxisSweep3Internal<unsigned short>::Handle *)((char *)v10 + v9);
      v12 = (1 << axis) & 3;
      if ( updateOverlaps )
      {
        if ( v11->m_maxEdges[v12] >= pHandleB->m_minEdges[v12]
          && btAxisSweep3Internal<unsigned short>::testOverlap2D(v11, v12, (1 << v12) & 3, pHandleB) )
        {
          (*(void (__thiscall **)(int, btAxisSweep3Internal<unsigned short>::Handle *, btAxisSweep3Internal<unsigned short>::Handle *, btDispatcher *))(*(_DWORD *)this[1].m_aabbMax.mVec128.m128_i32[1] + 8))(
            this[1].m_aabbMax.mVec128.m128_i32[1],
            v11,
            pHandleB,
            dispatcher);
          if ( this[1].m_aabbMax.mVec128.m128_i32[2] )
            (*(void (__thiscall **)(int, btAxisSweep3Internal<unsigned short>::Handle *, btAxisSweep3Internal<unsigned short>::Handle *, btDispatcher *))(*(_DWORD *)this[1].m_aabbMax.mVec128.m128_i32[2] + 8))(
              this[1].m_aabbMax.mVec128.m128_i32[2],
              v11,
              pHandleB,
              dispatcher);
        }
        v8 = v18;
      }
      v7 = v16;
      v14 = &v17[2 * axis + 54];
    }
    else
    {
      v14 = &v17[2 * axis + 48];
    }
    --*(_WORD *)v14;
    ++v7->m_minEdges[axis];
    v15 = *v6;
    *v6 = *v8;
    *v8 = v15;
    ++v6;
    ++v8;
  }
}
