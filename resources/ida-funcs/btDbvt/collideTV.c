void __userpurge btDbvt::collideTV<BroadphaseAabbTester>(
        const btDbvtAabbMm *vol@<eax>,
        btAlignedObjectArray<GrahamVector2> *root,
        BroadphaseAabbTester *policy)
{
  _DWORD *v3; // eax
  _DWORD *v4; // edi
  btAlignedObjectArray<GrahamVector2> *v5; // ecx
  int v6; // esi
  int v7; // edx
  int v8; // ebx
  _DWORD *v9; // eax
  _DWORD *v10; // eax
  int v11; // edx
  btAlignedObjectArray<GrahamVector2> **v12; // eax
  int v13; // esi
  int v14; // ebx
  _DWORD *v15; // eax
  _DWORD *v16; // eax
  int v17; // edx
  btAlignedObjectArray<GrahamVector2> **v18; // eax
  btAlignedObjectArray<GrahamVector2> *v19; // [esp-4h] [ebp-74h]
  btAlignedObjectArray<GrahamVector2> *v20; // [esp-4h] [ebp-74h]
  btAlignedObjectArray<GrahamVector2> *v21; // [esp-4h] [ebp-74h]
  btAlignedObjectArray<GrahamVector2> *v22; // [esp-4h] [ebp-74h]
  btAlignedObjectArray<GrahamVector2> *v23; // [esp-4h] [ebp-74h]
  int v24; // [esp+18h] [ebp-58h]
  int v25; // [esp+18h] [ebp-58h]
  int v26; // [esp+1Ch] [ebp-54h]
  __m128 v27; // [esp+20h] [ebp-50h]
  _DWORD v28[2]; // [esp+3Ch] [ebp-34h] BYREF
  int v29; // [esp+44h] [ebp-2Ch]
  void *ptr; // [esp+48h] [ebp-28h]
  char v31; // [esp+4Ch] [ebp-24h]
  __m128 v32[2]; // [esp+50h] [ebp-20h] BYREF

  qmemcpy(v32, vol, sizeof(v32));
  v3 = btAlignedAllocInternal(0x100u);
  v4 = v3;
  v5 = v19;
  v31 = 1;
  ptr = v3;
  v29 = 64;
  if ( v3 )
  {
    v5 = root;
    *v3 = root;
  }
  v6 = 1;
  do
  {
    v7 = v4[v6 - 1];
    v27 = _mm_or_ps(_mm_cmplt_ps(*(__m128 *)(v7 + 16), v32[0]), _mm_cmplt_ps(v32[1], *(__m128 *)v7));
    --v6;
    v26 = v7;
    if ( !(v27.m128_i32[2] | v27.m128_i32[1] | v27.m128_i32[0]) )
    {
      if ( *(_DWORD *)(v7 + 40) )
      {
        if ( v6 == v29 )
        {
          v8 = v6 ? 2 * v6 : 1;
          v24 = v8;
          if ( v29 < v8 )
          {
            if ( v8 )
            {
              v9 = btAlignedAllocInternal(4 * v8);
              v5 = v20;
              v4 = v9;
            }
            else
            {
              v4 = 0;
            }
            if ( v6 > 0 )
            {
              v10 = v4;
              v5 = (btAlignedObjectArray<GrahamVector2> *)((_BYTE *)ptr - (_BYTE *)v4);
              v11 = v6;
              do
              {
                if ( v10 )
                {
                  *v10 = *(_DWORD *)((char *)v10 + (_DWORD)v5);
                  v8 = v24;
                }
                ++v10;
                --v11;
              }
              while ( v11 );
            }
            if ( ptr )
            {
              btAlignedFreeInternal(ptr);
              v5 = v21;
            }
            v7 = v26;
            v31 = 1;
            ptr = v4;
            v29 = v8;
          }
        }
        v12 = (btAlignedObjectArray<GrahamVector2> **)&v4[v6];
        if ( v12 )
        {
          v5 = *(btAlignedObjectArray<GrahamVector2> **)(v7 + 36);
          *v12 = v5;
        }
        v13 = v6 + 1;
        if ( v13 == v29 )
        {
          v14 = v13 ? 2 * v13 : 1;
          v25 = v14;
          if ( v29 < v14 )
          {
            if ( v14 )
            {
              v15 = btAlignedAllocInternal(4 * v14);
              v5 = v22;
              v4 = v15;
            }
            else
            {
              v4 = 0;
            }
            if ( v13 > 0 )
            {
              v16 = v4;
              v5 = (btAlignedObjectArray<GrahamVector2> *)((_BYTE *)ptr - (_BYTE *)v4);
              v17 = v13;
              do
              {
                if ( v16 )
                {
                  *v16 = *(_DWORD *)((char *)v16 + (_DWORD)v5);
                  v14 = v25;
                }
                ++v16;
                --v17;
              }
              while ( v17 );
            }
            if ( ptr )
            {
              btAlignedFreeInternal(ptr);
              v5 = v23;
            }
            v7 = v26;
            v31 = 1;
            ptr = v4;
            v29 = v14;
          }
        }
        v18 = (btAlignedObjectArray<GrahamVector2> **)&v4[v13];
        if ( v18 )
        {
          v5 = *(btAlignedObjectArray<GrahamVector2> **)(v7 + 40);
          *v18 = v5;
        }
        v6 = v13 + 1;
      }
      else
      {
        policy->m_aabbCallback->process(policy->m_aabbCallback, *(const btBroadphaseProxy **)(v7 + 36));
      }
    }
  }
  while ( v6 > 0 );
  v28[1] = v6;
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v5, (int)v28);
}


void __userpurge btDbvt::collideTV<btCompoundLeafCallback>(
        const btDbvtAabbMm *vol@<eax>,
        const btDbvtNode *root,
        btCollisionShape *policy)
{
  _DWORD *v3; // eax
  _DWORD *v4; // edi
  int v5; // esi
  __m128 *v6; // ecx
  int v7; // ebx
  _DWORD *v8; // eax
  char *v9; // ecx
  int v10; // edx
  _DWORD *v11; // eax
  int v12; // esi
  int v13; // ebx
  _DWORD *v14; // eax
  char *v15; // ecx
  int v16; // edx
  __m128 **v17; // eax
  int v18; // [esp+18h] [ebp-58h]
  int v19; // [esp+18h] [ebp-58h]
  __m128 *v20; // [esp+1Ch] [ebp-54h]
  __m128 v21; // [esp+20h] [ebp-50h]
  _BYTE v22[4]; // [esp+3Ch] [ebp-34h] BYREF
  int v23; // [esp+40h] [ebp-30h]
  int v24; // [esp+44h] [ebp-2Ch]
  void *ptr; // [esp+48h] [ebp-28h]
  char v26; // [esp+4Ch] [ebp-24h]
  __m128 v27[2]; // [esp+50h] [ebp-20h] BYREF

  qmemcpy(v27, vol, sizeof(v27));
  v3 = btAlignedAllocInternal(0x100u);
  v4 = v3;
  v26 = 1;
  ptr = v3;
  v24 = 64;
  if ( v3 )
    *v3 = root;
  v5 = 1;
  do
  {
    v6 = (__m128 *)v4[v5 - 1];
    v21 = _mm_or_ps(_mm_cmplt_ps(v6[1], v27[0]), _mm_cmplt_ps(v27[1], *v6));
    --v5;
    v20 = v6;
    if ( !(v21.m128_i32[2] | v21.m128_i32[1] | v21.m128_i32[0]) )
    {
      if ( v6[2].m128_i32[2] )
      {
        if ( v5 == v24 )
        {
          v7 = v5 ? 2 * v5 : 1;
          v18 = v7;
          if ( v24 < v7 )
          {
            if ( v7 )
              v4 = btAlignedAllocInternal(4 * v7);
            else
              v4 = 0;
            if ( v5 > 0 )
            {
              v8 = v4;
              v9 = (char *)((_BYTE *)ptr - (_BYTE *)v4);
              v10 = v5;
              do
              {
                if ( v8 )
                {
                  *v8 = *(_DWORD *)((char *)v8 + (_DWORD)v9);
                  v7 = v18;
                }
                ++v8;
                --v10;
              }
              while ( v10 );
            }
            if ( ptr )
              btAlignedFreeInternal(ptr);
            v6 = v20;
            v26 = 1;
            ptr = v4;
            v24 = v7;
          }
        }
        v11 = &v4[v5];
        if ( v11 )
          *v11 = v6[2].m128_i32[1];
        v12 = v5 + 1;
        if ( v12 == v24 )
        {
          v13 = v12 ? 2 * v12 : 1;
          v19 = v13;
          if ( v24 < v13 )
          {
            if ( v13 )
              v4 = btAlignedAllocInternal(4 * v13);
            else
              v4 = 0;
            if ( v12 > 0 )
            {
              v14 = v4;
              v15 = (char *)((_BYTE *)ptr - (_BYTE *)v4);
              v16 = v12;
              do
              {
                if ( v14 )
                {
                  *v14 = *(_DWORD *)((char *)v14 + (_DWORD)v15);
                  v13 = v19;
                }
                ++v14;
                --v16;
              }
              while ( v16 );
            }
            if ( ptr )
              btAlignedFreeInternal(ptr);
            v6 = v20;
            v26 = 1;
            ptr = v4;
            v24 = v13;
          }
        }
        v17 = (__m128 **)&v4[v12];
        if ( v17 )
        {
          v6 = (__m128 *)v6[2].m128_i32[2];
          *v17 = v6;
        }
        v5 = v12 + 1;
      }
      else
      {
        btCompoundLeafCallback::Process((btCompoundLeafCallback *)v6, policy, (int)v6);
      }
    }
  }
  while ( v5 > 0 );
  v23 = v5;
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)v6,
    (int)v22);
}


void __userpurge btDbvt::collideTV<btDbvtTreeCollider>(
        const btDbvtAabbMm *vol@<eax>,
        btAlignedObjectArray<GrahamVector2> *root,
        btDbvtTreeCollider *policy)
{
  _DWORD *v3; // eax
  btAlignedObjectArray<GrahamVector2> *v4; // ecx
  int v5; // esi
  int v6; // edx
  int v7; // ebx
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  _DWORD *v10; // eax
  int v11; // edx
  btAlignedObjectArray<GrahamVector2> **v12; // eax
  int v13; // esi
  int v14; // ebx
  _DWORD *v15; // eax
  _DWORD *v16; // edi
  _DWORD *v17; // eax
  int v18; // edx
  btAlignedObjectArray<GrahamVector2> **v19; // eax
  btDbvtNode *leaf; // eax
  btAlignedObjectArray<GrahamVector2> *v21; // [esp-4h] [ebp-74h]
  btAlignedObjectArray<GrahamVector2> *v22; // [esp-4h] [ebp-74h]
  btAlignedObjectArray<GrahamVector2> *v23; // [esp-4h] [ebp-74h]
  btAlignedObjectArray<GrahamVector2> *v24; // [esp-4h] [ebp-74h]
  btAlignedObjectArray<GrahamVector2> *v25; // [esp-4h] [ebp-74h]
  int v26; // [esp+18h] [ebp-58h]
  int v27; // [esp+18h] [ebp-58h]
  int v28; // [esp+1Ch] [ebp-54h]
  __m128 v29; // [esp+20h] [ebp-50h]
  char v30[4]; // [esp+3Ch] [ebp-34h] BYREF
  int v31; // [esp+40h] [ebp-30h]
  int v32; // [esp+44h] [ebp-2Ch]
  void *ptr; // [esp+48h] [ebp-28h]
  char v34; // [esp+4Ch] [ebp-24h]
  __m128 v35[2]; // [esp+50h] [ebp-20h] BYREF

  qmemcpy(v35, vol, sizeof(v35));
  v3 = btAlignedAllocInternal(0x100u);
  v4 = v21;
  v34 = 1;
  ptr = v3;
  v32 = 64;
  if ( v3 )
  {
    v4 = root;
    *v3 = root;
  }
  v5 = 1;
  do
  {
    v6 = *((_DWORD *)ptr + v5 - 1);
    v29 = _mm_or_ps(_mm_cmplt_ps(*(__m128 *)(v6 + 16), v35[0]), _mm_cmplt_ps(v35[1], *(__m128 *)v6));
    --v5;
    v28 = v6;
    if ( !(v29.m128_i32[2] | v29.m128_i32[1] | v29.m128_i32[0]) )
    {
      if ( *(_DWORD *)(v6 + 40) )
      {
        if ( v5 == v32 )
        {
          v7 = v5 ? 2 * v5 : 1;
          v26 = v7;
          if ( v32 < v7 )
          {
            if ( v7 )
            {
              v8 = btAlignedAllocInternal(4 * v7);
              v4 = v22;
              v9 = v8;
            }
            else
            {
              v9 = 0;
            }
            if ( v5 > 0 )
            {
              v10 = v9;
              v4 = (btAlignedObjectArray<GrahamVector2> *)((_BYTE *)ptr - (_BYTE *)v9);
              v11 = v5;
              do
              {
                if ( v10 )
                {
                  *v10 = *(_DWORD *)((char *)v10 + (_DWORD)v4);
                  v7 = v26;
                }
                ++v10;
                --v11;
              }
              while ( v11 );
            }
            if ( ptr )
            {
              btAlignedFreeInternal(ptr);
              v4 = v23;
            }
            v6 = v28;
            v34 = 1;
            ptr = v9;
            v32 = v7;
          }
        }
        v12 = (btAlignedObjectArray<GrahamVector2> **)((char *)ptr + 4 * v5);
        if ( v12 )
        {
          v4 = *(btAlignedObjectArray<GrahamVector2> **)(v6 + 36);
          *v12 = v4;
        }
        v13 = v5 + 1;
        if ( v13 == v32 )
        {
          v14 = v13 ? 2 * v13 : 1;
          v27 = v14;
          if ( v32 < v14 )
          {
            if ( v14 )
            {
              v15 = btAlignedAllocInternal(4 * v14);
              v4 = v24;
              v16 = v15;
            }
            else
            {
              v16 = 0;
            }
            if ( v13 > 0 )
            {
              v17 = v16;
              v4 = (btAlignedObjectArray<GrahamVector2> *)((_BYTE *)ptr - (_BYTE *)v16);
              v18 = v13;
              do
              {
                if ( v17 )
                {
                  *v17 = *(_DWORD *)((char *)v17 + (_DWORD)v4);
                  v14 = v27;
                }
                ++v17;
                --v18;
              }
              while ( v18 );
            }
            if ( ptr )
            {
              btAlignedFreeInternal(ptr);
              v4 = v25;
            }
            v6 = v28;
            v34 = 1;
            ptr = v16;
            v32 = v14;
          }
        }
        v19 = (btAlignedObjectArray<GrahamVector2> **)((char *)ptr + 4 * v13);
        if ( v19 )
        {
          v4 = *(btAlignedObjectArray<GrahamVector2> **)(v6 + 40);
          *v19 = v4;
        }
        v5 = v13 + 1;
      }
      else
      {
        leaf = policy->proxy->leaf;
        if ( (btDbvtNode *)v6 != leaf )
        {
          policy->pbp->m_paircache->addOverlappingPair(
            policy->pbp->m_paircache,
            *(btBroadphaseProxy **)(v6 + 36),
            (btBroadphaseProxy *)leaf->dataAsInt);
          ++policy->pbp->m_newpairs;
        }
      }
    }
  }
  while ( v5 > 0 );
  v31 = v5;
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v4, (int)v30);
}


void __userpurge btDbvt::collideTV<btSoftColliders::CollideCL_RS>(
        const btDbvtAabbMm *vol@<eax>,
        const btDbvtNode *root,
        btSoftColliders::CollideCL_RS *policy)
{
  char *v3; // eax
  char *v4; // ebx
  int v5; // esi
  btDbvtNode *v6; // ecx
  _DWORD *v7; // eax
  _DWORD *v8; // edi
  _DWORD *v9; // eax
  char *v10; // eax
  int v11; // esi
  int v12; // ebx
  _DWORD *v13; // edi
  _DWORD *v14; // eax
  char *v15; // ecx
  int v16; // edx
  btDbvtNode **v17; // eax
  btDbvtNode *v18; // [esp+14h] [ebp-5Ch]
  int v19; // [esp+18h] [ebp-58h]
  int v20; // [esp+1Ch] [ebp-54h]
  int v21; // [esp+1Ch] [ebp-54h]
  __m128 v22; // [esp+20h] [ebp-50h]
  char v23[4]; // [esp+3Ch] [ebp-34h] BYREF
  int v24; // [esp+40h] [ebp-30h]
  int v25; // [esp+44h] [ebp-2Ch]
  void *ptr; // [esp+48h] [ebp-28h]
  char v27; // [esp+4Ch] [ebp-24h]
  __m128 v28[2]; // [esp+50h] [ebp-20h] BYREF

  qmemcpy(v28, vol, sizeof(v28));
  v3 = (char *)btAlignedAllocInternal(0x100u);
  v4 = v3;
  v27 = 1;
  ptr = v3;
  v25 = 64;
  if ( v3 )
    *(_DWORD *)v3 = root;
  v5 = 1;
  do
  {
    v6 = *(btDbvtNode **)&v4[4 * v5 - 4];
    v22 = _mm_or_ps(_mm_cmplt_ps(v6->volume.mx.mVec128, v28[0]), _mm_cmplt_ps(v28[1], v6->volume.mi.mVec128));
    --v5;
    v18 = v6;
    if ( !(v22.m128_i32[2] | v22.m128_i32[1] | v22.m128_i32[0]) )
    {
      if ( v6->childs[1] )
      {
        if ( v5 == v25 )
        {
          v19 = v5 ? 2 * v5 : 1;
          if ( v25 < v19 )
          {
            if ( v19 )
            {
              v7 = btAlignedAllocInternal(4 * v19);
              v6 = v18;
              v8 = v7;
            }
            else
            {
              v8 = 0;
            }
            if ( v5 > 0 )
            {
              v9 = v8;
              v20 = v5;
              do
              {
                if ( v9 )
                  *v9 = *(_DWORD *)((char *)v9 + v4 - (char *)v8);
                ++v9;
                --v20;
              }
              while ( v20 );
              v6 = v18;
            }
            if ( v4 )
            {
              btAlignedFreeInternal(v4);
              v6 = v18;
            }
            v27 = 1;
            ptr = v8;
            v25 = v19;
            v4 = (char *)v8;
          }
        }
        v10 = &v4[4 * v5];
        if ( v10 )
          *(_DWORD *)v10 = v6->childs[0];
        v11 = v5 + 1;
        if ( v11 == v25 )
        {
          if ( v11 )
            v12 = 2 * v11;
          else
            v12 = 1;
          v21 = v12;
          if ( v25 < v12 )
          {
            if ( v12 )
              v13 = btAlignedAllocInternal(4 * v12);
            else
              v13 = 0;
            if ( v11 > 0 )
            {
              v14 = v13;
              v15 = (char *)((_BYTE *)ptr - (_BYTE *)v13);
              v16 = v11;
              do
              {
                if ( v14 )
                {
                  *v14 = *(_DWORD *)((char *)v14 + (_DWORD)v15);
                  v12 = v21;
                }
                ++v14;
                --v16;
              }
              while ( v16 );
            }
            if ( ptr )
              btAlignedFreeInternal(ptr);
            v27 = 1;
            ptr = v13;
            v25 = v12;
          }
          v6 = v18;
          v4 = (char *)ptr;
        }
        v17 = (btDbvtNode **)&v4[4 * v11];
        if ( v17 )
        {
          v6 = v6->childs[1];
          *v17 = v6;
        }
        v5 = v11 + 1;
      }
      else
      {
        btSoftColliders::CollideCL_RS::Process(policy, v6, (btConvexInternalShape *)v6);
      }
    }
  }
  while ( v5 > 0 );
  v24 = v5;
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)v6,
    (int)v23);
}


void __userpurge btDbvt::collideTV<btSoftColliders::CollideSDF_RS>(
        const btDbvtAabbMm *vol@<eax>,
        const btDbvtNode *root,
        btSoftBody::Node *policy)
{
  _DWORD *v3; // eax
  _DWORD *v4; // edi
  int v5; // esi
  __m128 *v6; // ecx
  int v7; // ebx
  _DWORD *v8; // eax
  char *v9; // ecx
  int v10; // edx
  _DWORD *v11; // eax
  int v12; // esi
  int v13; // ebx
  _DWORD *v14; // eax
  char *v15; // ecx
  int v16; // edx
  __m128 **v17; // eax
  int v18; // [esp+18h] [ebp-58h]
  int v19; // [esp+18h] [ebp-58h]
  __m128 *v20; // [esp+1Ch] [ebp-54h]
  __m128 v21; // [esp+20h] [ebp-50h]
  _BYTE v22[4]; // [esp+3Ch] [ebp-34h] BYREF
  int v23; // [esp+40h] [ebp-30h]
  int v24; // [esp+44h] [ebp-2Ch]
  void *ptr; // [esp+48h] [ebp-28h]
  char v26; // [esp+4Ch] [ebp-24h]
  __m128 v27[2]; // [esp+50h] [ebp-20h] BYREF

  qmemcpy(v27, vol, sizeof(v27));
  v3 = btAlignedAllocInternal(0x100u);
  v4 = v3;
  v26 = 1;
  ptr = v3;
  v24 = 64;
  if ( v3 )
    *v3 = root;
  v5 = 1;
  do
  {
    v6 = (__m128 *)v4[v5 - 1];
    v21 = _mm_or_ps(_mm_cmplt_ps(v6[1], v27[0]), _mm_cmplt_ps(v27[1], *v6));
    --v5;
    v20 = v6;
    if ( !(v21.m128_i32[2] | v21.m128_i32[1] | v21.m128_i32[0]) )
    {
      if ( v6[2].m128_i32[2] )
      {
        if ( v5 == v24 )
        {
          v7 = v5 ? 2 * v5 : 1;
          v18 = v7;
          if ( v24 < v7 )
          {
            if ( v7 )
              v4 = btAlignedAllocInternal(4 * v7);
            else
              v4 = 0;
            if ( v5 > 0 )
            {
              v8 = v4;
              v9 = (char *)((_BYTE *)ptr - (_BYTE *)v4);
              v10 = v5;
              do
              {
                if ( v8 )
                {
                  *v8 = *(_DWORD *)((char *)v8 + (_DWORD)v9);
                  v7 = v18;
                }
                ++v8;
                --v10;
              }
              while ( v10 );
            }
            if ( ptr )
              btAlignedFreeInternal(ptr);
            v6 = v20;
            v26 = 1;
            ptr = v4;
            v24 = v7;
          }
        }
        v11 = &v4[v5];
        if ( v11 )
          *v11 = v6[2].m128_i32[1];
        v12 = v5 + 1;
        if ( v12 == v24 )
        {
          v13 = v12 ? 2 * v12 : 1;
          v19 = v13;
          if ( v24 < v13 )
          {
            if ( v13 )
              v4 = btAlignedAllocInternal(4 * v13);
            else
              v4 = 0;
            if ( v12 > 0 )
            {
              v14 = v4;
              v15 = (char *)((_BYTE *)ptr - (_BYTE *)v4);
              v16 = v12;
              do
              {
                if ( v14 )
                {
                  *v14 = *(_DWORD *)((char *)v14 + (_DWORD)v15);
                  v13 = v19;
                }
                ++v14;
                --v16;
              }
              while ( v16 );
            }
            if ( ptr )
              btAlignedFreeInternal(ptr);
            v6 = v20;
            v26 = 1;
            ptr = v4;
            v24 = v13;
          }
        }
        v17 = (__m128 **)&v4[v12];
        if ( v17 )
        {
          v6 = (__m128 *)v6[2].m128_i32[2];
          *v17 = v6;
        }
        v5 = v12 + 1;
      }
      else
      {
        btSoftColliders::CollideSDF_RS::DoNode(
          (btSoftColliders::CollideSDF_RS *)v6,
          (const float *)v4,
          policy,
          v6[2].m128_i32[1]);
      }
    }
  }
  while ( v5 > 0 );
  v23 = v5;
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)v6,
    (int)v22);
}
