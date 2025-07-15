void __thiscall btDbvt::collideTT<btSoftColliders::CollideCL_SS>(
        const btDbvtNode *root0,
        const btDbvtNode *root1,
        btAlignedObjectArray<GrahamVector2> *policy,
        const btGjkEpaSolver2::sResults *a4)
{
  int v4; // edi
  char *v5; // eax
  char *v6; // esi
  char *v7; // edx
  btAlignedObjectArray<GrahamVector2> *v8; // ecx
  const btDbvtNode *v9; // eax
  const btDbvtNode *v10; // ebx
  int v11; // ecx
  _DWORD *v12; // eax
  _DWORD *v13; // ecx
  bool v14; // zf
  btDbvtNode *v15; // eax
  btDbvtNode *v16; // eax
  int v17; // edi
  btDbvtNode *v18; // eax
  btDbvtNode *v19; // ebx
  int v20; // edi
  btDbvtNode *v21; // edx
  btDbvtNode *v22; // ecx
  int v23; // edi
  btDbvtNode *v24; // edx
  _DWORD *v25; // [esp+10h] [ebp-50h]
  int v26; // [esp+14h] [ebp-4Ch]
  int v27; // [esp+14h] [ebp-4Ch]
  char *v28; // [esp+18h] [ebp-48h]
  int v29; // [esp+18h] [ebp-48h]
  int v30; // [esp+1Ch] [ebp-44h]
  int v31; // [esp+1Ch] [ebp-44h]
  char *v32; // [esp+1Ch] [ebp-44h]
  int v33; // [esp+20h] [ebp-40h]
  int v34; // [esp+24h] [ebp-3Ch]
  const btDbvtNode *v35; // [esp+24h] [ebp-3Ch]
  __m128 v36; // [esp+30h] [ebp-30h]
  char v37[4]; // [esp+4Ch] [ebp-14h] BYREF
  int v38; // [esp+50h] [ebp-10h]
  int v39; // [esp+54h] [ebp-Ch]
  char *v40; // [esp+58h] [ebp-8h]
  char v41; // [esp+5Ch] [ebp-4h]

  if ( policy )
  {
    v4 = 1;
    v30 = 124;
    v5 = (char *)btAlignedAllocInternal(0x400u);
    v6 = v5;
    v41 = 1;
    v40 = v5;
    v39 = 128;
    v7 = v5;
    v26 = 128;
    do
    {
      if ( v7 )
      {
        *(_DWORD *)v7 = v33;
        *((_DWORD *)v7 + 1) = v34;
      }
      v7 += 8;
      --v26;
    }
    while ( v26 );
    v38 = 128;
    *(_DWORD *)v5 = root1;
    v8 = policy;
    *((_DWORD *)v5 + 1) = policy;
    while ( 1 )
    {
      v9 = *(const btDbvtNode **)&v6[8 * v4-- - 4];
      v10 = *(const btDbvtNode **)&v6[8 * v4];
      v35 = v9;
      if ( v4 > v30 )
      {
        v11 = 2 * v38;
        v27 = 2 * v38;
        if ( 2 * v38 > v38 )
        {
          if ( v39 < v11 )
          {
            if ( v11 )
            {
              v12 = btAlignedAllocInternal(16 * v38);
              v11 = 2 * v38;
              v25 = v12;
              v9 = v35;
            }
            else
            {
              v25 = 0;
            }
            if ( v38 > 0 )
            {
              v13 = v25;
              v28 = (char *)(v6 - (char *)v25);
              v31 = v38;
              do
              {
                if ( v13 )
                {
                  *v13 = *(_DWORD *)((char *)v13 + (_DWORD)v28);
                  v13[1] = *(_DWORD *)((char *)v13 + (_DWORD)v28 + 4);
                }
                v13 += 2;
                --v31;
              }
              while ( v31 );
              v11 = v27;
            }
            if ( v6 )
            {
              btAlignedFreeInternal(v6);
              v9 = v35;
              v11 = v27;
            }
            v6 = (char *)v25;
            v41 = 1;
            v39 = v11;
          }
          if ( v38 < v11 )
          {
            v32 = &v6[8 * v38];
            v29 = v11 - v38;
            do
            {
              if ( v32 )
              {
                *(_DWORD *)v32 = v33;
                *((_DWORD *)v32 + 1) = v35;
                v11 = v27;
              }
              v14 = v29-- == 1;
              v32 += 8;
            }
            while ( !v14 );
          }
        }
        v38 = v11;
        v8 = (btAlignedObjectArray<GrahamVector2> *)(v11 - 4);
        v30 = (int)v8;
      }
      if ( v10 == v9 )
      {
        if ( v10->childs[1] )
        {
          v15 = v10->childs[0];
          *(_DWORD *)&v6[8 * v4] = v15;
          *(_DWORD *)&v6[8 * v4 + 4] = v15;
          v16 = v10->childs[1];
          v17 = v4 + 1;
          *(_DWORD *)&v6[8 * v17] = v16;
          *(_DWORD *)&v6[8 * v17 + 4] = v16;
          v18 = v10->childs[0];
          v19 = v10->childs[1];
          v20 = v17 + 1;
          *(_DWORD *)&v6[8 * v20] = v18;
          *(_DWORD *)&v6[8 * v20 + 4] = v19;
          goto LABEL_40;
        }
      }
      else
      {
        v36 = _mm_or_ps(
                _mm_cmplt_ps(v10->volume.mx.mVec128, v9->volume.mi.mVec128),
                _mm_cmplt_ps(v9->volume.mx.mVec128, v10->volume.mi.mVec128));
        v8 = (btAlignedObjectArray<GrahamVector2> *)(v36.m128_i32[2] | v36.m128_i32[1] | v36.m128_i32[0]);
        if ( !v8 )
        {
          if ( v10->childs[1] )
          {
            v8 = (btAlignedObjectArray<GrahamVector2> *)v10->childs[0];
            if ( v9->childs[1] )
            {
              v21 = v9->childs[0];
              *(_DWORD *)&v6[8 * v4] = v8;
              *(_DWORD *)&v6[8 * v4 + 4] = v21;
              v22 = v10->childs[1];
              *(_DWORD *)&v6[8 * v4 + 12] = v9->childs[0];
              v23 = v4 + 1;
              *(_DWORD *)&v6[8 * v23] = v22;
              v8 = (btAlignedObjectArray<GrahamVector2> *)v10->childs[0];
              v24 = v9->childs[1];
              v4 = v23 + 1;
              *(_DWORD *)&v6[8 * v4] = v8;
              *(_DWORD *)&v6[8 * v4 + 4] = v24;
              v10 = v10->childs[1];
              goto LABEL_38;
            }
            *(_DWORD *)&v6[8 * v4] = v8;
            *(_DWORD *)&v6[8 * v4 + 4] = v9;
            v10 = v10->childs[1];
          }
          else
          {
            if ( !v9->childs[1] )
            {
              btSoftColliders::CollideCL_SS::Process(v10, 0, a4, v9);
              goto LABEL_42;
            }
            v8 = (btAlignedObjectArray<GrahamVector2> *)v9->childs[0];
            *(_DWORD *)&v6[8 * v4] = v10;
            *(_DWORD *)&v6[8 * v4 + 4] = v8;
LABEL_38:
            v9 = v9->childs[1];
          }
          v20 = v4 + 1;
          *(_DWORD *)&v6[8 * v20] = v10;
          *(_DWORD *)&v6[8 * v20 + 4] = v9;
LABEL_40:
          v4 = v20 + 1;
        }
      }
LABEL_42:
      if ( !v4 )
      {
        v40 = v6;
        btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v8, (int)v37);
        return;
      }
    }
  }
}


void __thiscall btDbvt::collideTT<btSoftColliders::CollideVF_SS>(
        const btDbvtNode *root0,
        const btDbvtNode *root1,
        btAlignedObjectArray<GrahamVector2> *policy,
        btSoftColliders::CollideVF_SS *a4)
{
  int v4; // edi
  char *v5; // eax
  char *v6; // esi
  char *v7; // edx
  btAlignedObjectArray<GrahamVector2> *v8; // ecx
  const btDbvtNode *v9; // eax
  const btDbvtNode *v10; // ebx
  int v11; // ecx
  _DWORD *v12; // eax
  _DWORD *v13; // ecx
  bool v14; // zf
  btDbvtNode *v15; // eax
  btDbvtNode *v16; // eax
  int v17; // edi
  btDbvtNode *v18; // eax
  btDbvtNode *v19; // ebx
  int v20; // edi
  btDbvtNode *v21; // edx
  btDbvtNode *v22; // ecx
  int v23; // edi
  btDbvtNode *v24; // edx
  _DWORD *v25; // [esp+10h] [ebp-50h]
  int v26; // [esp+14h] [ebp-4Ch]
  int v27; // [esp+14h] [ebp-4Ch]
  char *v28; // [esp+18h] [ebp-48h]
  int v29; // [esp+18h] [ebp-48h]
  int v30; // [esp+1Ch] [ebp-44h]
  int v31; // [esp+1Ch] [ebp-44h]
  char *v32; // [esp+1Ch] [ebp-44h]
  int v33; // [esp+20h] [ebp-40h]
  int v34; // [esp+24h] [ebp-3Ch]
  const btDbvtNode *v35; // [esp+24h] [ebp-3Ch]
  __m128 v36; // [esp+30h] [ebp-30h]
  char v37[4]; // [esp+4Ch] [ebp-14h] BYREF
  int v38; // [esp+50h] [ebp-10h]
  int v39; // [esp+54h] [ebp-Ch]
  char *v40; // [esp+58h] [ebp-8h]
  char v41; // [esp+5Ch] [ebp-4h]

  if ( policy )
  {
    v4 = 1;
    v30 = 124;
    v5 = (char *)btAlignedAllocInternal(0x400u);
    v6 = v5;
    v41 = 1;
    v40 = v5;
    v39 = 128;
    v7 = v5;
    v26 = 128;
    do
    {
      if ( v7 )
      {
        *(_DWORD *)v7 = v33;
        *((_DWORD *)v7 + 1) = v34;
      }
      v7 += 8;
      --v26;
    }
    while ( v26 );
    v38 = 128;
    *(_DWORD *)v5 = root1;
    v8 = policy;
    *((_DWORD *)v5 + 1) = policy;
    while ( 1 )
    {
      v9 = *(const btDbvtNode **)&v6[8 * v4-- - 4];
      v10 = *(const btDbvtNode **)&v6[8 * v4];
      v35 = v9;
      if ( v4 > v30 )
      {
        v11 = 2 * v38;
        v27 = 2 * v38;
        if ( 2 * v38 > v38 )
        {
          if ( v39 < v11 )
          {
            if ( v11 )
            {
              v12 = btAlignedAllocInternal(16 * v38);
              v11 = 2 * v38;
              v25 = v12;
              v9 = v35;
            }
            else
            {
              v25 = 0;
            }
            if ( v38 > 0 )
            {
              v13 = v25;
              v28 = (char *)(v6 - (char *)v25);
              v31 = v38;
              do
              {
                if ( v13 )
                {
                  *v13 = *(_DWORD *)((char *)v13 + (_DWORD)v28);
                  v13[1] = *(_DWORD *)((char *)v13 + (_DWORD)v28 + 4);
                }
                v13 += 2;
                --v31;
              }
              while ( v31 );
              v11 = v27;
            }
            if ( v6 )
            {
              btAlignedFreeInternal(v6);
              v9 = v35;
              v11 = v27;
            }
            v6 = (char *)v25;
            v41 = 1;
            v39 = v11;
          }
          if ( v38 < v11 )
          {
            v32 = &v6[8 * v38];
            v29 = v11 - v38;
            do
            {
              if ( v32 )
              {
                *(_DWORD *)v32 = v33;
                *((_DWORD *)v32 + 1) = v35;
                v11 = v27;
              }
              v14 = v29-- == 1;
              v32 += 8;
            }
            while ( !v14 );
          }
        }
        v38 = v11;
        v8 = (btAlignedObjectArray<GrahamVector2> *)(v11 - 4);
        v30 = (int)v8;
      }
      if ( v10 == v9 )
      {
        if ( v10->childs[1] )
        {
          v15 = v10->childs[0];
          *(_DWORD *)&v6[8 * v4] = v15;
          *(_DWORD *)&v6[8 * v4 + 4] = v15;
          v16 = v10->childs[1];
          v17 = v4 + 1;
          *(_DWORD *)&v6[8 * v17] = v16;
          *(_DWORD *)&v6[8 * v17 + 4] = v16;
          v18 = v10->childs[0];
          v19 = v10->childs[1];
          v20 = v17 + 1;
          *(_DWORD *)&v6[8 * v20] = v18;
          *(_DWORD *)&v6[8 * v20 + 4] = v19;
          goto LABEL_40;
        }
      }
      else
      {
        v36 = _mm_or_ps(
                _mm_cmplt_ps(v10->volume.mx.mVec128, v9->volume.mi.mVec128),
                _mm_cmplt_ps(v9->volume.mx.mVec128, v10->volume.mi.mVec128));
        v8 = (btAlignedObjectArray<GrahamVector2> *)(v36.m128_i32[2] | v36.m128_i32[1] | v36.m128_i32[0]);
        if ( !v8 )
        {
          if ( v10->childs[1] )
          {
            v8 = (btAlignedObjectArray<GrahamVector2> *)v10->childs[0];
            if ( v9->childs[1] )
            {
              v21 = v9->childs[0];
              *(_DWORD *)&v6[8 * v4] = v8;
              *(_DWORD *)&v6[8 * v4 + 4] = v21;
              v22 = v10->childs[1];
              *(_DWORD *)&v6[8 * v4 + 12] = v9->childs[0];
              v23 = v4 + 1;
              *(_DWORD *)&v6[8 * v23] = v22;
              v8 = (btAlignedObjectArray<GrahamVector2> *)v10->childs[0];
              v24 = v9->childs[1];
              v4 = v23 + 1;
              *(_DWORD *)&v6[8 * v4] = v8;
              *(_DWORD *)&v6[8 * v4 + 4] = v24;
              v10 = v10->childs[1];
              goto LABEL_38;
            }
            *(_DWORD *)&v6[8 * v4] = v8;
            *(_DWORD *)&v6[8 * v4 + 4] = v9;
            v10 = v10->childs[1];
          }
          else
          {
            if ( !v9->childs[1] )
            {
              btSoftColliders::CollideVF_SS::Process(v10, a4, v9);
              goto LABEL_42;
            }
            v8 = (btAlignedObjectArray<GrahamVector2> *)v9->childs[0];
            *(_DWORD *)&v6[8 * v4] = v10;
            *(_DWORD *)&v6[8 * v4 + 4] = v8;
LABEL_38:
            v9 = v9->childs[1];
          }
          v20 = v4 + 1;
          *(_DWORD *)&v6[8 * v20] = v10;
          *(_DWORD *)&v6[8 * v20 + 4] = v9;
LABEL_40:
          v4 = v20 + 1;
        }
      }
LABEL_42:
      if ( !v4 )
      {
        v40 = v6;
        btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v8, (int)v37);
        return;
      }
    }
  }
}
