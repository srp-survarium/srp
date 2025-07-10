void __cdecl whirlpool_block(WHIRLPOOL_CTX *ctx, _BYTE *inp, unsigned int n)
{
  int v3; // edi
  int v4; // esi
  int i; // eax
  char v6; // dl
  unsigned __int64 *v7; // eax
  int v8; // edx
  unsigned __int64 v9; // rt0
  unsigned int v10; // ecx
  unsigned int v11; // eax
  int v12; // esi
  int v13; // edx
  unsigned int v14; // ebx
  int v15; // ebp
  unsigned __int64 v16; // rt0
  int v17; // ebx
  unsigned int v18; // edx
  unsigned int v19; // esi
  unsigned int v20; // edi
  unsigned int v21; // eax
  unsigned int v22; // ecx
  unsigned int v23; // ebp
  unsigned int v24; // ebx
  unsigned __int64 v25; // rt0
  int v26; // ebx
  unsigned int v27; // edx
  unsigned int v28; // esi
  int v29; // ecx
  int v30; // edi
  unsigned int v31; // eax
  unsigned int v32; // ecx
  unsigned __int64 v33; // rt0
  unsigned int v34; // ebx
  unsigned int v35; // ebp
  unsigned int v36; // ecx
  unsigned int v37; // eax
  unsigned int v38; // ecx
  unsigned int v39; // eax
  unsigned int v40; // ecx
  int v41; // eax
  unsigned int v42; // ecx
  int v43; // eax
  unsigned int v44; // ecx
  int v45; // eax
  int v46; // ebx
  unsigned int v47; // edx
  unsigned int v48; // esi
  int v49; // edi
  unsigned int v50; // ecx
  unsigned int v51; // eax
  unsigned int v52; // eax
  unsigned int v53; // ecx
  unsigned int v54; // ebx
  unsigned int v55; // ebp
  unsigned int v56; // ecx
  int v57; // eax
  unsigned int v58; // ecx
  unsigned int v59; // eax
  unsigned int v60; // ecx
  int v61; // eax
  unsigned int v62; // ecx
  unsigned int v63; // eax
  unsigned int v64; // ecx
  int v65; // eax
  int v66; // ebx
  int v67; // ebp
  unsigned int v68; // edx
  unsigned int v69; // esi
  unsigned int v70; // edi
  unsigned int v71; // eax
  unsigned int v72; // ecx
  unsigned int v73; // ebx
  unsigned int v74; // ebp
  unsigned int v75; // ecx
  int v76; // eax
  unsigned int v77; // ecx
  unsigned int v78; // eax
  unsigned int v79; // ecx
  int v80; // eax
  unsigned int v81; // ecx
  unsigned int v82; // eax
  unsigned int v83; // ecx
  int v84; // eax
  int v85; // ebx
  int v86; // ebp
  unsigned int v87; // edx
  unsigned int v88; // esi
  unsigned int v89; // edi
  int v90; // ecx
  int v91; // eax
  unsigned __int64 v92; // rt0
  unsigned int v93; // ebx
  unsigned int v94; // ebp
  unsigned __int64 v95; // rt0
  unsigned __int64 v96; // rt0
  int v97; // ebx
  int v98; // ebp
  unsigned int v99; // edx
  unsigned int v100; // esi
  unsigned int v101; // edi
  int v102; // ecx
  unsigned int v103; // ebx
  unsigned int v104; // ebp
  int v105; // ebx
  unsigned __int64 v106; // rt0
  int v107; // ebp
  unsigned int v108; // edx
  unsigned int v109; // esi
  int v110; // edi
  unsigned int v111; // eax
  unsigned int v112; // ecx
  unsigned int v113; // ebx
  unsigned int v114; // ebp
  unsigned int v115; // ecx
  int v116; // eax
  unsigned int v117; // ecx
  unsigned int v118; // eax
  unsigned int v119; // ecx
  int v120; // eax
  unsigned int v121; // ecx
  unsigned int v122; // eax
  unsigned int v123; // ecx
  int v124; // eax
  int v125; // ebx
  int v126; // ebp
  int v127; // eax
  unsigned int v128; // ecx
  int v129; // edx
  int v130; // esi
  unsigned int v131; // edi
  unsigned int v132; // ebx
  int v133; // esi
  int v134; // ebp
  int v135; // esi
  int v136; // ebp
  int v137; // esi
  int v138; // ebp
  int v139; // esi
  int v140; // ebp
  unsigned __int64 v141; // rt0
  unsigned int v142; // ebx
  int v143; // esi
  unsigned int v144; // edi
  int v145; // ebp
  int v146; // esi
  unsigned int v147; // eax
  unsigned int v148; // esi
  unsigned int v149; // ebx
  unsigned int v150; // edi
  int v151; // esi
  int v152; // eax
  int v153; // edi
  int v154; // ebx
  bool v155; // cc
  char *v156; // ecx
  WHIRLPOOL_CTX *v157; // eax
  int v158; // ebp
  unsigned __int8 *v159; // esi
  char v160; // bl
  char v161; // bl
  int v162; // esi
  char v163; // bl
  bool v164; // zf
  __int64 v165; // [esp+0h] [ebp-260h]
  int v166; // [esp+10h] [ebp-250h]
  __int64 v167; // [esp+14h] [ebp-24Ch]
  int v168; // [esp+1Ch] [ebp-244h]
  __int64 v169; // [esp+20h] [ebp-240h]
  char *v170; // [esp+28h] [ebp-238h]
  __int64 v171; // [esp+2Ch] [ebp-234h]
  __int64 v172; // [esp+34h] [ebp-22Ch]
  __int64 v173; // [esp+3Ch] [ebp-224h]
  __int64 v174; // [esp+44h] [ebp-21Ch]
  __int64 v175; // [esp+4Ch] [ebp-214h]
  __int64 v176; // [esp+54h] [ebp-20Ch]
  __int64 v177; // [esp+5Ch] [ebp-204h]
  __int64 v178; // [esp+64h] [ebp-1FCh]
  int v179; // [esp+6Ch] [ebp-1F4h]
  int v180; // [esp+70h] [ebp-1F0h]
  int v181; // [esp+74h] [ebp-1ECh]
  int v182; // [esp+78h] [ebp-1E8h]
  __int64 v183; // [esp+7Ch] [ebp-1E4h]
  int v184; // [esp+84h] [ebp-1DCh]
  int v185; // [esp+88h] [ebp-1D8h]
  int v186; // [esp+8Ch] [ebp-1D4h]
  int v187; // [esp+90h] [ebp-1D0h]
  int v188; // [esp+94h] [ebp-1CCh]
  int v189; // [esp+98h] [ebp-1C8h]
  __int64 v190; // [esp+9Ch] [ebp-1C4h]
  int v191; // [esp+A4h] [ebp-1BCh]
  int v192; // [esp+A8h] [ebp-1B8h]
  int v193; // [esp+B0h] [ebp-1B0h]
  int v194; // [esp+B4h] [ebp-1ACh]
  int v195; // [esp+B8h] [ebp-1A8h]
  __int64 v196; // [esp+BCh] [ebp-1A4h]
  unsigned __int64 *v197; // [esp+C4h] [ebp-19Ch]
  __int64 v198; // [esp+C8h] [ebp-198h]
  __int64 v199; // [esp+D0h] [ebp-190h]
  __int64 v200; // [esp+D8h] [ebp-188h]
  __int64 v201; // [esp+E0h] [ebp-180h]
  __int64 v202; // [esp+E8h] [ebp-178h]
  int v203; // [esp+F0h] [ebp-170h]
  unsigned int v204; // [esp+F4h] [ebp-16Ch]
  __int64 v205; // [esp+F8h] [ebp-168h]
  __int64 v206; // [esp+100h] [ebp-160h]
  __int64 v207; // [esp+108h] [ebp-158h]
  __int64 v208; // [esp+110h] [ebp-150h]
  unsigned __int64 v209; // [esp+118h] [ebp-148h]
  __int64 v210; // [esp+120h] [ebp-140h]
  __int64 v211; // [esp+128h] [ebp-138h]
  int v212; // [esp+134h] [ebp-12Ch]
  int v213; // [esp+13Ch] [ebp-124h]
  __int64 v214; // [esp+140h] [ebp-120h]
  unsigned int v215; // [esp+14Ch] [ebp-114h]
  int v216; // [esp+154h] [ebp-10Ch]
  unsigned int v217; // [esp+15Ch] [ebp-104h]
  unsigned int v218; // [esp+164h] [ebp-FCh]
  unsigned int v219; // [esp+16Ch] [ebp-F4h]
  int v220; // [esp+170h] [ebp-F0h]
  unsigned __int64 v221; // [esp+17Ch] [ebp-E4h]
  int v222; // [esp+184h] [ebp-DCh]
  unsigned __int64 v223; // [esp+188h] [ebp-D8h]
  WHIRLPOOL_CTX *v224; // [esp+194h] [ebp-CCh]
  int v225; // [esp+198h] [ebp-C8h]
  _DWORD v226[16]; // [esp+19Ch] [ebp-C4h] BYREF
  _BYTE v227[64]; // [esp+1DCh] [ebp-84h] BYREF
  _BYTE v228[64]; // [esp+21Ch] [ebp-44h] BYREF

  v224 = ctx;
  if ( ((unsigned int)&unk_800000 & OPENSSL_ia32cap_P) != 0 )
  {
    whirlpool_block_mmx(ctx, inp, n);
  }
  else
  {
    v3 = (char *)ctx - v227;
    v222 = v228 - (_BYTE *)ctx;
    v225 = &v228[1] - (_BYTE *)ctx;
    v168 = inp - v228;
    v4 = inp - v227;
    v170 = inp + 2;
    v166 = inp - v227;
    while ( 1 )
    {
      for ( i = 0; i < 64; ++i )
      {
        v6 = v227[i + v3];
        v227[i] = v6;
        v228[i] = v6 ^ v227[i + v4];
      }
      v7 = &stru_8495F8.q[256];
      v197 = &stru_8495F8.q[256];
      do
      {
        HIDWORD(v211) = HIDWORD(stru_8495F8.q[v227[43]]);
        LODWORD(v211) = *(_DWORD *)&stru_8495F8.c[8 * v227[43]];
        HIDWORD(v172) = HIDWORD(stru_8495F8.q[v227[36]]);
        LODWORD(v172) = *(_DWORD *)&stru_8495F8.c[8 * v227[36]];
        HIDWORD(v199) = HIDWORD(stru_8495F8.q[v227[29]]);
        LODWORD(v199) = *(_DWORD *)&stru_8495F8.c[8 * v227[29]];
        HIDWORD(v214) = HIDWORD(stru_8495F8.q[v227[22]]);
        LODWORD(v221) = *(_DWORD *)&stru_8495F8.c[8 * v227[15]];
        v8 = *(_DWORD *)v7;
        HIDWORD(v221) = HIDWORD(stru_8495F8.q[v227[15]]);
        HIDWORD(v9) = HIDWORD(v214) ^ (v221 >> 24);
        LODWORD(v9) = *(_DWORD *)&stru_8495F8.c[8 * v227[22]] ^ ((_DWORD)v221 << 8);
        LODWORD(v214) = *(_DWORD *)&stru_8495F8.c[8 * v227[22]];
        v226[1] = *((_DWORD *)v7 + 1);
        v10 = *(_DWORD *)&stru_8495F8.c[8 * v227[57]];
        v11 = HIDWORD(stru_8495F8.q[v227[57]]);
        v226[0] = v8;
        v12 = *(_DWORD *)&stru_8495F8.c[8 * v227[50]];
        v13 = HIDWORD(stru_8495F8.q[v227[50]]);
        HIDWORD(v9) = v13 ^ ((v211 ^ ((v172 ^ ((v199 ^ (v9 << 8)) << 8)) << 8)) >> 24);
        LODWORD(v9) = v12
                    ^ (((unsigned int)v211
                      ^ (((unsigned int)v172 ^ (((unsigned int)v199 ^ ((_DWORD)v9 << 8)) << 8)) << 8)) << 8);
        v14 = v11 ^ (v9 >> 24);
        v15 = v10 ^ ((_DWORD)v9 << 8);
        LODWORD(v9) = v12 ^ (__PAIR64__(v11, v10) >> 8);
        HIDWORD(v9) = v13 ^ (v11 >> 8);
        v16 = v221 ^ ((v214 ^ ((v199 ^ ((v172 ^ ((v211 ^ (v9 >> 8)) >> 8)) >> 8)) >> 8)) >> 8);
        v17 = HIDWORD(stru_8495F8.q[v227[0]]) ^ (HIDWORD(v16) >> 8) ^ (__PAIR64__(v14, v15) >> 24);
        v226[0] ^= *(_DWORD *)&stru_8495F8.c[8 * v227[0]] ^ (v16 >> 8) ^ (v15 << 8);
        v226[1] ^= v17;
        v18 = *(_DWORD *)&stru_8495F8.c[8 * v227[1]];
        v19 = HIDWORD(stru_8495F8.q[v227[1]]);
        v20 = *(_DWORD *)&stru_8495F8.c[8 * v227[58]];
        v218 = HIDWORD(stru_8495F8.q[v227[58]]);
        LODWORD(v16) = v20 ^ (__PAIR64__(v19, v18) >> 8);
        HIDWORD(v16) = v218 ^ (v19 >> 8);
        HIDWORD(v201) = HIDWORD(stru_8495F8.q[v227[51]]);
        LODWORD(v201) = *(_DWORD *)&stru_8495F8.c[8 * v227[51]];
        HIDWORD(v176) = HIDWORD(stru_8495F8.q[v227[44]]);
        LODWORD(v176) = *(_DWORD *)&stru_8495F8.c[8 * v227[44]];
        LODWORD(v16) = v176 ^ ((v201 ^ (v16 >> 8)) >> 8);
        HIDWORD(v16) = HIDWORD(v176) ^ ((unsigned int)(HIDWORD(v201) ^ (HIDWORD(v16) >> 8)) >> 8);
        HIDWORD(v206) = HIDWORD(stru_8495F8.q[v227[37]]);
        LODWORD(v206) = *(_DWORD *)&stru_8495F8.c[8 * v227[37]];
        HIDWORD(v174) = HIDWORD(stru_8495F8.q[v227[30]]);
        LODWORD(v174) = *(_DWORD *)&stru_8495F8.c[8 * v227[30]];
        v21 = *(_DWORD *)&stru_8495F8.c[8 * v227[23]];
        v22 = HIDWORD(stru_8495F8.q[v227[23]]);
        LODWORD(v16) = v174 ^ ((v206 ^ (v16 >> 8)) >> 8);
        HIDWORD(v16) = HIDWORD(v174)
                     ^ ((HIDWORD(v206) ^ ((HIDWORD(v176) ^ ((HIDWORD(v201) ^ ((v218 ^ (v19 >> 8)) >> 8)) >> 8)) >> 8)) >> 8);
        v23 = v22 ^ (HIDWORD(v16) >> 8);
        v24 = v21 ^ (v16 >> 8);
        v25 = __PAIR64__(v218, v20)
            ^ ((v201 ^ ((v176 ^ ((v206 ^ ((v174 ^ (__PAIR64__(v22, v21) << 8)) << 8)) << 8)) << 8)) << 8);
        HIDWORD(v25) = v19 ^ (v25 >> 24);
        LODWORD(v25) = v18 ^ ((_DWORD)v25 << 8);
        v26 = *(_DWORD *)&stru_8495F8.c[8 * v227[8]] ^ ((_DWORD)v25 << 8) ^ (__PAIR64__(v23, v24) >> 8);
        v27 = *(_DWORD *)&stru_8495F8.c[8 * v227[9]];
        v28 = HIDWORD(stru_8495F8.q[v227[9]]);
        v29 = HIDWORD(stru_8495F8.q[v227[2]]);
        v30 = *(_DWORD *)&stru_8495F8.c[8 * v227[2]];
        v226[3] = HIDWORD(stru_8495F8.q[v227[8]]) ^ (v25 >> 24) ^ (v23 >> 8);
        v226[2] = v26;
        v212 = v29;
        LODWORD(v25) = v30 ^ (__PAIR64__(v28, v27) >> 8);
        HIDWORD(v25) = v29 ^ (v28 >> 8);
        v204 = HIDWORD(stru_8495F8.q[v227[59]]);
        v203 = *(_DWORD *)&stru_8495F8.c[8 * v227[59]];
        v182 = HIDWORD(stru_8495F8.q[v227[52]]);
        v181 = *(_DWORD *)&stru_8495F8.c[8 * v227[52]];
        LODWORD(v208) = *(_DWORD *)&stru_8495F8.c[8 * v227[45]];
        HIDWORD(v208) = HIDWORD(stru_8495F8.q[v227[45]]);
        LODWORD(v178) = *(_DWORD *)&stru_8495F8.c[8 * v227[38]];
        HIDWORD(v178) = HIDWORD(stru_8495F8.q[v227[38]]);
        v31 = *(_DWORD *)&stru_8495F8.c[8 * v227[31]];
        v32 = HIDWORD(stru_8495F8.q[v227[31]]);
        v33 = v178
            ^ ((v208
              ^ (__PAIR64__(
                   v182 ^ ((v204 ^ (HIDWORD(v25) >> 8)) >> 8),
                   v181 ^ (unsigned int)(__PAIR64__(v204 ^ (HIDWORD(v25) >> 8), v203 ^ (unsigned int)(v25 >> 8)) >> 8)) >> 8)) >> 8);
        v34 = v31 ^ (v33 >> 8);
        v35 = v32 ^ (HIDWORD(v33) >> 8);
        v36 = HIDWORD(v178) ^ (__PAIR64__(v32, v31) >> 24);
        v37 = v178 ^ (v31 << 8);
        v38 = HIDWORD(v208) ^ (__PAIR64__(v36, v37) >> 24);
        v39 = v208 ^ (v37 << 8);
        v40 = v182 ^ (__PAIR64__(v38, v39) >> 24);
        v41 = v181 ^ (v39 << 8);
        v42 = v204 ^ (__PAIR64__(v40, v41) >> 24);
        v43 = v203 ^ (v41 << 8);
        v44 = v212 ^ (__PAIR64__(v42, v43) >> 24);
        v45 = v30 ^ (v43 << 8);
        HIDWORD(v33) = v28 ^ (__PAIR64__(v44, v45) >> 24);
        LODWORD(v33) = v27 ^ (v45 << 8);
        v46 = *(_DWORD *)&stru_8495F8.c[8 * v227[16]] ^ ((_DWORD)v33 << 8) ^ (__PAIR64__(v35, v34) >> 8);
        v47 = *(_DWORD *)&stru_8495F8.c[8 * v227[17]];
        v48 = HIDWORD(stru_8495F8.q[v227[17]]);
        v49 = *(_DWORD *)&stru_8495F8.c[8 * v227[10]];
        v213 = HIDWORD(stru_8495F8.q[v227[10]]);
        v50 = *(_DWORD *)&stru_8495F8.c[8 * v227[3]];
        v51 = HIDWORD(stru_8495F8.q[v227[3]]);
        v226[5] = HIDWORD(stru_8495F8.q[v227[16]]) ^ (v33 >> 24) ^ (v35 >> 8);
        v226[4] = v46;
        v209 = __PAIR64__(v51, v50);
        v189 = HIDWORD(stru_8495F8.q[v227[60]]);
        v188 = *(_DWORD *)&stru_8495F8.c[8 * v227[60]];
        LODWORD(v33) = v49 ^ (__PAIR64__(v48, v47) >> 8);
        HIDWORD(v33) = v213 ^ (v48 >> 8);
        HIDWORD(v210) = HIDWORD(stru_8495F8.q[v227[53]]);
        LODWORD(v210) = *(_DWORD *)&stru_8495F8.c[8 * v227[53]];
        v184 = *(_DWORD *)&stru_8495F8.c[8 * v227[46]];
        v185 = HIDWORD(stru_8495F8.q[v227[46]]);
        v52 = *(_DWORD *)&stru_8495F8.c[8 * v227[39]];
        v53 = HIDWORD(stru_8495F8.q[v227[39]]);
        LODWORD(v33) = v188 ^ ((v209 ^ (v33 >> 8)) >> 8);
        HIDWORD(v33) = v189 ^ ((unsigned int)(HIDWORD(v209) ^ (HIDWORD(v33) >> 8)) >> 8);
        LODWORD(v33) = v184 ^ ((v210 ^ (v33 >> 8)) >> 8);
        HIDWORD(v33) = v185
                     ^ ((HIDWORD(v210) ^ ((v189 ^ ((HIDWORD(v209) ^ ((v213 ^ (v48 >> 8)) >> 8)) >> 8)) >> 8)) >> 8);
        v54 = v52 ^ (v33 >> 8);
        v55 = v53 ^ (HIDWORD(v33) >> 8);
        v56 = v185 ^ (__PAIR64__(v53, v52) >> 24);
        v57 = v184 ^ (v52 << 8);
        v58 = HIDWORD(v210) ^ (__PAIR64__(v56, v57) >> 24);
        v59 = v210 ^ (v57 << 8);
        v60 = v189 ^ (__PAIR64__(v58, v59) >> 24);
        v61 = v188 ^ (v59 << 8);
        v62 = HIDWORD(v209) ^ (__PAIR64__(v60, v61) >> 24);
        v63 = v209 ^ (v61 << 8);
        v64 = v213 ^ (__PAIR64__(v62, v63) >> 24);
        v65 = v49 ^ (v63 << 8);
        HIDWORD(v33) = v48 ^ (__PAIR64__(v64, v65) >> 24);
        LODWORD(v33) = v47 ^ (v65 << 8);
        v66 = *(_DWORD *)&stru_8495F8.c[8 * v227[24]] ^ ((_DWORD)v33 << 8) ^ (__PAIR64__(v55, v54) >> 8);
        v67 = HIDWORD(stru_8495F8.q[v227[24]]) ^ (v33 >> 24) ^ (v55 >> 8);
        v68 = *(_DWORD *)&stru_8495F8.c[8 * v227[25]];
        v69 = HIDWORD(stru_8495F8.q[v227[25]]);
        v70 = *(_DWORD *)&stru_8495F8.c[8 * v227[18]];
        v215 = HIDWORD(stru_8495F8.q[v227[18]]);
        HIDWORD(v205) = HIDWORD(stru_8495F8.q[v227[11]]);
        LODWORD(v205) = *(_DWORD *)&stru_8495F8.c[8 * v227[11]];
        v195 = HIDWORD(stru_8495F8.q[v227[4]]);
        v194 = *(_DWORD *)&stru_8495F8.c[8 * v227[4]];
        HIDWORD(v207) = HIDWORD(stru_8495F8.q[v227[61]]);
        LODWORD(v207) = *(_DWORD *)&stru_8495F8.c[8 * v227[61]];
        v191 = *(_DWORD *)&stru_8495F8.c[8 * v227[54]];
        v192 = HIDWORD(stru_8495F8.q[v227[54]]);
        v71 = *(_DWORD *)&stru_8495F8.c[8 * v227[47]];
        v72 = HIDWORD(stru_8495F8.q[v227[47]]);
        v226[6] = v66;
        v226[7] = v67;
        LODWORD(v33) = v194 ^ ((v205 ^ ((__PAIR64__(v215, v70) ^ (__PAIR64__(v69, v68) >> 8)) >> 8)) >> 8);
        HIDWORD(v33) = v195 ^ ((HIDWORD(v205) ^ ((v215 ^ (v69 >> 8)) >> 8)) >> 8);
        LODWORD(v33) = v191 ^ ((v207 ^ (v33 >> 8)) >> 8);
        HIDWORD(v33) = v192 ^ ((unsigned int)(HIDWORD(v207) ^ (HIDWORD(v33) >> 8)) >> 8);
        v73 = v71 ^ (v33 >> 8);
        v74 = v72
            ^ ((v192 ^ ((HIDWORD(v207) ^ ((v195 ^ ((HIDWORD(v205) ^ ((v215 ^ (v69 >> 8)) >> 8)) >> 8)) >> 8)) >> 8)) >> 8);
        v75 = v192 ^ (__PAIR64__(v72, v71) >> 24);
        v76 = v191 ^ (v71 << 8);
        v77 = HIDWORD(v207) ^ (__PAIR64__(v75, v76) >> 24);
        v78 = v207 ^ (v76 << 8);
        v79 = v195 ^ (__PAIR64__(v77, v78) >> 24);
        v80 = v194 ^ (v78 << 8);
        v81 = HIDWORD(v205) ^ (__PAIR64__(v79, v80) >> 24);
        v82 = v205 ^ (v80 << 8);
        v83 = v215 ^ (__PAIR64__(v81, v82) >> 24);
        v84 = v70 ^ (v82 << 8);
        HIDWORD(v33) = v69 ^ (__PAIR64__(v83, v84) >> 24);
        LODWORD(v33) = v68 ^ (v84 << 8);
        v85 = *(_DWORD *)&stru_8495F8.c[8 * v227[32]] ^ ((_DWORD)v33 << 8) ^ (__PAIR64__(v74, v73) >> 8);
        v86 = HIDWORD(stru_8495F8.q[v227[32]]) ^ (v33 >> 24) ^ (v74 >> 8);
        v87 = *(_DWORD *)&stru_8495F8.c[8 * v227[33]];
        v88 = HIDWORD(stru_8495F8.q[v227[33]]);
        v89 = *(_DWORD *)&stru_8495F8.c[8 * v227[26]];
        v217 = HIDWORD(stru_8495F8.q[v227[26]]);
        HIDWORD(v169) = HIDWORD(stru_8495F8.q[v227[19]]);
        LODWORD(v169) = *(_DWORD *)&stru_8495F8.c[8 * v227[19]];
        HIDWORD(v167) = HIDWORD(stru_8495F8.q[v227[12]]);
        LODWORD(v167) = *(_DWORD *)&stru_8495F8.c[8 * v227[12]];
        v90 = *(_DWORD *)&stru_8495F8.c[8 * v227[5]];
        v91 = HIDWORD(stru_8495F8.q[v227[5]]);
        v226[8] = v85;
        v226[9] = v86;
        HIDWORD(v165) = HIDWORD(stru_8495F8.q[v227[62]]);
        LODWORD(v33) = v167 ^ ((v169 ^ ((__PAIR64__(v217, v89) ^ (__PAIR64__(v88, v87) >> 8)) >> 8)) >> 8);
        HIDWORD(v33) = HIDWORD(v167) ^ ((HIDWORD(v169) ^ ((v217 ^ (v88 >> 8)) >> 8)) >> 8);
        LODWORD(v165) = *(_DWORD *)&stru_8495F8.c[8 * v227[62]];
        LODWORD(v33) = v90 ^ (v33 >> 8);
        HIDWORD(v33) = v91 ^ (HIDWORD(v33) >> 8);
        v92 = v165 ^ (v33 >> 8);
        v93 = *(_DWORD *)&stru_8495F8.c[8 * v227[55]] ^ (v92 >> 8);
        v94 = HIDWORD(stru_8495F8.q[v227[55]]) ^ (HIDWORD(v92) >> 8);
        HIDWORD(v92) = HIDWORD(stru_8495F8.q[v227[55]]);
        LODWORD(v92) = *(_DWORD *)&stru_8495F8.c[8 * v227[55]];
        v95 = v165 ^ (v92 << 8);
        HIDWORD(v95) = v91 ^ (v95 >> 24);
        LODWORD(v95) = v90 ^ ((_DWORD)v95 << 8);
        v96 = __PAIR64__(v217, v89) ^ ((v169 ^ ((v167 ^ (v95 << 8)) << 8)) << 8);
        HIDWORD(v96) = v88 ^ (v96 >> 24);
        LODWORD(v96) = v87 ^ ((_DWORD)v96 << 8);
        v97 = *(_DWORD *)&stru_8495F8.c[8 * v227[40]] ^ ((_DWORD)v96 << 8) ^ (__PAIR64__(v94, v93) >> 8);
        v98 = HIDWORD(stru_8495F8.q[v227[40]]) ^ (v96 >> 24) ^ (v94 >> 8);
        v99 = *(_DWORD *)&stru_8495F8.c[8 * v227[41]];
        v100 = HIDWORD(stru_8495F8.q[v227[41]]);
        v101 = *(_DWORD *)&stru_8495F8.c[8 * v227[34]];
        v219 = HIDWORD(stru_8495F8.q[v227[34]]);
        v102 = *(_DWORD *)&stru_8495F8.c[8 * v227[27]];
        v226[10] = v97;
        v226[11] = v98;
        LODWORD(v177) = v102;
        HIDWORD(v177) = HIDWORD(stru_8495F8.q[v227[27]]);
        HIDWORD(v175) = HIDWORD(stru_8495F8.q[v227[20]]);
        LODWORD(v175) = *(_DWORD *)&stru_8495F8.c[8 * v227[20]];
        HIDWORD(v173) = HIDWORD(stru_8495F8.q[v227[13]]);
        LODWORD(v173) = *(_DWORD *)&stru_8495F8.c[8 * v227[13]];
        LODWORD(v96) = v175 ^ ((v177 ^ ((__PAIR64__(v219, v101) ^ (__PAIR64__(v100, v99) >> 8)) >> 8)) >> 8);
        HIDWORD(v96) = HIDWORD(v175) ^ ((HIDWORD(v177) ^ ((v219 ^ (v100 >> 8)) >> 8)) >> 8);
        HIDWORD(v171) = HIDWORD(stru_8495F8.q[v227[6]]);
        LODWORD(v171) = *(_DWORD *)&stru_8495F8.c[8 * v227[6]];
        LODWORD(v96) = v171 ^ ((v173 ^ (v96 >> 8)) >> 8);
        HIDWORD(v96) = HIDWORD(v171) ^ ((unsigned int)(HIDWORD(v173) ^ (HIDWORD(v96) >> 8)) >> 8);
        v103 = *(_DWORD *)&stru_8495F8.c[8 * v227[63]] ^ (v96 >> 8);
        v104 = HIDWORD(stru_8495F8.q[v227[63]])
             ^ ((HIDWORD(v171)
               ^ ((HIDWORD(v173) ^ ((HIDWORD(v175) ^ ((HIDWORD(v177) ^ ((v219 ^ (v100 >> 8)) >> 8)) >> 8)) >> 8)) >> 8)) >> 8);
        HIDWORD(v96) = HIDWORD(stru_8495F8.q[v227[63]]);
        LODWORD(v96) = *(_DWORD *)&stru_8495F8.c[8 * v227[63]];
        v105 = __PAIR64__(v104, v103) >> 8;
        v106 = __PAIR64__(v219, v101) ^ ((v177 ^ ((v175 ^ ((v173 ^ ((v171 ^ (v96 << 8)) << 8)) << 8)) << 8)) << 8);
        HIDWORD(v106) = v100 ^ (v106 >> 24);
        LODWORD(v106) = v99 ^ ((_DWORD)v106 << 8);
        v107 = HIDWORD(stru_8495F8.q[v227[48]]) ^ (v106 >> 24) ^ (v104 >> 8);
        v226[12] = *(_DWORD *)&stru_8495F8.c[8 * v227[48]] ^ ((_DWORD)v106 << 8) ^ v105;
        v226[13] = v107;
        v108 = *(_DWORD *)&stru_8495F8.c[8 * v227[49]];
        v109 = HIDWORD(stru_8495F8.q[v227[49]]);
        v110 = *(_DWORD *)&stru_8495F8.c[8 * v227[42]];
        v216 = HIDWORD(stru_8495F8.q[v227[42]]);
        HIDWORD(v190) = HIDWORD(stru_8495F8.q[v227[35]]);
        LODWORD(v190) = *(_DWORD *)&stru_8495F8.c[8 * v227[35]];
        LODWORD(v106) = v110 ^ (__PAIR64__(v109, v108) >> 8);
        HIDWORD(v106) = v216 ^ (v109 >> 8);
        v187 = HIDWORD(stru_8495F8.q[v227[28]]);
        v186 = *(_DWORD *)&stru_8495F8.c[8 * v227[28]];
        HIDWORD(v183) = HIDWORD(stru_8495F8.q[v227[21]]);
        LODWORD(v106) = v186 ^ ((v190 ^ (v106 >> 8)) >> 8);
        HIDWORD(v106) = v187 ^ ((unsigned int)(HIDWORD(v190) ^ (HIDWORD(v106) >> 8)) >> 8);
        LODWORD(v183) = *(_DWORD *)&stru_8495F8.c[8 * v227[21]];
        v180 = HIDWORD(stru_8495F8.q[v227[14]]);
        v179 = *(_DWORD *)&stru_8495F8.c[8 * v227[14]];
        v111 = *(_DWORD *)&stru_8495F8.c[8 * v227[7]];
        v112 = HIDWORD(stru_8495F8.q[v227[7]]);
        LODWORD(v106) = v179 ^ ((v183 ^ (v106 >> 8)) >> 8);
        HIDWORD(v106) = v180
                      ^ ((HIDWORD(v183) ^ ((v187 ^ ((HIDWORD(v190) ^ ((v216 ^ (v109 >> 8)) >> 8)) >> 8)) >> 8)) >> 8);
        v113 = v111 ^ (v106 >> 8);
        v114 = v112 ^ (HIDWORD(v106) >> 8);
        v115 = v180 ^ (__PAIR64__(v112, v111) >> 24);
        v116 = v179 ^ (v111 << 8);
        v117 = HIDWORD(v183) ^ (__PAIR64__(v115, v116) >> 24);
        v118 = v183 ^ (v116 << 8);
        v119 = v187 ^ (__PAIR64__(v117, v118) >> 24);
        v120 = v186 ^ (v118 << 8);
        v121 = HIDWORD(v190) ^ (__PAIR64__(v119, v120) >> 24);
        v122 = v190 ^ (v120 << 8);
        v123 = v216 ^ (__PAIR64__(v121, v122) >> 24);
        v124 = v110 ^ (v122 << 8);
        HIDWORD(v106) = v109 ^ (__PAIR64__(v123, v124) >> 24);
        LODWORD(v106) = v108 ^ (v124 << 8);
        v125 = *(_DWORD *)&stru_8495F8.c[8 * v227[56]] ^ ((_DWORD)v106 << 8) ^ (__PAIR64__(v114, v113) >> 8);
        v126 = HIDWORD(stru_8495F8.q[v227[56]]) ^ (v106 >> 24) ^ (v114 >> 8);
        v226[14] = v125;
        v226[15] = v126;
        v127 = 2;
        qmemcpy(v227, v226, sizeof(v227));
        v128 = 0;
        v129 = 8;
        do
        {
          v130 = (unsigned __int8)v228[8 * (((_BYTE)v127 - 3) & 7) + 1];
          v131 = *(_DWORD *)&stru_8495F8.c[8 * v130];
          v132 = HIDWORD(stru_8495F8.q[v130]);
          v133 = (unsigned __int8)v228[8 * (((_BYTE)v127 - 4) & 7) + 2];
          v134 = *(_DWORD *)&stru_8495F8.c[8 * v133];
          HIDWORD(v202) = HIDWORD(stru_8495F8.q[v133]);
          v223 = __PAIR64__(v132, v131);
          v135 = (unsigned __int8)v228[8 * (((_BYTE)v127 + 3) & 7) + 3];
          LODWORD(v202) = v134;
          v136 = *(_DWORD *)&stru_8495F8.c[8 * v135];
          HIDWORD(v200) = HIDWORD(stru_8495F8.q[v135]);
          v137 = (unsigned __int8)v228[8 * (((_BYTE)v127 + 2) & 7) + 4];
          LODWORD(v200) = v136;
          v138 = *(_DWORD *)&stru_8495F8.c[8 * v137];
          HIDWORD(v198) = HIDWORD(stru_8495F8.q[v137]);
          v220 = v127 + 1;
          v139 = (unsigned __int8)v228[8 * ((v127 + 1) & 7) + 5];
          LODWORD(v198) = v138;
          v140 = *(_DWORD *)&stru_8495F8.c[8 * v139];
          v141 = v198 ^ ((v200 ^ ((v202 ^ (__PAIR64__(v132, v131) >> 8)) >> 8)) >> 8);
          HIDWORD(v196) = HIDWORD(stru_8495F8.q[v139]);
          v142 = HIDWORD(v196) ^ (HIDWORD(v141) >> 8);
          v143 = (unsigned __int8)v228[8 * (v127 & 7) + 6];
          LODWORD(v196) = v140;
          v144 = v140 ^ (v141 >> 8);
          v145 = *(_DWORD *)&stru_8495F8.c[8 * v143];
          v193 = HIDWORD(stru_8495F8.q[v143]);
          v146 = (unsigned __int8)v228[8 * (((_BYTE)v127 - 1) & 7) + 7];
          v147 = *(_DWORD *)&stru_8495F8.c[8 * v146];
          v148 = HIDWORD(stru_8495F8.q[v146]);
          LODWORD(v141) = v145 ^ (__PAIR64__(v142, v144) >> 8);
          HIDWORD(v141) = v193 ^ (v142 >> 8);
          v149 = v148 ^ (HIDWORD(v141) >> 8);
          v150 = v147 ^ (v141 >> 8);
          v128 += 8;
          LODWORD(v141) = v223
                        ^ (((unsigned int)v202
                          ^ (((unsigned int)v200
                            ^ (((unsigned int)v198 ^ (((unsigned int)v196 ^ ((v145 ^ (v147 << 8)) << 8)) << 8)) << 8)) << 8)) << 8);
          v151 = (v223
                ^ ((v202
                  ^ ((v200
                    ^ ((v198
                      ^ ((v196
                        ^ (__PAIR64__(v193 ^ (unsigned int)(__PAIR64__(v148, v147) >> 24), v145 ^ (v147 << 8)) << 8)) << 8)) << 8)) << 8)) << 8)) >> 24;
          v152 = (unsigned __int8)v227[v128 + 56];
          v153 = *(_DWORD *)&stru_8495F8.c[8 * v152] ^ ((_DWORD)v141 << 8) ^ (__PAIR64__(v149, v150) >> 8);
          v154 = HIDWORD(stru_8495F8.q[v152]) ^ v151 ^ (v149 >> 8);
          *(WHIRLPOOL_CTX **)((char *)&v224 + v128) = (WHIRLPOOL_CTX *)(v153 ^ *(unsigned int *)((char *)&v224 + v128));
          v226[v128 / 4 - 1] ^= v154;
          --v129;
          v127 = v220;
        }
        while ( v129 );
        v7 = v197 + 1;
        v155 = (int)(v197 + 1) < (int)"ECDSA part of OpenSSL 1.0.0g 18 Jan 2012";
        qmemcpy(v228, v226, sizeof(v228));
        ++v197;
      }
      while ( v155 );
      v156 = v170;
      v157 = v224;
      v158 = 16;
      do
      {
        v159 = &v157->H.c[v222];
        v160 = v157->H.c[0] ^ v157->H.c[v222 + v168];
        v157 = (WHIRLPOOL_CTX *)((char *)v157 + 4);
        v161 = *v159 ^ v160;
        v162 = v225;
        LOBYTE(v157[-1].bitlen[8]) = v161;
        BYTE1(v157[-1].bitlen[8]) ^= *(v156 - 1) ^ v157->H.c[v162 - 4];
        v163 = *v156 ^ BYTE2(v157[-1].bitlen[8]) ^ v157->H.c[&v228[2] - (_BYTE *)ctx - 4];
        v156 += 4;
        BYTE2(v157[-1].bitlen[8]) = v163;
        HIBYTE(v157[-1].bitlen[8]) ^= *(v156 - 3) ^ v157->H.c[&v228[3] - (_BYTE *)ctx - 4];
        --v158;
      }
      while ( v158 );
      v4 = v166 + 64;
      v164 = n-- == 1;
      v166 += 64;
      v170 = v156;
      v168 += 64;
      if ( v164 )
        break;
      v3 = (char *)ctx - v227;
    }
  }
}
