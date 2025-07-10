int __cdecl jpeg_idct_13x13(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // ecx
  __int16 *v6; // ebx
  _DWORD *v7; // ebp
  int *v8; // eax
  int v9; // esi
  int v10; // edi
  int v11; // edx
  int v12; // esi
  int v13; // edx
  int v14; // ebx
  int v15; // ebx
  int v16; // ebx
  int v17; // ebx
  int v18; // ebp
  bool v19; // zf
  int result; // eax
  int *v21; // edx
  int v22; // ebx
  int v23; // ebp
  int v24; // esi
  int v25; // edx
  int v26; // edi
  int v27; // esi
  int v28; // edx
  int v29; // ebp
  int v30; // edi
  int v31; // esi
  int v32; // edi
  int v33; // edx
  int v34; // edi
  int v35; // ebp
  _BYTE *v36; // eax
  int v37; // edx
  int v38; // edx
  int v39; // edx
  int v40; // edx
  int v41; // ebx
  bool v42; // cc
  int v43; // [esp+10h] [ebp-1E8h]
  int v44; // [esp+10h] [ebp-1E8h]
  int v45; // [esp+10h] [ebp-1E8h]
  int v46; // [esp+10h] [ebp-1E8h]
  int v47; // [esp+10h] [ebp-1E8h]
  int v48; // [esp+10h] [ebp-1E8h]
  int v49; // [esp+14h] [ebp-1E4h]
  int v50; // [esp+14h] [ebp-1E4h]
  int v51; // [esp+14h] [ebp-1E4h]
  int v52; // [esp+14h] [ebp-1E4h]
  int v53; // [esp+14h] [ebp-1E4h]
  int v54; // [esp+14h] [ebp-1E4h]
  int v55; // [esp+14h] [ebp-1E4h]
  int v56; // [esp+14h] [ebp-1E4h]
  int v57; // [esp+14h] [ebp-1E4h]
  int v58; // [esp+18h] [ebp-1E0h]
  int v59; // [esp+18h] [ebp-1E0h]
  int v60; // [esp+18h] [ebp-1E0h]
  int v61; // [esp+18h] [ebp-1E0h]
  int v62; // [esp+18h] [ebp-1E0h]
  int v63; // [esp+18h] [ebp-1E0h]
  int v64; // [esp+18h] [ebp-1E0h]
  int v65; // [esp+18h] [ebp-1E0h]
  int v66; // [esp+1Ch] [ebp-1DCh]
  int v67; // [esp+1Ch] [ebp-1DCh]
  _DWORD *v68; // [esp+20h] [ebp-1D8h]
  _BYTE *v69; // [esp+20h] [ebp-1D8h]
  int v70; // [esp+24h] [ebp-1D4h]
  int v71; // [esp+24h] [ebp-1D4h]
  int v72; // [esp+24h] [ebp-1D4h]
  int v73; // [esp+28h] [ebp-1D0h]
  int v74; // [esp+28h] [ebp-1D0h]
  int v75; // [esp+28h] [ebp-1D0h]
  int v76; // [esp+2Ch] [ebp-1CCh]
  int v77; // [esp+2Ch] [ebp-1CCh]
  int v78; // [esp+30h] [ebp-1C8h]
  int v79; // [esp+30h] [ebp-1C8h]
  int v80; // [esp+30h] [ebp-1C8h]
  int v81; // [esp+30h] [ebp-1C8h]
  int v82; // [esp+34h] [ebp-1C4h]
  int v83; // [esp+34h] [ebp-1C4h]
  int v84; // [esp+38h] [ebp-1C0h]
  int v85; // [esp+3Ch] [ebp-1BCh]
  int v86; // [esp+3Ch] [ebp-1BCh]
  int v87; // [esp+40h] [ebp-1B8h]
  int v88; // [esp+40h] [ebp-1B8h]
  int v89; // [esp+44h] [ebp-1B4h]
  int v90; // [esp+44h] [ebp-1B4h]
  int v91; // [esp+48h] [ebp-1B0h]
  int v92; // [esp+48h] [ebp-1B0h]
  int v93; // [esp+4Ch] [ebp-1ACh]
  int v94; // [esp+50h] [ebp-1A8h]
  int v95; // [esp+50h] [ebp-1A8h]
  int v96; // [esp+54h] [ebp-1A4h]
  _BYTE v97[16]; // [esp+68h] [ebp-190h] BYREF
  char v98; // [esp+78h] [ebp-180h] BYREF

  v5 = *(_DWORD *)(a1 + 292) + 128;
  v6 = (__int16 *)(a3 + 64);
  v7 = (_DWORD *)(*(_DWORD *)(a2 + 84) + 128);
  v8 = (int *)&v98;
  v82 = a3 + 64;
  v68 = v7;
  v87 = 8;
  do
  {
    v66 = *(v7 - 16) * *(v6 - 16);
    v9 = *v7 * *v6;
    v73 = ((*(v7 - 32) * *(v6 - 32)) << 13) + 1024;
    v70 = v7[16] * v6[16];
    v78 = v9 + v70;
    v58 = v9 - v70;
    v49 = v73 + 793 * (v9 - v70);
    v10 = 9465 * (v9 + v70) + v49 + 11249 * v66;
    v93 = v49 + 4108 * v66 - 9465 * (v9 + v70);
    v11 = v73 + 3989 * (v9 - v70);
    v96 = v11 + 8672 * v66 - 2592 * (v9 + v70);
    v91 = 2592 * (v9 + v70) + v11 - 10258 * v66;
    v50 = 7678 * (v9 - v70) - v73;
    v94 = v73 - 7678 * (v9 - v70) - 1396 * v66 - 3570 * (v9 + v70);
    v12 = *(v7 - 24) * *(v6 - 24);
    v89 = 3570 * v78 - 6581 * v66 - v50;
    v85 = v73 + 11585 * (v58 - v66);
    v67 = *(v7 - 8) * *(v6 - 8);
    v13 = v7[8] * v6[8];
    v59 = 10832 * (v12 + v67);
    v71 = v7[24] * v6[24];
    v43 = 9534 * (v13 + v12);
    v51 = 7682 * (v12 + v71);
    v79 = v59 + v43 + v51 - 16549 * v12;
    v14 = -2773 * (v13 + v67);
    v60 = v14 + 6859 * v67 + v59;
    v44 = v14 - 12879 * v13 + v43;
    v15 = -9534 * (v67 + v71);
    v61 = v15 + v60;
    v52 = v15 + 18068 * v71 + v51;
    v16 = -5384 * (v13 + v71);
    v45 = v16 + v44;
    v53 = v16 + v52;
    v17 = 7682 * (v13 - v67);
    v76 = v17 + 2773 * (v12 + v71) + 2611 * v12 - 3818 * v67;
    v18 = v17 + 3150 * v13 - 14273 * v71 + 2773 * (v12 + v71);
    *(v8 - 8) = (v10 + v79) >> 11;
    v8[88] = (v10 - v79) >> 11;
    v8[80] = (v96 - v61) >> 11;
    *v8 = (v96 + v61) >> 11;
    v8[72] = (v93 - v45) >> 11;
    v8[8] = (v93 + v45) >> 11;
    v8[64] = (v94 - v53) >> 11;
    v8[16] = (v94 + v53) >> 11;
    v8[56] = (v89 - v76) >> 11;
    v8[48] = (v91 - v18) >> 11;
    v8[24] = (v76 + v89) >> 11;
    v8[32] = (v91 + v18) >> 11;
    v8[40] = v85 >> 11;
    v6 = (__int16 *)(v82 + 2);
    v7 = v68 + 1;
    ++v8;
    v19 = v87-- == 1;
    v82 += 2;
    ++v68;
  }
  while ( !v19 );
  result = 0;
  v21 = (int *)v97;
  v88 = 0;
  v69 = v97;
  do
  {
    v22 = *(v21 - 2);
    v23 = *(v21 - 4);
    v24 = *v21;
    v25 = v21[2];
    v26 = v25 + v24;
    v27 = v24 - v25;
    v80 = v26;
    v28 = 9465 * v26;
    v62 = v27;
    v29 = (v23 + 16) << 13;
    v30 = v29 + 793 * v27;
    v31 = v28 + v30 + 11249 * v22;
    v54 = v30;
    v32 = 4108 * v22 - v28;
    v33 = v29 + 3989 * v62;
    v74 = v29;
    v34 = v54 + v32;
    v35 = v33 + 8672 * v22 - 2592 * v80;
    v92 = 2592 * v80 + v33 - 10258 * v22;
    v95 = v74 - 7678 * v62 - 1396 * *((_DWORD *)v69 - 2) - 3570 * v80;
    v36 = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * result));
    v90 = 3570 * v80 - 6581 * *((_DWORD *)v69 - 2) - (7678 * v62 - v74);
    v86 = v74 + 11585 * (v62 - *((_DWORD *)v69 - 2));
    v75 = *((_DWORD *)v69 - 3);
    v83 = *((_DWORD *)v69 + 1);
    v72 = *((_DWORD *)v69 + 3);
    v63 = 10832 * (v75 + *((_DWORD *)v69 - 1));
    v46 = 9534 * (v75 + v83);
    v55 = 7682 * (v75 + v72);
    v81 = v63 + v46 + v55 - 16549 * v75;
    v37 = -2773 * (v83 + *((_DWORD *)v69 - 1));
    v64 = v37 + 6859 * *((_DWORD *)v69 - 1) + v63;
    v47 = v37 - 12879 * v83 + v46;
    v38 = -9534 * (v72 + *((_DWORD *)v69 - 1));
    v65 = v38 + v64;
    v56 = v38 + 18068 * v72 + v55;
    v39 = -5384 * (v83 + v72);
    v48 = v39 + v47;
    v57 = v39 + v56;
    v84 = 2773 * (v75 + v72);
    v40 = 7682 * (v83 - *((_DWORD *)v69 - 1));
    v77 = v40 + v84 + 2611 * v75 - 3818 * *((_DWORD *)v69 - 1);
    v41 = v40 + 3150 * v83 - 14273 * v72 + v84;
    *v36 = *(_BYTE *)((((v31 + v81) >> 18) & 0x3FF) + v5);
    v36[12] = *(_BYTE *)((((v31 - v81) >> 18) & 0x3FF) + v5);
    v36[1] = *(_BYTE *)((((v65 + v35) >> 18) & 0x3FF) + v5);
    v36[11] = *(_BYTE *)(v5 + (((v35 - v65) >> 18) & 0x3FF));
    v36[2] = *(_BYTE *)((((v34 + v48) >> 18) & 0x3FF) + v5);
    v36[10] = *(_BYTE *)((((v34 - v48) >> 18) & 0x3FF) + v5);
    v36[3] = *(_BYTE *)((((v95 + v57) >> 18) & 0x3FF) + v5);
    v36[9] = *(_BYTE *)((((v95 - v57) >> 18) & 0x3FF) + v5);
    v36[4] = *(_BYTE *)((((v77 + v90) >> 18) & 0x3FF) + v5);
    v36[8] = *(_BYTE *)((((v90 - v77) >> 18) & 0x3FF) + v5);
    v36[5] = *(_BYTE *)((((v41 + v92) >> 18) & 0x3FF) + v5);
    v36[7] = *(_BYTE *)((((v92 - v41) >> 18) & 0x3FF) + v5);
    v36[6] = *(_BYTE *)(((v86 >> 18) & 0x3FF) + v5);
    result = v88 + 1;
    v21 = (int *)(v69 + 32);
    v42 = v88 + 1 < 13;
    v69 += 32;
    ++v88;
  }
  while ( v42 );
  return result;
}
