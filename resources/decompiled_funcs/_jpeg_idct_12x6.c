int __cdecl jpeg_idct_12x6(int a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // ecx
  int v6; // ebx
  __int16 *v7; // edx
  char *v8; // eax
  int v9; // esi
  int v10; // ebp
  int v11; // esi
  int v12; // edi
  int v13; // ebp
  int v14; // esi
  int v15; // ebp
  int v16; // edi
  int v17; // esi
  int v18; // edi
  int v19; // esi
  int v20; // ebp
  int v21; // esi
  int v22; // edi
  int v23; // ebp
  int v24; // esi
  int v25; // ebp
  int v26; // edi
  int v27; // esi
  int v28; // edi
  int v29; // esi
  int v30; // ebp
  int v31; // esi
  int v32; // edi
  int v33; // ebp
  int v34; // esi
  int v35; // edi
  int v36; // ebp
  int v37; // esi
  int v38; // ebp
  int v39; // edi
  int v40; // esi
  int v41; // edi
  int v42; // esi
  int v43; // ebp
  int v44; // esi
  int v45; // edi
  int v46; // ebp
  int v47; // esi
  int result; // eax
  char *v49; // esi
  int v50; // edx
  int v51; // ecx
  int v52; // edi
  _BYTE *v53; // eax
  int v54; // edx
  int v55; // edi
  int v56; // edx
  int v57; // edi
  int v58; // ecx
  int v59; // ebp
  int v60; // ebp
  int v61; // edi
  int v62; // edx
  int v63; // ebp
  int v64; // ecx
  int v65; // edx
  int v66; // [esp+10h] [ebp-F4h]
  int v67; // [esp+10h] [ebp-F4h]
  int v68; // [esp+10h] [ebp-F4h]
  int v69; // [esp+10h] [ebp-F4h]
  int v70; // [esp+14h] [ebp-F0h]
  int v71; // [esp+14h] [ebp-F0h]
  int v72; // [esp+14h] [ebp-F0h]
  int v73; // [esp+14h] [ebp-F0h]
  int v74; // [esp+14h] [ebp-F0h]
  int v75; // [esp+14h] [ebp-F0h]
  int v76; // [esp+18h] [ebp-ECh]
  int v77; // [esp+18h] [ebp-ECh]
  int v78; // [esp+18h] [ebp-ECh]
  int v79; // [esp+18h] [ebp-ECh]
  int v80; // [esp+18h] [ebp-ECh]
  int v81; // [esp+18h] [ebp-ECh]
  int v82; // [esp+18h] [ebp-ECh]
  int v83; // [esp+18h] [ebp-ECh]
  int v84; // [esp+1Ch] [ebp-E8h]
  int v85; // [esp+1Ch] [ebp-E8h]
  int v86; // [esp+1Ch] [ebp-E8h]
  int v87; // [esp+1Ch] [ebp-E8h]
  int v88; // [esp+1Ch] [ebp-E8h]
  int v89; // [esp+1Ch] [ebp-E8h]
  int v90; // [esp+20h] [ebp-E4h]
  int v91; // [esp+20h] [ebp-E4h]
  int v92; // [esp+20h] [ebp-E4h]
  int v93; // [esp+20h] [ebp-E4h]
  int v94; // [esp+20h] [ebp-E4h]
  int v95; // [esp+24h] [ebp-E0h]
  int v96; // [esp+24h] [ebp-E0h]
  int v97; // [esp+24h] [ebp-E0h]
  int v98; // [esp+24h] [ebp-E0h]
  int v99; // [esp+24h] [ebp-E0h]
  int v100; // [esp+28h] [ebp-DCh]
  int v101; // [esp+28h] [ebp-DCh]
  int v102; // [esp+28h] [ebp-DCh]
  int v103; // [esp+28h] [ebp-DCh]
  int v104; // [esp+28h] [ebp-DCh]
  int v105; // [esp+2Ch] [ebp-D8h]
  int v106; // [esp+2Ch] [ebp-D8h]
  int v107; // [esp+30h] [ebp-D4h]
  int v108; // [esp+34h] [ebp-D0h]
  int v109; // [esp+38h] [ebp-CCh]
  int v110; // [esp+3Ch] [ebp-C8h]
  int v111; // [esp+40h] [ebp-C4h]
  char v112; // [esp+4Ch] [ebp-B8h] BYREF
  char v113; // [esp+64h] [ebp-A0h] BYREF

  v5 = *(_DWORD **)(a2 + 84);
  v6 = *(_DWORD *)(a1 + 292) + 128;
  v7 = (__int16 *)(a3 + 32);
  v8 = &v113;
  v105 = 2;
  do
  {
    v9 = ((*v5 * *(v7 - 16)) << 13) + 1024;
    v10 = 5793 * v5[32] * v7[16] + v9;
    v100 = (v9 - 11586 * v5[32] * v7[16]) >> 11;
    v11 = 10033 * v5[16] * *v7;
    v95 = v11 + v10;
    v12 = v5[8] * *(v7 - 8);
    v90 = v10 - v11;
    v76 = v5[40] * v7[24];
    v13 = 2998 * (v12 + v76);
    v70 = v5[24] * v7[8];
    v84 = v13 + ((v12 + v70) << 13);
    v14 = v13 + ((v76 - v70) << 13);
    v66 = 4 * (v12 - v76 - v70);
    *((_DWORD *)v8 + 32) = (v95 - v84) >> 11;
    *((_DWORD *)v8 - 8) = (v95 + v84) >> 11;
    *(_DWORD *)v8 = v100 + v66;
    *((_DWORD *)v8 + 24) = v100 - v66;
    v15 = v90 + v14;
    v16 = v90 - v14;
    v17 = v5[1] * *(v7 - 15);
    *((_DWORD *)v8 + 16) = v16 >> 11;
    v18 = 5793 * v5[33] * v7[17];
    v19 = (v17 << 13) + 1024;
    *((_DWORD *)v8 + 8) = v15 >> 11;
    v20 = v18 + v19;
    v101 = (v19 - 2 * v18) >> 11;
    v21 = 10033 * v5[17] * v7[1];
    v96 = v21 + v20;
    v22 = v5[9] * *(v7 - 7);
    v91 = v20 - v21;
    v77 = v5[41] * v7[25];
    v71 = v5[25] * v7[9];
    v23 = 2998 * (v22 + v77);
    v85 = v23 + ((v22 + v71) << 13);
    v24 = v23 + ((v77 - v71) << 13);
    v67 = 4 * (v22 - v77 - v71);
    *((_DWORD *)v8 + 33) = (v96 - v85) >> 11;
    *((_DWORD *)v8 - 7) = (v96 + v85) >> 11;
    *((_DWORD *)v8 + 1) = v101 + v67;
    *((_DWORD *)v8 + 25) = v101 - v67;
    v25 = v91 + v24;
    v26 = v91 - v24;
    v27 = v5[2] * *(v7 - 14);
    *((_DWORD *)v8 + 17) = v26 >> 11;
    v28 = 5793 * v5[34] * v7[18];
    v29 = (v27 << 13) + 1024;
    *((_DWORD *)v8 + 9) = v25 >> 11;
    v30 = v28 + v29;
    v102 = (v29 - 2 * v28) >> 11;
    v31 = 10033 * v5[18] * v7[2];
    v32 = v31 + v30;
    v33 = v30 - v31;
    v34 = v5[26] * v7[10];
    v92 = v33;
    v97 = v32;
    v35 = v5[10] * *(v7 - 6);
    v78 = v5[42] * v7[26];
    v36 = 2998 * (v35 + v78);
    v86 = v36 + ((v35 + v34) << 13);
    v68 = 4 * (v35 - v78 - v34);
    v37 = v36 + ((v78 - v34) << 13);
    *((_DWORD *)v8 + 34) = (v97 - v86) >> 11;
    *((_DWORD *)v8 - 6) = (v97 + v86) >> 11;
    *((_DWORD *)v8 + 2) = v102 + v68;
    *((_DWORD *)v8 + 26) = v102 - v68;
    v38 = v92 + v37;
    v39 = v92 - v37;
    v40 = v5[3] * *(v7 - 13);
    *((_DWORD *)v8 + 18) = v39 >> 11;
    v41 = 5793 * v5[35] * v7[19];
    v42 = (v40 << 13) + 1024;
    *((_DWORD *)v8 + 10) = v38 >> 11;
    v43 = v41 + v42;
    v103 = (v42 - 2 * v41) >> 11;
    v44 = 10033 * v5[19] * v7[3];
    v98 = v44 + v43;
    v45 = v5[11] * *(v7 - 5);
    v93 = v43 - v44;
    v79 = v5[43] * v7[27];
    v46 = 2998 * (v45 + v79);
    v72 = v5[27] * v7[11];
    v87 = v46 + ((v45 + v72) << 13);
    v47 = v46 + ((v79 - v72) << 13);
    v69 = 4 * (v45 - v79 - v72);
    *((_DWORD *)v8 - 5) = (v98 + v87) >> 11;
    *((_DWORD *)v8 + 35) = (v98 - v87) >> 11;
    *((_DWORD *)v8 + 3) = v103 + v69;
    *((_DWORD *)v8 + 27) = v103 - v69;
    *((_DWORD *)v8 + 11) = (v93 + v47) >> 11;
    *((_DWORD *)v8 + 19) = (v93 - v47) >> 11;
    v7 += 4;
    v5 += 4;
    v8 += 16;
    --v105;
  }
  while ( v105 );
  result = 0;
  v107 = 0;
  v49 = &v112;
  do
  {
    v50 = 10033 * *((_DWORD *)v49 + 2);
    v51 = (*((_DWORD *)v49 - 2) + 16) << 13;
    v88 = v50 + v51;
    v52 = v51 - v50;
    v73 = *((_DWORD *)v49 + 4) << 13;
    v53 = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * result));
    v80 = (*(_DWORD *)v49 << 13) - v73;
    v104 = v51 + v80;
    v109 = v51 - v80;
    v81 = 11190 * *(_DWORD *)v49 + v73;
    v54 = 11190 * *(_DWORD *)v49 - v73 - (*(_DWORD *)v49 << 13);
    v99 = v88 + v81;
    v110 = v88 - v81;
    v94 = v52 + v54;
    v55 = v52 - v54;
    v56 = *((_DWORD *)v49 - 1);
    v111 = v55;
    v57 = *((_DWORD *)v49 + 1);
    v74 = -4433 * v57;
    v58 = v56 + *((_DWORD *)v49 + 3);
    v82 = 7053 * (v58 + *((_DWORD *)v49 + 5)) + 2139 * v58;
    v108 = 7053 * (v58 + *((_DWORD *)v49 + 5));
    v59 = *((_DWORD *)v49 + 3);
    v89 = v82 + 10703 * v57 + 2295 * v56;
    v83 = -4433 * v57 + -8565 * (v59 + *((_DWORD *)v49 + 5)) - 12112 * v59 + v82;
    v106 = v108 + 12998 * *((_DWORD *)v49 + 5) - 10703 * v57 - 8565 * (v59 + *((_DWORD *)v49 + 5));
    v60 = -5540 * v56;
    v61 = v57 - *((_DWORD *)v49 + 3);
    v62 = v56 - *((_DWORD *)v49 + 5);
    v63 = v74 + v60 - 16244 * *((_DWORD *)v49 + 5) + v108;
    v64 = 4433 * (v61 + v62);
    v65 = v64 + 6270 * v62;
    v75 = v64 - 15137 * v61;
    *v53 = *(_BYTE *)((((v99 + v89) >> 18) & 0x3FF) + v6);
    v53[11] = *(_BYTE *)((((v99 - v89) >> 18) & 0x3FF) + v6);
    v53[1] = *(_BYTE *)((((v104 + v65) >> 18) & 0x3FF) + v6);
    v53[10] = *(_BYTE *)((((v104 - v65) >> 18) & 0x3FF) + v6);
    v53[2] = *(_BYTE *)((((v94 + v83) >> 18) & 0x3FF) + v6);
    v53[9] = *(_BYTE *)((((v94 - v83) >> 18) & 0x3FF) + v6);
    v53[3] = *(_BYTE *)((((v106 + v111) >> 18) & 0x3FF) + v6);
    v53[8] = *(_BYTE *)((((v111 - v106) >> 18) & 0x3FF) + v6);
    v53[4] = *(_BYTE *)((((v75 + v109) >> 18) & 0x3FF) + v6);
    v53[7] = *(_BYTE *)((((v109 - v75) >> 18) & 0x3FF) + v6);
    v53[5] = *(_BYTE *)((((v110 + v63) >> 18) & 0x3FF) + v6);
    v53[6] = *(_BYTE *)((((v110 - v63) >> 18) & 0x3FF) + v6);
    result = v107 + 1;
    v49 += 32;
    ++v107;
  }
  while ( v107 < 6 );
  return result;
}
