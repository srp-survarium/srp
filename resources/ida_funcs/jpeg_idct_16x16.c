int __cdecl jpeg_idct_16x16(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // ecx
  __int16 *v6; // esi
  _DWORD *v7; // ebx
  int *v8; // eax
  int v9; // ebp
  int v10; // edi
  int v11; // edx
  int v12; // ebp
  int v13; // edx
  int v14; // edi
  int v15; // edx
  int v16; // edi
  int v17; // ebp
  int v18; // edx
  int v19; // esi
  int v20; // ebp
  int v21; // ebx
  int v22; // edi
  int v23; // edi
  int v24; // edx
  int v25; // edi
  int v26; // edx
  int v27; // ebp
  int v28; // edx
  int v29; // edi
  bool v30; // zf
  int result; // eax
  _DWORD *v32; // ebp
  int v33; // edi
  int v34; // esi
  int v35; // edx
  int v36; // ebx
  int v37; // esi
  int v38; // edi
  int v39; // edx
  int v40; // ebx
  int v41; // edx
  int v42; // edi
  int v43; // ebx
  int v44; // edx
  int v45; // edi
  int v46; // esi
  _BYTE *v47; // eax
  int v48; // edi
  int v49; // edi
  int v50; // edx
  int v51; // edi
  int v52; // edx
  int v53; // esi
  int v54; // edi
  bool v55; // cc
  int v56; // [esp+10h] [ebp-254h]
  int v57; // [esp+10h] [ebp-254h]
  int v58; // [esp+10h] [ebp-254h]
  int v59; // [esp+10h] [ebp-254h]
  int v60; // [esp+10h] [ebp-254h]
  int v61; // [esp+10h] [ebp-254h]
  int v62; // [esp+14h] [ebp-250h]
  int v63; // [esp+14h] [ebp-250h]
  int v64; // [esp+14h] [ebp-250h]
  int v65; // [esp+14h] [ebp-250h]
  int v66; // [esp+14h] [ebp-250h]
  int v67; // [esp+14h] [ebp-250h]
  int v68; // [esp+14h] [ebp-250h]
  int v69; // [esp+14h] [ebp-250h]
  int v70; // [esp+18h] [ebp-24Ch]
  int v71; // [esp+18h] [ebp-24Ch]
  int v72; // [esp+18h] [ebp-24Ch]
  int v73; // [esp+18h] [ebp-24Ch]
  int v74; // [esp+18h] [ebp-24Ch]
  int v75; // [esp+18h] [ebp-24Ch]
  int v76; // [esp+18h] [ebp-24Ch]
  int v77; // [esp+1Ch] [ebp-248h]
  int v78; // [esp+1Ch] [ebp-248h]
  int v79; // [esp+1Ch] [ebp-248h]
  int v80; // [esp+1Ch] [ebp-248h]
  int v81; // [esp+1Ch] [ebp-248h]
  int v82; // [esp+1Ch] [ebp-248h]
  int v83; // [esp+1Ch] [ebp-248h]
  int v84; // [esp+20h] [ebp-244h]
  int v85; // [esp+20h] [ebp-244h]
  int v86; // [esp+24h] [ebp-240h]
  int v87; // [esp+24h] [ebp-240h]
  int v88; // [esp+24h] [ebp-240h]
  int v89; // [esp+24h] [ebp-240h]
  int v90; // [esp+28h] [ebp-23Ch]
  int v91; // [esp+28h] [ebp-23Ch]
  int v92; // [esp+28h] [ebp-23Ch]
  int v93; // [esp+28h] [ebp-23Ch]
  int v94; // [esp+28h] [ebp-23Ch]
  int v95; // [esp+2Ch] [ebp-238h]
  int v96; // [esp+2Ch] [ebp-238h]
  int v97; // [esp+2Ch] [ebp-238h]
  int v98; // [esp+2Ch] [ebp-238h]
  int v99; // [esp+30h] [ebp-234h]
  int v100; // [esp+30h] [ebp-234h]
  int v101; // [esp+30h] [ebp-234h]
  int v102; // [esp+34h] [ebp-230h]
  int v103; // [esp+34h] [ebp-230h]
  int v104; // [esp+34h] [ebp-230h]
  int v105; // [esp+34h] [ebp-230h]
  int v106; // [esp+38h] [ebp-22Ch]
  int v107; // [esp+38h] [ebp-22Ch]
  int v108; // [esp+38h] [ebp-22Ch]
  int v109; // [esp+3Ch] [ebp-228h]
  _BYTE *v110; // [esp+3Ch] [ebp-228h]
  _DWORD *v111; // [esp+40h] [ebp-224h]
  int v112; // [esp+40h] [ebp-224h]
  int v113; // [esp+44h] [ebp-220h]
  int v114; // [esp+44h] [ebp-220h]
  int v115; // [esp+48h] [ebp-21Ch]
  int v116; // [esp+48h] [ebp-21Ch]
  int v117; // [esp+4Ch] [ebp-218h]
  int v118; // [esp+4Ch] [ebp-218h]
  int v119; // [esp+50h] [ebp-214h]
  int v120; // [esp+50h] [ebp-214h]
  int v121; // [esp+54h] [ebp-210h]
  int v122; // [esp+54h] [ebp-210h]
  int v123; // [esp+58h] [ebp-20Ch]
  int v124; // [esp+58h] [ebp-20Ch]
  int v125; // [esp+5Ch] [ebp-208h]
  int v126; // [esp+5Ch] [ebp-208h]
  int v127; // [esp+60h] [ebp-204h]
  _BYTE v128[24]; // [esp+6Ch] [ebp-1F8h] BYREF
  char v129; // [esp+84h] [ebp-1E0h] BYREF

  v5 = *(_DWORD *)(a1 + 292) + 128;
  v6 = (__int16 *)(a3 + 32);
  v7 = (_DWORD *)(*(_DWORD *)(a2 + 84) + 64);
  v8 = (int *)&v129;
  v127 = a3 + 32;
  v111 = v7;
  v109 = 8;
  do
  {
    v9 = v7[16] * v6[16];
    v10 = 4433 * v9;
    v11 = ((*(v7 - 16) * *(v6 - 16)) << 13) + 1024;
    v95 = v11 + 10703 * v9;
    v90 = v11 - 10703 * v9;
    v12 = 4433 * v9 + v11;
    v13 = v11 - v10;
    v14 = *v7 * *v6;
    v62 = v7[32] * v6[32];
    v102 = v13;
    v99 = 11363 * (v14 - v62) + 20995 * v62;
    v106 = 2260 * (v14 - v62);
    v15 = v106 + 7373 * v14;
    v77 = 11363 * (v14 - v62) - 4926 * v14;
    v63 = v106 - 4176 * v62;
    v113 = v95 + v99;
    v107 = v95 - v99;
    v123 = v12 - v15;
    v115 = v12 + v15;
    v121 = v102 - v77;
    v125 = v102 + v77;
    v16 = *(v7 - 8) * *(v6 - 8);
    v119 = v63 + v90;
    v17 = v7[24] * v6[24];
    v117 = v90 - v63;
    v18 = v7[8] * v6[8];
    v19 = v7[40] * v6[40];
    v84 = v17;
    v56 = 11086 * (v18 + v16);
    v78 = 10217 * (v16 + v17);
    v64 = 8956 * (v19 + v16);
    v91 = 5461 * (v16 + v17);
    v96 = 7350 * (v16 - v19);
    v70 = 3363 * (v16 - v18);
    v20 = v91 + v70 - 15038 * v16;
    v21 = v56 + v78 + v64 - 18730 * v16;
    v22 = 1136 * (v18 + v84);
    v103 = v96 + v20;
    v57 = v22 + 589 * v18 + v56;
    v79 = v22 - 9222 * v84 + v78;
    v86 = 11529 * (v84 - v18);
    v92 = v86 - 6278 * v84 + v91;
    v71 = v86 + 16154 * v18 + v70;
    v23 = v19 + v18;
    v24 = -10217 * (v19 + v18);
    v72 = v24 + v71;
    v23 *= -5461;
    v58 = v23 + v57;
    v87 = v23;
    v25 = v24 + 25733 * v19 + v96;
    v26 = -11086 * (v19 + v84);
    v80 = v26 + v79;
    v27 = v87 + v26 + 8728 * v19;
    v28 = 3363 * (v19 - v84);
    v65 = v27 + v64;
    v29 = v28 + v25;
    v8[112] = (v113 - v21) >> 11;
    *(v8 - 8) = (v113 + v21) >> 11;
    v8[104] = (v115 - v58) >> 11;
    *v8 = (v115 + v58) >> 11;
    v8[96] = (v125 - v80) >> 11;
    v8[8] = (v125 + v80) >> 11;
    v8[88] = (v119 - v65) >> 11;
    v8[80] = (v117 - v29) >> 11;
    v8[72] = (v121 - (v28 + v92)) >> 11;
    v8[32] = (v121 + v28 + v92) >> 11;
    v8[64] = (v123 - v72) >> 11;
    v8[40] = (v123 + v72) >> 11;
    v8[24] = (v117 + v29) >> 11;
    v8[16] = (v119 + v65) >> 11;
    v8[48] = (v107 + v103) >> 11;
    v8[56] = (v107 - v103) >> 11;
    v6 = (__int16 *)(v127 + 2);
    v7 = v111 + 1;
    ++v8;
    v30 = v109-- == 1;
    v127 += 2;
    ++v111;
  }
  while ( !v30 );
  result = 0;
  v32 = v128;
  v112 = 0;
  v110 = v128;
  do
  {
    v33 = v32[2];
    v34 = 4433 * v33;
    v33 *= 10703;
    v35 = (*(v32 - 2) + 16) << 13;
    v36 = v34;
    v97 = v33 + v35;
    v37 = v35 - v33;
    v73 = v36 + v35;
    v66 = v32[4];
    v104 = v35 - v36;
    v38 = 11363 * (*v32 - v66);
    v39 = 2260 * (*v32 - v66);
    v100 = v38 + 20995 * v66;
    v40 = v38 - 4926 * *v32;
    v67 = v39 - 4176 * v66;
    v114 = v97 + v100;
    v108 = v97 - v100;
    v116 = v73 + v39 + 7373 * *v32;
    v124 = v73 - (v39 + 7373 * *v32);
    v41 = v104 + v40;
    v42 = v104 - v40;
    v43 = v32[3];
    v126 = v41;
    v122 = v42;
    v44 = v32[1];
    v120 = v67 + v37;
    v45 = *(v32 - 1);
    v118 = v37 - v67;
    v46 = v32[5];
    v59 = 11086 * (v44 + v45);
    v47 = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * result));
    v81 = 10217 * (v43 + v45);
    v68 = 8956 * (v46 + v45);
    v98 = 7350 * (v45 - v46);
    v74 = 3363 * (v45 - v44);
    v93 = 5461 * (v43 + v45);
    v101 = v59 + v81 + v68 - 18730 * v45;
    v85 = *((_DWORD *)v110 + 3);
    v105 = v98 + v93 + v74 - 15038 * v45;
    v48 = 1136 * (v44 + v85);
    v60 = v48 + 589 * v44 + v59;
    v82 = v48 - 9222 * v85 + v81;
    v88 = 11529 * (v85 - v44);
    v94 = v88 - 6278 * v85 + v93;
    v75 = v88 + 16154 * v44 + v74;
    v49 = v46 + v44;
    v50 = -10217 * (v46 + v44);
    v76 = v50 + v75;
    v49 *= -5461;
    v61 = v49 + v60;
    v89 = v49;
    v51 = v50 + 25733 * v46 + v98;
    v52 = -11086 * (v46 + v85);
    v83 = v52 + v82;
    v53 = 3363 * (v46 - v85);
    v69 = v89 + v52 + 8728 * v32[5] + v68;
    v54 = v53 + v51;
    *v47 = *(_BYTE *)((((v114 + v101) >> 18) & 0x3FF) + v5);
    v47[15] = *(_BYTE *)((((v114 - v101) >> 18) & 0x3FF) + v5);
    v47[1] = *(_BYTE *)((((v116 + v61) >> 18) & 0x3FF) + v5);
    v47[14] = *(_BYTE *)((((v116 - v61) >> 18) & 0x3FF) + v5);
    v47[2] = *(_BYTE *)((((v126 + v83) >> 18) & 0x3FF) + v5);
    v47[13] = *(_BYTE *)((((v126 - v83) >> 18) & 0x3FF) + v5);
    v47[3] = *(_BYTE *)((((v120 + v69) >> 18) & 0x3FF) + v5);
    v47[12] = *(_BYTE *)((((v120 - v69) >> 18) & 0x3FF) + v5);
    v47[4] = *(_BYTE *)((((v118 + v54) >> 18) & 0x3FF) + v5);
    v47[11] = *(_BYTE *)((((v118 - v54) >> 18) & 0x3FF) + v5);
    v47[5] = *(_BYTE *)((((v122 + v53 + v94) >> 18) & 0x3FF) + v5);
    v47[10] = *(_BYTE *)((((v122 - (v53 + v94)) >> 18) & 0x3FF) + v5);
    v47[6] = *(_BYTE *)((((v124 + v76) >> 18) & 0x3FF) + v5);
    v47[9] = *(_BYTE *)((((v124 - v76) >> 18) & 0x3FF) + v5);
    v47[7] = *(_BYTE *)((((v108 + v105) >> 18) & 0x3FF) + v5);
    v47[8] = *(_BYTE *)((((v108 - v105) >> 18) & 0x3FF) + v5);
    result = v112 + 1;
    v32 = v110 + 32;
    v55 = v112 + 1 < 16;
    v110 += 32;
    ++v112;
  }
  while ( v55 );
  return result;
}
