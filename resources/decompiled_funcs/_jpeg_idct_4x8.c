char *__cdecl jpeg_idct_4x8(int a1, int a2, __int16 *a3, int a4, int a5)
{
  _DWORD *v5; // ebx
  __int16 *v6; // edi
  int v7; // ecx
  int *v8; // eax
  int v9; // edx
  int v10; // edx
  int v11; // esi
  int v12; // ebp
  int v13; // esi
  int v14; // edx
  int v15; // ebp
  int v16; // edx
  int v17; // esi
  int v18; // edx
  int v19; // edi
  int v20; // ebp
  int v21; // edx
  int v22; // ebx
  int v23; // edi
  int v24; // esi
  int v25; // ebp
  char *result; // eax
  int v27; // ebx
  int v28; // edx
  int v29; // esi
  int v30; // ebp
  int v31; // edx
  int v32; // edx
  _BYTE *v33; // edi
  int v34; // ebx
  int v35; // edx
  int v36; // esi
  int v37; // edx
  int v38; // ebx
  int v39; // ebp
  int v40; // edx
  _BYTE *v41; // edi
  int v42; // edx
  int v43; // ebx
  int v44; // edx
  int v45; // esi
  int v46; // edx
  int v47; // ebx
  int v48; // ebp
  int v49; // edx
  int v50; // edx
  _BYTE *v51; // edi
  int v52; // ebx
  int v53; // edx
  int v54; // esi
  int v55; // edx
  int v56; // ebx
  int v57; // ebp
  int v58; // edx
  _BYTE *v59; // edi
  int v60; // edx
  bool v61; // zf
  int v62; // [esp+10h] [ebp-ACh]
  int v63; // [esp+10h] [ebp-ACh]
  int v64; // [esp+10h] [ebp-ACh]
  int v65; // [esp+10h] [ebp-ACh]
  int v66; // [esp+10h] [ebp-ACh]
  int v67; // [esp+10h] [ebp-ACh]
  int v68; // [esp+10h] [ebp-ACh]
  int v69; // [esp+14h] [ebp-A8h]
  _DWORD *v70; // [esp+14h] [ebp-A8h]
  int v71; // [esp+18h] [ebp-A4h]
  int v72; // [esp+18h] [ebp-A4h]
  int v73; // [esp+18h] [ebp-A4h]
  int v74; // [esp+18h] [ebp-A4h]
  int v75; // [esp+18h] [ebp-A4h]
  int i; // [esp+1Ch] [ebp-A0h]
  int v77; // [esp+1Ch] [ebp-A0h]
  __int16 v78; // [esp+20h] [ebp-9Ch]
  int v79; // [esp+20h] [ebp-9Ch]
  __int16 *v80; // [esp+24h] [ebp-98h]
  _DWORD *v81; // [esp+28h] [ebp-94h]
  int v82; // [esp+2Ch] [ebp-90h]
  int v83; // [esp+30h] [ebp-8Ch]
  int v84; // [esp+34h] [ebp-88h]
  int v85; // [esp+38h] [ebp-84h]
  char v86; // [esp+3Ch] [ebp-80h] BYREF
  char v87; // [esp+40h] [ebp-7Ch] BYREF

  v5 = *(_DWORD **)(a2 + 84);
  v6 = a3;
  v7 = *(_DWORD *)(a1 + 292) + 128;
  v80 = a3;
  v81 = v5;
  v8 = (int *)&v86;
  for ( i = 4; i > 0; --i )
  {
    v78 = v6[8];
    if ( v78 || v6[16] || v6[24] || v6[32] || v6[40] || v6[48] || v6[56] )
    {
      v10 = v5[16] * v6[16];
      v11 = v5[48] * v6[48];
      v12 = 4433 * (v11 + v10);
      v69 = v12 + 6270 * v10;
      v62 = v12 - 15137 * v11;
      v13 = (v5[32] * v6[32]) << 13;
      v14 = ((*v5 * *v6) << 13) + 1024;
      v15 = v13 + v14;
      v16 = v14 - v13;
      v85 = v15 + v69;
      v84 = v15 - v69;
      v82 = v16 + v62;
      v17 = v5[40] * v6[40];
      v83 = v16 - v62;
      v18 = v5[56] * v6[56];
      v19 = v5[24] * v6[24];
      v63 = v5[8] * v78;
      v79 = 9633 * (v18 + v19 + v17 + v63) - 16069 * (v18 + v19);
      v71 = 9633 * (v18 + v19 + v17 + v63) - 3196 * (v17 + v63);
      v20 = -7373 * (v18 + v63);
      v21 = v79 + v20 + 2446 * v18;
      v64 = v71 + v20 + 12299 * v63;
      v22 = -20995 * (v17 + v19);
      v23 = v79 + v22 + 25172 * v19;
      v24 = v71 + v22 + 16819 * v17;
      *v8 = (v85 + v64) >> 11;
      v8[28] = (v85 - v64) >> 11;
      v25 = v82 + v23;
      v8[24] = (v82 - v23) >> 11;
      v8[20] = (v83 - v24) >> 11;
      v8[8] = (v83 + v24) >> 11;
      v5 = v81;
      v8[12] = (v84 + v21) >> 11;
      v6 = v80;
      v8[4] = v25 >> 11;
      v8[16] = (v84 - v21) >> 11;
    }
    else
    {
      v9 = 4 * *v5 * *v6;
      *v8 = v9;
      v8[4] = v9;
      v8[8] = v9;
      v8[12] = v9;
      v8[16] = v9;
      v8[20] = v9;
      v8[24] = v9;
      v8[28] = v9;
    }
    ++v6;
    ++v5;
    ++v8;
    v81 = v5;
    v80 = v6;
  }
  result = &v87;
  v70 = (_DWORD *)(a4 + 8);
  v77 = 2;
  do
  {
    v27 = *((_DWORD *)result + 1);
    v28 = *((_DWORD *)result - 1) + 16;
    v29 = v28 + v27;
    v30 = (v28 - v27) << 13;
    v72 = *((_DWORD *)result + 2);
    v31 = 4433 * (*(_DWORD *)result + v72);
    v65 = v31 + 6270 * *(_DWORD *)result;
    v32 = v31 - 15137 * v72;
    v33 = (_BYTE *)(a5 + *(v70 - 2));
    v29 <<= 13;
    *v33 = *(_BYTE *)((((v29 + v65) >> 18) & 0x3FF) + v7);
    v33[3] = *(_BYTE *)((((v29 - v65) >> 18) & 0x3FF) + v7);
    v33[1] = *(_BYTE *)((((v32 + v30) >> 18) & 0x3FF) + v7);
    v34 = *((_DWORD *)result + 5);
    v33[2] = *(_BYTE *)(v7 + (((v30 - v32) >> 18) & 0x3FF));
    v35 = *((_DWORD *)result + 3) + 16;
    v36 = v35 + v34;
    v37 = v35 - v34;
    v38 = *((_DWORD *)result + 4);
    v39 = v37 << 13;
    v73 = *((_DWORD *)result + 6);
    v40 = 4433 * (v38 + v73);
    v41 = (_BYTE *)(a5 + *(v70 - 1));
    v66 = v40 + 6270 * v38;
    v42 = v40 - 15137 * v73;
    v36 <<= 13;
    *v41 = *(_BYTE *)((((v36 + v66) >> 18) & 0x3FF) + v7);
    v41[3] = *(_BYTE *)((((v36 - v66) >> 18) & 0x3FF) + v7);
    v41[1] = *(_BYTE *)((((v42 + v39) >> 18) & 0x3FF) + v7);
    v43 = *((_DWORD *)result + 9);
    v41[2] = *(_BYTE *)(v7 + (((v39 - v42) >> 18) & 0x3FF));
    v44 = *((_DWORD *)result + 7) + 16;
    v45 = v44 + v43;
    v46 = v44 - v43;
    v47 = *((_DWORD *)result + 8);
    v48 = v46 << 13;
    v74 = *((_DWORD *)result + 10);
    v49 = 4433 * (v47 + v74);
    v67 = v49 + 6270 * v47;
    v50 = v49 - 15137 * v74;
    v51 = (_BYTE *)(a5 + *v70);
    v45 <<= 13;
    *v51 = *(_BYTE *)((((v45 + v67) >> 18) & 0x3FF) + v7);
    v51[3] = *(_BYTE *)((((v45 - v67) >> 18) & 0x3FF) + v7);
    v51[1] = *(_BYTE *)((((v50 + v48) >> 18) & 0x3FF) + v7);
    v52 = *((_DWORD *)result + 13);
    v51[2] = *(_BYTE *)(v7 + (((v48 - v50) >> 18) & 0x3FF));
    v53 = *((_DWORD *)result + 11) + 16;
    v54 = v53 + v52;
    v55 = v53 - v52;
    v56 = *((_DWORD *)result + 12);
    v57 = v55 << 13;
    v75 = *((_DWORD *)result + 14);
    v58 = 4433 * (v56 + v75);
    v59 = (_BYTE *)(a5 + v70[1]);
    v68 = v58 + 6270 * v56;
    v60 = v58 - 15137 * v75;
    v54 <<= 13;
    *v59 = *(_BYTE *)((((v54 + v68) >> 18) & 0x3FF) + v7);
    v59[3] = *(_BYTE *)((((v54 - v68) >> 18) & 0x3FF) + v7);
    v70 += 4;
    v59[1] = *(_BYTE *)((((v60 + v57) >> 18) & 0x3FF) + v7);
    result += 64;
    v61 = v77-- == 1;
    v59[2] = *(_BYTE *)(v7 + (((v57 - v60) >> 18) & 0x3FF));
  }
  while ( !v61 );
  return result;
}
