char __cdecl jpeg_idct_3x6(int a1, int a2, __int16 *a3, _DWORD *a4, int a5)
{
  _DWORD *v5; // ecx
  int v6; // esi
  int v7; // ebx
  int v8; // edi
  int v9; // esi
  int v10; // ebx
  int v11; // edi
  int v13; // ebp
  int v14; // ebx
  int v15; // edi
  int v16; // esi
  int v17; // ebx
  int v18; // eax
  int v19; // edi
  int v20; // esi
  int v21; // ebx
  int v22; // edi
  int v23; // ebp
  int v24; // ebx
  int v25; // ebp
  int v26; // esi
  int v27; // ebx
  int v28; // edi
  int v29; // esi
  int v30; // ebx
  int v31; // edi
  int v32; // ebx
  int v33; // edx
  int v34; // ebp
  int v35; // ecx
  int v36; // edi
  int v37; // ebx
  int v38; // edi
  int v39; // ecx
  int v40; // edx
  int v41; // edx
  _BYTE *v42; // ebp
  _BYTE *v43; // ebp
  int v44; // ecx
  int v45; // edx
  int v46; // ebp
  int v47; // edi
  int v48; // ecx
  int v49; // ecx
  int v50; // edx
  int v51; // edi
  int v52; // ecx
  int v53; // edx
  _BYTE *v54; // edi
  int v55; // ecx
  int v56; // edx
  _BYTE *v57; // esi
  char result; // al
  int v59; // [esp+10h] [ebp-54h]
  int v60; // [esp+10h] [ebp-54h]
  int v61; // [esp+14h] [ebp-50h]
  int v62; // [esp+14h] [ebp-50h]
  int v63; // [esp+14h] [ebp-50h]
  int v64; // [esp+18h] [ebp-4Ch]
  int v65; // [esp+18h] [ebp-4Ch]
  int v66; // [esp+18h] [ebp-4Ch]
  int v67; // [esp+1Ch] [ebp-48h]
  int v68; // [esp+28h] [ebp-3Ch]
  int v69; // [esp+2Ch] [ebp-38h]
  int v70; // [esp+30h] [ebp-34h]
  int v71; // [esp+34h] [ebp-30h]
  int v72; // [esp+38h] [ebp-2Ch]
  int v73; // [esp+40h] [ebp-24h]
  int v74; // [esp+44h] [ebp-20h]
  int v75; // [esp+48h] [ebp-1Ch]
  int v76; // [esp+4Ch] [ebp-18h]
  int v77; // [esp+50h] [ebp-14h]
  int v78; // [esp+54h] [ebp-10h]
  int v79; // [esp+58h] [ebp-Ch]
  int v80; // [esp+5Ch] [ebp-8h]
  int v81; // [esp+60h] [ebp-4h]
  int v82; // [esp+68h] [ebp+4h]
  int v83; // [esp+68h] [ebp+4h]
  int v84; // [esp+68h] [ebp+4h]
  int v85; // [esp+6Ch] [ebp+8h]
  int v86; // [esp+6Ch] [ebp+8h]
  int v87; // [esp+6Ch] [ebp+8h]

  v5 = *(_DWORD **)(a2 + 84);
  v6 = ((*v5 * *a3) << 13) + 1024;
  v7 = 5793 * v5[32] * a3[32] + v6;
  v8 = 10033 * v5[16] * a3[16];
  v61 = (v6 - 11586 * v5[32] * a3[32]) >> 11;
  v9 = v7 + v8;
  v10 = v7 - v8;
  v11 = v5[8] * a3[8];
  v64 = v10;
  v85 = v5[40] * a3[40];
  v13 = 2998 * (v11 + v85);
  v59 = v5[24] * a3[24];
  v82 = v13 + ((v11 + v59) << 13);
  v14 = v13 + ((v85 - v59) << 13);
  v15 = 4 * (v11 - v85 - v59);
  v79 = (v9 - v82) >> 11;
  v67 = (v9 + v82) >> 11;
  v76 = v61 - v15;
  v71 = (v64 + v14) >> 11;
  v73 = (v64 - v14) >> 11;
  v16 = ((v5[1] * a3[1]) << 13) + 1024;
  v17 = 5793 * v5[33] * a3[33] + v16;
  v18 = *(_DWORD *)(a1 + 292) + 128;
  v68 = v61 + v15;
  v62 = (v16 - 11586 * v5[33] * a3[33]) >> 11;
  v19 = 10033 * v5[17] * a3[17];
  v20 = v17 + v19;
  v21 = v17 - v19;
  v22 = v5[9] * a3[9];
  v65 = v21;
  v86 = v5[41] * a3[41];
  v60 = v5[25] * a3[25];
  v23 = 2998 * (v22 + v86);
  v83 = v23 + ((v22 + v60) << 13);
  v24 = v23 + ((v86 - v60) << 13);
  v25 = v20 + v83;
  v80 = (v20 - v83) >> 11;
  v69 = v62 + 4 * (v22 - v86 - v60);
  v77 = v62 - 4 * (v22 - v86 - v60);
  v72 = (v65 + v24) >> 11;
  v74 = (v65 - v24) >> 11;
  v26 = ((v5[2] * a3[2]) << 13) + 1024;
  v27 = 5793 * v5[34] * a3[34] + v26;
  v28 = 10033 * v5[18] * a3[18];
  v63 = (v26 - 11586 * v5[34] * a3[34]) >> 11;
  v29 = v27 + v28;
  v30 = v27 - v28;
  v31 = v5[10] * a3[10];
  v66 = v30;
  v32 = v5[26] * a3[26];
  v87 = v5[42] * a3[42];
  v33 = 2998 * (v31 + v87);
  v84 = v33 + ((v32 + v31) << 13);
  v34 = 10033 * (v25 >> 11);
  v35 = v33 + ((v87 - v32) << 13);
  v81 = (v29 - v84) >> 11;
  v36 = 4 * (v31 - v87 - v32);
  v37 = v63 + v36;
  v78 = v63 - v36;
  v38 = v66 + v35;
  v70 = v37;
  v75 = (v66 - v35) >> 11;
  v39 = (v67 + 16) << 13;
  v40 = 5793 * ((v29 + v84) >> 11) + v39;
  LOBYTE(v37) = *(_BYTE *)((((v40 + v34) >> 18) & 0x3FF) + v18);
  v41 = v40 - v34;
  v42 = (_BYTE *)(a5 + *a4);
  *v42 = v37;
  v42[2] = *(_BYTE *)(((v41 >> 18) & 0x3FF) + v18);
  v42[1] = *(_BYTE *)((((v39 - 11586 * ((v29 + v84) >> 11)) >> 18) & 0x3FF) + v18);
  v43 = (_BYTE *)(a5 + a4[1]);
  v44 = (v68 + 16) << 13;
  v45 = 5793 * v70 + v44;
  *v43 = *(_BYTE *)((((v45 + 10033 * v69) >> 18) & 0x3FF) + v18);
  v43[2] = *(_BYTE *)((((v45 - 10033 * v69) >> 18) & 0x3FF) + v18);
  v43[1] = *(_BYTE *)((((v44 - 11586 * v70) >> 18) & 0x3FF) + v18);
  v46 = a4[2];
  v47 = 5793 * (v38 >> 11);
  v48 = (v71 + 16) << 13;
  *(_BYTE *)(v46 + a5) = *(_BYTE *)((((v47 + v48 + 10033 * v72) >> 18) & 0x3FF) + v18);
  *(_BYTE *)(v46 + a5 + 2) = *(_BYTE *)((((v47 + v48 - 10033 * v72) >> 18) & 0x3FF) + v18);
  *(_BYTE *)(a5 + v46 + 1) = *(_BYTE *)((((v48 - 2 * v47) >> 18) & 0x3FF) + v18);
  v49 = (v73 + 16) << 13;
  v50 = v49 + 5793 * v75;
  v51 = a4[3];
  *(_BYTE *)(v51 + a5) = *(_BYTE *)((((v50 + 10033 * v74) >> 18) & 0x3FF) + v18);
  *(_BYTE *)(v51 + a5 + 2) = *(_BYTE *)((((v50 - 10033 * v74) >> 18) & 0x3FF) + v18);
  *(_BYTE *)(a5 + v51 + 1) = *(_BYTE *)(v18 + (((v49 - 11586 * v75) >> 18) & 0x3FF));
  v52 = (v76 + 16) << 13;
  v53 = v52 + 5793 * v78;
  v54 = (_BYTE *)(a5 + a4[4]);
  *v54 = *(_BYTE *)((((v53 + 10033 * v77) >> 18) & 0x3FF) + v18);
  v54[2] = *(_BYTE *)((((v53 - 10033 * v77) >> 18) & 0x3FF) + v18);
  v54[1] = *(_BYTE *)(v18 + (((v52 - 11586 * v78) >> 18) & 0x3FF));
  v55 = (v79 + 16) << 13;
  v56 = 5793 * v81 + v55;
  v57 = (_BYTE *)(a5 + a4[5]);
  *v57 = *(_BYTE *)((((v56 + 10033 * v80) >> 18) & 0x3FF) + v18);
  v57[2] = *(_BYTE *)((((v56 - 10033 * v80) >> 18) & 0x3FF) + v18);
  result = *(_BYTE *)((((v55 - 11586 * v81) >> 18) & 0x3FF) + v18);
  v57[1] = result;
  return result;
}
