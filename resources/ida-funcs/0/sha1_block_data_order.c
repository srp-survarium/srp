int __cdecl sha1_block_data_order(_DWORD *a1, unsigned int *a2, int a3)
{
  _DWORD *v3; // ebp
  unsigned int *v4; // esi
  int v5; // edi
  int v6; // ebx
  int v7; // ecx
  int v8; // edx
  int v9; // esi
  int v10; // ebx
  unsigned __int32 v11; // esi
  int v12; // eax
  int v13; // edi
  int v14; // edx
  int v15; // esi
  unsigned __int32 v16; // edx
  int v17; // ecx
  int v18; // edi
  unsigned __int32 v19; // ecx
  int v20; // ebx
  int v21; // edx
  unsigned __int32 v22; // ebx
  int v23; // eax
  int v24; // ecx
  unsigned __int32 v25; // eax
  int v26; // esi
  int v27; // ebx
  unsigned __int32 v28; // esi
  int v29; // edi
  int v30; // eax
  unsigned __int32 v31; // edi
  int v32; // edx
  int v33; // esi
  unsigned __int32 v34; // edx
  int v35; // ecx
  int v36; // edi
  unsigned __int32 v37; // ecx
  int v38; // ebx
  int v39; // edx
  unsigned __int32 v40; // ebx
  int v41; // eax
  int v42; // ecx
  unsigned __int32 v43; // eax
  int v44; // esi
  int v45; // ebx
  unsigned __int32 v46; // esi
  int v47; // edi
  int v48; // eax
  unsigned __int32 v49; // edi
  int v50; // edx
  int v51; // esi
  unsigned __int32 v52; // edx
  int v53; // ecx
  int v54; // edi
  unsigned __int32 v55; // ecx
  int v56; // ebp
  int v57; // edx
  int v58; // ebx
  int v59; // ebp
  int v60; // ecx
  int v61; // eax
  int v62; // ebp
  int v63; // ebx
  int v64; // esi
  int v65; // ebp
  int v66; // eax
  int v67; // edi
  int v68; // ebp
  int v69; // esi
  int v70; // edx
  int v71; // ebp
  int v72; // edi
  int v73; // ecx
  int v74; // ebp
  int v75; // edx
  int v76; // ebx
  int v77; // ebp
  int v78; // ecx
  int v79; // eax
  int v80; // ebp
  int v81; // ebx
  int v82; // esi
  int v83; // ebp
  int v84; // eax
  int v85; // edi
  int v86; // ebp
  int v87; // esi
  int v88; // edx
  int v89; // ebp
  int v90; // edi
  int v91; // ecx
  int v92; // ebp
  int v93; // edx
  int v94; // ebx
  int v95; // ebp
  int v96; // ecx
  int v97; // eax
  int v98; // ebp
  int v99; // ebx
  int v100; // esi
  int v101; // ebp
  int v102; // eax
  int v103; // edi
  int v104; // ebp
  int v105; // esi
  int v106; // edx
  int v107; // ebp
  int v108; // edi
  int v109; // ecx
  int v110; // ebp
  int v111; // edx
  int v112; // ebx
  int v113; // ebp
  int v114; // ecx
  int v115; // eax
  int v116; // ebp
  int v117; // ebx
  int v118; // esi
  int v119; // ebp
  int v120; // eax
  int v121; // edi
  int v122; // ebp
  int v123; // esi
  int v124; // edx
  int v125; // ebp
  int v126; // edi
  int v127; // ecx
  int v128; // ebp
  int v129; // ebx
  int v130; // eax
  int v131; // edx
  int v132; // ebx
  int v133; // ebp
  int v134; // eax
  int v135; // esi
  int v136; // ecx
  int v137; // eax
  int v138; // ebp
  int v139; // esi
  int v140; // edi
  int v141; // ebx
  int v142; // esi
  int v143; // ebp
  int v144; // edi
  int v145; // edx
  int v146; // eax
  int v147; // edi
  int v148; // ebp
  int v149; // edx
  int v150; // ecx
  int v151; // esi
  int v152; // edx
  int v153; // ebp
  int v154; // ecx
  int v155; // ebx
  int v156; // edi
  int v157; // ecx
  int v158; // ebp
  int v159; // ebx
  int v160; // eax
  int v161; // edx
  int v162; // ebx
  int v163; // ebp
  int v164; // eax
  int v165; // esi
  int v166; // ecx
  int v167; // eax
  int v168; // ebp
  int v169; // esi
  int v170; // edi
  int v171; // ebx
  int v172; // esi
  int v173; // ebp
  int v174; // edi
  int v175; // edx
  int v176; // eax
  int v177; // edi
  int v178; // ebp
  int v179; // edx
  int v180; // ecx
  int v181; // esi
  int v182; // edx
  int v183; // ebp
  int v184; // ecx
  int v185; // ebx
  int v186; // edi
  int v187; // ecx
  int v188; // ebp
  int v189; // ebx
  int v190; // eax
  int v191; // edx
  int v192; // ebx
  int v193; // ebp
  int v194; // eax
  int v195; // esi
  int v196; // ecx
  int v197; // eax
  int v198; // ebp
  int v199; // esi
  int v200; // edi
  int v201; // ebx
  int v202; // esi
  int v203; // ebp
  int v204; // edi
  int v205; // edx
  int v206; // eax
  int v207; // edi
  int v208; // ebp
  int v209; // edx
  int v210; // ecx
  int v211; // esi
  int v212; // edx
  int v213; // ebp
  int v214; // ecx
  int v215; // ebx
  int v216; // edi
  int v217; // ecx
  int v218; // ebp
  int v219; // ebx
  int v220; // eax
  int v221; // edx
  int v222; // ebx
  int v223; // ebp
  int v224; // eax
  int v225; // esi
  int v226; // ecx
  int v227; // eax
  int v228; // ebp
  int v229; // ebx
  int v230; // esi
  int v231; // ebp
  int v232; // eax
  int v233; // edi
  int v234; // ebp
  int v235; // esi
  int v236; // edx
  int v237; // ebp
  int v238; // edi
  int v239; // ecx
  int v240; // ebp
  int v241; // edx
  int v242; // ebx
  int v243; // ebp
  int v244; // ecx
  int v245; // eax
  int v246; // ebp
  int v247; // ebx
  int v248; // esi
  int v249; // ebp
  int v250; // eax
  int v251; // edi
  int v252; // ebp
  int v253; // esi
  int v254; // edx
  int v255; // ebp
  int v256; // edi
  int v257; // ecx
  int v258; // ebp
  int v259; // edx
  int v260; // ebx
  int v261; // ebp
  int v262; // ecx
  int v263; // eax
  int v264; // ebp
  int v265; // ebx
  int v266; // esi
  int v267; // ebp
  int v268; // eax
  int v269; // edi
  int v270; // ebp
  int v271; // esi
  int v272; // edx
  int v273; // ebp
  int v274; // edi
  int v275; // ecx
  int v276; // ebp
  int v277; // edx
  int v278; // ebx
  int v279; // ebp
  int v280; // ecx
  int v281; // eax
  int v282; // ebp
  int v283; // ebx
  int v284; // esi
  int v285; // edi
  int v286; // esi
  int result; // eax
  int v288; // ebx
  int v289; // ecx
  unsigned __int32 v290; // [esp+0h] [ebp-50h]
  int v291; // [esp+0h] [ebp-50h]
  int v292; // [esp+0h] [ebp-50h]
  int v293; // [esp+0h] [ebp-50h]
  int v294; // [esp+0h] [ebp-50h]
  unsigned __int32 v295; // [esp+4h] [ebp-4Ch]
  int v296; // [esp+4h] [ebp-4Ch]
  int v297; // [esp+4h] [ebp-4Ch]
  int v298; // [esp+4h] [ebp-4Ch]
  int v299; // [esp+4h] [ebp-4Ch]
  unsigned __int32 v300; // [esp+8h] [ebp-48h]
  int v301; // [esp+8h] [ebp-48h]
  int v302; // [esp+8h] [ebp-48h]
  int v303; // [esp+8h] [ebp-48h]
  int v304; // [esp+8h] [ebp-48h]
  unsigned __int32 v305; // [esp+Ch] [ebp-44h]
  int v306; // [esp+Ch] [ebp-44h]
  int v307; // [esp+Ch] [ebp-44h]
  int v308; // [esp+Ch] [ebp-44h]
  int v309; // [esp+Ch] [ebp-44h]
  unsigned __int32 v310; // [esp+10h] [ebp-40h]
  int v311; // [esp+10h] [ebp-40h]
  int v312; // [esp+10h] [ebp-40h]
  int v313; // [esp+10h] [ebp-40h]
  int v314; // [esp+10h] [ebp-40h]
  unsigned __int32 v315; // [esp+14h] [ebp-3Ch]
  int v316; // [esp+14h] [ebp-3Ch]
  int v317; // [esp+14h] [ebp-3Ch]
  int v318; // [esp+14h] [ebp-3Ch]
  int v319; // [esp+14h] [ebp-3Ch]
  unsigned __int32 v320; // [esp+18h] [ebp-38h]
  int v321; // [esp+18h] [ebp-38h]
  int v322; // [esp+18h] [ebp-38h]
  int v323; // [esp+18h] [ebp-38h]
  int v324; // [esp+18h] [ebp-38h]
  unsigned __int32 v325; // [esp+1Ch] [ebp-34h]
  int v326; // [esp+1Ch] [ebp-34h]
  int v327; // [esp+1Ch] [ebp-34h]
  int v328; // [esp+1Ch] [ebp-34h]
  int v329; // [esp+1Ch] [ebp-34h]
  unsigned __int32 v330; // [esp+20h] [ebp-30h]
  int v331; // [esp+20h] [ebp-30h]
  int v332; // [esp+20h] [ebp-30h]
  int v333; // [esp+20h] [ebp-30h]
  int v334; // [esp+20h] [ebp-30h]
  unsigned __int32 v335; // [esp+24h] [ebp-2Ch]
  int v336; // [esp+24h] [ebp-2Ch]
  int v337; // [esp+24h] [ebp-2Ch]
  int v338; // [esp+24h] [ebp-2Ch]
  int v339; // [esp+24h] [ebp-2Ch]
  unsigned __int32 v340; // [esp+28h] [ebp-28h]
  int v341; // [esp+28h] [ebp-28h]
  int v342; // [esp+28h] [ebp-28h]
  int v343; // [esp+28h] [ebp-28h]
  int v344; // [esp+28h] [ebp-28h]
  unsigned __int32 v345; // [esp+2Ch] [ebp-24h]
  int v346; // [esp+2Ch] [ebp-24h]
  int v347; // [esp+2Ch] [ebp-24h]
  int v348; // [esp+2Ch] [ebp-24h]
  int v349; // [esp+2Ch] [ebp-24h]
  unsigned __int32 v350; // [esp+30h] [ebp-20h]
  int v351; // [esp+30h] [ebp-20h]
  int v352; // [esp+30h] [ebp-20h]
  int v353; // [esp+30h] [ebp-20h]
  int v354; // [esp+30h] [ebp-20h]
  unsigned __int32 v355; // [esp+34h] [ebp-1Ch]
  int v356; // [esp+34h] [ebp-1Ch]
  int v357; // [esp+34h] [ebp-1Ch]
  int v358; // [esp+34h] [ebp-1Ch]
  unsigned __int32 v359; // [esp+38h] [ebp-18h]
  int v360; // [esp+38h] [ebp-18h]
  int v361; // [esp+38h] [ebp-18h]
  int v362; // [esp+38h] [ebp-18h]
  unsigned __int32 v363; // [esp+3Ch] [ebp-14h]
  int v364; // [esp+3Ch] [ebp-14h]
  int v365; // [esp+3Ch] [ebp-14h]
  int v366; // [esp+3Ch] [ebp-14h]
  unsigned int *v367; // [esp+58h] [ebp+8h]
  unsigned int v368; // [esp+5Ch] [ebp+Ch]

  v3 = a1;
  v4 = a2;
  v368 = (unsigned int)&a2[16 * a3];
  v5 = a1[4];
  do
  {
    v290 = _byteswap_ulong(*v4);
    v295 = _byteswap_ulong(v4[1]);
    v300 = _byteswap_ulong(v4[2]);
    v305 = _byteswap_ulong(v4[3]);
    v310 = _byteswap_ulong(v4[4]);
    v315 = _byteswap_ulong(v4[5]);
    v320 = _byteswap_ulong(v4[6]);
    v325 = _byteswap_ulong(v4[7]);
    v330 = _byteswap_ulong(v4[8]);
    v335 = _byteswap_ulong(v4[9]);
    v340 = _byteswap_ulong(v4[10]);
    v345 = _byteswap_ulong(v4[11]);
    v350 = _byteswap_ulong(v4[12]);
    v355 = _byteswap_ulong(v4[13]);
    v359 = _byteswap_ulong(v4[14]);
    v363 = _byteswap_ulong(v4[15]);
    v367 = v4;
    v6 = v3[1];
    v7 = v3[2];
    v8 = v3[3];
    v9 = v8 ^ v6 & (v8 ^ v7);
    v10 = __ROR4__(v6, 2);
    v11 = v9 + v5 + __ROL4__(*v3, 5) + v290 + 1518500249;
    v12 = __ROR4__(*v3, 2);
    v13 = (v7 ^ *v3 & (v7 ^ v10)) + v8 + __ROL4__(v11, 5) + v295 + 1518500249;
    v14 = v10 ^ v11 & (v10 ^ v12);
    v15 = __ROR4__(v11, 2);
    v16 = v14 + v7 + __ROL4__(v13, 5) + v300 + 1518500249;
    v17 = v12 ^ v13 & (v12 ^ v15);
    v18 = __ROR4__(v13, 2);
    v19 = v17 + v10 + __ROL4__(v16, 5) + v305 + 1518500249;
    v20 = v15 ^ v16 & (v15 ^ v18);
    v21 = __ROR4__(v16, 2);
    v22 = v20 + v12 + __ROL4__(v19, 5) + v310 + 1518500249;
    v23 = v18 ^ v19 & (v18 ^ v21);
    v24 = __ROR4__(v19, 2);
    v25 = v23 + v15 + __ROL4__(v22, 5) + v315 + 1518500249;
    v26 = v21 ^ v22 & (v21 ^ v24);
    v27 = __ROR4__(v22, 2);
    v28 = v26 + v18 + __ROL4__(v25, 5) + v320 + 1518500249;
    v29 = v24 ^ v25 & (v24 ^ v27);
    v30 = __ROR4__(v25, 2);
    v31 = v29 + v21 + __ROL4__(v28, 5) + v325 + 1518500249;
    v32 = v27 ^ v28 & (v27 ^ v30);
    v33 = __ROR4__(v28, 2);
    v34 = v32 + v24 + __ROL4__(v31, 5) + v330 + 1518500249;
    v35 = v30 ^ v31 & (v30 ^ v33);
    v36 = __ROR4__(v31, 2);
    v37 = v35 + v27 + __ROL4__(v34, 5) + v335 + 1518500249;
    v38 = v33 ^ v34 & (v33 ^ v36);
    v39 = __ROR4__(v34, 2);
    v40 = v38 + v30 + __ROL4__(v37, 5) + v340 + 1518500249;
    v41 = v36 ^ v37 & (v36 ^ v39);
    v42 = __ROR4__(v37, 2);
    v43 = v41 + v33 + __ROL4__(v40, 5) + v345 + 1518500249;
    v44 = v39 ^ v40 & (v39 ^ v42);
    v45 = __ROR4__(v40, 2);
    v46 = v44 + v36 + __ROL4__(v43, 5) + v350 + 1518500249;
    v47 = v42 ^ v43 & (v42 ^ v45);
    v48 = __ROR4__(v43, 2);
    v49 = v47 + v39 + __ROL4__(v46, 5) + v355 + 1518500249;
    v50 = v45 ^ v46 & (v45 ^ v48);
    v51 = __ROR4__(v46, 2);
    v52 = v50 + v42 + __ROL4__(v49, 5) + v359 + 1518500249;
    v53 = v48 ^ v49 & (v48 ^ v51);
    v54 = __ROR4__(v49, 2);
    v55 = v45 + __ROL4__(v52, 5) + v363 + 1518500249 + v53;
    v56 = v52 & (v51 ^ v54);
    v57 = __ROR4__(v52, 2);
    v291 = __ROL4__(v355 ^ v330 ^ v300 ^ v290, 1);
    v58 = __ROL4__(v55, 5) + (v51 ^ v56) + v291 + v48 + 1518500249;
    v59 = v55 & (v54 ^ v57);
    v60 = __ROR4__(v55, 2);
    v296 = __ROL4__(v359 ^ v335 ^ v305 ^ v295, 1);
    v61 = __ROL4__(v58, 5) + (v54 ^ v59) + v296 + v51 + 1518500249;
    v62 = v58 & (v57 ^ v60);
    v63 = __ROR4__(v58, 2);
    v301 = __ROL4__(v363 ^ v340 ^ v310 ^ v300, 1);
    v64 = __ROL4__(v61, 5) + (v57 ^ v62) + v301 + v54 + 1518500249;
    v65 = v61 & (v60 ^ v63);
    v66 = __ROR4__(v61, 2);
    v306 = __ROL4__(v291 ^ v345 ^ v315 ^ v305, 1);
    v67 = __ROL4__(v64, 5) + (v60 ^ v65) + v306 + v57 + 1518500249;
    v68 = v64;
    v69 = __ROR4__(v64, 2);
    v311 = __ROL4__(v296 ^ v350 ^ v320 ^ v310, 1);
    v70 = __ROL4__(v67, 5) + v311 + v60 + (v63 ^ v66 ^ v68) + 1859775393;
    v71 = v67;
    v72 = __ROR4__(v67, 2);
    v316 = __ROL4__(v301 ^ v355 ^ v325 ^ v315, 1);
    v73 = __ROL4__(v70, 5) + v316 + v63 + (v66 ^ v69 ^ v71) + 1859775393;
    v74 = v70;
    v75 = __ROR4__(v70, 2);
    v321 = __ROL4__(v306 ^ v359 ^ v330 ^ v320, 1);
    v76 = __ROL4__(v73, 5) + v321 + v66 + (v69 ^ v72 ^ v74) + 1859775393;
    v77 = v73;
    v78 = __ROR4__(v73, 2);
    v326 = __ROL4__(v311 ^ v363 ^ v335 ^ v325, 1);
    v79 = __ROL4__(v76, 5) + v326 + v69 + (v72 ^ v75 ^ v77) + 1859775393;
    v80 = v76;
    v81 = __ROR4__(v76, 2);
    v331 = __ROL4__(v316 ^ v291 ^ v340 ^ v330, 1);
    v82 = __ROL4__(v79, 5) + v331 + v72 + (v75 ^ v78 ^ v80) + 1859775393;
    v83 = v79;
    v84 = __ROR4__(v79, 2);
    v336 = __ROL4__(v321 ^ v296 ^ v345 ^ v335, 1);
    v85 = __ROL4__(v82, 5) + v336 + v75 + (v78 ^ v81 ^ v83) + 1859775393;
    v86 = v82;
    v87 = __ROR4__(v82, 2);
    v341 = __ROL4__(v326 ^ v301 ^ v350 ^ v340, 1);
    v88 = __ROL4__(v85, 5) + v341 + v78 + (v81 ^ v84 ^ v86) + 1859775393;
    v89 = v85;
    v90 = __ROR4__(v85, 2);
    v346 = __ROL4__(v331 ^ v306 ^ v355 ^ v345, 1);
    v91 = __ROL4__(v88, 5) + v346 + v81 + (v84 ^ v87 ^ v89) + 1859775393;
    v92 = v88;
    v93 = __ROR4__(v88, 2);
    v351 = __ROL4__(v336 ^ v311 ^ v359 ^ v350, 1);
    v94 = __ROL4__(v91, 5) + v351 + v84 + (v87 ^ v90 ^ v92) + 1859775393;
    v95 = v91;
    v96 = __ROR4__(v91, 2);
    v356 = __ROL4__(v341 ^ v316 ^ v363 ^ v355, 1);
    v97 = __ROL4__(v94, 5) + v356 + v87 + (v90 ^ v93 ^ v95) + 1859775393;
    v98 = v94;
    v99 = __ROR4__(v94, 2);
    v360 = __ROL4__(v346 ^ v321 ^ v291 ^ v359, 1);
    v100 = __ROL4__(v97, 5) + v360 + v90 + (v93 ^ v96 ^ v98) + 1859775393;
    v101 = v97;
    v102 = __ROR4__(v97, 2);
    v364 = __ROL4__(v351 ^ v326 ^ v296 ^ v363, 1);
    v103 = __ROL4__(v100, 5) + v364 + v93 + (v96 ^ v99 ^ v101) + 1859775393;
    v104 = v100;
    v105 = __ROR4__(v100, 2);
    v292 = __ROL4__(v356 ^ v331 ^ v301 ^ v291, 1);
    v106 = __ROL4__(v103, 5) + v292 + v96 + (v99 ^ v102 ^ v104) + 1859775393;
    v107 = v103;
    v108 = __ROR4__(v103, 2);
    v297 = __ROL4__(v360 ^ v336 ^ v306 ^ v296, 1);
    v109 = __ROL4__(v106, 5) + v297 + v99 + (v102 ^ v105 ^ v107) + 1859775393;
    v110 = v106;
    v111 = __ROR4__(v106, 2);
    v302 = __ROL4__(v364 ^ v341 ^ v311 ^ v301, 1);
    v112 = __ROL4__(v109, 5) + v302 + v102 + (v105 ^ v108 ^ v110) + 1859775393;
    v113 = v109;
    v114 = __ROR4__(v109, 2);
    v307 = __ROL4__(v292 ^ v346 ^ v316 ^ v306, 1);
    v115 = __ROL4__(v112, 5) + v307 + v105 + (v108 ^ v111 ^ v113) + 1859775393;
    v116 = v112;
    v117 = __ROR4__(v112, 2);
    v312 = __ROL4__(v297 ^ v351 ^ v321 ^ v311, 1);
    v118 = __ROL4__(v115, 5) + v312 + v108 + (v111 ^ v114 ^ v116) + 1859775393;
    v119 = v115;
    v120 = __ROR4__(v115, 2);
    v317 = __ROL4__(v302 ^ v356 ^ v326 ^ v316, 1);
    v121 = __ROL4__(v118, 5) + v317 + v111 + (v114 ^ v117 ^ v119) + 1859775393;
    v122 = v118;
    v123 = __ROR4__(v118, 2);
    v322 = __ROL4__(v307 ^ v360 ^ v331 ^ v321, 1);
    v124 = __ROL4__(v121, 5) + v322 + v114 + (v117 ^ v120 ^ v122) + 1859775393;
    v125 = v121;
    v126 = __ROR4__(v121, 2);
    v327 = __ROL4__(v312 ^ v364 ^ v336 ^ v326, 1);
    v127 = __ROL4__(v124, 5) + v327 + v117 + (v120 ^ v123 ^ v125) + 1859775393;
    v332 = __ROL4__(v317 ^ v292 ^ v341 ^ v331, 1);
    v128 = v123 & (v126 | v124);
    v129 = v332 + v120 - 1894007588;
    v130 = v124;
    v131 = __ROR4__(v124, 2);
    v132 = __ROL4__(v127, 5) + (v126 & v130 | v128) + v129;
    v337 = __ROL4__(v322 ^ v297 ^ v346 ^ v336, 1);
    v133 = v126 & (v131 | v127);
    v134 = v337 + v123 - 1894007588;
    v135 = v127;
    v136 = __ROR4__(v127, 2);
    v137 = __ROL4__(v132, 5) + (v131 & v135 | v133) + v134;
    v342 = __ROL4__(v327 ^ v302 ^ v351 ^ v341, 1);
    v138 = v131 & (v136 | v132);
    v139 = v342 + v126 - 1894007588;
    v140 = v132;
    v141 = __ROR4__(v132, 2);
    v142 = __ROL4__(v137, 5) + (v136 & v140 | v138) + v139;
    v347 = __ROL4__(v332 ^ v307 ^ v356 ^ v346, 1);
    v143 = v136 & (v141 | v137);
    v144 = v347 + v131 - 1894007588;
    v145 = v137;
    v146 = __ROR4__(v137, 2);
    v147 = __ROL4__(v142, 5) + (v141 & v145 | v143) + v144;
    v352 = __ROL4__(v337 ^ v312 ^ v360 ^ v351, 1);
    v148 = v141 & (v146 | v142);
    v149 = v352 + v136 - 1894007588;
    v150 = v142;
    v151 = __ROR4__(v142, 2);
    v152 = __ROL4__(v147, 5) + (v146 & v150 | v148) + v149;
    v357 = __ROL4__(v342 ^ v317 ^ v364 ^ v356, 1);
    v153 = v146 & (v151 | v147);
    v154 = v357 + v141 - 1894007588;
    v155 = v147;
    v156 = __ROR4__(v147, 2);
    v157 = __ROL4__(v152, 5) + (v151 & v155 | v153) + v154;
    v361 = __ROL4__(v347 ^ v322 ^ v292 ^ v360, 1);
    v158 = v151 & (v156 | v152);
    v159 = v361 + v146 - 1894007588;
    v160 = v152;
    v161 = __ROR4__(v152, 2);
    v162 = __ROL4__(v157, 5) + (v156 & v160 | v158) + v159;
    v365 = __ROL4__(v352 ^ v327 ^ v297 ^ v364, 1);
    v163 = v156 & (v161 | v157);
    v164 = v365 + v151 - 1894007588;
    v165 = v157;
    v166 = __ROR4__(v157, 2);
    v167 = __ROL4__(v162, 5) + (v161 & v165 | v163) + v164;
    v293 = __ROL4__(v357 ^ v332 ^ v302 ^ v292, 1);
    v168 = v161 & (v166 | v162);
    v169 = v293 + v156 - 1894007588;
    v170 = v162;
    v171 = __ROR4__(v162, 2);
    v172 = __ROL4__(v167, 5) + (v166 & v170 | v168) + v169;
    v298 = __ROL4__(v361 ^ v337 ^ v307 ^ v297, 1);
    v173 = v166 & (v171 | v167);
    v174 = v298 + v161 - 1894007588;
    v175 = v167;
    v176 = __ROR4__(v167, 2);
    v177 = __ROL4__(v172, 5) + (v171 & v175 | v173) + v174;
    v303 = __ROL4__(v365 ^ v342 ^ v312 ^ v302, 1);
    v178 = v171 & (v176 | v172);
    v179 = v303 + v166 - 1894007588;
    v180 = v172;
    v181 = __ROR4__(v172, 2);
    v182 = __ROL4__(v177, 5) + (v176 & v180 | v178) + v179;
    v308 = __ROL4__(v293 ^ v347 ^ v317 ^ v307, 1);
    v183 = v176 & (v181 | v177);
    v184 = v308 + v171 - 1894007588;
    v185 = v177;
    v186 = __ROR4__(v177, 2);
    v187 = __ROL4__(v182, 5) + (v181 & v185 | v183) + v184;
    v313 = __ROL4__(v298 ^ v352 ^ v322 ^ v312, 1);
    v188 = v181 & (v186 | v182);
    v189 = v313 + v176 - 1894007588;
    v190 = v182;
    v191 = __ROR4__(v182, 2);
    v192 = __ROL4__(v187, 5) + (v186 & v190 | v188) + v189;
    v318 = __ROL4__(v303 ^ v357 ^ v327 ^ v317, 1);
    v193 = v186 & (v191 | v187);
    v194 = v318 + v181 - 1894007588;
    v195 = v187;
    v196 = __ROR4__(v187, 2);
    v197 = __ROL4__(v192, 5) + (v191 & v195 | v193) + v194;
    v323 = __ROL4__(v308 ^ v361 ^ v332 ^ v322, 1);
    v198 = v191 & (v196 | v192);
    v199 = v323 + v186 - 1894007588;
    v200 = v192;
    v201 = __ROR4__(v192, 2);
    v202 = __ROL4__(v197, 5) + (v196 & v200 | v198) + v199;
    v328 = __ROL4__(v313 ^ v365 ^ v337 ^ v327, 1);
    v203 = v196 & (v201 | v197);
    v204 = v328 + v191 - 1894007588;
    v205 = v197;
    v206 = __ROR4__(v197, 2);
    v207 = __ROL4__(v202, 5) + (v201 & v205 | v203) + v204;
    v333 = __ROL4__(v318 ^ v293 ^ v342 ^ v332, 1);
    v208 = v201 & (v206 | v202);
    v209 = v333 + v196 - 1894007588;
    v210 = v202;
    v211 = __ROR4__(v202, 2);
    v212 = __ROL4__(v207, 5) + (v206 & v210 | v208) + v209;
    v338 = __ROL4__(v323 ^ v298 ^ v347 ^ v337, 1);
    v213 = v206 & (v211 | v207);
    v214 = v338 + v201 - 1894007588;
    v215 = v207;
    v216 = __ROR4__(v207, 2);
    v217 = __ROL4__(v212, 5) + (v211 & v215 | v213) + v214;
    v343 = __ROL4__(v328 ^ v303 ^ v352 ^ v342, 1);
    v218 = v211 & (v216 | v212);
    v219 = v343 + v206 - 1894007588;
    v220 = v212;
    v221 = __ROR4__(v212, 2);
    v222 = __ROL4__(v217, 5) + (v216 & v220 | v218) + v219;
    v348 = __ROL4__(v333 ^ v308 ^ v357 ^ v347, 1);
    v223 = v216 & (v221 | v217);
    v224 = v348 + v211 - 1894007588;
    v225 = v217;
    v226 = __ROR4__(v217, 2);
    v227 = __ROL4__(v222, 5) + (v221 & v225 | v223) + v224;
    v228 = v222;
    v229 = __ROR4__(v222, 2);
    v353 = __ROL4__(v338 ^ v313 ^ v361 ^ v352, 1);
    v230 = __ROL4__(v227, 5) + v353 + v216 + (v221 ^ v226 ^ v228) - 899497514;
    v231 = v227;
    v232 = __ROR4__(v227, 2);
    v358 = __ROL4__(v343 ^ v318 ^ v365 ^ v357, 1);
    v233 = __ROL4__(v230, 5) + v358 + v221 + (v226 ^ v229 ^ v231) - 899497514;
    v234 = v230;
    v235 = __ROR4__(v230, 2);
    v362 = __ROL4__(v348 ^ v323 ^ v293 ^ v361, 1);
    v236 = __ROL4__(v233, 5) + v362 + v226 + (v229 ^ v232 ^ v234) - 899497514;
    v237 = v233;
    v238 = __ROR4__(v233, 2);
    v366 = __ROL4__(v353 ^ v328 ^ v298 ^ v365, 1);
    v239 = __ROL4__(v236, 5) + v366 + v229 + (v232 ^ v235 ^ v237) - 899497514;
    v240 = v236;
    v241 = __ROR4__(v236, 2);
    v294 = __ROL4__(v358 ^ v333 ^ v303 ^ v293, 1);
    v242 = __ROL4__(v239, 5) + v294 + v232 + (v235 ^ v238 ^ v240) - 899497514;
    v243 = v239;
    v244 = __ROR4__(v239, 2);
    v299 = __ROL4__(v362 ^ v338 ^ v308 ^ v298, 1);
    v245 = __ROL4__(v242, 5) + v299 + v235 + (v238 ^ v241 ^ v243) - 899497514;
    v246 = v242;
    v247 = __ROR4__(v242, 2);
    v304 = __ROL4__(v366 ^ v343 ^ v313 ^ v303, 1);
    v248 = __ROL4__(v245, 5) + v304 + v238 + (v241 ^ v244 ^ v246) - 899497514;
    v249 = v245;
    v250 = __ROR4__(v245, 2);
    v309 = __ROL4__(v294 ^ v348 ^ v318 ^ v308, 1);
    v251 = __ROL4__(v248, 5) + v309 + v241 + (v244 ^ v247 ^ v249) - 899497514;
    v252 = v248;
    v253 = __ROR4__(v248, 2);
    v314 = __ROL4__(v299 ^ v353 ^ v323 ^ v313, 1);
    v254 = __ROL4__(v251, 5) + v314 + v244 + (v247 ^ v250 ^ v252) - 899497514;
    v255 = v251;
    v256 = __ROR4__(v251, 2);
    v319 = __ROL4__(v304 ^ v358 ^ v328 ^ v318, 1);
    v257 = __ROL4__(v254, 5) + v319 + v247 + (v250 ^ v253 ^ v255) - 899497514;
    v258 = v254;
    v259 = __ROR4__(v254, 2);
    v324 = __ROL4__(v309 ^ v362 ^ v333 ^ v323, 1);
    v260 = __ROL4__(v257, 5) + v324 + v250 + (v253 ^ v256 ^ v258) - 899497514;
    v261 = v257;
    v262 = __ROR4__(v257, 2);
    v329 = __ROL4__(v314 ^ v366 ^ v338 ^ v328, 1);
    v263 = __ROL4__(v260, 5) + v329 + v253 + (v256 ^ v259 ^ v261) - 899497514;
    v264 = v260;
    v265 = __ROR4__(v260, 2);
    v334 = __ROL4__(v319 ^ v294 ^ v343 ^ v333, 1);
    v266 = __ROL4__(v263, 5) + v334 + v256 + (v259 ^ v262 ^ v264) - 899497514;
    v267 = v263;
    v268 = __ROR4__(v263, 2);
    v339 = __ROL4__(v324 ^ v299 ^ v348 ^ v338, 1);
    v269 = __ROL4__(v266, 5) + v339 + v259 + (v262 ^ v265 ^ v267) - 899497514;
    v270 = v266;
    v271 = __ROR4__(v266, 2);
    v344 = __ROL4__(v329 ^ v304 ^ v353 ^ v343, 1);
    v272 = __ROL4__(v269, 5) + v344 + v262 + (v265 ^ v268 ^ v270) - 899497514;
    v273 = v269;
    v274 = __ROR4__(v269, 2);
    v349 = __ROL4__(v334 ^ v309 ^ v358 ^ v348, 1);
    v275 = __ROL4__(v272, 5) + v349 + v265 + (v268 ^ v271 ^ v273) - 899497514;
    v276 = v272;
    v277 = __ROR4__(v272, 2);
    v354 = __ROL4__(v339 ^ v314 ^ v362 ^ v353, 1);
    v278 = __ROL4__(v275, 5) + v354 + v268 + (v271 ^ v274 ^ v276) - 899497514;
    v279 = v275;
    v280 = __ROR4__(v275, 2);
    v281 = __ROL4__(v278, 5) + __ROL4__(v344 ^ v319 ^ v366 ^ v358, 1) + v271 + (v274 ^ v277 ^ v279) - 899497514;
    v282 = v278;
    v283 = __ROR4__(v278, 2);
    v284 = __ROL4__(v281, 5) + __ROL4__(v349 ^ v324 ^ v294 ^ v362, 1) + v274 + (v277 ^ v280 ^ v282) - 899497514;
    v285 = __ROL4__(v284, 5) + __ROL4__(v354 ^ v329 ^ v299 ^ v366, 1) + v277 + (v280 ^ v283 ^ v281) - 899497514;
    v3 = a1;
    v286 = a1[1] + v284;
    result = a1[2] + __ROR4__(v281, 2);
    v288 = a1[3] + v283;
    v289 = a1[4] + v280;
    *a1 += v285;
    a1[1] = v286;
    a1[2] = result;
    v5 = v289;
    a1[3] = v288;
    v4 = v367 + 16;
    a1[4] = v289;
  }
  while ( (unsigned int)(v367 + 16) < v368 );
  return result;
}
