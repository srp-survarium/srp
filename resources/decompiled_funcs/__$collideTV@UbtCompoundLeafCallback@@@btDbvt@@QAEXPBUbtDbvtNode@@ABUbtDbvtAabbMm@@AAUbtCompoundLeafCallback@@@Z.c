void __userpurge btDbvt::collideTV<btCompoundLeafCallback>(
        const btDbvtAabbMm *vol@<eax>,
        const btDbvtNode *root,
        btCompoundLeafCallback *policy)
{
  unsigned __int64 v3; // xmm0_8
  int v4; // edi
  char *v5; // ebx
  int v6; // esi
  btDbvtNode *v7; // ecx
  _BYTE *v8; // esi
  int v9; // edx
  _DWORD *v10; // eax
  int v11; // ecx
  char *v12; // eax
  int v13; // edi
  _BYTE *v14; // esi
  int v15; // edx
  _DWORD *v16; // eax
  int v17; // ecx
  char *v18; // eax
  int v19; // [esp+60h] [ebp-3Ch]
  int v20; // [esp+60h] [ebp-3Ch]
  btDbvtNode *v21; // [esp+64h] [ebp-38h]
  __m128 v22; // [esp+6Ch] [ebp-30h]
  btVector3 v23; // [esp+7Ch] [ebp-20h]
  __m128 v24; // [esp+8Ch] [ebp-10h]

  v23.mVec128 = (__m128)vol->mi;
  v24.m128_u64[0] = vol->mx.mVec128.m128_u64[0];
  v3 = vol->mx.mVec128.m128_u64[1];
  v4 = 1;
  ++gNumAlignedAllocs;
  v24.m128_u64[1] = v3;
  v5 = (char *)sAlignedAllocFunc(0x100u, 16);
  v6 = 64;
  if ( v5 )
    *(_DWORD *)v5 = root;
  do
  {
    v7 = *(btDbvtNode **)&v5[4 * v4 - 4];
    v22 = _mm_or_ps(_mm_cmplt_ps(v7->volume.mx.mVec128, v23.mVec128), _mm_cmplt_ps(v24, v7->volume.mi.mVec128));
    --v4;
    v21 = v7;
    if ( !(v22.m128_i32[2] | v22.m128_i32[1] | v22.m128_i32[0]) )
    {
      if ( v7->childs[1] )
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
          }
        }
        v12 = &v5[4 * v4];
        if ( v12 )
          *(_DWORD *)v12 = v7->childs[0];
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
              v15 = v5 - v14;
              v16 = v14;
              v17 = v13;
              do
              {
                if ( v16 )
                {
                  *v16 = *(_DWORD *)((char *)v16 + v15);
                  v15 = v5 - v14;
                }
                ++v16;
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
            v5 = v14;
            v6 = v20;
          }
        }
        v18 = &v5[4 * v13];
        if ( v18 )
          *(_DWORD *)v18 = v7->childs[1];
        v4 = v13 + 1;
      }
      else
      {
        btCompoundLeafCallback::Process((btCompoundLeafCallback *)v7, policy, v7);
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
