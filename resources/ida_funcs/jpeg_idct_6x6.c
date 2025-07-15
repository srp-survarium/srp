char *__cdecl jpeg_idct_6x6(int a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // edx
  int v6; // ecx
  __int16 *v7; // esi
  char *v8; // eax
  int v9; // edi
  int v10; // ebp
  int v11; // edi
  int v12; // ebx
  int v13; // ebp
  int v14; // edi
  int v15; // ebp
  int v16; // ebx
  int v17; // edi
  int v18; // ebx
  int v19; // edi
  int v20; // ebp
  int v21; // edi
  int v22; // ebx
  int v23; // ebp
  int v24; // edi
  int v25; // ebp
  int v26; // ebx
  int v27; // edi
  int v28; // ebx
  int v29; // edi
  int v30; // ebp
  int v31; // edi
  int v32; // ebx
  int v33; // ebp
  int v34; // edi
  char *result; // eax
  int v36; // edx
  int v37; // ebx
  int v38; // ebp
  int v39; // edx
  int v40; // edi
  int v41; // edx
  _BYTE *v42; // esi
  int v43; // ebx
  int v44; // edx
  int v45; // edi
  _BYTE *v46; // esi
  int v47; // edx
  int v48; // ebx
  int v49; // ebp
  int v50; // edx
  int v51; // edi
  int v52; // edx
  int v53; // ebx
  int v54; // edx
  int v55; // edi
  int v56; // edx
  int v57; // ebx
  _BYTE *v58; // esi
  int v59; // ebp
  int v60; // edx
  int v61; // edi
  int v62; // edx
  bool v63; // zf
  int v64; // [esp+10h] [ebp-B0h]
  int v65; // [esp+10h] [ebp-B0h]
  int v66; // [esp+10h] [ebp-B0h]
  int v67; // [esp+10h] [ebp-B0h]
  int v68; // [esp+10h] [ebp-B0h]
  int v69; // [esp+10h] [ebp-B0h]
  int v70; // [esp+10h] [ebp-B0h]
  int v71; // [esp+14h] [ebp-ACh]
  int v72; // [esp+14h] [ebp-ACh]
  int v73; // [esp+14h] [ebp-ACh]
  int v74; // [esp+14h] [ebp-ACh]
  int v75; // [esp+18h] [ebp-A8h]
  int v76; // [esp+18h] [ebp-A8h]
  int v77; // [esp+18h] [ebp-A8h]
  int v78; // [esp+18h] [ebp-A8h]
  int v79; // [esp+18h] [ebp-A8h]
  int v80; // [esp+18h] [ebp-A8h]
  int v81; // [esp+1Ch] [ebp-A4h]
  int v82; // [esp+1Ch] [ebp-A4h]
  int v83; // [esp+1Ch] [ebp-A4h]
  int v84; // [esp+1Ch] [ebp-A4h]
  int v85; // [esp+1Ch] [ebp-A4h]
  int v86; // [esp+1Ch] [ebp-A4h]
  int v87; // [esp+20h] [ebp-A0h]
  int v88; // [esp+20h] [ebp-A0h]
  int v89; // [esp+20h] [ebp-A0h]
  _DWORD *v90; // [esp+20h] [ebp-A0h]
  int v91; // [esp+24h] [ebp-9Ch]
  int v92; // [esp+24h] [ebp-9Ch]
  int v93; // [esp+24h] [ebp-9Ch]
  int v94; // [esp+28h] [ebp-98h]
  int v95; // [esp+28h] [ebp-98h]
  int v96; // [esp+28h] [ebp-98h]
  int v97; // [esp+2Ch] [ebp-94h]
  int v98; // [esp+2Ch] [ebp-94h]
  char v99; // [esp+38h] [ebp-88h] BYREF
  char v100; // [esp+48h] [ebp-78h] BYREF

  v5 = *(_DWORD **)(a2 + 84);
  v6 = *(_DWORD *)(a1 + 292) + 128;
  v7 = (__int16 *)(a3 + 32);
  v8 = &v100;
  v97 = 2;
  do
  {
    v9 = ((*v5 * *(v7 - 16)) << 13) + 1024;
    v10 = 5793 * v5[32] * v7[16] + v9;
    v87 = (v9 - 11586 * v5[32] * v7[16]) >> 11;
    v11 = 10033 * v5[16] * *v7;
    v75 = v11 + v10;
    v12 = v5[8] * *(v7 - 8);
    v81 = v10 - v11;
    v91 = v5[40] * v7[24];
    v13 = 2998 * (v12 + v91);
    v94 = v5[24] * v7[8];
    v71 = v13 + ((v12 + v94) << 13);
    v14 = v13 + ((v91 - v94) << 13);
    v64 = 4 * (v12 - v91 - v94);
    *((_DWORD *)v8 + 24) = (v75 - v71) >> 11;
    *((_DWORD *)v8 - 6) = (v75 + v71) >> 11;
    *(_DWORD *)v8 = v87 + v64;
    *((_DWORD *)v8 + 18) = v87 - v64;
    v15 = v81 + v14;
    v16 = v81 - v14;
    v17 = v5[1] * *(v7 - 15);
    *((_DWORD *)v8 + 12) = v16 >> 11;
    v18 = 5793 * v5[33] * v7[17];
    v19 = (v17 << 13) + 1024;
    *((_DWORD *)v8 + 6) = v15 >> 11;
    v20 = v18 + v19;
    v88 = (v19 - 2 * v18) >> 11;
    v21 = 10033 * v5[17] * v7[1];
    v76 = v21 + v20;
    v22 = v5[9] * *(v7 - 7);
    v82 = v20 - v21;
    v92 = v5[41] * v7[25];
    v95 = v5[25] * v7[9];
    v23 = 2998 * (v22 + v92);
    v72 = v23 + ((v22 + v95) << 13);
    v24 = v23 + ((v92 - v95) << 13);
    v65 = 4 * (v22 - v92 - v95);
    *((_DWORD *)v8 + 25) = (v76 - v72) >> 11;
    *((_DWORD *)v8 - 5) = (v76 + v72) >> 11;
    *((_DWORD *)v8 + 1) = v88 + v65;
    *((_DWORD *)v8 + 19) = v88 - v65;
    v25 = v82 + v24;
    v26 = v82 - v24;
    v27 = v5[2] * *(v7 - 14);
    *((_DWORD *)v8 + 13) = v26 >> 11;
    v28 = 5793 * v5[34] * v7[18];
    v29 = (v27 << 13) + 1024;
    *((_DWORD *)v8 + 7) = v25 >> 11;
    v30 = v28 + v29;
    v89 = (v29 - 2 * v28) >> 11;
    v31 = 10033 * v5[18] * v7[2];
    v83 = v30 - v31;
    v77 = v31 + v30;
    v32 = v5[10] * *(v7 - 6);
    v93 = v5[42] * v7[26];
    v33 = 2998 * (v32 + v93);
    v96 = v5[26] * v7[10];
    v73 = v33 + ((v32 + v96) << 13);
    v66 = 4 * (v32 - v93 - v96);
    v34 = v33 + ((v93 - v96) << 13);
    *((_DWORD *)v8 + 26) = (v77 - v73) >> 11;
    *((_DWORD *)v8 - 4) = (v77 + v73) >> 11;
    *((_DWORD *)v8 + 2) = v89 + v66;
    *((_DWORD *)v8 + 20) = v89 - v66;
    *((_DWORD *)v8 + 8) = (v83 + v34) >> 11;
    *((_DWORD *)v8 + 14) = (v83 - v34) >> 11;
    v7 += 3;
    v5 += 3;
    v8 += 12;
    --v97;
  }
  while ( v97 );
  result = &v99;
  v90 = (_DWORD *)(a4 + 8);
  v98 = 2;
  do
  {
    v36 = (*((_DWORD *)result - 2) + 16) << 13;
    v37 = 5793 * *((_DWORD *)result + 2) + v36;
    v38 = v36 - 11586 * *((_DWORD *)result + 2);
    v39 = 10033 * *(_DWORD *)result;
    v78 = v37 + v39;
    v40 = *((_DWORD *)result - 1);
    v84 = v37 - v39;
    v41 = 2998 * (v40 + *((_DWORD *)result + 3));
    v42 = (_BYTE *)(a5 + *(v90 - 2));
    v43 = v41 + ((v40 + *((_DWORD *)result + 1)) << 13);
    v44 = v41 + ((*((_DWORD *)result + 3) - *((_DWORD *)result + 1)) << 13);
    v67 = (v40 - *((_DWORD *)result + 3) - *((_DWORD *)result + 1)) << 13;
    *v42 = *(_BYTE *)((((v78 + v43) >> 18) & 0x3FF) + v6);
    v42[5] = *(_BYTE *)((((v78 - v43) >> 18) & 0x3FF) + v6);
    v42[1] = *(_BYTE *)((((v67 + v38) >> 18) & 0x3FF) + v6);
    v42[4] = *(_BYTE *)(v6 + (((v38 - v67) >> 18) & 0x3FF));
    v42[2] = *(_BYTE *)((((v84 + v44) >> 18) & 0x3FF) + v6);
    v45 = *((_DWORD *)result + 8);
    v42[3] = *(_BYTE *)((((v84 - v44) >> 18) & 0x3FF) + v6);
    v45 *= 5793;
    v46 = (_BYTE *)(a5 + *(v90 - 1));
    v47 = (*((_DWORD *)result + 4) + 16) << 13;
    v48 = v45 + v47;
    v49 = v47 - 2 * v45;
    v50 = 10033 * *((_DWORD *)result + 6);
    v79 = v48 + v50;
    v51 = *((_DWORD *)result + 5);
    v85 = v48 - v50;
    v52 = 2998 * (v51 + *((_DWORD *)result + 9));
    v53 = v52 + ((v51 + *((_DWORD *)result + 7)) << 13);
    v54 = v52 + ((*((_DWORD *)result + 9) - *((_DWORD *)result + 7)) << 13);
    v68 = (v51 - *((_DWORD *)result + 9) - *((_DWORD *)result + 7)) << 13;
    *v46 = *(_BYTE *)((((v79 + v53) >> 18) & 0x3FF) + v6);
    v46[5] = *(_BYTE *)((((v79 - v53) >> 18) & 0x3FF) + v6);
    v46[1] = *(_BYTE *)((((v68 + v49) >> 18) & 0x3FF) + v6);
    v46[4] = *(_BYTE *)(v6 + (((v49 - v68) >> 18) & 0x3FF));
    v46[2] = *(_BYTE *)((((v85 + v54) >> 18) & 0x3FF) + v6);
    v55 = *((_DWORD *)result + 14);
    v46[3] = *(_BYTE *)((((v85 - v54) >> 18) & 0x3FF) + v6);
    v55 *= 5793;
    v56 = (*((_DWORD *)result + 10) + 16) << 13;
    v57 = v55 + v56;
    v58 = (_BYTE *)(a5 + *v90);
    v59 = v56 - 2 * v55;
    v60 = 10033 * *((_DWORD *)result + 12);
    v80 = v57 + v60;
    v61 = *((_DWORD *)result + 11);
    v86 = v57 - v60;
    v69 = 2998 * (v61 + *((_DWORD *)result + 15));
    v74 = v69 + ((v61 + *((_DWORD *)result + 13)) << 13);
    v62 = v69 + ((*((_DWORD *)result + 15) - *((_DWORD *)result + 13)) << 13);
    v70 = (v61 - *((_DWORD *)result + 15) - *((_DWORD *)result + 13)) << 13;
    *v58 = *(_BYTE *)((((v80 + v74) >> 18) & 0x3FF) + v6);
    v58[5] = *(_BYTE *)((((v80 - v74) >> 18) & 0x3FF) + v6);
    v90 += 3;
    v58[1] = *(_BYTE *)((((v70 + v59) >> 18) & 0x3FF) + v6);
    v58[4] = *(_BYTE *)(v6 + (((v59 - v70) >> 18) & 0x3FF));
    v58[2] = *(_BYTE *)((((v86 + v62) >> 18) & 0x3FF) + v6);
    result += 72;
    v63 = v98-- == 1;
    v58[3] = *(_BYTE *)((((v86 - v62) >> 18) & 0x3FF) + v6);
  }
  while ( !v63 );
  return result;
}
