void __userpurge btQuantizedBvh::updateSubtreeHeaders(
        btQuantizedBvh *this@<ecx>,
        int a2@<esi>,
        int leftChildNodexIndex,
        int rightChildNodexIndex)
{
  int v4; // ecx
  int v5; // eax
  _WORD *v6; // edi
  int v7; // edx
  int v8; // ecx
  int v9; // ecx
  int v10; // ebx
  int v11; // eax
  _QWORD *v12; // eax
  _QWORD *v13; // ecx
  int v14; // edx
  int v15; // ebx
  int v16; // eax
  __int64 v17; // xmm0_8
  _QWORD *v18; // eax
  void *v19; // eax
  int v20; // eax
  int v21; // ebx
  _QWORD *v22; // eax
  int v23; // eax
  int v24; // edi
  int v25; // eax
  _QWORD *v26; // eax
  _QWORD *v27; // ebx
  int v28; // edx
  _QWORD *v29; // ecx
  int v30; // edi
  int v31; // eax
  __int64 v32; // xmm0_8
  _QWORD *v33; // eax
  void *v34; // eax
  int v35; // eax
  int v36; // edi
  _QWORD *v37; // eax
  int v38; // eax
  int v39; // [esp+D0h] [ebp-3Ch]
  _QWORD *v40; // [esp+D4h] [ebp-38h]
  int v41; // [esp+D8h] [ebp-34h]
  int v42; // [esp+DCh] [ebp-30h]
  int v43; // [esp+DCh] [ebp-30h]
  int v44; // [esp+E0h] [ebp-2Ch]
  int v45; // [esp+E4h] [ebp-28h]
  int v46; // [esp+E8h] [ebp-24h]
  __int64 v47; // [esp+ECh] [ebp-20h]
  __int64 v48; // [esp+F4h] [ebp-18h]
  __int64 v49; // [esp+FCh] [ebp-10h]
  __int64 v50; // [esp+104h] [ebp-8h]

  v4 = *(_DWORD *)(a2 + 148);
  v5 = *(_DWORD *)(16 * leftChildNodexIndex + v4 + 12);
  v6 = (_WORD *)(v4 + 16 * leftChildNodexIndex);
  if ( v5 < 0 )
    v42 = -v5;
  else
    v42 = 1;
  v7 = v4 + 16 * rightChildNodexIndex;
  v8 = *(_DWORD *)(v7 + 12);
  v39 = v7;
  if ( v8 < 0 )
    v44 = -v8;
  else
    v44 = 1;
  v9 = 16 * v44;
  if ( 16 * v42 <= 2048 )
  {
    v10 = *(_DWORD *)(a2 + 164);
    v11 = *(_DWORD *)(a2 + 168);
    v45 = v10;
    if ( v10 == v11 )
    {
      v41 = v10 ? 2 * v10 : 1;
      if ( v11 < v41 )
      {
        if ( v41 )
        {
          ++gNumAlignedAllocs;
          v12 = sAlignedAllocFunc(32 * v41, 16);
          v7 = v39;
          v40 = v12;
        }
        else
        {
          v40 = 0;
        }
        if ( *(int *)(a2 + 164) > 0 )
        {
          v13 = v40;
          v14 = 0;
          v15 = *(_DWORD *)(a2 + 164);
          do
          {
            if ( v13 )
            {
              v16 = *(_DWORD *)(a2 + 172);
              v17 = *(_QWORD *)(v16 + v14);
              v18 = (_QWORD *)(v14 + v16);
              *v13 = v17;
              v13[1] = v18[1];
              v13[2] = v18[2];
              v13[3] = v18[3];
            }
            v14 += 32;
            v13 += 4;
            --v15;
          }
          while ( v15 );
          v10 = v45;
          v7 = v39;
        }
        v19 = *(void **)(a2 + 172);
        if ( v19 )
        {
          if ( *(_BYTE *)(a2 + 176) )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v19);
            v7 = v39;
          }
          *(_DWORD *)(a2 + 172) = 0;
        }
        *(_BYTE *)(a2 + 176) = 1;
        *(_DWORD *)(a2 + 172) = v40;
        *(_DWORD *)(a2 + 168) = v41;
      }
    }
    v20 = *(_DWORD *)(a2 + 172);
    ++*(_DWORD *)(a2 + 164);
    v21 = 32 * v10;
    v22 = (_QWORD *)(v21 + v20);
    if ( v22 )
    {
      *v22 = v47;
      v22[1] = v48;
      v22[2] = v49;
      v22[3] = v50;
    }
    v23 = v21 + *(_DWORD *)(a2 + 172);
    *(_WORD *)v23 = *v6;
    *(_WORD *)(v23 + 2) = v6[1];
    *(_WORD *)(v23 + 4) = v6[2];
    *(_WORD *)(v23 + 6) = v6[3];
    *(_WORD *)(v23 + 8) = v6[4];
    *(_WORD *)(v23 + 10) = v6[5];
    *(_DWORD *)(v23 + 12) = leftChildNodexIndex;
    *(_DWORD *)(v23 + 16) = v42;
    v9 = 16 * v44;
  }
  if ( v9 > 2048 )
  {
    *(_DWORD *)(a2 + 180) = *(_DWORD *)(a2 + 164);
  }
  else
  {
    v24 = *(_DWORD *)(a2 + 164);
    v25 = *(_DWORD *)(a2 + 168);
    v46 = v24;
    if ( v24 == v25 )
    {
      v43 = v24 ? 2 * v24 : 1;
      if ( v25 < v43 )
      {
        if ( v43 )
        {
          ++gNumAlignedAllocs;
          v26 = sAlignedAllocFunc(32 * v43, 16);
          v7 = v39;
          v27 = v26;
        }
        else
        {
          v27 = 0;
        }
        if ( *(int *)(a2 + 164) > 0 )
        {
          v28 = 0;
          v29 = v27;
          v30 = *(_DWORD *)(a2 + 164);
          do
          {
            if ( v29 )
            {
              v31 = *(_DWORD *)(a2 + 172);
              v32 = *(_QWORD *)(v31 + v28);
              v33 = (_QWORD *)(v28 + v31);
              *v29 = v32;
              v29[1] = v33[1];
              v29[2] = v33[2];
              v29[3] = v33[3];
            }
            v28 += 32;
            v29 += 4;
            --v30;
          }
          while ( v30 );
          v7 = v39;
          v24 = v46;
        }
        v34 = *(void **)(a2 + 172);
        if ( v34 )
        {
          if ( *(_BYTE *)(a2 + 176) )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v34);
            v7 = v39;
          }
          *(_DWORD *)(a2 + 172) = 0;
        }
        *(_DWORD *)(a2 + 172) = v27;
        *(_BYTE *)(a2 + 176) = 1;
        *(_DWORD *)(a2 + 168) = v43;
      }
    }
    v35 = *(_DWORD *)(a2 + 172);
    ++*(_DWORD *)(a2 + 164);
    v36 = 32 * v24;
    v37 = (_QWORD *)(v36 + v35);
    if ( v37 )
    {
      *v37 = v47;
      v37[1] = v48;
      v37[2] = v49;
      v37[3] = v50;
    }
    v38 = v36 + *(_DWORD *)(a2 + 172);
    *(_WORD *)v38 = *(_WORD *)v7;
    *(_WORD *)(v38 + 2) = *(_WORD *)(v7 + 2);
    *(_WORD *)(v38 + 4) = *(_WORD *)(v7 + 4);
    *(_WORD *)(v38 + 6) = *(_WORD *)(v7 + 6);
    *(_WORD *)(v38 + 8) = *(_WORD *)(v7 + 8);
    *(_WORD *)(v38 + 10) = *(_WORD *)(v7 + 10);
    *(_DWORD *)(v38 + 12) = rightChildNodexIndex;
    *(_DWORD *)(v38 + 16) = v44;
    *(_DWORD *)(a2 + 180) = *(_DWORD *)(a2 + 164);
  }
}
