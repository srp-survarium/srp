_DWORD *__cdecl bn_mul_comba8(_DWORD *a1, unsigned int *a2, unsigned int *a3)
{
  int v3; // ecx
  unsigned int v4; // edx
  unsigned __int64 v5; // rax
  bool v6; // cf
  int v7; // ecx
  unsigned __int64 v8; // kr08_8
  unsigned __int64 v9; // rax
  int v10; // ebp
  int v11; // ebx
  unsigned __int64 v12; // rax
  int v13; // ebp
  int v14; // ebx
  BOOL v15; // ett
  BOOL v16; // ecx
  unsigned __int64 v17; // rax
  int v18; // ebp
  int v19; // ebx
  BOOL v20; // ett
  int v21; // ecx
  unsigned __int64 v22; // rax
  int v23; // ebx
  int v24; // ecx
  unsigned __int64 v25; // rax
  int v26; // ebx
  int v27; // ecx
  BOOL v28; // ett
  BOOL v29; // ebp
  unsigned __int64 v30; // rax
  int v31; // ebx
  int v32; // ecx
  BOOL v33; // ett
  int v34; // ebp
  unsigned __int64 v35; // rax
  int v36; // ebx
  int v37; // ecx
  BOOL v38; // ett
  int v39; // ebp
  unsigned __int64 v40; // rax
  int v41; // ecx
  int v42; // ebp
  unsigned __int64 v43; // rax
  int v44; // ecx
  int v45; // ebp
  BOOL v46; // ett
  BOOL v47; // ebx
  unsigned __int64 v48; // rax
  int v49; // ecx
  int v50; // ebp
  BOOL v51; // ett
  int v52; // ebx
  unsigned __int64 v53; // rax
  int v54; // ecx
  int v55; // ebp
  BOOL v56; // ett
  int v57; // ebx
  unsigned __int64 v58; // rax
  int v59; // ecx
  int v60; // ebp
  BOOL v61; // ett
  int v62; // ebx
  unsigned __int64 v63; // rax
  int v64; // ebp
  int v65; // ebx
  unsigned __int64 v66; // rax
  int v67; // ebp
  int v68; // ebx
  BOOL v69; // ett
  BOOL v70; // ecx
  unsigned __int64 v71; // rax
  int v72; // ebp
  int v73; // ebx
  BOOL v74; // ett
  int v75; // ecx
  unsigned __int64 v76; // rax
  int v77; // ebp
  int v78; // ebx
  BOOL v79; // ett
  int v80; // ecx
  unsigned __int64 v81; // rax
  int v82; // ebp
  int v83; // ebx
  BOOL v84; // ett
  int v85; // ecx
  unsigned __int64 v86; // rax
  int v87; // ebp
  int v88; // ebx
  BOOL v89; // ett
  int v90; // ecx
  unsigned __int64 v91; // rax
  int v92; // ebx
  int v93; // ecx
  unsigned __int64 v94; // rax
  int v95; // ebx
  int v96; // ecx
  BOOL v97; // ett
  BOOL v98; // ebp
  unsigned __int64 v99; // rax
  int v100; // ebx
  int v101; // ecx
  BOOL v102; // ett
  int v103; // ebp
  unsigned __int64 v104; // rax
  int v105; // ebx
  int v106; // ecx
  BOOL v107; // ett
  int v108; // ebp
  unsigned __int64 v109; // rax
  int v110; // ebx
  int v111; // ecx
  BOOL v112; // ett
  int v113; // ebp
  unsigned __int64 v114; // rax
  int v115; // ebx
  int v116; // ecx
  BOOL v117; // ett
  int v118; // ebp
  unsigned __int64 v119; // rax
  int v120; // ebx
  int v121; // ecx
  BOOL v122; // ett
  int v123; // ebp
  unsigned __int64 v124; // rax
  int v125; // ecx
  int v126; // ebp
  unsigned __int64 v127; // rax
  int v128; // ecx
  int v129; // ebp
  BOOL v130; // ett
  BOOL v131; // ebx
  unsigned __int64 v132; // rax
  int v133; // ecx
  int v134; // ebp
  BOOL v135; // ett
  int v136; // ebx
  unsigned __int64 v137; // rax
  int v138; // ecx
  int v139; // ebp
  BOOL v140; // ett
  int v141; // ebx
  unsigned __int64 v142; // rax
  int v143; // ecx
  int v144; // ebp
  BOOL v145; // ett
  int v146; // ebx
  unsigned __int64 v147; // rax
  int v148; // ecx
  int v149; // ebp
  BOOL v150; // ett
  int v151; // ebx
  unsigned __int64 v152; // rax
  int v153; // ecx
  int v154; // ebp
  BOOL v155; // ett
  int v156; // ebx
  unsigned __int64 v157; // rax
  int v158; // ecx
  int v159; // ebp
  BOOL v160; // ett
  int v161; // ebx
  unsigned __int64 v162; // rax
  int v163; // ebp
  int v164; // ebx
  unsigned __int64 v165; // rax
  int v166; // ebp
  int v167; // ebx
  BOOL v168; // ett
  BOOL v169; // ecx
  unsigned __int64 v170; // rax
  int v171; // ebp
  int v172; // ebx
  BOOL v173; // ett
  int v174; // ecx
  unsigned __int64 v175; // rax
  int v176; // ebp
  int v177; // ebx
  BOOL v178; // ett
  int v179; // ecx
  unsigned __int64 v180; // rax
  int v181; // ebp
  int v182; // ebx
  BOOL v183; // ett
  int v184; // ecx
  unsigned __int64 v185; // rax
  int v186; // ebp
  int v187; // ebx
  BOOL v188; // ett
  int v189; // ecx
  unsigned __int64 v190; // rax
  int v191; // ebp
  int v192; // ebx
  BOOL v193; // ett
  int v194; // ecx
  unsigned __int64 v195; // rax
  int v196; // ebx
  int v197; // ecx
  unsigned __int64 v198; // rax
  int v199; // ebx
  int v200; // ecx
  BOOL v201; // ett
  BOOL v202; // ebp
  unsigned __int64 v203; // rax
  int v204; // ebx
  int v205; // ecx
  BOOL v206; // ett
  int v207; // ebp
  unsigned __int64 v208; // rax
  int v209; // ebx
  int v210; // ecx
  BOOL v211; // ett
  int v212; // ebp
  unsigned __int64 v213; // rax
  int v214; // ebx
  int v215; // ecx
  BOOL v216; // ett
  int v217; // ebp
  unsigned __int64 v218; // rax
  int v219; // ebx
  int v220; // ecx
  BOOL v221; // ett
  int v222; // ebp
  unsigned __int64 v223; // rax
  int v224; // ecx
  int v225; // ebp
  unsigned __int64 v226; // rax
  int v227; // ecx
  int v228; // ebp
  BOOL v229; // ett
  BOOL v230; // ebx
  unsigned __int64 v231; // rax
  int v232; // ecx
  int v233; // ebp
  BOOL v234; // ett
  int v235; // ebx
  unsigned __int64 v236; // rax
  int v237; // ecx
  int v238; // ebp
  BOOL v239; // ett
  int v240; // ebx
  unsigned __int64 v241; // rax
  int v242; // ecx
  int v243; // ebp
  BOOL v244; // ett
  int v245; // ebx
  unsigned __int64 v246; // rax
  int v247; // ebp
  int v248; // ebx
  unsigned __int64 v249; // rax
  int v250; // ebp
  int v251; // ebx
  BOOL v252; // ett
  BOOL v253; // ecx
  unsigned __int64 v254; // rax
  int v255; // ebp
  int v256; // ebx
  BOOL v257; // ett
  int v258; // ecx
  unsigned __int64 v259; // rax
  int v260; // ebp
  int v261; // ebx
  BOOL v262; // ett
  int v263; // ecx
  unsigned __int64 v264; // rax
  int v265; // ebx
  int v266; // ecx
  unsigned __int64 v267; // rax
  int v268; // ebx
  int v269; // ecx
  BOOL v270; // ett
  BOOL v271; // ebp
  unsigned __int64 v272; // rax
  int v273; // ebx
  int v274; // ecx
  BOOL v275; // ett
  int v276; // ebp
  unsigned __int64 v277; // rax
  int v278; // ecx
  int v279; // ebp
  unsigned __int64 v280; // rax
  int v281; // ecx
  int v282; // ebp
  BOOL v283; // ett
  BOOL v284; // ebx
  unsigned __int64 v285; // rax
  int v286; // ebp
  int v287; // ebx
  unsigned __int64 v288; // rax
  int v289; // ebp
  _DWORD *result; // eax

  v3 = (*a3 * (unsigned __int64)*a2) >> 32;
  v4 = *a3;
  *a1 = *a3 * *a2;
  v5 = v4 * (unsigned __int64)a2[1];
  v6 = __CFADD__((_DWORD)v5, v3);
  v7 = v5 + v3;
  v8 = HIDWORD(v5) + (unsigned __int64)v6;
  v9 = a3[1] * (unsigned __int64)*a2;
  v6 = __CFADD__(__CFADD__((_DWORD)v9, v7), (_DWORD)v8) | __CFADD__(HIDWORD(v9), __CFADD__((_DWORD)v9, v7) + (_DWORD)v8);
  v10 = HIDWORD(v9) + __CFADD__((_DWORD)v9, v7) + (_DWORD)v8;
  HIDWORD(v9) = *a3;
  v11 = v6 + HIDWORD(v8);
  a1[1] = v9 + v7;
  v12 = HIDWORD(v9) * (unsigned __int64)a2[2];
  v6 = __CFADD__((_DWORD)v12, v10);
  v13 = v12 + v10;
  v15 = v6;
  v6 = __CFADD__(v6, v11);
  v14 = v15 + v11;
  v6 |= __CFADD__(HIDWORD(v12), v14);
  v14 += HIDWORD(v12);
  v16 = v6;
  v17 = a3[1] * (unsigned __int64)a2[1];
  v6 = __CFADD__((_DWORD)v17, v13);
  v18 = v17 + v13;
  v20 = v6;
  v6 = __CFADD__(v6, v14);
  v19 = v20 + v14;
  v6 |= __CFADD__(HIDWORD(v17), v19);
  v19 += HIDWORD(v17);
  v21 = v6 + v16;
  v22 = a3[2] * (unsigned __int64)*a2;
  v6 = __CFADD__(__CFADD__((_DWORD)v22, v18), v19);
  v23 = __CFADD__((_DWORD)v22, v18) + v19;
  v6 |= __CFADD__(HIDWORD(v22), v23);
  v23 += HIDWORD(v22);
  HIDWORD(v22) = *a3;
  v24 = v6 + v21;
  a1[2] = v22 + v18;
  v25 = HIDWORD(v22) * (unsigned __int64)a2[3];
  v6 = __CFADD__((_DWORD)v25, v23);
  v26 = v25 + v23;
  v28 = v6;
  v6 = __CFADD__(v6, v24);
  v27 = v28 + v24;
  v6 |= __CFADD__(HIDWORD(v25), v27);
  v27 += HIDWORD(v25);
  v29 = v6;
  v30 = a3[1] * (unsigned __int64)a2[2];
  v6 = __CFADD__((_DWORD)v30, v26);
  v31 = v30 + v26;
  v33 = v6;
  v6 = __CFADD__(v6, v27);
  v32 = v33 + v27;
  v6 |= __CFADD__(HIDWORD(v30), v32);
  v32 += HIDWORD(v30);
  v34 = v6 + v29;
  v35 = a3[2] * (unsigned __int64)a2[1];
  v6 = __CFADD__((_DWORD)v35, v31);
  v36 = v35 + v31;
  v38 = v6;
  v6 = __CFADD__(v6, v32);
  v37 = v38 + v32;
  v6 |= __CFADD__(HIDWORD(v35), v37);
  v37 += HIDWORD(v35);
  v39 = v6 + v34;
  v40 = a3[3] * (unsigned __int64)*a2;
  v6 = __CFADD__(__CFADD__((_DWORD)v40, v36), v37);
  v41 = __CFADD__((_DWORD)v40, v36) + v37;
  v6 |= __CFADD__(HIDWORD(v40), v41);
  v41 += HIDWORD(v40);
  HIDWORD(v40) = *a3;
  v42 = v6 + v39;
  a1[3] = v40 + v36;
  v43 = HIDWORD(v40) * (unsigned __int64)a2[4];
  v6 = __CFADD__((_DWORD)v43, v41);
  v44 = v43 + v41;
  v46 = v6;
  v6 = __CFADD__(v6, v42);
  v45 = v46 + v42;
  v6 |= __CFADD__(HIDWORD(v43), v45);
  v45 += HIDWORD(v43);
  v47 = v6;
  v48 = a3[1] * (unsigned __int64)a2[3];
  v6 = __CFADD__((_DWORD)v48, v44);
  v49 = v48 + v44;
  v51 = v6;
  v6 = __CFADD__(v6, v45);
  v50 = v51 + v45;
  v6 |= __CFADD__(HIDWORD(v48), v50);
  v50 += HIDWORD(v48);
  v52 = v6 + v47;
  v53 = a3[2] * (unsigned __int64)a2[2];
  v6 = __CFADD__((_DWORD)v53, v49);
  v54 = v53 + v49;
  v56 = v6;
  v6 = __CFADD__(v6, v50);
  v55 = v56 + v50;
  v6 |= __CFADD__(HIDWORD(v53), v55);
  v55 += HIDWORD(v53);
  v57 = v6 + v52;
  v58 = a3[3] * (unsigned __int64)a2[1];
  v6 = __CFADD__((_DWORD)v58, v54);
  v59 = v58 + v54;
  v61 = v6;
  v6 = __CFADD__(v6, v55);
  v60 = v61 + v55;
  v6 |= __CFADD__(HIDWORD(v58), v60);
  v60 += HIDWORD(v58);
  v62 = v6 + v57;
  v63 = a3[4] * (unsigned __int64)*a2;
  v6 = __CFADD__(__CFADD__((_DWORD)v63, v59), v60);
  v64 = __CFADD__((_DWORD)v63, v59) + v60;
  v6 |= __CFADD__(HIDWORD(v63), v64);
  v64 += HIDWORD(v63);
  HIDWORD(v63) = *a3;
  v65 = v6 + v62;
  a1[4] = v63 + v59;
  v66 = HIDWORD(v63) * (unsigned __int64)a2[5];
  v6 = __CFADD__((_DWORD)v66, v64);
  v67 = v66 + v64;
  v69 = v6;
  v6 = __CFADD__(v6, v65);
  v68 = v69 + v65;
  v6 |= __CFADD__(HIDWORD(v66), v68);
  v68 += HIDWORD(v66);
  v70 = v6;
  v71 = a3[1] * (unsigned __int64)a2[4];
  v6 = __CFADD__((_DWORD)v71, v67);
  v72 = v71 + v67;
  v74 = v6;
  v6 = __CFADD__(v6, v68);
  v73 = v74 + v68;
  v6 |= __CFADD__(HIDWORD(v71), v73);
  v73 += HIDWORD(v71);
  v75 = v6 + v70;
  v76 = a3[2] * (unsigned __int64)a2[3];
  v6 = __CFADD__((_DWORD)v76, v72);
  v77 = v76 + v72;
  v79 = v6;
  v6 = __CFADD__(v6, v73);
  v78 = v79 + v73;
  v6 |= __CFADD__(HIDWORD(v76), v78);
  v78 += HIDWORD(v76);
  v80 = v6 + v75;
  v81 = a3[3] * (unsigned __int64)a2[2];
  v6 = __CFADD__((_DWORD)v81, v77);
  v82 = v81 + v77;
  v84 = v6;
  v6 = __CFADD__(v6, v78);
  v83 = v84 + v78;
  v6 |= __CFADD__(HIDWORD(v81), v83);
  v83 += HIDWORD(v81);
  v85 = v6 + v80;
  v86 = a3[4] * (unsigned __int64)a2[1];
  v6 = __CFADD__((_DWORD)v86, v82);
  v87 = v86 + v82;
  v89 = v6;
  v6 = __CFADD__(v6, v83);
  v88 = v89 + v83;
  v6 |= __CFADD__(HIDWORD(v86), v88);
  v88 += HIDWORD(v86);
  v90 = v6 + v85;
  v91 = a3[5] * (unsigned __int64)*a2;
  v6 = __CFADD__(__CFADD__((_DWORD)v91, v87), v88);
  v92 = __CFADD__((_DWORD)v91, v87) + v88;
  v6 |= __CFADD__(HIDWORD(v91), v92);
  v92 += HIDWORD(v91);
  HIDWORD(v91) = *a3;
  v93 = v6 + v90;
  a1[5] = v91 + v87;
  v94 = HIDWORD(v91) * (unsigned __int64)a2[6];
  v6 = __CFADD__((_DWORD)v94, v92);
  v95 = v94 + v92;
  v97 = v6;
  v6 = __CFADD__(v6, v93);
  v96 = v97 + v93;
  v6 |= __CFADD__(HIDWORD(v94), v96);
  v96 += HIDWORD(v94);
  v98 = v6;
  v99 = a3[1] * (unsigned __int64)a2[5];
  v6 = __CFADD__((_DWORD)v99, v95);
  v100 = v99 + v95;
  v102 = v6;
  v6 = __CFADD__(v6, v96);
  v101 = v102 + v96;
  v6 |= __CFADD__(HIDWORD(v99), v101);
  v101 += HIDWORD(v99);
  v103 = v6 + v98;
  v104 = a3[2] * (unsigned __int64)a2[4];
  v6 = __CFADD__((_DWORD)v104, v100);
  v105 = v104 + v100;
  v107 = v6;
  v6 = __CFADD__(v6, v101);
  v106 = v107 + v101;
  v6 |= __CFADD__(HIDWORD(v104), v106);
  v106 += HIDWORD(v104);
  v108 = v6 + v103;
  v109 = a3[3] * (unsigned __int64)a2[3];
  v6 = __CFADD__((_DWORD)v109, v105);
  v110 = v109 + v105;
  v112 = v6;
  v6 = __CFADD__(v6, v106);
  v111 = v112 + v106;
  v6 |= __CFADD__(HIDWORD(v109), v111);
  v111 += HIDWORD(v109);
  v113 = v6 + v108;
  v114 = a3[4] * (unsigned __int64)a2[2];
  v6 = __CFADD__((_DWORD)v114, v110);
  v115 = v114 + v110;
  v117 = v6;
  v6 = __CFADD__(v6, v111);
  v116 = v117 + v111;
  v6 |= __CFADD__(HIDWORD(v114), v116);
  v116 += HIDWORD(v114);
  v118 = v6 + v113;
  v119 = a3[5] * (unsigned __int64)a2[1];
  v6 = __CFADD__((_DWORD)v119, v115);
  v120 = v119 + v115;
  v122 = v6;
  v6 = __CFADD__(v6, v116);
  v121 = v122 + v116;
  v6 |= __CFADD__(HIDWORD(v119), v121);
  v121 += HIDWORD(v119);
  v123 = v6 + v118;
  v124 = a3[6] * (unsigned __int64)*a2;
  v6 = __CFADD__(__CFADD__((_DWORD)v124, v120), v121);
  v125 = __CFADD__((_DWORD)v124, v120) + v121;
  v6 |= __CFADD__(HIDWORD(v124), v125);
  v125 += HIDWORD(v124);
  HIDWORD(v124) = *a3;
  v126 = v6 + v123;
  a1[6] = v124 + v120;
  v127 = HIDWORD(v124) * (unsigned __int64)a2[7];
  v6 = __CFADD__((_DWORD)v127, v125);
  v128 = v127 + v125;
  v130 = v6;
  v6 = __CFADD__(v6, v126);
  v129 = v130 + v126;
  v6 |= __CFADD__(HIDWORD(v127), v129);
  v129 += HIDWORD(v127);
  v131 = v6;
  v132 = a3[1] * (unsigned __int64)a2[6];
  v6 = __CFADD__((_DWORD)v132, v128);
  v133 = v132 + v128;
  v135 = v6;
  v6 = __CFADD__(v6, v129);
  v134 = v135 + v129;
  v6 |= __CFADD__(HIDWORD(v132), v134);
  v134 += HIDWORD(v132);
  v136 = v6 + v131;
  v137 = a3[2] * (unsigned __int64)a2[5];
  v6 = __CFADD__((_DWORD)v137, v133);
  v138 = v137 + v133;
  v140 = v6;
  v6 = __CFADD__(v6, v134);
  v139 = v140 + v134;
  v6 |= __CFADD__(HIDWORD(v137), v139);
  v139 += HIDWORD(v137);
  v141 = v6 + v136;
  v142 = a3[3] * (unsigned __int64)a2[4];
  v6 = __CFADD__((_DWORD)v142, v138);
  v143 = v142 + v138;
  v145 = v6;
  v6 = __CFADD__(v6, v139);
  v144 = v145 + v139;
  v6 |= __CFADD__(HIDWORD(v142), v144);
  v144 += HIDWORD(v142);
  v146 = v6 + v141;
  v147 = a3[4] * (unsigned __int64)a2[3];
  v6 = __CFADD__((_DWORD)v147, v143);
  v148 = v147 + v143;
  v150 = v6;
  v6 = __CFADD__(v6, v144);
  v149 = v150 + v144;
  v6 |= __CFADD__(HIDWORD(v147), v149);
  v149 += HIDWORD(v147);
  v151 = v6 + v146;
  v152 = a3[5] * (unsigned __int64)a2[2];
  v6 = __CFADD__((_DWORD)v152, v148);
  v153 = v152 + v148;
  v155 = v6;
  v6 = __CFADD__(v6, v149);
  v154 = v155 + v149;
  v6 |= __CFADD__(HIDWORD(v152), v154);
  v154 += HIDWORD(v152);
  v156 = v6 + v151;
  v157 = a3[6] * (unsigned __int64)a2[1];
  v6 = __CFADD__((_DWORD)v157, v153);
  v158 = v157 + v153;
  v160 = v6;
  v6 = __CFADD__(v6, v154);
  v159 = v160 + v154;
  v6 |= __CFADD__(HIDWORD(v157), v159);
  v159 += HIDWORD(v157);
  v161 = v6 + v156;
  v162 = a3[7] * (unsigned __int64)*a2;
  v6 = __CFADD__(__CFADD__((_DWORD)v162, v158), v159);
  v163 = __CFADD__((_DWORD)v162, v158) + v159;
  v6 |= __CFADD__(HIDWORD(v162), v163);
  v163 += HIDWORD(v162);
  HIDWORD(v162) = a3[1];
  v164 = v6 + v161;
  a1[7] = v162 + v158;
  v165 = HIDWORD(v162) * (unsigned __int64)a2[7];
  v6 = __CFADD__((_DWORD)v165, v163);
  v166 = v165 + v163;
  v168 = v6;
  v6 = __CFADD__(v6, v164);
  v167 = v168 + v164;
  v6 |= __CFADD__(HIDWORD(v165), v167);
  v167 += HIDWORD(v165);
  v169 = v6;
  v170 = a3[2] * (unsigned __int64)a2[6];
  v6 = __CFADD__((_DWORD)v170, v166);
  v171 = v170 + v166;
  v173 = v6;
  v6 = __CFADD__(v6, v167);
  v172 = v173 + v167;
  v6 |= __CFADD__(HIDWORD(v170), v172);
  v172 += HIDWORD(v170);
  v174 = v6 + v169;
  v175 = a3[3] * (unsigned __int64)a2[5];
  v6 = __CFADD__((_DWORD)v175, v171);
  v176 = v175 + v171;
  v178 = v6;
  v6 = __CFADD__(v6, v172);
  v177 = v178 + v172;
  v6 |= __CFADD__(HIDWORD(v175), v177);
  v177 += HIDWORD(v175);
  v179 = v6 + v174;
  v180 = a3[4] * (unsigned __int64)a2[4];
  v6 = __CFADD__((_DWORD)v180, v176);
  v181 = v180 + v176;
  v183 = v6;
  v6 = __CFADD__(v6, v177);
  v182 = v183 + v177;
  v6 |= __CFADD__(HIDWORD(v180), v182);
  v182 += HIDWORD(v180);
  v184 = v6 + v179;
  v185 = a3[5] * (unsigned __int64)a2[3];
  v6 = __CFADD__((_DWORD)v185, v181);
  v186 = v185 + v181;
  v188 = v6;
  v6 = __CFADD__(v6, v182);
  v187 = v188 + v182;
  v6 |= __CFADD__(HIDWORD(v185), v187);
  v187 += HIDWORD(v185);
  v189 = v6 + v184;
  v190 = a3[6] * (unsigned __int64)a2[2];
  v6 = __CFADD__((_DWORD)v190, v186);
  v191 = v190 + v186;
  v193 = v6;
  v6 = __CFADD__(v6, v187);
  v192 = v193 + v187;
  v6 |= __CFADD__(HIDWORD(v190), v192);
  v192 += HIDWORD(v190);
  v194 = v6 + v189;
  v195 = a3[7] * (unsigned __int64)a2[1];
  v6 = __CFADD__(__CFADD__((_DWORD)v195, v191), v192);
  v196 = __CFADD__((_DWORD)v195, v191) + v192;
  v6 |= __CFADD__(HIDWORD(v195), v196);
  v196 += HIDWORD(v195);
  HIDWORD(v195) = a3[2];
  v197 = v6 + v194;
  a1[8] = v195 + v191;
  v198 = HIDWORD(v195) * (unsigned __int64)a2[7];
  v6 = __CFADD__((_DWORD)v198, v196);
  v199 = v198 + v196;
  v201 = v6;
  v6 = __CFADD__(v6, v197);
  v200 = v201 + v197;
  v6 |= __CFADD__(HIDWORD(v198), v200);
  v200 += HIDWORD(v198);
  v202 = v6;
  v203 = a3[3] * (unsigned __int64)a2[6];
  v6 = __CFADD__((_DWORD)v203, v199);
  v204 = v203 + v199;
  v206 = v6;
  v6 = __CFADD__(v6, v200);
  v205 = v206 + v200;
  v6 |= __CFADD__(HIDWORD(v203), v205);
  v205 += HIDWORD(v203);
  v207 = v6 + v202;
  v208 = a3[4] * (unsigned __int64)a2[5];
  v6 = __CFADD__((_DWORD)v208, v204);
  v209 = v208 + v204;
  v211 = v6;
  v6 = __CFADD__(v6, v205);
  v210 = v211 + v205;
  v6 |= __CFADD__(HIDWORD(v208), v210);
  v210 += HIDWORD(v208);
  v212 = v6 + v207;
  v213 = a3[5] * (unsigned __int64)a2[4];
  v6 = __CFADD__((_DWORD)v213, v209);
  v214 = v213 + v209;
  v216 = v6;
  v6 = __CFADD__(v6, v210);
  v215 = v216 + v210;
  v6 |= __CFADD__(HIDWORD(v213), v215);
  v215 += HIDWORD(v213);
  v217 = v6 + v212;
  v218 = a3[6] * (unsigned __int64)a2[3];
  v6 = __CFADD__((_DWORD)v218, v214);
  v219 = v218 + v214;
  v221 = v6;
  v6 = __CFADD__(v6, v215);
  v220 = v221 + v215;
  v6 |= __CFADD__(HIDWORD(v218), v220);
  v220 += HIDWORD(v218);
  v222 = v6 + v217;
  v223 = a3[7] * (unsigned __int64)a2[2];
  v6 = __CFADD__(__CFADD__((_DWORD)v223, v219), v220);
  v224 = __CFADD__((_DWORD)v223, v219) + v220;
  v6 |= __CFADD__(HIDWORD(v223), v224);
  v224 += HIDWORD(v223);
  HIDWORD(v223) = a3[3];
  v225 = v6 + v222;
  a1[9] = v223 + v219;
  v226 = HIDWORD(v223) * (unsigned __int64)a2[7];
  v6 = __CFADD__((_DWORD)v226, v224);
  v227 = v226 + v224;
  v229 = v6;
  v6 = __CFADD__(v6, v225);
  v228 = v229 + v225;
  v6 |= __CFADD__(HIDWORD(v226), v228);
  v228 += HIDWORD(v226);
  v230 = v6;
  v231 = a3[4] * (unsigned __int64)a2[6];
  v6 = __CFADD__((_DWORD)v231, v227);
  v232 = v231 + v227;
  v234 = v6;
  v6 = __CFADD__(v6, v228);
  v233 = v234 + v228;
  v6 |= __CFADD__(HIDWORD(v231), v233);
  v233 += HIDWORD(v231);
  v235 = v6 + v230;
  v236 = a3[5] * (unsigned __int64)a2[5];
  v6 = __CFADD__((_DWORD)v236, v232);
  v237 = v236 + v232;
  v239 = v6;
  v6 = __CFADD__(v6, v233);
  v238 = v239 + v233;
  v6 |= __CFADD__(HIDWORD(v236), v238);
  v238 += HIDWORD(v236);
  v240 = v6 + v235;
  v241 = a3[6] * (unsigned __int64)a2[4];
  v6 = __CFADD__((_DWORD)v241, v237);
  v242 = v241 + v237;
  v244 = v6;
  v6 = __CFADD__(v6, v238);
  v243 = v244 + v238;
  v6 |= __CFADD__(HIDWORD(v241), v243);
  v243 += HIDWORD(v241);
  v245 = v6 + v240;
  v246 = a3[7] * (unsigned __int64)a2[3];
  v6 = __CFADD__(__CFADD__((_DWORD)v246, v242), v243);
  v247 = __CFADD__((_DWORD)v246, v242) + v243;
  v6 |= __CFADD__(HIDWORD(v246), v247);
  v247 += HIDWORD(v246);
  HIDWORD(v246) = a3[4];
  v248 = v6 + v245;
  a1[10] = v246 + v242;
  v249 = HIDWORD(v246) * (unsigned __int64)a2[7];
  v6 = __CFADD__((_DWORD)v249, v247);
  v250 = v249 + v247;
  v252 = v6;
  v6 = __CFADD__(v6, v248);
  v251 = v252 + v248;
  v6 |= __CFADD__(HIDWORD(v249), v251);
  v251 += HIDWORD(v249);
  v253 = v6;
  v254 = a3[5] * (unsigned __int64)a2[6];
  v6 = __CFADD__((_DWORD)v254, v250);
  v255 = v254 + v250;
  v257 = v6;
  v6 = __CFADD__(v6, v251);
  v256 = v257 + v251;
  v6 |= __CFADD__(HIDWORD(v254), v256);
  v256 += HIDWORD(v254);
  v258 = v6 + v253;
  v259 = a3[6] * (unsigned __int64)a2[5];
  v6 = __CFADD__((_DWORD)v259, v255);
  v260 = v259 + v255;
  v262 = v6;
  v6 = __CFADD__(v6, v256);
  v261 = v262 + v256;
  v6 |= __CFADD__(HIDWORD(v259), v261);
  v261 += HIDWORD(v259);
  v263 = v6 + v258;
  v264 = a3[7] * (unsigned __int64)a2[4];
  v6 = __CFADD__(__CFADD__((_DWORD)v264, v260), v261);
  v265 = __CFADD__((_DWORD)v264, v260) + v261;
  v6 |= __CFADD__(HIDWORD(v264), v265);
  v265 += HIDWORD(v264);
  HIDWORD(v264) = a3[5];
  v266 = v6 + v263;
  a1[11] = v264 + v260;
  v267 = HIDWORD(v264) * (unsigned __int64)a2[7];
  v6 = __CFADD__((_DWORD)v267, v265);
  v268 = v267 + v265;
  v270 = v6;
  v6 = __CFADD__(v6, v266);
  v269 = v270 + v266;
  v6 |= __CFADD__(HIDWORD(v267), v269);
  v269 += HIDWORD(v267);
  v271 = v6;
  v272 = a3[6] * (unsigned __int64)a2[6];
  v6 = __CFADD__((_DWORD)v272, v268);
  v273 = v272 + v268;
  v275 = v6;
  v6 = __CFADD__(v6, v269);
  v274 = v275 + v269;
  v6 |= __CFADD__(HIDWORD(v272), v274);
  v274 += HIDWORD(v272);
  v276 = v6 + v271;
  v277 = a3[7] * (unsigned __int64)a2[5];
  v6 = __CFADD__(__CFADD__((_DWORD)v277, v273), v274);
  v278 = __CFADD__((_DWORD)v277, v273) + v274;
  v6 |= __CFADD__(HIDWORD(v277), v278);
  v278 += HIDWORD(v277);
  HIDWORD(v277) = a3[6];
  v279 = v6 + v276;
  a1[12] = v277 + v273;
  v280 = HIDWORD(v277) * (unsigned __int64)a2[7];
  v6 = __CFADD__((_DWORD)v280, v278);
  v281 = v280 + v278;
  v283 = v6;
  v6 = __CFADD__(v6, v279);
  v282 = v283 + v279;
  v6 |= __CFADD__(HIDWORD(v280), v282);
  v282 += HIDWORD(v280);
  v284 = v6;
  v285 = a3[7] * (unsigned __int64)a2[6];
  v6 = __CFADD__(__CFADD__((_DWORD)v285, v281), v282);
  v286 = __CFADD__((_DWORD)v285, v281) + v282;
  v6 |= __CFADD__(HIDWORD(v285), v286);
  v286 += HIDWORD(v285);
  HIDWORD(v285) = a3[7];
  v287 = v6 + v284;
  a1[13] = v285 + v281;
  v288 = HIDWORD(v285) * (unsigned __int64)a2[7];
  v6 = __CFADD__((_DWORD)v288, v286);
  v289 = v288 + v286;
  result = a1;
  a1[14] = v289;
  a1[15] = HIDWORD(v288) + v6 + v287;
  return result;
}
