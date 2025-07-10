int __cdecl jpeg_idct_4x4(int a1, int a2, __int16 *a3, _DWORD *a4, int a5)
{
  _DWORD *v5; // ecx
  int v6; // esi
  int v7; // edi
  int v8; // ebx
  int v9; // esi
  int v10; // edi
  int v11; // ebp
  int v13; // esi
  int v14; // edi
  int v15; // esi
  int v16; // ebp
  int v17; // ebx
  int v18; // edi
  int v19; // esi
  int v20; // edi
  int v21; // ebx
  int v22; // esi
  int v23; // edi
  int v24; // ebp
  int v25; // esi
  int v26; // edi
  int v27; // esi
  int v28; // ebp
  int v29; // ebx
  int v30; // edi
  int v31; // esi
  int result; // eax
  int v33; // edi
  int v34; // ebx
  int v35; // ebp
  int v36; // esi
  int v37; // edi
  int v38; // esi
  int v39; // edi
  int v40; // esi
  int v41; // ebp
  int v42; // ebx
  int v43; // edi
  int v44; // esi
  int v45; // ebp
  int v46; // edi
  int v47; // ebp
  int v48; // esi
  int v49; // edx
  int v50; // ecx
  int v51; // esi
  int v52; // ecx
  int v53; // ebx
  int v54; // edi
  _BYTE *v55; // esi
  int v56; // ebp
  int v57; // edx
  int v58; // edi
  int v59; // edx
  int v60; // ecx
  _BYTE *v61; // esi
  int v62; // edx
  int v63; // ecx
  int v64; // edi
  int v65; // edx
  int v66; // ebp
  _BYTE *v67; // esi
  int v68; // edx
  int v69; // ecx
  int v70; // edi
  int v71; // edx
  int v72; // ebp
  _BYTE *v73; // esi
  int v74; // edx
  int v75; // ecx
  int v76; // edi
  int v77; // edx
  int v78; // ebp
  int v79; // [esp+10h] [ebp-40h]
  int v80; // [esp+14h] [ebp-3Ch]
  int v81; // [esp+18h] [ebp-38h]
  int v82; // [esp+20h] [ebp-30h]
  int v83; // [esp+24h] [ebp-2Ch]
  int v84; // [esp+28h] [ebp-28h]
  int v85; // [esp+2Ch] [ebp-24h]
  int v86; // [esp+30h] [ebp-20h]
  int v87; // [esp+34h] [ebp-1Ch]
  int v88; // [esp+38h] [ebp-18h]
  int v89; // [esp+3Ch] [ebp-14h]
  int v90; // [esp+40h] [ebp-10h]
  int v91; // [esp+44h] [ebp-Ch]
  int v92; // [esp+48h] [ebp-8h]
  int v93; // [esp+4Ch] [ebp-4h]
  int v94; // [esp+54h] [ebp+4h]
  int v95; // [esp+54h] [ebp+4h]
  int v96; // [esp+54h] [ebp+4h]

  v5 = *(_DWORD **)(a2 + 84);
  v6 = *v5 * *a3;
  v7 = v5[16] * a3[16];
  v8 = v7 + v6;
  v9 = v6 - v7;
  v10 = v5[8] * a3[8];
  v11 = v5[24] * a3[24];
  v94 = 4 * v9;
  v13 = 4433 * (v10 + v11) + 1024;
  v14 = (v13 + 6270 * v10) >> 11;
  v15 = (v13 - 15137 * v11) >> 11;
  v8 *= 4;
  v16 = v8 + v14;
  v90 = v8 - v14;
  v17 = v94 + v15;
  v18 = v94 - v15;
  v19 = v5[1] * a3[1];
  v86 = v18;
  v20 = v5[17] * a3[17];
  v82 = v17;
  v21 = v20 + v19;
  v22 = v19 - v20;
  v23 = v5[9] * a3[9];
  v79 = v16;
  v24 = v5[25] * a3[25];
  v95 = 4 * v22;
  v25 = 4433 * (v23 + v24) + 1024;
  v26 = (v25 + 6270 * v23) >> 11;
  v21 *= 4;
  v27 = v25 - 15137 * v24;
  v28 = v21 + v26;
  v27 >>= 11;
  v91 = v21 - v26;
  v29 = v95 + v27;
  v30 = v95 - v27;
  v31 = v5[2] * a3[2];
  v87 = v30;
  result = *(_DWORD *)(a1 + 292) + 128;
  v33 = v5[18] * a3[18];
  v83 = v29;
  v80 = v28;
  v34 = v33 + v31;
  v35 = v5[26] * a3[26];
  v36 = v31 - v33;
  v37 = v5[10] * a3[10];
  v96 = 4 * v36;
  v38 = 4433 * (v37 + v35) + 1024;
  v39 = (v38 + 6270 * v37) >> 11;
  v40 = (v38 - 15137 * v35) >> 11;
  v34 *= 4;
  v41 = v34 + v39;
  v92 = v34 - v39;
  v42 = v96 + v40;
  v43 = v96 - v40;
  v44 = v5[3] * a3[3];
  v81 = v41;
  v45 = v5[19] * a3[19];
  v88 = v43;
  v46 = v44 + v45;
  v47 = 4 * (v44 - v45);
  v48 = v5[11] * a3[11];
  v49 = v5[27] * a3[27];
  v50 = 4433 * (v49 + v48) + 1024;
  v51 = v50 + 6270 * v48;
  v46 *= 4;
  v52 = (v50 - 15137 * v49) >> 11;
  v84 = v42;
  v51 >>= 11;
  v53 = v46 + v51;
  v54 = v46 - v51;
  v85 = v52 + v47;
  v55 = (_BYTE *)(a5 + *a4);
  v93 = v54;
  v89 = v47 - v52;
  v56 = (v79 + 16 - v81) << 13;
  v57 = 4433 * (v53 + v80);
  v58 = v57 + 6270 * v80;
  v59 = v57 - 15137 * v53;
  v60 = (v81 + v79 + 16) << 13;
  *v55 = *(_BYTE *)((((v60 + v58) >> 18) & 0x3FF) + result);
  v55[3] = *(_BYTE *)((((v60 - v58) >> 18) & 0x3FF) + result);
  v55[1] = *(_BYTE *)((((v59 + v56) >> 18) & 0x3FF) + result);
  v55[2] = *(_BYTE *)(result + (((v56 - v59) >> 18) & 0x3FF));
  v61 = (_BYTE *)(a5 + a4[1]);
  v62 = 4433 * (v85 + v83);
  v63 = (v84 + v82 + 16) << 13;
  v64 = v62 + 6270 * v83;
  v65 = v62 - 15137 * v85;
  *v61 = *(_BYTE *)((((v63 + v64) >> 18) & 0x3FF) + result);
  v61[3] = *(_BYTE *)((((v63 - v64) >> 18) & 0x3FF) + result);
  v66 = (v82 + 16 - v84) << 13;
  v61[1] = *(_BYTE *)((((v65 + v66) >> 18) & 0x3FF) + result);
  v61[2] = *(_BYTE *)(result + (((v66 - v65) >> 18) & 0x3FF));
  v67 = (_BYTE *)(a5 + a4[2]);
  v68 = 4433 * (v89 + v87);
  v69 = (v88 + v86 + 16) << 13;
  v70 = v68 + 6270 * v87;
  v71 = v68 - 15137 * v89;
  v72 = (v86 + 16 - v88) << 13;
  *v67 = *(_BYTE *)((((v69 + v70) >> 18) & 0x3FF) + result);
  v67[3] = *(_BYTE *)((((v69 - v70) >> 18) & 0x3FF) + result);
  v67[1] = *(_BYTE *)((((v71 + v72) >> 18) & 0x3FF) + result);
  v67[2] = *(_BYTE *)(result + (((v72 - v71) >> 18) & 0x3FF));
  v73 = (_BYTE *)(a5 + a4[3]);
  v74 = 4433 * (v93 + v91);
  v75 = (v92 + v90 + 16) << 13;
  v76 = v74 + 6270 * v91;
  v77 = v74 - 15137 * v93;
  *v73 = *(_BYTE *)((((v75 + v76) >> 18) & 0x3FF) + result);
  v73[3] = *(_BYTE *)((((v75 - v76) >> 18) & 0x3FF) + result);
  v78 = (v90 + 16 - v92) << 13;
  v73[1] = *(_BYTE *)((((v77 + v78) >> 18) & 0x3FF) + result);
  v73[2] = *(_BYTE *)(result + (((v78 - v77) >> 18) & 0x3FF));
  return result;
}
