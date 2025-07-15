char *__cdecl jpeg_idct_5x10(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // ecx
  __int16 *v6; // edi
  int *v7; // edx
  _DWORD *v8; // esi
  int v9; // ebp
  int v10; // eax
  int v11; // ebx
  int v12; // eax
  int v13; // ebx
  int v14; // ebp
  int v15; // eax
  int v16; // eax
  int v17; // ebx
  int v18; // eax
  int v19; // ebp
  int v20; // ebx
  char *result; // eax
  int v22; // edx
  int v23; // ebx
  int v24; // esi
  int v25; // ebp
  int v26; // edx
  int v27; // ebx
  int v28; // edx
  _BYTE *v29; // edi
  int v30; // edx
  int v31; // ebp
  int v32; // esi
  int v33; // edx
  int v34; // ebx
  _BYTE *v35; // edi
  int v36; // esi
  int v37; // ebp
  int v38; // edx
  int v39; // ebx
  int v40; // edx
  int v41; // edx
  int v42; // ebp
  int v43; // edx
  int v44; // ebx
  int v45; // esi
  int v46; // ebp
  int v47; // edx
  int v48; // ebx
  int v49; // edx
  _BYTE *v50; // edi
  int v51; // edx
  int v52; // ebp
  int v53; // edx
  int v54; // ebx
  int v55; // esi
  int v56; // ebp
  int v57; // edx
  int v58; // ebx
  int v59; // edx
  _BYTE *v60; // edi
  int v61; // edx
  int v62; // ebp
  int v63; // esi
  int v64; // edx
  _BYTE *v65; // edi
  int v66; // esi
  int v67; // ebx
  int v68; // ebp
  int v69; // edx
  int v70; // ebx
  int v71; // edx
  int v72; // edx
  bool v73; // zf
  int v74; // [esp+10h] [ebp-104h]
  int v75; // [esp+10h] [ebp-104h]
  int v76; // [esp+10h] [ebp-104h]
  int v77; // [esp+10h] [ebp-104h]
  int v78; // [esp+10h] [ebp-104h]
  int v79; // [esp+10h] [ebp-104h]
  int v80; // [esp+10h] [ebp-104h]
  int v81; // [esp+10h] [ebp-104h]
  int v82; // [esp+14h] [ebp-100h]
  int v83; // [esp+14h] [ebp-100h]
  int v84; // [esp+14h] [ebp-100h]
  int v85; // [esp+14h] [ebp-100h]
  int v86; // [esp+14h] [ebp-100h]
  int v87; // [esp+14h] [ebp-100h]
  int v88; // [esp+18h] [ebp-FCh]
  int v89; // [esp+18h] [ebp-FCh]
  int v90; // [esp+18h] [ebp-FCh]
  int v91; // [esp+18h] [ebp-FCh]
  int v92; // [esp+18h] [ebp-FCh]
  int v93; // [esp+18h] [ebp-FCh]
  int v94; // [esp+18h] [ebp-FCh]
  int v95; // [esp+1Ch] [ebp-F8h]
  int v96; // [esp+1Ch] [ebp-F8h]
  _DWORD *v97; // [esp+1Ch] [ebp-F8h]
  int v98; // [esp+20h] [ebp-F4h]
  int v99; // [esp+20h] [ebp-F4h]
  int v100; // [esp+20h] [ebp-F4h]
  int v101; // [esp+20h] [ebp-F4h]
  int v102; // [esp+20h] [ebp-F4h]
  int v103; // [esp+20h] [ebp-F4h]
  int v104; // [esp+24h] [ebp-F0h]
  int v105; // [esp+24h] [ebp-F0h]
  int v106; // [esp+2Ch] [ebp-E8h]
  int v107; // [esp+2Ch] [ebp-E8h]
  int v108; // [esp+30h] [ebp-E4h]
  int v109; // [esp+30h] [ebp-E4h]
  int v110; // [esp+34h] [ebp-E0h]
  int v111; // [esp+38h] [ebp-DCh]
  int v112; // [esp+3Ch] [ebp-D8h]
  int v113; // [esp+40h] [ebp-D4h]
  int v114; // [esp+44h] [ebp-D0h]
  int v115; // [esp+48h] [ebp-CCh]
  char v116; // [esp+5Ch] [ebp-B8h] BYREF
  char v117; // [esp+60h] [ebp-B4h] BYREF

  v5 = *(_DWORD *)(a1 + 292) + 128;
  v6 = (__int16 *)(a3 + 32);
  v7 = (int *)&v117;
  v8 = (_DWORD *)(*(_DWORD *)(a2 + 84) + 64);
  v104 = 5;
  do
  {
    v9 = v8[16] * v6[16];
    v10 = ((*(v8 - 16) * *(v6 - 16)) << 13) + 1024;
    v106 = v10 + 9373 * v9;
    v88 = v10 - 3580 * v9;
    v11 = v10 - 11586 * v9;
    v12 = *v8 * *v6;
    v110 = v11 >> 11;
    v13 = v8[32] * v6[32];
    v14 = 6810 * (v12 + v13);
    v15 = v14 + 4209 * v12;
    v74 = v14 - 17828 * v13;
    v114 = v106 - v15;
    v113 = v15 + v106;
    v115 = v74 + v88;
    v16 = v88 - v74;
    v17 = v8[8] * v6[8];
    v98 = v8[24] * v6[24];
    v95 = v8[40] * v6[40];
    v89 = v17 + v95;
    v75 = v17 - v95;
    v111 = v16;
    v18 = *(v8 - 8) * *(v6 - 8);
    v108 = 2531 * (v17 - v95);
    v82 = 7791 * (v17 + v95);
    v19 = v108 + (v98 << 13);
    v107 = v19 + v82 + 11443 * v18;
    v112 = v19 + 1812 * v18 - v82;
    ++v6;
    v96 = (v98 << 13) - ((v17 - v95) << 12) - v108;
    ++v8;
    v109 = 4 * (v18 - v75 - v98);
    v20 = 10323 * v18 - 4815 * v89 - v96;
    v76 = v96 + 5260 * v18 - 4815 * v89;
    v7[40] = (v113 - v107) >> 11;
    *(v7 - 5) = (v113 + v107) >> 11;
    v7[35] = (v115 - v20) >> 11;
    *v7 = (v115 + v20) >> 11;
    v7[30] = v110 - v109;
    v7[5] = v109 + v110;
    v7[25] = (v111 - v76) >> 11;
    v7[10] = (v111 + v76) >> 11;
    v7[15] = (v112 + v114) >> 11;
    v7[20] = (v114 - v112) >> 11;
    ++v7;
    --v104;
  }
  while ( v104 );
  result = &v116;
  v97 = (_DWORD *)(a4 + 8);
  v105 = 2;
  do
  {
    v22 = *((_DWORD *)result - 2);
    v23 = 6476 * (v22 + *(_DWORD *)result);
    v83 = 2896 * (v22 - *(_DWORD *)result);
    v24 = (*((_DWORD *)result - 4) + 16) << 13;
    v25 = v23 + v24 + v83;
    v26 = v24 + v83 - v23;
    v27 = *((_DWORD *)result - 3);
    v90 = v26;
    v99 = *((_DWORD *)result - 1);
    v28 = 6810 * (v27 + v99);
    v29 = (_BYTE *)(a5 + *(v97 - 2));
    v77 = v28 + 4209 * v27;
    v30 = v28 - 17828 * v99;
    *v29 = *(_BYTE *)((((v25 + v77) >> 18) & 0x3FF) + v5);
    v29[4] = *(_BYTE *)(v5 + (((v25 - v77) >> 18) & 0x3FF));
    v29[1] = *(_BYTE *)((((v30 + v90) >> 18) & 0x3FF) + v5);
    v31 = *((_DWORD *)result + 5);
    v29[3] = *(_BYTE *)(v5 + (((v90 - v30) >> 18) & 0x3FF));
    LOBYTE(v30) = *(_BYTE *)((((v24 - 4 * v83) >> 18) & 0x3FF) + v5);
    v32 = *((_DWORD *)result + 1);
    v29[2] = v30;
    v33 = *((_DWORD *)result + 3);
    v34 = 6476 * (v33 + v31);
    v35 = (_BYTE *)(a5 + *(v97 - 1));
    v84 = 2896 * (v33 - v31);
    v36 = (v32 + 16) << 13;
    v37 = v34 + v36 + v84;
    v38 = v36 + v84 - v34;
    v39 = *((_DWORD *)result + 2);
    v91 = v38;
    v100 = *((_DWORD *)result + 4);
    v40 = 6810 * (v39 + v100);
    v78 = v40 + 4209 * v39;
    v41 = v40 - 17828 * v100;
    *v35 = *(_BYTE *)((((v37 + v78) >> 18) & 0x3FF) + v5);
    v35[4] = *(_BYTE *)(v5 + (((v37 - v78) >> 18) & 0x3FF));
    v35[1] = *(_BYTE *)((((v41 + v91) >> 18) & 0x3FF) + v5);
    v42 = *((_DWORD *)result + 10);
    v35[3] = *(_BYTE *)(v5 + (((v91 - v41) >> 18) & 0x3FF));
    v35[2] = *(_BYTE *)((((v36 - 4 * v84) >> 18) & 0x3FF) + v5);
    v43 = *((_DWORD *)result + 8);
    v44 = 6476 * (v43 + v42);
    v85 = 2896 * (v43 - v42);
    v45 = (*((_DWORD *)result + 6) + 16) << 13;
    v46 = v44 + v45 + v85;
    v47 = v45 + v85 - v44;
    v48 = *((_DWORD *)result + 7);
    v92 = v47;
    v101 = *((_DWORD *)result + 9);
    v49 = 6810 * (v48 + v101);
    v50 = (_BYTE *)(a5 + *v97);
    v79 = v49 + 4209 * v48;
    v51 = v49 - 17828 * v101;
    *v50 = *(_BYTE *)((((v46 + v79) >> 18) & 0x3FF) + v5);
    v50[4] = *(_BYTE *)(v5 + (((v46 - v79) >> 18) & 0x3FF));
    v50[1] = *(_BYTE *)((((v51 + v92) >> 18) & 0x3FF) + v5);
    v50[3] = *(_BYTE *)(v5 + (((v92 - v51) >> 18) & 0x3FF));
    v52 = *((_DWORD *)result + 15);
    v50[2] = *(_BYTE *)((((v45 - 4 * v85) >> 18) & 0x3FF) + v5);
    v53 = *((_DWORD *)result + 13);
    v54 = 6476 * (v53 + v52);
    v86 = 2896 * (v53 - v52);
    v55 = (*((_DWORD *)result + 11) + 16) << 13;
    v56 = v54 + v55 + v86;
    v57 = v55 + v86 - v54;
    v58 = *((_DWORD *)result + 12);
    v93 = v57;
    v102 = *((_DWORD *)result + 14);
    v59 = 6810 * (v58 + v102);
    v60 = (_BYTE *)(a5 + v97[1]);
    v80 = v59 + 4209 * v58;
    v61 = v59 - 17828 * v102;
    *v60 = *(_BYTE *)((((v56 + v80) >> 18) & 0x3FF) + v5);
    v60[4] = *(_BYTE *)(v5 + (((v56 - v80) >> 18) & 0x3FF));
    v60[1] = *(_BYTE *)((((v61 + v93) >> 18) & 0x3FF) + v5);
    v62 = *((_DWORD *)result + 20);
    v60[3] = *(_BYTE *)(v5 + (((v93 - v61) >> 18) & 0x3FF));
    LOBYTE(v61) = *(_BYTE *)((((v55 - 4 * v86) >> 18) & 0x3FF) + v5);
    v63 = *((_DWORD *)result + 16);
    v60[2] = v61;
    v64 = *((_DWORD *)result + 18);
    v65 = (_BYTE *)(a5 + v97[2]);
    v66 = (v63 + 16) << 13;
    v67 = 6476 * (v64 + v62);
    v87 = 2896 * (v64 - v62);
    v68 = v67 + v66 + v87;
    v69 = v66 + v87 - v67;
    v70 = *((_DWORD *)result + 17);
    v94 = v69;
    v103 = *((_DWORD *)result + 19);
    v71 = 6810 * (v70 + v103);
    v81 = v71 + 4209 * v70;
    v72 = v71 - 17828 * v103;
    *v65 = *(_BYTE *)((((v68 + v81) >> 18) & 0x3FF) + v5);
    v97 += 5;
    v65[4] = *(_BYTE *)(v5 + (((v68 - v81) >> 18) & 0x3FF));
    v65[1] = *(_BYTE *)((((v72 + v94) >> 18) & 0x3FF) + v5);
    v65[3] = *(_BYTE *)(v5 + (((v94 - v72) >> 18) & 0x3FF));
    result += 100;
    v73 = v105-- == 1;
    v65[2] = *(_BYTE *)((((v66 - 4 * v87) >> 18) & 0x3FF) + v5);
  }
  while ( !v73 );
  return result;
}
