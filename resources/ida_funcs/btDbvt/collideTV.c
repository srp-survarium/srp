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


void __userpurge btDbvt::collideTV<btSoftColliders::CollideCL_RS>(
        const btDbvtAabbMm *vol@<eax>,
        const btDbvtNode *root,
        btSoftColliders::CollideCL_RS *policy)
{
  unsigned __int64 v3; // xmm0_8
  int v4; // edi
  char *v5; // ebx
  int v6; // esi
  const btDbvtNode *v7; // eax
  _BYTE *v8; // esi
  int v9; // edx
  _DWORD *v10; // eax
  int v11; // ecx
  char *v12; // ecx
  int v13; // edi
  _BYTE *v14; // esi
  int v15; // edx
  _DWORD *v16; // eax
  int v17; // ecx
  char *v18; // ecx
  int v19; // [esp+60h] [ebp-3Ch]
  int v20; // [esp+60h] [ebp-3Ch]
  const btDbvtNode *v21; // [esp+64h] [ebp-38h]
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
    v7 = *(const btDbvtNode **)&v5[4 * v4 - 4];
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
        btSoftColliders::CollideCL_RS::Process(v7, policy);
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


void __userpurge btDbvt::collideTV<btSoftColliders::CollideSDF_RS>(
        const btDbvtAabbMm *vol@<eax>,
        const btDbvtNode *root,
        btSoftColliders::CollideSDF_RS *policy)
{
  unsigned __int64 v3; // xmm0_8
  int v4; // edi
  char *v5; // ebx
  int v6; // esi
  int v7; // ecx
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
  int v21; // [esp+64h] [ebp-38h]
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
    v7 = *(_DWORD *)&v5[4 * v4 - 4];
    v22 = _mm_or_ps(_mm_cmplt_ps(*(__m128 *)(v7 + 16), v23.mVec128), _mm_cmplt_ps(v24, *(__m128 *)v7));
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
          *(_DWORD *)v18 = *(_DWORD *)(v7 + 40);
        v4 = v13 + 1;
      }
      else
      {
        btSoftColliders::CollideSDF_RS::DoNode(
          (btSoftColliders::CollideSDF_RS *)v7,
          (const float *)v4,
          policy,
          *(btSoftBody::Node **)(v7 + 36));
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
