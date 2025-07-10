char __cdecl jpeg_idct_5x5(int a1, int a2, __int16 *a3, _DWORD *a4, int a5)
{
  _DWORD *v6; // ecx
  int v7; // ebx
  int v8; // edi
  int v9; // ebp
  int v11; // esi
  int v12; // edi
  int v13; // ebx
  int v14; // ebp
  int v15; // edi
  int v16; // esi
  int v17; // ebx
  int v18; // ebp
  int v19; // edi
  int v20; // eax
  int v21; // edi
  int v22; // esi
  int v23; // ebx
  int v24; // ebp
  int v25; // esi
  int v26; // esi
  int v27; // edi
  int v28; // ebp
  int v29; // ebx
  int v30; // esi
  int v31; // edi
  int v32; // ebp
  int v33; // esi
  int v34; // edi
  int v35; // ebx
  int v36; // ebp
  int v37; // esi
  int v38; // esi
  int v39; // ebx
  int v40; // ebp
  int v41; // ebp
  int v42; // ebx
  int v43; // esi
  int v44; // ebx
  int v45; // ebp
  int v46; // esi
  int v47; // ebx
  int v48; // edx
  int v49; // ecx
  int v50; // ebx
  int v51; // ecx
  int v52; // ebx
  int v53; // edx
  int v54; // ebx
  int v55; // ecx
  int v56; // esi
  int v57; // edi
  int v58; // edx
  _BYTE *v59; // ebp
  int v60; // edx
  _BYTE *v61; // edi
  int v62; // ecx
  int v63; // ebx
  int v64; // edx
  int v65; // esi
  int v66; // ebp
  int v67; // edx
  int v68; // edx
  int v69; // ebx
  int v70; // edx
  int v71; // ecx
  int v72; // esi
  int v73; // ebp
  int v74; // edx
  _BYTE *v75; // edi
  int v76; // edx
  int v77; // ebx
  int v78; // edx
  int v79; // ecx
  int v80; // edi
  int v81; // ebp
  int v82; // edx
  _BYTE *v83; // esi
  int v84; // edx
  _BYTE *v85; // esi
  int v86; // ecx
  int v87; // ebx
  int v88; // edx
  int v89; // edi
  int v90; // ebp
  int v91; // edx
  int v92; // edx
  char result; // al
  int v94; // [esp+10h] [ebp-68h]
  int v95; // [esp+10h] [ebp-68h]
  int v96; // [esp+10h] [ebp-68h]
  int v97; // [esp+10h] [ebp-68h]
  int v98; // [esp+14h] [ebp-64h]
  int v99; // [esp+18h] [ebp-60h]
  int v100; // [esp+20h] [ebp-58h]
  int v101; // [esp+28h] [ebp-50h]
  int v102; // [esp+2Ch] [ebp-4Ch]
  int v103; // [esp+30h] [ebp-48h]
  int v104; // [esp+34h] [ebp-44h]
  int v105; // [esp+38h] [ebp-40h]
  int v106; // [esp+3Ch] [ebp-3Ch]
  int v107; // [esp+40h] [ebp-38h]
  int v108; // [esp+44h] [ebp-34h]
  int v109; // [esp+48h] [ebp-30h]
  int v110; // [esp+4Ch] [ebp-2Ch]
  int v111; // [esp+50h] [ebp-28h]
  int v112; // [esp+54h] [ebp-24h]
  int v113; // [esp+58h] [ebp-20h]
  int v114; // [esp+5Ch] [ebp-1Ch]
  int v115; // [esp+60h] [ebp-18h]
  int v116; // [esp+64h] [ebp-14h]
  int v117; // [esp+68h] [ebp-10h]
  int v118; // [esp+6Ch] [ebp-Ch]
  int v119; // [esp+70h] [ebp-8h]
  int v120; // [esp+74h] [ebp-4h]
  int v121; // [esp+7Ch] [ebp+4h]
  int v122; // [esp+7Ch] [ebp+4h]
  int v123; // [esp+7Ch] [ebp+4h]
  int v124; // [esp+7Ch] [ebp+4h]
  int v125; // [esp+7Ch] [ebp+4h]
  int v126; // [esp+7Ch] [ebp+4h]
  int v127; // [esp+7Ch] [ebp+4h]
  int v128; // [esp+7Ch] [ebp+4h]
  int v129; // [esp+7Ch] [ebp+4h]
  int v130; // [esp+7Ch] [ebp+4h]
  int v131; // [esp+7Ch] [ebp+4h]
  int v132; // [esp+7Ch] [ebp+4h]
  int v133; // [esp+80h] [ebp+8h]
  int v134; // [esp+80h] [ebp+8h]
  int v135; // [esp+80h] [ebp+8h]
  int v136; // [esp+80h] [ebp+8h]
  int v137; // [esp+80h] [ebp+8h]
  int v138; // [esp+80h] [ebp+8h]
  int v139; // [esp+84h] [ebp+Ch]
  int v140; // [esp+84h] [ebp+Ch]
  int v141; // [esp+84h] [ebp+Ch]
  int v142; // [esp+84h] [ebp+Ch]
  int v143; // [esp+84h] [ebp+Ch]

  v6 = *(_DWORD **)(a2 + 84);
  v7 = v6[32] * a3[32];
  v8 = v6[16] * a3[16];
  v9 = 6476 * (v7 + v8);
  v121 = 2896 * (v8 - v7);
  v11 = ((*v6 * *a3) << 13) + 1024;
  v139 = v121 + v11 + v9;
  v12 = v6[8] * a3[8];
  v94 = v121 + v11 - v9;
  v13 = v6[24] * a3[24];
  v14 = 6810 * (v13 + v12);
  v15 = v14 + 4209 * v12;
  v133 = v14 - 17828 * v13;
  v116 = (v139 - v15) >> 11;
  v98 = (v139 + v15) >> 11;
  v106 = (v11 - 4 * v121) >> 11;
  v16 = v6[17] * a3[17];
  v101 = (v94 + v133) >> 11;
  v17 = v6[33] * a3[33];
  v111 = (v94 - v133) >> 11;
  v18 = 6476 * (v17 + v16);
  v19 = ((v6[1] * a3[1]) << 13) + 1024;
  v122 = 2896 * (v16 - v17);
  v140 = v122 + v19 + v18;
  v20 = *(_DWORD *)(a1 + 292) + 128;
  v95 = v122 + v19 - v18;
  v21 = v19 - 11584 * (v16 - v17);
  v22 = v6[9] * a3[9];
  v23 = v6[25] * a3[25];
  v24 = 6810 * (v23 + v22);
  v25 = v24 + 4209 * v22;
  v134 = v24 - 17828 * v23;
  v99 = (v140 + v25) >> 11;
  v117 = (v140 - v25) >> 11;
  v112 = (v95 - v134) >> 11;
  v26 = v6[18] * a3[18];
  v107 = v21 >> 11;
  v27 = v6[34] * a3[34];
  v28 = 6476 * (v27 + v26);
  v102 = (v95 + v134) >> 11;
  v123 = 2896 * (v26 - v27);
  v29 = ((v6[2] * a3[2]) << 13) + 1024;
  v141 = v123 + v29 + v28;
  v30 = v6[10] * a3[10];
  v96 = v123 + v29 - v28;
  v31 = v6[26] * a3[26];
  v32 = 6810 * (v31 + v30);
  v33 = v32 + 4209 * v30;
  v135 = v32 - 17828 * v31;
  v118 = (v141 - v33) >> 11;
  v113 = (v96 - v135) >> 11;
  v34 = (v33 + v141) >> 11;
  v103 = (v96 + v135) >> 11;
  v108 = (v29 - 4 * v123) >> 11;
  v35 = v6[19] * a3[19];
  v136 = v6[35] * a3[35];
  v36 = 6476 * (v35 + v136);
  v124 = 2896 * (v35 - v136);
  v37 = ((v6[3] * a3[3]) << 13) + 1024;
  v142 = v36 + v37 + v124;
  v97 = v37 + v124 - v36;
  v38 = v37 - 11584 * (v35 - v136);
  v39 = v6[11] * a3[11];
  v137 = v6[27] * a3[27];
  v40 = 6810 * (v39 + v137);
  v125 = v40 + 4209 * v39;
  v138 = v40 - 17828 * v137;
  v119 = (v142 - v125) >> 11;
  v100 = (v142 + v125) >> 11;
  v104 = (v97 + v138) >> 11;
  v41 = v6[36] * a3[36];
  v114 = (v97 - v138) >> 11;
  v42 = v6[20] * a3[20];
  v109 = v38 >> 11;
  v126 = 2896 * (v42 - v41);
  v43 = ((v6[4] * a3[4]) << 13) + 1024;
  v44 = 6476 * (v42 + v41);
  v143 = v44 + v126 + v43;
  v45 = v126 + v43 - v44;
  v46 = v43 - 4 * v126;
  v47 = v6[12] * a3[12];
  v48 = v6[28] * a3[28];
  v49 = 6810 * (v48 + v47);
  v50 = v49 + 4209 * v47;
  v51 = v49 - 17828 * v48;
  v127 = v50;
  v52 = (v143 + v50) >> 11;
  v120 = (v143 - v127) >> 11;
  v105 = (v51 + v45) >> 11;
  v115 = (v45 - v51) >> 11;
  v53 = 6476 * (v52 + v34);
  v54 = 2896 * (v34 - v52);
  v55 = (v98 + 16) << 13;
  v110 = v46 >> 11;
  v56 = v54 + v55 + v53;
  v57 = v54 + v55 - v53;
  v58 = 6810 * (v99 + v100);
  v59 = (_BYTE *)(a5 + *a4);
  v128 = v58 + 4209 * v99;
  v60 = v58 - 17828 * v100;
  *v59 = *(_BYTE *)((((v56 + v128) >> 18) & 0x3FF) + v20);
  v59[4] = *(_BYTE *)((((v56 - v128) >> 18) & 0x3FF) + v20);
  v59[1] = *(_BYTE *)((((v57 + v60) >> 18) & 0x3FF) + v20);
  v59[3] = *(_BYTE *)((((v57 - v60) >> 18) & 0x3FF) + v20);
  v59[2] = *(_BYTE *)((((v55 - 4 * v54) >> 18) & 0x3FF) + v20);
  v61 = (_BYTE *)(a5 + a4[1]);
  v62 = (v101 + 16) << 13;
  v63 = 6476 * (v105 + v103);
  v64 = 2896 * (v103 - v105);
  v65 = v63 + v64 + v62;
  v66 = v64 + v62 - v63;
  v67 = 6810 * (v102 + v104);
  v129 = v67 + 4209 * v102;
  v68 = v67 - 17828 * v104;
  *v61 = *(_BYTE *)((((v65 + v129) >> 18) & 0x3FF) + v20);
  v61[4] = *(_BYTE *)((((v65 - v129) >> 18) & 0x3FF) + v20);
  v61[1] = *(_BYTE *)((((v68 + v66) >> 18) & 0x3FF) + v20);
  v61[3] = *(_BYTE *)(v20 + (((v66 - v68) >> 18) & 0x3FF));
  v61[2] = *(_BYTE *)((((v62 - 11584 * (v103 - v105)) >> 18) & 0x3FF) + v20);
  v69 = 6476 * (v110 + v108);
  v70 = 2896 * (v108 - v110);
  v71 = (v106 + 16) << 13;
  v72 = v69 + v70 + v71;
  v73 = v70 + v71 - v69;
  v74 = 6810 * (v107 + v109);
  v75 = (_BYTE *)(a5 + a4[2]);
  v130 = v74 + 4209 * v107;
  v76 = v74 - 17828 * v109;
  *v75 = *(_BYTE *)((((v72 + v130) >> 18) & 0x3FF) + v20);
  v75[4] = *(_BYTE *)((((v72 - v130) >> 18) & 0x3FF) + v20);
  v75[1] = *(_BYTE *)((((v76 + v73) >> 18) & 0x3FF) + v20);
  v75[3] = *(_BYTE *)(v20 + (((v73 - v76) >> 18) & 0x3FF));
  v75[2] = *(_BYTE *)((((v71 - 11584 * (v108 - v110)) >> 18) & 0x3FF) + v20);
  v77 = 6476 * (v115 + v113);
  v78 = 2896 * (v113 - v115);
  v79 = (v111 + 16) << 13;
  v80 = v77 + v78 + v79;
  v81 = v78 + v79 - v77;
  v82 = 6810 * (v112 + v114);
  v83 = (_BYTE *)(a5 + a4[3]);
  v131 = v82 + 4209 * v112;
  v84 = v82 - 17828 * v114;
  *v83 = *(_BYTE *)((((v80 + v131) >> 18) & 0x3FF) + v20);
  v83[4] = *(_BYTE *)((((v80 - v131) >> 18) & 0x3FF) + v20);
  v83[1] = *(_BYTE *)((((v84 + v81) >> 18) & 0x3FF) + v20);
  v83[3] = *(_BYTE *)(v20 + (((v81 - v84) >> 18) & 0x3FF));
  v83[2] = *(_BYTE *)((((v79 - 11584 * (v113 - v115)) >> 18) & 0x3FF) + v20);
  v85 = (_BYTE *)(a5 + a4[4]);
  v86 = (v116 + 16) << 13;
  v87 = 6476 * (v120 + v118);
  v88 = 2896 * (v118 - v120);
  v89 = v87 + v88 + v86;
  v90 = v88 + v86 - v87;
  v91 = 6810 * (v117 + v119);
  v132 = v91 + 4209 * v117;
  v92 = v91 - 17828 * v119;
  *v85 = *(_BYTE *)((((v89 + v132) >> 18) & 0x3FF) + v20);
  v85[4] = *(_BYTE *)((((v89 - v132) >> 18) & 0x3FF) + v20);
  v85[1] = *(_BYTE *)((((v92 + v90) >> 18) & 0x3FF) + v20);
  v85[3] = *(_BYTE *)(v20 + (((v90 - v92) >> 18) & 0x3FF));
  result = *(_BYTE *)((((v86 - 11584 * (v118 - v120)) >> 18) & 0x3FF) + v20);
  v85[2] = result;
  return result;
}
