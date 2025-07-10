void __userpurge btDbvt::collideTV<BroadphaseAabbTester>(
        const btDbvtAabbMm *vol@<eax>,
        const btDbvtNode *root,
        BroadphaseAabbTester *policy)
{
  unsigned __int64 v3; // xmm0_8
  int v4; // edi
  char *v5; // ebx
  int v6; // esi
  int v7; // edx
  _BYTE *v8; // esi
  int v9; // edx
  _DWORD *v10; // eax
  int v11; // ecx
  char *v12; // eax
  int v13; // edi
  _DWORD *v14; // esi
  _DWORD *v15; // eax
  int v16; // edx
  int v17; // ecx
  char *v18; // eax
  int v19; // [esp+B4h] [ebp-5Ch]
  int v20; // [esp+B4h] [ebp-5Ch]
  int v21; // [esp+B8h] [ebp-58h]
  __m128 v22; // [esp+C0h] [ebp-50h]
  char *v23; // [esp+E8h] [ebp-28h]
  btVector3 v24; // [esp+F0h] [ebp-20h]
  __m128 v25; // [esp+100h] [ebp-10h]

  v24.mVec128 = (__m128)vol->mi;
  v25.m128_u64[0] = vol->mx.mVec128.m128_u64[0];
  v3 = vol->mx.mVec128.m128_u64[1];
  v4 = 1;
  ++gNumAlignedAllocs;
  v25.m128_u64[1] = v3;
  v5 = (char *)sAlignedAllocFunc(0x100u, 16);
  v23 = v5;
  v6 = 64;
  if ( v5 )
    *(_DWORD *)v5 = root;
  do
  {
    v7 = *(_DWORD *)&v5[4 * v4 - 4];
    v22 = _mm_or_ps(_mm_cmplt_ps(*(__m128 *)(v7 + 16), v24.mVec128), _mm_cmplt_ps(v25, *(__m128 *)v7));
    --v4;
    v21 = v7;
    if ( !(v22.m128_i32[2] | v22.m128_i32[1] | v22.m128_i32[0]) )
    {
      if ( *(_DWORD *)(v7 + 40) )
      {
        if ( v4 == v6 )
        {
          v19 = v4 ? 2 * v4 : 1;
          if ( v6 < v19 )
          {
            if ( v19 )
            {
              ++gNumAlignedAllocs;
              v8 = sAlignedAllocFunc(4 * v19, 16);
            }
            else
            {
              v8 = 0;
            }
            if ( v4 > 0 )
            {
              v9 = v5 - v8;
              v10 = v8;
              v11 = v4;
              do
              {
                if ( v10 )
                {
                  *v10 = *(_DWORD *)((char *)v10 + v9);
                  v9 = v5 - v8;
                }
                ++v10;
                --v11;
              }
              while ( v11 );
            }
            if ( v5 )
            {
              ++gNumAlignedFree;
              sAlignedFreeFunc(v5);
            }
            v7 = v21;
            v5 = v8;
            v6 = v19;
            v23 = v5;
          }
        }
        v12 = &v5[4 * v4];
        if ( v12 )
          *(_DWORD *)v12 = *(_DWORD *)(v7 + 36);
        v13 = v4 + 1;
        if ( v13 == v6 )
        {
          v20 = v13 ? 2 * v13 : 1;
          if ( v6 < v20 )
          {
            if ( v20 )
            {
              ++gNumAlignedAllocs;
              v14 = sAlignedAllocFunc(4 * v20, 16);
            }
            else
            {
              v14 = 0;
            }
            if ( v13 > 0 )
            {
              v15 = v14;
              v16 = v5 - (char *)v14;
              v17 = v13;
              do
              {
                if ( v15 )
                {
                  *v15 = *(_DWORD *)((char *)v15 + v16);
                  v5 = v23;
                }
                ++v15;
                --v17;
              }
              while ( v17 );
            }
            if ( v5 )
            {
              ++gNumAlignedFree;
              sAlignedFreeFunc(v5);
            }
            v7 = v21;
            v5 = (char *)v14;
            v6 = v20;
            v23 = v5;
          }
        }
        v18 = &v5[4 * v13];
        if ( v18 )
          *(_DWORD *)v18 = *(_DWORD *)(v7 + 40);
        v4 = v13 + 1;
      }
      else
      {
        policy->m_aabbCallback->process(policy->m_aabbCallback, *(const btBroadphaseProxy **)(v7 + 36));
      }
    }
  }
  while ( v4 > 0 );
  if ( v5 )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(v5);
  }
}
