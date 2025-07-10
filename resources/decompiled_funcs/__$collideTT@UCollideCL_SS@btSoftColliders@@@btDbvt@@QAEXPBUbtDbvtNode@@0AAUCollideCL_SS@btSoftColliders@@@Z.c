void __thiscall btDbvt::collideTT<btSoftColliders::CollideCL_SS>(
        const btDbvtNode *root0,
        const btDbvtNode *root1,
        const btDbvtNode *policy,
        btSoftColliders::CollideCL_SS *policya)
{
  int v4; // esi
  char *v5; // eax
  int v6; // ecx
  char *v7; // edi
  int v8; // edx
  const btDbvtNode *v9; // ecx
  const btDbvtNode *v10; // ebx
  int v11; // eax
  char *v12; // eax
  char *v13; // edx
  _DWORD *v14; // eax
  char *v15; // eax
  btDbvtNode *v16; // eax
  btDbvtNode *v17; // eax
  int v18; // esi
  btDbvtNode *v19; // eax
  btDbvtNode *v20; // ebx
  btDbvtNode *v21; // eax
  btDbvtNode *v22; // edx
  btDbvtNode *v23; // edx
  btDbvtNode *v24; // edx
  btDbvtNode *v25; // ebx
  int v26; // esi
  btDbvtNode *v27; // eax
  btDbvtNode *v28; // ecx
  int v29; // esi
  int v30; // [esp+A0h] [ebp-4Ch]
  char *v31; // [esp+A4h] [ebp-48h]
  int v32; // [esp+ACh] [ebp-40h]
  int v33; // [esp+ACh] [ebp-40h]
  int v34; // [esp+ACh] [ebp-40h]
  int v35; // [esp+B4h] [ebp-38h]
  btDbvtNode *lb; // [esp+B8h] [ebp-34h]
  btDbvtNode *lba; // [esp+B8h] [ebp-34h]
  __m128 v38; // [esp+BCh] [ebp-30h]
  int v39; // [esp+DCh] [ebp-10h]
  int v40; // [esp+E0h] [ebp-Ch]

  if ( policy )
  {
    v4 = 1;
    ++gNumAlignedAllocs;
    v32 = 124;
    v5 = (char *)sAlignedAllocFunc(0x400u, 16);
    v6 = 128;
    v7 = v5;
    v40 = 128;
    do
    {
      if ( v5 )
      {
        *(_DWORD *)v5 = v35;
        *((_DWORD *)v5 + 1) = lb;
      }
      v5 += 8;
      --v6;
    }
    while ( v6 );
    v8 = 128;
    v39 = 128;
    *(_DWORD *)v7 = root1;
    *((_DWORD *)v7 + 1) = policy;
    while ( 1 )
    {
      v9 = *(const btDbvtNode **)&v7[8 * v4 - 4];
      v10 = *(const btDbvtNode **)&v7[8 * v4-- - 8];
      lba = (btDbvtNode *)v9;
      if ( v4 > v32 )
      {
        v11 = 2 * v8;
        v30 = 2 * v8;
        if ( 2 * v8 > v8 )
        {
          if ( v40 < v11 )
          {
            if ( v11 )
            {
              ++gNumAlignedAllocs;
              v12 = (char *)sAlignedAllocFunc(16 * v8, 16);
              v9 = lba;
              v31 = v12;
              v11 = v30;
            }
            else
            {
              v31 = 0;
            }
            if ( v39 > 0 )
            {
              v13 = (char *)(v7 - v31);
              v33 = v39;
              v14 = v31;
              while ( 1 )
              {
                if ( v14 )
                {
                  *v14 = *(_DWORD *)((char *)v14 + (_DWORD)v13);
                  v14[1] = *(_DWORD *)((char *)v14 + v7 - v31 + 4);
                }
                v14 += 2;
                if ( !--v33 )
                  break;
                v13 = (char *)(v7 - v31);
              }
              v11 = v30;
            }
            if ( v7 )
            {
              ++gNumAlignedFree;
              sAlignedFreeFunc(v7);
              v11 = v30;
              v9 = lba;
            }
            v7 = v31;
            v8 = v39;
            v40 = v11;
          }
          if ( v8 < v11 )
          {
            v34 = v11 - v39;
            v15 = &v7[8 * v8];
            do
            {
              if ( v15 )
              {
                *(_DWORD *)v15 = v35;
                *((_DWORD *)v15 + 1) = lba;
              }
              v15 += 8;
              --v34;
            }
            while ( v34 );
            v11 = v30;
          }
        }
        v39 = v11;
        v32 = v11 - 4;
      }
      if ( v10 == v9 )
      {
        if ( v10->childs[1] )
        {
          v16 = v10->childs[0];
          *(_DWORD *)&v7[8 * v4] = v16;
          *(_DWORD *)&v7[8 * v4 + 4] = v16;
          v17 = v10->childs[1];
          v18 = v4 + 1;
          *(_DWORD *)&v7[8 * v18] = v17;
          *(_DWORD *)&v7[8 * v18 + 4] = v17;
          v19 = v10->childs[0];
          v20 = v10->childs[1];
          ++v18;
          *(_DWORD *)&v7[8 * v18] = v19;
          *(_DWORD *)&v7[8 * v18 + 4] = v20;
          v4 = v18 + 1;
        }
      }
      else
      {
        v38 = _mm_or_ps(
                _mm_cmplt_ps(v10->volume.mx.mVec128, v9->volume.mi.mVec128),
                _mm_cmplt_ps(v9->volume.mx.mVec128, v10->volume.mi.mVec128));
        if ( !(v38.m128_i32[2] | v38.m128_i32[1] | v38.m128_i32[0]) )
        {
          if ( v10->childs[1] )
          {
            v21 = v10->childs[0];
            if ( v9->childs[1] )
            {
              v22 = v9->childs[0];
              *(_DWORD *)&v7[8 * v4] = v21;
              *(_DWORD *)&v7[8 * v4 + 4] = v22;
              v23 = v9->childs[0];
              *(_DWORD *)&v7[8 * v4 + 8] = v10->childs[1];
              *(_DWORD *)&v7[8 * v4 + 12] = v23;
              v24 = v9->childs[1];
              v4 += 2;
              *(_DWORD *)&v7[8 * v4] = v10->childs[0];
              *(_DWORD *)&v7[8 * v4 + 4] = v24;
              v25 = v10->childs[1];
              v9 = v9->childs[1];
            }
            else
            {
              *(_DWORD *)&v7[8 * v4] = v21;
              *(_DWORD *)&v7[8 * v4 + 4] = v9;
              v25 = v10->childs[1];
            }
            v26 = v4 + 1;
            *(_DWORD *)&v7[8 * v26] = v25;
            *(_DWORD *)&v7[8 * v26 + 4] = v9;
            v4 = v26 + 1;
          }
          else if ( v9->childs[1] )
          {
            v27 = v9->childs[0];
            *(_DWORD *)&v7[8 * v4] = v10;
            *(_DWORD *)&v7[8 * v4 + 4] = v27;
            v28 = v9->childs[1];
            v29 = v4 + 1;
            *(_DWORD *)&v7[8 * v29] = v10;
            *(_DWORD *)&v7[8 * v29 + 4] = v28;
            v4 = v29 + 1;
          }
          else
          {
            btSoftColliders::CollideCL_SS::Process(v10, v9, policya);
          }
        }
      }
      if ( !v4 )
        break;
      v8 = v39;
    }
    if ( v7 )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v7);
    }
  }
}
