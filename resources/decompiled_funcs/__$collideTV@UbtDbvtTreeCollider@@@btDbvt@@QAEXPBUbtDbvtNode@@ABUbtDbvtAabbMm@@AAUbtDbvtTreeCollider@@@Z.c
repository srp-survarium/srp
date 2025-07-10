void __userpurge btDbvt::collideTV<btDbvtTreeCollider>(
        const btDbvtAabbMm *vol@<eax>,
        const btDbvtNode *root,
        btDbvtTreeCollider *policy)
{
  unsigned __int64 v3; // xmm0_8
  char *v4; // ebx
  int v5; // edx
  int v6; // edi
  int v7; // ecx
  _DWORD *v8; // esi
  _DWORD *v9; // eax
  int v10; // edx
  int v11; // ecx
  char *v12; // eax
  int v13; // edi
  _DWORD *v14; // esi
  _DWORD *v15; // eax
  int v16; // edx
  int v17; // ecx
  char *v18; // eax
  btDbvtNode *leaf; // eax
  int v20; // [esp+B4h] [ebp-58h]
  int v21; // [esp+B4h] [ebp-58h]
  int v22; // [esp+B8h] [ebp-54h]
  __m128 v23; // [esp+BCh] [ebp-50h]
  int v24; // [esp+E0h] [ebp-2Ch]
  char *v25; // [esp+E4h] [ebp-28h]
  btVector3 v26; // [esp+ECh] [ebp-20h]
  __m128 v27; // [esp+FCh] [ebp-10h]

  v26.mVec128 = (__m128)vol->mi;
  v27.m128_u64[0] = vol->mx.mVec128.m128_u64[0];
  v3 = vol->mx.mVec128.m128_u64[1];
  ++gNumAlignedAllocs;
  v27.m128_u64[1] = v3;
  v4 = (char *)sAlignedAllocFunc(0x100u, 16);
  v5 = 64;
  v25 = v4;
  v24 = 64;
  if ( v4 )
    *(_DWORD *)v4 = root;
  v6 = 1;
  do
  {
    v7 = *(_DWORD *)&v4[4 * v6 - 4];
    v23 = _mm_or_ps(_mm_cmplt_ps(*(__m128 *)(v7 + 16), v26.mVec128), _mm_cmplt_ps(v27, *(__m128 *)v7));
    --v6;
    v22 = v7;
    if ( !(v23.m128_i32[2] | v23.m128_i32[1] | v23.m128_i32[0]) )
    {
      if ( *(_DWORD *)(v7 + 40) )
      {
        if ( v6 == v5 )
        {
          v20 = v6 ? 2 * v6 : 1;
          if ( v5 < v20 )
          {
            if ( v20 )
            {
              ++gNumAlignedAllocs;
              v8 = sAlignedAllocFunc(4 * v20, 16);
            }
            else
            {
              v8 = 0;
            }
            if ( v6 > 0 )
            {
              v9 = v8;
              v10 = v4 - (char *)v8;
              v11 = v6;
              do
              {
                if ( v9 )
                {
                  *v9 = *(_DWORD *)((char *)v9 + v10);
                  v4 = v25;
                }
                ++v9;
                --v11;
              }
              while ( v11 );
            }
            if ( v4 )
            {
              ++gNumAlignedFree;
              sAlignedFreeFunc(v4);
            }
            v5 = v20;
            v7 = v22;
            v4 = (char *)v8;
            v25 = (char *)v8;
            v24 = v20;
          }
        }
        v12 = &v4[4 * v6];
        if ( v12 )
          *(_DWORD *)v12 = *(_DWORD *)(v7 + 36);
        v13 = v6 + 1;
        if ( v13 == v5 )
        {
          v21 = v13 ? 2 * v13 : 1;
          if ( v5 < v21 )
          {
            if ( v21 )
            {
              ++gNumAlignedAllocs;
              v14 = sAlignedAllocFunc(4 * v21, 16);
            }
            else
            {
              v14 = 0;
            }
            if ( v13 > 0 )
            {
              v15 = v14;
              v16 = v4 - (char *)v14;
              v17 = v13;
              do
              {
                if ( v15 )
                {
                  *v15 = *(_DWORD *)((char *)v15 + v16);
                  v4 = v25;
                }
                ++v15;
                --v17;
              }
              while ( v17 );
            }
            if ( v4 )
            {
              ++gNumAlignedFree;
              sAlignedFreeFunc(v4);
            }
            v5 = v21;
            v7 = v22;
            v4 = (char *)v14;
            v25 = (char *)v14;
            v24 = v21;
          }
        }
        v18 = &v4[4 * v13];
        if ( v18 )
          *(_DWORD *)v18 = *(_DWORD *)(v7 + 40);
        v6 = v13 + 1;
      }
      else
      {
        leaf = policy->proxy->leaf;
        if ( (btDbvtNode *)v7 != leaf )
        {
          policy->pbp->m_paircache->addOverlappingPair(
            policy->pbp->m_paircache,
            *(btBroadphaseProxy **)(v7 + 36),
            (btBroadphaseProxy *)leaf->dataAsInt);
          ++policy->pbp->m_newpairs;
          v5 = v24;
        }
      }
    }
  }
  while ( v6 > 0 );
  if ( v4 )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(v4);
  }
}
