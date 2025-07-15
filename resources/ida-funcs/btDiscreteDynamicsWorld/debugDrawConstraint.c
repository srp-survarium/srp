void __thiscall btDiscreteDynamicsWorld::debugDrawConstraint(
        btDiscreteDynamicsWorld *this,
        btTypedConstraint *constraint,
        int a3)
{
  int v3; // eax
  int v4; // eax
  __int16 v5; // ax
  btMatrix3x3 *v6; // ecx
  float v7; // xmm1_4
  int v8; // eax
  int v9; // eax
  double v10; // st7
  double v11; // st7
  btTypedConstraint_vtbl *v12; // eax
  int v13; // eax
  float v14; // xmm1_4
  __m128 v15; // xmm0
  __m128i v16; // xmm0
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  float v26; // xmm4_4
  float v27; // xmm1_4
  btTypedConstraint_vtbl *v28; // eax
  float v29; // xmm3_4
  float v30; // xmm5_4
  float v31; // xmm4_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  int v34; // eax
  btTypedConstraint_vtbl *v35; // eax
  int v36; // eax
  btTypedConstraint_vtbl *v37; // eax
  int v38; // eax
  float *v39; // eax
  float v40; // xmm5_4
  float v41; // xmm2_4
  float v42; // xmm4_4
  float v43; // xmm1_4
  float v44; // xmm3_4
  float v45; // xmm7_4
  float v46; // xmm6_4
  float v47; // xmm5_4
  float v48; // xmm6_4
  float v49; // xmm5_4
  float v50; // xmm7_4
  float v51; // xmm7_4
  float v52; // xmm4_4
  float v53; // xmm5_4
  unsigned int v54; // xmm7_4
  float v55; // xmm4_4
  float v56; // xmm6_4
  float v57; // xmm0_4
  float v58; // xmm7_4
  float v59; // xmm6_4
  float v60; // xmm5_4
  float v61; // xmm6_4
  float v62; // xmm5_4
  float v63; // xmm7_4
  float v64; // xmm6_4
  float v65; // xmm7_4
  float v66; // xmm6_4
  float v67; // xmm5_4
  float v68; // xmm6_4
  float v69; // xmm5_4
  float v70; // xmm7_4
  float v71; // xmm6_4
  float v72; // xmm5_4
  int v73; // xmm6_4
  float v74; // xmm7_4
  float v75; // xmm6_4
  float v76; // xmm5_4
  float v77; // xmm7_4
  float v78; // xmm4_4
  float v79; // xmm1_4
  int v80; // eax
  float *v81; // eax
  float v82; // xmm5_4
  float v83; // xmm3_4
  float v84; // xmm2_4
  float v85; // xmm4_4
  float v86; // xmm1_4
  float v87; // xmm0_4
  float v88; // xmm7_4
  float v89; // xmm6_4
  float v90; // xmm3_4
  float v91; // xmm7_4
  float v92; // xmm6_4
  float v93; // xmm5_4
  float v94; // xmm4_4
  float v95; // xmm6_4
  float v96; // xmm5_4
  float v97; // xmm6_4
  float v98; // xmm3_4
  float v99; // xmm6_4
  float v100; // xmm7_4
  float v101; // xmm5_4
  float v102; // xmm6_4
  float v103; // xmm7_4
  float v104; // xmm6_4
  float v105; // xmm5_4
  float v106; // xmm7_4
  float v107; // xmm6_4
  float v108; // xmm7_4
  float v109; // xmm6_4
  float v110; // xmm5_4
  float v111; // xmm7_4
  float v112; // xmm6_4
  float v113; // xmm5_4
  float v114; // xmm6_4
  float v115; // xmm7_4
  float v116; // xmm5_4
  float v117; // xmm7_4
  float v118; // xmm5_4
  float v119; // xmm6_4
  float v120; // xmm7_4
  float v121; // xmm4_4
  float v122; // xmm6_4
  float v123; // xmm0_4
  btConeTwistConstraint *v124; // ecx
  int v125; // eax
  btConeTwistConstraint *v126; // ecx
  int v127; // eax
  int v128; // eax
  float *v129; // eax
  float v130; // xmm4_4
  float v131; // xmm2_4
  float v132; // xmm0_4
  float v133; // xmm1_4
  float v134; // xmm5_4
  float v135; // xmm7_4
  float v136; // xmm7_4
  float v137; // xmm6_4
  float v138; // xmm4_4
  float v139; // xmm7_4
  float v140; // xmm6_4
  float v141; // xmm5_4
  float v142; // xmm7_4
  float v143; // xmm6_4
  unsigned int v144; // xmm7_4
  float v145; // xmm4_4
  float v146; // xmm3_4
  float v147; // xmm6_4
  float v148; // xmm7_4
  float v149; // xmm6_4
  float v150; // xmm5_4
  float v151; // xmm7_4
  float v152; // xmm6_4
  float v153; // xmm5_4
  float v154; // xmm7_4
  float v155; // xmm6_4
  float v156; // xmm6_4
  float v157; // xmm5_4
  float v158; // xmm6_4
  int v159; // eax
  float v160; // xmm2_4
  float v161; // xmm1_4
  float v162; // xmm0_4
  float v163; // xmm5_4
  float v164; // xmm4_4
  float v165; // xmm6_4
  float v166; // xmm7_4
  float v167; // xmm5_4
  float v168; // xmm4_4
  float v169; // xmm1_4
  float v170; // xmm0_4
  float v171; // xmm2_4
  float v172; // xmm4_4
  float v173; // xmm1_4
  unsigned int v174; // xmm4_4
  float v175; // xmm0_4
  float v176; // xmm4_4
  float v177; // xmm3_4
  float v178; // xmm1_4
  float v179; // xmm2_4
  float v180; // xmm7_4
  float v181; // xmm1_4
  float v182; // xmm6_4
  float v183; // xmm2_4
  float v184; // xmm7_4
  float v185; // xmm6_4
  float v186; // xmm7_4
  float v187; // xmm6_4
  float v188; // xmm7_4
  float v189; // xmm6_4
  float v190; // xmm7_4
  btTypedConstraint_vtbl *v191; // eax
  int v192; // eax
  float *v193; // eax
  float v194; // xmm2_4
  float v195; // xmm3_4
  float v196; // xmm1_4
  float v197; // xmm5_4
  float v198; // xmm4_4
  float v199; // xmm6_4
  float v200; // xmm6_4
  float v201; // xmm7_4
  float v202; // xmm5_4
  float v203; // xmm4_4
  float v204; // xmm1_4
  float v205; // xmm3_4
  unsigned int v206; // xmm4_4
  float v207; // xmm2_4
  float v208; // xmm0_4
  float v209; // xmm1_4
  float v210; // xmm4_4
  float v211; // xmm6_4
  float v212; // xmm2_4
  float v213; // xmm0_4
  float v214; // xmm2_4
  float v215; // xmm1_4
  float v216; // xmm4_4
  float v217; // xmm1_4
  float v218; // xmm4_4
  float v219; // xmm7_4
  float v220; // xmm6_4
  float v221; // xmm1_4
  float v222; // xmm7_4
  float v223; // xmm6_4
  float v224; // xmm7_4
  float v225; // xmm6_4
  float v226; // xmm5_4
  float v227; // xmm7_4
  float v228; // xmm6_4
  float v229; // xmm7_4
  float v230; // xmm6_4
  float v231; // xmm5_4
  float v232; // xmm6_4
  int v233; // eax
  int v234; // eax
  float v235; // xmm2_4
  float v236; // xmm1_4
  float v237; // xmm0_4
  float v238; // xmm4_4
  float v239; // xmm3_4
  float v240; // xmm6_4
  float v241; // xmm5_4
  float v242; // xmm6_4
  float v243; // xmm7_4
  float v244; // xmm4_4
  float v245; // xmm3_4
  float v246; // xmm1_4
  float v247; // xmm0_4
  float v248; // xmm2_4
  float v249; // xmm3_4
  float v250; // xmm1_4
  unsigned int v251; // xmm3_4
  float v252; // xmm6_4
  float v253; // xmm3_4
  float v254; // xmm0_4
  float v255; // xmm1_4
  float v256; // xmm6_4
  float v257; // xmm5_4
  float v258; // xmm1_4
  float v259; // xmm2_4
  float v260; // xmm7_4
  float v261; // xmm6_4
  float v262; // xmm7_4
  float v263; // xmm6_4
  float v264; // xmm5_4
  float v265; // xmm6_4
  float v266; // xmm7_4
  float v267; // xmm6_4
  float v268; // xmm7_4
  float v269; // xmm0_4
  float v270; // xmm6_4
  float v271; // xmm2_4
  btAngularLimit *v272; // ecx
  int v273; // eax
  btAngularLimit *v274; // ecx
  float *v275; // eax
  float v276; // xmm2_4
  float v277; // xmm1_4
  float v278; // xmm3_4
  float v279; // xmm1_4
  float v280; // xmm2_4
  float v281; // xmm3_4
  unsigned int v282; // xmm2_4
  btTypedConstraint_vtbl *v283; // eax
  int v284; // eax
  float *v285; // ebx
  float v286; // xmm1_4
  float v287; // xmm0_4
  float v288; // xmm2_4
  float v289; // xmm0_4
  unsigned int v290; // xmm1_4
  float v291; // xmm2_4
  int v292; // eax
  long double v293; // [esp+54h] [ebp-200h]
  long double v294; // [esp+54h] [ebp-200h]
  int v295; // [esp+54h] [ebp-200h]
  const float *v296; // [esp+54h] [ebp-200h]
  float v297; // [esp+54h] [ebp-200h]
  const float *v298; // [esp+54h] [ebp-200h]
  int v299; // [esp+54h] [ebp-200h]
  const float *v300; // [esp+54h] [ebp-200h]
  int v301; // [esp+58h] [ebp-1FCh]
  bool v302; // [esp+6Fh] [ebp-1E5h]
  int v303; // [esp+70h] [ebp-1E4h] BYREF
  btMatrix3x3 fAngleInRadians; // [esp+74h] [ebp-1E0h] BYREF
  float v305; // [esp+ACh] [ebp-1A8h] BYREF
  btMatrix3x3 v306; // [esp+B0h] [ebp-1A4h] BYREF
  float v307; // [esp+E0h] [ebp-174h]
  float v308; // [esp+E4h] [ebp-170h]
  float v309; // [esp+E8h] [ebp-16Ch]
  float v310; // [esp+ECh] [ebp-168h]
  int v311; // [esp+F0h] [ebp-164h]
  btVector3 v312; // [esp+F4h] [ebp-160h] BYREF
  unsigned int v313; // [esp+108h] [ebp-14Ch]
  float v314; // [esp+10Ch] [ebp-148h] BYREF
  float v315; // [esp+110h] [ebp-144h] BYREF
  float v316; // [esp+114h] [ebp-140h] BYREF
  float v317; // [esp+118h] [ebp-13Ch] BYREF
  float v318; // [esp+11Ch] [ebp-138h] BYREF
  float v319; // [esp+120h] [ebp-134h] BYREF
  _BYTE v320[12]; // [esp+124h] [ebp-130h] BYREF
  int v321; // [esp+130h] [ebp-124h]
  int v322; // [esp+134h] [ebp-120h] BYREF
  int v323; // [esp+138h] [ebp-11Ch]
  float v324; // [esp+13Ch] [ebp-118h]
  int v325; // [esp+140h] [ebp-114h]
  int v326; // [esp+144h] [ebp-110h]
  int v327; // [esp+148h] [ebp-10Ch] BYREF
  float v328; // [esp+14Ch] [ebp-108h]
  int v329; // [esp+150h] [ebp-104h]
  unsigned __int64 v330; // [esp+154h] [ebp-100h] BYREF
  int v331; // [esp+15Ch] [ebp-F8h]
  btVector3 v332; // [esp+160h] [ebp-F4h]
  float v333; // [esp+170h] [ebp-E4h]
  float v334; // [esp+174h] [ebp-E0h]
  float v335; // [esp+178h] [ebp-DCh]
  float v336; // [esp+17Ch] [ebp-D8h]
  int v337; // [esp+180h] [ebp-D4h]
  int v338; // [esp+184h] [ebp-D0h]
  int v339; // [esp+188h] [ebp-CCh]
  int v340; // [esp+18Ch] [ebp-C8h]
  int v341; // [esp+190h] [ebp-C4h]
  int v342; // [esp+1B0h] [ebp-A4h]
  int v343; // [esp+1B4h] [ebp-A0h]
  int v344; // [esp+1B8h] [ebp-9Ch]
  int v345; // [esp+1BCh] [ebp-98h]
  int v346; // [esp+1C8h] [ebp-8Ch]
  int v347; // [esp+1CCh] [ebp-88h]
  int v348; // [esp+1D0h] [ebp-84h]
  int v349; // [esp+1D4h] [ebp-80h] BYREF
  int v350; // [esp+1D8h] [ebp-7Ch]
  int v351; // [esp+1DCh] [ebp-78h]
  int v352; // [esp+1E0h] [ebp-74h]
  _DWORD v353[4]; // [esp+1E4h] [ebp-70h] BYREF
  _DWORD v354[8]; // [esp+1F4h] [ebp-60h] BYREF
  _DWORD v355[8]; // [esp+214h] [ebp-40h] BYREF
  btVector3 v356; // [esp+234h] [ebp-20h] BYREF
  int v357; // [esp+244h] [ebp-10h] BYREF
  int v358; // [esp+248h] [ebp-Ch] BYREF
  int v359; // [esp+24Ch] [ebp-8h]
  int v360; // [esp+250h] [ebp-4h]
  int vars0; // [esp+254h] [ebp+0h]
  _UNKNOWN *retaddr; // [esp+258h] [ebp+4h] BYREF

  v3 = ((int (__thiscall *)(btTypedConstraint *))constraint->getInfo1)(constraint);
  v302 = ((*(int (__thiscall **)(int))(*(_DWORD *)v3 + 48))(v3) & 0x800) != 0;
  v4 = ((int (__thiscall *)(btTypedConstraint *))constraint->getInfo1)(constraint);
  v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 48))(v4);
  v7 = *(float *)(a3 + 36);
  fAngleInRadians.m_el[1].mVec128.m128_i8[11] = (v5 & 0x1000) != 0;
  fAngleInRadians.m_el[0].mVec128.m128_f32[3] = v7;
  if ( v7 <= 0.0 )
    return;
  switch ( *(_DWORD *)(a3 + 4) )
  {
    case 3:
      btMatrix3x3::setIdentity(v6, (int)&v306.m_el[1].mVec128.m128_i32[1]);
      v275 = *(float **)(a3 + 24);
      v312.mVec128 = (__m128)0LL;
      v276 = v275[6];
      v277 = v275[5];
      *(unsigned __int64 *)((char *)v306.m_el[0].mVec128.m128_u64 + 4) = *(_QWORD *)(a3 + 336);
      v306.m_el[0].mVec128.m128_i32[3] = *(_DWORD *)(a3 + 344);
      v275 += 4;
      v306.m_el[1].mVec128.m128_i32[0] = *(_DWORD *)(a3 + 348);
      v278 = v275[5] * v306.m_el[0].mVec128.m128_f32[2];
      fAngleInRadians.m_el[2].mVec128.m128_f32[0] = (float)((float)((float)(v276 * v306.m_el[0].mVec128.m128_f32[3])
                                                                  + (float)(v277 * v306.m_el[0].mVec128.m128_f32[2]))
                                                          + (float)(v306.m_el[0].mVec128.m128_f32[1] * *v275))
                                                  + v275[12];
      v279 = v306.m_el[0].mVec128.m128_f32[1] * v275[8];
      v280 = (float)((float)((float)(v275[6] * v306.m_el[0].mVec128.m128_f32[3]) + v278)
                   + (float)(v306.m_el[0].mVec128.m128_f32[1] * v275[4]))
           + v275[13];
      v281 = v275[9] * v306.m_el[0].mVec128.m128_f32[2];
      fAngleInRadians.m_el[2].mVec128.m128_f32[1] = v280;
      *(float *)&v282 = (float)((float)((float)(v275[10] * v306.m_el[0].mVec128.m128_f32[3]) + v281) + v279) + v275[14];
      v283 = constraint->__vftable;
      fAngleInRadians.m_el[2].mVec128.m128_u64[1] = v282;
      v312.mVec128.m128_u64[0] = fAngleInRadians.m_el[2].mVec128.m128_u64[0];
      v312.mVec128.m128_u64[1] = v282;
      v284 = ((int (__thiscall *)(btTypedConstraint *))v283->getInfo1)(constraint);
      (*(void (__thiscall **)(int, float *, int))(*(_DWORD *)v284 + 56))(
        v284,
        &v306.m_el[1].mVec128.m128_f32[1],
        fAngleInRadians.m_el[0].mVec128.m128_i32[3]);
      v285 = *(float **)(a3 + 28);
      v286 = v285[6];
      v287 = v285[5];
      *(unsigned __int64 *)((char *)v306.m_el[0].mVec128.m128_u64 + 4) = *(_QWORD *)(a3 + 352);
      v306.m_el[0].mVec128.m128_i32[3] = *(_DWORD *)(a3 + 360);
      v285 += 4;
      v306.m_el[1].mVec128.m128_i32[0] = *(_DWORD *)(a3 + 364);
      v288 = v285[5] * v306.m_el[0].mVec128.m128_f32[2];
      fAngleInRadians.m_el[2].mVec128.m128_f32[0] = (float)((float)((float)(v286 * v306.m_el[0].mVec128.m128_f32[3])
                                                                  + (float)(v287 * v306.m_el[0].mVec128.m128_f32[2]))
                                                          + (float)(v306.m_el[0].mVec128.m128_f32[1] * *v285))
                                                  + v285[12];
      v289 = v306.m_el[0].mVec128.m128_f32[1] * v285[8];
      *(float *)&v290 = (float)((float)((float)(v285[6] * v306.m_el[0].mVec128.m128_f32[3]) + v288)
                              + (float)(v285[4] * v306.m_el[0].mVec128.m128_f32[1]))
                      + v285[13];
      v291 = v285[9] * v306.m_el[0].mVec128.m128_f32[2];
      fAngleInRadians.m_el[2].mVec128.m128_i32[1] = v290;
      fAngleInRadians.m_el[2].mVec128.m128_f32[2] = (float)((float)((float)(v285[10] * v306.m_el[0].mVec128.m128_f32[3])
                                                                  + v291)
                                                          + v289)
                                                  + v285[14];
      fAngleInRadians.m_el[2].mVec128.m128_i32[3] = 0;
      v312.mVec128.m128_i32[0] = fAngleInRadians.m_el[2].mVec128.m128_i32[0];
      *(unsigned __int64 *)((char *)v312.mVec128.m128_u64 + 4) = __PAIR64__(
                                                                   fAngleInRadians.m_el[2].mVec128.m128_u32[2],
                                                                   v290);
      v312.mVec128.m128_i32[3] = 0;
      if ( v302 )
      {
        v292 = ((int (__thiscall *)(btTypedConstraint *))constraint->getInfo1)(constraint);
        (*(void (__thiscall **)(int, float *, int))(*(_DWORD *)v292 + 56))(
          v292,
          &v306.m_el[1].mVec128.m128_f32[1],
          fAngleInRadians.m_el[0].mVec128.m128_i32[3]);
      }
      break;
    case 4:
      v193 = *(float **)(a3 + 24);
      v194 = *(float *)(a3 + 676);
      v195 = *(float *)(a3 + 672);
      v196 = *(float *)(a3 + 680);
      v197 = v193[5];
      v198 = v193[6];
      v193 += 4;
      v199 = *v193;
      fAngleInRadians.m_el[1].mVec128.m128_u64[0] = __PAIR64__(LODWORD(v197), LODWORD(v198));
      *(float *)&v303 = v199;
      v200 = (float)((float)((float)(v199 * v195) + (float)(v197 * v194)) + (float)(v198 * v196)) + v193[12];
      v201 = v193[9];
      v202 = *(float *)(a3 + 664);
      fAngleInRadians.m_el[2].mVec128.m128_f32[1] = (float)((float)((float)(v193[5] * v194) + (float)(v193[6] * v196))
                                                          + (float)(v195 * v193[4]))
                                                  + v193[13];
      v203 = (float)(v193[9] * v194) + (float)(v193[10] * v196);
      v204 = v193[8] * v195;
      v205 = *(float *)(a3 + 644);
      *(float *)&v206 = (float)(v203 + v204) + v193[14];
      v207 = (float)(v193[9] * *(float *)(a3 + 648)) + (float)(v193[10] * v202);
      v208 = v193[8] * *(float *)(a3 + 632);
      v209 = v193[9];
      fAngleInRadians.m_el[2].mVec128.m128_u64[1] = v206;
      v210 = v193[10];
      fAngleInRadians.m_el[2].mVec128.m128_f32[0] = v200;
      v211 = *(float *)(a3 + 640);
      v212 = v207 + v208;
      v213 = *(float *)(a3 + 628);
      v314 = v212;
      v214 = *(float *)(a3 + 660);
      v215 = (float)(v209 * v205) + (float)(v210 * v214);
      v216 = v193[8];
      fAngleInRadians.m_el[0].mVec128.m128_f32[0] = v211;
      v217 = v215 + (float)(v216 * v213);
      v218 = *(float *)(a3 + 656);
      v219 = (float)(v201 * v211) + (float)(v193[10] * v218);
      v220 = v193[8];
      v316 = v217;
      v221 = *(float *)(a3 + 624);
      v222 = v219 + (float)(v220 * v221);
      v223 = *(float *)(a3 + 648);
      v317 = v222;
      v224 = v193[5] * v223;
      v225 = v193[6] * v202;
      v226 = *(float *)(a3 + 632);
      v227 = (float)(v224 + v225) + (float)(v193[4] * v226);
      v228 = v193[5];
      v319 = v227;
      v229 = v193[6];
      v318 = (float)((float)(v228 * v205) + (float)(v229 * v214)) + (float)(v213 * v193[4]);
      v315 = (float)((float)(v193[5] * fAngleInRadians.m_el[0].mVec128.m128_f32[0]) + (float)(v229 * v218))
           + (float)(v221 * v193[4]);
      v230 = *(float *)&v303 * v226;
      v231 = *(float *)(a3 + 664);
      v232 = v230 + (float)(fAngleInRadians.m_el[1].mVec128.m128_f32[1] * *(float *)(a3 + 648));
      fAngleInRadians.m_el[0].mVec128.m128_f32[1] = (float)((float)(v213 * *(float *)&v303)
                                                          + (float)(v205 * fAngleInRadians.m_el[1].mVec128.m128_f32[1]))
                                                  + (float)(v214 * fAngleInRadians.m_el[1].mVec128.m128_f32[0]);
      v306.m_el[0].mVec128.m128_f32[0] = v232 + (float)(fAngleInRadians.m_el[1].mVec128.m128_f32[0] * v231);
      fAngleInRadians.m_el[0].mVec128.m128_f32[0] = (float)((float)(v221 * *(float *)&v303)
                                                          + (float)(fAngleInRadians.m_el[0].mVec128.m128_f32[0]
                                                                  * fAngleInRadians.m_el[1].mVec128.m128_f32[1]))
                                                  + (float)(v218 * fAngleInRadians.m_el[1].mVec128.m128_f32[0]);
      btMatrix3x3::setValue(
        &fAngleInRadians,
        (int)&v330,
        &fAngleInRadians.m_el[0].mVec128.m128_f32[1],
        (float *)&v306,
        &v315,
        &v318,
        &v319,
        &v317,
        &v316,
        &v314,
        (const float *)LODWORD(v293));
      *(unsigned __int64 *)((char *)v306.m_el[1].mVec128.m128_u64 + 4) = v330;
      v306.m_el[1].mVec128.m128_i32[3] = v331;
      v306.m_el[2] = (btVector3)v332.mVec128;
      v307 = v333;
      v308 = v334;
      v309 = v335;
      v310 = v336;
      v311 = v337;
      v312.mVec128 = (__m128)fAngleInRadians.m_el[2];
      if ( v302 )
      {
        v233 = ((int (__thiscall *)(btTypedConstraint *))constraint->getInfo1)(constraint);
        (*(void (__thiscall **)(int, float *, int))(*(_DWORD *)v233 + 56))(
          v233,
          &v306.m_el[1].mVec128.m128_f32[1],
          fAngleInRadians.m_el[0].mVec128.m128_i32[3]);
      }
      v234 = *(_DWORD *)(a3 + 28);
      v235 = *(float *)(a3 + 736);
      v236 = *(float *)(a3 + 740);
      v237 = *(float *)(a3 + 744);
      v238 = *(float *)(v234 + 20);
      v239 = *(float *)(v234 + 24);
      v234 += 16;
      v240 = v235 * *(float *)v234;
      v303 = *(int *)v234;
      v241 = *(float *)(a3 + 708);
      fAngleInRadians.m_el[1].mVec128.m128_u64[0] = __PAIR64__(LODWORD(v238), LODWORD(v239));
      v242 = (float)((float)(v240 + (float)(v236 * v238)) + (float)(v237 * v239)) + *(float *)(v234 + 48);
      v243 = *(float *)(v234 + 36);
      v244 = *(float *)(a3 + 712);
      fAngleInRadians.m_el[2].mVec128.m128_f32[1] = (float)((float)((float)(*(float *)(v234 + 20) * v236)
                                                                  + (float)(*(float *)(v234 + 24) * v237))
                                                          + (float)(*(float *)(v234 + 16) * v235))
                                                  + *(float *)(v234 + 52);
      v245 = *(float *)(v234 + 36) * v236;
      v246 = *(float *)(v234 + 40) * v237;
      v247 = *(float *)(v234 + 32) * v235;
      v248 = *(float *)(v234 + 40);
      v249 = v245 + v246;
      v250 = *(float *)(v234 + 36);
      *(float *)&v251 = (float)(v249 + v247) + *(float *)(v234 + 56);
      fAngleInRadians.m_el[2].mVec128.m128_f32[0] = v242;
      v252 = *(float *)(v234 + 36) * v241;
      fAngleInRadians.m_el[2].mVec128.m128_u64[1] = v251;
      v253 = *(float *)(a3 + 728);
      v254 = *(float *)(a3 + 696);
      fAngleInRadians.m_el[0].mVec128.m128_f32[0] = v241;
      v255 = (float)((float)(v250 * v244) + (float)(v248 * v253)) + (float)(v254 * *(float *)(v234 + 32));
      v256 = v252 + (float)(*(float *)(v234 + 40) * *(float *)(a3 + 724));
      v257 = *(float *)(a3 + 720);
      fAngleInRadians.m_el[0].mVec128.m128_i32[1] = *(_DWORD *)(a3 + 724);
      v316 = v255;
      v258 = *(float *)(a3 + 692);
      v259 = *(float *)(a3 + 688);
      v317 = v256 + (float)(v258 * *(float *)(v234 + 32));
      v260 = v243 * *(float *)(a3 + 704);
      fAngleInRadians.m_el[1].mVec128.m128_i32[3] = *(_DWORD *)(a3 + 704);
      v261 = *(float *)(v234 + 40) * v257;
      v314 = v257;
      v262 = (float)(v260 + v261) + (float)(v259 * *(float *)(v234 + 32));
      v263 = *(float *)(v234 + 24) * fAngleInRadians.m_el[0].mVec128.m128_f32[1];
      v318 = (float)((float)(*(float *)(v234 + 20) * v244) + (float)(*(float *)(v234 + 24) * v253))
           + (float)(*(float *)(v234 + 16) * v254);
      v264 = (float)((float)(*(float *)(v234 + 20) * fAngleInRadians.m_el[0].mVec128.m128_f32[0]) + v263)
           + (float)(*(float *)(v234 + 16) * v258);
      v265 = *(float *)(v234 + 20);
      v319 = v262;
      v266 = *(float *)(v234 + 24);
      v315 = v264;
      v267 = (float)(v265 * fAngleInRadians.m_el[1].mVec128.m128_f32[3]) + (float)(v266 * v314);
      v268 = *(float *)(v234 + 16);
      v306.m_el[0].mVec128.m128_f32[0] = (float)((float)(v254 * *(float *)&v303)
                                               + (float)(v244 * fAngleInRadians.m_el[1].mVec128.m128_f32[1]))
                                       + (float)(v253 * fAngleInRadians.m_el[1].mVec128.m128_f32[0]);
      v269 = fAngleInRadians.m_el[1].mVec128.m128_f32[3] * fAngleInRadians.m_el[1].mVec128.m128_f32[1];
      v270 = v267 + (float)(v268 * v259);
      v271 = (float)((float)(v259 * *(float *)&v303)
                   + (float)(fAngleInRadians.m_el[1].mVec128.m128_f32[3] * fAngleInRadians.m_el[1].mVec128.m128_f32[1]))
           + (float)(v314 * fAngleInRadians.m_el[1].mVec128.m128_f32[0]);
      v314 = v270;
      fAngleInRadians.m_el[0].mVec128.m128_f32[0] = (float)((float)(v258 * *(float *)&v303)
                                                          + (float)(fAngleInRadians.m_el[0].mVec128.m128_f32[0]
                                                                  * fAngleInRadians.m_el[1].mVec128.m128_f32[1]))
                                                  + (float)(fAngleInRadians.m_el[0].mVec128.m128_f32[1]
                                                          * fAngleInRadians.m_el[1].mVec128.m128_f32[0]);
      fAngleInRadians.m_el[0].mVec128.m128_f32[1] = v271;
      btMatrix3x3::setValue(
        (btMatrix3x3 *)&fAngleInRadians.m_el[0].m_floats[1],
        (int)&v330,
        (float *)&fAngleInRadians,
        (float *)&v306,
        &v314,
        &v315,
        &v318,
        &v319,
        &v317,
        &v316,
        v300);
      *(unsigned __int64 *)((char *)v306.m_el[1].mVec128.m128_u64 + 4) = v330;
      v306.m_el[1].mVec128.m128_i32[3] = v331;
      v306.m_el[2] = (btVector3)v332.mVec128;
      v307 = v333;
      v308 = v334;
      v309 = v335;
      v310 = v336;
      v311 = v337;
      v312.mVec128 = (__m128)fAngleInRadians.m_el[2];
      if ( v302 )
      {
        v273 = ((int (__thiscall *)(btTypedConstraint *))constraint->getInfo1)(constraint);
        (*(void (__thiscall **)(int, float *, int))(*(_DWORD *)v273 + 56))(
          v273,
          &v306.m_el[1].mVec128.m128_f32[1],
          fAngleInRadians.m_el[0].mVec128.m128_i32[3]);
      }
      btAngularLimit::getLow(v272, (float *)(a3 + 760));
      *(float *)&v303 = v269;
      btAngularLimit::getHigh(v274, (float *)(a3 + 760));
      fAngleInRadians.m_el[0].mVec128.m128_f32[2] = v269;
      break;
    case 5:
      v39 = *(float **)(a3 + 24);
      v40 = *(float *)(a3 + 388);
      v41 = v39[5];
      v42 = *(float *)(a3 + 392);
      v43 = v39[6];
      v39 += 4;
      v44 = *v39;
      v45 = (float)((float)((float)(*v39 * *(float *)(a3 + 384)) + (float)(v41 * v40)) + (float)(v43 * v42)) + v39[12];
      v46 = v39[5] * v40;
      v47 = v39[6];
      fAngleInRadians.m_el[2].mVec128.m128_f32[0] = v45;
      v48 = v46 + (float)(v47 * v42);
      v49 = *(float *)(a3 + 384);
      v50 = v39[9];
      fAngleInRadians.m_el[2].mVec128.m128_f32[1] = (float)(v48 + (float)(v39[4] * v49)) + v39[13];
      v51 = (float)(v50 * *(float *)(a3 + 388)) + (float)(v39[10] * v42);
      v52 = v39[8] * v49;
      v53 = *(float *)(a3 + 344) * v39[8];
      *(float *)&v54 = (float)(v51 + v52) + v39[14];
      v55 = *(float *)(a3 + 360);
      v56 = v39[9] * v55;
      fAngleInRadians.m_el[2].mVec128.m128_u64[1] = v54;
      v57 = *(float *)(a3 + 376);
      v58 = v39[9];
      v59 = (float)(v56 + (float)(v39[10] * v57)) + v53;
      v60 = *(float *)(a3 + 372);
      fAngleInRadians.m_el[0].mVec128.m128_f32[0] = v59;
      v61 = v39[10] * v60;
      v62 = *(float *)(a3 + 368);
      v63 = (float)((float)(v58 * *(float *)(a3 + 356)) + v61) + (float)(v39[8] * *(float *)(a3 + 340));
      v64 = *(float *)(a3 + 352);
      fAngleInRadians.m_el[0].mVec128.m128_f32[1] = v63;
      v65 = (float)((float)(v39[9] * v64) + (float)(v39[10] * v62)) + (float)(v39[8] * *(float *)(a3 + 336));
      v66 = v39[5] * v55;
      v67 = v39[6] * v57;
      fAngleInRadians.m_el[1].mVec128.m128_f32[3] = v65;
      v68 = v66 + v67;
      v69 = *(float *)(a3 + 356);
      v70 = v39[6];
      v305 = v68 + (float)(v39[4] * *(float *)(a3 + 344));
      v71 = v39[5] * v69;
      v72 = *(float *)(a3 + 352);
      *(float *)&v73 = (float)(v71 + (float)(v70 * *(float *)(a3 + 372))) + (float)(v39[4] * *(float *)(a3 + 340));
      v74 = v39[6];
      v303 = v73;
      v75 = v39[5] * v72;
      v76 = *(float *)(a3 + 336);
      fAngleInRadians.m_el[1].mVec128.m128_f32[1] = (float)(v75 + (float)(v74 * *(float *)(a3 + 368)))
                                                  + (float)(v39[4] * v76);
      v77 = (float)((float)(v44 * *(float *)(a3 + 344)) + (float)(v41 * v55)) + (float)(v43 * v57);
      v78 = (float)((float)(v44 * *(float *)(a3 + 340)) + (float)(v41 * *(float *)(a3 + 356)))
          + (float)(v43 * *(float *)(a3 + 372));
      v79 = (float)((float)(v43 * *(float *)(a3 + 368)) + (float)(v44 * v76)) + (float)(v41 * *(float *)(a3 + 352));
      fAngleInRadians.m_el[1].mVec128.m128_f32[0] = v77;
      fAngleInRadians.m_el[0].mVec128.m128_f32[2] = v78;
      v306.m_el[0].mVec128.m128_f32[0] = v79;
      btMatrix3x3::setValue(
        &v306,
        (int)&v330,
        &fAngleInRadians.m_el[0].mVec128.m128_f32[2],
        fAngleInRadians.m_el[1].mVec128.m128_f32,
        &fAngleInRadians.m_el[1].mVec128.m128_f32[1],
        (float *)&v303,
        &v305,
        &fAngleInRadians.m_el[1].mVec128.m128_f32[3],
        &fAngleInRadians.m_el[0].mVec128.m128_f32[1],
        (const float *)&fAngleInRadians,
        (const float *)LODWORD(v293));
      *(unsigned __int64 *)((char *)v306.m_el[1].mVec128.m128_u64 + 4) = v330;
      v306.m_el[1].mVec128.m128_i32[3] = v331;
      v306.m_el[2] = (btVector3)v332.mVec128;
      v307 = v333;
      v308 = v334;
      v309 = v335;
      v310 = v336;
      v311 = v337;
      v312.mVec128 = (__m128)fAngleInRadians.m_el[2];
      if ( v302 )
      {
        v80 = ((int (__thiscall *)(btTypedConstraint *))constraint->getInfo1)(constraint);
        (*(void (__thiscall **)(int, float *, int))(*(_DWORD *)v80 + 56))(
          v80,
          &v306.m_el[1].mVec128.m128_f32[1],
          fAngleInRadians.m_el[0].mVec128.m128_i32[3]);
      }
      v81 = *(float **)(a3 + 28);
      v82 = *(float *)(a3 + 452);
      v83 = *(float *)(a3 + 448);
      v84 = v81[5];
      v85 = *(float *)(a3 + 456);
      v86 = v81[6];
      v81 += 4;
      v87 = *v81;
      v88 = v81[6];
      fAngleInRadians.m_el[2].mVec128.m128_f32[0] = (float)((float)((float)(*v81 * v83) + (float)(v84 * v82))
                                                          + (float)(v86 * v85))
                                                  + v81[12];
      v89 = (float)((float)((float)(v81[5] * v82) + (float)(v88 * v85)) + (float)(v83 * v81[4])) + v81[13];
      v90 = v83 * v81[8];
      v91 = v81[10];
      fAngleInRadians.m_el[2].mVec128.m128_f32[1] = v89;
      v92 = v81[9] * v82;
      v93 = v81[10] * v85;
      v94 = *(float *)(a3 + 424);
      v95 = v92 + v93;
      v96 = *(float *)(a3 + 408);
      fAngleInRadians.m_el[2].mVec128.m128_f32[2] = (float)(v95 + v90) + v81[14];
      v97 = v81[9] * v94;
      fAngleInRadians.m_el[2].mVec128.m128_i32[3] = 0;
      v98 = *(float *)(a3 + 440);
      v99 = v97 + (float)(v91 * v98);
      v100 = v81[8] * v96;
      v101 = *(float *)(a3 + 436);
      v102 = v99 + v100;
      v103 = v81[9];
      v306.m_el[0].mVec128.m128_f32[0] = v102;
      v104 = v81[10] * v101;
      v105 = *(float *)(a3 + 432);
      v106 = (float)((float)(v103 * *(float *)(a3 + 420)) + v104) + (float)(v81[8] * *(float *)(a3 + 404));
      v107 = *(float *)(a3 + 416);
      fAngleInRadians.m_el[0].mVec128.m128_f32[0] = v106;
      v108 = (float)(v81[9] * v107) + (float)(v81[10] * v105);
      v109 = (float)(v81[5] * v94) + (float)(v81[6] * v98);
      v110 = *(float *)(a3 + 408) * v81[4];
      fAngleInRadians.m_el[0].mVec128.m128_f32[1] = v108 + (float)(*(float *)(a3 + 400) * v81[8]);
      v111 = v81[6];
      v112 = v109 + v110;
      v113 = *(float *)(a3 + 420);
      fAngleInRadians.m_el[1].mVec128.m128_f32[3] = v112;
      v114 = (float)(v81[5] * v113) + (float)(v111 * *(float *)(a3 + 436));
      v115 = v81[5];
      v116 = *(float *)(a3 + 416);
      v305 = v114 + (float)(*(float *)(a3 + 404) * v81[4]);
      v117 = v115 * v116;
      v118 = *(float *)(a3 + 432);
      v119 = *(float *)(a3 + 408);
      *(float *)&v303 = (float)(v117 + (float)(v81[6] * v118)) + (float)(*(float *)(a3 + 400) * v81[4]);
      v120 = (float)((float)(v87 * v119) + (float)(v84 * v94)) + (float)(v86 * v98);
      v121 = (float)(v87 * *(float *)(a3 + 404)) + (float)(v84 * *(float *)(a3 + 420));
      v122 = v86 * *(float *)(a3 + 436);
      v123 = (float)((float)(v87 * *(float *)(a3 + 400)) + (float)(v84 * *(float *)(a3 + 416))) + (float)(v86 * v118);
      fAngleInRadians.m_el[1].mVec128.m128_f32[1] = v120;
      fAngleInRadians.m_el[1].mVec128.m128_f32[0] = v121 + v122;
      fAngleInRadians.m_el[0].mVec128.m128_f32[2] = v123;
      btMatrix3x3::setValue(
        (btMatrix3x3 *)&fAngleInRadians.m_el[0].m_floats[2],
        (int)&v330,
        fAngleInRadians.m_el[1].mVec128.m128_f32,
        &fAngleInRadians.m_el[1].mVec128.m128_f32[1],
        (float *)&v303,
        &v305,
        &fAngleInRadians.m_el[1].mVec128.m128_f32[3],
        &fAngleInRadians.m_el[0].mVec128.m128_f32[1],
        (float *)&fAngleInRadians,
        (const float *)&v306,
        v296);
      *(unsigned __int64 *)((char *)v306.m_el[1].mVec128.m128_u64 + 4) = v330;
      v306.m_el[1].mVec128.m128_i32[3] = v331;
      v306.m_el[2] = (btVector3)v332.mVec128;
      v307 = v333;
      v308 = v334;
      v309 = v335;
      v310 = v336;
      v311 = v337;
      v312.mVec128 = (__m128)fAngleInRadians.m_el[2];
      if ( v302 )
      {
        v125 = ((int (__thiscall *)(btTypedConstraint *))constraint->getInfo1)(constraint);
        (*(void (__thiscall **)(int, float *, int))(*(_DWORD *)v125 + 56))(
          v125,
          &v306.m_el[1].mVec128.m128_f32[1],
          fAngleInRadians.m_el[0].mVec128.m128_i32[3]);
      }
      if ( fAngleInRadians.m_el[1].mVec128.m128_i8[11] )
      {
        btConeTwistConstraint::GetPointForAngle(
          v124,
          a3,
          (int)v320,
          6.0868354,
          fAngleInRadians.m_el[0].mVec128.m128_f32[3],
          v297);
        fAngleInRadians.m_el[2].mVec128.m128_f32[0] = (float)((float)((float)(v306.m_el[1].mVec128.m128_f32[3]
                                                                            * *(float *)&v320[8])
                                                                    + (float)(v306.m_el[1].mVec128.m128_f32[2]
                                                                            * *(float *)&v320[4]))
                                                            + (float)(v306.m_el[1].mVec128.m128_f32[1] * *(float *)v320))
                                                    + v312.mVec128.m128_f32[0];
        fAngleInRadians.m_el[2].mVec128.m128_f32[1] = (float)((float)((float)(v306.m_el[2].mVec128.m128_f32[3]
                                                                            * *(float *)&v320[8])
                                                                    + (float)(v306.m_el[2].mVec128.m128_f32[2]
                                                                            * *(float *)&v320[4]))
                                                            + (float)(v306.m_el[2].mVec128.m128_f32[1] * *(float *)v320))
                                                    + v312.mVec128.m128_f32[1];
        fAngleInRadians.m_el[0].mVec128.m128_i32[2] = 0;
        fAngleInRadians.m_el[2].mVec128.m128_f32[2] = (float)((float)((float)(v310 * *(float *)&v320[8])
                                                                    + (float)(v309 * *(float *)&v320[4]))
                                                            + (float)(v308 * *(float *)v320))
                                                    + v312.mVec128.m128_f32[2];
        *(float *)v320 = fAngleInRadians.m_el[2].mVec128.m128_f32[0];
        *(_QWORD *)&v320[4] = *(unsigned __int64 *)((char *)fAngleInRadians.m_el[2].mVec128.m128_u64 + 4);
        v321 = 0;
        fAngleInRadians.m_el[2].mVec128.m128_i32[3] = 0;
        do
        {
          btConeTwistConstraint::GetPointForAngle(
            v126,
            a3,
            (int)&v306.m_el[0].mVec128.m128_i32[1],
            (float)fAngleInRadians.m_el[0].mVec128.m128_i32[2] * 0.19634953,
            fAngleInRadians.m_el[0].mVec128.m128_f32[3],
            *(float *)&v298);
          fAngleInRadians.m_el[2].mVec128.m128_f32[0] = (float)((float)((float)(v306.m_el[1].mVec128.m128_f32[3]
                                                                              * v306.m_el[0].mVec128.m128_f32[3])
                                                                      + (float)(v306.m_el[1].mVec128.m128_f32[2]
                                                                              * v306.m_el[0].mVec128.m128_f32[2]))
                                                              + (float)(v306.m_el[1].mVec128.m128_f32[1]
                                                                      * v306.m_el[0].mVec128.m128_f32[1]))
                                                      + v312.mVec128.m128_f32[0];
          fAngleInRadians.m_el[2].mVec128.m128_f32[1] = (float)((float)((float)(v306.m_el[2].mVec128.m128_f32[3]
                                                                              * v306.m_el[0].mVec128.m128_f32[3])
                                                                      + (float)(v306.m_el[2].mVec128.m128_f32[2]
                                                                              * v306.m_el[0].mVec128.m128_f32[2]))
                                                              + (float)(v306.m_el[2].mVec128.m128_f32[1]
                                                                      * v306.m_el[0].mVec128.m128_f32[1]))
                                                      + v312.mVec128.m128_f32[1];
          fAngleInRadians.m_el[2].mVec128.m128_f32[2] = (float)((float)((float)(v310 * v306.m_el[0].mVec128.m128_f32[3])
                                                                      + (float)(v309 * v306.m_el[0].mVec128.m128_f32[2]))
                                                              + (float)(v308 * v306.m_el[0].mVec128.m128_f32[1]))
                                                      + v312.mVec128.m128_f32[2];
          *(btVector3 *)((char *)v306.m_el + 4) = fAngleInRadians.m_el[2];
          v127 = ((int (__thiscall *)(btTypedConstraint *))constraint->getInfo1)(constraint);
          memset(v353, 0, sizeof(v353));
          (*(void (__thiscall **)(int, _BYTE *, float *, _DWORD *))(*(_DWORD *)v127 + 12))(
            v127,
            v320,
            &v306.m_el[0].mVec128.m128_f32[1],
            v353);
          if ( !(fAngleInRadians.m_el[0].mVec128.m128_i32[2] % 4) )
          {
            v128 = ((int (__thiscall *)(btTypedConstraint *))constraint->getInfo1)(constraint);
            memset(v354, 0, 16);
            (*(void (__thiscall **)(int, btVector3 *, float *, _DWORD *))(*(_DWORD *)v128 + 12))(
              v128,
              &v312,
              &v306.m_el[0].mVec128.m128_f32[1],
              v354);
          }
          ++fAngleInRadians.m_el[0].mVec128.m128_i32[2];
          *(_QWORD *)v320 = *(unsigned __int64 *)((char *)v306.m_el[0].mVec128.m128_u64 + 4);
          *(_DWORD *)&v320[8] = v306.m_el[0].mVec128.m128_i32[3];
          v321 = v306.m_el[1].mVec128.m128_i32[0];
        }
        while ( fAngleInRadians.m_el[0].mVec128.m128_i32[2] < 32 );
        v129 = *(float **)(a3 + 28);
        fAngleInRadians.m_el[0].mVec128.m128_i32[0] = *(_DWORD *)(a3 + 488);
        v314 = *(float *)(a3 + 548);
        if ( v129[88] <= 0.0 )
        {
          v159 = *(_DWORD *)(a3 + 24);
          v160 = *(float *)(a3 + 384);
          v161 = *(float *)(a3 + 388);
          v162 = *(float *)(a3 + 392);
          v163 = *(float *)(v159 + 20);
          v164 = *(float *)(v159 + 24);
          v159 += 16;
          fAngleInRadians.m_el[1].mVec128.m128_i32[1] = *(_DWORD *)v159;
          fAngleInRadians.m_el[1].mVec128.m128_f32[0] = v164;
          *(float *)&v303 = v163;
          v165 = *(float *)(v159 + 36);
          v166 = (float)((float)((float)(v160 * fAngleInRadians.m_el[1].mVec128.m128_f32[1]) + (float)(v161 * v163))
                       + (float)(v162 * v164))
               + *(float *)(v159 + 48);
          v167 = *(float *)(a3 + 372);
          fAngleInRadians.m_el[2].mVec128.m128_f32[1] = (float)((float)((float)(*(float *)(v159 + 20) * v161)
                                                                      + (float)(*(float *)(v159 + 24) * v162))
                                                              + (float)(v160 * *(float *)(v159 + 16)))
                                                      + *(float *)(v159 + 52);
          v168 = *(float *)(v159 + 36) * v161;
          v169 = *(float *)(v159 + 40) * v162;
          v170 = *(float *)(v159 + 32) * v160;
          v171 = *(float *)(v159 + 40);
          v172 = v168 + v169;
          v173 = *(float *)(v159 + 36);
          *(float *)&v174 = (float)(v172 + v170) + *(float *)(v159 + 56);
          v175 = *(float *)(a3 + 344);
          fAngleInRadians.m_el[2].mVec128.m128_u64[1] = v174;
          v176 = *(float *)(a3 + 360);
          v177 = *(float *)(a3 + 376);
          fAngleInRadians.m_el[2].mVec128.m128_f32[0] = v166;
          v178 = (float)((float)(v173 * v176) + (float)(v171 * v177)) + (float)(v175 * *(float *)(v159 + 32));
          v179 = *(float *)(a3 + 340);
          v180 = *(float *)(v159 + 40) * v167;
          v316 = v178;
          v181 = *(float *)(a3 + 356);
          *(unsigned __int64 *)((char *)fAngleInRadians.m_el[0].mVec128.m128_u64 + 4) = __PAIR64__(
                                                                                          *(_DWORD *)(a3 + 336),
                                                                                          LODWORD(v179));
          v182 = (float)((float)(v165 * v181) + v180) + (float)(v179 * *(float *)(v159 + 32));
          v183 = *(float *)(a3 + 368);
          v317 = v182;
          v184 = *(float *)(v159 + 36) * *(float *)(a3 + 352);
          fAngleInRadians.m_el[1].mVec128.m128_i32[3] = *(_DWORD *)(a3 + 352);
          v185 = *(float *)(v159 + 20);
          v319 = (float)(v184 + (float)(*(float *)(v159 + 40) * v183))
               + (float)(fAngleInRadians.m_el[0].mVec128.m128_f32[2] * *(float *)(v159 + 32));
          v186 = *(float *)(v159 + 24);
          v318 = (float)((float)(v185 * v176) + (float)(v186 * v177)) + (float)(v175 * *(float *)(v159 + 16));
          v187 = (float)(*(float *)(v159 + 20) * v181) + (float)(v186 * v167);
          v188 = *(float *)(v159 + 24);
          v315 = v187 + (float)(fAngleInRadians.m_el[0].mVec128.m128_f32[1] * *(float *)(v159 + 16));
          v189 = (float)(*(float *)(v159 + 20) * fAngleInRadians.m_el[1].mVec128.m128_f32[3]) + (float)(v188 * v183);
          v190 = fAngleInRadians.m_el[0].mVec128.m128_f32[2] * *(float *)(v159 + 16);
          v305 = (float)((float)(v175 * fAngleInRadians.m_el[1].mVec128.m128_f32[1]) + (float)(v176 * *(float *)&v303))
               + (float)(v177 * fAngleInRadians.m_el[1].mVec128.m128_f32[0]);
          v306.m_el[0].mVec128.m128_f32[0] = v189 + v190;
          fAngleInRadians.m_el[0].mVec128.m128_f32[1] = (float)((float)(v181 * *(float *)&v303)
                                                              + (float)(v167
                                                                      * fAngleInRadians.m_el[1].mVec128.m128_f32[0]))
                                                      + (float)(fAngleInRadians.m_el[0].mVec128.m128_f32[1]
                                                              * fAngleInRadians.m_el[1].mVec128.m128_f32[1]);
          fAngleInRadians.m_el[1].mVec128.m128_f32[3] = (float)((float)(v183
                                                                      * fAngleInRadians.m_el[1].mVec128.m128_f32[0])
                                                              + (float)(fAngleInRadians.m_el[0].mVec128.m128_f32[2]
                                                                      * fAngleInRadians.m_el[1].mVec128.m128_f32[1]))
                                                      + (float)(fAngleInRadians.m_el[1].mVec128.m128_f32[3]
                                                              * *(float *)&v303);
          btMatrix3x3::setValue(
            (btMatrix3x3 *)&fAngleInRadians.m_el[1].m_floats[3],
            (int)&v330,
            &fAngleInRadians.m_el[0].mVec128.m128_f32[1],
            &v305,
            (float *)&v306,
            &v315,
            &v318,
            &v319,
            &v317,
            &v316,
            v298);
        }
        else
        {
          v130 = *(float *)(a3 + 448);
          v131 = v129[5];
          v132 = v129[4];
          v133 = v129[6];
          v134 = *(float *)(a3 + 456);
          v135 = v129[9];
          fAngleInRadians.m_el[2].mVec128.m128_f32[0] = (float)((float)((float)(v132 * v130)
                                                                      + (float)(v131 * *(float *)(a3 + 452)))
                                                              + (float)(v133 * v134))
                                                      + v129[16];
          v136 = (float)((float)((float)(v135 * *(float *)(a3 + 452)) + (float)(v129[10] * v134))
                       + (float)(v130 * v129[8]))
               + v129[17];
          v137 = *(float *)(a3 + 452);
          v138 = v130 * v129[12];
          fAngleInRadians.m_el[2].mVec128.m128_f32[1] = v136;
          v139 = v129[13] * v137;
          v140 = v129[14] * v134;
          v141 = *(float *)(a3 + 408);
          v142 = v139 + v140;
          v143 = v129[13];
          *(float *)&v144 = (float)(v142 + v138) + v129[18];
          v145 = *(float *)(a3 + 424);
          fAngleInRadians.m_el[2].mVec128.m128_u64[1] = v144;
          v146 = *(float *)(a3 + 440);
          v147 = (float)((float)(v143 * v145) + (float)(v129[14] * v146)) + (float)(v129[12] * v141);
          fAngleInRadians.m_el[0].mVec128.m128_i32[2] = *(_DWORD *)(a3 + 404);
          v148 = v129[13];
          v306.m_el[0].mVec128.m128_f32[0] = v147;
          v149 = *(float *)(a3 + 420);
          *(float *)&v303 = v141;
          v150 = *(float *)(a3 + 436);
          fAngleInRadians.m_el[1].mVec128.m128_f32[1] = v149;
          v151 = (float)(v148 * v149) + (float)(v129[14] * v150);
          v152 = *(float *)(a3 + 416);
          v305 = v150;
          v153 = *(float *)(a3 + 432);
          v315 = v151 + (float)(fAngleInRadians.m_el[0].mVec128.m128_f32[2] * v129[12]);
          fAngleInRadians.m_el[1].mVec128.m128_i32[0] = *(_DWORD *)(a3 + 400);
          v154 = v129[13] * v152;
          fAngleInRadians.m_el[1].mVec128.m128_f32[3] = v152;
          v155 = v129[14] * v153;
          fAngleInRadians.m_el[0].mVec128.m128_f32[1] = v153;
          v318 = (float)(v154 + v155) + (float)(fAngleInRadians.m_el[1].mVec128.m128_f32[0] * v129[12]);
          v156 = v129[10] * v305;
          v319 = (float)((float)(v129[9] * v145) + (float)(v129[10] * v146)) + (float)(*(float *)&v303 * v129[8]);
          v157 = (float)((float)(v129[9] * fAngleInRadians.m_el[1].mVec128.m128_f32[1]) + v156)
               + (float)(fAngleInRadians.m_el[0].mVec128.m128_f32[2] * v129[8]);
          v158 = v129[10] * fAngleInRadians.m_el[0].mVec128.m128_f32[1];
          v317 = v157;
          v316 = (float)((float)(v129[9] * fAngleInRadians.m_el[1].mVec128.m128_f32[3]) + v158)
               + (float)(fAngleInRadians.m_el[1].mVec128.m128_f32[0] * v129[8]);
          *(float *)&v303 = (float)((float)(v132 * *(float *)&v303) + (float)(v131 * v145)) + (float)(v133 * v146);
          v305 = (float)((float)(v132 * fAngleInRadians.m_el[0].mVec128.m128_f32[2])
                       + (float)(v131 * fAngleInRadians.m_el[1].mVec128.m128_f32[1]))
               + (float)(v133 * v305);
          fAngleInRadians.m_el[0].mVec128.m128_f32[1] = (float)((float)(v132
                                                                      * fAngleInRadians.m_el[1].mVec128.m128_f32[0])
                                                              + (float)(v131
                                                                      * fAngleInRadians.m_el[1].mVec128.m128_f32[3]))
                                                      + (float)(v133 * fAngleInRadians.m_el[0].mVec128.m128_f32[1]);
          btMatrix3x3::setValue(
            (btMatrix3x3 *)&fAngleInRadians.m_el[0].m_floats[1],
            (int)&v330,
            &v305,
            (float *)&v303,
            &v316,
            &v317,
            &v319,
            &v318,
            &v315,
            (const float *)&v306,
            v298);
        }
        *(unsigned __int64 *)((char *)v306.m_el[1].mVec128.m128_u64 + 4) = v330;
        v306.m_el[1].mVec128.m128_i32[3] = v331;
        v306.m_el[2] = (btVector3)v332.mVec128;
        v307 = v333;
        v308 = v334;
        v309 = v335;
        v310 = v336;
        v311 = v337;
        v312.mVec128 = (__m128)fAngleInRadians.m_el[2];
        v191 = constraint->__vftable;
        v356.mVec128 = (__m128)fAngleInRadians.m_el[2];
        v326 = v330;
        v327 = v332.mVec128.m128_i32[1];
        v322 = HIDWORD(v330);
        v328 = v334;
        v323 = v332.mVec128.m128_i32[2];
        v329 = 0;
        v324 = v335;
        v325 = 0;
        v192 = ((int (__thiscall *)(btTypedConstraint *, int))v191->getInfo1)(constraint, v299);
        fAngleInRadians.m_el[0].mVec128.m128_f32[0] = 10.0;
        v303 = 1;
        v346 = 0;
        v347 = 0;
        v348 = 0;
        v349 = 0;
        (*(void (__thiscall **)(int, _UNKNOWN **))(*(_DWORD *)v192 + 60))(v192, &retaddr);
      }
      break;
    default:
      if ( *(_DWORD *)(a3 + 4) != 6 )
      {
        if ( *(_DWORD *)(a3 + 4) == 7 )
        {
          v330 = *(_QWORD *)(a3 + 912);
          v331 = *(_DWORD *)(a3 + 920);
          v332.mVec128 = *(__m128 *)(a3 + 924);
          v333 = *(float *)(a3 + 940);
          v334 = *(float *)(a3 + 944);
          v335 = *(float *)(a3 + 948);
          v336 = *(float *)(a3 + 952);
          v337 = *(_DWORD *)(a3 + 956);
          v338 = *(_DWORD *)(a3 + 960);
          v339 = *(_DWORD *)(a3 + 964);
          v340 = *(_DWORD *)(a3 + 968);
          v341 = *(_DWORD *)(a3 + 972);
          if ( v302 )
          {
            v23 = ((int (__thiscall *)(btTypedConstraint *))constraint->getInfo1)(constraint);
            (*(void (__thiscall **)(int, unsigned __int64 *, int))(*(_DWORD *)v23 + 56))(
              v23,
              &v330,
              fAngleInRadians.m_el[0].mVec128.m128_i32[3]);
          }
          v330 = *(_QWORD *)(a3 + 976);
          v331 = *(_DWORD *)(a3 + 984);
          v332.mVec128 = *(__m128 *)(a3 + 988);
          v333 = *(float *)(a3 + 1004);
          v334 = *(float *)(a3 + 1008);
          v335 = *(float *)(a3 + 1012);
          v336 = *(float *)(a3 + 1016);
          v337 = *(_DWORD *)(a3 + 1020);
          v338 = *(_DWORD *)(a3 + 1024);
          v339 = *(_DWORD *)(a3 + 1028);
          v340 = *(_DWORD *)(a3 + 1032);
          v341 = *(_DWORD *)(a3 + 1036);
          if ( v302 )
          {
            v24 = ((int (__thiscall *)(btTypedConstraint *))constraint->getInfo1)(constraint);
            (*(void (__thiscall **)(int, unsigned __int64 *, int))(*(_DWORD *)v24 + 56))(
              v24,
              &v330,
              fAngleInRadians.m_el[0].mVec128.m128_i32[3]);
          }
          if ( fAngleInRadians.m_el[1].mVec128.m128_i8[11] )
          {
            v25 = a3 + 912;
            if ( !*(_BYTE *)(a3 + 176) )
              v25 = a3 + 976;
            *(unsigned __int64 *)((char *)v306.m_el[1].mVec128.m128_u64 + 4) = *(_QWORD *)v25;
            v306.m_el[1].mVec128.m128_i32[3] = *(_DWORD *)(v25 + 8);
            v306.m_el[2] = *(btVector3 *)(v25 + 12);
            v307 = *(float *)(v25 + 28);
            v308 = *(float *)(v25 + 32);
            v309 = *(float *)(v25 + 36);
            v310 = *(float *)(v25 + 40);
            v311 = *(_DWORD *)(v25 + 44);
            v26 = *(float *)(a3 + 180);
            v312.mVec128 = *(__m128 *)(v25 + 48);
            v27 = (float)(v306.m_el[1].mVec128.m128_f32[3] + v306.m_el[1].mVec128.m128_f32[2]) * 0.0;
            v28 = constraint->__vftable;
            v29 = (float)(v306.m_el[2].mVec128.m128_f32[1] * v26) + v312.mVec128.m128_f32[1];
            v306.m_el[0].mVec128.m128_f32[1] = (float)((float)(v306.m_el[1].mVec128.m128_f32[1] * v26)
                                                     + v312.mVec128.m128_f32[0])
                                             + v27;
            v30 = (float)(v308 * v26) + v312.mVec128.m128_f32[2];
            v31 = *(float *)(a3 + 184);
            v32 = (float)(v306.m_el[2].mVec128.m128_f32[3] + v306.m_el[2].mVec128.m128_f32[2]) * 0.0;
            v306.m_el[0].mVec128.m128_f32[2] = v29 + v32;
            v33 = (float)(v310 + v309) * 0.0;
            v306.m_el[0].mVec128.m128_f32[3] = v30 + v33;
            *(float *)&v320[4] = (float)((float)(v306.m_el[2].mVec128.m128_f32[1] * v31) + v312.mVec128.m128_f32[1])
                               + v32;
            v306.m_el[1].mVec128.m128_i32[0] = 0;
            *(float *)v320 = (float)((float)(v306.m_el[1].mVec128.m128_f32[1] * v31) + v312.mVec128.m128_f32[0]) + v27;
            *(float *)&v320[8] = (float)((float)(v308 * v31) + v312.mVec128.m128_f32[2]) + v33;
            v321 = 0;
            v34 = ((int (__thiscall *)(btTypedConstraint *))v28->getInfo1)(constraint);
            v358 = 0;
            v359 = 0;
            v360 = 0;
            vars0 = 0;
            (*(void (__thiscall **)(int, float *, int *, int *))(*(_DWORD *)v34 + 12))(
              v34,
              &v306.m_el[2].mVec128.m128_f32[2],
              &v327,
              &v358);
            fAngleInRadians.m_el[2].mVec128.m128_f32[2] = *(float *)(a3 + 188);
            v35 = constraint->__vftable;
            fAngleInRadians.m_el[2].mVec128.m128_f32[1] = *(float *)(a3 + 192);
            *((float *)&v330 + 1) = v309;
            v331 = v312.mVec128.m128_i32[1];
            v332.mVec128.m128_u64[1] = __PAIR64__(v312.mVec128.m128_u32[2], LODWORD(v310));
            v332.mVec128.m128_u64[0] = v313;
            v333 = v314;
            v334 = 0.0;
            v36 = ((int (__thiscall *)(btTypedConstraint *))v35->getInfo1)(constraint);
            fAngleInRadians.m_el[0].mVec128.m128_f32[0] = 10.0;
            v303 = 1;
            memset(&v355[5], 0, 12);
            v356.mVec128.m128_i32[0] = 0;
            (*(void (__thiscall **)(int, int))(*(_DWORD *)v36 + 60))(v36, a3 + 1024);
          }
          return;
        }
        if ( *(_DWORD *)(a3 + 4) != 9 )
          return;
      }
      *(unsigned __int64 *)((char *)v306.m_el[1].mVec128.m128_u64 + 4) = *(_QWORD *)(a3 + 1168);
      v306.m_el[1].mVec128.m128_i32[3] = *(_DWORD *)(a3 + 1176);
      v306.m_el[2] = *(btVector3 *)(a3 + 1180);
      v307 = *(float *)(a3 + 1196);
      v308 = *(float *)(a3 + 1200);
      v309 = *(float *)(a3 + 1204);
      v310 = *(float *)(a3 + 1208);
      v311 = *(_DWORD *)(a3 + 1212);
      v312.mVec128 = *(__m128 *)(a3 + 1216);
      if ( v302 )
      {
        v8 = ((int (__thiscall *)(btTypedConstraint *))constraint->getInfo1)(constraint);
        (*(void (__thiscall **)(int, float *, int))(*(_DWORD *)v8 + 56))(
          v8,
          &v306.m_el[1].mVec128.m128_f32[1],
          fAngleInRadians.m_el[0].mVec128.m128_i32[3]);
      }
      *(unsigned __int64 *)((char *)v306.m_el[1].mVec128.m128_u64 + 4) = *(_QWORD *)(a3 + 1232);
      v306.m_el[1].mVec128.m128_i32[3] = *(_DWORD *)(a3 + 1240);
      v306.m_el[2] = *(btVector3 *)(a3 + 1244);
      v307 = *(float *)(a3 + 1260);
      v308 = *(float *)(a3 + 1264);
      v309 = *(float *)(a3 + 1268);
      v310 = *(float *)(a3 + 1272);
      v311 = *(_DWORD *)(a3 + 1276);
      v312.mVec128 = *(__m128 *)(a3 + 1280);
      if ( v302 )
      {
        v9 = ((int (__thiscall *)(btTypedConstraint *))constraint->getInfo1)(constraint);
        (*(void (__thiscall **)(int, float *, int))(*(_DWORD *)v9 + 56))(
          v9,
          &v306.m_el[1].mVec128.m128_f32[1],
          fAngleInRadians.m_el[0].mVec128.m128_i32[3]);
      }
      if ( fAngleInRadians.m_el[1].mVec128.m128_i8[11] )
      {
        fAngleInRadians.m_el[1].mVec128.m128_f32[3] = *(float *)(a3 + 1028);
        v10 = *(float *)(a3 + 1088);
        v306.m_el[1].mVec128.m128_i32[1] = *(_DWORD *)(a3 + 1168);
        fAngleInRadians.m_el[0].mVec128.m128_f32[1] = v10;
        v11 = *(float *)(a3 + 1092);
        v306.m_el[1].mVec128.m128_i32[2] = *(_DWORD *)(a3 + 1172);
        fAngleInRadians.m_el[0].mVec128.m128_f32[0] = v11;
        v306.m_el[1].mVec128.m128_i32[3] = *(_DWORD *)(a3 + 1176);
        v306.m_el[2] = *(btVector3 *)(a3 + 1180);
        v307 = *(float *)(a3 + 1196);
        v308 = *(float *)(a3 + 1200);
        v309 = *(float *)(a3 + 1204);
        v310 = *(float *)(a3 + 1208);
        v311 = *(_DWORD *)(a3 + 1212);
        v12 = constraint->__vftable;
        v312.mVec128 = *(__m128 *)(a3 + 1216);
        v322 = v306.m_el[1].mVec128.m128_i32[3];
        v323 = v306.m_el[2].mVec128.m128_i32[3];
        v324 = v310;
        *(_DWORD *)v320 = v306.m_el[1].mVec128.m128_i32[1];
        v325 = 0;
        *(_QWORD *)&v320[4] = __PAIR64__(LODWORD(v308), v306.m_el[2].mVec128.m128_u32[1]);
        v321 = 0;
        v305 = *(float *)(a3 + 1024);
        v13 = ((int (__thiscall *)(btTypedConstraint *))v12->getInfo1)(constraint);
        memset(v355, 0, 16);
        (*(void (__thiscall **)(int, int, int *, _BYTE *, _DWORD, float, int, int, int, _DWORD *, _DWORD))(*(_DWORD *)v13 + 64))(
          v13,
          a3 + 1280,
          &v322,
          v320,
          fAngleInRadians.m_el[0].mVec128.m128_f32[3] * 0.89999998,
          COERCE_FLOAT(LODWORD(v305)),
          fAngleInRadians.m_el[1].mVec128.m128_i32[3],
          fAngleInRadians.m_el[0].mVec128.m128_i32[1],
          fAngleInRadians.m_el[0].mVec128.m128_i32[0],
          v355,
          10.0);
        v14 = *(float *)(a3 + 1304);
        v326 = v306.m_el[1].mVec128.m128_i32[2];
        v327 = v306.m_el[2].mVec128.m128_i32[2];
        v328 = v309;
        v329 = 0;
        v15 = (__m128)*(unsigned int *)(a3 + 1300);
        *(_DWORD *)v320 = v306.m_el[1].mVec128.m128_i32[2];
        *(_QWORD *)&v320[4] = __PAIR64__(LODWORD(v309), v306.m_el[2].mVec128.m128_u32[2]);
        fAngleInRadians.m_el[0].mVec128.m128_i32[0] = v15.m128_i32[0];
        v321 = 0;
        *(float *)&v303 = v14;
        v16 = (__m128i)_mm_cvtps_pd(v15);
        __libm_sse2_cos(v293);
        *(float *)v16.m128i_i32 = *(double *)v16.m128i_i64;
        fAngleInRadians.m_el[1].mVec128.m128_u64[0] = __PAIR64__(LODWORD(v14), v16.m128i_u32[0]);
        *(double *)v16.m128i_i64 = fAngleInRadians.m_el[0].mVec128.m128_f32[0];
        __libm_sse2_sin(v16);
        fAngleInRadians.m_el[0].mVec128.m128_i32[2] = fAngleInRadians.m_el[0].mVec128.m128_i32[0];
        __libm_sse2_cos(v294);
        *(double *)v16.m128i_i64 = v14;
        __libm_sse2_sin(v16);
        v17 = v306.m_el[2].mVec128.m128_f32[2];
        v18 = v306.m_el[1].mVec128.m128_f32[2];
        v19 = *(double *)v16.m128i_i64;
        *(float *)v16.m128i_i32 = (float)(v306.m_el[2].mVec128.m128_f32[2] * v19)
                                + (float)(v306.m_el[1].mVec128.m128_f32[2] * fAngleInRadians.m_el[1].mVec128.m128_f32[1]);
        v20 = v309;
        *(unsigned __int64 *)((char *)v306.m_el[1].mVec128.m128_u64 + 4) = *(_QWORD *)(a3 + 1232);
        v306.m_el[1].mVec128.m128_i32[3] = *(_DWORD *)(a3 + 1240);
        v306.m_el[2] = *(btVector3 *)(a3 + 1244);
        v307 = *(float *)(a3 + 1260);
        v308 = *(float *)(a3 + 1264);
        v309 = *(float *)(a3 + 1268);
        v310 = *(float *)(a3 + 1272);
        v311 = *(_DWORD *)(a3 + 1276);
        v312.mVec128.m128_u64[0] = *(_QWORD *)(a3 + 1280);
        v312.mVec128.m128_i32[2] = *(_DWORD *)(a3 + 1288);
        fAngleInRadians.m_el[2].mVec128.m128_f32[1] = (float)(v17 * fAngleInRadians.m_el[1].mVec128.m128_f32[1])
                                                    - (float)(v18 * v19);
        v312.mVec128.m128_i32[3] = *(_DWORD *)(a3 + 1292);
        fAngleInRadians.m_el[2].mVec128.m128_f32[0] = (float)(*(float *)v16.m128i_i32
                                                            * fAngleInRadians.m_el[1].mVec128.m128_f32[0])
                                                    - (float)(v20 * fAngleInRadians.m_el[0].mVec128.m128_f32[0]);
        fAngleInRadians.m_el[2].mVec128.m128_f32[2] = (float)(v20 * fAngleInRadians.m_el[1].mVec128.m128_f32[0])
                                                    + (float)(*(float *)v16.m128i_i32
                                                            * fAngleInRadians.m_el[0].mVec128.m128_f32[0]);
        v306.m_el[0].mVec128.m128_i32[1] = v306.m_el[1].mVec128.m128_i32[1] ^ _mask__NegFloat_;
        v306.m_el[0].mVec128.m128_i32[2] = v306.m_el[2].mVec128.m128_i32[1] ^ _mask__NegFloat_;
        v306.m_el[0].mVec128.m128_i32[3] = LODWORD(v308) ^ _mask__NegFloat_;
        v21 = *(float *)(a3 + 964);
        v306.m_el[1].mVec128.m128_i32[0] = 0;
        fAngleInRadians.m_el[0].mVec128.m128_i32[1] = *(_DWORD *)(a3 + 960);
        fAngleInRadians.m_el[0].mVec128.m128_f32[0] = v21;
        if ( fAngleInRadians.m_el[0].mVec128.m128_f32[1] <= v21 )
        {
          if ( v21 <= fAngleInRadians.m_el[0].mVec128.m128_f32[1] )
          {
LABEL_26:
            *(unsigned __int64 *)((char *)v306.m_el[1].mVec128.m128_u64 + 4) = *(_QWORD *)(a3 + 1168);
            v306.m_el[1].mVec128.m128_i32[3] = *(_DWORD *)(a3 + 1176);
            v306.m_el[2] = *(btVector3 *)(a3 + 1180);
            v307 = *(float *)(a3 + 1196);
            v308 = *(float *)(a3 + 1200);
            v309 = *(float *)(a3 + 1204);
            v310 = *(float *)(a3 + 1208);
            v311 = *(_DWORD *)(a3 + 1212);
            v312.mVec128 = *(__m128 *)(a3 + 1216);
            v356.mVec128.m128_u64[0] = *(_QWORD *)(a3 + 752);
            v37 = constraint->__vftable;
            v356.mVec128.m128_u64[1] = *(_QWORD *)(a3 + 760);
            v357 = *(_DWORD *)(a3 + 768);
            v358 = *(_DWORD *)(a3 + 772);
            v359 = *(_DWORD *)(a3 + 776);
            v360 = *(_DWORD *)(a3 + 780);
            v38 = ((int (__thiscall *)(btTypedConstraint *))v37->getInfo1)(constraint);
            v349 = 0;
            v350 = 0;
            v351 = 0;
            v352 = 0;
            (*(void (__thiscall **)(int, btVector3 *, int *, float *, int *))(*(_DWORD *)v38 + 68))(
              v38,
              &v356,
              &v357,
              &v306.m_el[1].mVec128.m128_f32[1],
              &v349);
            return;
          }
          v22 = ((int (__thiscall *)(btTypedConstraint *, int, int))constraint->getInfo1)(constraint, v295, v301);
          v348 = 0;
          v349 = 0;
          v350 = 0;
          v351 = 0;
        }
        else
        {
          v22 = ((int (__thiscall *)(btTypedConstraint *, int, int))constraint->getInfo1)(constraint, v295, v301);
          v342 = 0;
          v343 = 0;
          v344 = 0;
          v345 = 0;
        }
        (*(void (__thiscall **)(int, int, btVector3 *, btMatrix3x3 *))(*(_DWORD *)v22 + 60))(
          v22,
          a3 + 1280,
          &v306.m_el[2],
          &v306);
        goto LABEL_26;
      }
      break;
  }
}
