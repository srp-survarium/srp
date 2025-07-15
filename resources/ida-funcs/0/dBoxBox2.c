int __fastcall dBoxBox2(
        const btVector3 *side1,
        const btVector3 *side2,
        const btVector3 *p1,
        const float *R1,
        const btVector3 *p2,
        const float *R2,
        btVector3 *normal,
        float *depth,
        int *return_code,
        int *maxc)
{
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm6_4
  float v14; // xmm5_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm7_4
  float v18; // xmm4_4
  float v19; // xmm7_4
  float v20; // xmm4_4
  float v21; // xmm2_4
  float v22; // xmm4_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm7_4
  float v27; // xmm4_4
  float v28; // xmm0_4
  float v29; // xmm2_4
  float v30; // xmm5_4
  float v31; // xmm6_4
  int v32; // xmm0_4
  float v33; // xmm5_4
  float v34; // xmm5_4
  float v35; // xmm6_4
  float v36; // xmm0_4
  float v37; // xmm4_4
  float v38; // xmm2_4
  float v39; // xmm4_4
  float v40; // xmm2_4
  float v41; // xmm2_4
  int result; // eax
  float v43; // xmm2_4
  float v44; // xmm2_4
  float v45; // xmm2_4
  float v46; // xmm2_4
  const float *v47; // esi
  BOOL v48; // edx
  float v49; // xmm2_4
  float v50; // xmm3_4
  float v51; // xmm6_4
  float v52; // xmm5_4
  float v53; // xmm6_4
  float v54; // xmm3_4
  float v55; // xmm6_4
  float v56; // xmm5_4
  float v57; // xmm6_4
  float v58; // xmm5_4
  float v59; // xmm6_4
  float v60; // xmm5_4
  float v61; // xmm6_4
  float v62; // xmm5_4
  float v63; // xmm4_4
  float v64; // xmm6_4
  float v65; // xmm5_4
  float v66; // xmm6_4
  float v67; // xmm4_4
  float v68; // xmm6_4
  float v69; // xmm5_4
  float v70; // xmm6_4
  float v71; // xmm4_4
  float v72; // xmm6_4
  float v73; // xmm5_4
  float v74; // xmm6_4
  float v75; // xmm4_4
  float v76; // xmm7_4
  float v77; // xmm5_4
  float v78; // xmm6_4
  float v79; // xmm2_4
  float v80; // xmm5_4
  float v81; // xmm4_4
  const float *v82; // edi
  bool v83; // cc
  const float *v84; // edx
  float v85; // xmm4_4
  float v86; // xmm5_4
  float v87; // xmm6_4
  float v88; // xmm3_4
  float v89; // xmm0_4
  int v90; // edi
  float *v91; // ecx
  const float *v92; // edx
  float v93; // xmm3_4
  float v94; // xmm0_4
  int v95; // esi
  float *v96; // ecx
  float *v97; // eax
  float v98; // xmm7_4
  int v99; // esi
  int v100; // edx
  float *v101; // eax
  int v102; // eax
  float *v103; // ebx
  float v104; // xmm0_4
  float v105; // xmm7_4
  float v106; // xmm4_4
  float v107; // xmm6_4
  float v108; // xmm4_4
  float v109; // xmm0_4
  float v110; // xmm3_4
  int j; // edx
  float v112; // xmm3_4
  float *v113; // eax
  int k; // edx
  float v115; // xmm3_4
  float *v116; // eax
  int v117; // eax
  const btVector3 *v118; // esi
  const btVector3 *v119; // ebx
  float *v120; // ecx
  float *v121; // edx
  float v122; // xmm5_4
  float v123; // xmm6_4
  float v124; // xmm7_4
  unsigned int v125; // xmm2_4
  unsigned int v126; // xmm3_4
  float v127; // xmm4_4
  float v128; // xmm7_4
  float v129; // xmm5_4
  float v130; // xmm2_4
  float v131; // xmm3_4
  float v132; // xmm4_4
  int v133; // eax
  int v134; // eax
  float v135; // xmm0_4
  float *v136; // ecx
  char *v137; // eax
  char *v138; // eax
  int v139; // eax
  int v140; // eax
  int v141; // esi
  float *v142; // eax
  float v143; // xmm1_4
  float v144; // xmm5_4
  int v145; // esi
  float *v146; // ecx
  float v147; // xmm3_4
  float v148; // xmm6_4
  float v149; // xmm0_4
  float v150; // xmm4_4
  float *v151; // esi
  float *v152; // edi
  int v153; // xmm2_4
  float v154; // xmm3_4
  float v155; // xmm4_4
  float v156; // xmm0_4
  float v157; // xmm1_4
  float v158; // xmm7_4
  float v159; // xmm4_4
  float v160; // ebx
  float v161; // xmm1_4
  float v162; // xmm2_4
  float v163; // xmm0_4
  float v164; // xmm0_4
  int v165; // edx
  float v166; // xmm3_4
  float v167; // xmm4_4
  float v168; // xmm5_4
  float v169; // eax
  int v170; // edx
  float v171; // xmm6_4
  float *v172; // edx
  float v173; // xmm0_4
  float v174; // xmm2_4
  float v175; // xmm0_4
  int v176; // ebx
  float v177; // eax
  float v178; // xmm1_4
  float *v179; // eax
  float v180; // xmm1_4
  float v181; // xmm7_4
  float *v182; // eax
  int v183; // ebx
  float v184; // xmm0_4
  int v185; // eax
  int v186; // edi
  float *v187; // ebx
  int i; // eax
  int v189; // eax
  float *v190; // ebx
  float v191; // xmm1_4
  btVector3 *v192; // eax
  int v193; // ecx
  int v194; // eax
  float v195; // xmm1_4
  int v196; // ecx
  int v197; // edx
  int v198; // ecx
  float *v199; // eax
  float v200; // xmm1_4
  int v201; // eax
  float v202; // xmm2_4
  float v203; // xmm3_4
  float *v204; // eax
  float v205; // xmm0_4
  int v206; // edx
  float v207; // xmm6_4
  int v208; // [esp+0h] [ebp-1C4h]
  const float *v209; // [esp+10h] [ebp-1B4h]
  float v210; // [esp+10h] [ebp-1B4h]
  float v211; // [esp+10h] [ebp-1B4h]
  float v212; // [esp+10h] [ebp-1B4h]
  float v213; // [esp+10h] [ebp-1B4h]
  int v214; // [esp+10h] [ebp-1B4h]
  const float *v215; // [esp+10h] [ebp-1B4h]
  float v216; // [esp+10h] [ebp-1B4h]
  float *v217; // [esp+10h] [ebp-1B4h]
  float v218; // [esp+14h] [ebp-1B0h]
  float v219[2]; // [esp+18h] [ebp-1ACh] BYREF
  float v220; // [esp+20h] [ebp-1A4h]
  int v221; // [esp+24h] [ebp-1A0h]
  int v222; // [esp+28h] [ebp-19Ch]
  float v223; // [esp+2Ch] [ebp-198h]
  int v224; // [esp+30h] [ebp-194h]
  float v225; // [esp+34h] [ebp-190h]
  float v226; // [esp+38h] [ebp-18Ch]
  float v227; // [esp+3Ch] [ebp-188h]
  float v228; // [esp+40h] [ebp-184h]
  float v229; // [esp+44h] [ebp-180h] BYREF
  float v230; // [esp+48h] [ebp-17Ch]
  float v231; // [esp+4Ch] [ebp-178h]
  int v232; // [esp+50h] [ebp-174h]
  float v233; // [esp+5Ch] [ebp-168h] BYREF
  float v234; // [esp+60h] [ebp-164h]
  float v235; // [esp+64h] [ebp-160h]
  float v236; // [esp+68h] [ebp-15Ch] BYREF
  float v237; // [esp+6Ch] [ebp-158h]
  float v238; // [esp+70h] [ebp-154h]
  float v239; // [esp+74h] [ebp-150h]
  float v240; // [esp+78h] [ebp-14Ch]
  float v241; // [esp+7Ch] [ebp-148h]
  float v242; // [esp+80h] [ebp-144h]
  unsigned __int64 v243; // [esp+84h] [ebp-140h] BYREF
  float v244; // [esp+8Ch] [ebp-138h]
  float v245; // [esp+90h] [ebp-134h]
  float v246; // [esp+94h] [ebp-130h] BYREF
  float v247; // [esp+98h] [ebp-12Ch]
  float v248; // [esp+9Ch] [ebp-128h]
  float v249; // [esp+A8h] [ebp-11Ch]
  float v250; // [esp+ACh] [ebp-118h]
  float v251; // [esp+B0h] [ebp-114h]
  float v252; // [esp+B4h] [ebp-110h]
  float v253; // [esp+B8h] [ebp-10Ch]
  float v254; // [esp+BCh] [ebp-108h]
  float v255; // [esp+C0h] [ebp-104h]
  unsigned __int64 v256; // [esp+C4h] [ebp-100h] BYREF
  float v257; // [esp+CCh] [ebp-F8h]
  float v258; // [esp+D0h] [ebp-F4h]
  float v259; // [esp+D4h] [ebp-F0h]
  float v260; // [esp+D8h] [ebp-ECh]
  float v261; // [esp+DCh] [ebp-E8h]
  float v262; // [esp+E0h] [ebp-E4h]
  float v263[8]; // [esp+E4h] [ebp-E0h] BYREF
  float v264[16]; // [esp+104h] [ebp-C0h] BYREF
  int v265[8]; // [esp+144h] [ebp-80h] BYREF
  _DWORD v266[24]; // [esp+164h] [ebp-60h] BYREF

  v10 = p2->mVec128.m128_f32[0];
  v11 = p2->mVec128.m128_f32[2];
  v12 = p2->mVec128.m128_f32[1];
  v209 = 0;
  v13 = R1[8];
  v14 = R1[4];
  v223 = *R1;
  v15 = v12 - p1->mVec128.m128_f32[1];
  v16 = v10 - p1->mVec128.m128_f32[0];
  v248 = v11 - p1->mVec128.m128_f32[2];
  v17 = R1[5] * v15;
  *(float *)&v243 = (float)((float)(v16 * v223) + (float)(v13 * v248)) + (float)(v14 * v15);
  v18 = (float)((float)(R1[9] * v248) + v17) + (float)(v16 * R1[1]);
  v19 = *R2;
  *((float *)&v243 + 1) = v18;
  v20 = (float)(R1[10] * v248) + (float)(R1[6] * v15);
  v21 = side1->mVec128.m128_f32[0];
  v247 = v15;
  v22 = v20 + (float)(v16 * R1[2]);
  v233 = v21 * 0.5;
  v234 = side1->mVec128.m128_f32[1] * 0.5;
  v235 = side1->mVec128.m128_f32[2] * 0.5;
  v236 = side2->mVec128.m128_f32[0] * 0.5;
  v237 = side2->mVec128.m128_f32[1] * 0.5;
  v23 = side2->mVec128.m128_f32[2] * 0.5;
  v24 = R2[8];
  v219[0] = v19;
  v238 = v23;
  v25 = R2[4];
  v229 = 0.0;
  v230 = 0.0;
  v231 = 0.0;
  v244 = v22;
  v26 = (float)((float)(v19 * v223) + (float)(v24 * v13)) + (float)(v25 * v14);
  v27 = R2[4];
  v241 = (float)((float)(R2[9] * v13) + (float)(R2[5] * v14)) + (float)(R2[1] * v223);
  v28 = (float)((float)(R2[10] * v13) + (float)(R2[6] * v14)) + (float)(R2[2] * v223);
  v29 = R2[8];
  v30 = R1[9];
  v220 = v28;
  v31 = R1[9] * R2[10];
  *(float *)&v32 = (float)((float)(R1[5] * v27) + (float)(v30 * v29)) + (float)(v219[0] * R1[1]);
  v33 = R1[9] * R2[9];
  v222 = v32;
  v34 = (float)(v33 + (float)(R1[5] * R2[5])) + (float)(R2[1] * R1[1]);
  v35 = (float)(v31 + (float)(R1[5] * R2[6])) + (float)(R1[1] * R2[2]);
  v36 = (float)(R1[6] * v27) + (float)(R1[10] * v29);
  v37 = R1[10] * R2[9];
  v38 = R1[10] * R2[10];
  v240 = v36 + (float)(R1[2] * v219[0]);
  v39 = (float)(v37 + (float)(R1[6] * R2[5])) + (float)(R1[2] * R2[1]);
  v40 = (float)(v38 + (float)(R1[6] * R2[6])) + (float)(R1[2] * R2[2]);
  v228 = v26;
  v226 = v34;
  v227 = v35;
  v242 = v40;
  LODWORD(v250) = LODWORD(v26) & _mask__AbsFloat_;
  v225 = 0.0;
  v221 = 0;
  LODWORD(v255) = LODWORD(v34) & _mask__AbsFloat_;
  LODWORD(v252) = LODWORD(v240) & _mask__AbsFloat_;
  LODWORD(v254) = LODWORD(v241) & _mask__AbsFloat_;
  v224 = LODWORD(v220) & _mask__AbsFloat_;
  LODWORD(v239) = LODWORD(v35) & _mask__AbsFloat_;
  LODWORD(v253) = LODWORD(v39) & _mask__AbsFloat_;
  LODWORD(v251) = LODWORD(v40) & _mask__AbsFloat_;
  v218 = FLOAT_N3_4028235e38;
  v41 = COERCE_FLOAT(v243 & _mask__AbsFloat_)
      - (float)((float)((float)((float)(COERCE_FLOAT(LODWORD(v220) & _mask__AbsFloat_) * v238)
                              + (float)(COERCE_FLOAT(LODWORD(v241) & _mask__AbsFloat_) * v237))
                      + (float)(COERCE_FLOAT(LODWORD(v26) & _mask__AbsFloat_) * v236))
              + v233);
  LODWORD(v249) = v222 & _mask__AbsFloat_;
  if ( v41 > 0.0 )
    return 0;
  if ( v41 > -3.4028235e38 )
  {
    v218 = COERCE_FLOAT(v243 & _mask__AbsFloat_)
         - (float)((float)((float)((float)(COERCE_FLOAT(LODWORD(v220) & _mask__AbsFloat_) * v238)
                                 + (float)(COERCE_FLOAT(LODWORD(v241) & _mask__AbsFloat_) * v237))
                         + (float)(COERCE_FLOAT(LODWORD(v26) & _mask__AbsFloat_) * v236))
                 + v233);
    v209 = R1;
    LODWORD(v225) = *(float *)&v243 < 0.0;
    v221 = 1;
  }
  v43 = COERCE_FLOAT(HIDWORD(v243) & _mask__AbsFloat_)
      - (float)((float)((float)((float)(v239 * v238) + (float)(v255 * v237)) + (float)(v249 * v236)) + v234);
  if ( v43 > 0.0 )
    return 0;
  if ( v43 > v218 )
  {
    v218 = COERCE_FLOAT(HIDWORD(v243) & _mask__AbsFloat_)
         - (float)((float)((float)((float)(v239 * v238) + (float)(v255 * v237)) + (float)(v249 * v236)) + v234);
    v209 = R1 + 1;
    LODWORD(v225) = *((float *)&v243 + 1) < 0.0;
    v221 = 2;
  }
  v44 = COERCE_FLOAT(LODWORD(v244) & _mask__AbsFloat_)
      - (float)((float)((float)((float)(v251 * v238) + (float)(v253 * v237)) + (float)(v252 * v236)) + v235);
  if ( v44 > 0.0 )
    return 0;
  if ( v44 > v218 )
  {
    v218 = COERCE_FLOAT(LODWORD(v244) & _mask__AbsFloat_)
         - (float)((float)((float)((float)(v251 * v238) + (float)(v253 * v237)) + (float)(v252 * v236)) + v235);
    v209 = R1 + 2;
    LODWORD(v225) = v244 < 0.0;
    v221 = 3;
  }
  v219[0] = (float)((float)(v16 * v219[0]) + (float)(R2[8] * v248)) + (float)(R2[4] * v247);
  v45 = COERCE_FLOAT(LODWORD(v219[0]) & _mask__AbsFloat_)
      - (float)((float)((float)((float)(v252 * v235) + (float)(v249 * v234)) + (float)(v250 * v233)) + v236);
  if ( v45 > 0.0 )
    return 0;
  if ( v45 > v218 )
  {
    v218 = COERCE_FLOAT(LODWORD(v219[0]) & _mask__AbsFloat_)
         - (float)((float)((float)((float)(v252 * v235) + (float)(v249 * v234)) + (float)(v250 * v233)) + v236);
    v209 = R2;
    LODWORD(v225) = v219[0] < 0.0;
    v221 = 4;
  }
  v46 = COERCE_FLOAT(
          COERCE_UNSIGNED_INT((float)((float)(R2[9] * v248) + (float)(R2[5] * v247)) + (float)(v16 * R2[1]))
        & _mask__AbsFloat_)
      - (float)((float)((float)((float)(v253 * v235) + (float)(v255 * v234)) + (float)(v254 * v233)) + v237);
  if ( v46 > 0.0 )
    return 0;
  if ( v46 <= v218 )
  {
    v48 = LODWORD(v225);
    v47 = v209;
  }
  else
  {
    v218 = COERCE_FLOAT(
             COERCE_UNSIGNED_INT((float)((float)(R2[9] * v248) + (float)(R2[5] * v247)) + (float)(v16 * R2[1]))
           & _mask__AbsFloat_)
         - (float)((float)((float)((float)(v253 * v235) + (float)(v255 * v234)) + (float)(v254 * v233)) + v237);
    v47 = R2 + 1;
    v48 = (float)((float)((float)(R2[9] * v248) + (float)(R2[5] * v247)) + (float)(v16 * R2[1])) < 0.0;
    v221 = 5;
  }
  v49 = COERCE_FLOAT(
          COERCE_UNSIGNED_INT((float)((float)(R2[10] * v248) + (float)(R2[6] * v247)) + (float)(R2[2] * v16))
        & _mask__AbsFloat_)
      - (float)((float)((float)((float)(v251 * v235) + (float)(v239 * v234)) + (float)(*(float *)&v224 * v233)) + v238);
  if ( v49 > 0.0 )
    return 0;
  if ( v49 > v218 )
  {
    v218 = COERCE_FLOAT(
             COERCE_UNSIGNED_INT((float)((float)(R2[10] * v248) + (float)(R2[6] * v247)) + (float)(R2[2] * v16))
           & _mask__AbsFloat_)
         - (float)((float)((float)((float)(v251 * v235) + (float)(v239 * v234)) + (float)(*(float *)&v224 * v233)) + v238);
    v47 = R2 + 2;
    v48 = (float)((float)((float)(R2[10] * v248) + (float)(R2[6] * v247)) + (float)(v16 * R2[2])) < 0.0;
    v221 = 6;
  }
  v250 = v250 + 0.0000099999997;
  v254 = v254 + 0.0000099999997;
  *(float *)&v224 = *(float *)&v224 + 0.0000099999997;
  v249 = v249 + 0.0000099999997;
  v255 = v255 + 0.0000099999997;
  v239 = v239 + 0.0000099999997;
  v252 = v252 + 0.0000099999997;
  v253 = v253 + 0.0000099999997;
  v251 = v251 + 0.0000099999997;
  v50 = COERCE_FLOAT(
          COERCE_UNSIGNED_INT((float)(v244 * *(float *)&v222) - (float)(v240 * *((float *)&v243 + 1)))
        & _mask__AbsFloat_)
      - (float)((float)((float)((float)(v254 * v238) + (float)(*(float *)&v224 * v237)) + (float)(v252 * v234))
              + (float)(v249 * v235));
  if ( v50 > 0.00000011920929 )
    return 0;
  LODWORD(v219[0]) = LODWORD(v240) ^ _mask__NegFloat_;
  v51 = fsqrt(
          (float)(COERCE_FLOAT(LODWORD(v240) ^ _mask__NegFloat_) * COERCE_FLOAT(LODWORD(v240) ^ _mask__NegFloat_))
        + (float)(*(float *)&v222 * *(float *)&v222));
  if ( v51 <= 0.00000011920929
    || (v52 = s_bm_current_air_resistance / v51,
        v53 = (float)(s_bm_current_air_resistance / v51) * v50,
        (float)(v53 * 1.05) <= v218) )
  {
    v54 = v229;
  }
  else
  {
    v218 = v53;
    v47 = 0;
    v54 = v52 * 0.0;
    v230 = v52 * v219[0];
    v231 = v52 * *(float *)&v222;
    v48 = (float)((float)(v244 * *(float *)&v222) - (float)(v240 * *((float *)&v243 + 1))) < 0.0;
    v221 = 7;
  }
  v210 = (float)(v244 * v226) - (float)(v39 * *((float *)&v243 + 1));
  LODWORD(v219[0]) = LODWORD(v210) & _mask__AbsFloat_;
  v225 = COERCE_FLOAT(LODWORD(v210) & _mask__AbsFloat_)
       - (float)((float)((float)((float)(v250 * v238) + (float)(*(float *)&v224 * v236)) + (float)(v253 * v234))
               + (float)(v255 * v235));
  if ( v225 > 0.00000011920929 )
    return 0;
  LODWORD(v219[0]) = LODWORD(v39) ^ _mask__NegFloat_;
  v55 = fsqrt((float)(v219[0] * v219[0]) + (float)(v226 * v226));
  if ( v55 > 0.00000011920929 )
  {
    v56 = s_bm_current_air_resistance / v55;
    if ( (float)((float)((float)(s_bm_current_air_resistance / v55) * v225) * 1.05) > v218 )
    {
      v218 = v56 * v225;
      v47 = 0;
      v54 = v56 * 0.0;
      v230 = v219[0] * v56;
      v231 = v56 * v226;
      v48 = v210 < 0.0;
      v221 = 8;
    }
  }
  v211 = (float)(v244 * v227) - (float)(v242 * *((float *)&v243 + 1));
  LODWORD(v219[0]) = LODWORD(v211) & _mask__AbsFloat_;
  v225 = COERCE_FLOAT(LODWORD(v211) & _mask__AbsFloat_)
       - (float)((float)((float)((float)(v251 * v234) + (float)(v250 * v237)) + (float)(v239 * v235))
               + (float)(v254 * v236));
  if ( v225 > 0.00000011920929 )
    return 0;
  v57 = fsqrt(
          (float)(v227 * v227)
        + (float)(COERCE_FLOAT(LODWORD(v242) ^ _mask__NegFloat_) * COERCE_FLOAT(LODWORD(v242) ^ _mask__NegFloat_)));
  LODWORD(v219[0]) = LODWORD(v242) ^ _mask__NegFloat_;
  if ( v57 > 0.00000011920929 )
  {
    v58 = s_bm_current_air_resistance / v57;
    if ( (float)((float)((float)(s_bm_current_air_resistance / v57) * v225) * 1.05) > v218 )
    {
      v218 = v58 * v225;
      v47 = 0;
      v54 = v58 * 0.0;
      v230 = v58 * v219[0];
      v231 = v58 * v227;
      v48 = v211 < 0.0;
      v221 = 9;
    }
  }
  v212 = (float)(*(float *)&v243 * v240) - (float)(v244 * v228);
  LODWORD(v219[0]) = LODWORD(v212) & _mask__AbsFloat_;
  v225 = COERCE_FLOAT(LODWORD(v212) & _mask__AbsFloat_)
       - (float)((float)((float)((float)(v255 * v238) + (float)(v239 * v237)) + (float)(v252 * v233))
               + (float)(v250 * v235));
  if ( v225 > 0.00000011920929 )
    return 0;
  v59 = fsqrt(
          (float)(v240 * v240)
        + (float)(COERCE_FLOAT(LODWORD(v228) ^ _mask__NegFloat_) * COERCE_FLOAT(LODWORD(v228) ^ _mask__NegFloat_)));
  LODWORD(v219[0]) = LODWORD(v228) ^ _mask__NegFloat_;
  if ( v59 > 0.00000011920929 )
  {
    v60 = s_bm_current_air_resistance / v59;
    if ( (float)((float)((float)(s_bm_current_air_resistance / v59) * v225) * 1.05) > v218 )
    {
      v218 = v60 * v225;
      v54 = v60 * v240;
      v47 = 0;
      v230 = v60 * 0.0;
      v231 = v60 * v219[0];
      v48 = v212 < 0.0;
      v221 = 10;
    }
  }
  v213 = (float)(*(float *)&v243 * v39) - (float)(v244 * v241);
  LODWORD(v219[0]) = LODWORD(v213) & _mask__AbsFloat_;
  v225 = COERCE_FLOAT(LODWORD(v213) & _mask__AbsFloat_)
       - (float)((float)((float)((float)(v249 * v238) + (float)(v239 * v236)) + (float)(v253 * v233))
               + (float)(v254 * v235));
  if ( v225 > 0.00000011920929 )
    return 0;
  v61 = fsqrt(
          (float)(v39 * v39)
        + (float)(COERCE_FLOAT(LODWORD(v241) ^ _mask__NegFloat_) * COERCE_FLOAT(LODWORD(v241) ^ _mask__NegFloat_)));
  LODWORD(v219[0]) = LODWORD(v241) ^ _mask__NegFloat_;
  if ( v61 > 0.00000011920929 )
  {
    v62 = s_bm_current_air_resistance / v61;
    if ( (float)((float)((float)(s_bm_current_air_resistance / v61) * v225) * 1.05) > v218 )
    {
      v54 = v62 * v39;
      v47 = 0;
      v218 = v62 * v225;
      v230 = v62 * 0.0;
      v231 = v62 * v219[0];
      v48 = v213 < 0.0;
      v221 = 11;
    }
  }
  v63 = COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(*(float *)&v243 * v242) - (float)(v244 * v220)) & _mask__AbsFloat_)
      - (float)((float)((float)((float)(v249 * v237) + (float)(v255 * v236)) + (float)(v251 * v233))
              + (float)(*(float *)&v224 * v235));
  if ( v63 > 0.00000011920929 )
    return 0;
  v64 = fsqrt(
          (float)(v242 * v242)
        + (float)(COERCE_FLOAT(LODWORD(v220) ^ _mask__NegFloat_) * COERCE_FLOAT(LODWORD(v220) ^ _mask__NegFloat_)));
  LODWORD(v219[0]) = LODWORD(v220) ^ _mask__NegFloat_;
  if ( v64 > 0.00000011920929 )
  {
    v65 = s_bm_current_air_resistance / v64;
    v66 = (float)(s_bm_current_air_resistance / v64) * v63;
    if ( (float)(v66 * 1.05) > v218 )
    {
      v54 = v65 * v242;
      v47 = 0;
      v218 = v66;
      v230 = v65 * 0.0;
      v231 = v65 * v219[0];
      v48 = (float)((float)(*(float *)&v243 * v242) - (float)(v244 * v220)) < 0.0;
      v221 = 12;
    }
  }
  v67 = COERCE_FLOAT(
          COERCE_UNSIGNED_INT((float)(*((float *)&v243 + 1) * v228) - (float)(*(float *)&v243 * *(float *)&v222))
        & _mask__AbsFloat_)
      - (float)((float)((float)((float)(v253 * v238) + (float)(v251 * v237)) + (float)(v249 * v233))
              + (float)(v250 * v234));
  if ( v67 > 0.00000011920929 )
    return 0;
  LODWORD(v219[0]) = v222 ^ _mask__NegFloat_;
  v68 = fsqrt((float)(v219[0] * v219[0]) + (float)(v228 * v228));
  if ( v68 > 0.00000011920929 )
  {
    v69 = s_bm_current_air_resistance / v68;
    v70 = (float)(s_bm_current_air_resistance / v68) * v67;
    if ( (float)(v70 * 1.05) > v218 )
    {
      v54 = v69 * v219[0];
      v47 = 0;
      v218 = v70;
      v230 = v69 * v228;
      v231 = v69 * 0.0;
      v48 = (float)((float)(*((float *)&v243 + 1) * v228) - (float)(*(float *)&v243 * *(float *)&v222)) < 0.0;
      v221 = 13;
    }
  }
  *(float *)&v222 = (float)(v241 * *((float *)&v243 + 1)) - (float)(*(float *)&v243 * v226);
  v71 = COERCE_FLOAT(v222 & _mask__AbsFloat_)
      - (float)((float)((float)((float)(v252 * v238) + (float)(v251 * v236)) + (float)(v255 * v233))
              + (float)(v254 * v234));
  if ( v71 > 0.00000011920929 )
    return 0;
  LODWORD(v219[0]) = LODWORD(v226) ^ _mask__NegFloat_;
  v72 = fsqrt((float)(v219[0] * v219[0]) + (float)(v241 * v241));
  if ( v72 > 0.00000011920929 )
  {
    v73 = s_bm_current_air_resistance / v72;
    v74 = (float)(s_bm_current_air_resistance / v72) * v71;
    if ( (float)(v74 * 1.05) > v218 )
    {
      v54 = v73 * v219[0];
      v47 = 0;
      v218 = v74;
      v230 = v73 * v241;
      v231 = v73 * 0.0;
      v48 = *(float *)&v222 < 0.0;
      v221 = 14;
    }
  }
  *(float *)&v222 = (float)(v220 * *((float *)&v243 + 1)) - (float)(*(float *)&v243 * v227);
  v75 = COERCE_FLOAT(v222 & _mask__AbsFloat_)
      - (float)((float)((float)((float)(v252 * v237) + (float)(v253 * v236)) + (float)(v239 * v233))
              + (float)(*(float *)&v224 * v234));
  if ( v75 > 0.00000011920929 )
    return 0;
  LODWORD(v76) = LODWORD(v227) ^ _mask__NegFloat_;
  v77 = fsqrt((float)(v76 * v76) + (float)(v220 * v220));
  v78 = v218;
  LODWORD(v219[0]) = LODWORD(v227) ^ _mask__NegFloat_;
  if ( v77 <= 0.00000011920929
    || (v79 = s_bm_current_air_resistance / v77, v80 = v79 * v75, (float)((float)(v79 * v75) * 1.05) <= v218) )
  {
    v81 = v230;
  }
  else
  {
    v81 = v79 * v220;
    v47 = 0;
    v78 = v80;
    v54 = v79 * v76;
    v231 = v79 * 0.0;
    v48 = *(float *)&v222 < 0.0;
    v221 = 15;
  }
  if ( !v221 )
    return 0;
  v82 = R1;
  if ( v47 )
  {
    normal->mVec128.m128_f32[0] = *v47;
    normal->mVec128.m128_f32[1] = v47[4];
    normal->mVec128.m128_f32[2] = v47[8];
  }
  else
  {
    normal->mVec128.m128_f32[0] = (float)((float)(v54 * v223) + (float)(R1[1] * v81)) + (float)(v231 * R1[2]);
    normal->mVec128.m128_f32[1] = (float)((float)(R1[6] * v231) + (float)(R1[5] * v81)) + (float)(v54 * R1[4]);
    normal->mVec128.m128_f32[2] = (float)((float)(R1[10] * v231) + (float)(R1[9] * v81)) + (float)(v54 * R1[8]);
  }
  if ( v48 )
  {
    normal->mVec128.m128_i32[0] ^= _mask__NegFloat_;
    normal->mVec128.m128_i32[1] ^= _mask__NegFloat_;
    normal->mVec128.m128_i32[2] ^= _mask__NegFloat_;
  }
  v83 = v221 <= 6;
  v214 = LODWORD(v78) ^ _mask__NegFloat_;
  *(_DWORD *)depth = LODWORD(v78) ^ _mask__NegFloat_;
  if ( v83 )
  {
    if ( v221 > 3 )
    {
      v118 = p2;
      v215 = R2;
      v119 = p1;
      *(float *)&v120 = COERCE_FLOAT(&v236);
      v121 = &v233;
    }
    else
    {
      v118 = p1;
      v215 = R1;
      v82 = R2;
      v119 = p2;
      *(float *)&v120 = COERCE_FLOAT(&v233);
      v121 = &v236;
    }
    v122 = normal->mVec128.m128_f32[0];
    v123 = normal->mVec128.m128_f32[1];
    v124 = normal->mVec128.m128_f32[2];
    v226 = *(float *)&v120;
    v227 = *(float *)&v118;
    if ( v221 > 3 )
    {
      LODWORD(v122) ^= _mask__NegFloat_;
      LODWORD(v123) ^= _mask__NegFloat_;
      LODWORD(v124) ^= _mask__NegFloat_;
    }
    *(float *)&v125 = (float)((float)(v82[8] * v124) + (float)(v82[4] * v123)) + (float)(v122 * *v82);
    *(float *)&v126 = (float)((float)(v82[9] * v124) + (float)(v82[5] * v123)) + (float)(v122 * v82[1]);
    v127 = v82[10] * v124;
    v231 = v124;
    v128 = v82[6];
    v229 = v122;
    v129 = v122 * v82[2];
    v256 = __PAIR64__(v126, v125);
    LODWORD(v130) = v125 & _mask__AbsFloat_;
    LODWORD(v131) = v126 & _mask__AbsFloat_;
    v257 = (float)(v127 + (float)(v128 * v123)) + v129;
    v230 = v123;
    LODWORD(v132) = LODWORD(v257) & _mask__AbsFloat_;
    if ( v131 <= v130 )
    {
      if ( v130 > v132 )
      {
        v133 = 0;
        LODWORD(v223) = 1;
        goto LABEL_103;
      }
      v223 = 0.0;
    }
    else
    {
      v223 = 0.0;
      if ( v131 > v132 )
      {
        v133 = 1;
LABEL_103:
        v222 = 2;
        goto LABEL_106;
      }
    }
    v133 = 2;
    v222 = 1;
LABEL_106:
    v134 = v133;
    v135 = v121[v134];
    LODWORD(v220) = (char *)v119 - (char *)v118;
    v136 = (float *)&v82[v134];
    if ( *(float *)((char *)&v256 + v134 * 4) >= 0.0 )
    {
      v138 = (char *)((char *)&v246 - (char *)v118);
      LODWORD(v219[0]) = 3;
      do
      {
        *(float *)&v138[(_DWORD)v118] = (float)(*(float *)((char *)v118->mVec128.m128_f32 + LODWORD(v220))
                                              - v118->mVec128.m128_f32[0])
                                      - (float)(*v136 * v135);
        v136 += 4;
        v118 = (const btVector3 *)((char *)v118 + 4);
        --LODWORD(v219[0]);
      }
      while ( LODWORD(v219[0]) );
    }
    else
    {
      v137 = (char *)((char *)&v246 - (char *)v118);
      LODWORD(v219[0]) = 3;
      do
      {
        *(float *)((char *)v118->mVec128.m128_f32 + (_DWORD)v137) = (float)(*(float *)((char *)v118->mVec128.m128_f32
                                                                                     + LODWORD(v220))
                                                                          - v118->mVec128.m128_f32[0])
                                                                  + (float)(v135 * *v136);
        v136 += 4;
        v118 = (const btVector3 *)((char *)v118 + 4);
        --LODWORD(v219[0]);
      }
      while ( LODWORD(v219[0]) );
    }
    if ( v221 > 3 )
      v139 = v221 - 4;
    else
      v139 = v221 - 1;
    v242 = *(float *)&v139;
    if ( *(float *)&v139 == 0.0 )
    {
      v140 = 1;
      v141 = 2;
    }
    else
    {
      v141 = 1;
      if ( v139 == 1 )
        v141 = 2;
      v140 = 0;
    }
    LODWORD(v240) = 4 * v140;
    v142 = (float *)&v215[v140];
    v143 = v142[8];
    v144 = (float)((float)(v142[4] * v247) + (float)(v143 * v248)) + (float)(*v142 * v246);
    v145 = 4 * v141;
    v146 = (float *)((char *)v215 + v145);
    v147 = *(const float *)((char *)v215 + v145 + 32);
    v148 = (float)((float)(*(const float *)((char *)v215 + v145 + 16) * v247) + (float)(v147 * v248))
         + (float)(*(const float *)((char *)v215 + v145) * v246);
    v149 = v142[4];
    v150 = v147;
    v220 = *(float *)&v145;
    LODWORD(v219[0]) = 4 * LODWORD(v223);
    v151 = (float *)&v82[LODWORD(v223)];
    v152 = (float *)&v82[v222];
    *(float *)&v153 = (float)((float)(v143 * v152[8]) + (float)(v142[4] * v152[4])) + (float)(*v142 * *v152);
    v154 = (float)((float)(v147 * v151[8]) + (float)(v146[4] * v151[4])) + (float)(*v146 * *v151);
    v155 = (float)((float)(v150 * v152[8]) + (float)(v146[4] * v152[4])) + (float)(*v146 * *v152);
    v216 = (float)((float)(v143 * v151[8]) + (float)(v149 * v151[4])) + (float)(*v142 * *v151);
    v156 = v121[LODWORD(v223)] * v216;
    v157 = v121[v222];
    v158 = v121[LODWORD(v223)] * v154;
    v228 = v154;
    v223 = v155;
    v159 = v157 * v155;
    v241 = v144;
    v239 = v148;
    v222 = v153;
    v219[0] = v157 * *(float *)&v153;
    v160 = v226;
    v257 = (float)(v144 - v156) + (float)(v157 * *(float *)&v153);
    v161 = (float)(v157 * *(float *)&v153) + v156;
    v261 = (float)(v156 + v144) - v219[0];
    v162 = (float)(v144 - v156) - v219[0];
    v219[0] = *(float *)(LODWORD(v226) + LODWORD(v240));
    v163 = *(float *)(LODWORD(v226) + LODWORD(v220));
    *(float *)&v256 = v162;
    v259 = v161 + v144;
    *((float *)&v256 + 1) = (float)(v148 - v158) - v159;
    v258 = (float)(v148 - v158) + v159;
    v260 = (float)(v159 + v158) + v148;
    v262 = (float)(v158 + v148) - v159;
    v219[1] = v163;
    v240 = COERCE_FLOAT(intersectRectQuad2(v219, v264));
    if ( SLODWORD(v240) >= 1 )
    {
      v164 = s_bm_current_air_resistance / (float)((float)(v223 * v216) - (float)(v228 * *(float *)&v222));
      v165 = 0;
      v166 = v164 * v216;
      v167 = v164 * *(float *)&v222;
      v168 = v164 * v228;
      v223 = v164 * v223;
      *(float *)&v224 = 0.0;
      v220 = 0.0;
      v169 = COERCE_FLOAT(v266);
      v228 = *(float *)(LODWORD(v160) + 4 * LODWORD(v242));
      v226 = COERCE_FLOAT(v266);
      do
      {
        v170 = 2 * v165;
        v171 = v264[v170];
        v172 = &v264[v170 + 1];
        v173 = *v172 - v239;
        v174 = (float)(v223 * (float)(v171 - v241)) - (float)(v173 * v167);
        v175 = (float)(v173 * v166) - (float)(v168 * (float)(v171 - v241));
        v176 = 0;
        *(float *)&v222 = v169;
        v217 = v151;
        LODWORD(v219[0]) = v152;
        do
        {
          v177 = v219[0];
          LODWORD(v219[0]) += 16;
          v178 = v175 * *(float *)LODWORD(v177);
          v179 = v217;
          v180 = v178 + *(&v246 + v176);
          v217 += 4;
          v181 = v174 * *v179;
          v182 = (float *)v222;
          v222 += 4;
          ++v176;
          *v182 = v180 + v181;
        }
        while ( v176 < 3 );
        v169 = v226;
        v183 = v224;
        v184 = v228
             - (float)((float)((float)(*(float *)(LODWORD(v226) + 8) * v231) + (float)(v229 * *(float *)LODWORD(v226)))
                     + (float)(*(float *)(LODWORD(v226) + 4) * v230));
        v263[v224] = v184;
        if ( v184 >= 0.0 )
        {
          v169 = *(float *)&v222;
          v264[2 * v183] = v171;
          v264[2 * v183++ + 1] = *v172;
          v224 = v183;
          v226 = v169;
        }
        v165 = ++LODWORD(v220);
      }
      while ( SLODWORD(v220) < SLODWORD(v240) );
      v185 = 1;
      if ( v183 >= 1 )
      {
        if ( v183 > 4 )
        {
          v195 = v263[0];
          v196 = 0;
          do
          {
            if ( v263[v185] > v195 )
            {
              v195 = v263[v185];
              v196 = v185;
            }
            ++v185;
          }
          while ( v185 < v183 );
          cullPoints2(v264, v183, 4, v196, v265);
          v220 = 0.0;
          do
          {
            v197 = v265[LODWORD(v220)];
            v198 = 0;
            v199 = (float *)&v266[3 * v197];
            do
            {
              *(&v246 + v198) = *(float *)(LODWORD(v227) + 4 * v198) + *v199;
              ++v198;
              ++v199;
            }
            while ( v198 < 3 );
            v200 = normal->mVec128.m128_f32[0];
            if ( v221 >= 4 )
            {
              v202 = normal->mVec128.m128_f32[1];
              v203 = normal->mVec128.m128_f32[2];
              v204 = &v263[v197];
              v205 = *v204;
              v206 = *maxc;
              v207 = v246 - (float)(*v204 * v200);
              v230 = v247 - (float)(*v204 * v202);
              LODWORD(v243) = LODWORD(v200) ^ _mask__NegFloat_;
              v208 = *(_DWORD *)v204 ^ _mask__NegFloat_;
              v231 = v248 - (float)(v205 * v203);
              v229 = v207;
              v232 = 0;
              HIDWORD(v243) = LODWORD(v202) ^ _mask__NegFloat_;
              LODWORD(v244) = LODWORD(v203) ^ _mask__NegFloat_;
              v245 = 0.0;
              (*(void (__thiscall **)(int *, unsigned __int64 *, float *, int))(v206 + 12))(maxc, &v243, &v229, v208);
            }
            else
            {
              v201 = *maxc;
              LODWORD(v256) = LODWORD(v200) ^ _mask__NegFloat_;
              HIDWORD(v256) = normal->mVec128.m128_i32[1] ^ _mask__NegFloat_;
              LODWORD(v257) = normal->mVec128.m128_i32[2] ^ _mask__NegFloat_;
              v258 = 0.0;
              (*(void (__thiscall **)(int *, unsigned __int64 *, float *, _DWORD))(v201 + 12))(
                maxc,
                &v256,
                &v246,
                LODWORD(v263[v197]) ^ _mask__NegFloat_);
            }
            ++LODWORD(v220);
          }
          while ( SLODWORD(v220) < 4 );
          v224 = 4;
        }
        else
        {
          v186 = 0;
          if ( v221 >= 4 )
          {
            LODWORD(v219[0]) = LODWORD(v227) - (_DWORD)normal;
            v190 = (float *)v266;
            LODWORD(v223) = (char *)&v246 - (char *)normal;
            do
            {
              v191 = v263[v186];
              v192 = normal;
              v193 = 3;
              do
              {
                *(float *)((char *)v192->mVec128.m128_f32 + LODWORD(v223)) = (float)(*(float *)((char *)v192->mVec128.m128_f32
                                                                                              + LODWORD(v219[0]))
                                                                                   + *v190++)
                                                                           - (float)(v191 * v192->mVec128.m128_f32[0]);
                v192 = (btVector3 *)((char *)v192 + 4);
                --v193;
              }
              while ( v193 );
              v194 = *maxc;
              LODWORD(v256) = normal->mVec128.m128_i32[0] ^ _mask__NegFloat_;
              HIDWORD(v256) = normal->mVec128.m128_i32[1] ^ _mask__NegFloat_;
              LODWORD(v257) = normal->mVec128.m128_i32[2] ^ _mask__NegFloat_;
              v258 = 0.0;
              (*(void (__stdcall **)(unsigned __int64 *, float *, _DWORD))(v194 + 12))(
                &v256,
                &v246,
                LODWORD(v191) ^ _mask__NegFloat_);
              ++v186;
            }
            while ( v186 < v224 );
          }
          else
          {
            v187 = (float *)v266;
            do
            {
              for ( i = 0; i < 3; ++i )
                *(&v246 + i) = *(float *)(LODWORD(v227) + 4 * i) + *v187++;
              v189 = *maxc;
              LODWORD(v256) = normal->mVec128.m128_i32[0] ^ _mask__NegFloat_;
              HIDWORD(v256) = normal->mVec128.m128_i32[1] ^ _mask__NegFloat_;
              LODWORD(v257) = normal->mVec128.m128_i32[2] ^ _mask__NegFloat_;
              v258 = 0.0;
              (*(void (__stdcall **)(unsigned __int64 *, float *, _DWORD))(v189 + 12))(
                &v256,
                &v246,
                LODWORD(v263[v186++]) ^ _mask__NegFloat_);
            }
            while ( v186 < v224 );
          }
        }
        result = v224;
        goto LABEL_92;
      }
    }
    return 0;
  }
  v84 = R1;
  v85 = normal->mVec128.m128_f32[2];
  v86 = normal->mVec128.m128_f32[1];
  v87 = normal->mVec128.m128_f32[0];
  v256 = p1->mVec128.m128_u64[0];
  v257 = p1->mVec128.m128_f32[2];
  v227 = v85;
  *(float *)&v222 = v86;
  v223 = v87;
  LODWORD(v219[0]) = 3;
  do
  {
    if ( (float)((float)((float)(v84[8] * v85) + (float)(v86 * v84[4])) + (float)(v87 * *v84)) <= 0.0 )
      v88 = FLOAT_N1_0;
    else
      v88 = s_bm_current_air_resistance;
    v89 = *(const float *)((char *)v84 + (char *)&v233 - (char *)R1);
    v90 = 0;
    v91 = (float *)v84;
    do
    {
      *((float *)&v256 + v90) = (float)((float)(v89 * *v91) * v88) + *((float *)&v256 + v90);
      ++v90;
      v91 += 4;
    }
    while ( v90 < 3 );
    ++v84;
    --LODWORD(v219[0]);
  }
  while ( LODWORD(v219[0]) );
  v243 = p2->mVec128.m128_u64[0];
  v244 = p2->mVec128.m128_f32[2];
  v92 = R2;
  LODWORD(v219[0]) = 3;
  do
  {
    if ( (float)((float)((float)(v92[8] * v85) + (float)(v92[4] * v86)) + (float)(*v92 * v87)) <= 0.0 )
      v93 = s_bm_current_air_resistance;
    else
      v93 = FLOAT_N1_0;
    v94 = *(const float *)((char *)v92 + (char *)&v236 - (char *)R2);
    v95 = 0;
    v96 = (float *)v92;
    do
    {
      v97 = (float *)&v243 + v95++;
      v98 = (float)((float)(v94 * *v96) * v93) + *v97;
      v96 += 4;
      *v97 = v98;
    }
    while ( v95 < 3 );
    ++v92;
    --LODWORD(v219[0]);
  }
  while ( LODWORD(v219[0]) );
  v99 = 0;
  v100 = (v221 - 7) % 3;
  v101 = (float *)&R1[(v221 - 7) / 3];
  do
  {
    ++v99;
    *(&v245 + v99) = *v101;
    v101 += 4;
  }
  while ( v99 < 3 );
  v102 = 0;
  v103 = (float *)&R2[v100];
  do
  {
    ++v102;
    *(&v228 + v102) = *v103;
    v103 += 4;
  }
  while ( v102 < 3 );
  v104 = (float)((float)(v247 * v230) + (float)(v248 * v231)) + (float)(v229 * v246);
  v105 = (float)((float)(v248 * (float)(v244 - v257))
               + (float)(v247 * (float)(*((float *)&v243 + 1) - *((float *)&v256 + 1))))
       + (float)(v246 * (float)(*(float *)&v243 - *(float *)&v256));
  v106 = s_bm_current_air_resistance - (float)(v104 * v104);
  LODWORD(v107) = COERCE_UNSIGNED_INT(
                    (float)((float)(v231 * (float)(v244 - v257))
                          + (float)(v230 * (float)(*((float *)&v243 + 1) - *((float *)&v256 + 1))))
                  + (float)(v229 * (float)(*(float *)&v243 - *(float *)&v256)))
                ^ _mask__NegFloat_;
  if ( v106 > 0.000099999997 )
  {
    v110 = s_bm_current_air_resistance / v106;
    v108 = (float)((float)(v104 * v107) + v105) * (float)(s_bm_current_air_resistance / v106);
    v109 = (float)((float)(v104 * v105) + v107) * v110;
  }
  else
  {
    v108 = 0.0;
    v109 = 0.0;
  }
  for ( j = 0; j < 12; j += 4 )
  {
    v112 = *(float *)((char *)&v246 + j);
    v113 = (float *)((char *)&v256 + j);
    *v113 = (float)(v112 * v108) + *v113;
  }
  for ( k = 0; k < 12; k += 4 )
  {
    v115 = *(float *)((char *)&v229 + k);
    v116 = (float *)((char *)&v243 + k);
    *v116 = (float)(v115 * v109) + *v116;
  }
  v117 = *maxc;
  LODWORD(v256) = LODWORD(v223) ^ _mask__NegFloat_;
  HIDWORD(v256) = v222 ^ _mask__NegFloat_;
  LODWORD(v257) = LODWORD(v227) ^ _mask__NegFloat_;
  v258 = 0.0;
  (*(void (__stdcall **)(unsigned __int64 *, unsigned __int64 *, _DWORD))(v117 + 12))(
    &v256,
    &v243,
    v214 ^ _mask__NegFloat_);
  result = 1;
LABEL_92:
  *return_code = v221;
  return result;
}
