int __cdecl jpeg_idct_9x9(int a1, int a2, int a3, int a4, int a5)
{
  int *v5; // ecx
  __int16 *v6; // edx
  _DWORD *v7; // esi
  int v8; // edi
  int v9; // ebx
  int v10; // eax
  int v11; // edi
  int v12; // eax
  int v13; // ebx
  int v14; // ebx
  int v15; // eax
  int result; // eax
  char *v17; // edi
  int v18; // esi
  int v19; // ecx
  int v20; // edx
  int v21; // ebx
  int v22; // ebp
  int v23; // ecx
  int v24; // esi
  _BYTE *v25; // eax
  int v26; // edx
  int v27; // ebx
  int v28; // ebx
  int v29; // [esp+10h] [ebp-154h]
  int v30; // [esp+10h] [ebp-154h]
  int v31; // [esp+10h] [ebp-154h]
  int v32; // [esp+10h] [ebp-154h]
  int v33; // [esp+10h] [ebp-154h]
  int v34; // [esp+10h] [ebp-154h]
  int v35; // [esp+14h] [ebp-150h]
  int v36; // [esp+18h] [ebp-14Ch]
  int v37; // [esp+18h] [ebp-14Ch]
  int v38; // [esp+1Ch] [ebp-148h]
  int v39; // [esp+1Ch] [ebp-148h]
  int v40; // [esp+1Ch] [ebp-148h]
  int v41; // [esp+20h] [ebp-144h]
  int v42; // [esp+24h] [ebp-140h]
  int v43; // [esp+24h] [ebp-140h]
  int v44; // [esp+28h] [ebp-13Ch]
  int v45; // [esp+28h] [ebp-13Ch]
  int v46; // [esp+2Ch] [ebp-138h]
  int v47; // [esp+30h] [ebp-134h]
  int v48; // [esp+30h] [ebp-134h]
  int v49; // [esp+34h] [ebp-130h]
  int v50; // [esp+34h] [ebp-130h]
  int v51; // [esp+38h] [ebp-12Ch]
  int v52; // [esp+3Ch] [ebp-128h]
  int v53; // [esp+40h] [ebp-124h]
  char v54; // [esp+54h] [ebp-110h] BYREF
  char v55; // [esp+64h] [ebp-100h] BYREF

  v53 = *(_DWORD *)(a1 + 292) + 128;
  v5 = (int *)&v55;
  v6 = (__int16 *)(a3 + 64);
  v7 = (_DWORD *)(*(_DWORD *)(a2 + 84) + 128);
  v42 = 8;
  do
  {
    v8 = *(v7 - 16) * *(v6 - 16);
    v9 = *v7 * *v6;
    v10 = ((*(v7 - 32) * *(v6 - 32)) << 13) + 1024;
    v36 = v10 + 5793 * v7[16] * v6[16];
    v44 = 5793 * (v8 - v9) + v10 - 11586 * v7[16] * v6[16];
    v38 = 10887 * (v9 + v8);
    v49 = v10 - 11586 * v7[16] * v6[16] - 11586 * (v8 - v9);
    v29 = 8875 * v8;
    v11 = v38 + v36 - 2012 * v9;
    v52 = v36 + v29 - v38;
    v47 = 2012 * v9 + v36 - v29;
    v12 = *(v7 - 24) * *(v6 - 24);
    v51 = v7[8] * v6[8];
    v46 = v7[24] * v6[24];
    v41 = -10033 * *(v7 - 8) * *(v6 - 8);
    v39 = 3962 * (v12 + v46) + 7447 * (v12 + v51) - v41;
    v13 = 11409 * (v51 - v46);
    v30 = v41 - v13 + 7447 * (v12 + v51);
    v14 = v13 - 10033 * *(v7 - 8) * *(v6 - 8) + 3962 * (v12 + v46);
    v15 = 10033 * (v12 - v46 - v51);
    v5[56] = (v11 - v39) >> 11;
    *(v5 - 8) = (v11 + v39) >> 11;
    v5[48] = (v44 - v15) >> 11;
    *v5 = (v44 + v15) >> 11;
    v5[40] = (v52 - v30) >> 11;
    v5[32] = (v47 - v14) >> 11;
    v5[8] = (v52 + v30) >> 11;
    v5[16] = (v47 + v14) >> 11;
    v5[24] = v49 >> 11;
    ++v6;
    ++v7;
    ++v5;
    --v42;
  }
  while ( v42 );
  result = 0;
  v43 = 0;
  v17 = &v54;
  do
  {
    v18 = *((_DWORD *)v17 - 2);
    v19 = (*((_DWORD *)v17 - 4) + 16) << 13;
    v20 = v19 + 5793 * *((_DWORD *)v17 + 2);
    v31 = v19 - 11586 * *((_DWORD *)v17 + 2);
    v45 = 5793 * (v18 - *(_DWORD *)v17) + v31;
    v21 = 2012 * *(_DWORD *)v17;
    v22 = 10887 * (*(_DWORD *)v17 + v18);
    v50 = v31 - 11586 * (v18 - *(_DWORD *)v17);
    v23 = v22 + v20 - v21;
    v32 = 8875 * v18;
    v24 = v20 + 8875 * v18 - v22;
    v25 = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * result));
    v48 = v21 + v20 - v32;
    v26 = *((_DWORD *)v17 - 3);
    v33 = 7447 * (v26 + *((_DWORD *)v17 + 1));
    v35 = 3962 * (v26 + *((_DWORD *)v17 + 3));
    v40 = v35 + v33 - -10033 * *((_DWORD *)v17 - 1);
    v27 = 11409 * (*((_DWORD *)v17 + 1) - *((_DWORD *)v17 + 3));
    v34 = -10033 * *((_DWORD *)v17 - 1) - v27 + v33;
    v37 = 10033 * (v26 - *((_DWORD *)v17 + 3) - *((_DWORD *)v17 + 1));
    v28 = v27 - 10033 * *((_DWORD *)v17 - 1) + v35;
    *v25 = *(_BYTE *)((((v23 + v40) >> 18) & 0x3FF) + v53);
    v25[8] = *(_BYTE *)((((v23 - v40) >> 18) & 0x3FF) + v53);
    v25[1] = *(_BYTE *)((((v45 + v37) >> 18) & 0x3FF) + v53);
    v25[7] = *(_BYTE *)((((v45 - v37) >> 18) & 0x3FF) + v53);
    v25[2] = *(_BYTE *)((((v24 + v34) >> 18) & 0x3FF) + v53);
    v25[6] = *(_BYTE *)((((v24 - v34) >> 18) & 0x3FF) + v53);
    v25[3] = *(_BYTE *)((((v48 + v28) >> 18) & 0x3FF) + v53);
    v25[5] = *(_BYTE *)((((v48 - v28) >> 18) & 0x3FF) + v53);
    v25[4] = *(_BYTE *)(((v50 >> 18) & 0x3FF) + v53);
    result = v43 + 1;
    v17 += 32;
    ++v43;
  }
  while ( v43 < 9 );
  return result;
}
