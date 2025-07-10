void __cdecl idea_encrypt(unsigned int *d, idea_key_st *key)
{
  unsigned int v2; // ecx
  unsigned int v3; // edx
  unsigned int v4; // edx
  unsigned int v5; // ebp
  unsigned int v6; // ebx
  __int16 v7; // dx
  unsigned int *v8; // eax
  int v9; // esi
  unsigned int v10; // ecx
  unsigned int v11; // edi
  unsigned int v12; // esi
  unsigned int *v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // edx
  unsigned int v16; // edx
  unsigned int v17; // ecx
  _DWORD *v18; // eax
  unsigned int v19; // esi
  unsigned int v20; // ecx
  unsigned int v21; // ecx
  unsigned int v22; // ecx
  unsigned int v23; // edx
  unsigned __int16 v24; // di
  int v25; // edx
  int v26; // ebp
  _DWORD *v27; // eax
  int v28; // esi
  int v29; // ecx
  int v30; // esi
  _DWORD *v31; // eax
  int v32; // ebx
  int v33; // edx
  _DWORD *v34; // eax
  unsigned int v35; // ebp
  int v36; // edi
  _DWORD *v37; // eax
  unsigned int v38; // ecx
  unsigned int v39; // edx
  unsigned int v40; // edx
  int v41; // ecx
  _DWORD *v42; // eax
  unsigned int v43; // edi
  unsigned int v44; // ecx
  unsigned int v45; // ecx
  unsigned int v46; // ecx
  int v47; // edi
  unsigned int v48; // edx
  unsigned __int16 v49; // bp
  int v50; // edx
  _DWORD *v51; // eax
  int v52; // esi
  int v53; // ecx
  int v54; // esi
  _DWORD *v55; // eax
  int v56; // ebx
  int v57; // edx
  _DWORD *v58; // eax
  unsigned int v59; // ebx
  int v60; // edi
  _DWORD *v61; // eax
  unsigned int v62; // ecx
  unsigned int v63; // edx
  int v64; // ebp
  unsigned int v65; // edx
  _DWORD *v66; // eax
  unsigned int v67; // edi
  unsigned int v68; // ecx
  unsigned int v69; // ecx
  int v70; // edi
  unsigned int v71; // edx
  unsigned __int16 v72; // bx
  int v73; // edx
  int v74; // esi
  _DWORD *v75; // eax
  int v76; // ecx
  int v77; // esi
  _DWORD *v78; // eax
  int v79; // ebp
  int v80; // edx
  _DWORD *v81; // eax
  unsigned int v82; // ebp
  int v83; // edi
  _DWORD *v84; // eax
  unsigned int v85; // ecx
  unsigned int v86; // edx
  int v87; // ebx
  unsigned int v88; // edx
  int v89; // eax
  unsigned int v90; // edi
  unsigned int v91; // ecx
  unsigned int v92; // ecx
  int v93; // edi
  unsigned int v94; // edx
  unsigned __int16 v95; // bp
  int v96; // edx
  int v97; // esi
  int v98; // eax
  int v99; // ecx
  int v100; // esi
  int v101; // eax
  int v102; // ebx
  int v103; // edx
  int v104; // eax
  unsigned int v105; // ebx
  int v106; // edi
  int v107; // eax
  unsigned int v108; // ecx
  unsigned int v109; // edx
  int v110; // ebp
  unsigned int v111; // edx
  int v112; // eax
  unsigned int v113; // edi
  unsigned int v114; // ecx
  unsigned int v115; // ecx
  int v116; // edi
  unsigned int v117; // edx
  unsigned __int16 v118; // bx
  int v119; // edx
  int v120; // esi
  int v121; // eax
  int v122; // ecx
  int v123; // esi
  int v124; // eax
  int v125; // ebp
  int v126; // edx
  int v127; // eax
  unsigned int v128; // ebp
  int v129; // edi
  int v130; // eax
  unsigned int v131; // ecx
  unsigned int v132; // edx
  int v133; // ebx
  unsigned int v134; // edx
  int v135; // eax
  unsigned int v136; // edi
  unsigned int v137; // ecx
  unsigned int v138; // ecx
  int v139; // edi
  unsigned int v140; // edx
  unsigned __int16 v141; // bp
  int v142; // edx
  int v143; // esi
  int v144; // eax
  int v145; // ecx
  int v146; // esi
  int v147; // eax
  int v148; // ebx
  int v149; // edx
  int v150; // eax
  unsigned int v151; // ebx
  int v152; // edi
  int v153; // eax
  unsigned int v154; // ecx
  unsigned int v155; // edx
  int v156; // ebp
  unsigned int v157; // edx
  int v158; // eax
  unsigned int v159; // edi
  unsigned int v160; // ecx
  unsigned int v161; // ecx
  int v162; // edi
  unsigned int v163; // edx
  unsigned __int16 v164; // bx
  int v165; // edx
  int v166; // esi
  int v167; // eax
  int v168; // ecx
  int v169; // esi
  int v170; // eax
  int v171; // ebp
  int v172; // edx
  int v173; // eax
  unsigned int v174; // edi
  int v175; // ebx
  int v176; // eax
  unsigned int v177; // ecx
  unsigned int v178; // edx
  unsigned int v179; // edx
  int v180; // ecx
  _DWORD *v181; // eax
  unsigned int v182; // ebx
  unsigned int v183; // ecx
  unsigned int v184; // ecx
  unsigned int v185; // ecx
  int v186; // ebx
  unsigned int v187; // edx
  unsigned __int16 v188; // di
  int v189; // edx
  unsigned int v190; // esi
  _DWORD *v191; // eax
  int v192; // ecx
  int v193; // esi
  unsigned int v194; // ebp
  int v195; // ebx
  _DWORD *v196; // eax
  int v197; // ecx
  int v198; // eax
  int v199; // ecx
  unsigned int v200; // edx
  unsigned int v201; // edx
  int v202; // [esp+10h] [ebp-4h]
  int v203; // [esp+10h] [ebp-4h]
  int v204; // [esp+10h] [ebp-4h]
  int v205; // [esp+10h] [ebp-4h]
  int v206; // [esp+10h] [ebp-4h]
  __int16 v207; // [esp+1Ch] [ebp+8h]
  unsigned int v208; // [esp+1Ch] [ebp+8h]
  unsigned int v209; // [esp+1Ch] [ebp+8h]
  unsigned int v210; // [esp+1Ch] [ebp+8h]
  unsigned int v211; // [esp+1Ch] [ebp+8h]
  unsigned int v212; // [esp+1Ch] [ebp+8h]
  unsigned int v213; // [esp+1Ch] [ebp+8h]
  unsigned int v214; // [esp+1Ch] [ebp+8h]

  v2 = HIWORD(*d);
  v3 = v2 * key->data[0][0];
  if ( v3 )
  {
    v4 = (unsigned __int16)v3 - HIWORD(v3);
    v2 = HIWORD(v4);
  }
  else
  {
    v4 = 1 - key->data[0][0];
  }
  v5 = key->data[0][1] + *d;
  v6 = key->data[0][2] + HIWORD(d[1]);
  v7 = v4 - v2;
  v8 = &key->data[0][3];
  v9 = (unsigned __int16)d[1];
  v10 = v9 * key->data[0][3];
  v207 = v7;
  if ( v10 )
    v11 = (unsigned __int16)v10 - HIWORD(v10) - ((unsigned int)((unsigned __int16)v10 - HIWORD(v10)) >> 16);
  else
    v11 = 1 - *v8 - v9;
  v12 = v8[1];
  v13 = v8 + 1;
  v14 = (unsigned __int16)(v7 ^ v6);
  if ( v14 * v12 )
  {
    v15 = (unsigned __int16)(v14 * v12) - ((v14 * v12) >> 16);
    v14 = HIWORD(v15);
  }
  else
  {
    v15 = 1 - v12;
  }
  v16 = v15 - v14;
  v17 = v13[1];
  v18 = v13 + 1;
  v19 = (unsigned __int16)(v16 + (v5 ^ v11));
  v20 = v19 * v17;
  if ( v20 )
  {
    v21 = (unsigned __int16)v20 - HIWORD(v20);
    v19 = HIWORD(v21);
  }
  else
  {
    v21 = 1 - *v18;
  }
  v22 = v21 - v19;
  v23 = v22 + v16;
  v24 = v23 ^ v11;
  v25 = v5 ^ v23;
  v26 = v18[1];
  v27 = v18 + 1;
  v28 = v6 ^ v22;
  v29 = (unsigned __int16)(v207 ^ v22);
  if ( v29 * v26 )
    v208 = (unsigned __int16)(v29 * v26)
         - ((unsigned int)(v29 * v26) >> 16)
         - (((unsigned __int16)(v29 * v26) - ((unsigned int)(v29 * v26) >> 16)) >> 16);
  else
    LOWORD(v208) = 1 - v26 - v29;
  v30 = v27[1] + v28;
  v31 = v27 + 1;
  v32 = v31[1] + v25;
  ++v31;
  v33 = v31[1];
  v34 = v31 + 1;
  if ( v24 * v33 )
    v35 = (unsigned __int16)(v24 * v33)
        - (((unsigned int)v24 * v33) >> 16)
        - (((unsigned __int16)(v24 * v33) - (((unsigned int)v24 * v33) >> 16)) >> 16);
  else
    LOWORD(v35) = 1 - v33 - v24;
  v36 = v34[1];
  v37 = v34 + 1;
  v38 = (unsigned __int16)(v208 ^ v32);
  if ( v38 * v36 )
  {
    v39 = (unsigned __int16)(v38 * v36) - ((v38 * v36) >> 16);
    v38 = HIWORD(v39);
  }
  else
  {
    v39 = 1 - v36;
  }
  v40 = v39 - v38;
  v41 = v37[1];
  v42 = v37 + 1;
  v43 = (unsigned __int16)(v40 + (v30 ^ v35));
  v44 = v43 * v41;
  if ( v44 )
  {
    v45 = (unsigned __int16)v44 - HIWORD(v44);
    v43 = HIWORD(v45);
  }
  else
  {
    v45 = 1 - *v42;
  }
  v46 = v45 - v43;
  v47 = v42[1];
  v48 = v46 + v40;
  v49 = v48 ^ v35;
  v50 = v30 ^ v48;
  v51 = v42 + 1;
  v52 = v32 ^ v46;
  v53 = (unsigned __int16)(v208 ^ v46);
  if ( v53 * v47 )
    v209 = (unsigned __int16)(v53 * v47)
         - ((unsigned int)(v53 * v47) >> 16)
         - (((unsigned __int16)(v53 * v47) - ((unsigned int)(v53 * v47) >> 16)) >> 16);
  else
    LOWORD(v209) = 1 - v47 - v53;
  v54 = v51[1] + v52;
  v55 = v51 + 1;
  v56 = v55[1] + v50;
  ++v55;
  v57 = v55[1];
  v58 = v55 + 1;
  v202 = v56;
  if ( v49 * v57 )
    v59 = (unsigned __int16)(v49 * v57)
        - (((unsigned int)v49 * v57) >> 16)
        - (((unsigned __int16)(v49 * v57) - (((unsigned int)v49 * v57) >> 16)) >> 16);
  else
    LOWORD(v59) = 1 - v57 - v49;
  v60 = v58[1];
  v61 = v58 + 1;
  v62 = (unsigned __int16)(v209 ^ v202);
  if ( v62 * v60 )
  {
    v63 = (unsigned __int16)(v62 * v60) - ((v62 * v60) >> 16);
    v62 = HIWORD(v63);
  }
  else
  {
    v63 = 1 - v60;
  }
  v64 = v61[1];
  v65 = v63 - v62;
  v66 = v61 + 1;
  v67 = (unsigned __int16)(v65 + (v54 ^ v59));
  if ( v67 * v64 )
  {
    v68 = (unsigned __int16)(v67 * v64) - ((v67 * v64) >> 16);
    v67 = HIWORD(v68);
  }
  else
  {
    v68 = 1 - v64;
  }
  v69 = v68 - v67;
  v70 = v66[1];
  v71 = v69 + v65;
  v72 = v71 ^ v59;
  v73 = v54 ^ v71;
  v74 = v202 ^ v69;
  v75 = v66 + 1;
  v76 = (unsigned __int16)(v209 ^ v69);
  if ( v76 * v70 )
    v210 = (unsigned __int16)(v76 * v70)
         - ((unsigned int)(v76 * v70) >> 16)
         - (((unsigned __int16)(v76 * v70) - ((unsigned int)(v76 * v70) >> 16)) >> 16);
  else
    LOWORD(v210) = 1 - v70 - v76;
  v77 = v75[1] + v74;
  v78 = v75 + 1;
  v79 = v78[1] + v73;
  ++v78;
  v80 = v78[1];
  v81 = v78 + 1;
  v203 = v79;
  if ( v72 * v80 )
    v82 = (unsigned __int16)(v72 * v80)
        - (((unsigned int)v72 * v80) >> 16)
        - (((unsigned __int16)(v72 * v80) - (((unsigned int)v72 * v80) >> 16)) >> 16);
  else
    LOWORD(v82) = 1 - v80 - v72;
  v83 = v81[1];
  v84 = (int)(v81 + 1);
  v85 = (unsigned __int16)(v210 ^ v203);
  if ( v85 * v83 )
  {
    v86 = (unsigned __int16)(v85 * v83) - ((v85 * v83) >> 16);
    v85 = HIWORD(v86);
  }
  else
  {
    v86 = 1 - v83;
  }
  v87 = *(_DWORD *)(v84 + 4);
  v88 = v86 - v85;
  v89 = v84 + 4;
  v90 = (unsigned __int16)(v88 + (v77 ^ v82));
  if ( v90 * v87 )
  {
    v91 = (unsigned __int16)(v90 * v87) - ((v90 * v87) >> 16);
    v90 = HIWORD(v91);
  }
  else
  {
    v91 = 1 - v87;
  }
  v92 = v91 - v90;
  v93 = *(_DWORD *)(v89 + 4);
  v94 = v92 + v88;
  v95 = v94 ^ v82;
  v96 = v77 ^ v94;
  v97 = v203 ^ v92;
  v98 = v89 + 4;
  v99 = (unsigned __int16)(v210 ^ v92);
  if ( v99 * v93 )
    v211 = (unsigned __int16)(v99 * v93)
         - ((unsigned int)(v99 * v93) >> 16)
         - (((unsigned __int16)(v99 * v93) - ((unsigned int)(v99 * v93) >> 16)) >> 16);
  else
    LOWORD(v211) = 1 - v93 - v99;
  v100 = *(_DWORD *)(v98 + 4) + v97;
  v101 = v98 + 4;
  v102 = *(_DWORD *)(v101 + 4) + v96;
  v101 += 4;
  v103 = *(_DWORD *)(v101 + 4);
  v104 = v101 + 4;
  v204 = v102;
  if ( v95 * v103 )
    v105 = (unsigned __int16)(v95 * v103)
         - (((unsigned int)v95 * v103) >> 16)
         - (((unsigned __int16)(v95 * v103) - (((unsigned int)v95 * v103) >> 16)) >> 16);
  else
    LOWORD(v105) = 1 - v103 - v95;
  v106 = *(_DWORD *)(v104 + 4);
  v107 = v104 + 4;
  v108 = (unsigned __int16)(v211 ^ v204);
  if ( v108 * v106 )
  {
    v109 = (unsigned __int16)(v108 * v106) - ((v108 * v106) >> 16);
    v108 = HIWORD(v109);
  }
  else
  {
    v109 = 1 - v106;
  }
  v110 = *(_DWORD *)(v107 + 4);
  v111 = v109 - v108;
  v112 = v107 + 4;
  v113 = (unsigned __int16)(v111 + (v100 ^ v105));
  if ( v113 * v110 )
  {
    v114 = (unsigned __int16)(v113 * v110) - ((v113 * v110) >> 16);
    v113 = HIWORD(v114);
  }
  else
  {
    v114 = 1 - v110;
  }
  v115 = v114 - v113;
  v116 = *(_DWORD *)(v112 + 4);
  v117 = v115 + v111;
  v118 = v117 ^ v105;
  v119 = v100 ^ v117;
  v120 = v204 ^ v115;
  v121 = v112 + 4;
  v122 = (unsigned __int16)(v211 ^ v115);
  if ( v122 * v116 )
    v212 = (unsigned __int16)(v122 * v116)
         - ((unsigned int)(v122 * v116) >> 16)
         - (((unsigned __int16)(v122 * v116) - ((unsigned int)(v122 * v116) >> 16)) >> 16);
  else
    LOWORD(v212) = 1 - v116 - v122;
  v123 = *(_DWORD *)(v121 + 4) + v120;
  v124 = v121 + 4;
  v125 = *(_DWORD *)(v124 + 4) + v119;
  v124 += 4;
  v126 = *(_DWORD *)(v124 + 4);
  v127 = v124 + 4;
  v205 = v125;
  if ( v118 * v126 )
    v128 = (unsigned __int16)(v118 * v126)
         - (((unsigned int)v118 * v126) >> 16)
         - (((unsigned __int16)(v118 * v126) - (((unsigned int)v118 * v126) >> 16)) >> 16);
  else
    LOWORD(v128) = 1 - v126 - v118;
  v129 = *(_DWORD *)(v127 + 4);
  v130 = v127 + 4;
  v131 = (unsigned __int16)(v212 ^ v205);
  if ( v131 * v129 )
  {
    v132 = (unsigned __int16)(v131 * v129) - ((v131 * v129) >> 16);
    v131 = HIWORD(v132);
  }
  else
  {
    v132 = 1 - v129;
  }
  v133 = *(_DWORD *)(v130 + 4);
  v134 = v132 - v131;
  v135 = v130 + 4;
  v136 = (unsigned __int16)(v134 + (v123 ^ v128));
  if ( v136 * v133 )
  {
    v137 = (unsigned __int16)(v136 * v133) - ((v136 * v133) >> 16);
    v136 = HIWORD(v137);
  }
  else
  {
    v137 = 1 - v133;
  }
  v138 = v137 - v136;
  v139 = *(_DWORD *)(v135 + 4);
  v140 = v138 + v134;
  v141 = v140 ^ v128;
  v142 = v123 ^ v140;
  v143 = v205 ^ v138;
  v144 = v135 + 4;
  v145 = (unsigned __int16)(v212 ^ v138);
  if ( v145 * v139 )
    v213 = (unsigned __int16)(v145 * v139)
         - ((unsigned int)(v145 * v139) >> 16)
         - (((unsigned __int16)(v145 * v139) - ((unsigned int)(v145 * v139) >> 16)) >> 16);
  else
    LOWORD(v213) = 1 - v139 - v145;
  v146 = *(_DWORD *)(v144 + 4) + v143;
  v147 = v144 + 4;
  v148 = *(_DWORD *)(v147 + 4) + v142;
  v147 += 4;
  v149 = *(_DWORD *)(v147 + 4);
  v150 = v147 + 4;
  v206 = v148;
  if ( v141 * v149 )
    v151 = (unsigned __int16)(v141 * v149)
         - (((unsigned int)v141 * v149) >> 16)
         - (((unsigned __int16)(v141 * v149) - (((unsigned int)v141 * v149) >> 16)) >> 16);
  else
    LOWORD(v151) = 1 - v149 - v141;
  v152 = *(_DWORD *)(v150 + 4);
  v153 = v150 + 4;
  v154 = (unsigned __int16)(v213 ^ v206);
  if ( v154 * v152 )
  {
    v155 = (unsigned __int16)(v154 * v152) - ((v154 * v152) >> 16);
    v154 = HIWORD(v155);
  }
  else
  {
    v155 = 1 - v152;
  }
  v156 = *(_DWORD *)(v153 + 4);
  v157 = v155 - v154;
  v158 = v153 + 4;
  v159 = (unsigned __int16)(v157 + (v146 ^ v151));
  if ( v159 * v156 )
  {
    v160 = (unsigned __int16)(v159 * v156) - ((v159 * v156) >> 16);
    v159 = HIWORD(v160);
  }
  else
  {
    v160 = 1 - v156;
  }
  v161 = v160 - v159;
  v162 = *(_DWORD *)(v158 + 4);
  v163 = v161 + v157;
  v164 = v163 ^ v151;
  v165 = v146 ^ v163;
  v166 = v206 ^ v161;
  v167 = v158 + 4;
  v168 = (unsigned __int16)(v213 ^ v161);
  if ( v168 * v162 )
    v214 = (unsigned __int16)(v168 * v162)
         - ((unsigned int)(v168 * v162) >> 16)
         - (((unsigned __int16)(v168 * v162) - ((unsigned int)(v168 * v162) >> 16)) >> 16);
  else
    LOWORD(v214) = 1 - v162 - v168;
  v169 = *(_DWORD *)(v167 + 4) + v166;
  v170 = v167 + 4;
  v171 = *(_DWORD *)(v170 + 4) + v165;
  v170 += 4;
  v172 = *(_DWORD *)(v170 + 4);
  v173 = v170 + 4;
  if ( v164 * v172 )
    v174 = (unsigned __int16)(v164 * v172)
         - (((unsigned int)v164 * v172) >> 16)
         - (((unsigned __int16)(v164 * v172) - (((unsigned int)v164 * v172) >> 16)) >> 16);
  else
    LOWORD(v174) = 1 - v172 - v164;
  v175 = *(_DWORD *)(v173 + 4);
  v176 = v173 + 4;
  v177 = (unsigned __int16)(v214 ^ v171);
  if ( v177 * v175 )
  {
    v178 = (unsigned __int16)(v177 * v175) - ((v177 * v175) >> 16);
    v177 = HIWORD(v178);
  }
  else
  {
    v178 = 1 - v175;
  }
  v179 = v178 - v177;
  v180 = *(_DWORD *)(v176 + 4);
  v181 = (_DWORD *)(v176 + 4);
  v182 = (unsigned __int16)(v179 + (v169 ^ v174));
  v183 = v182 * v180;
  if ( v183 )
  {
    v184 = (unsigned __int16)v183 - HIWORD(v183);
    v182 = HIWORD(v184);
  }
  else
  {
    v184 = 1 - *v181;
  }
  v185 = v184 - v182;
  v186 = v181[1];
  v187 = v185 + v179;
  v188 = v187 ^ v174;
  v189 = v169 ^ v187;
  v190 = v185;
  v191 = v181 + 1;
  v192 = (unsigned __int16)(v214 ^ v185);
  v193 = v171 ^ v190;
  if ( v192 * v186 )
    v194 = (unsigned __int16)(v192 * v186)
         - ((unsigned int)(v192 * v186) >> 16)
         - (((unsigned __int16)(v192 * v186) - ((unsigned int)(v192 * v186) >> 16)) >> 16);
  else
    v194 = 1 - v186 - v192;
  v195 = v189 + v191[1];
  v196 = v191 + 1;
  v197 = v196[1];
  v198 = v196[2];
  v199 = v193 + v197;
  if ( v188 * v198 )
  {
    v200 = (unsigned __int16)(v188 * v198) - (((unsigned int)v188 * v198) >> 16);
    v201 = v200 - HIWORD(v200);
  }
  else
  {
    LOWORD(v201) = 1 - v198 - v188;
  }
  *d = (v194 << 16) | (unsigned __int16)v195;
  d[1] = (unsigned __int16)v201 | (v199 << 16);
}
