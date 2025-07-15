void __userpurge btDbvt::collideTTpersistentStack<btDbvtTreeCollider>(
        btDbvt *this@<ecx>,
        int a2@<edi>,
        const btDbvtNode *root0,
        const btDbvtNode *root1,
        btDbvtTreeCollider *policy)
{
  int v5; // ebx
  int v6; // esi
  _DWORD *v7; // eax
  int v8; // edx
  _DWORD *v9; // ecx
  int v10; // eax
  int v11; // edx
  void *v12; // eax
  int v13; // ecx
  _DWORD *v14; // eax
  _DWORD *v15; // eax
  int v16; // eax
  int v17; // ebx
  int v18; // eax
  int v19; // edx
  int v20; // ecx
  _DWORD *v21; // eax
  int v22; // edx
  void *v23; // edx
  _DWORD *v24; // ecx
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  int v28; // ecx
  int v29; // ecx
  int v30; // ebx
  int v31; // eax
  int v32; // esi
  int v33; // edx
  int v34; // ecx
  int v35; // ecx
  int v36; // ecx
  int v37; // ebx
  int v38; // ecx
  int v39; // esi
  int v40; // ecx
  int v41; // edx
  int v42; // ecx
  int v43; // eax
  int v44; // ecx
  int v45; // esi
  _DWORD *v46; // [esp+80h] [ebp-4Ch]
  _DWORD *v47; // [esp+84h] [ebp-48h]
  int v48; // [esp+84h] [ebp-48h]
  int i; // [esp+88h] [ebp-44h]
  int v50; // [esp+88h] [ebp-44h]
  int v51; // [esp+8Ch] [ebp-40h]
  _DWORD *v52; // [esp+8Ch] [ebp-40h]
  int v53; // [esp+8Ch] [ebp-40h]
  int v54; // [esp+90h] [ebp-3Ch]
  int v55; // [esp+90h] [ebp-3Ch]
  int v56; // [esp+94h] [ebp-38h]
  int v57; // [esp+98h] [ebp-34h]
  int v58; // [esp+9Ch] [ebp-30h]
  int v59; // [esp+A0h] [ebp-2Ch]
  int v60; // [esp+A0h] [ebp-2Ch]
  int v61; // [esp+A8h] [ebp-24h]
  int v62; // [esp+B0h] [ebp-1Ch]
  int v63; // [esp+B8h] [ebp-14h]
  __m128 v64; // [esp+BCh] [ebp-10h]

  if ( root0 && root1 )
  {
    v5 = *(_DWORD *)(a2 + 24);
    v6 = 1;
    v54 = 124;
    v51 = v5;
    if ( v5 <= 128 )
    {
      if ( v5 < 128 && *(int *)(a2 + 28) < 128 )
      {
        ++gNumAlignedAllocs;
        v7 = sAlignedAllocFunc(0x400u, 16);
        v8 = *(_DWORD *)(a2 + 24);
        v9 = v7;
        v10 = 0;
        v47 = v9;
        for ( i = v8; v10 < v8; v9 += 2 )
        {
          if ( v9 )
          {
            v11 = *(_DWORD *)(a2 + 32);
            *v9 = *(_DWORD *)(v11 + 8 * v10);
            v5 = v51;
            v9[1] = *(_DWORD *)(v11 + 8 * v10 + 4);
            v8 = i;
          }
          ++v10;
        }
        v12 = *(void **)(a2 + 32);
        if ( v12 )
        {
          if ( *(_BYTE *)(a2 + 36) )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v12);
          }
          *(_DWORD *)(a2 + 32) = 0;
        }
        *(_BYTE *)(a2 + 36) = 1;
        *(_DWORD *)(a2 + 32) = v47;
        *(_DWORD *)(a2 + 28) = 128;
      }
      if ( v5 < 128 )
      {
        v13 = 8 * v5;
        do
        {
          v14 = (_DWORD *)(v13 + *(_DWORD *)(a2 + 32));
          if ( v14 )
          {
            *v14 = v58;
            v14[1] = v59;
          }
          v13 += 8;
        }
        while ( v13 < 1024 );
      }
    }
    *(_DWORD *)(a2 + 24) = 128;
    v15 = *(_DWORD **)(a2 + 32);
    *v15 = root0;
    v15[1] = root1;
    do
    {
      v16 = *(_DWORD *)(a2 + 32);
      v17 = *(_DWORD *)(v16 + 8 * v6 - 8);
      v18 = *(_DWORD *)(v16 + 8 * v6-- - 4);
      v60 = v18;
      if ( v6 > v54 )
      {
        v19 = *(_DWORD *)(a2 + 24);
        v20 = 2 * v19;
        v50 = 2 * v19;
        v57 = v19;
        if ( 2 * v19 >= v19 )
        {
          if ( v20 > v19 && *(_DWORD *)(a2 + 28) < v20 )
          {
            if ( v20 )
            {
              ++gNumAlignedAllocs;
              v21 = sAlignedAllocFunc(16 * v19, 16);
              v20 = v50;
              v52 = v21;
              v18 = v60;
            }
            else
            {
              v52 = 0;
            }
            v55 = *(_DWORD *)(a2 + 24);
            v48 = 0;
            if ( v55 > 0 )
            {
              v22 = 0;
              v46 = v52;
              do
              {
                if ( v46 )
                {
                  v56 = *(_DWORD *)(a2 + 32);
                  *v46 = *(_DWORD *)(v56 + 8 * v22);
                  v46[1] = *(_DWORD *)(v56 + 8 * v48 + 4);
                  v22 = v48;
                }
                v46 += 2;
                v48 = ++v22;
              }
              while ( v22 < v55 );
              v20 = v50;
            }
            v23 = *(void **)(a2 + 32);
            if ( v23 )
            {
              if ( *(_BYTE *)(a2 + 36) )
              {
                ++gNumAlignedFree;
                sAlignedFreeFunc(v23);
                v20 = v50;
                v18 = v60;
              }
              *(_DWORD *)(a2 + 32) = 0;
            }
            *(_DWORD *)(a2 + 32) = v52;
            v19 = v57;
            *(_BYTE *)(a2 + 36) = 1;
            *(_DWORD *)(a2 + 28) = v20;
          }
          v53 = v19;
          if ( v19 < v20 )
          {
            do
            {
              v24 = (_DWORD *)(*(_DWORD *)(a2 + 32) + 8 * v19);
              if ( v24 )
              {
                *v24 = v58;
                v24[1] = v60;
                v19 = v53;
              }
              v20 = v50;
              v53 = ++v19;
            }
            while ( v19 < v50 );
          }
        }
        *(_DWORD *)(a2 + 24) = v20;
        v54 = v20 - 4;
      }
      if ( v17 == v18 )
      {
        if ( *(_DWORD *)(v17 + 40) )
        {
          v25 = *(_DWORD *)(v17 + 36);
          v26 = *(_DWORD *)(a2 + 32);
          *(_DWORD *)(v26 + 8 * v6) = v25;
          *(_DWORD *)(v26 + 8 * v6 + 4) = v25;
          v27 = *(_DWORD *)(v17 + 40);
          v28 = *(_DWORD *)(a2 + 32);
          *(_DWORD *)(v28 + 8 * v6 + 8) = v27;
          *(_DWORD *)(v28 + 8 * v6 + 12) = v27;
          v29 = *(_DWORD *)(v17 + 36);
          v30 = *(_DWORD *)(v17 + 40);
          v31 = *(_DWORD *)(a2 + 32);
          v32 = v6 + 2;
          *(_DWORD *)(v31 + 8 * v32) = v29;
          *(_DWORD *)(v31 + 8 * v32 + 4) = v30;
          v6 = v32 + 1;
        }
      }
      else
      {
        v64 = _mm_or_ps(
                _mm_cmplt_ps(*(__m128 *)(v18 + 16), *(__m128 *)v17),
                _mm_cmplt_ps(*(__m128 *)(v17 + 16), *(__m128 *)v18));
        if ( !(v64.m128_i32[2] | v64.m128_i32[1] | v64.m128_i32[0]) )
        {
          if ( *(_DWORD *)(v17 + 40) )
          {
            v33 = *(_DWORD *)(v17 + 36);
            if ( *(_DWORD *)(v18 + 40) )
            {
              v61 = *(_DWORD *)(v18 + 36);
              v34 = *(_DWORD *)(a2 + 32);
              *(_DWORD *)(v34 + 8 * v6) = v33;
              *(_DWORD *)(v34 + 8 * v6 + 4) = v61;
              v62 = *(_DWORD *)(v18 + 36);
              v35 = *(_DWORD *)(a2 + 32);
              *(_DWORD *)(v35 + 8 * v6 + 8) = *(_DWORD *)(v17 + 40);
              *(_DWORD *)(v35 + 8 * v6 + 12) = v62;
              v6 += 2;
              v63 = *(_DWORD *)(v18 + 40);
              v36 = *(_DWORD *)(a2 + 32);
              *(_DWORD *)(v36 + 8 * v6) = *(_DWORD *)(v17 + 36);
              *(_DWORD *)(v36 + 8 * v6 + 4) = v63;
              v37 = *(_DWORD *)(v17 + 40);
              v18 = *(_DWORD *)(v18 + 40);
            }
            else
            {
              v40 = *(_DWORD *)(a2 + 32);
              *(_DWORD *)(v40 + 8 * v6) = v33;
              *(_DWORD *)(v40 + 8 * v6 + 4) = v18;
              v37 = *(_DWORD *)(v17 + 40);
            }
            v38 = *(_DWORD *)(a2 + 32);
            v39 = v6 + 1;
            *(_DWORD *)(v38 + 8 * v39) = v37;
            *(_DWORD *)(v38 + 8 * v39 + 4) = v18;
            v6 = v39 + 1;
          }
          else if ( *(_DWORD *)(v18 + 40) )
          {
            v41 = *(_DWORD *)(v18 + 36);
            v42 = *(_DWORD *)(a2 + 32);
            *(_DWORD *)(v42 + 8 * v6) = v17;
            *(_DWORD *)(v42 + 8 * v6 + 4) = v41;
            v43 = *(_DWORD *)(v18 + 40);
            v44 = *(_DWORD *)(a2 + 32);
            v45 = v6 + 1;
            *(_DWORD *)(v44 + 8 * v45) = v17;
            *(_DWORD *)(v44 + 8 * v45 + 4) = v43;
            v6 = v45 + 1;
          }
          else
          {
            policy->pbp->m_paircache->addOverlappingPair(
              policy->pbp->m_paircache,
              *(btBroadphaseProxy **)(v17 + 36),
              *(btBroadphaseProxy **)(v18 + 36));
            ++policy->pbp->m_newpairs;
          }
        }
      }
    }
    while ( v6 );
  }
}
