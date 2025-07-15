void __userpurge btDbvt::collideTTpersistentStack<btDbvtTreeCollider>(
        btDbvt *this@<ecx>,
        int a2@<esi>,
        const btDbvtNode *root0,
        const btDbvtNode *root1,
        btDbvtTreeCollider *policy)
{
  int v5; // eax
  int v6; // edi
  _DWORD *v7; // ecx
  int v8; // eax
  int v9; // ecx
  _DWORD *v10; // eax
  _DWORD *v11; // eax
  int v12; // eax
  int v13; // ebx
  int v14; // eax
  int v15; // edx
  int v16; // ecx
  _DWORD *v17; // eax
  _DWORD *v18; // ecx
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // ecx
  int v23; // edi
  int v24; // ecx
  int v25; // ebx
  int v26; // eax
  int v27; // edi
  int v28; // ecx
  int v29; // eax
  int v30; // ecx
  int v31; // edi
  int v32; // ecx
  int v33; // eax
  int v34; // ecx
  int v35; // eax
  int v36; // ecx
  int v37; // ecx
  int v38; // eax
  int v39; // [esp+14h] [ebp-4Ch]
  _DWORD *v40; // [esp+14h] [ebp-4Ch]
  int v41; // [esp+18h] [ebp-48h]
  int v42; // [esp+18h] [ebp-48h]
  int v43; // [esp+18h] [ebp-48h]
  _DWORD *v44; // [esp+1Ch] [ebp-44h]
  int v45; // [esp+1Ch] [ebp-44h]
  int v46; // [esp+20h] [ebp-40h]
  _DWORD *v47; // [esp+20h] [ebp-40h]
  int v48; // [esp+24h] [ebp-3Ch]
  int v49; // [esp+24h] [ebp-3Ch]
  int v50; // [esp+28h] [ebp-38h]
  int v51; // [esp+2Ch] [ebp-34h]
  int v52; // [esp+30h] [ebp-30h]
  int v53; // [esp+34h] [ebp-2Ch]
  int v54; // [esp+34h] [ebp-2Ch]
  int v55; // [esp+3Ch] [ebp-24h]
  int v56; // [esp+44h] [ebp-1Ch]
  int v57; // [esp+4Ch] [ebp-14h]
  __m128 v58; // [esp+50h] [ebp-10h]

  if ( root0 && root1 )
  {
    v5 = *(_DWORD *)(a2 + 24);
    v6 = 1;
    v48 = 124;
    v41 = v5;
    if ( v5 <= 128 )
    {
      if ( v5 < 128 && *(int *)(a2 + 28) < 128 )
      {
        v39 = 0;
        v7 = btAlignedAllocInternal(0x400u);
        v44 = v7;
        v46 = *(_DWORD *)(a2 + 24);
        if ( v46 > 0 )
        {
          do
          {
            if ( v7 )
            {
              v8 = *(_DWORD *)(a2 + 32);
              *v7 = *(_DWORD *)(v8 + 8 * v39);
              v7[1] = *(_DWORD *)(v8 + 8 * v39 + 4);
            }
            ++v39;
            v7 += 2;
          }
          while ( v39 < v46 );
        }
        if ( *(_DWORD *)(a2 + 32) )
        {
          if ( *(_BYTE *)(a2 + 36) )
            btAlignedFreeInternal(*(void **)(a2 + 32));
          *(_DWORD *)(a2 + 32) = 0;
        }
        *(_DWORD *)(a2 + 32) = v44;
        v5 = v41;
        *(_BYTE *)(a2 + 36) = 1;
        *(_DWORD *)(a2 + 28) = 128;
      }
      if ( v5 < 128 )
      {
        v9 = 8 * v5;
        do
        {
          v10 = (_DWORD *)(v9 + *(_DWORD *)(a2 + 32));
          if ( v10 )
          {
            *v10 = v52;
            v10[1] = v53;
          }
          v9 += 8;
        }
        while ( v9 < 1024 );
      }
    }
    *(_DWORD *)(a2 + 24) = 128;
    v11 = *(_DWORD **)(a2 + 32);
    *v11 = root0;
    v11[1] = root1;
    do
    {
      v12 = *(_DWORD *)(a2 + 32);
      --v6;
      v13 = *(_DWORD *)(v12 + 8 * v6);
      v14 = *(_DWORD *)(v12 + 8 * v6 + 4);
      v54 = v14;
      if ( v6 > v48 )
      {
        v15 = *(_DWORD *)(a2 + 24);
        v16 = 2 * v15;
        v45 = 2 * v15;
        v51 = v15;
        if ( 2 * v15 >= v15 )
        {
          if ( v16 > v15 && *(_DWORD *)(a2 + 28) < v16 )
          {
            if ( v16 )
            {
              v17 = btAlignedAllocInternal(16 * *(_DWORD *)(a2 + 24));
              v16 = v45;
              v47 = v17;
              v14 = v54;
            }
            else
            {
              v47 = 0;
            }
            v42 = 0;
            v49 = *(_DWORD *)(a2 + 24);
            if ( v49 > 0 )
            {
              v40 = v47;
              do
              {
                if ( v40 )
                {
                  v50 = *(_DWORD *)(a2 + 32);
                  *v40 = *(_DWORD *)(v50 + 8 * v42);
                  v40[1] = *(_DWORD *)(v50 + 8 * v42 + 4);
                }
                ++v42;
                v40 += 2;
              }
              while ( v42 < v49 );
              v16 = v45;
            }
            if ( *(_DWORD *)(a2 + 32) )
            {
              if ( *(_BYTE *)(a2 + 36) )
              {
                btAlignedFreeInternal(*(void **)(a2 + 32));
                v14 = v54;
                v16 = v45;
              }
              *(_DWORD *)(a2 + 32) = 0;
            }
            *(_DWORD *)(a2 + 32) = v47;
            v15 = v51;
            *(_BYTE *)(a2 + 36) = 1;
            *(_DWORD *)(a2 + 28) = v16;
          }
          v43 = v15;
          if ( v15 < v16 )
          {
            do
            {
              v18 = (_DWORD *)(*(_DWORD *)(a2 + 32) + 8 * v43);
              if ( v18 )
              {
                *v18 = v52;
                v18[1] = v54;
              }
              ++v43;
              v16 = v45;
            }
            while ( v43 < v45 );
          }
        }
        *(_DWORD *)(a2 + 24) = v16;
        v48 = v16 - 4;
      }
      if ( v13 == v14 )
      {
        if ( *(_DWORD *)(v13 + 40) )
        {
          v19 = *(_DWORD *)(v13 + 36);
          v20 = *(_DWORD *)(a2 + 32);
          *(_DWORD *)(v20 + 8 * v6) = v19;
          *(_DWORD *)(v20 + 8 * v6 + 4) = v19;
          v21 = *(_DWORD *)(v13 + 40);
          v22 = *(_DWORD *)(a2 + 32);
          *(_DWORD *)(v22 + 8 * v6 + 12) = v21;
          v23 = v6 + 1;
          *(_DWORD *)(v22 + 8 * v23) = v21;
          v24 = *(_DWORD *)(v13 + 36);
          v25 = *(_DWORD *)(v13 + 40);
          v26 = *(_DWORD *)(a2 + 32);
          v27 = v23 + 1;
          *(_DWORD *)(v26 + 8 * v27) = v24;
          *(_DWORD *)(v26 + 8 * v27 + 4) = v25;
LABEL_55:
          v6 = v27 + 1;
        }
      }
      else
      {
        v58 = _mm_or_ps(
                _mm_cmplt_ps(*(__m128 *)(v14 + 16), *(__m128 *)v13),
                _mm_cmplt_ps(*(__m128 *)(v13 + 16), *(__m128 *)v14));
        if ( !(v58.m128_i32[2] | v58.m128_i32[1] | v58.m128_i32[0]) )
        {
          if ( *(_DWORD *)(v13 + 40) )
          {
            v28 = *(_DWORD *)(v13 + 36);
            if ( *(_DWORD *)(v14 + 40) )
            {
              v55 = *(_DWORD *)(v14 + 36);
              v29 = *(_DWORD *)(a2 + 32);
              *(_DWORD *)(v29 + 8 * v6) = v28;
              *(_DWORD *)(v29 + 8 * v6 + 4) = v55;
              v56 = *(_DWORD *)(v54 + 36);
              v30 = *(_DWORD *)(a2 + 32);
              v31 = v6 + 1;
              *(_DWORD *)(v30 + 8 * v31) = *(_DWORD *)(v13 + 40);
              *(_DWORD *)(v30 + 8 * v31 + 4) = v56;
              v57 = *(_DWORD *)(v54 + 40);
              v32 = *(_DWORD *)(a2 + 32);
              ++v31;
              *(_DWORD *)(v32 + 8 * v31) = *(_DWORD *)(v13 + 36);
              *(_DWORD *)(v32 + 8 * v31 + 4) = v57;
              v33 = *(_DWORD *)(v54 + 40);
              v34 = *(_DWORD *)(a2 + 32);
              v27 = v31 + 1;
              *(_DWORD *)(v34 + 8 * v27) = *(_DWORD *)(v13 + 40);
              *(_DWORD *)(v34 + 8 * v27 + 4) = v33;
              goto LABEL_55;
            }
            v35 = *(_DWORD *)(a2 + 32);
            *(_DWORD *)(v35 + 8 * v6) = v28;
            v36 = v54;
            *(_DWORD *)(v35 + 8 * v6 + 4) = v54;
            v13 = *(_DWORD *)(v13 + 40);
          }
          else
          {
            if ( !*(_DWORD *)(v14 + 40) )
            {
              policy->pbp->m_paircache->addOverlappingPair(
                policy->pbp->m_paircache,
                *(btBroadphaseProxy **)(v13 + 36),
                *(btBroadphaseProxy **)(v14 + 36));
              ++policy->pbp->m_newpairs;
              continue;
            }
            v37 = *(_DWORD *)(a2 + 32);
            *(_DWORD *)(v37 + 8 * v6 + 4) = *(_DWORD *)(v14 + 36);
            *(_DWORD *)(v37 + 8 * v6) = v13;
            v36 = *(_DWORD *)(v54 + 40);
          }
          v38 = *(_DWORD *)(a2 + 32);
          v27 = v6 + 1;
          *(_DWORD *)(v38 + 8 * v27) = v13;
          *(_DWORD *)(v38 + 8 * v27 + 4) = v36;
          goto LABEL_55;
        }
      }
    }
    while ( v6 );
  }
}
