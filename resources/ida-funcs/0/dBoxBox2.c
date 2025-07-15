int __fastcall dBoxBox2(
        const btVector3 *side2,
        const btVector3 *side1,
        const btVector3 *p1,
        float *R1,
        const btVector3 *p2,
        float *R2,
        btVector3 *normal,
        float *depth,
        int *return_code,
        btDiscreteCollisionDetectorInterface::Result *maxc)
{
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm6_4
  float v16; // xmm7_4
  float v17; // xmm3_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm3_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm3_4
  float v26; // xmm1_4
  double v27; // st7
  float v28; // xmm4_4
  float v29; // xmm0_4
  float v30; // xmm4_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  long double v36; // st7
  long double v37; // st7
  long double v38; // st7
  long double v39; // st7
  long double v40; // st7
  float v41; // xmm0_4
  long double v42; // st6
  int result; // eax
  float v44; // xmm1_4
  BOOL v45; // ebx
  long double v46; // st7
  long double v47; // st7
  float v48; // xmm0_4
  long double v49; // st7
  long double v50; // st7
  float v51; // xmm0_4
  long double v52; // st7
  long double v53; // st7
  float v54; // xmm0_4
  long double v55; // st7
  long double v56; // st7
  float v57; // xmm0_4
  long double v58; // st7
  long double v59; // st7
  float v60; // xmm0_4
  long double v61; // st7
  long double v62; // st7
  float v63; // xmm0_4
  long double v64; // st7
  long double v65; // st7
  float v66; // xmm0_4
  long double v67; // st7
  long double v68; // st7
  float v69; // xmm0_4
  long double v70; // st7
  long double v71; // st7
  float v72; // xmm3_4
  float v73; // xmm0_4
  float v74; // xmm2_4
  float v75; // xmm1_4
  float v76; // xmm0_4
  int v77; // edx
  float *v78; // ecx
  btVector3 *v79; // eax
  const float *v80; // esi
  float v81; // xmm5_4
  float v82; // xmm6_4
  int v83; // ecx
  float *v84; // eax
  float v85; // xmm2_4
  float v86; // xmm3_4
  float v87; // xmm1_4
  float v88; // xmm0_4
  float v89; // xmm7_4
  float v90; // xmm7_4
  float v91; // xmm4_4
  int v92; // xmm0_4
  float v93; // xmm6_4
  float v94; // xmm5_4
  int v95; // eax
  const float *v96; // ecx
  float v97; // xmm0_4
  float v98; // xmm2_4
  float v99; // xmm1_4
  float v100; // xmm4_4
  float v101; // xmm3_4
  float v102; // xmm2_4
  float v103; // xmm1_4
  int v104; // eax
  int v105; // edx
  btDiscreteCollisionDetectorInterface::Result_vtbl *v106; // edx
  void (__thiscall *addContactPoint)(btDiscreteCollisionDetectorInterface::Result *, const btVector3 *, const btVector3 *, float); // edx
  const float *v108; // edi
  btVector3 *v109; // ecx
  int v110; // ebx
  int v111; // eax
  float v112; // xmm2_4
  float v113; // xmm0_4
  float v114; // xmm1_4
  float v115; // xmm4_4
  float v116; // eax
  int v117; // ecx
  int v118; // eax
  float v119; // xmm2_4
  float v120; // xmm3_4
  float v121; // xmm4_4
  float v122; // xmm5_4
  float v123; // xmm6_4
  float v124; // xmm0_4
  float v125; // xmm1_4
  float v126; // xmm6_4
  float v127; // xmm4_4
  float v128; // xmm5_4
  float v129; // xmm0_4
  float v130; // ecx
  float v131; // xmm0_4
  int v132; // edi
  float v133; // xmm7_4
  float v134; // xmm5_4
  float v135; // xmm6_4
  int v136; // ecx
  float *v137; // edx
  float *v138; // ecx
  float v139; // xmm3_4
  float v140; // xmm4_4
  float v141; // xmm0_4
  float v142; // xmm1_4
  float v143; // xmm0_4
  int v144; // ebx
  float *v145; // esi
  float v146; // xmm1_4
  void (__thiscall *v147)(btDiscreteCollisionDetectorInterface::Result *, const btVector3 *, const btVector3 *, float); // eax
  float *v148; // ebx
  float v149; // xmm0_4
  float v150; // xmm2_4
  float v151; // xmm0_4
  void (__thiscall *v152)(btDiscreteCollisionDetectorInterface::Result *, const btVector3 *, const btVector3 *, float); // edx
  float v153; // xmm0_4
  int v154; // ecx
  int v155; // eax
  int i; // ebx
  int v157; // ecx
  float v158; // xmm7_4
  float v159; // xmm0_4
  btDiscreteCollisionDetectorInterface::Result_vtbl *v160; // edx
  float v161; // xmm3_4
  float v162; // xmm0_4
  float v163; // xmm1_4
  float v164; // xmm2_4
  float v165; // xmm4_4
  float _X; // [esp+4A18h] [ebp-1B4h]
  float v167; // [esp+4A2Ch] [ebp-1A0h]
  float v168; // [esp+4A30h] [ebp-19Ch]
  float v169; // [esp+4A30h] [ebp-19Ch]
  float v170; // [esp+4A30h] [ebp-19Ch]
  float v171; // [esp+4A30h] [ebp-19Ch]
  float v172; // [esp+4A30h] [ebp-19Ch]
  float v173; // [esp+4A30h] [ebp-19Ch]
  float v174; // [esp+4A30h] [ebp-19Ch]
  float v175; // [esp+4A30h] [ebp-19Ch]
  float v176; // [esp+4A30h] [ebp-19Ch]
  float v177; // [esp+4A30h] [ebp-19Ch]
  float v178; // [esp+4A30h] [ebp-19Ch]
  float v179; // [esp+4A30h] [ebp-19Ch]
  float v180; // [esp+4A30h] [ebp-19Ch]
  float v181; // [esp+4A30h] [ebp-19Ch]
  float v182; // [esp+4A30h] [ebp-19Ch]
  BOOL v183; // [esp+4A34h] [ebp-198h]
  float v184; // [esp+4A34h] [ebp-198h]
  float v185; // [esp+4A34h] [ebp-198h]
  float v186; // [esp+4A34h] [ebp-198h]
  float v187; // [esp+4A34h] [ebp-198h]
  float v188; // [esp+4A34h] [ebp-198h]
  float v189; // [esp+4A34h] [ebp-198h]
  float v190; // [esp+4A34h] [ebp-198h]
  float v191; // [esp+4A34h] [ebp-198h]
  float v192; // [esp+4A34h] [ebp-198h]
  float v193; // [esp+4A38h] [ebp-194h]
  float v194; // [esp+4A38h] [ebp-194h]
  float v195; // [esp+4A38h] [ebp-194h]
  float v196; // [esp+4A38h] [ebp-194h]
  float v197; // [esp+4A38h] [ebp-194h]
  float v198; // [esp+4A38h] [ebp-194h]
  float v199; // [esp+4A38h] [ebp-194h]
  float v200; // [esp+4A38h] [ebp-194h]
  float v201; // [esp+4A38h] [ebp-194h]
  float v202; // [esp+4A38h] [ebp-194h]
  float v203; // [esp+4A38h] [ebp-194h]
  float v204; // [esp+4A38h] [ebp-194h]
  float v205; // [esp+4A3Ch] [ebp-190h]
  float v206; // [esp+4A3Ch] [ebp-190h]
  int v207; // [esp+4A3Ch] [ebp-190h]
  float v208; // [esp+4A3Ch] [ebp-190h]
  int v209; // [esp+4A3Ch] [ebp-190h]
  int v210; // [esp+4A40h] [ebp-18Ch]
  float v211; // [esp+4A44h] [ebp-188h]
  float v212; // [esp+4A44h] [ebp-188h]
  const btVector3 *v213; // [esp+4A44h] [ebp-188h]
  float v214; // [esp+4A48h] [ebp-184h]
  float v215; // [esp+4A48h] [ebp-184h]
  btVector3 *v216; // [esp+4A48h] [ebp-184h]
  float v217; // [esp+4A48h] [ebp-184h]
  btVector3 v218; // [esp+4A4Ch] [ebp-180h] BYREF
  float *v219; // [esp+4A64h] [ebp-168h]
  float v220; // [esp+4A68h] [ebp-164h]
  btVector3 v221; // [esp+4A6Ch] [ebp-160h] BYREF
  float v222; // [esp+4A80h] [ebp-14Ch] BYREF
  float v223; // [esp+4A84h] [ebp-148h]
  float v224; // [esp+4A88h] [ebp-144h]
  btVector3 v225; // [esp+4A8Ch] [ebp-140h] BYREF
  float v226; // [esp+4AA0h] [ebp-12Ch]
  float v227; // [esp+4AA4h] [ebp-128h]
  float v228; // [esp+4AA8h] [ebp-124h]
  int v229; // [esp+4AACh] [ebp-120h]
  float v230; // [esp+4AB0h] [ebp-11Ch]
  float v231; // [esp+4AB4h] [ebp-118h]
  float v232; // [esp+4AB8h] [ebp-114h]
  float v233; // [esp+4ABCh] [ebp-110h]
  float v234; // [esp+4AC0h] [ebp-10Ch]
  float v235; // [esp+4AC4h] [ebp-108h]
  float v236; // [esp+4AC8h] [ebp-104h] BYREF
  float v237; // [esp+4ACCh] [ebp-100h]
  float v238; // [esp+4AD0h] [ebp-FCh]
  float v239; // [esp+4AD4h] [ebp-F8h]
  float v240; // [esp+4AD8h] [ebp-F4h]
  btVector3 v241; // [esp+4ADCh] [ebp-F0h] BYREF
  float h; // [esp+4AECh] [ebp-E0h] BYREF
  float v243; // [esp+4AF0h] [ebp-DCh]
  float v244; // [esp+4AF4h] [ebp-D8h]
  float p; // [esp+4B0Ch] [ebp-C0h] BYREF
  float v246; // [esp+4B10h] [ebp-BCh]
  float v247; // [esp+4B14h] [ebp-B8h]
  float v248[5]; // [esp+4B18h] [ebp-B4h]
  float v249[17]; // [esp+4B2Ch] [ebp-A0h] BYREF
  _DWORD v250[23]; // [esp+4B70h] [ebp-5Ch] BYREF

  v10 = p2->mVec128.m128_f32[1] - p1->mVec128.m128_f32[1];
  v11 = p2->mVec128.m128_f32[2] - p1->mVec128.m128_f32[2];
  memset(&v221, 0, 12);
  v12 = p2->mVec128.m128_f32[0] - p1->mVec128.m128_f32[0];
  v13 = R1[4];
  v14 = R1[8];
  v15 = *R1;
  v16 = R1[5] * v10;
  v218.mVec128.m128_f32[0] = (float)((float)(v11 * v14) + (float)(v10 * v13)) + (float)(v12 * *R1);
  v17 = (float)((float)(R1[9] * v11) + v16) + (float)(v12 * R1[1]);
  v243 = v10;
  v218.mVec128.m128_f32[1] = v17;
  v18 = R1[10] * v11;
  v244 = v11;
  v19 = R1[6] * v10;
  v20 = side1->mVec128.m128_f32[0];
  h = v12;
  v21 = v18 + v19;
  v22 = R2[4];
  v23 = v21 + (float)(v12 * R1[2]);
  v225.mVec128.m128_f32[0] = v20 * 0.5;
  v225.mVec128.m128_f32[1] = side1->mVec128.m128_f32[1] * 0.5;
  v225.mVec128.m128_f32[2] = side1->mVec128.m128_f32[2] * 0.5;
  v222 = side2->mVec128.m128_f32[0] * 0.5;
  v223 = side2->mVec128.m128_f32[1] * 0.5;
  v24 = side2->mVec128.m128_f32[2] * 0.5;
  v218.mVec128.m128_f32[2] = v23;
  v25 = *R2;
  v224 = v24;
  v26 = R2[8];
  v219 = 0;
  v236 = v15;
  v27 = R2[9] * v14 + R2[5] * v13;
  v228 = (float)((float)(v25 * v15) + (float)(v26 * v14)) + (float)(v22 * v13);
  v214 = v27 + R2[1] * v15;
  v211 = (float)((float)(R2[10] * v14) + (float)(R2[6] * v13)) + (float)(R2[2] * v15);
  v28 = R1[5] * R2[5];
  v227 = (float)((float)(R1[5] * v22) + (float)(R1[9] * v26)) + (float)(v25 * R1[1]);
  v29 = (float)((float)(R1[9] * R2[9]) + v28) + (float)(R2[1] * R1[1]);
  v30 = R1[5] * R2[6];
  v220 = v29;
  v205 = (float)((float)(R1[9] * R2[10]) + v30) + (float)(R1[1] * R2[2]);
  v31 = R1[6] * v22;
  v32 = R1[10] * v26;
  v33 = R1[6] * R2[5];
  v237 = (float)(v31 + v32) + (float)(R1[2] * v25);
  v34 = (float)((float)(R1[10] * R2[9]) + v33) + (float)(R1[2] * R2[1]);
  v35 = R1[6] * R2[6];
  v239 = v34;
  v226 = (float)((float)(R1[10] * R2[10]) + v35) + (float)(R1[2] * R2[2]);
  v235 = fabsf(v228);
  v238 = fabsf(v214);
  v230 = fabsf(v211);
  v233 = fabsf(v227);
  v234 = fabsf(v220);
  *(float *)&v229 = fabsf(v205);
  v231 = fabsf(v237);
  v232 = fabsf(v34);
  v240 = fabsf(v226);
  v167 = -3.4028235e38;
  v183 = 0;
  v210 = 0;
  v36 = fabsf(v218.mVec128.m128_f32[0]) - (v230 * v224 + v238 * v223 + v235 * v222 + v225.mVec128.m128_f32[0]);
  if ( v36 > 0.0 )
    return 0;
  v168 = v36;
  if ( v168 > -3.4028235e38 )
  {
    v167 = v36;
    v219 = R1;
    v183 = v218.mVec128.m128_f32[0] < 0.0;
    v210 = 1;
  }
  v37 = fabsf(v218.mVec128.m128_f32[1])
      - (*(float *)&v229 * v224
       + v234 * v223
       + v233 * v222
       + v225.mVec128.m128_f32[1]);
  if ( v37 > 0.0 )
    return 0;
  v169 = v37;
  if ( v169 > v167 )
  {
    v167 = v37;
    v219 = R1 + 1;
    v183 = v218.mVec128.m128_f32[1] < 0.0;
    v210 = 2;
  }
  v38 = fabsf(v218.mVec128.m128_f32[2]) - (v240 * v224 + v232 * v223 + v231 * v222 + v225.mVec128.m128_f32[2]);
  if ( v38 > 0.0 )
    return 0;
  v170 = v38;
  if ( v170 > v167 )
  {
    v167 = v38;
    v219 = R1 + 2;
    v183 = v218.mVec128.m128_f32[2] < 0.0;
    v210 = 3;
  }
  v193 = v244 * R2[8] + v243 * R2[4] + h * v25;
  v39 = fabsf(v193)
      - (v231 * v225.mVec128.m128_f32[2]
       + v233 * v225.mVec128.m128_f32[1]
       + v235 * v225.mVec128.m128_f32[0]
       + v222);
  if ( v39 > 0.0 )
    return 0;
  v171 = v39;
  if ( v171 > v167 )
  {
    v167 = v39;
    v219 = R2;
    v183 = v193 < 0.0;
    v210 = 4;
  }
  v40 = fabsf((float)((float)(R2[9] * v244) + (float)(R2[5] * v243)) + (float)(R2[1] * h))
      - (v232 * v225.mVec128.m128_f32[2]
       + v234 * v225.mVec128.m128_f32[1]
       + v238 * v225.mVec128.m128_f32[0]
       + v223);
  if ( v40 > 0.0 )
    return 0;
  v172 = v40;
  if ( v172 > v167 )
  {
    v167 = v40;
    v41 = (float)((float)(R2[9] * v244) + (float)(R2[5] * v243)) + (float)(h * R2[1]);
    v219 = R2 + 1;
    v183 = v41 < 0.0;
    v210 = 5;
  }
  v42 = fabsf((float)((float)(R2[10] * v244) + (float)(R2[6] * v243)) + (float)(h * R2[2]))
      - (v240 * v225.mVec128.m128_f32[2]
       + *(float *)&v229 * v225.mVec128.m128_f32[1]
       + v225.mVec128.m128_f32[0] * v230
       + v224);
  if ( v42 > 0.0 )
    return 0;
  v173 = v42;
  if ( v173 <= v167 )
  {
    v45 = v183;
  }
  else
  {
    v167 = v42;
    v44 = (float)((float)(R2[10] * v244) + (float)(R2[6] * v243)) + (float)(h * R2[2]);
    v219 = R2 + 2;
    v45 = v44 < 0.0;
    v210 = 6;
  }
  v235 = v235 + 0.0000099999997;
  v238 = v238 + 0.0000099999997;
  v234 = v234 + 0.0000099999997;
  *(float *)&v229 = *(float *)&v229 + 0.0000099999997;
  v230 = v230 + 0.0000099999997;
  v232 = v232 + 0.0000099999997;
  v233 = v233 + 0.0000099999997;
  v240 = v240 + 0.0000099999997;
  v231 = v231 + 0.0000099999997;
  h = v218.mVec128.m128_f32[2] * v227 - v218.mVec128.m128_f32[1] * v237;
  v46 = fabsf(h) - (v238 * v224 + v230 * v223 + v231 * v225.mVec128.m128_f32[1] + v233 * v225.mVec128.m128_f32[2]);
  v174 = v46;
  if ( v46 > 0.00000011920929 )
    return 0;
  v47 = sqrtf((float)((float)-v237 * (float)-v237) + (float)(v227 * v227));
  v184 = v47;
  if ( v47 > 0.00000011920929 )
  {
    v48 = *(float *)&clear_value / v184;
    if ( (float)((float)((float)(*(float *)&clear_value / v184) * v174) * 1.05) > v167 )
    {
      v167 = (float)(*(float *)&clear_value / v184) * v174;
      v221.mVec128.m128_f32[0] = v48 * 0.0;
      v219 = 0;
      v221.mVec128.m128_f32[1] = v48 * (float)-v237;
      v221.mVec128.m128_f32[2] = v48 * v227;
      v45 = h < 0.0;
      v210 = 7;
    }
  }
  v194 = v218.mVec128.m128_f32[2] * v220 - v218.mVec128.m128_f32[1] * v239;
  v49 = fabsf(v194) - (v235 * v224 + v230 * v222 + v232 * v225.mVec128.m128_f32[1] + v234 * v225.mVec128.m128_f32[2]);
  v175 = v49;
  if ( v49 > 0.00000011920929 )
    return 0;
  h = -v239;
  v50 = sqrtf((float)((float)-v239 * (float)-v239) + (float)(v220 * v220));
  v185 = v50;
  if ( v50 > 0.00000011920929 )
  {
    v51 = *(float *)&clear_value / v185;
    if ( (float)((float)((float)(*(float *)&clear_value / v185) * v175) * 1.05) > v167 )
    {
      v167 = (float)(*(float *)&clear_value / v185) * v175;
      v221.mVec128.m128_f32[0] = v51 * 0.0;
      v219 = 0;
      v221.mVec128.m128_f32[1] = h * v51;
      v221.mVec128.m128_f32[2] = v51 * v220;
      v45 = v194 < 0.0;
      v210 = 8;
    }
  }
  v195 = v218.mVec128.m128_f32[2] * v205 - v218.mVec128.m128_f32[1] * v226;
  v52 = fabsf(v195)
      - (v240 * v225.mVec128.m128_f32[1]
       + v235 * v223
       + *(float *)&v229 * v225.mVec128.m128_f32[2]
       + v238 * v222);
  v176 = v52;
  if ( v52 > 0.00000011920929 )
    return 0;
  h = -v226;
  v53 = sqrtf((float)((float)-v226 * (float)-v226) + (float)(v205 * v205));
  v186 = v53;
  if ( v53 > 0.00000011920929 )
  {
    v54 = *(float *)&clear_value / v186;
    if ( (float)((float)((float)(*(float *)&clear_value / v186) * v176) * 1.05) > v167 )
    {
      v167 = (float)(*(float *)&clear_value / v186) * v176;
      v221.mVec128.m128_f32[0] = v54 * 0.0;
      v219 = 0;
      v221.mVec128.m128_f32[1] = h * v54;
      v221.mVec128.m128_f32[2] = v54 * v205;
      v45 = v195 < 0.0;
      v210 = 9;
    }
  }
  v196 = v218.mVec128.m128_f32[0] * v237 - v218.mVec128.m128_f32[2] * v228;
  v55 = fabsf(v196)
      - (v234 * v224
       + *(float *)&v229 * v223
       + v231 * v225.mVec128.m128_f32[0]
       + v235 * v225.mVec128.m128_f32[2]);
  v177 = v55;
  if ( v55 > 0.00000011920929 )
    return 0;
  h = -v228;
  v56 = sqrtf((float)((float)-v228 * (float)-v228) + (float)(v237 * v237));
  v187 = v56;
  if ( v56 > 0.00000011920929 )
  {
    v57 = *(float *)&clear_value / v187;
    if ( (float)((float)((float)(*(float *)&clear_value / v187) * v177) * 1.05) > v167 )
    {
      v167 = (float)(*(float *)&clear_value / v187) * v177;
      v221.mVec128.m128_f32[0] = v57 * v237;
      v221.mVec128.m128_f32[1] = v57 * 0.0;
      v219 = 0;
      v221.mVec128.m128_f32[2] = h * v57;
      v45 = v196 < 0.0;
      v210 = 10;
    }
  }
  v197 = v218.mVec128.m128_f32[0] * v239 - v218.mVec128.m128_f32[2] * v214;
  v58 = fabsf(v197)
      - (v233 * v224
       + *(float *)&v229 * v222
       + v232 * v225.mVec128.m128_f32[0]
       + v238 * v225.mVec128.m128_f32[2]);
  v178 = v58;
  if ( v58 > 0.00000011920929 )
    return 0;
  h = -v214;
  v59 = sqrtf((float)((float)-v214 * (float)-v214) + (float)(v239 * v239));
  v188 = v59;
  if ( v59 > 0.00000011920929 )
  {
    v60 = *(float *)&clear_value / v188;
    if ( (float)((float)((float)(*(float *)&clear_value / v188) * v178) * 1.05) > v167 )
    {
      v167 = (float)(*(float *)&clear_value / v188) * v178;
      v221.mVec128.m128_f32[0] = v60 * v239;
      v221.mVec128.m128_f32[1] = v60 * 0.0;
      v219 = 0;
      v221.mVec128.m128_f32[2] = h * v60;
      v45 = v197 < 0.0;
      v210 = 11;
    }
  }
  v198 = v218.mVec128.m128_f32[0] * v226 - v218.mVec128.m128_f32[2] * v211;
  v61 = fabsf(v198) - (v233 * v223 + v234 * v222 + v240 * v225.mVec128.m128_f32[0] + v230 * v225.mVec128.m128_f32[2]);
  v179 = v61;
  if ( v61 > 0.00000011920929 )
    return 0;
  h = -v211;
  v62 = sqrtf((float)((float)-v211 * (float)-v211) + (float)(v226 * v226));
  v189 = v62;
  if ( v62 > 0.00000011920929 )
  {
    v63 = *(float *)&clear_value / v189;
    if ( (float)((float)((float)(*(float *)&clear_value / v189) * v179) * 1.05) > v167 )
    {
      v167 = (float)(*(float *)&clear_value / v189) * v179;
      v221.mVec128.m128_f32[0] = v63 * v226;
      v221.mVec128.m128_f32[1] = v63 * 0.0;
      v219 = 0;
      v221.mVec128.m128_f32[2] = h * v63;
      v45 = v198 < 0.0;
      v210 = 12;
    }
  }
  v199 = v218.mVec128.m128_f32[1] * v228 - v218.mVec128.m128_f32[0] * v227;
  v64 = fabsf(v199) - (v232 * v224 + v240 * v223 + v233 * v225.mVec128.m128_f32[0] + v235 * v225.mVec128.m128_f32[1]);
  v180 = v64;
  if ( v64 > 0.00000011920929 )
    return 0;
  h = -v227;
  v65 = sqrtf((float)((float)-v227 * (float)-v227) + (float)(v228 * v228));
  v190 = v65;
  if ( v65 > 0.00000011920929 )
  {
    v66 = *(float *)&clear_value / v190;
    if ( (float)((float)((float)(*(float *)&clear_value / v190) * v180) * 1.05) > v167 )
    {
      v167 = (float)(*(float *)&clear_value / v190) * v180;
      v221.mVec128.m128_f32[0] = h * v66;
      v221.mVec128.m128_f32[1] = v66 * v228;
      v219 = 0;
      v221.mVec128.m128_f32[2] = v66 * 0.0;
      v45 = v199 < 0.0;
      v210 = 13;
    }
  }
  v200 = v218.mVec128.m128_f32[1] * v214 - v218.mVec128.m128_f32[0] * v220;
  v67 = fabsf(v200) - (v231 * v224 + v240 * v222 + v234 * v225.mVec128.m128_f32[0] + v238 * v225.mVec128.m128_f32[1]);
  v181 = v67;
  if ( v67 > 0.00000011920929 )
    return 0;
  h = -v220;
  v68 = sqrtf((float)((float)-v220 * (float)-v220) + (float)(v214 * v214));
  v191 = v68;
  if ( v68 > 0.00000011920929 )
  {
    v69 = *(float *)&clear_value / v191;
    if ( (float)((float)((float)(*(float *)&clear_value / v191) * v181) * 1.05) > v167 )
    {
      v167 = (float)(*(float *)&clear_value / v191) * v181;
      v221.mVec128.m128_f32[0] = h * v69;
      v221.mVec128.m128_f32[1] = v69 * v214;
      v219 = 0;
      v221.mVec128.m128_f32[2] = v69 * 0.0;
      v45 = v200 < 0.0;
      v210 = 14;
    }
  }
  v201 = v218.mVec128.m128_f32[1] * v211 - v218.mVec128.m128_f32[0] * v205;
  v70 = fabsf(v201)
      - (v231 * v223
       + v232 * v222
       + *(float *)&v229 * v225.mVec128.m128_f32[0]
       + v230 * v225.mVec128.m128_f32[1]);
  v182 = v70;
  if ( v70 > 0.00000011920929 )
    return 0;
  h = -v205;
  v71 = sqrtf((float)(v211 * v211) + (float)(h * h));
  v192 = v71;
  v72 = v167;
  if ( v71 <= 0.00000011920929
    || (v73 = *(float *)&clear_value / v192,
        (float)((float)((float)(*(float *)&clear_value / v192) * v182) * 1.05) <= v167) )
  {
    v77 = v210;
    if ( !v210 )
      return 0;
    v78 = v219;
    if ( v219 )
    {
      v79 = normal;
      v80 = R1;
      normal->mVec128.m128_f32[0] = *v219;
      normal->mVec128.m128_f32[1] = v78[4];
      normal->mVec128.m128_f32[2] = v78[8];
      goto LABEL_62;
    }
    v76 = v221.mVec128.m128_f32[2];
    v75 = v221.mVec128.m128_f32[1];
    v74 = v221.mVec128.m128_f32[0];
  }
  else
  {
    v72 = (float)(*(float *)&clear_value / v192) * v182;
    v74 = h * v73;
    v75 = v73 * v211;
    v76 = v73 * 0.0;
    v210 = 15;
    v77 = 15;
    v45 = v201 < 0.0;
  }
  v79 = normal;
  v80 = R1;
  normal->mVec128.m128_f32[0] = (float)((float)(v76 * R1[2]) + (float)(v75 * R1[1])) + (float)(v74 * v236);
  normal->mVec128.m128_f32[1] = (float)((float)(R1[6] * v76) + (float)(R1[5] * v75)) + (float)(v74 * R1[4]);
  normal->mVec128.m128_f32[2] = (float)((float)(R1[10] * v76) + (float)(R1[9] * v75)) + (float)(R1[8] * v74);
LABEL_62:
  if ( v45 )
  {
    v79->mVec128.m128_f32[0] = -v79->mVec128.m128_f32[0];
    v79->mVec128.m128_f32[1] = -v79->mVec128.m128_f32[1];
    v79->mVec128.m128_f32[2] = -v79->mVec128.m128_f32[2];
  }
  v202 = -v72;
  *depth = -v72;
  if ( v77 > 6 )
  {
    v81 = p1->mVec128.m128_f32[0];
    v82 = p1->mVec128.m128_f32[1];
    v241.mVec128.m128_i32[2] = p1->mVec128.m128_i32[2];
    v215 = v79->mVec128.m128_f32[2];
    v206 = v79->mVec128.m128_f32[1];
    v83 = 0;
    v212 = v79->mVec128.m128_f32[0];
    v84 = (float *)(v80 + 4);
    do
    {
      v85 = v84[4];
      v86 = *v84;
      if ( (float)((float)((float)(v85 * v215) + (float)(*(v84 - 4) * v212)) + (float)(v206 * *v84)) <= 0.0 )
        v87 = -1.0;
      else
        v87 = *(float *)&clear_value;
      v88 = v225.mVec128.m128_f32[v83];
      v89 = v88 * *(v84 - 4);
      ++v83;
      ++v84;
      v90 = (float)(v89 * v87) + v81;
      v91 = (float)((float)(v88 * v86) * v87) + v82;
      v81 = v90;
      v82 = v91;
      v241.mVec128.m128_f32[2] = (float)((float)(v88 * v85) * v87) + v241.mVec128.m128_f32[2];
    }
    while ( v83 < 3 );
    v92 = p2->mVec128.m128_i32[2];
    v93 = p2->mVec128.m128_f32[1];
    v241.mVec128.m128_u64[0] = __PAIR64__(LODWORD(v91), LODWORD(v90));
    v94 = p2->mVec128.m128_f32[0];
    v95 = 0;
    v218.mVec128.m128_i32[2] = v92;
    v96 = R2 + 4;
    do
    {
      v97 = v96[4];
      v98 = *(v96 - 4);
      v99 = *v96;
      if ( (float)((float)((float)(v97 * v215) + (float)(v98 * v212)) + (float)(*v96 * v206)) <= 0.0 )
        v100 = *(float *)&clear_value;
      else
        v100 = -1.0;
      v101 = *(&v222 + v95++);
      ++v96;
      v102 = (float)((float)(v98 * v101) * v100) + v94;
      v103 = (float)((float)(v99 * v101) * v100) + v93;
      v94 = v102;
      v93 = v103;
      v218.mVec128.m128_f32[2] = (float)((float)(v97 * v101) * v100) + v218.mVec128.m128_f32[2];
    }
    while ( v95 < 3 );
    v104 = (v210 - 7) / 3;
    v105 = (v210 - 7) % 3;
    v218.mVec128.m128_u64[0] = __PAIR64__(LODWORD(v103), LODWORD(v102));
    v225.mVec128.m128_f32[0] = R1[v104];
    v225.mVec128.m128_f32[1] = R1[v104 + 4];
    v225.mVec128.m128_f32[2] = R1[v104 + 8];
    v221.mVec128.m128_f32[0] = R2[v105];
    v221.mVec128.m128_f32[1] = R2[v105 + 4];
    v221.mVec128.m128_f32[2] = R2[v105 + 8];
    dLineClosestApproach(&v241, &v218, &v221, &h, &v225, &v236);
    v106 = maxc->__vftable;
    v218.mVec128.m128_f32[0] = (float)(v221.mVec128.m128_f32[0] * h) + v218.mVec128.m128_f32[0];
    addContactPoint = v106->addContactPoint;
    v218.mVec128.m128_f32[1] = (float)(v221.mVec128.m128_f32[1] * h) + v218.mVec128.m128_f32[1];
    v218.mVec128.m128_f32[2] = (float)(v221.mVec128.m128_f32[2] * h) + v218.mVec128.m128_f32[2];
    v241.mVec128.m128_f32[0] = -v212;
    v241.mVec128.m128_i32[1] = LODWORD(v206) ^ 0x80000000;
    v241.mVec128.m128_u64[1] = LODWORD(v215) ^ 0x80000000LL;
    ((void (__thiscall *)(btDiscreteCollisionDetectorInterface::Result *, btVector3 *, btVector3 *, _DWORD))addContactPoint)(
      maxc,
      &v241,
      &v218,
      -v202);
    *return_code = v210;
    return 1;
  }
  if ( v77 > 3 )
  {
    v108 = R2;
    v213 = p2;
    v220 = *(float *)&p1;
    v228 = COERCE_FLOAT(&v222);
    v109 = &v225;
  }
  else
  {
    v213 = p1;
    v220 = *(float *)&p2;
    v108 = v80;
    v80 = R2;
    v228 = COERCE_FLOAT(&v225);
    v109 = (btVector3 *)&v222;
  }
  v216 = v109;
  if ( v77 > 3 )
  {
    v218.mVec128.m128_f32[0] = -v79->mVec128.m128_f32[0];
    v218.mVec128.m128_f32[1] = -v79->mVec128.m128_f32[1];
    v218.mVec128.m128_f32[2] = -v79->mVec128.m128_f32[2];
  }
  else
  {
    v218.mVec128.m128_u64[0] = v79->mVec128.m128_u64[0];
    v218.mVec128.m128_i32[2] = v79->mVec128.m128_i32[2];
  }
  v241.mVec128.m128_f32[0] = v80[4] * v218.mVec128.m128_f32[1]
                           + v80[8] * v218.mVec128.m128_f32[2]
                           + v218.mVec128.m128_f32[0] * *v80;
  v241.mVec128.m128_f32[1] = v80[9] * v218.mVec128.m128_f32[2]
                           + v80[5] * v218.mVec128.m128_f32[1]
                           + v218.mVec128.m128_f32[0] * v80[1];
  v241.mVec128.m128_f32[2] = v218.mVec128.m128_f32[1] * v80[6]
                           + v218.mVec128.m128_f32[2] * v80[10]
                           + v218.mVec128.m128_f32[0] * v80[2];
  v221.mVec128.m128_f32[0] = fabsf(v241.mVec128.m128_f32[0]);
  v221.mVec128.m128_f32[1] = fabsf(v241.mVec128.m128_f32[1]);
  v221.mVec128.m128_f32[2] = fabsf(v241.mVec128.m128_f32[2]);
  if ( v221.mVec128.m128_f32[1] <= (double)v221.mVec128.m128_f32[0] )
  {
    if ( v221.mVec128.m128_f32[0] > v221.mVec128.m128_f32[2] )
    {
      v111 = 0;
      v110 = 1;
      v207 = 2;
      goto LABEL_89;
    }
    v110 = 0;
  }
  else
  {
    v110 = 0;
    if ( v221.mVec128.m128_f32[1] > v221.mVec128.m128_f32[2] )
    {
      v111 = 1;
      v207 = 2;
      goto LABEL_89;
    }
  }
  v111 = 2;
  v207 = 1;
LABEL_89:
  v112 = v216->mVec128.m128_f32[v111];
  if ( v241.mVec128.m128_f32[v111] >= 0.0 )
  {
    v113 = (float)(*(float *)LODWORD(v220) - v213->mVec128.m128_f32[0]) - (float)(v80[v111] * v112);
    v114 = (float)(*(float *)(LODWORD(v220) + 4) - v213->mVec128.m128_f32[1]) - (float)(v80[v111 + 4] * v112);
    v115 = (float)(*(float *)(LODWORD(v220) + 8) - v213->mVec128.m128_f32[2]) - (float)(v80[v111 + 8] * v112);
  }
  else
  {
    v113 = (float)(v80[v111] * v112) + (float)(*(float *)LODWORD(v220) - v213->mVec128.m128_f32[0]);
    v114 = (float)(v80[v111 + 4] * v112) + (float)(*(float *)(LODWORD(v220) + 4) - v213->mVec128.m128_f32[1]);
    v115 = (float)(v80[v111 + 8] * v112) + (float)(*(float *)(LODWORD(v220) + 8) - v213->mVec128.m128_f32[2]);
  }
  *(unsigned __int64 *)((char *)v221.mVec128.m128_u64 + 4) = __PAIR64__(LODWORD(v115), LODWORD(v114));
  v221.mVec128.m128_f32[0] = v113;
  if ( v210 > 3 )
    LODWORD(v116) = v210 - 4;
  else
    LODWORD(v116) = v210 - 1;
  v236 = v116;
  v117 = 2;
  if ( v116 == 0.0 )
  {
    v118 = 1;
  }
  else
  {
    if ( LODWORD(v116) != 1 )
      v117 = 1;
    v118 = 0;
  }
  v119 = (float)((float)(v108[v118 + 4] * v114) + (float)(v108[v118 + 8] * v115)) + (float)(v113 * v108[v118]);
  v120 = (float)((float)(v108[v117 + 4] * v114) + (float)(v108[v117 + 8] * v115)) + (float)(v113 * v108[v117]);
  v121 = (float)((float)(v108[v118 + 8] * v80[v207 + 8]) + (float)(v108[v118 + 4] * v80[v207 + 4]))
       + (float)(v108[v118] * v80[v207]);
  v122 = (float)((float)(v108[v117 + 8] * v80[v207 + 8]) + (float)(v108[v117 + 4] * v80[v207 + 4]))
       + (float)(v108[v117] * v80[v207]);
  v123 = v216->mVec128.m128_f32[v110];
  v203 = (float)((float)(v108[v118 + 8] * v80[v110 + 8]) + (float)(v108[v118 + 4] * v80[v110 + 4]))
       + (float)(v108[v118] * v80[v110]);
  v124 = v203 * v123;
  v220 = (float)((float)(v108[v117 + 8] * v80[v110 + 8]) + (float)(v108[v117 + 4] * v80[v110 + 4]))
       + (float)(v108[v117] * v80[v110]);
  v125 = v220 * v123;
  v126 = v216->mVec128.m128_f32[v207];
  v226 = v121;
  v127 = v121 * v126;
  v227 = v122;
  v128 = v122 * v126;
  p = (float)(v119 - v124) - v127;
  h = v120 - v125;
  v246 = (float)(v120 - v125) - v128;
  v248[0] = v128 + (float)(v120 - v125);
  v239 = v119;
  v237 = v120;
  v247 = v127 + (float)(v119 - v124);
  v248[1] = (float)(v127 + v124) + v119;
  v248[3] = (float)(v124 + v119) - v127;
  h = *(float *)(LODWORD(v228) + 4 * v118);
  v129 = *(float *)(LODWORD(v228) + 4 * v117);
  v248[2] = (float)(v128 + v125) + v120;
  v248[4] = (float)(v125 + v120) - v128;
  v243 = v129;
  v130 = COERCE_FLOAT(intersectRectQuad2(&p, &h, v249));
  result = 0;
  *(float *)&v229 = v130;
  if ( SLODWORD(v130) >= 1 )
  {
    v131 = *(float *)&clear_value / (float)((float)(v227 * v203) - (float)(v220 * v226));
    v132 = 0;
    v133 = v131 * v220;
    v134 = v131 * v203;
    v135 = v131 * v226;
    v220 = v131 * v220;
    v227 = v131 * v227;
    v136 = v207;
    v204 = v80[v207];
    h = v80[v110];
    v217 = v80[v207 + 4];
    v208 = v80[v110 + 4];
    v230 = v80[v136 + 8];
    v226 = v80[v110 + 8];
    v137 = (float *)v250;
    v236 = *(float *)(LODWORD(v228) + 4 * LODWORD(v236));
    v138 = (float *)v250;
    while ( 1 )
    {
      v139 = v249[2 * result + 1] - v237;
      v140 = v249[2 * result];
      v141 = (float)((float)(v140 - v239) * v227) - (float)(v135 * v139);
      v142 = (float)(v134 * v139) - (float)((float)(v140 - v239) * v133);
      *(v138 - 1) = (float)((float)(v141 * h) + (float)(v142 * v204)) + v221.mVec128.m128_f32[0];
      v138[1] = (float)((float)(v141 * v226) + (float)(v142 * v230)) + v221.mVec128.m128_f32[2];
      *v138 = (float)((float)(v141 * v208) + (float)(v142 * v217)) + v221.mVec128.m128_f32[1];
      v143 = v236
           - (float)((float)((float)(v137[1] * v218.mVec128.m128_f32[2])
                           + (float)(*(v137 - 1) * v218.mVec128.m128_f32[0]))
                   + (float)(v218.mVec128.m128_f32[1] * *v137));
      *(&p + v132) = v143;
      if ( v143 >= 0.0 )
      {
        v249[2 * v132] = v140;
        v249[2 * v132++ + 1] = v249[2 * result + 1];
        v138 += 3;
        v137 += 3;
      }
      if ( ++result >= v229 )
        break;
      v133 = v220;
    }
    if ( v132 >= 1 )
    {
      if ( v132 > 4 )
      {
        v153 = p;
        v154 = 0;
        v155 = 1;
        if ( v132 - 1 >= 4 )
        {
          do
          {
            if ( *(&p + v155) > v153 )
            {
              v153 = *(&p + v155);
              v154 = v155;
            }
            if ( *(&v246 + v155) > v153 )
            {
              v153 = *(&v246 + v155);
              v154 = v155 + 1;
            }
            if ( v248[v155 - 1] > v153 )
            {
              v153 = v248[v155 - 1];
              v154 = v155 + 2;
            }
            if ( v248[v155] > v153 )
            {
              v153 = v248[v155];
              v154 = v155 + 3;
            }
            v155 += 4;
          }
          while ( v155 < v132 - 3 );
        }
        for ( ; v155 < v132; ++v155 )
        {
          if ( *(&p + v155) > v153 )
          {
            v153 = *(&p + v155);
            v154 = v155;
          }
        }
        cullPoints2(v249, v132, 4, v154, (int *)&h);
        for ( i = 0; i < 4; ++i )
        {
          v157 = *((_DWORD *)&h + i);
          v158 = v249[3 * v157 + 16] + v213->mVec128.m128_f32[0];
          v241.mVec128.m128_f32[1] = *(float *)&v250[3 * v157] + v213->mVec128.m128_f32[1];
          v159 = *(float *)&v250[3 * v157 + 1] + v213->mVec128.m128_f32[2];
          v160 = maxc->__vftable;
          v241.mVec128.m128_f32[0] = v158;
          v241.mVec128.m128_f32[2] = v159;
          if ( v210 >= 4 )
          {
            v161 = *(&p + v157);
            v162 = normal->mVec128.m128_f32[0];
            v163 = normal->mVec128.m128_f32[1];
            v164 = normal->mVec128.m128_f32[2];
            v165 = normal->mVec128.m128_f32[0] * v161;
            v221.mVec128.m128_f32[1] = v241.mVec128.m128_f32[1] - (float)(v163 * v161);
            v221.mVec128.m128_f32[2] = v241.mVec128.m128_f32[2] - (float)(v164 * v161);
            v225.mVec128.m128_f32[0] = -v162;
            _X = -*(&p + v157);
            v221.mVec128.m128_f32[0] = v158 - v165;
            v221.mVec128.m128_i32[3] = 0;
            v225.mVec128.m128_f32[1] = -v163;
            v225.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(-v164);
            ((void (__thiscall *)(btDiscreteCollisionDetectorInterface::Result *, btVector3 *, btVector3 *, _DWORD))v160->addContactPoint)(
              maxc,
              &v225,
              &v221,
              LODWORD(_X));
          }
          else
          {
            v218.mVec128.m128_f32[0] = -normal->mVec128.m128_f32[0];
            v218.mVec128.m128_f32[1] = -normal->mVec128.m128_f32[1];
            v218.mVec128.m128_f32[2] = -normal->mVec128.m128_f32[2];
            v218.mVec128.m128_i32[3] = 0;
            ((void (__thiscall *)(btDiscreteCollisionDetectorInterface::Result *, btVector3 *, btVector3 *, _DWORD))v160->addContactPoint)(
              maxc,
              &v218,
              &v241,
              -*(&p + v157));
          }
        }
        *return_code = v210;
        return 4;
      }
      else if ( v210 >= 4 )
      {
        v209 = 0;
        v148 = (float *)v250;
        do
        {
          v149 = *(&p + v209);
          v218.mVec128.m128_f32[0] = (float)(*(v148 - 1) + v213->mVec128.m128_f32[0])
                                   - (float)(normal->mVec128.m128_f32[0] * v149);
          v150 = v149 * normal->mVec128.m128_f32[1];
          v151 = v149 * normal->mVec128.m128_f32[2];
          v218.mVec128.m128_f32[1] = (float)(*v148 + v213->mVec128.m128_f32[1]) - v150;
          v152 = maxc->addContactPoint;
          v218.mVec128.m128_f32[2] = (float)(v148[1] + v213->mVec128.m128_f32[2]) - v151;
          v241.mVec128.m128_f32[0] = -normal->mVec128.m128_f32[0];
          v241.mVec128.m128_f32[1] = -normal->mVec128.m128_f32[1];
          v241.mVec128.m128_f32[2] = -normal->mVec128.m128_f32[2];
          v241.mVec128.m128_i32[3] = 0;
          ((void (__stdcall *)(btVector3 *, btVector3 *, _DWORD))v152)(&v241, &v218, -*(&p + v209));
          v148 += 3;
          ++v209;
        }
        while ( v209 < v132 );
        *return_code = v210;
        return v132;
      }
      else
      {
        v144 = 0;
        v145 = (float *)v250;
        do
        {
          v218.mVec128.m128_f32[0] = *(v145 - 1) + v213->mVec128.m128_f32[0];
          v218.mVec128.m128_f32[1] = v213->mVec128.m128_f32[1] + *v145;
          v146 = normal->mVec128.m128_f32[0];
          v218.mVec128.m128_f32[2] = v145[1] + v213->mVec128.m128_f32[2];
          v241.mVec128.m128_f32[0] = -v146;
          v241.mVec128.m128_f32[1] = -normal->mVec128.m128_f32[1];
          v147 = maxc->addContactPoint;
          v241.mVec128.m128_f32[2] = -normal->mVec128.m128_f32[2];
          v241.mVec128.m128_i32[3] = 0;
          ((void (__stdcall *)(btVector3 *, btVector3 *, _DWORD))v147)(&v241, &v218, -*(&p + v144++));
          v145 += 3;
        }
        while ( v144 < v132 );
        *return_code = v210;
        return v132;
      }
    }
    return 0;
  }
  return result;
}
