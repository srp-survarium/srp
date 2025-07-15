_BYTE *__cdecl jpeg_idct_ifast(int a1, int a2, __int16 *a3, int a4, int a5)
{
  _DWORD *v5; // edx
  int v7; // ebp
  int *v8; // ecx
  int v9; // eax
  int v10; // edi
  int v11; // ebp
  int v12; // eax
  int v13; // ebx
  int v14; // edi
  int v15; // edi
  int v16; // ebx
  int v17; // eax
  int v18; // ebp
  int v19; // edi
  int v20; // eax
  int v21; // ebx
  int v22; // ebp
  int v23; // edi
  int v24; // eax
  int v25; // esi
  int *v26; // edx
  _BYTE *result; // eax
  char v28; // cl
  int v29; // edi
  int v30; // esi
  int v31; // ebx
  int v32; // ecx
  int v33; // edi
  int v34; // ecx
  int v35; // esi
  int v36; // edi
  int v37; // esi
  int v38; // ebx
  int v39; // edi
  int v40; // ecx
  int v41; // edi
  int v42; // ebx
  int v43; // edi
  int v44; // [esp+Ch] [ebp-124h]
  int v45; // [esp+Ch] [ebp-124h]
  int v46; // [esp+Ch] [ebp-124h]
  int v47; // [esp+Ch] [ebp-124h]
  int v48; // [esp+10h] [ebp-120h]
  int v49; // [esp+10h] [ebp-120h]
  int v50; // [esp+14h] [ebp-11Ch]
  int v51; // [esp+14h] [ebp-11Ch]
  int v52; // [esp+14h] [ebp-11Ch]
  int i; // [esp+18h] [ebp-118h]
  int v54; // [esp+18h] [ebp-118h]
  int v55; // [esp+1Ch] [ebp-114h]
  int v56; // [esp+1Ch] [ebp-114h]
  int v57; // [esp+20h] [ebp-110h]
  int v58; // [esp+20h] [ebp-110h]
  int v59; // [esp+24h] [ebp-10Ch]
  int v60; // [esp+24h] [ebp-10Ch]
  int v61; // [esp+28h] [ebp-108h]
  int v62; // [esp+28h] [ebp-108h]
  int v63; // [esp+2Ch] [ebp-104h]
  int v64; // [esp+2Ch] [ebp-104h]
  _BYTE v65[256]; // [esp+30h] [ebp-100h] BYREF

  v5 = *(_DWORD **)(a2 + 84);
  v7 = *(_DWORD *)(a1 + 292) + 128;
  v55 = v7;
  v8 = (int *)v65;
  for ( i = 8; i > 0; --i )
  {
    if ( a3[8] || a3[16] || a3[24] || a3[32] || a3[40] || a3[48] || a3[56] )
    {
      v10 = *v5 * *a3;
      v11 = v5[32] * a3[32];
      v12 = v5[16] * a3[16];
      v50 = v5[48] * a3[48];
      v13 = v10 + v11;
      v14 = v10 - v11;
      v44 = ((362 * (v12 - v50)) >> 8) - (v12 + v50);
      v59 = v13 + v12 + v50;
      v51 = v13 - (v12 + v50);
      v61 = v44 + v14;
      v63 = v14 - v44;
      v15 = v5[40] * a3[40];
      v16 = v5[8] * a3[8];
      v17 = v5[24] * a3[24];
      v48 = v5[56] * a3[56];
      v18 = v15 + v17;
      v19 = v15 - v17;
      v20 = v16 + v48;
      v21 = v16 - v48;
      v57 = v18;
      v49 = v20 + v18;
      v22 = (473 * (v21 + v19)) >> 8;
      v23 = v22 + ((-669 * v19) >> 8) - v49;
      v24 = ((362 * (v20 - v57)) >> 8) - v23;
      v45 = v24 + ((277 * v21) >> 8) - v22;
      *v8 = v59 + v49;
      v8[56] = v59 - v49;
      v8[8] = v23 + v61;
      v8[40] = v63 - v24;
      v8[48] = v61 - v23;
      v8[16] = v24 + v63;
      v7 = v55;
      v8[32] = v45 + v51;
      v9 = v51 - v45;
    }
    else
    {
      v9 = *v5 * *a3;
      *v8 = v9;
      v8[8] = v9;
      v8[16] = v9;
      v8[32] = v9;
      v8[40] = v9;
      v8[48] = v9;
      v8[56] = v9;
    }
    v8[24] = v9;
    ++a3;
    ++v5;
    ++v8;
  }
  v25 = 0;
  v26 = (int *)v65;
  v54 = 0;
  do
  {
    result = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * v25));
    if ( v26[1] || v26[2] || v26[3] || v26[4] || v26[5] || v26[6] || v26[7] )
    {
      v29 = v26[4];
      v30 = *v26 + v29;
      v31 = *v26 - v29;
      v32 = v26[2];
      v33 = v32 + v26[6];
      v46 = ((362 * (v32 - v26[6])) >> 8) - v33;
      v60 = v33 + v30;
      v52 = v30 - v33;
      v34 = v26[3];
      v62 = v46 + v31;
      v35 = v26[5];
      v36 = v35 + v34;
      v37 = v35 - v34;
      v64 = v31 - v46;
      v38 = v26[7];
      v58 = v36;
      v39 = v26[1];
      v40 = v38 + v39;
      v41 = v39 - v38;
      v47 = (473 * (v41 + v37)) >> 8;
      v42 = v47 + ((-669 * v37) >> 8) - (v40 + v58);
      v56 = ((362 * (v40 - v58)) >> 8) - v42;
      v43 = v56 + ((277 * v41) >> 8) - v47;
      *result = *(_BYTE *)((((v60 + v40 + v58) >> 5) & 0x3FF) + v7);
      result[7] = *(_BYTE *)((((v60 - (v40 + v58)) >> 5) & 0x3FF) + v7);
      result[1] = *(_BYTE *)((((v42 + v62) >> 5) & 0x3FF) + v7);
      result[6] = *(_BYTE *)((((v62 - v42) >> 5) & 0x3FF) + v7);
      result[2] = *(_BYTE *)((((v56 + v64) >> 5) & 0x3FF) + v7);
      result[5] = *(_BYTE *)((((v64 - v56) >> 5) & 0x3FF) + v7);
      result[4] = *(_BYTE *)((((v43 + v52) >> 5) & 0x3FF) + v7);
      v28 = *(_BYTE *)((((v52 - v43) >> 5) & 0x3FF) + v7);
      v25 = v54;
    }
    else
    {
      v28 = *(_BYTE *)(((*v26 >> 5) & 0x3FF) + v7);
      *result = v28;
      result[1] = v28;
      result[2] = v28;
      result[4] = v28;
      result[5] = v28;
      result[6] = v28;
      result[7] = v28;
    }
    ++v25;
    v26 += 8;
    result[3] = v28;
    v54 = v25;
  }
  while ( v25 < 8 );
  return result;
}
