int __cdecl jpeg_idct_8x16(int a1, int a2, int a3, int a4, int a5)
{
  __int16 *v5; // edx
  _DWORD *v6; // ebx
  int *v7; // eax
  int v8; // edi
  int v9; // esi
  int v10; // ecx
  int v11; // ebp
  int v12; // edi
  int v13; // ecx
  int v14; // esi
  int v15; // edi
  int v16; // ecx
  int v17; // ebp
  int v18; // esi
  int v19; // ecx
  int v20; // edi
  int v21; // edx
  int v22; // ebx
  int v23; // esi
  int v24; // esi
  int v25; // ecx
  int v26; // esi
  int v27; // ecx
  int v28; // ebp
  int v29; // edx
  int v30; // esi
  int v31; // ebp
  bool v32; // zf
  int result; // eax
  char *v34; // ecx
  int v35; // esi
  int v36; // ebp
  int v37; // edx
  int v38; // ebx
  int v39; // edi
  int v40; // edx
  int v41; // esi
  int v42; // edx
  int v43; // esi
  int v44; // edx
  int v45; // edi
  int v46; // esi
  int v47; // edx
  int v48; // ebp
  int v49; // ebx
  _BYTE *v50; // eax
  int v51; // edx
  int v52; // ebp
  int v53; // edi
  int v54; // [esp+10h] [ebp-250h]
  int v55; // [esp+10h] [ebp-250h]
  int v56; // [esp+10h] [ebp-250h]
  int v57; // [esp+10h] [ebp-250h]
  int v58; // [esp+14h] [ebp-24Ch]
  int v59; // [esp+14h] [ebp-24Ch]
  int v60; // [esp+14h] [ebp-24Ch]
  int v61; // [esp+18h] [ebp-248h]
  int v62; // [esp+18h] [ebp-248h]
  int v63; // [esp+18h] [ebp-248h]
  int v64; // [esp+18h] [ebp-248h]
  int v65; // [esp+18h] [ebp-248h]
  int v66; // [esp+1Ch] [ebp-244h]
  int v67; // [esp+1Ch] [ebp-244h]
  int v68; // [esp+1Ch] [ebp-244h]
  int v69; // [esp+1Ch] [ebp-244h]
  int v70; // [esp+1Ch] [ebp-244h]
  int v71; // [esp+20h] [ebp-240h]
  int v72; // [esp+20h] [ebp-240h]
  int v73; // [esp+20h] [ebp-240h]
  int v74; // [esp+24h] [ebp-23Ch]
  int v75; // [esp+24h] [ebp-23Ch]
  int v76; // [esp+24h] [ebp-23Ch]
  int v77; // [esp+24h] [ebp-23Ch]
  int v78; // [esp+28h] [ebp-238h]
  int v79; // [esp+28h] [ebp-238h]
  int v80; // [esp+28h] [ebp-238h]
  int v81; // [esp+2Ch] [ebp-234h]
  int v82; // [esp+2Ch] [ebp-234h]
  _DWORD *v83; // [esp+30h] [ebp-230h]
  int v84; // [esp+30h] [ebp-230h]
  int v85; // [esp+34h] [ebp-22Ch]
  int v86; // [esp+34h] [ebp-22Ch]
  int v87; // [esp+34h] [ebp-22Ch]
  int v88; // [esp+38h] [ebp-228h]
  int v89; // [esp+3Ch] [ebp-224h]
  int v90; // [esp+40h] [ebp-220h]
  int v91; // [esp+44h] [ebp-21Ch]
  int v92; // [esp+48h] [ebp-218h]
  int v93; // [esp+4Ch] [ebp-214h]
  int v94; // [esp+50h] [ebp-210h]
  int v95; // [esp+54h] [ebp-20Ch]
  int v96; // [esp+58h] [ebp-208h]
  int v97; // [esp+5Ch] [ebp-204h]
  char v98; // [esp+78h] [ebp-1E8h] BYREF
  char v99; // [esp+80h] [ebp-1E0h] BYREF

  v5 = (__int16 *)(a3 + 32);
  v6 = (_DWORD *)(*(_DWORD *)(a2 + 84) + 64);
  v96 = *(_DWORD *)(a1 + 292) + 128;
  v7 = (int *)&v99;
  v88 = a3 + 32;
  v83 = v6;
  v81 = 8;
  do
  {
    v8 = v6[16] * v5[16];
    v9 = 4433 * v8;
    v8 *= 10703;
    v10 = ((*(v6 - 16) * *(v5 - 16)) << 13) + 1024;
    v78 = v8 + v10;
    v11 = v10 - v8;
    v12 = v9 + v10;
    v13 = v10 - v9;
    v14 = *v6 * *v5;
    v66 = v12;
    v15 = v6[32] * v5[32];
    v85 = v13;
    v74 = v11;
    v61 = 2260 * (v14 - v15);
    v58 = 11363 * (v14 - v15) + 20995 * v15;
    v16 = v61 + 7373 * v14;
    v17 = 11363 * (v14 - v15) - 4926 * v14;
    v71 = v61 - 4176 * v15;
    v93 = v78 + v58;
    v94 = v78 - v58;
    v92 = v66 - v16;
    v90 = v85 - v17;
    v95 = v85 + v17;
    v91 = v66 + v16;
    v18 = *(v6 - 8) * *(v5 - 8);
    v97 = v74 - v71;
    v19 = v6[8] * v5[8];
    v89 = v71 + v74;
    v20 = v6[24] * v5[24];
    v21 = v6[40] * v5[40];
    v62 = 11086 * (v19 + v18);
    v54 = 10217 * (v20 + v18);
    v72 = 8956 * (v21 + v18);
    v75 = 5461 * (v20 + v18);
    v79 = 7350 * (v18 - v21);
    v67 = 3363 * (v18 - v19);
    v22 = v62 + v54 + v72 - 18730 * v18;
    v86 = v79 + v75 + v67 - 15038 * v18;
    v23 = 1136 * (v20 + v19);
    v63 = v23 + 589 * v19 + v62;
    v55 = v23 - 9222 * v20 + v54;
    v59 = 11529 * (v20 - v19);
    v76 = v59 - 6278 * v20 + v75;
    v68 = v59 + 16154 * v19 + v67;
    v24 = v21 + v19;
    v25 = -10217 * (v21 + v19);
    v69 = v25 + v68;
    v24 *= -5461;
    v64 = v24 + v63;
    v60 = v24;
    v26 = v25 + 25733 * v21 + v79;
    v27 = -11086 * (v21 + v20);
    v56 = v27 + v55;
    v28 = 8728 * v21;
    v29 = 3363 * (v21 - v20);
    v30 = v29 + v26;
    v31 = v60 + v27 + v28 + v72;
    *(v7 - 8) = (v93 + v22) >> 11;
    v7[112] = (v93 - v22) >> 11;
    v7[104] = (v91 - v64) >> 11;
    *v7 = (v91 + v64) >> 11;
    v7[96] = (v95 - v56) >> 11;
    v7[88] = (v89 - v31) >> 11;
    v7[16] = (v89 + v31) >> 11;
    v7[80] = (v97 - v30) >> 11;
    v7[24] = (v97 + v30) >> 11;
    v7[72] = (v90 - (v29 + v76)) >> 11;
    v7[32] = (v90 + v29 + v76) >> 11;
    v7[64] = (v92 - v69) >> 11;
    v7[40] = (v92 + v69) >> 11;
    v7[8] = (v95 + v56) >> 11;
    v7[48] = (v94 + v86) >> 11;
    v7[56] = (v94 - v86) >> 11;
    v5 = (__int16 *)(v88 + 2);
    v6 = v83 + 1;
    ++v7;
    v32 = v81-- == 1;
    v88 += 2;
    ++v83;
  }
  while ( !v32 );
  result = 0;
  v84 = 0;
  v34 = &v98;
  do
  {
    v35 = *((_DWORD *)v34 - 4);
    v36 = *((_DWORD *)v34 - 2);
    v37 = 4433 * (*(_DWORD *)v34 + v35);
    v38 = v37 + 6270 * v35;
    v39 = v37 - 15137 * *(_DWORD *)v34;
    v40 = *((_DWORD *)v34 - 6) + 16;
    v41 = (v40 + v36) << 13;
    v80 = v38 + v41;
    v87 = v41 - v38;
    v42 = (v40 - v36) << 13;
    v43 = v39 + v42;
    v44 = v42 - v39;
    v45 = *((_DWORD *)v34 - 3);
    v73 = *((_DWORD *)v34 - 5);
    v77 = v43;
    v46 = *((_DWORD *)v34 - 1);
    v70 = v44;
    v47 = *((_DWORD *)v34 + 1);
    v82 = 9633 * (v45 + v47 + v46 + v73) - 16069 * (v45 + v47);
    v57 = 9633 * (v45 + v47 + v46 + v73) - 3196 * (v46 + v73);
    v48 = -7373 * (v73 + v47);
    v49 = v48 + v57 + 12299 * v73;
    v50 = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * result));
    v51 = v48 + v82 + 2446 * v47;
    v52 = -20995 * (v45 + v46);
    v65 = v52 + v57 + 16819 * v46;
    v53 = v52 + v82 + 25172 * v45;
    *v50 = *(_BYTE *)((((v80 + v49) >> 18) & 0x3FF) + v96);
    v50[7] = *(_BYTE *)((((v80 - v49) >> 18) & 0x3FF) + v96);
    v50[1] = *(_BYTE *)((((v77 + v53) >> 18) & 0x3FF) + v96);
    v50[6] = *(_BYTE *)((((v77 - v53) >> 18) & 0x3FF) + v96);
    v50[2] = *(_BYTE *)((((v70 + v65) >> 18) & 0x3FF) + v96);
    v50[5] = *(_BYTE *)((((v70 - v65) >> 18) & 0x3FF) + v96);
    v50[3] = *(_BYTE *)((((v87 + v51) >> 18) & 0x3FF) + v96);
    v50[4] = *(_BYTE *)((((v87 - v51) >> 18) & 0x3FF) + v96);
    result = v84 + 1;
    v34 += 32;
    ++v84;
  }
  while ( v84 < 16 );
  return result;
}
