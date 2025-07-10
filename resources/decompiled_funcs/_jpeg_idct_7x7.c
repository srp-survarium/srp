int *__cdecl jpeg_idct_7x7(int a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // ecx
  __int16 *v6; // edx
  int v7; // esi
  int v8; // eax
  int v9; // ebx
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  int v13; // ebx
  int v14; // eax
  int v15; // edi
  int v16; // ecx
  int v17; // edx
  int v18; // edi
  int v19; // eax
  int v20; // esi
  int v21; // ebp
  int v22; // ebx
  int v23; // ebp
  int v24; // ebx
  bool v25; // zf
  int v26; // ecx
  int *result; // eax
  int v28; // ebx
  int v29; // ebp
  int v30; // esi
  int v31; // eax
  int v32; // ecx
  int v33; // esi
  int v34; // edi
  int v35; // eax
  int v36; // ecx
  int v37; // edi
  int v38; // esi
  int v39; // edx
  int v40; // ebx
  int v41; // edx
  _BYTE *v42; // ebp
  int v43; // ebx
  bool v44; // cc
  int v45; // [esp+10h] [ebp-ECh]
  int v46; // [esp+10h] [ebp-ECh]
  int v47; // [esp+10h] [ebp-ECh]
  int v48; // [esp+10h] [ebp-ECh]
  int v49; // [esp+14h] [ebp-E8h]
  _BYTE *v50; // [esp+14h] [ebp-E8h]
  int v51; // [esp+18h] [ebp-E4h]
  int v52; // [esp+1Ch] [ebp-E0h]
  int v53; // [esp+1Ch] [ebp-E0h]
  int v54; // [esp+1Ch] [ebp-E0h]
  int v55; // [esp+1Ch] [ebp-E0h]
  int v56; // [esp+1Ch] [ebp-E0h]
  int v57; // [esp+20h] [ebp-DCh]
  int v58; // [esp+20h] [ebp-DCh]
  int v59; // [esp+20h] [ebp-DCh]
  int v60; // [esp+24h] [ebp-D8h]
  int v61; // [esp+24h] [ebp-D8h]
  int v62; // [esp+28h] [ebp-D4h]
  int v63; // [esp+28h] [ebp-D4h]
  _DWORD *v64; // [esp+2Ch] [ebp-D0h]
  int *v65; // [esp+30h] [ebp-CCh]
  int v66; // [esp+34h] [ebp-C8h]
  _BYTE v67[12]; // [esp+48h] [ebp-B4h] BYREF
  char v68; // [esp+54h] [ebp-A8h] BYREF

  v5 = *(_DWORD **)(a2 + 84);
  v66 = *(_DWORD *)(a1 + 292) + 128;
  v6 = (__int16 *)(a3 + 64);
  v64 = v5;
  v49 = a3 + 64;
  v65 = (int *)&v68;
  v62 = 7;
  do
  {
    v7 = v5[32] * *v6;
    v8 = *v5 * *(v6 - 32);
    v9 = v5[16] * *(v6 - 16);
    v10 = v5[48] * v6[16];
    v11 = 7223 * (v7 - v10);
    v57 = v10;
    v60 = v9;
    v12 = 2578 * (v9 - v7);
    v13 = v57 + v9;
    v14 = (v8 << 13) + 1024;
    v52 = v14 + 10438 * v13;
    v15 = v11 + v12 - 15083 * v7;
    v16 = v52 - 637 * v57 + v11;
    v17 = v52 - 20239 * v60 + v12;
    v18 = v14 + v15;
    v19 = 11585 * (v7 - v13) + v14;
    v45 = v64[24] * *(__int16 *)(v49 - 16);
    v20 = v64[40] * *(__int16 *)(v49 + 16);
    v61 = v64[8] * *(__int16 *)(v49 - 48);
    v21 = 7663 * (v61 + v45);
    v22 = 1395 * (v61 - v45);
    v53 = v21 - v22;
    v23 = -11295 * (v20 + v45) + v22 + v21;
    v24 = 5027 * (v20 + v61);
    v46 = v24 + 15326 * v20 - 11295 * (v20 + v45);
    *(v65 - 7) = (v16 + v24 + v53) >> 11;
    v65[35] = (v16 - (v24 + v53)) >> 11;
    v65[28] = (v18 - v23) >> 11;
    v65[21] = (v17 - v46) >> 11;
    *v65 = (v23 + v18) >> 11;
    v65[7] = (v46 + v17) >> 11;
    v65[14] = v19 >> 11;
    v6 = (__int16 *)(v49 + 2);
    v5 = v64 + 1;
    v25 = v62-- == 1;
    v49 += 2;
    ++v64;
    ++v65;
  }
  while ( !v25 );
  v26 = 0;
  result = (int *)v67;
  v63 = 0;
  v50 = v67;
  do
  {
    v28 = *(result - 2);
    v29 = *(_DWORD *)(a4 + 4 * v26);
    v30 = *(result - 4);
    v47 = *result;
    v58 = result[2];
    v31 = 7223 * (*result - v58);
    v32 = 2578 * (v28 - v47);
    v33 = (v30 + 16) << 13;
    v54 = v33 + 10438 * (v28 + v58);
    v34 = v31 + v32 - 15083 * v47;
    v35 = v54 - 637 * v58 + v31;
    v36 = v54 - 20239 * v28 + v32;
    v37 = v33 + v34;
    v38 = 11585 * (v47 - (v28 + v58)) + v33;
    v39 = *((_DWORD *)v50 - 3);
    v59 = *((_DWORD *)v50 + 1);
    v40 = 7663 * (v39 + *((_DWORD *)v50 - 1));
    v41 = 1395 * (v39 - *((_DWORD *)v50 - 1));
    v55 = v40 - v41;
    v51 = -11295 * (v59 + *((_DWORD *)v50 - 1)) + v41 + v40;
    v42 = (_BYTE *)(a5 + v29);
    v43 = 5027 * (*((_DWORD *)v50 - 3) + v59);
    v56 = v43 + v55;
    v48 = v43 + 15326 * v59 - 11295 * (v59 + *((_DWORD *)v50 - 1));
    *v42 = *(_BYTE *)((((v56 + v35) >> 18) & 0x3FF) + v66);
    v42[6] = *(_BYTE *)((((v35 - v56) >> 18) & 0x3FF) + v66);
    v42[1] = *(_BYTE *)((((v51 + v37) >> 18) & 0x3FF) + v66);
    v42[5] = *(_BYTE *)((((v37 - v51) >> 18) & 0x3FF) + v66);
    v42[2] = *(_BYTE *)((((v48 + v36) >> 18) & 0x3FF) + v66);
    v42[4] = *(_BYTE *)((((v36 - v48) >> 18) & 0x3FF) + v66);
    v26 = v63 + 1;
    result = (int *)(v50 + 28);
    v44 = v63 + 1 < 7;
    v42[3] = *(_BYTE *)(((v38 >> 18) & 0x3FF) + v66);
    v50 += 28;
    ++v63;
  }
  while ( v44 );
  return result;
}
