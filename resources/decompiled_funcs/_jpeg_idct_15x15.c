int __cdecl jpeg_idct_15x15(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // ecx
  __int16 *v6; // ebx
  _DWORD *v7; // ebp
  int *v8; // eax
  int v9; // edx
  int v10; // edi
  int v11; // esi
  int v12; // ebp
  int v13; // ebx
  int v14; // edx
  int v15; // edx
  int v16; // ebp
  int v17; // esi
  int v18; // ebx
  int v19; // edi
  int v20; // ebx
  int v21; // edi
  int v22; // esi
  int v23; // edi
  int v24; // ebp
  int v25; // edx
  int v26; // edx
  int v27; // ebp
  int v28; // ebp
  int v29; // edx
  int v30; // esi
  bool v31; // zf
  int result; // eax
  int *v33; // esi
  int v34; // edi
  int v35; // ebx
  int v36; // edx
  int v37; // ebp
  int v38; // esi
  int v39; // edx
  int v40; // edx
  int v41; // ebp
  int v42; // ebx
  _BYTE *v43; // eax
  int v44; // esi
  int v45; // edi
  int v46; // ebx
  int v47; // edx
  int v48; // edx
  int v49; // edx
  int v50; // ebp
  bool v51; // cc
  int v52; // [esp+10h] [ebp-228h]
  int v53; // [esp+10h] [ebp-228h]
  int v54; // [esp+10h] [ebp-228h]
  int v55; // [esp+14h] [ebp-224h]
  int v56; // [esp+14h] [ebp-224h]
  int v57; // [esp+14h] [ebp-224h]
  int v58; // [esp+14h] [ebp-224h]
  int v59; // [esp+14h] [ebp-224h]
  int v60; // [esp+18h] [ebp-220h]
  int v61; // [esp+18h] [ebp-220h]
  int v62; // [esp+18h] [ebp-220h]
  int v63; // [esp+18h] [ebp-220h]
  int v64; // [esp+18h] [ebp-220h]
  int v65; // [esp+1Ch] [ebp-21Ch]
  int v66; // [esp+1Ch] [ebp-21Ch]
  int v67; // [esp+1Ch] [ebp-21Ch]
  int v68; // [esp+1Ch] [ebp-21Ch]
  int v69; // [esp+20h] [ebp-218h]
  int v70; // [esp+20h] [ebp-218h]
  int v71; // [esp+24h] [ebp-214h]
  int v72; // [esp+24h] [ebp-214h]
  int v73; // [esp+24h] [ebp-214h]
  int v74; // [esp+28h] [ebp-210h]
  int v75; // [esp+28h] [ebp-210h]
  _DWORD *v76; // [esp+2Ch] [ebp-20Ch]
  _BYTE *v77; // [esp+2Ch] [ebp-20Ch]
  __int16 *v78; // [esp+30h] [ebp-208h]
  int v79; // [esp+30h] [ebp-208h]
  int v80; // [esp+34h] [ebp-204h]
  int v81; // [esp+34h] [ebp-204h]
  int v82; // [esp+38h] [ebp-200h]
  int v83; // [esp+38h] [ebp-200h]
  int v84; // [esp+3Ch] [ebp-1FCh]
  int v85; // [esp+3Ch] [ebp-1FCh]
  int v86; // [esp+40h] [ebp-1F8h]
  int v87; // [esp+40h] [ebp-1F8h]
  int v88; // [esp+44h] [ebp-1F4h]
  int v89; // [esp+44h] [ebp-1F4h]
  int v90; // [esp+48h] [ebp-1F0h]
  int v91; // [esp+48h] [ebp-1F0h]
  int v92; // [esp+4Ch] [ebp-1ECh]
  int v93; // [esp+4Ch] [ebp-1ECh]
  int v94; // [esp+50h] [ebp-1E8h]
  int v95; // [esp+50h] [ebp-1E8h]
  int v96; // [esp+54h] [ebp-1E4h]
  int v97; // [esp+54h] [ebp-1E4h]
  _BYTE v98[16]; // [esp+68h] [ebp-1D0h] BYREF
  char v99; // [esp+78h] [ebp-1C0h] BYREF

  v5 = *(_DWORD *)(a1 + 292) + 128;
  v6 = (__int16 *)(a3 + 64);
  v7 = (_DWORD *)(*(_DWORD *)(a2 + 84) + 128);
  v8 = (int *)&v99;
  v78 = (__int16 *)(a3 + 64);
  v76 = v7;
  v80 = 8;
  do
  {
    v9 = *(v7 - 32) * *(v6 - 32);
    v10 = *(v7 - 16) * *(v6 - 16);
    v11 = *v7 * *v6;
    v12 = v7[16] * v6[16];
    v13 = 9373 * v12;
    v12 *= 3580;
    v14 = (v9 << 13) + 1024;
    v65 = v14 - v12;
    v55 = v14 + v13;
    v15 = 2 * v12 - 2 * v13 + v14;
    v16 = v10 - v11;
    v17 = v10 + v11;
    v60 = 11795 * v10;
    v82 = 10958 * v17 + v55 + 374 * v16;
    v18 = 374 * v16 + v65 - 10958 * v17;
    v19 = v17;
    v17 *= 6476;
    v84 = v55 - 3271 * v16 - 4482 * v19;
    v20 = v60 + v18;
    v94 = 4482 * v19 + v65 - 3271 * v16 - v60;
    v90 = v17 + 2896 * v16 + v65;
    v21 = 2896 * v16 + v55 - v17;
    v92 = v15 + 5792 * v16;
    v86 = v15 - 11584 * v16;
    v22 = *(v76 - 24) * *(v78 - 24);
    v96 = v21;
    v61 = *(v76 - 8) * *(v78 - 8);
    v23 = 10033 * v76[8] * v78[8];
    v24 = v76[24] * v78[24];
    v25 = 6810 * (v22 + v61 - v24);
    v71 = v24;
    v52 = v25 + 4209 * v22;
    v88 = v25 - 17828 * (v61 - v24);
    v74 = -11018 * v61;
    v56 = -6810 * v61;
    v26 = 20131 * v24 - -11018 * v61;
    v62 = v22 - v24;
    v27 = v23 + 11522 * (v22 - v24);
    v69 = v27 + v26;
    v28 = v27 + v56 - 9113 * v22;
    v66 = 10033 * v62 - v23;
    v29 = 4712 * (v22 + v71);
    v57 = v29 + 3897 * v22 - v23 + v56;
    v30 = v29 + v23 - 7121 * v71 + v74;
    *(v8 - 8) = (v82 + v69) >> 11;
    v8[104] = (v82 - v69) >> 11;
    *v8 = (v90 + v52) >> 11;
    v8[96] = (v90 - v52) >> 11;
    v8[88] = (v92 - v66) >> 11;
    v8[8] = (v92 + v66) >> 11;
    v8[16] = (v20 + v57) >> 11;
    v8[80] = (v20 - v57) >> 11;
    v8[72] = (v96 - v88) >> 11;
    v8[64] = (v84 - v30) >> 11;
    v8[56] = (v94 - v28) >> 11;
    v8[24] = (v88 + v96) >> 11;
    v8[32] = (v30 + v84) >> 11;
    v8[40] = (v94 + v28) >> 11;
    v8[48] = v86 >> 11;
    v6 = v78 + 1;
    v7 = v76 + 1;
    ++v8;
    v31 = v80-- == 1;
    ++v78;
    ++v76;
  }
  while ( !v31 );
  result = 0;
  v33 = (int *)v98;
  v79 = 0;
  v77 = v98;
  do
  {
    v34 = *(v33 - 2);
    v35 = *v33;
    v36 = *(v33 - 4);
    v37 = v33[2];
    v38 = 9373 * v37;
    v37 *= 3580;
    v39 = (v36 + 16) << 13;
    v67 = v39 - v37;
    v58 = v39 + v38;
    v40 = 2 * v37 - 2 * v38 + v39;
    v41 = v34 - v35;
    v42 = v34 + v35;
    v53 = 374 * v41;
    v83 = 10958 * v42 + v58 + 374 * v41;
    v72 = v41;
    v41 *= 3271;
    v43 = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * result));
    v85 = v58 - v41 - 4482 * v42;
    v44 = 11795 * v34 + v53 + v67 - 10958 * v42;
    v45 = 4482 * v42 + v67 - v41 - 11795 * v34;
    v91 = 6476 * v42 + v67 + 2896 * v72;
    v97 = 2896 * v72 + v58 - 6476 * v42;
    v93 = 5792 * v72 + v40;
    v46 = *((_DWORD *)v77 - 3);
    v87 = v40 - 11584 * v72;
    v63 = *((_DWORD *)v77 - 1);
    v81 = 10033 * *((_DWORD *)v77 + 1);
    v73 = *((_DWORD *)v77 + 3);
    v47 = 6810 * (v46 + v63 - v73);
    v54 = v47 + 4209 * v46;
    v89 = v47 - 17828 * (v63 - v73);
    v75 = -11018 * v63;
    v59 = -6810 * v63;
    v48 = v81 + 11522 * (v46 - v73);
    v70 = v48 + 20131 * v73 - -11018 * v63;
    v95 = v48 + -6810 * v63 - 9113 * v46;
    v68 = 10033 * (v46 - v73) - v81;
    v64 = 4712 * (v46 + v73);
    v49 = v64 + 3897 * v46 - v81 + v59;
    *v43 = *(_BYTE *)((((v83 + v70) >> 18) & 0x3FF) + v5);
    v43[14] = *(_BYTE *)(v5 + (((v83 - v70) >> 18) & 0x3FF));
    v43[1] = *(_BYTE *)((((v91 + v54) >> 18) & 0x3FF) + v5);
    v43[13] = *(_BYTE *)(v5 + (((v91 - v54) >> 18) & 0x3FF));
    v43[2] = *(_BYTE *)((((v93 + v68) >> 18) & 0x3FF) + v5);
    v43[12] = *(_BYTE *)(v5 + (((v93 - v68) >> 18) & 0x3FF));
    v43[3] = *(_BYTE *)((((v44 + v49) >> 18) & 0x3FF) + v5);
    v43[11] = *(_BYTE *)((((v44 - v49) >> 18) & 0x3FF) + v5);
    v50 = v64 + v81 - 7121 * v73 + v75;
    v43[4] = *(_BYTE *)((((v97 + v89) >> 18) & 0x3FF) + v5);
    v43[10] = *(_BYTE *)((((v97 - v89) >> 18) & 0x3FF) + v5);
    v43[5] = *(_BYTE *)((((v85 + v50) >> 18) & 0x3FF) + v5);
    v43[9] = *(_BYTE *)((((v85 - v50) >> 18) & 0x3FF) + v5);
    v43[6] = *(_BYTE *)((((v95 + v45) >> 18) & 0x3FF) + v5);
    v43[8] = *(_BYTE *)((((v45 - v95) >> 18) & 0x3FF) + v5);
    v43[7] = *(_BYTE *)(((v87 >> 18) & 0x3FF) + v5);
    result = v79 + 1;
    v33 = (int *)(v77 + 32);
    v51 = v79 + 1 < 15;
    v77 += 32;
    ++v79;
  }
  while ( v51 );
  return result;
}
