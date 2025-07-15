void __userpurge btAxisSweep3Internal<unsigned short>::sortMaxDown(
        unsigned __int16 edge@<ax>,
        btAxisSweep3Internal<unsigned short>::Handle *this,
        int axis,
        btDispatcher *dispatcher,
        bool updateOverlaps)
{
  btAxisSweep3Internal<unsigned short>::Edge *v6; // edi
  btAxisSweep3Internal<unsigned short>::Edge *v7; // edx
  unsigned __int16 *v8; // eax
  int v9; // ecx
  btAxisSweep3Internal<unsigned short>::Handle *v10; // eax
  btAxisSweep3Internal<unsigned short>::Handle *v11; // esi
  int v12; // eax
  btAxisSweep3Internal<unsigned short>::Edge v14; // ecx
  unsigned __int16 *v15; // [esp+Ch] [ebp-Ch]
  char *v16; // [esp+10h] [ebp-8h]
  btAxisSweep3Internal<unsigned short>::Edge *v17; // [esp+14h] [ebp-4h]
  btAxisSweep3Internal<unsigned short>::Handle *pHandleB; // [esp+20h] [ebp+8h]

  v6 = (btAxisSweep3Internal<unsigned short>::Edge *)(*(&this[1].m_uniqueId + axis) + 4 * edge);
  v7 = v6 - 1;
  v17 = v6 - 1;
  if ( v6->m_pos < v6[-1].m_pos )
  {
    v8 = (unsigned __int16 *)(*(_DWORD *)&this[1].m_collisionFilterGroup + (v6->m_handle << 6) + 2 * axis + 54);
    v15 = v8;
    do
    {
      v9 = v7->m_handle << 6;
      v16 = (char *)(v9 + *(_DWORD *)&this[1].m_collisionFilterGroup);
      if ( (v7->m_pos & 1) != 0 )
      {
        ++*(_WORD *)(v9 + *(_DWORD *)&this[1].m_collisionFilterGroup + 2 * axis + 54);
      }
      else
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
          v7 = v17;
        }
        ++*(_WORD *)&v16[2 * axis + 48];
        v8 = v15;
      }
      --*v8;
      v14 = *v6;
      *v6 = *v7;
      *v7 = v14;
      --v6;
      v17 = --v7;
    }
    while ( v6->m_pos < v7->m_pos );
  }
}
