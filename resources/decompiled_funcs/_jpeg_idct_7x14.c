int *__cdecl jpeg_idct_7x14(int a1, int a2, int a3, int a4, int a5)
{
  __int16 *v5; // edi
  _DWORD *v6; // ebx
  int *v7; // eax
  int v8; // edx
  int v9; // ecx
  int v10; // esi
  int v11; // ecx
  int v12; // edx
  int v13; // edx
  int v14; // ecx
  int v15; // edx
  int v16; // ebp
  int v17; // ecx
  int v18; // ebx
  int v19; // ebp
  int v20; // edi
  int v21; // ecx
  bool v22; // zf
  int v23; // ecx
  int *result; // eax
  int v25; // ebx
  int v26; // ebp
  int v27; // esi
  int v28; // eax
  int v29; // ecx
  int v30; // esi
  int v31; // edi
  int v32; // eax
  int v33; // ecx
  int v34; // edi
  int v35; // esi
  int v36; // edx
  int v37; // ebx
  int v38; // edx
  _BYTE *v39; // ebp
  int v40; // ebx
  bool v41; // cc
  int v42; // [esp+10h] [ebp-1D0h]
  int v43; // [esp+10h] [ebp-1D0h]
  _BYTE *v44; // [esp+10h] [ebp-1D0h]
  int v45; // [esp+14h] [ebp-1CCh]
  int v46; // [esp+14h] [ebp-1CCh]
  int v47; // [esp+14h] [ebp-1CCh]
  int v48; // [esp+14h] [ebp-1CCh]
  int v49; // [esp+18h] [ebp-1C8h]
  int v50; // [esp+18h] [ebp-1C8h]
  int v51; // [esp+18h] [ebp-1C8h]
  int v52; // [esp+1Ch] [ebp-1C4h]
  int v53; // [esp+1Ch] [ebp-1C4h]
  int v54; // [esp+1Ch] [ebp-1C4h]
  int v55; // [esp+1Ch] [ebp-1C4h]
  int v56; // [esp+1Ch] [ebp-1C4h]
  int v57; // [esp+20h] [ebp-1C0h]
  int v58; // [esp+20h] [ebp-1C0h]
  int v59; // [esp+20h] [ebp-1C0h]
  int v60; // [esp+24h] [ebp-1BCh]
  int v61; // [esp+24h] [ebp-1BCh]
  int v62; // [esp+24h] [ebp-1BCh]
  int v63; // [esp+24h] [ebp-1BCh]
  int v64; // [esp+28h] [ebp-1B8h]
  int v65; // [esp+28h] [ebp-1B8h]
  int v66; // [esp+2Ch] [ebp-1B4h]
  int v67; // [esp+30h] [ebp-1B0h]
  _DWORD *v68; // [esp+34h] [ebp-1ACh]
  int v69; // [esp+38h] [ebp-1A8h]
  int v70; // [esp+3Ch] [ebp-1A4h]
  int v71; // [esp+40h] [ebp-1A0h]
  int v72; // [esp+44h] [ebp-19Ch]
  int v73; // [esp+48h] [ebp-198h]
  int v74; // [esp+4Ch] [ebp-194h]
  int v75; // [esp+50h] [ebp-190h]
  int v76; // [esp+54h] [ebp-18Ch]
  _BYTE v77[12]; // [esp+68h] [ebp-178h] BYREF
  char v78; // [esp+74h] [ebp-16Ch] BYREF

  v5 = (__int16 *)(a3 + 32);
  v6 = (_DWORD *)(*(_DWORD *)(a2 + 84) + 64);
  v75 = *(_DWORD *)(a1 + 292) + 128;
  v7 = (int *)&v78;
  v69 = a3 + 32;
  v68 = v6;
  v64 = 7;
  do
  {
    v8 = v6[16] * v5[16];
    v9 = ((*(v6 - 16) * *(v5 - 16)) << 13) + 1024;
    v52 = v9 + 10438 * v8;
    v45 = 2578 * v8 + v9;
    v60 = v9 - 7223 * v8;
    v10 = v9 - 11586 * v8;
    v11 = *v6 * *v5;
    v49 = v6[32] * v5[32];
    v12 = 9058 * (v11 + v49);
    v42 = v12 + 2237 * v11;
    v13 = v12 - 14084 * v49;
    v66 = 5027 * v11 - 11295 * v49;
    v72 = v52 + v42;
    v67 = v52 - v42;
    v73 = v13 + v45;
    v74 = v45 - v13;
    v14 = *(v6 - 8) * *(v5 - 8);
    v76 = v60 - v66;
    v15 = v6[8] * v5[8];
    v70 = v66 + v60;
    v57 = v6[24] * v5[24];
    v46 = 10935 * (v15 + v14);
    v43 = v6[40] * v5[40];
    v10 >>= 11;
    v61 = 9810 * (v14 + v57);
    v53 = v46 + v61 + (v43 << 13) - 9232 * v14;
    v50 = 6164 * (v14 + v57);
    v16 = v50 - 8693 * v14;
    v17 = v14 - v15;
    v71 = 3826 * v17 - (v43 << 13) + v16;
    v47 = -8192 * v43 - 1297 * (v57 + v15) - 3474 * v15 + v46;
    v62 = -8192 * v43 - 1297 * (v57 + v15) - 19447 * v57 + v61;
    v18 = 11512 * (v57 - v15);
    v19 = v18 + (v43 << 13) - 13850 * v57 + v50;
    v20 = v18 + 5529 * v15 + 3826 * v17 - (v43 << 13);
    *(v7 - 7) = (v72 + v53) >> 11;
    v7[84] = (v72 - v53) >> 11;
    *v7 = (v73 + v47) >> 11;
    v7[77] = (v73 - v47) >> 11;
    v21 = 4 * (v43 + v17 - v57);
    v7[7] = (v70 + v62) >> 11;
    v7[70] = (v70 - v62) >> 11;
    v7[14] = v21 + v10;
    v7[56] = (v76 - v19) >> 11;
    v7[21] = (v76 + v19) >> 11;
    v7[49] = (v74 - v20) >> 11;
    v7[28] = (v74 + v20) >> 11;
    v7[63] = v10 - v21;
    v7[35] = (v71 + v67) >> 11;
    v7[42] = (v67 - v71) >> 11;
    v5 = (__int16 *)(v69 + 2);
    v6 = v68 + 1;
    ++v7;
    v22 = v64-- == 1;
    v69 += 2;
    ++v68;
  }
  while ( !v22 );
  v23 = 0;
  result = (int *)v77;
  v65 = 0;
  v44 = v77;
  do
  {
    v25 = *(result - 2);
    v26 = *(_DWORD *)(a4 + 4 * v23);
    v27 = *(result - 4);
    v51 = *result;
    v58 = result[2];
    v28 = 7223 * (*result - v58);
    v29 = 2578 * (v25 - v51);
    v30 = (v27 + 16) << 13;
    v54 = v30 + 10438 * (v25 + v58);
    v31 = v28 + v29 - 15083 * v51;
    v32 = v54 - 637 * v58 + v28;
    v33 = v54 - 20239 * v25 + v29;
    v34 = v30 + v31;
    v35 = 11585 * (v51 - (v25 + v58)) + v30;
    v36 = *((_DWORD *)v44 - 3);
    v59 = *((_DWORD *)v44 + 1);
    v37 = 7663 * (v36 + *((_DWORD *)v44 - 1));
    v38 = 1395 * (v36 - *((_DWORD *)v44 - 1));
    v55 = v37 - v38;
    v48 = -11295 * (v59 + *((_DWORD *)v44 - 1)) + v38 + v37;
    v39 = (_BYTE *)(a5 + v26);
    v40 = 5027 * (*((_DWORD *)v44 - 3) + v59);
    v56 = v40 + v55;
    v63 = v40 + 15326 * v59 - 11295 * (v59 + *((_DWORD *)v44 - 1));
    *v39 = *(_BYTE *)((((v32 + v56) >> 18) & 0x3FF) + v75);
    v39[6] = *(_BYTE *)((((v32 - v56) >> 18) & 0x3FF) + v75);
    v39[1] = *(_BYTE *)((((v34 + v48) >> 18) & 0x3FF) + v75);
    v39[5] = *(_BYTE *)((((v34 - v48) >> 18) & 0x3FF) + v75);
    v39[2] = *(_BYTE *)((((v33 + v63) >> 18) & 0x3FF) + v75);
    v39[4] = *(_BYTE *)((((v33 - v63) >> 18) & 0x3FF) + v75);
    v23 = v65 + 1;
    result = (int *)(v44 + 28);
    v41 = v65 + 1 < 14;
    v39[3] = *(_BYTE *)(((v35 >> 18) & 0x3FF) + v75);
    v44 += 28;
    ++v65;
  }
  while ( v41 );
  return result;
}
