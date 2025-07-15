btConvexHullShape *__userpurge btConvexHullShape::btConvexHullShape@<eax>(
        btConvexHullShape *this@<ecx>,
        int a2@<eax>,
        const float *points,
        int numPoints,
        int stride)
{
  const vostok::math::float4x4 *v5; // xmm0_4
  int v7; // ecx
  _QWORD *v8; // edi
  _QWORD *v9; // ecx
  int v10; // edx
  int v11; // edi
  int v12; // eax
  void *v13; // eax
  int v14; // ecx
  _QWORD *v15; // eax
  _QWORD *v16; // eax
  int v17; // ecx
  int v18; // ecx
  int v19; // ecx
  int v20; // ecx
  _QWORD *v21; // eax
  _QWORD *v23; // [esp+Ch] [ebp-18h]
  int v24; // [esp+10h] [ebp-14h]
  __int64 v25; // [esp+14h] [ebp-10h]
  __int64 v26; // [esp+1Ch] [ebp-8h]
  unsigned int v27; // [esp+1Ch] [ebp-8h]
  unsigned int v28; // [esp+1Ch] [ebp-8h]
  unsigned int v29; // [esp+1Ch] [ebp-8h]
  unsigned int v30; // [esp+1Ch] [ebp-8h]
  unsigned int v31; // [esp+1Ch] [ebp-8h]
  __int64 v32; // [esp+1Ch] [ebp-8h]

  v5 = clear_value;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 16) = v5;
  *(_DWORD *)(a2 + 20) = v5;
  *(_DWORD *)(a2 + 24) = v5;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 48) = 1025758986;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 80) = v5;
  *(_DWORD *)(a2 + 84) = v5;
  *(_DWORD *)(a2 + 88) = v5;
  *(_DWORD *)(a2 + 92) = 0;
  *(_DWORD *)(a2 + 96) = -1082130432;
  *(_DWORD *)(a2 + 100) = -1082130432;
  *(_DWORD *)(a2 + 104) = -1082130432;
  *(_DWORD *)(a2 + 108) = 0;
  *(_BYTE *)(a2 + 112) = 0;
  *(_DWORD *)a2 = &btConvexHullShape::`vftable';
  *(_BYTE *)(a2 + 144) = 1;
  *(_DWORD *)(a2 + 140) = 0;
  *(_DWORD *)(a2 + 132) = 0;
  *(_DWORD *)(a2 + 136) = 0;
  *(_DWORD *)(a2 + 4) = 4;
  v7 = *(_DWORD *)(a2 + 132);
  v24 = v7;
  if ( v7 <= 6 )
  {
    if ( v7 < 6 && *(int *)(a2 + 136) < 6 )
    {
      ++gNumAlignedAllocs;
      v8 = sAlignedAllocFunc(0x60u, 16);
      v23 = v8;
      if ( *(int *)(a2 + 132) > 0 )
      {
        v9 = v8;
        v10 = 0;
        v11 = *(_DWORD *)(a2 + 132);
        do
        {
          if ( v9 )
          {
            v12 = *(_DWORD *)(a2 + 140);
            *v9 = *(_QWORD *)(v12 + v10);
            v9[1] = *(_QWORD *)(v10 + v12 + 8);
          }
          v10 += 16;
          v9 += 2;
          --v11;
        }
        while ( v11 );
        v8 = v23;
      }
      v13 = *(void **)(a2 + 140);
      if ( v13 )
      {
        if ( *(_BYTE *)(a2 + 144) )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v13);
        }
        *(_DWORD *)(a2 + 140) = 0;
      }
      v7 = v24;
      *(_BYTE *)(a2 + 144) = 1;
      *(_DWORD *)(a2 + 140) = v8;
      *(_DWORD *)(a2 + 136) = 6;
    }
    if ( v7 < 6 )
    {
      v14 = 16 * v7;
      do
      {
        v15 = (_QWORD *)(v14 + *(_DWORD *)(a2 + 140));
        if ( v15 )
        {
          *v15 = v25;
          v15[1] = v26;
        }
        v14 += 16;
      }
      while ( v14 < 96 );
    }
  }
  *(_DWORD *)(a2 + 132) = 6;
  v16 = *(_QWORD **)(a2 + 140);
  v27 = *((_DWORD *)points + 2);
  *v16 = *(_QWORD *)points;
  v16[1] = v27;
  v28 = *((_DWORD *)points + 6);
  v17 = *(_DWORD *)(a2 + 140);
  *(_QWORD *)(v17 + 16) = *((_QWORD *)points + 2);
  *(_QWORD *)(v17 + 24) = v28;
  v18 = *(_DWORD *)(a2 + 140);
  v29 = *((_DWORD *)points + 10);
  *(_QWORD *)(v18 + 32) = *((_QWORD *)points + 4);
  *(_QWORD *)(v18 + 40) = v29;
  v19 = *(_DWORD *)(a2 + 140);
  v30 = *((_DWORD *)points + 14);
  *(_QWORD *)(v19 + 48) = *((_QWORD *)points + 6);
  *(_QWORD *)(v19 + 56) = v30;
  v20 = *(_DWORD *)(a2 + 140);
  v31 = *((_DWORD *)points + 18);
  *(_QWORD *)(v20 + 64) = *((_QWORD *)points + 8);
  v20 += 64;
  *(_QWORD *)(v20 + 8) = v31;
  v32 = *((unsigned int *)points + 22);
  v21 = (_QWORD *)(*(_DWORD *)(a2 + 140) + 80);
  *v21 = *((_QWORD *)points + 10);
  v21[1] = v32;
  btPolyhedralConvexAabbCachingShape::recalcLocalAabb((btPolyhedralConvexAabbCachingShape *)v20);
  return (btConvexHullShape *)a2;
}
