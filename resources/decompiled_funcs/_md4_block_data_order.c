void __cdecl md4_block_data_order(MD4state_st *c, unsigned __int8 *data_, unsigned int num)
{
  unsigned int B; // ebx
  unsigned int v5; // ebp
  unsigned int D; // esi
  int v7; // ecx
  int v8; // edx
  unsigned __int8 *v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // edx
  int v14; // edi
  int v15; // ecx
  int v16; // ecx
  int v17; // edx
  int v18; // ecx
  int v19; // edx
  int v20; // ecx
  int v21; // edx
  unsigned int v22; // ecx
  int v23; // edx
  int v24; // edi
  int v25; // ecx
  int v26; // edi
  unsigned int v27; // edx
  int v28; // esi
  int v29; // esi
  int v30; // edi
  int v31; // edx
  int v32; // edi
  int v33; // edi
  int v34; // esi
  int v35; // ebp
  unsigned int v36; // edi
  int v37; // ebx
  int v38; // ebp
  int v39; // edi
  int v40; // ebp
  int v41; // ebx
  int v42; // ecx
  int v43; // ecx
  int v44; // ebp
  int v45; // ebx
  int v46; // ebp
  int v47; // ecx
  int v48; // edx
  int v49; // edx
  int v50; // ebp
  int v51; // ecx
  int v52; // edx
  int v53; // ebp
  int v54; // edx
  int v55; // esi
  int v56; // ebp
  int v57; // edx
  int v58; // ebp
  int v59; // esi
  int v60; // edi
  int v61; // ebp
  int v62; // esi
  int v63; // ebp
  int v64; // edi
  int v65; // ebx
  int v66; // ebx
  int v67; // ebp
  int v68; // edi
  int v69; // ebp
  int v70; // ebx
  int v71; // ecx
  int v72; // ebx
  int v73; // ebp
  int v74; // ecx
  int v75; // edx
  int v76; // ecx
  int v77; // edx
  int v78; // esi
  int v79; // esi
  int v80; // edx
  int v81; // ebp
  int v82; // esi
  int v83; // edi
  int v84; // edi
  int v85; // ebp
  int v86; // edi
  int v87; // esi
  int v88; // edi
  int v89; // edi
  int v90; // ebp
  int v91; // edi
  int v92; // ecx
  int v93; // esi
  int v94; // ebp
  int v95; // edi
  int v96; // ecx
  int v97; // esi
  int v98; // ebx
  int v99; // edx
  int v100; // edi
  int v101; // esi
  int v102; // ecx
  int v103; // edi
  int v104; // esi
  int v105; // ebx
  int v106; // ecx
  int v107; // edi
  int v108; // esi
  int v109; // ebx
  int v110; // ecx
  int v111; // edi
  int v112; // edx
  int v113; // ebx
  int v114; // ebp
  int v115; // esi
  int v116; // ecx
  int v117; // edi
  int v118; // ebx
  int v119; // esi
  int v120; // edx
  int v121; // edi
  int v122; // ebp
  int v123; // esi
  unsigned int A; // edx
  int v125; // [esp+Ch] [ebp-48h]
  int v126; // [esp+10h] [ebp-44h]
  int v127; // [esp+14h] [ebp-40h]
  int v128; // [esp+18h] [ebp-3Ch]
  int v129; // [esp+1Ch] [ebp-38h]
  int v130; // [esp+20h] [ebp-34h]
  int v131; // [esp+24h] [ebp-30h]
  int v132; // [esp+28h] [ebp-2Ch]
  int v133; // [esp+2Ch] [ebp-28h]
  int v134; // [esp+30h] [ebp-24h]
  int v135; // [esp+34h] [ebp-20h]
  int v136; // [esp+38h] [ebp-1Ch]
  int v137; // [esp+3Ch] [ebp-18h]
  int v138; // [esp+40h] [ebp-14h]
  int v139; // [esp+44h] [ebp-10h]
  int v140; // [esp+48h] [ebp-Ch]
  int v141; // [esp+4Ch] [ebp-8h]
  unsigned int i; // [esp+5Ch] [ebp+8h]

  B = c->B;
  v5 = c->C;
  D = c->D;
  for ( i = c->A; num; i = A )
  {
    v7 = *data_;
    v8 = data_[1];
    v9 = data_ + 1;
    v10 = (v8 << 8) | v7;
    v11 = *++v9;
    v12 = (v9[1] << 24) | (v11 << 16) | v10;
    v9 += 2;
    v13 = v9[1];
    v14 = v12;
    v15 = *v9++;
    v16 = (v13 << 8) | v15;
    v17 = *++v9;
    v18 = (v17 << 16) | v16;
    v19 = *++v9;
    v20 = (v19 << 24) | v18;
    v21 = v9[1];
    v133 = v20;
    v141 = v14;
    v9 += 2;
    --num;
    v22 = v14 + (D ^ B & (v5 ^ D));
    v23 = (*v9 << 8) | v21;
    v24 = *++v9;
    v129 = (v9[1] << 24) | (v24 << 16) | v23;
    v25 = __ROL4__(i + v22, 3);
    v9 += 2;
    v26 = v9[1];
    v27 = D + v133 + (v5 ^ v25 & (B ^ v5));
    v28 = *v9++;
    v29 = (v26 << 8) | v28;
    v30 = *++v9;
    v137 = (v9[1] << 24) | (v30 << 16) | v29;
    v31 = __ROL4__(v27, 7);
    v9 += 2;
    v32 = *(unsigned __int16 *)v9++;
    v33 = (*++v9 << 16) | v32;
    v127 = (v9[1] << 24) | v33;
    v34 = __ROL4__(v5 + v129 + (B ^ v31 & (v25 ^ B)), 11);
    v9 += 2;
    v35 = *++v9;
    v36 = B + v137 + (v25 ^ v34 & (v25 ^ v31));
    v37 = (v35 << 8) | *(v9 - 1);
    v38 = *++v9;
    v135 = (v9[1] << 24) | (v38 << 16) | v37;
    v39 = __ROL4__(v36, 19);
    v9 += 2;
    v40 = v9[1];
    v41 = v25 + v127 + (v31 ^ v39 & (v34 ^ v31));
    v42 = *v9++;
    v43 = (v40 << 8) | v42;
    v44 = *++v9;
    v131 = (v9[1] << 24) | (v44 << 16) | v43;
    v45 = __ROL4__(v41, 3);
    v9 += 2;
    v46 = v9[1];
    v47 = v31 + v135 + (v34 ^ v45 & (v39 ^ v34));
    v48 = *v9++;
    v49 = (v46 << 8) | v48;
    v50 = *++v9;
    v51 = __ROL4__(v47, 7);
    v52 = (v9[1] << 24) | (v50 << 16) | v49;
    v9 += 2;
    v53 = v9[1];
    v139 = v52;
    ++v9;
    v54 = v34 + v131 + (v39 ^ v51 & (v45 ^ v39));
    v55 = (v53 << 8) | *(v9 - 1);
    v56 = *++v9;
    v126 = (v9[1] << 24) | (v56 << 16) | v55;
    v57 = __ROL4__(v54, 11);
    v9 += 2;
    v58 = *++v9;
    v59 = v39 + v139 + (v45 ^ v57 & (v45 ^ v51));
    v60 = (v58 << 8) | *(v9 - 1);
    v61 = *++v9;
    v134 = (v9[1] << 24) | (v61 << 16) | v60;
    v62 = __ROL4__(v59, 19);
    v9 += 2;
    v63 = v9[1];
    v64 = v45 + v126 + (v51 ^ v62 & (v57 ^ v51));
    v65 = *v9++;
    v66 = (v63 << 8) | v65;
    v67 = *++v9;
    v130 = (v9[1] << 24) | (v67 << 16) | v66;
    v68 = __ROL4__(v64, 3);
    v9 += 2;
    v69 = v9[1];
    v70 = v51 + v134 + (v57 ^ v68 & (v62 ^ v57));
    v71 = *v9;
    v72 = __ROL4__(v70, 7);
    v9 += 2;
    v138 = (v9[1] << 24) | (*v9 << 16) | (v69 << 8) | v71;
    v9 += 2;
    v73 = *++v9 << 8;
    v74 = v57 + v130 + (v62 ^ v72 & (v68 ^ v62));
    v75 = (v9[1] << 16) | v73 | *(v9 - 1);
    v128 = ((++v9)[1] << 24) | v75;
    v76 = __ROL4__(v74, 11);
    v9 += 2;
    v77 = v62 + v138 + (v68 ^ v76 & (v68 ^ v72));
    v78 = *(unsigned __int16 *)v9++;
    v79 = (*++v9 << 16) | v78;
    v136 = (v9[1] << 24) | v79;
    v80 = __ROL4__(v77, 19);
    v9 += 2;
    v81 = v9[1];
    v82 = v68 + v128 + (v72 ^ v80 & (v76 ^ v72));
    v83 = *v9++;
    v84 = (v81 << 8) | v83;
    v85 = *++v9;
    v86 = (v9[1] << 24) | (v85 << 16) | v84;
    v87 = __ROL4__(v82, 3);
    v9 += 2;
    v132 = v86;
    v88 = *(unsigned __int16 *)v9++;
    v89 = (*++v9 << 16) | v88;
    v90 = __ROL4__(v72 + v136 + (v76 ^ v87 & (v80 ^ v76)), 7);
    v140 = (v9[1] << 24) | v89;
    data_ = v9 + 2;
    v91 = __ROL4__(v76 + v132 + (v80 ^ v90 & (v87 ^ v80)), 11);
    v92 = __ROL4__(v80 + v140 + (v87 ^ v91 & (v87 ^ v90)), 19);
    v93 = __ROL4__(v141 + (v92 & v91 | v90 & (v92 | v91)) + v87 + 1518500249, 3);
    v94 = __ROL4__(v127 + (v93 & v92 | v91 & (v93 | v92)) + v90 + 1518500249, 5);
    v95 = __ROL4__(v126 + (v93 & v92 | v94 & (v93 | v92)) + v91 + 1518500249, 9);
    v96 = __ROL4__(v128 + (v93 & v95 | v94 & (v93 | v95)) + v92 + 1518500249, 13);
    v97 = __ROL4__(v133 + (v96 & v95 | v94 & (v96 | v95)) + v93 + 1518500249, 3);
    v98 = __ROL4__(v94 + v135 + (v97 & v96 | v95 & (v97 | v96)) + 1518500249, 5);
    v99 = __ROL4__(v134 + (v97 & v96 | v98 & (v97 | v96)) + v95 + 1518500249, 9);
    v100 = __ROL4__(v136 + (v97 & v99 | v98 & (v97 | v99)) + v96 + 1518500249, 13);
    v101 = __ROL4__(v129 + (v100 & v99 | v98 & (v100 | v99)) + v97 + 1518500249, 3);
    v125 = __ROL4__(v98 + v131 + (v101 & v100 | v99 & (v101 | v100)) + 1518500249, 5);
    v102 = __ROL4__(v130 + (v101 & v100 | v125 & (v101 | v100)) + v99 + 1518500249, 9);
    v103 = __ROL4__(v132 + (v101 & v102 | v125 & (v101 | v102)) + v100 + 1518500249, 13);
    v104 = __ROL4__(v137 + (v103 & v102 | v125 & (v103 | v102)) + v101 + 1518500249, 3);
    v105 = __ROL4__(v125 + v139 + (v104 & v103 | v102 & (v104 | v103)) + 1518500249, 5);
    v106 = __ROL4__(v138 + (v104 & v103 | v105 & (v104 | v103)) + v102 + 1518500249, 9);
    v107 = __ROL4__(v140 + (v104 & v106 | v105 & (v104 | v106)) + v103 + 1518500249, 13);
    v108 = __ROL4__(v141 + (v107 ^ v106 ^ v105) + v104 + 1859775393, 3);
    v109 = __ROL4__(v126 + (v108 ^ v107 ^ v106) + v105 + 1859775393, 9);
    v110 = __ROL4__(v127 + (v108 ^ v107 ^ v109) + v106 + 1859775393, 11);
    v111 = __ROL4__(v107 + v128 + (v108 ^ v110 ^ v109) + 1859775393, 15);
    v112 = __ROL4__(v129 + (v111 ^ v110 ^ v109) + v108 + 1859775393, 3);
    v113 = __ROL4__(v130 + (v112 ^ v111 ^ v110) + v109 + 1859775393, 9);
    v114 = __ROL4__(v131 + (v112 ^ v111 ^ v113) + v110 + 1859775393, 11);
    v115 = __ROL4__(v132 + (v112 ^ v114 ^ v113) + v111 + 1859775393, 15);
    v116 = __ROL4__(v133 + (v115 ^ v114 ^ v113) + v112 + 1859775393, 3);
    v117 = __ROL4__(v134 + (v116 ^ v115 ^ v114) + v113 + 1859775393, 9);
    v118 = __ROL4__(v135 + (v116 ^ v115 ^ v117) + v114 + 1859775393, 11);
    v119 = __ROL4__(v115 + v136 + (v116 ^ v118 ^ v117) + 1859775393, 15);
    v120 = __ROL4__(v137 + (v119 ^ v118 ^ v117) + v116 + 1859775393, 3);
    v121 = __ROL4__(v138 + (v120 ^ v119 ^ v118) + v117 + 1859775393, 9);
    v122 = __ROL4__(v139 + (v120 ^ v119 ^ v121) + v118 + 1859775393, 11);
    v123 = v140 + (v120 ^ v122 ^ v121) + v119 + 1859775393;
    c->A += v120;
    c->C += v122;
    c->D += v121;
    A = c->A;
    v5 = c->C;
    c->B += __ROL4__(v123, 15);
    B = c->B;
    D = c->D;
  }
}
