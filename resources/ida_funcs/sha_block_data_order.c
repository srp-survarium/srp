void __cdecl sha_block_data_order(SHAstate_st *c, unsigned __int8 *p, unsigned int num)
{
  SHAstate_st *v3; // ecx
  unsigned int h1; // ebx
  unsigned int i; // edi
  unsigned int h2; // ebp
  int v8; // edx
  unsigned __int8 *v9; // eax
  int v10; // edx
  int v11; // edx
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int v15; // esi
  int v16; // ecx
  int v17; // edx
  int v18; // ebx
  int v19; // edx
  int v20; // ecx
  int v21; // ecx
  int v22; // edi
  int v23; // ecx
  int v24; // ebp
  int v25; // ecx
  int v26; // ebp
  int v27; // ecx
  int v28; // esi
  int v29; // ebp
  int v30; // ecx
  int v31; // edx
  int v32; // ebx
  int v33; // edx
  int v34; // ecx
  int v35; // esi
  int v36; // edi
  int v37; // esi
  int v38; // ecx
  int v39; // ecx
  int v40; // edi
  int v41; // ebx
  int v42; // edi
  int v43; // ebp
  int v44; // ecx
  int v45; // edx
  int v46; // edx
  int v47; // ecx
  int v48; // ebx
  int v49; // esi
  int v50; // ebx
  int v51; // ecx
  int v52; // ecx
  int v53; // esi
  int v54; // ecx
  int v55; // esi
  int v56; // ebp
  int v57; // ecx
  int v58; // edx
  int v59; // edx
  int v60; // ecx
  int v61; // edi
  int v62; // ebx
  int v63; // edi
  int v64; // ecx
  int v65; // ebx
  int v66; // ecx
  int v67; // esi
  int v68; // ebx
  int v69; // esi
  int v70; // ecx
  int v71; // edx
  int v72; // edx
  int v73; // esi
  int v74; // ebx
  int v75; // edx
  int v76; // esi
  int v77; // ecx
  int v78; // ebp
  int v79; // ecx
  int v80; // ebp
  int v81; // ecx
  int v82; // esi
  int v83; // ebx
  int v84; // ebp
  int v85; // ebx
  int v86; // ebp
  int v87; // edi
  int v88; // esi
  int v89; // ebx
  int v90; // ebp
  int v91; // esi
  int v92; // edx
  int v93; // edi
  int v94; // ebx
  int v95; // ebp
  int v96; // esi
  int v97; // edi
  int v98; // ecx
  int v99; // ebp
  int v100; // ebp
  int v101; // ecx
  int v102; // ebx
  int v103; // edi
  int v104; // edx
  int v105; // ebp
  int v106; // ecx
  int v107; // ebx
  int v108; // esi
  int v109; // edx
  int v110; // edi
  int v111; // ebp
  int v112; // ebp
  int v113; // ebx
  int v114; // ebx
  int v115; // edi
  int v116; // ebp
  int v117; // esi
  int v118; // ebx
  int v119; // ebx
  int v120; // ecx
  int v121; // edx
  int v122; // ebp
  int v123; // ebx
  int v124; // ebx
  int v125; // ebx
  int v126; // edi
  int v127; // edi
  int v128; // esi
  int v129; // esi
  unsigned int v130; // esi
  unsigned int h0; // ebp
  bool v132; // zf
  int v133; // [esp+10h] [ebp-54h]
  int v134; // [esp+10h] [ebp-54h]
  int v135; // [esp+10h] [ebp-54h]
  int v136; // [esp+10h] [ebp-54h]
  int v137; // [esp+10h] [ebp-54h]
  int v138; // [esp+10h] [ebp-54h]
  int v139; // [esp+10h] [ebp-54h]
  int v140; // [esp+10h] [ebp-54h]
  int v141; // [esp+10h] [ebp-54h]
  int v142; // [esp+10h] [ebp-54h]
  int v143; // [esp+10h] [ebp-54h]
  int v144; // [esp+10h] [ebp-54h]
  int v145; // [esp+10h] [ebp-54h]
  int v146; // [esp+10h] [ebp-54h]
  int v147; // [esp+10h] [ebp-54h]
  int v148; // [esp+10h] [ebp-54h]
  int v149; // [esp+10h] [ebp-54h]
  int v150; // [esp+10h] [ebp-54h]
  int v151; // [esp+10h] [ebp-54h]
  int v152; // [esp+10h] [ebp-54h]
  int v153; // [esp+10h] [ebp-54h]
  int v154; // [esp+10h] [ebp-54h]
  int v155; // [esp+10h] [ebp-54h]
  int v156; // [esp+14h] [ebp-50h]
  int v157; // [esp+14h] [ebp-50h]
  int v158; // [esp+14h] [ebp-50h]
  int v159; // [esp+14h] [ebp-50h]
  int v160; // [esp+14h] [ebp-50h]
  int v161; // [esp+14h] [ebp-50h]
  int v162; // [esp+14h] [ebp-50h]
  int v163; // [esp+14h] [ebp-50h]
  int v164; // [esp+14h] [ebp-50h]
  int v165; // [esp+14h] [ebp-50h]
  int v166; // [esp+14h] [ebp-50h]
  int v167; // [esp+14h] [ebp-50h]
  int v168; // [esp+14h] [ebp-50h]
  int v169; // [esp+14h] [ebp-50h]
  int v170; // [esp+14h] [ebp-50h]
  int v171; // [esp+14h] [ebp-50h]
  int v172; // [esp+14h] [ebp-50h]
  int v173; // [esp+14h] [ebp-50h]
  int v174; // [esp+14h] [ebp-50h]
  int v175; // [esp+14h] [ebp-50h]
  int v176; // [esp+18h] [ebp-4Ch]
  int v177; // [esp+18h] [ebp-4Ch]
  int v178; // [esp+18h] [ebp-4Ch]
  int v179; // [esp+18h] [ebp-4Ch]
  int v180; // [esp+18h] [ebp-4Ch]
  int v181; // [esp+18h] [ebp-4Ch]
  int v182; // [esp+18h] [ebp-4Ch]
  int v183; // [esp+18h] [ebp-4Ch]
  int v184; // [esp+18h] [ebp-4Ch]
  int v185; // [esp+18h] [ebp-4Ch]
  int v186; // [esp+18h] [ebp-4Ch]
  int v187; // [esp+18h] [ebp-4Ch]
  int v188; // [esp+18h] [ebp-4Ch]
  int v189; // [esp+18h] [ebp-4Ch]
  int v190; // [esp+18h] [ebp-4Ch]
  int v191; // [esp+18h] [ebp-4Ch]
  int v192; // [esp+18h] [ebp-4Ch]
  int v193; // [esp+18h] [ebp-4Ch]
  int v194; // [esp+18h] [ebp-4Ch]
  int v195; // [esp+18h] [ebp-4Ch]
  int v196; // [esp+1Ch] [ebp-48h]
  int v197; // [esp+1Ch] [ebp-48h]
  int v198; // [esp+1Ch] [ebp-48h]
  int v199; // [esp+1Ch] [ebp-48h]
  int v200; // [esp+1Ch] [ebp-48h]
  int v201; // [esp+1Ch] [ebp-48h]
  int v202; // [esp+1Ch] [ebp-48h]
  int v203; // [esp+1Ch] [ebp-48h]
  int v204; // [esp+1Ch] [ebp-48h]
  int v205; // [esp+1Ch] [ebp-48h]
  int v206; // [esp+1Ch] [ebp-48h]
  int v207; // [esp+1Ch] [ebp-48h]
  int v208; // [esp+1Ch] [ebp-48h]
  int v209; // [esp+1Ch] [ebp-48h]
  int v210; // [esp+1Ch] [ebp-48h]
  int v211; // [esp+1Ch] [ebp-48h]
  int v212; // [esp+20h] [ebp-44h]
  int v213; // [esp+20h] [ebp-44h]
  int v214; // [esp+20h] [ebp-44h]
  int v215; // [esp+20h] [ebp-44h]
  int v216; // [esp+20h] [ebp-44h]
  int v217; // [esp+20h] [ebp-44h]
  int v218; // [esp+20h] [ebp-44h]
  int v219; // [esp+20h] [ebp-44h]
  int v220; // [esp+20h] [ebp-44h]
  int v221; // [esp+20h] [ebp-44h]
  int v222; // [esp+20h] [ebp-44h]
  int v223; // [esp+20h] [ebp-44h]
  int v224; // [esp+20h] [ebp-44h]
  int v225; // [esp+20h] [ebp-44h]
  int v226; // [esp+20h] [ebp-44h]
  int v227; // [esp+20h] [ebp-44h]
  int v228; // [esp+20h] [ebp-44h]
  int v229; // [esp+20h] [ebp-44h]
  int v230; // [esp+20h] [ebp-44h]
  int v231; // [esp+24h] [ebp-40h]
  int v232; // [esp+24h] [ebp-40h]
  int v233; // [esp+24h] [ebp-40h]
  int v234; // [esp+24h] [ebp-40h]
  int v235; // [esp+24h] [ebp-40h]
  int v236; // [esp+28h] [ebp-3Ch]
  int v237; // [esp+28h] [ebp-3Ch]
  int v238; // [esp+28h] [ebp-3Ch]
  int v239; // [esp+28h] [ebp-3Ch]
  int v240; // [esp+28h] [ebp-3Ch]
  int v241; // [esp+2Ch] [ebp-38h]
  int v242; // [esp+2Ch] [ebp-38h]
  int v243; // [esp+2Ch] [ebp-38h]
  int v244; // [esp+2Ch] [ebp-38h]
  int v245; // [esp+2Ch] [ebp-38h]
  int v246; // [esp+30h] [ebp-34h]
  int v247; // [esp+30h] [ebp-34h]
  int v248; // [esp+30h] [ebp-34h]
  int v249; // [esp+30h] [ebp-34h]
  int v250; // [esp+30h] [ebp-34h]
  int v251; // [esp+34h] [ebp-30h]
  int v252; // [esp+34h] [ebp-30h]
  int v253; // [esp+34h] [ebp-30h]
  int v254; // [esp+34h] [ebp-30h]
  int v255; // [esp+34h] [ebp-30h]
  int v256; // [esp+38h] [ebp-2Ch]
  int v257; // [esp+38h] [ebp-2Ch]
  int v258; // [esp+38h] [ebp-2Ch]
  int v259; // [esp+38h] [ebp-2Ch]
  int v260; // [esp+38h] [ebp-2Ch]
  int v261; // [esp+3Ch] [ebp-28h]
  int v262; // [esp+3Ch] [ebp-28h]
  int v263; // [esp+3Ch] [ebp-28h]
  int v264; // [esp+3Ch] [ebp-28h]
  int v265; // [esp+3Ch] [ebp-28h]
  int v266; // [esp+40h] [ebp-24h]
  int v267; // [esp+40h] [ebp-24h]
  int v268; // [esp+40h] [ebp-24h]
  int v269; // [esp+40h] [ebp-24h]
  int v270; // [esp+44h] [ebp-20h]
  int v271; // [esp+44h] [ebp-20h]
  int v272; // [esp+44h] [ebp-20h]
  int v273; // [esp+44h] [ebp-20h]
  int v274; // [esp+44h] [ebp-20h]
  int v275; // [esp+48h] [ebp-1Ch]
  int v276; // [esp+48h] [ebp-1Ch]
  int v277; // [esp+48h] [ebp-1Ch]
  int v278; // [esp+48h] [ebp-1Ch]
  int v279; // [esp+48h] [ebp-1Ch]
  int v280; // [esp+4Ch] [ebp-18h]
  int v281; // [esp+4Ch] [ebp-18h]
  int v282; // [esp+4Ch] [ebp-18h]
  int v283; // [esp+4Ch] [ebp-18h]
  int v284; // [esp+50h] [ebp-14h]
  int v285; // [esp+50h] [ebp-14h]
  int v286; // [esp+50h] [ebp-14h]
  int v287; // [esp+50h] [ebp-14h]
  int v288; // [esp+54h] [ebp-10h]
  int v289; // [esp+54h] [ebp-10h]
  int v290; // [esp+54h] [ebp-10h]
  int v291; // [esp+58h] [ebp-Ch]
  int v292; // [esp+58h] [ebp-Ch]
  int v293; // [esp+58h] [ebp-Ch]
  int v294; // [esp+5Ch] [ebp-8h]
  int v295; // [esp+5Ch] [ebp-8h]
  int v296; // [esp+60h] [ebp-4h]
  int v297; // [esp+60h] [ebp-4h]
  unsigned int h3; // [esp+6Ch] [ebp+8h]
  int v299; // [esp+6Ch] [ebp+8h]
  int v300; // [esp+6Ch] [ebp+8h]
  int v301; // [esp+6Ch] [ebp+8h]
  int v302; // [esp+6Ch] [ebp+8h]
  int v303; // [esp+6Ch] [ebp+8h]
  int v304; // [esp+6Ch] [ebp+8h]
  int v305; // [esp+6Ch] [ebp+8h]
  int v306; // [esp+6Ch] [ebp+8h]
  int v307; // [esp+6Ch] [ebp+8h]
  int v308; // [esp+6Ch] [ebp+8h]
  int v309; // [esp+6Ch] [ebp+8h]
  int v310; // [esp+6Ch] [ebp+8h]
  int v311; // [esp+6Ch] [ebp+8h]
  int v312; // [esp+6Ch] [ebp+8h]
  int v313; // [esp+6Ch] [ebp+8h]
  int v314; // [esp+6Ch] [ebp+8h]
  int v315; // [esp+6Ch] [ebp+8h]
  int v316; // [esp+6Ch] [ebp+8h]
  int v317; // [esp+6Ch] [ebp+8h]
  int v318; // [esp+6Ch] [ebp+8h]

  v3 = c;
  h1 = c->h1;
  for ( i = c->h0; ; i = h0 )
  {
    h2 = v3->h2;
    v8 = (p[1] << 16) | (*p << 24);
    v9 = p + 1;
    v10 = (*++v9 << 8) | v8;
    v11 = *++v9 | v10;
    v288 = v11;
    v12 = *++v9;
    v13 = (*++v9 << 16) | (v12 << 24);
    v14 = (*++v9 << 8) | v13;
    v291 = v9[1] | v14;
    v9 += 3;
    h3 = v3->h3;
    v15 = v288 + __ROL4__(i, 5) + (h3 ^ h1 & (h2 ^ h3)) + v3->h4 + 1518500249;
    v16 = (*v9 << 16) | (*(v9 - 1) << 24);
    v17 = *++v9;
    v231 = v9[1] | (v17 << 8) | v16;
    v18 = __ROL4__(h1, 30);
    v9 += 2;
    v19 = v291 + __ROL4__(v15, 5) + (h2 ^ i & (v18 ^ h2)) + h3 + 1518500249;
    v20 = *v9++;
    v21 = (*v9 << 16) | (v20 << 24);
    v156 = __ROL4__(i, 30);
    ++v9;
    v241 = v9[1] | (*v9 << 8) | v21;
    v9 += 2;
    v22 = h2 + v231 + __ROL4__(v19, 5) + (v18 ^ v15 & (v156 ^ v18)) + 1518500249;
    v23 = *v9;
    v24 = *++v9;
    v25 = (v24 << 16) | (v23 << 24);
    v26 = v9[1];
    v9 += 2;
    v251 = *v9 | (v26 << 8) | v25;
    v176 = __ROL4__(v15, 30);
    v27 = v9[1];
    v9 += 2;
    v28 = v241 + __ROL4__(v22, 5) + (v156 ^ v19 & (v156 ^ v176));
    v29 = __ROL4__(v19, 30);
    v30 = (*v9 << 16) | (v27 << 24);
    v31 = *++v9;
    v32 = v28 + v18 + 1518500249;
    v261 = v9[1] | (v31 << 8) | v30;
    v9 += 3;
    v33 = v251 + __ROL4__(v32, 5) + (v176 ^ v22 & (v29 ^ v176)) + v156 + 1518500249;
    v34 = (*v9 << 16) | (*(v9 - 1) << 24);
    v299 = __ROL4__(v22, 30);
    v35 = *++v9;
    v270 = *++v9 | (v35 << 8) | v34;
    v36 = (++v9)[1];
    v37 = v261 + __ROL4__(v33, 5) + (v29 ^ v32 & (v299 ^ v29)) + v176 + 1518500249;
    v38 = *v9++ << 24;
    v39 = (v36 << 16) | v38;
    v40 = *++v9;
    v41 = __ROL4__(v32, 30);
    v275 = v9[1] | (v40 << 8) | v39;
    v9 += 3;
    v42 = v270 + __ROL4__(v37, 5) + (v299 ^ v33 & (v41 ^ v299)) + v29 + 1518500249;
    v43 = __ROL4__(v33, 30);
    v44 = (*v9 << 16) | (*(v9 - 1) << 24);
    v45 = *++v9;
    v133 = v41;
    v236 = v9[1] | (v45 << 8) | v44;
    v9 += 3;
    v46 = v275 + __ROL4__(v42, 5) + (v41 ^ v37 & (v43 ^ v41)) + v299 + 1518500249;
    v47 = (*v9 << 16) | (*(v9 - 1) << 24);
    v48 = v9[1];
    v157 = __ROL4__(v37, 30);
    v9 += 2;
    v246 = *v9++ | (v48 << 8) | v47;
    v49 = v9[1];
    v50 = v236 + __ROL4__(v46, 5) + (v43 ^ v42 & (v157 ^ v43)) + v133 + 1518500249;
    v51 = *v9++;
    v52 = (v49 << 16) | (v51 << 24);
    v53 = v9[1];
    v9 += 2;
    v256 = *v9 | (v53 << 8) | v52;
    v177 = __ROL4__(v42, 30);
    v54 = v9[1];
    v9 += 2;
    v55 = v246 + __ROL4__(v50, 5) + (v157 ^ v46 & (v157 ^ v177)) + v43 + 1518500249;
    v56 = __ROL4__(v46, 30);
    v57 = (*v9 << 16) | (v54 << 24);
    v58 = *++v9;
    v266 = v9[1] | (v58 << 8) | v57;
    v9 += 3;
    v59 = v256 + __ROL4__(v55, 5) + (v177 ^ v50 & (v56 ^ v177)) + v157 + 1518500249;
    v60 = (*v9 << 16) | (*(v9 - 1) << 24);
    v61 = v9[1];
    v300 = __ROL4__(v50, 30);
    v9 += 2;
    v284 = *v9++ | (v61 << 8) | v60;
    v62 = *++v9;
    v63 = v266 + __ROL4__(v59, 5) + (v56 ^ v55 & (v300 ^ v56)) + v177 + 1518500249;
    v64 = (v62 << 16) | (*(v9 - 1) << 24);
    v65 = *++v9;
    v66 = v9[1] | (v65 << 8) | v64;
    v67 = __ROL4__(v55, 30);
    v9 += 2;
    v280 = v66;
    v68 = v300 ^ v59 & (v67 ^ v300);
    v134 = v67;
    v69 = v9[1];
    v70 = __ROL4__(v59, 30);
    v71 = *v9++;
    v72 = (v69 << 16) | (v71 << 24);
    v73 = *++v9;
    v74 = v284 + __ROL4__(v63, 5) + v68 + v56 + 1518500249;
    v75 = v9[1] | (v73 << 8) | v72;
    v9 += 2;
    v212 = v70;
    v76 = v300 + v280 + __ROL4__(v74, 5) + (v134 ^ v63 & (v70 ^ v134)) + 1518500249;
    v77 = *v9;
    v78 = *++v9;
    v79 = (v78 << 16) | (v77 << 24);
    v80 = *++v9;
    v196 = v76;
    v158 = __ROL4__(v63, 30);
    v81 = v9[1] | (v80 << 8) | v79;
    p = v9 + 2;
    v82 = v134 + v75 + __ROL4__(v76, 5) + (v212 ^ v74 & (v158 ^ v212)) + 1518500249;
    v83 = __ROL4__(v74, 30);
    v84 = __ROL4__(v196, 30);
    v135 = v212 + v81 + __ROL4__(v82, 5) + (v158 ^ v196 & (v158 ^ v83)) + 1518500249;
    v289 = v288 ^ v231 ^ v236 ^ v280;
    v213 = v289 + v158 + __ROL4__(v135, 5) + (v83 ^ v82 & (v84 ^ v83)) + 1518500249;
    v301 = __ROL4__(v82, 30);
    v292 = v291 ^ v241 ^ v246 ^ v75;
    v159 = v292 + v83 + __ROL4__(v213, 5) + (v84 ^ v135 & (v301 ^ v84)) + 1518500249;
    v232 = v231 ^ v251 ^ v256 ^ v81;
    v136 = __ROL4__(v135, 30);
    v178 = v232 + v84 + __ROL4__(v159, 5) + (v301 ^ v213 & (v136 ^ v301)) + 1518500249;
    v85 = __ROL4__(v213, 30);
    v242 = v289 ^ v241 ^ v261 ^ v266;
    v86 = v301 + __ROL4__(v178, 5) + (v136 ^ v159 & (v85 ^ v136));
    v160 = __ROL4__(v159, 30);
    v197 = v242 + v86 + 1518500249;
    v252 = v292 ^ v251 ^ v270 ^ v284;
    v302 = v252 + v136 + __ROL4__(v197, 5) + (v160 ^ v85 ^ v178) + 1859775393;
    v179 = __ROL4__(v178, 30);
    v262 = v232 ^ v261 ^ v275 ^ v280;
    v137 = v262 + v85 + __ROL4__(v302, 5) + (v160 ^ v197 ^ v179) + 1859775393;
    v198 = __ROL4__(v197, 30);
    v271 = v242 ^ v270 ^ v236 ^ v75;
    v214 = v271 + v160 + __ROL4__(v137, 5) + (v302 ^ v198 ^ v179) + 1859775393;
    v303 = __ROL4__(v302, 30);
    v276 = v252 ^ v275 ^ v246 ^ v81;
    v161 = v276 + v179 + __ROL4__(v214, 5) + (v137 ^ v303 ^ v198) + 1859775393;
    v138 = __ROL4__(v137, 30);
    v237 = v289 ^ v262 ^ v236 ^ v256;
    v180 = v237 + v198 + __ROL4__(v161, 5) + (v214 ^ v138 ^ v303) + 1859775393;
    v215 = __ROL4__(v214, 30);
    v247 = v292 ^ v271 ^ v246 ^ v266;
    v87 = v247 + v303 + __ROL4__(v180, 5) + (v161 ^ v215 ^ v138) + 1859775393;
    v162 = __ROL4__(v161, 30);
    v257 = v232 ^ v276 ^ v256 ^ v284;
    v88 = v257 + v138 + __ROL4__(v87, 5) + (v162 ^ v215 ^ v180) + 1859775393;
    v181 = __ROL4__(v180, 30);
    v304 = v88;
    v267 = v242 ^ v237 ^ v266 ^ v280;
    v139 = v267 + v215 + __ROL4__(v88, 5) + (v162 ^ v87 ^ v181) + 1859775393;
    v89 = __ROL4__(v87, 30);
    v90 = v88 ^ v89 ^ v181;
    v91 = v284 ^ v75;
    v92 = v289 ^ v271 ^ v267 ^ v75;
    v285 = v252 ^ v247 ^ v91;
    v305 = __ROL4__(v304, 30);
    v216 = v285 + v162 + __ROL4__(v139, 5) + v90 + 1859775393;
    v281 = v262 ^ v257 ^ v280 ^ v81;
    v93 = v281 + v181 + __ROL4__(v216, 5) + (v139 ^ v305 ^ v89) + 1859775393;
    v140 = __ROL4__(v139, 30);
    v94 = v92 + v89 + __ROL4__(v93, 5) + (v216 ^ v140 ^ v305) + 1859775393;
    v95 = __ROL4__(v216, 30);
    v96 = v292 ^ v276 ^ v285 ^ v81;
    v163 = __ROL4__(v93, 30);
    v199 = v96 + v305 + __ROL4__(v94, 5) + (v93 ^ v95 ^ v140) + 1859775393;
    v290 = v289 ^ v232 ^ v237 ^ v281;
    v306 = v290 + v140 + __ROL4__(v199, 5) + (v163 ^ v95 ^ v94) + 1859775393;
    v182 = __ROL4__(v94, 30);
    v293 = v292 ^ v242 ^ v247 ^ v92;
    v141 = v293 + v95 + __ROL4__(v306, 5) + (v163 ^ v199 ^ v182) + 1859775393;
    v200 = __ROL4__(v199, 30);
    v233 = v232 ^ v252 ^ v257 ^ v96;
    v217 = v233 + v163 + __ROL4__(v141, 5) + (v306 ^ v200 ^ v182) + 1859775393;
    v307 = __ROL4__(v306, 30);
    v243 = v290 ^ v242 ^ v262 ^ v267;
    v164 = v243 + v182 + __ROL4__(v217, 5) + (v141 ^ v307 ^ v200) + 1859775393;
    v142 = __ROL4__(v141, 30);
    v253 = v293 ^ v252 ^ v271 ^ v285;
    v183 = v253 + v200 + __ROL4__(v164, 5) + (v217 ^ v142 ^ v307) + 1859775393;
    v218 = __ROL4__(v217, 30);
    v263 = v233 ^ v262 ^ v276 ^ v281;
    v97 = v263 + v307 + __ROL4__(v183, 5) + (v164 ^ v218 ^ v142) + 1859775393;
    v165 = __ROL4__(v164, 30);
    v272 = v243 ^ v271 ^ v237 ^ v92;
    v98 = v272 + v142 + __ROL4__(v97, 5) + (v165 ^ v218 ^ v183) + 1859775393;
    v184 = __ROL4__(v183, 30);
    v277 = v253 ^ v276 ^ v247 ^ v96;
    v201 = __ROL4__(v97, 30);
    v238 = v290 ^ v263 ^ v237 ^ v257;
    v143 = v277 + v218 + __ROL4__(v98, 5) + (v165 ^ v97 ^ v184) + 1859775393;
    v219 = __ROL4__(v143, 5) + v238 + v165 + (v98 & v201 | v184 & (v98 | v201)) - 1894007588;
    v248 = v293 ^ v272 ^ v247 ^ v267;
    v308 = __ROL4__(v98, 30);
    v99 = v248 + v184 + (v143 & v308 | v201 & (v143 | v308));
    v144 = __ROL4__(v143, 30);
    v258 = v233 ^ v277 ^ v257 ^ v285;
    v166 = __ROL4__(v219, 5) + v99 - 1894007588;
    v100 = v258 + v201 + (v219 & v144 | v308 & (v219 | v144));
    v220 = __ROL4__(v219, 30);
    v268 = v243 ^ v238 ^ v267 ^ v281;
    v185 = __ROL4__(v166, 5) + v100 - 1894007588;
    v202 = __ROL4__(v185, 5) + v268 + v308 + (v166 & v220 | v144 & (v166 | v220)) - 1894007588;
    v286 = v253 ^ v248 ^ v285 ^ v92;
    v167 = __ROL4__(v166, 30);
    v309 = __ROL4__(v202, 5) + v286 + v144 + (v167 & v185 | v220 & (v167 | v185)) - 1894007588;
    v186 = __ROL4__(v185, 30);
    v282 = v263 ^ v258 ^ v281 ^ v96;
    v101 = __ROL4__(v309, 5) + v282 + v220 + (v202 & v186 | v167 & (v202 | v186)) - 1894007588;
    v102 = __ROL4__(v202, 30);
    v294 = v290 ^ v272 ^ v268 ^ v92;
    v103 = v294 + v167 + (v309 & v102 | v186 & (v309 | v102)) + __ROL4__(v101, 5) - 1894007588;
    v104 = __ROL4__(v309, 30);
    v105 = (v293 ^ v277 ^ v286 ^ v96) + v186 + (v101 & v104 | v102 & (v101 | v104));
    v296 = v293 ^ v277 ^ v286 ^ v96;
    v145 = __ROL4__(v101, 30);
    v106 = v290 ^ v233 ^ v238 ^ v282;
    v310 = v104;
    v107 = v102 + (v103 & v145 | v104 & (v103 | v145));
    v108 = __ROL4__(v103, 5) + v105 - 1894007588;
    v109 = v293 ^ v243 ^ v248 ^ v294;
    v110 = __ROL4__(v103, 30);
    v187 = v106 + v107 + __ROL4__(v108, 5) - 1894007588;
    v203 = v109 + v310 + (v108 & v110 | v145 & (v108 | v110)) + __ROL4__(v187, 5) - 1894007588;
    v168 = __ROL4__(v108, 30);
    v234 = v233 ^ v253 ^ v258 ^ v296;
    v111 = v145 + (v168 & v187 | v110 & (v168 | v187));
    v244 = v106 ^ v243 ^ v263 ^ v268;
    v188 = __ROL4__(v187, 30);
    v311 = __ROL4__(v203, 5) + v234 + v111 - 1894007588;
    v112 = v244 + v110 + (v203 & v188 | v168 & (v203 | v188));
    v254 = v109 ^ v253 ^ v272 ^ v286;
    v204 = __ROL4__(v203, 30);
    v146 = __ROL4__(v311, 5) + v112 - 1894007588;
    v113 = __ROL4__(v146, 5) + v254 + v168 + (v311 & v204 | v188 & (v311 | v204)) - 1894007588;
    v312 = __ROL4__(v311, 30);
    v264 = v234 ^ v263 ^ v277 ^ v282;
    v221 = v113;
    v169 = __ROL4__(v113, 5) + v264 + v188 + (v146 & v312 | v204 & (v146 | v312)) - 1894007588;
    v147 = __ROL4__(v146, 30);
    v273 = v244 ^ v272 ^ v238 ^ v294;
    v114 = __ROL4__(v169, 5) + v273 + v204 + (v221 & v147 | v312 & (v221 | v147)) - 1894007588;
    v222 = __ROL4__(v221, 30);
    v278 = v254 ^ v277 ^ v248 ^ v296;
    v115 = __ROL4__(v169, 30);
    v205 = __ROL4__(v114, 5) + v278 + v312 + (v169 & v222 | v147 & (v169 | v222)) - 1894007588;
    v239 = v106 ^ v264 ^ v238 ^ v258;
    v249 = v109 ^ v273 ^ v248 ^ v268;
    v189 = __ROL4__(v114, 30);
    v313 = __ROL4__(v205, 5) + v239 + v147 + (v115 & v114 | v222 & (v115 | v114)) - 1894007588;
    v148 = __ROL4__(v313, 5) + v249 + v222 + (v205 & v189 | v115 & (v205 | v189)) - 1894007588;
    v206 = __ROL4__(v205, 30);
    v259 = v234 ^ v278 ^ v258 ^ v286;
    v116 = v259 + v115 + (v313 & v206 | v189 & (v313 | v206));
    v314 = __ROL4__(v313, 30);
    v269 = v244 ^ v239 ^ v268 ^ v282;
    v223 = __ROL4__(v148, 5) + v116 - 1894007588;
    v170 = __ROL4__(v223, 5) + v269 + v189 + (v148 & v314 | v206 & (v148 | v314)) - 1894007588;
    v117 = v254 ^ v249 ^ v286 ^ v294;
    v149 = __ROL4__(v148, 30);
    v190 = v117 + (v223 ^ v149 ^ v314) + v206 + __ROL4__(v170, 5) - 899497514;
    v224 = __ROL4__(v223, 30);
    v283 = v264 ^ v259 ^ v282 ^ v296;
    v118 = v283 + (v170 ^ v224 ^ v149) + v314 + __ROL4__(v190, 5) - 899497514;
    v171 = __ROL4__(v170, 30);
    v207 = v118;
    v295 = v106 ^ v273 ^ v269 ^ v294;
    v119 = v295 + (v171 ^ v224 ^ v190) + v149 + __ROL4__(v118, 5) - 899497514;
    v191 = __ROL4__(v190, 30);
    v297 = v109 ^ v278 ^ v117 ^ v296;
    v120 = v234 ^ v239 ^ v283 ^ v106;
    v150 = v224 + __ROL4__(v119, 5) + v297 + (v171 ^ v207 ^ v191) - 899497514;
    v208 = __ROL4__(v207, 30);
    v315 = __ROL4__(v119, 30);
    v121 = v244 ^ v249 ^ v295 ^ v109;
    v122 = v150 ^ v315 ^ v208;
    v225 = v171 + __ROL4__(v150, 5) + v120 + (v119 ^ v208 ^ v191) - 899497514;
    v151 = __ROL4__(v150, 30);
    v172 = v121 + __ROL4__(v225, 5) + v191 + v122 - 899497514;
    v235 = v254 ^ v259 ^ v297 ^ v234;
    v192 = v235 + (v225 ^ v151 ^ v315) + v208 + __ROL4__(v172, 5) - 899497514;
    v226 = __ROL4__(v225, 30);
    v245 = v120 ^ v244 ^ v264 ^ v269;
    v123 = v245 + (v172 ^ v226 ^ v151) + v315 + __ROL4__(v192, 5) - 899497514;
    v173 = __ROL4__(v172, 30);
    v255 = v121 ^ v254 ^ v273 ^ v117;
    v316 = v255 + (v173 ^ v226 ^ v192) + v151 + __ROL4__(v123, 5) - 899497514;
    v193 = __ROL4__(v192, 30);
    v265 = v235 ^ v264 ^ v278 ^ v283;
    v152 = v226 + __ROL4__(v316, 5) + v265 + (v173 ^ v123 ^ v193) - 899497514;
    v209 = __ROL4__(v123, 30);
    v274 = v245 ^ v273 ^ v239 ^ v295;
    v227 = v274 + (v316 ^ v209 ^ v193) + v173 + __ROL4__(v152, 5) - 899497514;
    v317 = __ROL4__(v316, 30);
    v279 = v255 ^ v278 ^ v249 ^ v297;
    v174 = v279 + (v152 ^ v317 ^ v209) + v193 + __ROL4__(v227, 5) - 899497514;
    v153 = __ROL4__(v152, 30);
    v240 = v120 ^ v265 ^ v239 ^ v259;
    v194 = v240 + (v227 ^ v153 ^ v317) + v209 + __ROL4__(v174, 5) - 899497514;
    v228 = __ROL4__(v227, 30);
    v250 = v121 ^ v274 ^ v249 ^ v269;
    v124 = v250 + (v174 ^ v228 ^ v153) + v317 + __ROL4__(v194, 5) - 899497514;
    v175 = __ROL4__(v174, 30);
    v210 = v124;
    v260 = v235 ^ v279 ^ v259 ^ v117;
    v125 = v260 + (v175 ^ v228 ^ v194) + v153 + __ROL4__(v124, 5) - 899497514;
    v195 = __ROL4__(v194, 30);
    v126 = __ROL4__(v210, 30);
    v154 = v228 + __ROL4__(v125, 5) + (v245 ^ v240 ^ v269 ^ v283) + (v175 ^ v210 ^ v195) - 899497514;
    v287 = v255 ^ v250 ^ v117 ^ v295;
    v229 = v287 + (v125 ^ v126 ^ v195) + v175 + __ROL4__(v154, 5) - 899497514;
    v211 = v126;
    v318 = __ROL4__(v125, 30);
    v127 = v195 + __ROL4__(v229, 5) + (v154 ^ v318 ^ v126) + (v265 ^ v260 ^ v283 ^ v297) - 899497514;
    v155 = __ROL4__(v154, 30);
    v128 = (v229 ^ v155 ^ v318) + (v120 ^ v274 ^ v245 ^ v240 ^ v269 ^ v283 ^ v295);
    v230 = __ROL4__(v229, 30);
    v129 = v128 + v211 + __ROL4__(v127, 5) - 899497514;
    v3 = c;
    c->h1 += v129;
    c->h0 += (v127 ^ v230 ^ v155) + (v121 ^ v279 ^ v287 ^ v297) + v318 + __ROL4__(v129, 5) - 899497514;
    v130 = c->h3;
    h0 = c->h0;
    h1 = c->h1;
    c->h2 += __ROL4__(v127, 30);
    c->h3 = v230 + v130;
    v132 = num-- == 1;
    c->h4 += v155;
    if ( v132 )
      break;
  }
}
