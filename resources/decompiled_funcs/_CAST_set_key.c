void __cdecl CAST_set_key(cast_key_st *key, int len, const unsigned __int8 *data)
{
  unsigned int v3; // eax
  int v4; // esi
  unsigned int v5; // ecx
  int v6; // ebx
  int v7; // ebp
  int v8; // edi
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  int v12; // esi
  unsigned int v13; // eax
  int v14; // ebp
  int v15; // ebx
  unsigned int v16; // ecx
  unsigned int v17; // edi
  unsigned int v18; // ecx
  unsigned int v19; // ecx
  unsigned int v20; // edx
  unsigned int v21; // edi
  unsigned int v22; // edx
  unsigned int v23; // ecx
  int v24; // esi
  unsigned int v25; // eax
  unsigned int v26; // eax
  int v27; // esi
  unsigned int v28; // edi
  int v29; // edx
  unsigned int v30; // ecx
  unsigned int v31; // eax
  unsigned int v32; // eax
  int v33; // edi
  unsigned int v34; // ebx
  unsigned int v35; // eax
  int v36; // esi
  int v37; // ecx
  unsigned int v38; // eax
  unsigned int v39; // eax
  unsigned int v40; // ebp
  unsigned int v41; // edx
  int v42; // ebx
  unsigned int v43; // ebp
  int v44; // edx
  unsigned int v45; // eax
  unsigned int v46; // eax
  unsigned int v47; // ebx
  int v48; // ecx
  int v49; // ebx
  int v50; // ebp
  unsigned int v51; // eax
  unsigned int v52; // edi
  unsigned int v53; // ebp
  unsigned int v54; // eax
  unsigned int v55; // ebx
  unsigned int v56; // ecx
  unsigned int v57; // esi
  unsigned int v58; // eax
  unsigned int v59; // ebp
  unsigned int v60; // ecx
  unsigned int v61; // eax
  unsigned int v62; // edx
  int v63; // ecx
  int v64; // edx
  unsigned int v65; // eax
  unsigned int v66; // ebp
  unsigned int v67; // edx
  unsigned int v68; // ebp
  int v69; // ecx
  unsigned int v70; // edx
  int v71; // ebp
  int v72; // esi
  unsigned int v73; // eax
  unsigned int v74; // eax
  unsigned int v75; // eax
  unsigned int v76; // ecx
  unsigned int v77; // ecx
  int v78; // ebx
  unsigned int v79; // edx
  unsigned int v80; // edx
  unsigned int v81; // edx
  unsigned int v82; // esi
  unsigned int v83; // ecx
  unsigned int v84; // ecx
  unsigned int v85; // edx
  int v86; // edi
  int v87; // ebx
  unsigned int v88; // eax
  unsigned int v89; // eax
  int v90; // esi
  unsigned int v91; // edi
  int v92; // ecx
  unsigned int v93; // edx
  unsigned int v94; // eax
  unsigned int v95; // eax
  int v96; // edi
  unsigned int v97; // ebp
  unsigned int v98; // eax
  int v99; // esi
  int v100; // edx
  unsigned int v101; // eax
  unsigned int v102; // ebx
  unsigned int v103; // ecx
  int v104; // ebx
  unsigned int v105; // ebp
  int v106; // ecx
  int v107; // edi
  unsigned int v108; // eax
  unsigned int v109; // eax
  unsigned int v110; // ebx
  int v111; // edx
  int v112; // ebx
  unsigned int v113; // eax
  int v114; // ebp
  unsigned int v115; // eax
  int v116; // esi
  unsigned int v117; // eax
  int v118; // edx
  unsigned int v119; // eax
  unsigned int v120; // edi
  unsigned int v121; // esi
  unsigned int v122; // edx
  unsigned int v123; // eax
  unsigned int v124; // ebp
  unsigned int v125; // ebx
  unsigned int v126; // esi
  int v127; // ebp
  int v128; // edx
  unsigned int v129; // eax
  unsigned int v130; // esi
  unsigned int v131; // eax
  int v132; // ecx
  unsigned int v133; // eax
  int v134; // ebx
  unsigned int v135; // eax
  unsigned int v136; // esi
  unsigned int v137; // edi
  unsigned int v138; // ebx
  unsigned int v139; // eax
  int i; // eax
  unsigned int v141; // [esp+10h] [ebp-13Ch]
  unsigned int v142; // [esp+10h] [ebp-13Ch]
  unsigned int v143; // [esp+10h] [ebp-13Ch]
  unsigned int v144; // [esp+10h] [ebp-13Ch]
  unsigned int v145; // [esp+10h] [ebp-13Ch]
  unsigned int v146; // [esp+10h] [ebp-13Ch]
  unsigned int v147; // [esp+10h] [ebp-13Ch]
  unsigned int v148; // [esp+14h] [ebp-138h]
  unsigned int v149; // [esp+14h] [ebp-138h]
  unsigned int v150; // [esp+14h] [ebp-138h]
  unsigned int v151; // [esp+14h] [ebp-138h]
  unsigned int v152; // [esp+14h] [ebp-138h]
  unsigned int v153; // [esp+18h] [ebp-134h]
  unsigned int v154; // [esp+18h] [ebp-134h]
  unsigned int v155; // [esp+18h] [ebp-134h]
  unsigned int v156; // [esp+18h] [ebp-134h]
  unsigned int v157; // [esp+18h] [ebp-134h]
  unsigned int v158; // [esp+1Ch] [ebp-130h]
  unsigned int v159; // [esp+1Ch] [ebp-130h]
  unsigned int v160; // [esp+1Ch] [ebp-130h]
  unsigned int v161; // [esp+1Ch] [ebp-130h]
  unsigned int v162; // [esp+20h] [ebp-12Ch]
  unsigned int v163; // [esp+20h] [ebp-12Ch]
  unsigned int v164; // [esp+20h] [ebp-12Ch]
  unsigned int v165; // [esp+20h] [ebp-12Ch]
  unsigned int v166; // [esp+24h] [ebp-128h]
  unsigned int v167; // [esp+24h] [ebp-128h]
  unsigned int v168; // [esp+24h] [ebp-128h]
  unsigned int v169; // [esp+24h] [ebp-128h]
  unsigned int v170; // [esp+28h] [ebp-124h]
  unsigned int v171; // [esp+28h] [ebp-124h]
  unsigned int v172; // [esp+28h] [ebp-124h]
  unsigned int v173; // [esp+28h] [ebp-124h]
  unsigned int v174; // [esp+2Ch] [ebp-120h]
  unsigned int v175; // [esp+2Ch] [ebp-120h]
  unsigned int v176; // [esp+2Ch] [ebp-120h]
  unsigned int v177; // [esp+2Ch] [ebp-120h]
  unsigned int v178; // [esp+30h] [ebp-11Ch]
  unsigned int v179; // [esp+30h] [ebp-11Ch]
  unsigned int v180; // [esp+30h] [ebp-11Ch]
  unsigned int v181; // [esp+30h] [ebp-11Ch]
  unsigned int v182; // [esp+34h] [ebp-118h]
  unsigned int v183; // [esp+34h] [ebp-118h]
  unsigned int v184; // [esp+34h] [ebp-118h]
  unsigned int v185; // [esp+34h] [ebp-118h]
  unsigned int v186; // [esp+38h] [ebp-114h]
  int v187; // [esp+3Ch] [ebp-110h]
  int v188; // [esp+40h] [ebp-10Ch]
  int v189; // [esp+44h] [ebp-108h]
  unsigned int v190; // [esp+48h] [ebp-104h]
  int v191; // [esp+4Ch] [ebp-100h]
  int v192; // [esp+50h] [ebp-FCh]
  int v193; // [esp+54h] [ebp-F8h]
  unsigned int v194; // [esp+58h] [ebp-F4h]
  int v195; // [esp+5Ch] [ebp-F0h]
  int v196; // [esp+60h] [ebp-ECh]
  int v197; // [esp+64h] [ebp-E8h]
  unsigned int v198; // [esp+68h] [ebp-E4h]
  int v199; // [esp+6Ch] [ebp-E0h]
  int v200; // [esp+70h] [ebp-DCh]
  int v201; // [esp+74h] [ebp-D8h]
  unsigned int v202; // [esp+78h] [ebp-D4h]
  unsigned int v203; // [esp+7Ch] [ebp-D0h]
  unsigned int v204; // [esp+80h] [ebp-CCh]
  unsigned int v205; // [esp+84h] [ebp-C8h]
  unsigned int v206; // [esp+88h] [ebp-C4h]
  unsigned int v207; // [esp+8Ch] [ebp-C0h]
  int v208; // [esp+98h] [ebp-B4h]
  unsigned int v209; // [esp+9Ch] [ebp-B0h]
  int v210; // [esp+A0h] [ebp-ACh]
  int v211; // [esp+A8h] [ebp-A4h]
  unsigned int v212; // [esp+ACh] [ebp-A0h]
  int v213; // [esp+B4h] [ebp-98h]
  int v214; // [esp+B8h] [ebp-94h]
  unsigned int v215; // [esp+BCh] [ebp-90h]
  int v216; // [esp+C4h] [ebp-88h]
  int v217; // [esp+C8h] [ebp-84h]
  _DWORD v218[16]; // [esp+CCh] [ebp-80h]
  _DWORD v219[16]; // [esp+10Ch] [ebp-40h]

  v3 = 0;
  v4 = len;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v186 = 0;
  v187 = 0;
  v188 = 0;
  v189 = 0;
  v190 = 0;
  v191 = 0;
  v192 = 0;
  v193 = 0;
  v194 = 0;
  v195 = 0;
  v196 = 0;
  v197 = 0;
  v198 = 0;
  v199 = 0;
  v200 = 0;
  v201 = 0;
  if ( len > 16 )
    v4 = 16;
  v9 = 0;
  if ( v4 > 0 )
  {
    do
    {
      *(&v186 + v9) = data[v9];
      ++v9;
    }
    while ( v9 < v4 );
    v8 = v201;
    v7 = v200;
    v6 = v199;
    v3 = v190;
    v5 = v186;
  }
  v10 = v187 | (v5 << 8);
  v11 = v192 | ((v191 | (v3 << 8)) << 8);
  key->short_key = v4 <= 10;
  v203 = v193 | (v11 << 8);
  v12 = v8 | ((v7 | ((v6 | (v198 << 8)) << 8)) << 8);
  v13 = (v189 | ((v188 | (v10 << 8)) << 8))
      ^ CAST_S_table6[v194]
      ^ CAST_S_table6[v198]
      ^ CAST_S_table4[v6]
      ^ CAST_S_table7[v7]
      ^ CAST_S_table5[v8];
  v14 = (unsigned __int8)v13;
  v15 = BYTE2(v13);
  v141 = CAST_S_table6[BYTE2(v13)];
  v16 = CAST_S_table7[(unsigned __int8)v13] ^ CAST_S_table7[v196];
  v17 = v13 >> 8;
  v170 = v13;
  v13 >>= 24;
  v18 = v141 ^ CAST_S_table4[v13] ^ CAST_S_table5[(unsigned __int8)v17] ^ v16;
  v208 = v14;
  v207 = v13;
  v174 = (v197 | ((v196 | ((v195 | (v194 << 8)) << 8)) << 8)) ^ v18;
  v211 = (unsigned __int8)(v197 ^ v18);
  v209 = HIBYTE(v174);
  v162 = CAST_S_table6[BYTE2(v174)];
  v158 = CAST_S_table5[BYTE1(v174)];
  v19 = CAST_S_table7[HIBYTE(v174)];
  v178 = v12 ^ v19 ^ v162 ^ v158 ^ CAST_S_table4[v211] ^ CAST_S_table4[v195];
  v206 = v19;
  v214 = (unsigned __int8)v178;
  v212 = HIBYTE(v178);
  v166 = CAST_S_table4[BYTE1(v178)];
  v153 = CAST_S_table5[BYTE2(v178)];
  v182 = v203 ^ v153 ^ v166 ^ CAST_S_table7[HIBYTE(v178)] ^ CAST_S_table6[(unsigned __int8)v178] ^ CAST_S_table5[v197];
  v217 = (unsigned __int8)v182;
  v216 = BYTE1(v182);
  v215 = HIBYTE(v182);
  v148 = CAST_S_table7[BYTE1(v174)];
  v20 = CAST_S_table4[(unsigned __int8)v17] ^ CAST_S_table6[v211] ^ CAST_S_table4[HIBYTE(v178)];
  v21 = CAST_S_table7[(unsigned __int8)v17];
  v218[0] = v153 ^ v148 ^ v20;
  v218[1] = v19 ^ v162 ^ v158 ^ v166 ^ CAST_S_table5[(unsigned __int8)v178];
  v218[2] = v21
          ^ CAST_S_table6[v14]
          ^ CAST_S_table6[BYTE2(v178)]
          ^ CAST_S_table4[HIBYTE(v182)]
          ^ CAST_S_table5[BYTE2(v182)];
  v218[3] = v141
          ^ CAST_S_table7[v13]
          ^ CAST_S_table7[HIBYTE(v182)]
          ^ CAST_S_table5[(unsigned __int8)v182]
          ^ CAST_S_table4[BYTE1(v182)];
  v22 = v178
      ^ v148
      ^ CAST_S_table6[v13]
      ^ CAST_S_table6[HIBYTE(v174)]
      ^ CAST_S_table4[BYTE2(v174)]
      ^ CAST_S_table5[v211];
  v23 = CAST_S_table5[(unsigned __int8)((unsigned __int16)(v178
                                                         ^ v148
                                                         ^ LOWORD(CAST_S_table6[v13])
                                                         ^ LOWORD(CAST_S_table6[HIBYTE(v174)])
                                                         ^ LOWORD(CAST_S_table4[BYTE2(v174)])
                                                         ^ LOWORD(CAST_S_table5[v211])) >> 8)];
  v24 = (unsigned __int8)v22;
  v202 = v22;
  v22 >>= 24;
  v149 = v23;
  v25 = CAST_S_table7[v24] ^ CAST_S_table6[BYTE2(v202)] ^ CAST_S_table4[v22];
  v189 = v24;
  v26 = v170 ^ v21 ^ v23 ^ v25;
  v186 = v22;
  v27 = (unsigned __int8)v26;
  v203 = v26;
  v28 = HIBYTE(v26);
  v29 = BYTE2(v26);
  v30 = CAST_S_table5[BYTE1(v26)];
  v31 = v30 ^ v174 ^ CAST_S_table6[BYTE2(v26)] ^ CAST_S_table7[HIBYTE(v26)] ^ CAST_S_table4[v15];
  v190 = v28;
  v193 = v27;
  v32 = CAST_S_table4[v27] ^ v31;
  v33 = (unsigned __int8)v32;
  BYTE2(v27) = BYTE2(v32);
  v204 = v32;
  v154 = v30;
  BYTE1(v30) = BYTE1(v32);
  v34 = HIBYTE(v32);
  v35 = CAST_S_table6[(unsigned __int8)v32];
  v197 = v33;
  v36 = BYTE2(v27);
  v37 = BYTE1(v30);
  v38 = CAST_S_table4[v37] ^ CAST_S_table5[v36] ^ v35;
  v194 = v34;
  v39 = v182 ^ CAST_S_table7[v34] ^ CAST_S_table5[v14] ^ v38;
  v201 = (unsigned __int8)v39;
  v205 = v39;
  v200 = BYTE1(v39);
  v142 = CAST_S_table6[HIBYTE(v39)];
  v218[4] = v142 ^ v149 ^ CAST_S_table7[BYTE2(v39)] ^ CAST_S_table4[v34] ^ CAST_S_table4[v189];
  v218[5] = CAST_S_table7[(unsigned __int8)v39]
          ^ CAST_S_table6[BYTE1(v39)]
          ^ CAST_S_table5[BYTE2(v39)]
          ^ CAST_S_table4[BYTE2(v202)]
          ^ CAST_S_table5[v186];
  v40 = CAST_S_table6[v34];
  v218[6] = CAST_S_table4[v193] ^ v154 ^ v40 ^ CAST_S_table7[v36] ^ CAST_S_table6[v189];
  v218[7] = CAST_S_table7[v193] ^ CAST_S_table4[v29] ^ CAST_S_table5[v190] ^ CAST_S_table6[v37] ^ CAST_S_table7[v33];
  v41 = v202 ^ v142 ^ v40 ^ CAST_S_table5[(unsigned __int8)v39] ^ CAST_S_table7[BYTE1(v39)] ^ CAST_S_table4[BYTE2(v39)];
  v42 = (unsigned __int8)v41;
  v171 = v41;
  v43 = HIBYTE(v41);
  v44 = BYTE1(v41);
  v143 = CAST_S_table5[v44];
  v45 = CAST_S_table6[BYTE2(v171)] ^ CAST_S_table7[v42] ^ CAST_S_table7[v37];
  v208 = v42;
  v46 = CAST_S_table4[v43] ^ v45;
  v207 = v43;
  v47 = v204 ^ v143 ^ v46;
  v48 = (unsigned __int8)v47;
  v175 = v47;
  v209 = HIBYTE(v47);
  v49 = BYTE1(v47);
  v159 = CAST_S_table5[v49];
  v50 = (unsigned __int8)((v204 ^ v143 ^ v46) >> 16);
  v51 = CAST_S_table6[v50] ^ CAST_S_table4[v36];
  v211 = v48;
  v179 = v205 ^ v159 ^ CAST_S_table4[v48] ^ CAST_S_table7[v209] ^ v51;
  v214 = (unsigned __int8)v179;
  v213 = BYTE1(v179);
  v212 = HIBYTE(v179);
  v52 = CAST_S_table4[BYTE2(v171)];
  v53 = CAST_S_table4[v50];
  v54 = v203
      ^ CAST_S_table7[HIBYTE(v179)]
      ^ CAST_S_table5[BYTE2(v179)]
      ^ CAST_S_table4[BYTE1(v179)]
      ^ CAST_S_table6[(unsigned __int8)v179]
      ^ CAST_S_table5[v197];
  v55 = CAST_S_table7[v49];
  v217 = (unsigned __int8)v54;
  v183 = v54;
  v216 = BYTE1(v54);
  v215 = HIBYTE(v54);
  v56 = CAST_S_table7[BYTE2(v179)];
  v57 = CAST_S_table4[v208] ^ CAST_S_table4[BYTE2(v179)] ^ CAST_S_table6[HIBYTE(v54)] ^ CAST_S_table7[BYTE2(v54)];
  v58 = CAST_S_table6[BYTE1(v54)];
  v218[8] = v143 ^ v57;
  v218[9] = v52 ^ CAST_S_table5[v207] ^ CAST_S_table5[v215] ^ CAST_S_table7[v217] ^ v58;
  v218[10] = v159 ^ CAST_S_table4[v211] ^ CAST_S_table6[v44] ^ CAST_S_table6[HIBYTE(v179)] ^ v56;
  v218[11] = v55 ^ v53 ^ CAST_S_table5[v209] ^ CAST_S_table6[BYTE1(v179)] ^ CAST_S_table7[(unsigned __int8)v179];
  v202 = v179 ^ v55 ^ v53 ^ CAST_S_table6[v207] ^ CAST_S_table6[v209] ^ CAST_S_table5[v211];
  v189 = (unsigned __int8)v202;
  v186 = HIBYTE(v202);
  v167 = CAST_S_table6[BYTE2(v202)];
  v203 = v171
       ^ v167
       ^ CAST_S_table7[v44]
       ^ CAST_S_table7[(unsigned __int8)v202]
       ^ CAST_S_table5[BYTE1(v202)]
       ^ CAST_S_table4[HIBYTE(v202)];
  v59 = CAST_S_table7[HIBYTE(v203)];
  v60 = CAST_S_table6[BYTE2(v203)];
  v204 = v52 ^ v60 ^ v59 ^ v175 ^ CAST_S_table4[(unsigned __int8)v203] ^ CAST_S_table5[BYTE1(v203)];
  v163 = v60;
  v193 = (unsigned __int8)v203;
  v155 = CAST_S_table4[BYTE1(v204)];
  v197 = (unsigned __int8)v204;
  v150 = CAST_S_table5[BYTE2(v204)];
  v61 = v155 ^ v150 ^ v183 ^ CAST_S_table7[HIBYTE(v204)] ^ CAST_S_table5[v208] ^ CAST_S_table6[(unsigned __int8)v204];
  v201 = (unsigned __int8)v61;
  v205 = v61;
  v200 = BYTE1(v61);
  v198 = HIBYTE(v61);
  v62 = CAST_S_table5[(unsigned __int8)v203];
  v63 = BYTE2(v61);
  v218[12] = v150
           ^ CAST_S_table6[(unsigned __int8)v203]
           ^ CAST_S_table7[BYTE1(v203)]
           ^ CAST_S_table4[HIBYTE(v204)]
           ^ CAST_S_table4[(unsigned __int8)v202];
  v206 = CAST_S_table5[(unsigned __int8)v204];
  v64 = v59 ^ v155 ^ v206 ^ v62;
  v65 = CAST_S_table7[BYTE1(v202)];
  v66 = CAST_S_table6[HIBYTE(v204)];
  v218[13] = v163 ^ v64;
  v218[14] = v66 ^ CAST_S_table5[v63] ^ CAST_S_table4[v198] ^ CAST_S_table6[(unsigned __int8)v202] ^ v65;
  v67 = CAST_S_table5[v201];
  v218[15] = v67 ^ v167 ^ CAST_S_table4[v200] ^ CAST_S_table7[v63] ^ CAST_S_table7[HIBYTE(v202)];
  v68 = v202 ^ v67 ^ v66 ^ CAST_S_table7[v200] ^ CAST_S_table4[v63] ^ CAST_S_table6[v198];
  v69 = (unsigned __int8)v68;
  BYTE1(v57) = BYTE1(v68);
  v172 = v68;
  v70 = HIBYTE(v68);
  v71 = BYTE2(v68);
  v144 = CAST_S_table6[v71];
  v72 = BYTE1(v57);
  v73 = CAST_S_table5[v72] ^ CAST_S_table7[v69] ^ CAST_S_table7[BYTE1(v204)];
  v208 = v69;
  v74 = CAST_S_table4[v70] ^ v73;
  v207 = v70;
  v75 = v204 ^ v144 ^ v74;
  v210 = BYTE2(v75);
  v164 = CAST_S_table6[BYTE2(v75)];
  v160 = CAST_S_table5[BYTE1(v75)];
  v76 = CAST_S_table4[(unsigned __int8)v75] ^ CAST_S_table4[BYTE2(v204)];
  v176 = v75;
  v209 = HIBYTE(v75);
  v77 = v205 ^ CAST_S_table7[HIBYTE(v75)] ^ v164 ^ v160 ^ v76;
  v211 = (unsigned __int8)v75;
  v180 = v77;
  v214 = (unsigned __int8)v77;
  v78 = BYTE2(v77);
  v79 = CAST_S_table4[BYTE1(v77)];
  v212 = HIBYTE(v77);
  v168 = v79;
  v156 = CAST_S_table5[BYTE2(v77)];
  v80 = v203 ^ v156 ^ v79 ^ v206 ^ CAST_S_table7[HIBYTE(v77)] ^ CAST_S_table6[(unsigned __int8)v77];
  v217 = (unsigned __int8)v80;
  BYTE1(v77) = BYTE1(v80);
  BYTE2(v75) = BYTE2(v80);
  v184 = v80;
  v215 = HIBYTE(v80);
  v151 = CAST_S_table7[BYTE1(v75)];
  v81 = CAST_S_table4[v72] ^ CAST_S_table6[(unsigned __int8)v75] ^ CAST_S_table4[v212];
  v82 = CAST_S_table7[v72];
  v219[0] = v156 ^ v151 ^ v81;
  v83 = CAST_S_table4[BYTE1(v77)];
  v219[1] = CAST_S_table7[v209] ^ v164 ^ v160 ^ v168 ^ CAST_S_table5[v214];
  v219[2] = v82 ^ CAST_S_table6[v208] ^ CAST_S_table6[v78] ^ CAST_S_table4[v215] ^ CAST_S_table5[BYTE2(v75)];
  v219[3] = v144 ^ CAST_S_table7[v207] ^ CAST_S_table7[v215] ^ CAST_S_table5[v217] ^ v83;
  v84 = v180
      ^ v151
      ^ CAST_S_table6[v207]
      ^ CAST_S_table6[v209]
      ^ CAST_S_table4[v210]
      ^ CAST_S_table5[(unsigned __int8)v75];
  v85 = CAST_S_table5[(unsigned __int8)((unsigned __int16)(v180
                                                         ^ v151
                                                         ^ LOWORD(CAST_S_table6[v207])
                                                         ^ LOWORD(CAST_S_table6[v209])
                                                         ^ LOWORD(CAST_S_table4[v210])
                                                         ^ LOWORD(CAST_S_table5[(unsigned __int8)v75])) >> 8)];
  v86 = (unsigned __int8)v84;
  v202 = v84;
  v87 = BYTE2(v84);
  v84 >>= 24;
  v88 = CAST_S_table4[v84];
  v189 = v86;
  v186 = v84;
  v152 = v85;
  v89 = v172 ^ v82 ^ v85 ^ CAST_S_table7[v86] ^ CAST_S_table6[v87] ^ v88;
  v90 = (unsigned __int8)v89;
  v203 = v89;
  v91 = HIBYTE(v89);
  v92 = BYTE2(v89);
  v93 = CAST_S_table5[BYTE1(v89)];
  v94 = v93 ^ v176 ^ CAST_S_table6[BYTE2(v89)] ^ CAST_S_table7[HIBYTE(v89)] ^ CAST_S_table4[v71];
  v190 = v91;
  v193 = v90;
  v95 = CAST_S_table4[v90] ^ v94;
  v96 = (unsigned __int8)v95;
  BYTE2(v90) = BYTE2(v95);
  v204 = v95;
  v157 = v93;
  BYTE1(v93) = BYTE1(v95);
  v97 = HIBYTE(v95);
  v98 = CAST_S_table6[(unsigned __int8)v95];
  v197 = v96;
  v99 = BYTE2(v90);
  v100 = BYTE1(v93);
  v101 = CAST_S_table4[v100] ^ CAST_S_table5[v99] ^ v98;
  v194 = v97;
  v205 = v184 ^ CAST_S_table7[v97] ^ CAST_S_table5[v208] ^ v101;
  v201 = (unsigned __int8)v205;
  v200 = BYTE1(v205);
  v145 = CAST_S_table6[HIBYTE(v205)];
  v219[4] = v145 ^ v152 ^ CAST_S_table7[BYTE2(v205)] ^ CAST_S_table4[v97] ^ CAST_S_table4[v189];
  v219[5] = CAST_S_table7[(unsigned __int8)v205]
          ^ CAST_S_table6[BYTE1(v205)]
          ^ CAST_S_table5[BYTE2(v205)]
          ^ CAST_S_table4[v87]
          ^ CAST_S_table5[v186];
  v102 = CAST_S_table6[v97];
  v219[6] = CAST_S_table4[v193] ^ v157 ^ v102 ^ CAST_S_table7[v99] ^ CAST_S_table6[v189];
  v219[7] = CAST_S_table7[v193] ^ CAST_S_table4[v92] ^ CAST_S_table5[v190] ^ CAST_S_table6[v100] ^ CAST_S_table7[v96];
  v103 = v202
       ^ v145
       ^ v102
       ^ CAST_S_table5[(unsigned __int8)v205]
       ^ CAST_S_table7[BYTE1(v205)]
       ^ CAST_S_table4[BYTE2(v205)];
  v104 = (unsigned __int8)v103;
  BYTE2(v96) = BYTE2(v103);
  v173 = v103;
  v105 = HIBYTE(v103);
  v106 = BYTE1(v103);
  v146 = CAST_S_table5[v106];
  v107 = BYTE2(v96);
  v108 = CAST_S_table6[v107] ^ CAST_S_table7[v104] ^ CAST_S_table7[v100];
  v208 = v104;
  v109 = CAST_S_table4[v105] ^ v108;
  v207 = v105;
  v110 = v204 ^ v146 ^ v109;
  v111 = (unsigned __int8)v110;
  BYTE2(v105) = BYTE2(v110);
  v177 = v110;
  v209 = HIBYTE(v110);
  v112 = BYTE1(v110);
  v161 = CAST_S_table5[v112];
  v113 = CAST_S_table4[v99];
  v211 = v111;
  v114 = BYTE2(v105);
  v115 = v205 ^ v161 ^ CAST_S_table4[v111] ^ CAST_S_table7[v209] ^ CAST_S_table6[v114] ^ v113;
  v116 = (unsigned __int8)v115;
  v181 = v115;
  v213 = BYTE1(v115);
  BYTE2(v111) = BYTE2(v115);
  v212 = HIBYTE(v115);
  v117 = CAST_S_table6[(unsigned __int8)v115] ^ CAST_S_table5[v197];
  v214 = v116;
  v118 = BYTE2(v111);
  v119 = v203 ^ CAST_S_table7[v212] ^ CAST_S_table5[v118] ^ CAST_S_table4[v213] ^ v117;
  v120 = CAST_S_table4[v107];
  v217 = (unsigned __int8)v119;
  v185 = v119;
  v216 = BYTE1(v119);
  v215 = HIBYTE(v119);
  v121 = CAST_S_table4[v118] ^ CAST_S_table6[HIBYTE(v119)] ^ CAST_S_table7[BYTE2(v119)];
  v122 = CAST_S_table7[v118];
  v123 = CAST_S_table6[BYTE1(v119)];
  v124 = CAST_S_table4[v114];
  v219[8] = v146 ^ CAST_S_table4[v208] ^ v121;
  v125 = CAST_S_table7[v112];
  v219[9] = v120 ^ CAST_S_table5[v207] ^ CAST_S_table5[v215] ^ CAST_S_table7[v217] ^ v123;
  v219[10] = v161 ^ CAST_S_table4[v211] ^ CAST_S_table6[v106] ^ CAST_S_table6[v212] ^ v122;
  v219[11] = v125 ^ v124 ^ CAST_S_table5[v209] ^ CAST_S_table6[v213] ^ CAST_S_table7[v214];
  v126 = v181 ^ v125 ^ v124 ^ CAST_S_table6[v207] ^ CAST_S_table6[v209] ^ CAST_S_table5[v211];
  v127 = (unsigned __int8)v126;
  v186 = HIBYTE(v126);
  v128 = BYTE1(v126);
  v129 = CAST_S_table5[BYTE1(v126)] ^ CAST_S_table4[HIBYTE(v126)];
  v130 = CAST_S_table6[BYTE2(v126)];
  v131 = v173 ^ v130 ^ CAST_S_table7[v106] ^ CAST_S_table7[v127] ^ v129;
  v169 = v130;
  v132 = BYTE1(v131);
  v193 = (unsigned __int8)v131;
  v147 = CAST_S_table7[HIBYTE(v131)];
  v165 = CAST_S_table6[BYTE2(v131)];
  v133 = v120 ^ v165 ^ v147 ^ v177 ^ CAST_S_table4[(unsigned __int8)v131] ^ CAST_S_table5[BYTE1(v131)];
  v134 = (unsigned __int8)v133;
  BYTE1(v130) = BYTE1(v133);
  BYTE2(v120) = BYTE2(v133);
  v194 = HIBYTE(v133);
  v135 = CAST_S_table6[(unsigned __int8)v133];
  v197 = v134;
  v136 = CAST_S_table4[BYTE1(v130)];
  v137 = CAST_S_table5[BYTE2(v120)];
  v138 = v136 ^ v137 ^ v185 ^ CAST_S_table7[v194] ^ CAST_S_table5[v208] ^ v135;
  v201 = (unsigned __int8)v138;
  v198 = HIBYTE(v138);
  v219[12] = v137 ^ CAST_S_table6[v193] ^ CAST_S_table7[v132] ^ CAST_S_table4[v194] ^ CAST_S_table4[v127];
  v219[13] = v165 ^ v147 ^ v136 ^ CAST_S_table5[v193] ^ CAST_S_table5[v197];
  v139 = CAST_S_table4[BYTE1(v138)] ^ CAST_S_table5[(unsigned __int8)v138];
  v219[14] = CAST_S_table5[BYTE2(v138)]
           ^ CAST_S_table6[v194]
           ^ CAST_S_table6[v127]
           ^ CAST_S_table7[v128]
           ^ CAST_S_table4[HIBYTE(v138)];
  v219[15] = v169 ^ CAST_S_table7[BYTE2(v138)] ^ CAST_S_table7[v186] ^ v139;
  for ( i = 0; i < 16; ++i )
  {
    key->data[2 * i] = v218[i];
    key->data[2 * i + 1] = ((unsigned __int8)v219[i] - 16) & 0x1F;
  }
}
