char *__cdecl jpeg_idct_6x12(int a1, int a2, int a3, int a4, int a5)
{
  __int16 *v5; // ebp
  int v6; // ecx
  int *v7; // eax
  _DWORD *v8; // ebx
  int v9; // esi
  int v10; // edx
  int v11; // edi
  int v12; // esi
  int v13; // edx
  int v14; // edi
  int v15; // esi
  int v16; // ebp
  int v17; // edx
  int v18; // edi
  int v19; // ebp
  int v20; // esi
  int v21; // ebp
  int v22; // edx
  int v23; // esi
  int v24; // edx
  bool v25; // zf
  char *result; // eax
  int v27; // edx
  int v28; // ebx
  int v29; // ebp
  int v30; // edx
  int v31; // edi
  int v32; // edx
  _BYTE *v33; // esi
  int v34; // ebx
  int v35; // edx
  int v36; // edi
  _BYTE *v37; // esi
  int v38; // edx
  int v39; // ebx
  int v40; // ebp
  int v41; // edx
  int v42; // edi
  int v43; // edx
  int v44; // ebx
  int v45; // edx
  int v46; // edi
  int v47; // edx
  int v48; // ebx
  _BYTE *v49; // esi
  int v50; // ebp
  int v51; // edx
  int v52; // edi
  int v53; // edx
  int v54; // edi
  int v55; // edx
  int v56; // ebx
  int v57; // ebp
  int v58; // edx
  int v59; // edi
  int v60; // ebx
  _BYTE *v61; // esi
  int v62; // edi
  int v63; // edx
  int v64; // edx
  int v65; // [esp+8h] [ebp-160h]
  int v66; // [esp+8h] [ebp-160h]
  int v67; // [esp+8h] [ebp-160h]
  int v68; // [esp+8h] [ebp-160h]
  int v69; // [esp+8h] [ebp-160h]
  int v70; // [esp+8h] [ebp-160h]
  int v71; // [esp+8h] [ebp-160h]
  int v72; // [esp+Ch] [ebp-15Ch]
  int v73; // [esp+Ch] [ebp-15Ch]
  int v74; // [esp+Ch] [ebp-15Ch]
  int v75; // [esp+Ch] [ebp-15Ch]
  int v76; // [esp+10h] [ebp-158h]
  int v77; // [esp+10h] [ebp-158h]
  _DWORD *v78; // [esp+10h] [ebp-158h]
  int v79; // [esp+14h] [ebp-154h]
  int v80; // [esp+14h] [ebp-154h]
  int v81; // [esp+14h] [ebp-154h]
  int v82; // [esp+14h] [ebp-154h]
  int v83; // [esp+14h] [ebp-154h]
  int v84; // [esp+18h] [ebp-150h]
  int v85; // [esp+18h] [ebp-150h]
  int v86; // [esp+18h] [ebp-150h]
  int v87; // [esp+18h] [ebp-150h]
  int v88; // [esp+1Ch] [ebp-14Ch]
  int v89; // [esp+20h] [ebp-148h]
  int v90; // [esp+20h] [ebp-148h]
  int v91; // [esp+24h] [ebp-144h]
  int v92; // [esp+24h] [ebp-144h]
  int v93; // [esp+28h] [ebp-140h]
  int v94; // [esp+30h] [ebp-138h]
  int v95; // [esp+34h] [ebp-134h]
  int v96; // [esp+38h] [ebp-130h]
  int v97; // [esp+3Ch] [ebp-12Ch]
  int v98; // [esp+40h] [ebp-128h]
  int v99; // [esp+44h] [ebp-124h]
  char v100; // [esp+50h] [ebp-118h] BYREF
  char v101; // [esp+60h] [ebp-108h] BYREF

  v5 = (__int16 *)(a3 + 32);
  v6 = *(_DWORD *)(a1 + 292) + 128;
  v7 = (int *)&v101;
  v95 = a3 + 32;
  v8 = (_DWORD *)(*(_DWORD *)(a2 + 84) + 64);
  v91 = 6;
  do
  {
    v9 = 10033 * v8[16] * v5[16];
    v10 = ((*(v8 - 16) * *(v5 - 16)) << 13) + 1024;
    v72 = v9 + v10;
    v65 = v10 - v9;
    v11 = *v8 * *v5;
    v12 = (v8[32] * v5[32]) << 13;
    v76 = (v11 << 13) - v12;
    v99 = v10 + v76;
    v97 = v10 - v76;
    v79 = v72 + v12 + 11190 * v11;
    v98 = v72 - (v12 + 11190 * v11);
    v13 = 11190 * v11 - v12 - (v11 << 13);
    v84 = v13 + v65;
    v14 = v8[8] * v5[8];
    v96 = v65 - v13;
    v15 = *(v8 - 8) * *(v5 - 8);
    v88 = v8[40] * v5[40];
    v66 = 10703 * v14;
    v94 = v8[24] * v5[24];
    v89 = -4433 * v14;
    v93 = 7053 * (v15 + v94 + v88);
    v16 = v93 + 2139 * (v15 + v94);
    v73 = 10703 * v14 + v16 + 2295 * v15;
    v17 = -4433 * v14 + -8565 * (v94 + v88) - 12112 * v94;
    v18 = v14 - v94;
    v77 = v17 + v16;
    v19 = -5540 * v15;
    v20 = v15 - v88;
    ++v8;
    v21 = v89 + v19 - 16244 * v88 + v93;
    v22 = 4433 * (v18 + v20);
    v23 = v22 + 6270 * v20;
    v90 = v22 - 15137 * v18;
    v7[60] = (v79 - v73) >> 11;
    *(v7 - 6) = (v79 + v73) >> 11;
    *v7 = (v99 + v23) >> 11;
    v7[54] = (v99 - v23) >> 11;
    v24 = v93 + 12998 * v88 - v66 - 8565 * (v94 + v88);
    v7[48] = (v84 - v77) >> 11;
    v7[6] = (v84 + v77) >> 11;
    v7[42] = (v96 - v24) >> 11;
    v7[12] = (v24 + v96) >> 11;
    v7[36] = (v97 - v90) >> 11;
    v7[18] = (v90 + v97) >> 11;
    v7[24] = (v98 + v21) >> 11;
    v7[30] = (v98 - v21) >> 11;
    v5 = (__int16 *)(v95 + 2);
    ++v7;
    v25 = v91-- == 1;
    v95 += 2;
  }
  while ( !v25 );
  result = &v100;
  v78 = (_DWORD *)(a4 + 8);
  v92 = 3;
  do
  {
    v27 = (*((_DWORD *)result - 2) + 16) << 13;
    v28 = 5793 * *((_DWORD *)result + 2) + v27;
    v29 = v27 - 11586 * *((_DWORD *)result + 2);
    v30 = 10033 * *(_DWORD *)result;
    v80 = v28 + v30;
    v31 = *((_DWORD *)result - 1);
    v85 = v28 - v30;
    v32 = 2998 * (v31 + *((_DWORD *)result + 3));
    v33 = (_BYTE *)(a5 + *(v78 - 2));
    v34 = v32 + ((v31 + *((_DWORD *)result + 1)) << 13);
    v35 = v32 + ((*((_DWORD *)result + 3) - *((_DWORD *)result + 1)) << 13);
    v67 = (v31 - *((_DWORD *)result + 1) - *((_DWORD *)result + 3)) << 13;
    *v33 = *(_BYTE *)((((v80 + v34) >> 18) & 0x3FF) + v6);
    v33[5] = *(_BYTE *)((((v80 - v34) >> 18) & 0x3FF) + v6);
    v33[1] = *(_BYTE *)((((v67 + v29) >> 18) & 0x3FF) + v6);
    v33[4] = *(_BYTE *)(v6 + (((v29 - v67) >> 18) & 0x3FF));
    v33[2] = *(_BYTE *)((((v85 + v35) >> 18) & 0x3FF) + v6);
    v36 = *((_DWORD *)result + 8);
    v33[3] = *(_BYTE *)((((v85 - v35) >> 18) & 0x3FF) + v6);
    v36 *= 5793;
    v37 = (_BYTE *)(a5 + *(v78 - 1));
    v38 = (*((_DWORD *)result + 4) + 16) << 13;
    v39 = v36 + v38;
    v40 = v38 - 2 * v36;
    v41 = 10033 * *((_DWORD *)result + 6);
    v81 = v39 + v41;
    v42 = *((_DWORD *)result + 5);
    v86 = v39 - v41;
    v43 = 2998 * (v42 + *((_DWORD *)result + 9));
    v44 = v43 + ((v42 + *((_DWORD *)result + 7)) << 13);
    v45 = v43 + ((*((_DWORD *)result + 9) - *((_DWORD *)result + 7)) << 13);
    v68 = (v42 - *((_DWORD *)result + 7) - *((_DWORD *)result + 9)) << 13;
    *v37 = *(_BYTE *)((((v81 + v44) >> 18) & 0x3FF) + v6);
    v37[5] = *(_BYTE *)((((v81 - v44) >> 18) & 0x3FF) + v6);
    v37[1] = *(_BYTE *)((((v68 + v40) >> 18) & 0x3FF) + v6);
    v37[4] = *(_BYTE *)(v6 + (((v40 - v68) >> 18) & 0x3FF));
    v37[2] = *(_BYTE *)((((v86 + v45) >> 18) & 0x3FF) + v6);
    v46 = *((_DWORD *)result + 14);
    v37[3] = *(_BYTE *)((((v86 - v45) >> 18) & 0x3FF) + v6);
    v46 *= 5793;
    v47 = (*((_DWORD *)result + 10) + 16) << 13;
    v48 = v46 + v47;
    v49 = (_BYTE *)(a5 + *v78);
    v50 = v47 - 2 * v46;
    v51 = 10033 * *((_DWORD *)result + 12);
    v82 = v48 + v51;
    v52 = *((_DWORD *)result + 11);
    v87 = v48 - v51;
    v69 = 2998 * (v52 + *((_DWORD *)result + 15));
    v74 = v69 + ((v52 + *((_DWORD *)result + 13)) << 13);
    v53 = v69 + ((*((_DWORD *)result + 15) - *((_DWORD *)result + 13)) << 13);
    v70 = (v52 - *((_DWORD *)result + 13) - *((_DWORD *)result + 15)) << 13;
    *v49 = *(_BYTE *)((((v82 + v74) >> 18) & 0x3FF) + v6);
    v49[5] = *(_BYTE *)((((v82 - v74) >> 18) & 0x3FF) + v6);
    v49[1] = *(_BYTE *)((((v70 + v50) >> 18) & 0x3FF) + v6);
    v49[4] = *(_BYTE *)(v6 + (((v50 - v70) >> 18) & 0x3FF));
    v49[2] = *(_BYTE *)((((v87 + v53) >> 18) & 0x3FF) + v6);
    v54 = *((_DWORD *)result + 20);
    v49[3] = *(_BYTE *)((((v87 - v53) >> 18) & 0x3FF) + v6);
    v54 *= 5793;
    v55 = (*((_DWORD *)result + 16) + 16) << 13;
    v56 = v54 + v55;
    v57 = v55 - 2 * v54;
    v58 = 10033 * *((_DWORD *)result + 18);
    v59 = v56 + v58;
    v60 = v56 - v58;
    v61 = (_BYTE *)(a5 + v78[1]);
    v83 = v59;
    v62 = *((_DWORD *)result + 17);
    v63 = 2998 * (v62 + *((_DWORD *)result + 21));
    v75 = v63 + ((v62 + *((_DWORD *)result + 19)) << 13);
    v64 = v63 + ((*((_DWORD *)result + 21) - *((_DWORD *)result + 19)) << 13);
    v71 = (v62 - *((_DWORD *)result + 19) - *((_DWORD *)result + 21)) << 13;
    *v61 = *(_BYTE *)((((v83 + v75) >> 18) & 0x3FF) + v6);
    v61[5] = *(_BYTE *)((((v83 - v75) >> 18) & 0x3FF) + v6);
    v78 += 4;
    v61[1] = *(_BYTE *)((((v71 + v57) >> 18) & 0x3FF) + v6);
    v61[4] = *(_BYTE *)(v6 + (((v57 - v71) >> 18) & 0x3FF));
    v61[2] = *(_BYTE *)((((v60 + v64) >> 18) & 0x3FF) + v6);
    result += 96;
    v25 = v92-- == 1;
    v61[3] = *(_BYTE *)((((v60 - v64) >> 18) & 0x3FF) + v6);
  }
  while ( !v25 );
  return result;
}
