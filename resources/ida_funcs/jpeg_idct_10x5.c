int __cdecl jpeg_idct_10x5(int a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // ecx
  __int16 *v6; // edx
  int *v7; // eax
  int v8; // edi
  int v9; // ebx
  int v10; // ebp
  int v11; // esi
  int v12; // edi
  int v13; // ebx
  int v14; // ebp
  int v15; // edi
  int v16; // ebx
  int v17; // edi
  int v18; // esi
  int v19; // ebp
  int v20; // esi
  int v21; // edi
  int v22; // ebx
  int v23; // ebp
  int v24; // edi
  int v25; // ebx
  int v26; // edi
  int v27; // esi
  int v28; // ebp
  int v29; // esi
  int v30; // edi
  int v31; // ebx
  int v32; // ebp
  int v33; // edi
  int v34; // ebx
  int v35; // edi
  int v36; // esi
  int v37; // ebp
  int v38; // esi
  int v39; // edi
  int v40; // ebx
  int v41; // ebp
  int v42; // edi
  int v43; // esi
  int result; // eax
  char *v45; // edi
  int v46; // ebp
  int v47; // ecx
  int v48; // edx
  int v49; // ebx
  int v50; // ecx
  int v51; // edx
  int v52; // edx
  int v53; // ebp
  int v54; // ebx
  int v55; // edx
  int v56; // ebp
  int v57; // ebx
  int v58; // ebp
  _BYTE *v59; // eax
  int v60; // ebp
  int v61; // [esp+10h] [ebp-D4h]
  int v62; // [esp+10h] [ebp-D4h]
  int v63; // [esp+10h] [ebp-D4h]
  int v64; // [esp+10h] [ebp-D4h]
  int v65; // [esp+10h] [ebp-D4h]
  int v66; // [esp+10h] [ebp-D4h]
  int v67; // [esp+14h] [ebp-D0h]
  int v68; // [esp+14h] [ebp-D0h]
  int v69; // [esp+14h] [ebp-D0h]
  int v70; // [esp+14h] [ebp-D0h]
  int v71; // [esp+14h] [ebp-D0h]
  int v72; // [esp+18h] [ebp-CCh]
  int v73; // [esp+18h] [ebp-CCh]
  int v74; // [esp+18h] [ebp-CCh]
  int v75; // [esp+18h] [ebp-CCh]
  int v76; // [esp+18h] [ebp-CCh]
  int v77; // [esp+1Ch] [ebp-C8h]
  int v78; // [esp+1Ch] [ebp-C8h]
  int v79; // [esp+1Ch] [ebp-C8h]
  int v80; // [esp+1Ch] [ebp-C8h]
  int v81; // [esp+1Ch] [ebp-C8h]
  int v82; // [esp+20h] [ebp-C4h]
  int v83; // [esp+20h] [ebp-C4h]
  int v84; // [esp+20h] [ebp-C4h]
  int v85; // [esp+24h] [ebp-C0h]
  int v86; // [esp+24h] [ebp-C0h]
  int v87; // [esp+28h] [ebp-BCh]
  int v88; // [esp+28h] [ebp-BCh]
  int v89; // [esp+2Ch] [ebp-B8h]
  int v90; // [esp+30h] [ebp-B4h]
  int v91; // [esp+34h] [ebp-B0h]
  int v92; // [esp+38h] [ebp-ACh]
  int v93; // [esp+3Ch] [ebp-A8h]
  int v94; // [esp+40h] [ebp-A4h]
  char v95; // [esp+4Ch] [ebp-98h] BYREF
  char v96; // [esp+64h] [ebp-80h] BYREF

  v5 = *(_DWORD **)(a2 + 84);
  v82 = *(_DWORD *)(a1 + 292) + 128;
  v6 = (__int16 *)(a3 + 64);
  v7 = (int *)&v96;
  v85 = 2;
  do
  {
    v8 = v5[16] * *(v6 - 16);
    v9 = v5[32] * *v6;
    v10 = 6476 * (v9 + v8);
    v67 = 2896 * (v8 - v9);
    v11 = ((*v5 * *(v6 - 32)) << 13) + 1024;
    v61 = v67 + v11 + v10;
    v12 = v5[8] * *(v6 - 24);
    v72 = v67 + v11 - v10;
    v13 = v5[24] * *(v6 - 8);
    v14 = 6810 * (v13 + v12);
    v15 = v14 + 4209 * v12;
    v77 = v14 - 17828 * v13;
    v7[24] = (v61 - v15) >> 11;
    *(v7 - 8) = (v61 + v15) >> 11;
    v16 = v5[33] * v6[1];
    v7[16] = (v72 - v77) >> 11;
    v17 = v5[17] * *(v6 - 15);
    v7[8] = (v11 - 4 * v67) >> 11;
    v18 = v5[1] * *(v6 - 31);
    *v7 = (v72 + v77) >> 11;
    v19 = 6476 * (v16 + v17);
    v68 = 2896 * (v17 - v16);
    v20 = (v18 << 13) + 1024;
    v62 = v68 + v20 + v19;
    v21 = v5[9] * *(v6 - 23);
    v73 = v68 + v20 - v19;
    v22 = v5[25] * *(v6 - 7);
    v23 = 6810 * (v22 + v21);
    v24 = v23 + 4209 * v21;
    v78 = v23 - 17828 * v22;
    v7[25] = (v62 - v24) >> 11;
    *(v7 - 7) = (v62 + v24) >> 11;
    v25 = v5[34] * v6[2];
    v7[17] = (v73 - v78) >> 11;
    v26 = v5[18] * *(v6 - 14);
    v7[9] = (v20 - 4 * v68) >> 11;
    v27 = v5[2] * *(v6 - 30);
    v7[1] = (v73 + v78) >> 11;
    v28 = 6476 * (v25 + v26);
    v69 = 2896 * (v26 - v25);
    v29 = (v27 << 13) + 1024;
    v63 = v69 + v29 + v28;
    v30 = v5[10] * *(v6 - 22);
    v74 = v69 + v29 - v28;
    v31 = v5[26] * *(v6 - 6);
    v32 = 6810 * (v31 + v30);
    v33 = v32 + 4209 * v30;
    v79 = v32 - 17828 * v31;
    v7[26] = (v63 - v33) >> 11;
    *(v7 - 6) = (v63 + v33) >> 11;
    v34 = v5[35] * v6[3];
    v7[18] = (v74 - v79) >> 11;
    v35 = v5[19] * *(v6 - 13);
    v7[10] = (v29 - 4 * v69) >> 11;
    v36 = v5[3] * *(v6 - 29);
    v7[2] = (v74 + v79) >> 11;
    v37 = 6476 * (v34 + v35);
    v38 = (v36 << 13) + 1024;
    v70 = 2896 * (v35 - v34);
    v64 = v70 + v38 + v37;
    v39 = v5[11] * *(v6 - 21);
    v75 = v70 + v38 - v37;
    v40 = v5[27] * *(v6 - 5);
    v41 = 6810 * (v40 + v39);
    v42 = v41 + 4209 * v39;
    v80 = v41 - 17828 * v40;
    v7[27] = (v64 - v42) >> 11;
    *(v7 - 5) = (v64 + v42) >> 11;
    v7[3] = (v75 + v80) >> 11;
    v7[19] = (v75 - v80) >> 11;
    v7[11] = (v38 - 4 * v70) >> 11;
    v6 += 4;
    v5 += 4;
    v7 += 4;
    --v85;
  }
  while ( v85 );
  v43 = v82;
  result = 0;
  v90 = 0;
  v45 = &v95;
  do
  {
    v46 = *((_DWORD *)v45 + 2);
    v47 = 3580 * v46;
    v46 *= 9373;
    v48 = (*((_DWORD *)v45 - 2) + 16) << 13;
    v65 = v48 + v46;
    v49 = v48 - v47;
    v50 = v48 + 2 * v47 - 2 * v46;
    v83 = *((_DWORD *)v45 + 4);
    v51 = 6810 * (*(_DWORD *)v45 + v83);
    v87 = v51 + 4209 * *(_DWORD *)v45;
    v91 = v65 + v87;
    v93 = v65 - v87;
    v52 = v51 - 17828 * v83;
    v53 = v49 + v52;
    v92 = v49 - v52;
    v54 = *((_DWORD *)v45 + 1);
    v55 = *((_DWORD *)v45 - 1);
    v94 = v53;
    v84 = *((_DWORD *)v45 + 3) << 13;
    v56 = v54 + *((_DWORD *)v45 + 5);
    v57 = v54 - *((_DWORD *)v45 + 5);
    v76 = v56;
    v71 = 7791 * v56;
    v58 = 2531 * v57 + v84;
    v66 = v71 + v58 + 11443 * v55;
    v81 = v58 + 1812 * v55 - v71;
    v59 = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * result));
    v86 = v84 - (v57 << 12) - 2531 * v57;
    v88 = ((v55 - v57) << 13) - v84;
    v60 = 10323 * v55 - v86 - 4815 * v76;
    v89 = v86 + 5260 * v55 - 4815 * v76;
    *v59 = *(_BYTE *)((((v91 + v66) >> 18) & 0x3FF) + v43);
    v59[9] = *(_BYTE *)((((v91 - v66) >> 18) & 0x3FF) + v43);
    v59[1] = *(_BYTE *)((((v94 + v60) >> 18) & 0x3FF) + v43);
    v59[8] = *(_BYTE *)((((v94 - v60) >> 18) & 0x3FF) + v43);
    v59[2] = *(_BYTE *)((((v50 + v88) >> 18) & 0x3FF) + v43);
    v59[7] = *(_BYTE *)((((v50 - v88) >> 18) & 0x3FF) + v43);
    v59[3] = *(_BYTE *)((((v92 + v89) >> 18) & 0x3FF) + v43);
    v59[6] = *(_BYTE *)((((v92 - v89) >> 18) & 0x3FF) + v43);
    v59[4] = *(_BYTE *)((((v93 + v81) >> 18) & 0x3FF) + v43);
    v59[5] = *(_BYTE *)((((v93 - v81) >> 18) & 0x3FF) + v43);
    result = v90 + 1;
    v45 += 32;
    ++v90;
  }
  while ( v90 < 5 );
  return result;
}
