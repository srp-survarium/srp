void __thiscall btConeTwistConstraint::solveConstraintObsolete(
        btConeTwistConstraint *this,
        btRigidBody *bodyA,
        btRigidBody *bodyB,
        float timeStep)
{
  bool v5; // zf
  float *m_rbA; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float *m_rbB; // ecx
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm3_4
  btRigidBody *v14; // edi
  float v15; // xmm6_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm6_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float v21; // xmm4_4
  float v22; // xmm2_4
  float v23; // xmm7_4
  float v24; // xmm0_4
  const vostok::math::float4x4 *v25; // xmm1_4
  float v26; // xmm2_4
  int v27; // xmm6_4
  btRigidBody *v28; // esi
  float v29; // xmm2_4
  float v30; // xmm7_4
  int v31; // xmm2_4
  float v32; // xmm7_4
  float v33; // xmm2_4
  float v34; // xmm2_4
  float v35; // xmm7_4
  float v36; // xmm5_4
  float *v37; // ecx
  int v38; // edx
  float v39; // xmm4_4
  float v40; // xmm3_4
  float v41; // xmm1_4
  float v42; // xmm1_4
  float v43; // xmm3_4
  float v44; // xmm4_4
  float *v45; // eax
  float v46; // xmm2_4
  float v47; // xmm5_4
  float v48; // xmm6_4
  float v49; // xmm7_4
  float v50; // xmm6_4
  float v51; // xmm7_4
  float v52; // xmm6_4
  float v53; // xmm7_4
  float v54; // xmm2_4
  float v55; // xmm6_4
  float v56; // xmm7_4
  float v57; // xmm6_4
  float v58; // xmm2_4
  float v59; // xmm5_4
  float v60; // xmm4_4
  float v61; // xmm3_4
  float v62; // xmm3_4
  float v63; // xmm4_4
  float *v64; // eax
  float v65; // xmm1_4
  float v66; // xmm5_4
  float v67; // xmm6_4
  float v68; // xmm3_4
  float v69; // xmm7_4
  float v70; // xmm2_4
  float v71; // xmm2_4
  float v72; // xmm4_4
  float v73; // xmm2_4
  float v74; // xmm3_4
  float v75; // xmm4_4
  btRigidBody *v76; // eax
  unsigned __int64 v77; // xmm2_8
  unsigned __int64 v78; // xmm2_8
  btRigidBody *v79; // eax
  unsigned __int64 v80; // xmm2_8
  float v81; // xmm5_4
  float v82; // xmm4_4
  float v83; // xmm3_4
  float v84; // xmm1_4
  float v85; // xmm1_4
  float v86; // xmm7_4
  float v87; // xmm6_4
  float v88; // xmm3_4
  float *v89; // eax
  float v90; // xmm6_4
  float v91; // xmm4_4
  float v92; // xmm3_4
  float v93; // xmm5_4
  float v94; // xmm7_4
  float v95; // xmm3_4
  float v96; // xmm7_4
  unsigned int v97; // xmm3_4
  unsigned int v98; // xmm0_4
  float v99; // xmm4_4
  float v100; // xmm1_4
  float v101; // xmm7_4
  unsigned int v102; // xmm1_4
  unsigned int v103; // xmm4_4
  __m128i si128; // xmm5
  float v105; // xmm6_4
  btTransform *v106; // eax
  float v107; // xmm6_4
  float v108; // xmm7_4
  float v109; // xmm6_4
  unsigned int v110; // xmm7_4
  float v111; // xmm6_4
  float v112; // xmm6_4
  float v113; // xmm6_4
  float v114; // xmm7_4
  float v115; // xmm4_4
  float v116; // xmm5_4
  float v117; // xmm6_4
  float v118; // xmm1_4
  long double v119; // st7
  float *v120; // eax
  float v121; // xmm2_4
  float v122; // xmm3_4
  float v123; // xmm7_4
  float v124; // xmm1_4
  float v125; // xmm2_4
  long double v126; // st7
  float *v127; // eax
  float v128; // xmm2_4
  float v129; // xmm3_4
  float v130; // xmm7_4
  long double v131; // st7
  float *v132; // eax
  float v133; // xmm1_4
  float v134; // xmm5_4
  float v135; // xmm6_4
  float v136; // xmm0_4
  float v137; // xmm1_4
  float v138; // xmm5_4
  float v139; // xmm6_4
  float *v140; // eax
  float v141; // xmm7_4
  float v142; // xmm5_4
  float v143; // xmm6_4
  float v144; // xmm0_4
  float v145; // xmm1_4
  float v146; // xmm6_4
  float v147; // xmm7_4
  float v148; // xmm5_4
  float v149; // xmm1_4
  float v150; // xmm2_4
  float m_maxMotorImpulse; // xmm3_4
  float v152; // xmm5_4
  int v153; // xmm1_4
  unsigned int v154; // xmm5_4
  unsigned int v155; // xmm0_4
  long double v156; // st7
  float v157; // xmm1_4
  float v158; // xmm2_4
  float *v159; // eax
  float v160; // xmm7_4
  float v161; // xmm5_4
  float v162; // xmm1_4
  float v163; // xmm3_4
  float v164; // xmm4_4
  float v165; // xmm0_4
  float v166; // xmm7_4
  float v167; // xmm0_4
  float v168; // xmm5_4
  float v169; // xmm0_4
  float m_inverseMass; // xmm5_4
  float v171; // xmm5_4
  float v172; // xmm6_4
  float *v173; // eax
  float v174; // xmm5_4
  float v175; // xmm6_4
  float v176; // xmm7_4
  float v177; // xmm2_4
  float v178; // xmm5_4
  float v179; // xmm6_4
  float v180; // xmm7_4
  float v181; // xmm3_4
  float v182; // xmm4_4
  unsigned int v183; // xmm1_4
  unsigned int v184; // xmm2_4
  long double v185; // st7
  float *v186; // eax
  float v187; // xmm6_4
  float v188; // xmm0_4
  float v189; // xmm3_4
  float v190; // xmm6_4
  float v191; // xmm0_4
  float v192; // xmm3_4
  float v193; // xmm0_4
  float v194; // xmm3_4
  float *v195; // eax
  float v196; // xmm4_4
  float v197; // xmm7_4
  float v198; // xmm0_4
  float v199; // xmm3_4
  float v200; // xmm0_4
  float v201; // xmm1_4
  float *v202; // eax
  float v203; // xmm1_4
  float v204; // xmm5_4
  float v205; // xmm6_4
  float v206; // xmm7_4
  float v207; // xmm2_4
  float v208; // xmm3_4
  float v209; // xmm4_4
  float v210; // xmm7_4
  float v211; // xmm7_4
  float v212; // xmm2_4
  float v213; // xmm3_4
  float *v214; // eax
  float v215; // xmm7_4
  float v216; // xmm2_4
  float v217; // xmm3_4
  float v218; // xmm4_4
  float v219; // xmm7_4
  float v220; // xmm2_4
  float v221; // xmm3_4
  float v222; // xmm5_4
  float v223; // xmm2_4
  float v224; // xmm3_4
  float v225; // xmm3_4
  float v226; // xmm1_4
  float v227; // xmm5_4
  float v228; // xmm2_4
  float v229; // xmm2_4
  float v230; // xmm3_4
  float v231; // xmm4_4
  float v232; // xmm1_4
  int v233; // xmm6_4
  float v234; // xmm7_4
  unsigned int v235; // xmm1_4
  float v236; // xmm2_4
  float v237; // xmm3_4
  int v238; // xmm4_4
  float v239; // xmm1_4
  float v240; // xmm2_4
  float m_accSwingLimitImpulse; // xmm2_4
  float v242; // xmm3_4
  float *p_X; // eax
  float v244; // xmm0_4
  float v245; // xmm0_4
  float v246; // xmm2_4
  float v247; // xmm3_4
  float v248; // xmm1_4
  float v249; // xmm0_4
  float v250; // xmm4_4
  float v251; // xmm2_4
  float *v252; // eax
  float v253; // xmm1_4
  float v254; // xmm2_4
  float v255; // xmm3_4
  float v256; // xmm6_4
  float v257; // xmm7_4
  float v258; // xmm4_4
  float v259; // xmm5_4
  float v260; // xmm0_4
  float v261; // xmm1_4
  float v262; // xmm2_4
  float v263; // xmm3_4
  float v264; // xmm7_4
  float v265; // xmm7_4
  float v266; // xmm1_4
  float v267; // xmm2_4
  float *v268; // eax
  float v269; // xmm7_4
  float v270; // xmm1_4
  float v271; // xmm3_4
  float v272; // xmm2_4
  float v273; // xmm7_4
  float v274; // xmm1_4
  float v275; // xmm3_4
  float v276; // xmm4_4
  float v277; // xmm1_4
  float v278; // xmm2_4
  float v279; // xmm3_4
  float v280; // xmm1_4
  float v281; // xmm2_4
  float m_accTwistLimitImpulse; // xmm3_4
  float v283; // xmm2_4
  float *v284; // eax
  float v285; // xmm1_4
  float *v286; // eax
  float v287; // xmm4_4
  float v288; // xmm5_4
  float v289; // xmm6_4
  float v290; // xmm7_4
  float v291; // xmm1_4
  float v292; // xmm3_4
  float v293; // xmm5_4
  float v294; // xmm6_4
  float v295; // xmm7_4
  float v296; // xmm4_4
  float v297; // xmm3_4
  float v298; // xmm4_4
  float *v299; // eax
  float v300; // xmm7_4
  float v301; // xmm3_4
  float v302; // xmm4_4
  float v303; // xmm5_4
  float v304; // xmm6_4
  float v305; // xmm1_4
  float v306; // xmm4_4
  float v307; // xmm5_4
  float v308; // xmm6_4
  float v309; // xmm7_4
  float v310; // xmm2_4
  float v311; // xmm2_4
  float v312; // xmm3_4
  float v313; // [esp+45CCh] [ebp-274h] BYREF
  float v314; // [esp+45D0h] [ebp-270h]
  float v315; // [esp+45D4h] [ebp-26Ch]
  float _X; // [esp+45D8h] [ebp-268h] BYREF
  float v317; // [esp+45DCh] [ebp-264h]
  btVector3 v318; // [esp+45E0h] [ebp-260h] BYREF
  __m128i v319; // [esp+45F0h] [ebp-250h] BYREF
  __m128i v320; // [esp+4600h] [ebp-240h] BYREF
  float v321; // [esp+461Ch] [ebp-224h]
  btVector3 angVel; // [esp+4620h] [ebp-220h] BYREF
  float v323; // [esp+4638h] [ebp-208h]
  float v324; // [esp+463Ch] [ebp-204h]
  float v325; // [esp+4640h] [ebp-200h]
  float v326; // [esp+4644h] [ebp-1FCh]
  float v327; // [esp+4648h] [ebp-1F8h]
  float v328; // [esp+464Ch] [ebp-1F4h]
  btVector3 linvel; // [esp+4650h] [ebp-1F0h] BYREF
  float v330; // [esp+466Ch] [ebp-1D4h]
  __m128i v331; // [esp+4670h] [ebp-1D0h]
  __m128i v332; // [esp+4680h] [ebp-1C0h] BYREF
  float v333; // [esp+4694h] [ebp-1ACh]
  float v334; // [esp+4698h] [ebp-1A8h]
  float v335; // [esp+469Ch] [ebp-1A4h]
  btTransform v336; // [esp+46A0h] [ebp-1A0h] BYREF
  btTransform transform1; // [esp+46E0h] [ebp-160h] BYREF
  btVector3 angvel; // [esp+4720h] [ebp-120h] BYREF
  btTransform predictedTransform; // [esp+4730h] [ebp-110h] BYREF
  btVector3 v340; // [esp+4770h] [ebp-D0h] BYREF
  btTransform v341; // [esp+4780h] [ebp-C0h] BYREF
  btTransform curTrans; // [esp+47C0h] [ebp-80h] BYREF
  btTransform transform0; // [esp+4800h] [ebp-40h] BYREF

  if ( this->m_useSolveConstraintObsolete )
  {
    v5 = !this->m_angularOnly;
    m_rbA = (float *)this->m_rbA;
    v7 = this->m_rbAFrame.m_origin.mVec128.m128_f32[2];
    v8 = this->m_rbAFrame.m_origin.mVec128.m128_f32[1];
    v9 = this->m_rbAFrame.m_origin.mVec128.m128_f32[0];
    m_rbB = (float *)this->m_rbB;
    v11 = m_rbA[10] * v7;
    v12 = m_rbA[9] * v8;
    v13 = (float)((float)((float)(m_rbA[5] * v8) + (float)(m_rbA[6] * v7))
                + (float)(this->m_rbAFrame.m_origin.mVec128.m128_f32[0] * m_rbA[4]))
        + m_rbA[16];
    v14 = bodyA;
    v15 = (float)(m_rbA[13] * v8) + (float)(m_rbA[14] * v7);
    v16 = this->m_rbBFrame.m_origin.mVec128.m128_f32[2];
    v17 = this->m_rbBFrame.m_origin.mVec128.m128_f32[1];
    v18 = (float)(v15 + (float)(m_rbA[12] * v9)) + m_rbA[18];
    v19 = (float)(v12 + v11) + (float)(m_rbA[8] * v9);
    v20 = this->m_rbBFrame.m_origin.mVec128.m128_f32[0];
    v21 = v19 + m_rbA[17];
    v22 = (float)((float)((float)(m_rbB[5] * v17) + (float)(m_rbB[6] * v16)) + (float)(m_rbB[4] * v20)) + m_rbB[16];
    v23 = (float)((float)((float)(m_rbB[9] * v17) + (float)(m_rbB[10] * v16)) + (float)(m_rbB[8] * v20)) + m_rbB[17];
    v24 = (float)(m_rbB[13] * v17) + (float)(m_rbB[14] * v16);
    v25 = clear_value;
    *(float *)&v332.m128i_i32[2] = (float)(v24 + (float)(m_rbB[12] * v20)) + m_rbB[18];
    v340.mVec128.m128_f32[2] = v18;
    v332.m128i_i64[0] = __PAIR64__(LODWORD(v23), LODWORD(v22));
    if ( v5 )
    {
      v26 = v22 - m_rbB[16];
      *(float *)&v27 = v18 - m_rbA[18];
      *(float *)&v319.m128i_i32[1] = v23 - m_rbB[17];
      linvel.mVec128.m128_f32[1] = bodyA->m_angularVelocity.mVec128.m128_f32[1]
                                 + bodyA->m_deltaAngularVelocity.mVec128.m128_f32[1];
      v28 = bodyB;
      linvel.mVec128.m128_f32[2] = bodyA->m_angularVelocity.mVec128.m128_f32[2]
                                 + bodyA->m_deltaAngularVelocity.mVec128.m128_f32[2];
      v313 = linvel.mVec128.m128_f32[1] * *(float *)&v27;
      *(float *)v319.m128i_i32 = v26;
      *(float *)&v319.m128i_i32[2] = *(float *)&v332.m128i_i32[2] - m_rbB[18];
      v29 = bodyA->m_angularVelocity.mVec128.m128_f32[0] + bodyA->m_deltaAngularVelocity.mVec128.m128_f32[0];
      *(float *)v320.m128i_i32 = v13 - m_rbA[16];
      *(float *)&v320.m128i_i32[1] = v21 - m_rbA[17];
      *(float *)v331.m128i_i32 = (float)(linvel.mVec128.m128_f32[1] * *(float *)&v27)
                               - (float)(linvel.mVec128.m128_f32[2] * *(float *)&v320.m128i_i32[1]);
      v30 = bodyA->m_linearVelocity.mVec128.m128_f32[1] + bodyA->m_deltaLinearVelocity.mVec128.m128_f32[1];
      *(float *)&v331.m128i_i32[1] = (float)(*(float *)v320.m128i_i32 * linvel.mVec128.m128_f32[2])
                                   - (float)(v29 * *(float *)&v27);
      *(float *)&v31 = (float)(v29 * *(float *)&v320.m128i_i32[1])
                     - (float)(*(float *)v320.m128i_i32 * linvel.mVec128.m128_f32[1]);
      linvel.mVec128.m128_f32[0] = (float)(bodyA->m_linearVelocity.mVec128.m128_f32[0]
                                         + bodyA->m_deltaLinearVelocity.mVec128.m128_f32[0])
                                 + *(float *)v331.m128i_i32;
      v318.mVec128.m128_f32[1] = bodyB->m_angularVelocity.mVec128.m128_f32[1]
                               + bodyB->m_deltaAngularVelocity.mVec128.m128_f32[1];
      v313 = v318.mVec128.m128_f32[1] * *(float *)&v319.m128i_i32[2];
      linvel.mVec128.m128_f32[1] = v30 + *(float *)&v331.m128i_i32[1];
      v32 = bodyB->m_angularVelocity.mVec128.m128_f32[2] + bodyB->m_deltaAngularVelocity.mVec128.m128_f32[2];
      v331.m128i_i32[2] = v31;
      v33 = (float)(bodyA->m_linearVelocity.mVec128.m128_f32[2] + bodyA->m_deltaLinearVelocity.mVec128.m128_f32[2])
          + *(float *)&v31;
      v318.mVec128.m128_f32[2] = v32;
      linvel.mVec128.m128_f32[2] = v33;
      v34 = bodyB->m_angularVelocity.mVec128.m128_f32[0] + bodyB->m_deltaAngularVelocity.mVec128.m128_f32[0];
      v313 = *(float *)v319.m128i_i32 * v32;
      *(float *)v331.m128i_i32 = (float)(v318.mVec128.m128_f32[1] * *(float *)&v319.m128i_i32[2])
                               - (float)(v32 * *(float *)&v319.m128i_i32[1]);
      v320.m128i_i32[2] = v27;
      *(float *)&v331.m128i_i32[1] = (float)(*(float *)v319.m128i_i32 * v32)
                                   - (float)(v34 * *(float *)&v319.m128i_i32[2]);
      v35 = (float)(bodyB->m_linearVelocity.mVec128.m128_f32[1] + bodyB->m_deltaLinearVelocity.mVec128.m128_f32[1])
          + *(float *)&v331.m128i_i32[1];
      v36 = (float)(bodyB->m_linearVelocity.mVec128.m128_f32[0] + bodyB->m_deltaLinearVelocity.mVec128.m128_f32[0])
          + *(float *)v331.m128i_i32;
      angVel.mVec128.m128_f32[2] = (float)(bodyB->m_linearVelocity.mVec128.m128_f32[2]
                                         + bodyB->m_deltaLinearVelocity.mVec128.m128_f32[2])
                                 + (float)((float)(v34 * *(float *)&v319.m128i_i32[1])
                                         - (float)(*(float *)v319.m128i_i32 * v318.mVec128.m128_f32[1]));
      v318.mVec128.m128_f32[0] = linvel.mVec128.m128_f32[0] - v36;
      v318.mVec128.m128_f32[1] = linvel.mVec128.m128_f32[1] - v35;
      v318.mVec128.m128_f32[2] = linvel.mVec128.m128_f32[2] - angVel.mVec128.m128_f32[2];
      *(float *)&v331.m128i_i32[2] = v340.mVec128.m128_f32[2] - *(float *)&v332.m128i_i32[2];
      *(float *)v331.m128i_i32 = v13 - *(float *)v332.m128i_i32;
      *(float *)&v331.m128i_i32[1] = v21 - *(float *)&v332.m128i_i32[1];
      v313 = *(float *)&clear_value / timeStep;
      v37 = &this->m_jac[0].m_linearJointAxis.mVec128.m128_f32[2];
      v38 = 3;
      while ( 1 )
      {
        v39 = *v37;
        v40 = *(float *)&v25 / v37[18];
        v41 = *(v37 - 2);
        _X = *(v37 - 1);
        v42 = (float)((float)((float)((float)-(float)((float)((float)(v41 * *(float *)v331.m128i_i32)
                                                            + (float)(_X * *(float *)&v331.m128i_i32[1]))
                                                    + (float)(v39 * *(float *)&v331.m128i_i32[2]))
                                    * v313)
                            * v40)
                    * 0.30000001)
            - (float)((float)((float)((float)(v41 * v318.mVec128.m128_f32[0]) + (float)(_X * v318.mVec128.m128_f32[1]))
                            + (float)(v39 * v318.mVec128.m128_f32[2]))
                    * v40);
        this->m_appliedImpulse = this->m_appliedImpulse + v42;
        v43 = *v37;
        v44 = *(v37 - 1);
        v45 = (float *)this->m_rbA;
        v46 = (float)(*v37 * *(float *)&v320.m128i_i32[1]) - (float)(v44 * *(float *)&v27);
        v47 = *(v37 - 2);
        linvel.mVec128.m128_f32[1] = (float)(v47 * *(float *)&v27) - (float)(*v37 * *(float *)v320.m128i_i32);
        linvel.mVec128.m128_f32[2] = (float)(v44 * *(float *)v320.m128i_i32)
                                   - (float)(v47 * *(float *)&v320.m128i_i32[1]);
        *(float *)v332.m128i_i32 = (float)(v43 * *(float *)&v319.m128i_i32[1])
                                 - (float)(v44 * *(float *)&v319.m128i_i32[2]);
        *(float *)&v332.m128i_i32[1] = (float)(v47 * *(float *)&v319.m128i_i32[2])
                                     - (float)(v43 * *(float *)v319.m128i_i32);
        v315 = v44 * *(float *)v319.m128i_i32;
        v48 = v45[70] * linvel.mVec128.m128_f32[2];
        *(float *)&v332.m128i_i32[2] = (float)(v44 * *(float *)v319.m128i_i32)
                                     - (float)(v47 * *(float *)&v319.m128i_i32[1]);
        v49 = v45[69] * linvel.mVec128.m128_f32[1];
        v315 = v48;
        v50 = (float)(v48 + v49) + (float)(v45[68] * v46);
        v51 = v45[73] * linvel.mVec128.m128_f32[1];
        angVel.mVec128.m128_f32[0] = v50;
        v315 = v45[74] * linvel.mVec128.m128_f32[2];
        v52 = v315 + v51;
        v53 = v46 * v45[72];
        v54 = v46 * v45[76];
        v55 = v52 + v53;
        v56 = v45[77] * linvel.mVec128.m128_f32[1];
        angVel.mVec128.m128_f32[1] = v55;
        v315 = v45[78] * linvel.mVec128.m128_f32[2];
        v57 = (float)(v315 + v56) + v54;
        v58 = v45[88];
        v59 = v47 * v58;
        v60 = v44 * v58;
        v61 = v43 * v58;
        if ( bodyA->m_inverseMass != 0.0 )
        {
          bodyA->m_deltaLinearVelocity.mVec128.m128_f32[1] = bodyA->m_deltaLinearVelocity.mVec128.m128_f32[1]
                                                           + (float)(v60 * v42);
          bodyA->m_deltaLinearVelocity.mVec128.m128_f32[2] = bodyA->m_deltaLinearVelocity.mVec128.m128_f32[2]
                                                           + (float)(v61 * v42);
          bodyA->m_deltaLinearVelocity.mVec128.m128_f32[0] = (float)(v59 * v42)
                                                           + bodyA->m_deltaLinearVelocity.mVec128.m128_f32[0];
          v62 = (float)((float)(bodyA->m_angularFactor.mVec128.m128_f32[1] * v42) * angVel.mVec128.m128_f32[1])
              + bodyA->m_deltaAngularVelocity.mVec128.m128_f32[1];
          v63 = (float)((float)(bodyA->m_angularFactor.mVec128.m128_f32[2] * v42) * v57)
              + bodyA->m_deltaAngularVelocity.mVec128.m128_f32[2];
          bodyA->m_deltaAngularVelocity.mVec128.m128_f32[0] = bodyA->m_deltaAngularVelocity.mVec128.m128_f32[0]
                                                            + (float)((float)(bodyA->m_angularFactor.mVec128.m128_f32[0]
                                                                            * v42)
                                                                    * angVel.mVec128.m128_f32[0]);
          bodyA->m_deltaAngularVelocity.mVec128.m128_f32[1] = v62;
          bodyA->m_deltaAngularVelocity.mVec128.m128_f32[2] = v63;
        }
        v64 = (float *)this->m_rbB;
        v65 = -v42;
        v66 = (float)((float)(v64[70] * *(float *)&v332.m128i_i32[2]) + (float)(v64[69] * *(float *)&v332.m128i_i32[1]))
            + (float)(*(float *)v332.m128i_i32 * v64[68]);
        v67 = (float)((float)(v64[74] * *(float *)&v332.m128i_i32[2]) + (float)(v64[73] * *(float *)&v332.m128i_i32[1]))
            + (float)(*(float *)v332.m128i_i32 * v64[72]);
        v68 = v64[88];
        v69 = (float)((float)(v64[78] * *(float *)&v332.m128i_i32[2]) + (float)(v64[77] * *(float *)&v332.m128i_i32[1]))
            + (float)(*(float *)v332.m128i_i32 * v64[76]);
        v70 = *(v37 - 2);
        v340.mVec128.m128_f32[1] = *(v37 - 1) * v68;
        v71 = v70 * v68;
        v72 = *v37 * v68;
        if ( bodyB->m_inverseMass != 0.0 )
        {
          bodyB->m_deltaLinearVelocity.mVec128.m128_f32[0] = (float)(v71 * v65)
                                                           + bodyB->m_deltaLinearVelocity.mVec128.m128_f32[0];
          v73 = bodyB->m_deltaLinearVelocity.mVec128.m128_f32[1];
          angvel.mVec128.m128_f32[1] = v65 * v340.mVec128.m128_f32[1];
          bodyB->m_deltaLinearVelocity.mVec128.m128_f32[1] = v73 + (float)(v65 * v340.mVec128.m128_f32[1]);
          bodyB->m_deltaLinearVelocity.mVec128.m128_f32[2] = bodyB->m_deltaLinearVelocity.mVec128.m128_f32[2]
                                                           + (float)(v65 * v72);
          v74 = (float)((float)(bodyB->m_angularFactor.mVec128.m128_f32[1] * v65) * v67)
              + bodyB->m_deltaAngularVelocity.mVec128.m128_f32[1];
          v75 = (float)((float)(bodyB->m_angularFactor.mVec128.m128_f32[2] * v65) * v69)
              + bodyB->m_deltaAngularVelocity.mVec128.m128_f32[2];
          bodyB->m_deltaAngularVelocity.mVec128.m128_f32[0] = bodyB->m_deltaAngularVelocity.mVec128.m128_f32[0]
                                                            + (float)((float)(v65
                                                                            * bodyB->m_angularFactor.mVec128.m128_f32[0])
                                                                    * v66);
          bodyB->m_deltaAngularVelocity.mVec128.m128_f32[1] = v74;
          bodyB->m_deltaAngularVelocity.mVec128.m128_f32[2] = v75;
        }
        v25 = clear_value;
        v37 += 24;
        if ( !--v38 )
          break;
        v27 = v320.m128i_i32[2];
      }
    }
    else
    {
      v28 = bodyB;
    }
    if ( this->m_bMotorEnabled )
    {
      v76 = this->m_rbA;
      curTrans.m_basis.m_el[0].mVec128.m128_u64[0] = v76->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
      curTrans.m_basis.m_el[0].mVec128.m128_u64[1] = v76->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
      curTrans.m_basis.m_el[1] = v76->m_worldTransform.m_basis.m_el[1];
      curTrans.m_basis.m_el[2].mVec128.m128_u64[0] = v76->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[0];
      v77 = v76->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[1];
      v76 = (btRigidBody *)((char *)v76 + 16);
      curTrans.m_basis.m_el[2].mVec128.m128_u64[1] = v77;
      curTrans.m_origin.mVec128.m128_u64[0] = v76->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[0];
      v78 = v76->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[1];
      v79 = this->m_rbB;
      curTrans.m_origin.mVec128.m128_u64[1] = v78;
      transform0.m_basis.m_el[0].mVec128.m128_u64[0] = v79->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
      transform0.m_basis.m_el[0].mVec128.m128_u64[1] = v79->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
      transform0.m_basis.m_el[1].mVec128.m128_u64[0] = v79->m_worldTransform.m_basis.m_el[1].mVec128.m128_u64[0];
      v80 = v79->m_worldTransform.m_basis.m_el[1].mVec128.m128_u64[1];
      v79 = (btRigidBody *)((char *)v79 + 16);
      transform0.m_basis.m_el[1].mVec128.m128_u64[1] = v80;
      transform0.m_basis.m_el[2] = v79->m_worldTransform.m_basis.m_el[1];
      transform0.m_origin = v79->m_worldTransform.m_basis.m_el[2];
      *(float *)v319.m128i_i32 = bodyA->m_angularVelocity.mVec128.m128_f32[0]
                               + bodyA->m_deltaAngularVelocity.mVec128.m128_f32[0];
      *(float *)&v319.m128i_i32[1] = bodyA->m_angularVelocity.mVec128.m128_f32[1]
                                   + bodyA->m_deltaAngularVelocity.mVec128.m128_f32[1];
      *(float *)&v319.m128i_i32[2] = bodyA->m_angularVelocity.mVec128.m128_f32[2]
                                   + bodyA->m_deltaAngularVelocity.mVec128.m128_f32[2];
      v319.m128i_i32[3] = 0;
      angvel.mVec128 = (__m128)_mm_load_si128(&v319);
      *(float *)v332.m128i_i32 = v28->m_angularVelocity.mVec128.m128_f32[0]
                               + v28->m_deltaAngularVelocity.mVec128.m128_f32[0];
      *(float *)&v332.m128i_i32[1] = v28->m_angularVelocity.mVec128.m128_f32[1]
                                   + v28->m_deltaAngularVelocity.mVec128.m128_f32[1];
      *(float *)&v332.m128i_i32[2] = v28->m_angularVelocity.mVec128.m128_f32[2]
                                   + v28->m_deltaAngularVelocity.mVec128.m128_f32[2];
      v332.m128i_i32[3] = 0;
      v340.mVec128 = (__m128)_mm_load_si128(&v332);
      predictedTransform.m_basis.m_el[0].mVec128.m128_u64[0] = (unsigned int)v25;
      memset(&predictedTransform.m_basis.m_el[0].m_floats[2], 0, 12);
      *(unsigned __int64 *)((char *)predictedTransform.m_basis.m_el[1].mVec128.m128_u64 + 4) = (unsigned int)v25;
      memset(&predictedTransform.m_basis.m_el[1].m_floats[3], 0, 12);
      predictedTransform.m_basis.m_el[2].mVec128.m128_u64[1] = (unsigned int)v25;
      memset(&predictedTransform.m_origin, 0, sizeof(predictedTransform.m_origin));
      memset(&linvel, 0, sizeof(linvel));
      btTransformUtil::integrateTransform(&curTrans, &linvel, &angvel, timeStep, &predictedTransform);
      transform1.m_basis.m_el[0].mVec128.m128_u64[0] = (unsigned int)clear_value;
      memset(&transform1.m_basis.m_el[0].m_floats[2], 0, 12);
      *(unsigned __int64 *)((char *)transform1.m_basis.m_el[1].mVec128.m128_u64 + 4) = (unsigned int)clear_value;
      memset(&transform1.m_basis.m_el[1].m_floats[3], 0, 12);
      transform1.m_basis.m_el[2].mVec128.m128_u64[1] = (unsigned int)clear_value;
      memset(&transform1.m_origin, 0, sizeof(transform1.m_origin));
      btTransformUtil::integrateTransform(&transform0, &linvel, &v340, timeStep, &transform1);
      btMatrix3x3::setRotation((btMatrix3x3 *)&this->m_qTarget, (int)&v336);
      v81 = this->m_rbBFrame.m_basis.m_el[0].mVec128.m128_f32[1];
      v82 = this->m_rbBFrame.m_basis.m_el[0].mVec128.m128_f32[2];
      LODWORD(v80) = this->m_rbBFrame.m_basis.m_el[2].mVec128.m128_i32[2];
      v83 = *(float *)&v80;
      v318.mVec128.m128_f32[0] = (float)((float)((float)(this->m_rbBFrame.m_basis.m_el[0].mVec128.m128_f32[0] + v81)
                                               + v82)
                                       * 0.0)
                               + this->m_rbBFrame.m_origin.mVec128.m128_f32[0];
      v318.mVec128.m128_f32[1] = (float)((float)((float)(this->m_rbBFrame.m_basis.m_el[1].mVec128.m128_f32[2]
                                                       + this->m_rbBFrame.m_basis.m_el[1].mVec128.m128_f32[1])
                                               + this->m_rbBFrame.m_basis.m_el[1].mVec128.m128_f32[0])
                                       * 0.0)
                               + this->m_rbBFrame.m_origin.mVec128.m128_f32[1];
      v84 = this->m_rbBFrame.m_basis.m_el[2].mVec128.m128_f32[1] * v336.m_basis.m_el[1].mVec128.m128_f32[2];
      v318.mVec128.m128_f32[2] = (float)((float)((float)(this->m_rbBFrame.m_basis.m_el[2].mVec128.m128_f32[2]
                                                       + this->m_rbBFrame.m_basis.m_el[2].mVec128.m128_f32[1])
                                               + this->m_rbBFrame.m_basis.m_el[2].mVec128.m128_f32[0])
                                       * 0.0)
                               + this->m_rbBFrame.m_origin.mVec128.m128_f32[2];
      v85 = (float)(v84 + (float)(*(float *)&v80 * v336.m_basis.m_el[2].mVec128.m128_f32[2]))
          + (float)(v336.m_basis.m_el[0].mVec128.m128_f32[2] * this->m_rbBFrame.m_basis.m_el[2].mVec128.m128_f32[0]);
      *(float *)&v80 = this->m_rbBFrame.m_basis.m_el[2].mVec128.m128_f32[1] * v336.m_basis.m_el[1].mVec128.m128_f32[1];
      v315 = v85;
      v327 = (float)(*(float *)&v80 + (float)(v83 * v336.m_basis.m_el[2].mVec128.m128_f32[1]))
           + (float)(this->m_rbBFrame.m_basis.m_el[2].mVec128.m128_f32[0] * v336.m_basis.m_el[0].mVec128.m128_f32[1]);
      v86 = this->m_rbBFrame.m_basis.m_el[1].mVec128.m128_f32[2];
      _X = (float)((float)(this->m_rbBFrame.m_basis.m_el[2].mVec128.m128_f32[1]
                         * v336.m_basis.m_el[1].mVec128.m128_f32[0])
                 + (float)(this->m_rbBFrame.m_basis.m_el[2].mVec128.m128_f32[2]
                         * v336.m_basis.m_el[2].mVec128.m128_f32[0]))
         + (float)(v336.m_basis.m_el[0].mVec128.m128_f32[0] * this->m_rbBFrame.m_basis.m_el[2].mVec128.m128_f32[0]);
      v87 = this->m_rbBFrame.m_basis.m_el[1].mVec128.m128_f32[2];
      v317 = (float)((float)(this->m_rbBFrame.m_basis.m_el[1].mVec128.m128_f32[1]
                           * v336.m_basis.m_el[1].mVec128.m128_f32[2])
                   + (float)(v86 * v336.m_basis.m_el[2].mVec128.m128_f32[2]))
           + (float)(this->m_rbBFrame.m_basis.m_el[1].mVec128.m128_f32[0] * v336.m_basis.m_el[0].mVec128.m128_f32[2]);
      v323 = (float)((float)(this->m_rbBFrame.m_basis.m_el[1].mVec128.m128_f32[1]
                           * v336.m_basis.m_el[1].mVec128.m128_f32[1])
                   + (float)(v87 * v336.m_basis.m_el[2].mVec128.m128_f32[1]))
           + (float)(v336.m_basis.m_el[0].mVec128.m128_f32[1] * this->m_rbBFrame.m_basis.m_el[1].mVec128.m128_f32[0]);
      v313 = (float)((float)(this->m_rbBFrame.m_basis.m_el[1].mVec128.m128_f32[1]
                           * v336.m_basis.m_el[1].mVec128.m128_f32[0])
                   + (float)(v86 * v336.m_basis.m_el[2].mVec128.m128_f32[0]))
           + (float)(v336.m_basis.m_el[0].mVec128.m128_f32[0] * this->m_rbBFrame.m_basis.m_el[1].mVec128.m128_f32[0]);
      v88 = this->m_rbBFrame.m_basis.m_el[0].mVec128.m128_f32[0];
      v333 = (float)((float)(v336.m_basis.m_el[2].mVec128.m128_f32[2] * v82)
                   + (float)(v336.m_basis.m_el[0].mVec128.m128_f32[2] * v88))
           + (float)(v336.m_basis.m_el[1].mVec128.m128_f32[2] * v81);
      v335 = (float)((float)(v336.m_basis.m_el[2].mVec128.m128_f32[1] * v82)
                   + (float)(v336.m_basis.m_el[0].mVec128.m128_f32[1] * v88))
           + (float)(v336.m_basis.m_el[1].mVec128.m128_f32[1] * v81);
      v334 = (float)((float)(v336.m_basis.m_el[1].mVec128.m128_f32[0] * v81)
                   + (float)(v336.m_basis.m_el[2].mVec128.m128_f32[0] * v82))
           + (float)(v336.m_basis.m_el[0].mVec128.m128_f32[0] * v88);
      v89 = (float *)btTransform::inverse(&this->m_rbAFrame, &v341);
      v90 = v89[12];
      v91 = v89[13];
      v92 = v89[14];
      v93 = v313;
      *(float *)v320.m128i_i32 = (float)((float)((float)(v334 * v90) + (float)(v335 * v91)) + (float)(v333 * v92))
                               + v318.mVec128.m128_f32[0];
      *(float *)&v320.m128i_i32[1] = (float)((float)((float)(v313 * v90) + (float)(v323 * v91)) + (float)(v317 * v92))
                                   + v318.mVec128.m128_f32[1];
      v94 = v89[2];
      *(float *)&v320.m128i_i32[2] = (float)((float)((float)(_X * v90) + (float)(v327 * v91)) + (float)(v85 * v92))
                                   + v318.mVec128.m128_f32[2];
      v320.m128i_i32[3] = 0;
      v325 = v89[10];
      v324 = v89[6];
      v330 = v94;
      v95 = (float)(_X * v94) + (float)(v327 * v324);
      v96 = v89[1];
      *(float *)&v97 = v95 + (float)(v85 * v325);
      v321 = v89[9];
      v326 = v89[5];
      *(float *)&v98 = (float)((float)(_X * v96) + (float)(v327 * v326)) + (float)(v85 * v321);
      v314 = v89[8];
      v99 = v85 * v314;
      v100 = _X * *v89;
      v315 = *v89;
      v328 = v96;
      v101 = v89[4];
      v313 = (float)(v100 + (float)(v327 * v101)) + v99;
      *(float *)&v102 = (float)((float)(v93 * v330) + (float)(v323 * v324)) + (float)(v317 * v325);
      *(float *)&v103 = (float)((float)(v93 * v328) + (float)(v323 * v326)) + (float)(v317 * v321);
      v327 = (float)((float)(v93 * v315) + (float)(v323 * v101)) + (float)(v317 * v314);
      v317 = (float)((float)(v334 * v330) + (float)(v335 * v324)) + (float)(v333 * v325);
      v323 = (float)((float)(v334 * v328) + (float)(v335 * v326)) + (float)(v333 * v321);
      v336.m_basis.m_el[0].mVec128.m128_f32[1] = v323;
      v336.m_basis.m_el[0].mVec128.m128_f32[2] = v317;
      v336.m_basis.m_el[0].mVec128.m128_f32[0] = (float)((float)(v334 * v315) + (float)(v335 * v101))
                                               + (float)(v333 * v314);
      si128 = _mm_load_si128((const __m128i *)&v336);
      v321 = v336.m_basis.m_el[0].mVec128.m128_f32[0];
      v341.m_basis.m_el[0] = (btVector3)si128;
      v336.m_basis.m_el[1].mVec128.m128_u64[0] = __PAIR64__(v103, LODWORD(v327));
      v336.m_basis.m_el[2].mVec128.m128_u64[0] = __PAIR64__(v98, LODWORD(v313));
      v336.m_basis.m_el[1].mVec128.m128_u64[1] = v102;
      v341.m_basis.m_el[1] = (btVector3)_mm_load_si128((const __m128i *)&v336.m_basis.m_el[1]);
      v336.m_basis.m_el[2].mVec128.m128_u64[1] = v97;
      v341.m_basis.m_el[2] = (btVector3)_mm_load_si128((const __m128i *)&v336.m_basis.m_el[2]);
      v341.m_origin = (btVector3)_mm_load_si128(&v320);
      v318.mVec128.m128_f32[0] = (float)((float)((float)(*(float *)v320.m128i_i32
                                                       * transform1.m_basis.m_el[0].mVec128.m128_f32[0])
                                               + (float)(*(float *)&v320.m128i_i32[2]
                                                       * transform1.m_basis.m_el[0].mVec128.m128_f32[2]))
                                       + (float)(*(float *)&v320.m128i_i32[1]
                                               * transform1.m_basis.m_el[0].mVec128.m128_f32[1]))
                               + transform1.m_origin.mVec128.m128_f32[0];
      v318.mVec128.m128_f32[1] = (float)((float)((float)(transform1.m_basis.m_el[1].mVec128.m128_f32[2]
                                                       * *(float *)&v320.m128i_i32[2])
                                               + (float)(transform1.m_basis.m_el[1].mVec128.m128_f32[1]
                                                       * *(float *)&v320.m128i_i32[1]))
                                       + (float)(*(float *)v320.m128i_i32
                                               * transform1.m_basis.m_el[1].mVec128.m128_f32[0]))
                               + transform1.m_origin.mVec128.m128_f32[1];
      v318.mVec128.m128_f32[2] = (float)((float)((float)(transform1.m_basis.m_el[2].mVec128.m128_f32[2]
                                                       * *(float *)&v320.m128i_i32[2])
                                               + (float)(transform1.m_basis.m_el[2].mVec128.m128_f32[1]
                                                       * *(float *)&v320.m128i_i32[1]))
                                       + (float)(*(float *)v320.m128i_i32
                                               * transform1.m_basis.m_el[2].mVec128.m128_f32[0]))
                               + transform1.m_origin.mVec128.m128_f32[2];
      v318.mVec128.m128_i32[3] = 0;
      v330 = (float)((float)(*(float *)&v102 * transform1.m_basis.m_el[2].mVec128.m128_f32[1])
                   + (float)(v317 * transform1.m_basis.m_el[2].mVec128.m128_f32[0]))
           + (float)(*(float *)&v97 * transform1.m_basis.m_el[2].mVec128.m128_f32[2]);
      v324 = (float)((float)(*(float *)&v98 * transform1.m_basis.m_el[2].mVec128.m128_f32[2])
                   + (float)(v323 * transform1.m_basis.m_el[2].mVec128.m128_f32[0]))
           + (float)(*(float *)&v103 * transform1.m_basis.m_el[2].mVec128.m128_f32[1]);
      *(float *)si128.m128i_i32 = v313;
      v328 = (float)((float)(v327 * transform1.m_basis.m_el[2].mVec128.m128_f32[1])
                   + (float)(v336.m_basis.m_el[0].mVec128.m128_f32[0] * transform1.m_basis.m_el[2].mVec128.m128_f32[0]))
           + (float)(v313 * transform1.m_basis.m_el[2].mVec128.m128_f32[2]);
      v315 = (float)((float)(*(float *)&v102 * transform1.m_basis.m_el[1].mVec128.m128_f32[1])
                   + (float)(v317 * transform1.m_basis.m_el[1].mVec128.m128_f32[0]))
           + (float)(*(float *)&v97 * transform1.m_basis.m_el[1].mVec128.m128_f32[2]);
      _X = (float)((float)(*(float *)&v98 * transform1.m_basis.m_el[1].mVec128.m128_f32[2])
                 + (float)(v323 * transform1.m_basis.m_el[1].mVec128.m128_f32[0]))
         + (float)(*(float *)&v103 * transform1.m_basis.m_el[1].mVec128.m128_f32[1]);
      v314 = (float)(v327 * transform1.m_basis.m_el[1].mVec128.m128_f32[1])
           + (float)(v336.m_basis.m_el[0].mVec128.m128_f32[0] * transform1.m_basis.m_el[1].mVec128.m128_f32[0]);
      v105 = v314 + (float)(v313 * transform1.m_basis.m_el[1].mVec128.m128_f32[2]);
      v313 = (float)((float)(*(float *)&v102 * transform1.m_basis.m_el[0].mVec128.m128_f32[1])
                   + (float)(*(float *)&v97 * transform1.m_basis.m_el[0].mVec128.m128_f32[2]))
           + (float)(v317 * transform1.m_basis.m_el[0].mVec128.m128_f32[0]);
      v336.m_basis.m_el[0].mVec128.m128_f32[1] = (float)((float)(*(float *)&v98
                                                               * transform1.m_basis.m_el[0].mVec128.m128_f32[2])
                                                       + (float)(*(float *)&v103
                                                               * transform1.m_basis.m_el[0].mVec128.m128_f32[1]))
                                               + (float)(v323 * transform1.m_basis.m_el[0].mVec128.m128_f32[0]);
      v336.m_basis.m_el[1].mVec128.m128_f32[1] = _X;
      v336.m_basis.m_el[0].mVec128.m128_f32[2] = v313;
      v336.m_basis.m_el[1].mVec128.m128_u64[1] = LODWORD(v315);
      v336.m_basis.m_el[0].mVec128.m128_i32[3] = 0;
      v336.m_basis.m_el[2].mVec128.m128_f32[0] = v328;
      v336.m_basis.m_el[0].mVec128.m128_f32[0] = (float)((float)(v327 * transform1.m_basis.m_el[0].mVec128.m128_f32[1])
                                                       + (float)(*(float *)si128.m128i_i32
                                                               * transform1.m_basis.m_el[0].mVec128.m128_f32[2]))
                                               + (float)(v336.m_basis.m_el[0].mVec128.m128_f32[0]
                                                       * transform1.m_basis.m_el[0].mVec128.m128_f32[0]);
      transform1.m_basis.m_el[0] = (btVector3)_mm_load_si128((const __m128i *)&v336);
      v336.m_basis.m_el[2].mVec128.m128_f32[1] = v324;
      v336.m_basis.m_el[1].mVec128.m128_f32[0] = v105;
      transform1.m_basis.m_el[1] = (btVector3)_mm_load_si128((const __m128i *)&v336.m_basis.m_el[1]);
      v336.m_basis.m_el[2].mVec128.m128_u64[1] = LODWORD(v330);
      transform1.m_basis.m_el[2] = (btVector3)_mm_load_si128((const __m128i *)&v336.m_basis.m_el[2]);
      transform1.m_origin = (btVector3)_mm_load_si128((const __m128i *)&v318);
      v106 = btTransform::inverse(&v341, &v336);
      si128.m128i_i32[0] = v106->m_origin.mVec128.m128_i32[1];
      LODWORD(v80) = v106->m_origin.mVec128.m128_i32[0];
      v107 = v106->m_origin.mVec128.m128_f32[2];
      v318.mVec128.m128_f32[0] = (float)((float)((float)(predictedTransform.m_basis.m_el[0].mVec128.m128_f32[0]
                                                       * *(float *)&v80)
                                               + (float)(*(float *)si128.m128i_i32
                                                       * predictedTransform.m_basis.m_el[0].mVec128.m128_f32[1]))
                                       + (float)(v107 * predictedTransform.m_basis.m_el[0].mVec128.m128_f32[2]))
                               + predictedTransform.m_origin.mVec128.m128_f32[0];
      v108 = (float)(predictedTransform.m_basis.m_el[1].mVec128.m128_f32[0] * *(float *)&v80)
           + (float)(predictedTransform.m_basis.m_el[1].mVec128.m128_f32[1] * *(float *)si128.m128i_i32);
      *(float *)&v80 = predictedTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v107;
      v109 = v106->m_origin.mVec128.m128_f32[0];
      v318.mVec128.m128_f32[1] = (float)(v108 + *(float *)&v80) + predictedTransform.m_origin.mVec128.m128_f32[1];
      *(float *)&v110 = (float)((float)((float)(predictedTransform.m_basis.m_el[2].mVec128.m128_f32[0] * v109)
                                      + (float)(predictedTransform.m_basis.m_el[2].mVec128.m128_f32[1]
                                              * *(float *)si128.m128i_i32))
                              + (float)(predictedTransform.m_basis.m_el[2].mVec128.m128_f32[2]
                                      * v106->m_origin.mVec128.m128_f32[2]))
                      + predictedTransform.m_origin.mVec128.m128_f32[2];
      v111 = v106->m_basis.m_el[1].mVec128.m128_f32[2];
      v318.mVec128.m128_u64[1] = v110;
      v321 = v106->m_basis.m_el[2].mVec128.m128_f32[2];
      si128.m128i_i32[0] = v106->m_basis.m_el[0].mVec128.m128_i32[2];
      _X = v111;
      v313 = *(float *)si128.m128i_i32;
      v314 = (float)(predictedTransform.m_basis.m_el[2].mVec128.m128_f32[0] * *(float *)si128.m128i_i32)
           + (float)(predictedTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v111);
      v325 = v106->m_basis.m_el[2].mVec128.m128_f32[1];
      v112 = v106->m_basis.m_el[1].mVec128.m128_f32[1];
      v323 = v314 + (float)(predictedTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v321);
      v326 = v112;
      v315 = v106->m_basis.m_el[0].mVec128.m128_f32[1];
      v314 = (float)(predictedTransform.m_basis.m_el[2].mVec128.m128_f32[0] * v315)
           + (float)(predictedTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v112);
      v113 = v106->m_basis.m_el[2].mVec128.m128_f32[0];
      v327 = v314 + (float)(predictedTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v325);
      v324 = v106->m_basis.m_el[1].mVec128.m128_f32[0];
      *(float *)&v80 = predictedTransform.m_basis.m_el[2].mVec128.m128_f32[0]
                     * v106->m_basis.m_el[0].mVec128.m128_f32[0];
      v328 = v106->m_basis.m_el[0].mVec128.m128_f32[0];
      v334 = (float)(*(float *)&v80 + (float)(predictedTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v324))
           + (float)(predictedTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v113);
      v330 = (float)((float)(predictedTransform.m_basis.m_el[1].mVec128.m128_f32[0] * *(float *)si128.m128i_i32)
                   + (float)(predictedTransform.m_basis.m_el[1].mVec128.m128_f32[1] * _X))
           + (float)(predictedTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v321);
      v114 = v324 * predictedTransform.m_basis.m_el[0].mVec128.m128_f32[1];
      v324 = (float)((float)(predictedTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v328)
                   + (float)(predictedTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v324))
           + (float)(predictedTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v113);
      v336.m_basis.m_el[1].mVec128.m128_f32[0] = v324;
      v336.m_basis.m_el[0].mVec128.m128_f32[0] = (float)((float)(predictedTransform.m_basis.m_el[0].mVec128.m128_f32[0]
                                                               * v328)
                                                       + v114)
                                               + (float)(v113 * predictedTransform.m_basis.m_el[0].mVec128.m128_f32[2]);
      v336.m_basis.m_el[1].mVec128.m128_u64[1] = LODWORD(v330);
      v336.m_basis.m_el[0].mVec128.m128_i32[3] = 0;
      v336.m_basis.m_el[2].mVec128.m128_f32[0] = v334;
      v336.m_basis.m_el[0].mVec128.m128_f32[1] = (float)((float)(predictedTransform.m_basis.m_el[0].mVec128.m128_f32[0]
                                                               * v315)
                                                       + (float)(v326
                                                               * predictedTransform.m_basis.m_el[0].mVec128.m128_f32[1]))
                                               + (float)(v325 * predictedTransform.m_basis.m_el[0].mVec128.m128_f32[2]);
      v336.m_basis.m_el[0].mVec128.m128_f32[2] = (float)((float)(predictedTransform.m_basis.m_el[0].mVec128.m128_f32[0]
                                                               * *(float *)si128.m128i_i32)
                                                       + (float)(_X
                                                               * predictedTransform.m_basis.m_el[0].mVec128.m128_f32[1]))
                                               + (float)(v321 * predictedTransform.m_basis.m_el[0].mVec128.m128_f32[2]);
      v341.m_basis.m_el[0] = (btVector3)_mm_load_si128((const __m128i *)&v336);
      v336.m_basis.m_el[2].mVec128.m128_f32[1] = v327;
      v336.m_basis.m_el[1].mVec128.m128_f32[1] = (float)((float)(predictedTransform.m_basis.m_el[1].mVec128.m128_f32[0]
                                                               * v315)
                                                       + (float)(predictedTransform.m_basis.m_el[1].mVec128.m128_f32[1]
                                                               * v326))
                                               + (float)(predictedTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v325);
      v341.m_basis.m_el[1] = (btVector3)_mm_load_si128((const __m128i *)&v336.m_basis.m_el[1]);
      v336.m_basis.m_el[2].mVec128.m128_u64[1] = LODWORD(v323);
      v341.m_basis.m_el[2] = (btVector3)_mm_load_si128((const __m128i *)&v336.m_basis.m_el[2]);
      v341.m_origin = (btVector3)_mm_load_si128((const __m128i *)&v318);
      btTransformUtil::calculateVelocity(&transform1, &linvel, &angVel, &curTrans, timeStep);
      btTransformUtil::calculateVelocity(&v341, &linvel, &v318, &transform0, timeStep);
      *(float *)v320.m128i_i32 = angVel.mVec128.m128_f32[0] - *(float *)v319.m128i_i32;
      *(float *)&v320.m128i_i32[1] = angVel.mVec128.m128_f32[1] - *(float *)&v319.m128i_i32[1];
      v115 = v318.mVec128.m128_f32[0] - *(float *)v332.m128i_i32;
      v116 = v318.mVec128.m128_f32[1] - *(float *)&v332.m128i_i32[1];
      v117 = v318.mVec128.m128_f32[2] - *(float *)&v332.m128i_i32[2];
      *(float *)&v320.m128i_i32[2] = angVel.mVec128.m128_f32[2] - *(float *)&v319.m128i_i32[2];
      v118 = (float)((float)(*(float *)&v320.m128i_i32[2] * *(float *)&v320.m128i_i32[2])
                   + (float)((float)(angVel.mVec128.m128_f32[1] - *(float *)&v319.m128i_i32[1])
                           * (float)(angVel.mVec128.m128_f32[1] - *(float *)&v319.m128i_i32[1])))
           + (float)((float)(angVel.mVec128.m128_f32[0] - *(float *)v319.m128i_i32)
                   * (float)(angVel.mVec128.m128_f32[0] - *(float *)v319.m128i_i32));
      *(float *)v319.m128i_i32 = v318.mVec128.m128_f32[0] - *(float *)v332.m128i_i32;
      *(float *)&v319.m128i_i32[1] = v318.mVec128.m128_f32[1] - *(float *)&v332.m128i_i32[1];
      *(float *)&v319.m128i_i32[2] = v318.mVec128.m128_f32[2] - *(float *)&v332.m128i_i32[2];
      v314 = 0.0;
      v313 = 0.0;
      _X = v118;
      if ( v118 <= 0.00000011920929 )
      {
        v124 = v314;
      }
      else
      {
        v119 = sqrtf(_X);
        v120 = (float *)this->m_rbA;
        v121 = v120[76];
        v122 = v120[77];
        v123 = v120[74];
        v120 += 68;
        _X = 1.0 / v119;
        v318.mVec128.m128_f32[0] = _X * *(float *)v320.m128i_i32;
        v318.mVec128.m128_f32[1] = *(float *)&v320.m128i_i32[1] * _X;
        v318.mVec128.m128_f32[2] = *(float *)&v320.m128i_i32[2] * _X;
        v318.mVec128.m128_i32[3] = 0;
        v331 = _mm_load_si128((const __m128i *)&v318);
        v117 = *(float *)&v319.m128i_i32[2];
        v116 = *(float *)&v319.m128i_i32[1];
        v115 = *(float *)v319.m128i_i32;
        v124 = (float)((float)((float)((float)((float)(v120[10] * (float)(*(float *)&v320.m128i_i32[2] * _X))
                                             + (float)(v123 * (float)(*(float *)&v320.m128i_i32[1] * _X)))
                                     + (float)(v120[2] * (float)(_X * *(float *)v320.m128i_i32)))
                             * (float)(*(float *)&v320.m128i_i32[2] * _X))
                     + (float)((float)((float)((float)(v122 * (float)(*(float *)&v320.m128i_i32[2] * _X))
                                             + (float)(v120[5] * (float)(*(float *)&v320.m128i_i32[1] * _X)))
                                     + (float)(v120[1] * (float)(_X * *(float *)v320.m128i_i32)))
                             * (float)(*(float *)&v320.m128i_i32[1] * _X)))
             + (float)((float)((float)((float)(v121 * (float)(*(float *)&v320.m128i_i32[2] * _X))
                                     + (float)(v120[4] * (float)(*(float *)&v320.m128i_i32[1] * _X)))
                             + (float)(*v120 * (float)(_X * *(float *)v320.m128i_i32)))
                     * (float)(_X * *(float *)v320.m128i_i32));
        v314 = v124;
      }
      v125 = v313;
      v313 = (float)((float)(v117 * v117) + (float)(v116 * v116)) + (float)(v115 * v115);
      if ( v313 > 0.00000011920929 )
      {
        v126 = sqrtf(v313);
        v127 = (float *)this->m_rbB;
        v128 = v127[76];
        v129 = v127[77];
        v130 = v127[74];
        v127 += 68;
        v313 = 1.0 / v126;
        v318.mVec128.m128_f32[0] = v313 * *(float *)v319.m128i_i32;
        v318.mVec128.m128_f32[1] = *(float *)&v319.m128i_i32[1] * v313;
        v318.mVec128.m128_f32[2] = *(float *)&v319.m128i_i32[2] * v313;
        v318.mVec128.m128_i32[3] = 0;
        angVel.mVec128 = (__m128)_mm_load_si128((const __m128i *)&v318);
        v125 = (float)((float)((float)((float)((float)(v127[10] * (float)(*(float *)&v319.m128i_i32[2] * v313))
                                             + (float)(v130 * (float)(*(float *)&v319.m128i_i32[1] * v313)))
                                     + (float)(v127[2] * (float)(v313 * *(float *)v319.m128i_i32)))
                             * (float)(*(float *)&v319.m128i_i32[2] * v313))
                     + (float)((float)((float)((float)(v129 * (float)(*(float *)&v319.m128i_i32[2] * v313))
                                             + (float)(v127[5] * (float)(*(float *)&v319.m128i_i32[1] * v313)))
                                     + (float)(v127[1] * (float)(v313 * *(float *)v319.m128i_i32)))
                             * (float)(*(float *)&v319.m128i_i32[1] * v313)))
             + (float)((float)((float)((float)(v128 * (float)(*(float *)&v319.m128i_i32[2] * v313))
                                     + (float)(v127[4] * (float)(*(float *)&v319.m128i_i32[1] * v313)))
                             + (float)((float)(v313 * *(float *)v319.m128i_i32) * *v127))
                     * (float)(v313 * *(float *)v319.m128i_i32));
        v124 = v314;
      }
      v318.mVec128.m128_f32[2] = (float)(*(float *)&v331.m128i_i32[2] * v124)
                               + (float)(angVel.mVec128.m128_f32[2] * v125);
      v318.mVec128.m128_f32[1] = (float)(*(float *)&v331.m128i_i32[1] * v124)
                               + (float)(angVel.mVec128.m128_f32[1] * v125);
      v318.mVec128.m128_f32[0] = (float)(*(float *)v331.m128i_i32 * v124) + (float)(angVel.mVec128.m128_f32[0] * v125);
      v313 = (float)((float)(v318.mVec128.m128_f32[2] * v318.mVec128.m128_f32[2])
                   + (float)(v318.mVec128.m128_f32[1] * v318.mVec128.m128_f32[1]))
           + (float)(v318.mVec128.m128_f32[0] * v318.mVec128.m128_f32[0]);
      if ( v313 <= 0.00000011920929 )
      {
        v14 = bodyA;
        v28 = bodyB;
      }
      else
      {
        v131 = sqrtf(v313);
        v132 = (float *)this->m_rbA;
        v133 = v132[72];
        v134 = v132[73];
        v135 = v132[74];
        v132 += 68;
        v313 = 1.0 / v131;
        v136 = (float)((float)(v132[8] * (float)(v318.mVec128.m128_f32[2] * v313))
                     + (float)(v133 * (float)(v318.mVec128.m128_f32[1] * v313)))
             + (float)((float)(v318.mVec128.m128_f32[0] * v313) * *v132);
        v137 = (float)((float)(v132[9] * (float)(v318.mVec128.m128_f32[2] * v313))
                     + (float)(v134 * (float)(v318.mVec128.m128_f32[1] * v313)))
             + (float)(v132[1] * (float)(v318.mVec128.m128_f32[0] * v313));
        v138 = (float)(v132[10] * (float)(v318.mVec128.m128_f32[2] * v313))
             + (float)(v135 * (float)(v318.mVec128.m128_f32[1] * v313));
        v139 = v132[2];
        v140 = (float *)this->m_rbB;
        v141 = v140[74];
        v142 = v138 + (float)(v139 * (float)(v318.mVec128.m128_f32[0] * v313));
        v143 = v140[73];
        v140 += 68;
        v144 = (float)((float)(v136 * (float)(v318.mVec128.m128_f32[0] * v313))
                     + (float)(v142 * (float)(v318.mVec128.m128_f32[2] * v313)))
             + (float)(v137 * (float)(v318.mVec128.m128_f32[1] * v313));
        v145 = (float)((float)((float)((float)((float)(v140[8] * (float)(v318.mVec128.m128_f32[2] * v313))
                                             + (float)(v140[4] * (float)(v318.mVec128.m128_f32[1] * v313)))
                                     + (float)((float)(v318.mVec128.m128_f32[0] * v313) * *v140))
                             * (float)(v318.mVec128.m128_f32[0] * v313))
                     + (float)((float)((float)((float)(v140[10] * (float)(v318.mVec128.m128_f32[2] * v313))
                                             + (float)(v141 * (float)(v318.mVec128.m128_f32[1] * v313)))
                                     + (float)(v140[2] * (float)(v318.mVec128.m128_f32[0] * v313)))
                             * (float)(v318.mVec128.m128_f32[2] * v313)))
             + (float)((float)((float)((float)(v140[9] * (float)(v318.mVec128.m128_f32[2] * v313))
                                     + (float)(v143 * (float)(v318.mVec128.m128_f32[1] * v313)))
                             + (float)(v140[1] * (float)(v318.mVec128.m128_f32[0] * v313)))
                     * (float)(v318.mVec128.m128_f32[1] * v313));
        v146 = *(float *)&v319.m128i_i32[1] * v145;
        v147 = *(float *)&v319.m128i_i32[2] * v145;
        v148 = (float)(*(float *)v320.m128i_i32 * v144) - (float)(*(float *)v319.m128i_i32 * v145);
        v149 = *(float *)&clear_value / (float)((float)(v145 + v144) * (float)(v145 + v144));
        v150 = v149 * (float)((float)(*(float *)&v320.m128i_i32[1] * v144) - v146);
        m_maxMotorImpulse = this->m_maxMotorImpulse;
        v152 = v148 * v149;
        *(float *)&v153 = v149 * (float)((float)(*(float *)&v320.m128i_i32[2] * v144) - v147);
        v319.m128i_i64[0] = __PAIR64__(LODWORD(v150), LODWORD(v152));
        v319.m128i_i32[2] = v153;
        if ( m_maxMotorImpulse >= 0.0 )
        {
          v5 = !this->m_bNormalizedMotorStrength;
          v314 = m_maxMotorImpulse;
          if ( !v5 )
            v314 = m_maxMotorImpulse / v144;
          *(float *)&v154 = v152 + this->m_accMotorImpulse.mVec128.m128_f32[0];
          *(float *)&v155 = this->m_accMotorImpulse.mVec128.m128_f32[1] + v150;
          v318.mVec128.m128_f32[2] = this->m_accMotorImpulse.mVec128.m128_f32[2] + *(float *)&v153;
          v318.mVec128.m128_u64[0] = __PAIR64__(v155, v154);
          v156 = sqrtf(
                   (float)((float)(v318.mVec128.m128_f32[2] * v318.mVec128.m128_f32[2])
                         + (float)(*(float *)&v155 * *(float *)&v155))
                 + (float)(*(float *)&v154 * *(float *)&v154));
          v313 = v156;
          if ( v156 > v314 )
          {
            v318.mVec128.m128_f32[2] = (float)((float)((float)(*(float *)&clear_value / v313) * v318.mVec128.m128_f32[2])
                                             * v314)
                                     - this->m_accMotorImpulse.mVec128.m128_f32[2];
            v157 = (float)((float)((float)(*(float *)&clear_value / v313) * v318.mVec128.m128_f32[1]) * v314)
                 - this->m_accMotorImpulse.mVec128.m128_f32[1];
            v318.mVec128.m128_f32[0] = (float)((float)(v318.mVec128.m128_f32[0] * (float)(*(float *)&clear_value / v313))
                                             * v314)
                                     - this->m_accMotorImpulse.mVec128.m128_f32[0];
            v318.mVec128.m128_f32[1] = v157;
            v318.mVec128.m128_i32[3] = 0;
            v319 = _mm_load_si128((const __m128i *)&v318);
          }
          v152 = *(float *)v319.m128i_i32;
          v150 = *(float *)&v319.m128i_i32[1];
          v153 = v319.m128i_i32[2];
          this->m_accMotorImpulse.mVec128.m128_f32[0] = this->m_accMotorImpulse.mVec128.m128_f32[0]
                                                      + *(float *)v319.m128i_i32;
          this->m_accMotorImpulse.mVec128.m128_f32[1] = v150 + this->m_accMotorImpulse.mVec128.m128_f32[1];
          this->m_accMotorImpulse.mVec128.m128_f32[2] = *(float *)&v153 + this->m_accMotorImpulse.mVec128.m128_f32[2];
        }
        v313 = sqrtf((float)((float)(*(float *)&v153 * *(float *)&v153) + (float)(v150 * v150)) + (float)(v152 * v152));
        v158 = v313;
        v159 = (float *)this->m_rbA;
        v160 = v159[70];
        v161 = v159[73];
        v162 = (float)(*(float *)&clear_value / v313) * *(float *)v319.m128i_i32;
        v163 = (float)(*(float *)&clear_value / v313) * *(float *)&v319.m128i_i32[1];
        v164 = (float)(*(float *)&clear_value / v313) * *(float *)&v319.m128i_i32[2];
        v165 = v159[69];
        v159 += 68;
        v166 = (float)((float)(v160 * v164) + (float)(v165 * v163)) + (float)(v162 * *v159);
        v167 = (float)((float)(v159[6] * v164) + (float)(v161 * v163)) + (float)(v159[4] * v162);
        v168 = v159[9];
        angVel.mVec128.m128_f32[1] = v167;
        v169 = (float)((float)(v159[10] * v164) + (float)(v168 * v163)) + (float)(v162 * v159[8]);
        m_inverseMass = bodyA->m_inverseMass;
        angVel.mVec128.m128_f32[2] = v169;
        angvel.mVec128.m128_f32[2] = v164;
        if ( m_inverseMass != 0.0 )
        {
          bodyA->m_deltaLinearVelocity.mVec128.m128_f32[0] = (float)(v313 * 0.0)
                                                           + bodyA->m_deltaLinearVelocity.mVec128.m128_f32[0];
          bodyA->m_deltaLinearVelocity.mVec128.m128_f32[1] = bodyA->m_deltaLinearVelocity.mVec128.m128_f32[1]
                                                           + (float)(v158 * 0.0);
          bodyA->m_deltaLinearVelocity.mVec128.m128_f32[2] = bodyA->m_deltaLinearVelocity.mVec128.m128_f32[2]
                                                           + (float)(v158 * 0.0);
          v171 = bodyA->m_angularFactor.mVec128.m128_f32[1];
          v172 = bodyA->m_angularFactor.mVec128.m128_f32[2];
          bodyA->m_deltaAngularVelocity.mVec128.m128_f32[0] = (float)((float)(bodyA->m_angularFactor.mVec128.m128_f32[0]
                                                                            * v158)
                                                                    * v166)
                                                            + bodyA->m_deltaAngularVelocity.mVec128.m128_f32[0];
          bodyA->m_deltaAngularVelocity.mVec128.m128_f32[1] = bodyA->m_deltaAngularVelocity.mVec128.m128_f32[1]
                                                            + (float)((float)(v171 * v158) * angVel.mVec128.m128_f32[1]);
          bodyA->m_deltaAngularVelocity.mVec128.m128_f32[2] = bodyA->m_deltaAngularVelocity.mVec128.m128_f32[2]
                                                            + (float)((float)(v172 * v158) * angVel.mVec128.m128_f32[2]);
          v164 = angvel.mVec128.m128_f32[2];
        }
        v173 = (float *)this->m_rbB;
        v174 = v173[70];
        v175 = v173[69];
        v176 = v173[73];
        v173 += 68;
        v177 = -v158;
        v14 = bodyA;
        v178 = (float)((float)(v174 * v164) + (float)(v175 * v163)) + (float)(v162 * *v173);
        v179 = (float)((float)(v173[6] * v164) + (float)(v176 * v163)) + (float)(v173[4] * v162);
        v180 = (float)((float)(v173[10] * v164) + (float)(v173[9] * v163)) + (float)(v162 * v173[8]);
        if ( bodyB->m_inverseMass != 0.0 )
        {
          bodyB->m_deltaLinearVelocity.mVec128.m128_f32[0] = (float)(v177 * 0.0)
                                                           + bodyB->m_deltaLinearVelocity.mVec128.m128_f32[0];
          bodyB->m_deltaLinearVelocity.mVec128.m128_f32[1] = bodyB->m_deltaLinearVelocity.mVec128.m128_f32[1]
                                                           + (float)(v177 * 0.0);
          bodyB->m_deltaLinearVelocity.mVec128.m128_f32[2] = bodyB->m_deltaLinearVelocity.mVec128.m128_f32[2]
                                                           + (float)(v177 * 0.0);
          v181 = (float)((float)(bodyB->m_angularFactor.mVec128.m128_f32[1] * v177) * v179)
               + bodyB->m_deltaAngularVelocity.mVec128.m128_f32[1];
          v182 = (float)((float)(bodyB->m_angularFactor.mVec128.m128_f32[2] * v177) * v180)
               + bodyB->m_deltaAngularVelocity.mVec128.m128_f32[2];
          bodyB->m_deltaAngularVelocity.mVec128.m128_f32[0] = (float)((float)(bodyB->m_angularFactor.mVec128.m128_f32[0]
                                                                            * v177)
                                                                    * v178)
                                                            + bodyB->m_deltaAngularVelocity.mVec128.m128_f32[0];
          bodyB->m_deltaAngularVelocity.mVec128.m128_f32[1] = v181;
          bodyB->m_deltaAngularVelocity.mVec128.m128_f32[2] = v182;
        }
        v28 = bodyB;
      }
    }
    else
    {
      _X = this->m_damping;
      if ( _X > 0.00000011920929 )
      {
        *(float *)&v183 = (float)(v28->m_angularVelocity.mVec128.m128_f32[0]
                                + v28->m_deltaAngularVelocity.mVec128.m128_f32[0])
                        - (float)(bodyA->m_angularVelocity.mVec128.m128_f32[0]
                                + bodyA->m_deltaAngularVelocity.mVec128.m128_f32[0]);
        *(float *)&v184 = (float)(v28->m_angularVelocity.mVec128.m128_f32[1]
                                + v28->m_deltaAngularVelocity.mVec128.m128_f32[1])
                        - (float)(bodyA->m_angularVelocity.mVec128.m128_f32[1]
                                + bodyA->m_deltaAngularVelocity.mVec128.m128_f32[1]);
        *(float *)&v320.m128i_i32[2] = (float)(v28->m_angularVelocity.mVec128.m128_f32[2]
                                             + v28->m_deltaAngularVelocity.mVec128.m128_f32[2])
                                     - (float)(bodyA->m_angularVelocity.mVec128.m128_f32[2]
                                             + bodyA->m_deltaAngularVelocity.mVec128.m128_f32[2]);
        v320.m128i_i64[0] = __PAIR64__(v184, v183);
        v313 = (float)((float)(*(float *)&v320.m128i_i32[2] * *(float *)&v320.m128i_i32[2])
                     + (float)(*(float *)&v184 * *(float *)&v184))
             + (float)(*(float *)&v183 * *(float *)&v183);
        if ( v313 > 0.00000011920929 )
        {
          v185 = sqrtf(v313);
          v186 = (float *)this->m_rbA;
          v187 = v186[76];
          v188 = v186[72];
          v189 = v186[73];
          v313 = 1.0 / v185;
          v190 = (float)((float)(v187 * (float)(v313 * *(float *)&v320.m128i_i32[2]))
                       + (float)(v188 * (float)(v313 * *(float *)&v320.m128i_i32[1])))
               + (float)((float)(*(float *)v320.m128i_i32 * v313) * v186[68]);
          v191 = (float)((float)(v186[77] * (float)(v313 * *(float *)&v320.m128i_i32[2]))
                       + (float)(v189 * (float)(v313 * *(float *)&v320.m128i_i32[1])))
               + (float)(v186[69] * (float)(*(float *)v320.m128i_i32 * v313));
          v192 = v186[74];
          angVel.mVec128.m128_f32[1] = v191;
          v193 = (float)(v186[78] * (float)(v313 * *(float *)&v320.m128i_i32[2]))
               + (float)(v192 * (float)(v313 * *(float *)&v320.m128i_i32[1]));
          v194 = v186[70];
          v195 = (float *)this->m_rbB;
          v196 = v195[77];
          v197 = v195[74];
          v198 = v193 + (float)(v194 * (float)(*(float *)v320.m128i_i32 * v313));
          v199 = v195[76];
          angVel.mVec128.m128_f32[2] = v198;
          v200 = v195[72] * (float)(v313 * *(float *)&v320.m128i_i32[1]);
          v195 += 68;
          v201 = (float)(*(float *)&clear_value
                       / (float)((float)((float)((float)((float)((float)((float)(v195[10]
                                                                               * (float)(v313
                                                                                       * *(float *)&v320.m128i_i32[2]))
                                                                       + (float)(v197
                                                                               * (float)(v313
                                                                                       * *(float *)&v320.m128i_i32[1])))
                                                               + (float)(v195[2]
                                                                       * (float)(*(float *)v320.m128i_i32 * v313)))
                                                       + angVel.mVec128.m128_f32[2])
                                               * (float)(v313 * *(float *)&v320.m128i_i32[2]))
                                       + (float)((float)((float)((float)((float)(v196
                                                                               * (float)(v313
                                                                                       * *(float *)&v320.m128i_i32[2]))
                                                                       + (float)(v195[5]
                                                                               * (float)(v313
                                                                                       * *(float *)&v320.m128i_i32[1])))
                                                               + (float)(v195[1]
                                                                       * (float)(*(float *)v320.m128i_i32 * v313)))
                                                       + angVel.mVec128.m128_f32[1])
                                               * (float)(v313 * *(float *)&v320.m128i_i32[1])))
                               + (float)((float)((float)((float)((float)(v199
                                                                       * (float)(v313 * *(float *)&v320.m128i_i32[2]))
                                                               + v200)
                                                       + (float)((float)(*(float *)v320.m128i_i32 * v313) * *v195))
                                               + v190)
                                       * (float)(*(float *)v320.m128i_i32 * v313))))
               * _X;
          v318.mVec128.m128_f32[0] = *(float *)v320.m128i_i32 * v201;
          v318.mVec128.m128_f32[1] = *(float *)&v320.m128i_i32[1] * v201;
          v318.mVec128.m128_f32[2] = *(float *)&v320.m128i_i32[2] * v201;
          v317 = sqrtf(
                   (float)((float)((float)(*(float *)v320.m128i_i32 * v201) * (float)(*(float *)v320.m128i_i32 * v201))
                         + (float)(v318.mVec128.m128_f32[2] * v318.mVec128.m128_f32[2]))
                 + (float)(v318.mVec128.m128_f32[1] * v318.mVec128.m128_f32[1]));
          v202 = (float *)this->m_rbA;
          v203 = (float)(*(float *)&clear_value / v317) * (float)(*(float *)&v320.m128i_i32[1] * v201);
          v204 = v318.mVec128.m128_f32[0] * (float)(*(float *)&clear_value / v317);
          v205 = (float)(*(float *)&clear_value / v317) * v318.mVec128.m128_f32[2];
          v206 = bodyA->m_inverseMass;
          v207 = (float)((float)(v202[70] * v205) + (float)(v202[69] * v203)) + (float)(v204 * v202[68]);
          v208 = (float)((float)(v202[74] * v205) + (float)(v202[73] * v203)) + (float)(v204 * v202[72]);
          v209 = (float)((float)(v202[78] * v205) + (float)(v202[77] * v203)) + (float)(v204 * v202[76]);
          angvel.mVec128.m128_f32[2] = v205;
          if ( v206 != 0.0 )
          {
            v210 = bodyA->m_deltaLinearVelocity.mVec128.m128_f32[0] + (float)(v317 * 0.0);
            angVel.mVec128.m128_f32[1] = v317 * 0.0;
            angVel.mVec128.m128_f32[2] = v317 * 0.0;
            bodyA->m_deltaLinearVelocity.mVec128.m128_f32[1] = (float)(v317 * 0.0)
                                                             + bodyA->m_deltaLinearVelocity.mVec128.m128_f32[1];
            bodyA->m_deltaLinearVelocity.mVec128.m128_f32[2] = angVel.mVec128.m128_f32[2]
                                                             + bodyA->m_deltaLinearVelocity.mVec128.m128_f32[2];
            bodyA->m_deltaLinearVelocity.mVec128.m128_f32[0] = v210;
            angVel.mVec128.m128_f32[0] = bodyA->m_angularFactor.mVec128.m128_f32[0] * v317;
            angVel.mVec128.m128_f32[1] = bodyA->m_angularFactor.mVec128.m128_f32[1] * v317;
            v211 = angVel.mVec128.m128_f32[0] * v207;
            v212 = (float)(angVel.mVec128.m128_f32[1] * v208) + bodyA->m_deltaAngularVelocity.mVec128.m128_f32[1];
            v213 = bodyA->m_deltaAngularVelocity.mVec128.m128_f32[0] + v211;
            bodyA->m_deltaAngularVelocity.mVec128.m128_f32[2] = (float)((float)(bodyA->m_angularFactor.mVec128.m128_f32[2]
                                                                              * v317)
                                                                      * v209)
                                                              + bodyA->m_deltaAngularVelocity.mVec128.m128_f32[2];
            v205 = angvel.mVec128.m128_f32[2];
            bodyA->m_deltaAngularVelocity.mVec128.m128_f32[0] = v213;
            bodyA->m_deltaAngularVelocity.mVec128.m128_f32[1] = v212;
          }
          v214 = (float *)this->m_rbB;
          v215 = v214[70];
          v216 = v214[69];
          v217 = v214[73];
          v214 += 68;
          v218 = -v317;
          v219 = (float)((float)(v215 * v205) + (float)(v216 * v203)) + (float)(v204 * *v214);
          v220 = (float)(v214[6] * v205) + (float)(v217 * v203);
          v221 = v204 * v214[4];
          v222 = v204 * v214[8];
          v223 = v220 + v221;
          v224 = v214[9];
          angVel.mVec128.m128_f32[1] = v223;
          v225 = v224 * v203;
          v226 = v28->m_inverseMass;
          angVel.mVec128.m128_f32[2] = (float)((float)(v214[10] * v205) + v225) + v222;
          if ( v226 != 0.0 )
          {
            v227 = v28->m_deltaLinearVelocity.mVec128.m128_f32[0];
            v228 = (float)(v218 * 0.0) + v28->m_deltaLinearVelocity.mVec128.m128_f32[1];
            v28->m_deltaLinearVelocity.mVec128.m128_f32[2] = (float)(v218 * 0.0)
                                                           + v28->m_deltaLinearVelocity.mVec128.m128_f32[2];
            v28->m_deltaLinearVelocity.mVec128.m128_f32[1] = v228;
            v28->m_deltaLinearVelocity.mVec128.m128_f32[0] = v227 + (float)(v218 * 0.0);
            v229 = (float)(v28->m_angularFactor.mVec128.m128_f32[1] * v218) * angVel.mVec128.m128_f32[1];
            v230 = (float)(v28->m_angularFactor.mVec128.m128_f32[2] * v218) * angVel.mVec128.m128_f32[2];
            v231 = v28->m_deltaAngularVelocity.mVec128.m128_f32[0]
                 + (float)((float)(v28->m_angularFactor.mVec128.m128_f32[0] * v218) * v219);
            v28->m_deltaAngularVelocity.mVec128.m128_f32[1] = v28->m_deltaAngularVelocity.mVec128.m128_f32[1] + v229;
            v232 = v28->m_deltaAngularVelocity.mVec128.m128_f32[2] + v230;
            v28->m_deltaAngularVelocity.mVec128.m128_f32[0] = v231;
            v28->m_deltaAngularVelocity.mVec128.m128_f32[2] = v232;
          }
        }
      }
    }
    v5 = !this->m_solveSwingLimit;
    *(float *)&v233 = v14->m_angularVelocity.mVec128.m128_f32[0] + v14->m_deltaAngularVelocity.mVec128.m128_f32[0];
    v234 = v14->m_angularVelocity.mVec128.m128_f32[1] + v14->m_deltaAngularVelocity.mVec128.m128_f32[1];
    *(float *)&v235 = v14->m_angularVelocity.mVec128.m128_f32[2] + v14->m_deltaAngularVelocity.mVec128.m128_f32[2];
    v236 = v28->m_angularVelocity.mVec128.m128_f32[0] + v28->m_deltaAngularVelocity.mVec128.m128_f32[0];
    v237 = v28->m_angularVelocity.mVec128.m128_f32[1] + v28->m_deltaAngularVelocity.mVec128.m128_f32[1];
    *(float *)&v238 = v28->m_angularVelocity.mVec128.m128_f32[2] + v28->m_deltaAngularVelocity.mVec128.m128_f32[2];
    v319.m128i_i32[0] = v233;
    *(__int64 *)((char *)v319.m128i_i64 + 4) = __PAIR64__(v235, LODWORD(v234));
    v320.m128i_i64[0] = __PAIR64__(LODWORD(v237), LODWORD(v236));
    v320.m128i_i32[2] = v238;
    if ( !v5 )
    {
      v239 = (float)((float)(this->m_biasFactor / timeStep) * this->m_swingCorrection) * this->m_swingLimitRatio;
      v240 = (float)((float)(this->m_swingAxis.mVec128.m128_f32[2]
                           * (float)(*(float *)&v238 - *(float *)&v319.m128i_i32[2]))
                   + (float)(this->m_swingAxis.mVec128.m128_f32[1] * (float)(v237 - v234)))
           + (float)(this->m_swingAxis.mVec128.m128_f32[0] * (float)(v236 - *(float *)&v233));
      if ( v240 > 0.0 )
        v239 = (float)((float)(this->m_relaxationFactor * this->m_swingLimitRatio) * v240) + v239;
      m_accSwingLimitImpulse = this->m_accSwingLimitImpulse;
      v242 = (float)(this->m_kSwing * v239) + m_accSwingLimitImpulse;
      _X = 0.0;
      v313 = v242;
      p_X = &v313;
      if ( v242 <= 0.0 )
        p_X = &_X;
      v244 = *p_X;
      this->m_accSwingLimitImpulse = *p_X;
      v245 = v244 - m_accSwingLimitImpulse;
      v246 = this->m_swingAxis.mVec128.m128_f32[1] * v245;
      v247 = this->m_swingAxis.mVec128.m128_f32[2] * v245;
      v248 = this->m_swingAxis.mVec128.m128_f32[0] * v245;
      v249 = (float)((float)(this->m_twistAxisA.mVec128.m128_f32[2] * v247)
                   + (float)(this->m_twistAxisA.mVec128.m128_f32[1] * v246))
           + (float)(this->m_twistAxisA.mVec128.m128_f32[0] * v248);
      v250 = v249 * this->m_twistAxisA.mVec128.m128_f32[0];
      v251 = v246 - (float)(this->m_twistAxisA.mVec128.m128_f32[1] * v249);
      v318.mVec128.m128_f32[2] = v247 - (float)(this->m_twistAxisA.mVec128.m128_f32[2] * v249);
      v318.mVec128.m128_f32[1] = v251;
      v318.mVec128.m128_f32[0] = v248 - v250;
      v317 = sqrtf(
               (float)((float)(v318.mVec128.m128_f32[2] * v318.mVec128.m128_f32[2]) + (float)(v251 * v251))
             + (float)(v318.mVec128.m128_f32[0] * v318.mVec128.m128_f32[0]));
      v252 = (float *)this->m_rbA;
      v253 = v252[70];
      v254 = v252[74];
      v255 = v252[78];
      v256 = v318.mVec128.m128_f32[2] * (float)(*(float *)&clear_value / v317);
      v257 = v14->m_inverseMass;
      v258 = v318.mVec128.m128_f32[0] * (float)(*(float *)&clear_value / v317);
      v259 = v318.mVec128.m128_f32[1] * (float)(*(float *)&clear_value / v317);
      v260 = v252[69];
      v252 += 68;
      v261 = (float)((float)(v253 * v256) + (float)(v260 * v259)) + (float)(v258 * *v252);
      v262 = (float)((float)(v254 * v256) + (float)(v252[5] * v259)) + (float)(v252[4] * v258);
      v263 = (float)((float)(v255 * v256) + (float)(v252[9] * v259)) + (float)(v252[8] * v258);
      angvel.mVec128.m128_f32[2] = v256;
      if ( v257 != 0.0 )
      {
        v264 = v14->m_deltaLinearVelocity.mVec128.m128_f32[0] + (float)(v317 * 0.0);
        angVel.mVec128.m128_f32[1] = v317 * 0.0;
        angVel.mVec128.m128_f32[2] = v317 * 0.0;
        v14->m_deltaLinearVelocity.mVec128.m128_f32[1] = v14->m_deltaLinearVelocity.mVec128.m128_f32[1]
                                                       + (float)(v317 * 0.0);
        v14->m_deltaLinearVelocity.mVec128.m128_f32[2] = v14->m_deltaLinearVelocity.mVec128.m128_f32[2]
                                                       + angVel.mVec128.m128_f32[2];
        v14->m_deltaLinearVelocity.mVec128.m128_f32[0] = v264;
        angVel.mVec128.m128_f32[0] = v14->m_angularFactor.mVec128.m128_f32[0] * v317;
        angVel.mVec128.m128_f32[1] = v14->m_angularFactor.mVec128.m128_f32[1] * v317;
        v265 = angVel.mVec128.m128_f32[0] * v261;
        v266 = (float)(angVel.mVec128.m128_f32[1] * v262) + v14->m_deltaAngularVelocity.mVec128.m128_f32[1];
        v267 = v14->m_deltaAngularVelocity.mVec128.m128_f32[0] + v265;
        v14->m_deltaAngularVelocity.mVec128.m128_f32[2] = (float)((float)(v14->m_angularFactor.mVec128.m128_f32[2] * v317)
                                                                * v263)
                                                        + v14->m_deltaAngularVelocity.mVec128.m128_f32[2];
        v256 = angvel.mVec128.m128_f32[2];
        v14->m_deltaAngularVelocity.mVec128.m128_f32[0] = v267;
        v14->m_deltaAngularVelocity.mVec128.m128_f32[1] = v266;
      }
      v268 = (float *)this->m_rbB;
      v269 = v268[70];
      v270 = v268[69];
      v271 = v268[73];
      v268 += 68;
      v272 = -v317;
      v273 = (float)((float)(v269 * v256) + (float)(v270 * v259)) + (float)(v258 * *v268);
      v274 = (float)((float)(v268[6] * v256) + (float)(v271 * v259)) + (float)(v268[4] * v258);
      v275 = v268[9];
      angVel.mVec128.m128_f32[1] = v274;
      angVel.mVec128.m128_f32[2] = (float)((float)(v268[10] * v256) + (float)(v275 * v259)) + (float)(v268[8] * v258);
      v276 = -v317;
      if ( v28->m_inverseMass != 0.0 )
      {
        v28->m_deltaLinearVelocity.mVec128.m128_f32[0] = (float)(v272 * 0.0)
                                                       + v28->m_deltaLinearVelocity.mVec128.m128_f32[0];
        v277 = (float)(v272 * 0.0) + v28->m_deltaLinearVelocity.mVec128.m128_f32[2];
        v28->m_deltaLinearVelocity.mVec128.m128_f32[1] = (float)(v272 * 0.0)
                                                       + v28->m_deltaLinearVelocity.mVec128.m128_f32[1];
        v28->m_deltaLinearVelocity.mVec128.m128_f32[2] = v277;
        v278 = (float)((float)(v28->m_angularFactor.mVec128.m128_f32[1] * v276) * angVel.mVec128.m128_f32[1])
             + v28->m_deltaAngularVelocity.mVec128.m128_f32[1];
        v279 = (float)((float)(v28->m_angularFactor.mVec128.m128_f32[2] * v276) * angVel.mVec128.m128_f32[2])
             + v28->m_deltaAngularVelocity.mVec128.m128_f32[2];
        v28->m_deltaAngularVelocity.mVec128.m128_f32[0] = v28->m_deltaAngularVelocity.mVec128.m128_f32[0]
                                                        + (float)((float)(v28->m_angularFactor.mVec128.m128_f32[0] * v276)
                                                                * v273);
        v28->m_deltaAngularVelocity.mVec128.m128_f32[1] = v278;
        v28->m_deltaAngularVelocity.mVec128.m128_f32[2] = v279;
      }
      v233 = v319.m128i_i32[0];
      v234 = *(float *)&v319.m128i_i32[1];
      v236 = *(float *)v320.m128i_i32;
      v237 = *(float *)&v320.m128i_i32[1];
      v238 = v320.m128i_i32[2];
    }
    if ( this->m_solveTwistLimit )
    {
      v280 = (float)((float)(this->m_biasFactor / timeStep) * this->m_twistCorrection) * this->m_twistLimitRatio;
      v281 = (float)((float)(this->m_twistAxis.mVec128.m128_f32[2]
                           * (float)(*(float *)&v238 - *(float *)&v319.m128i_i32[2]))
                   + (float)(this->m_twistAxis.mVec128.m128_f32[1] * (float)(v237 - v234)))
           + (float)((float)(v236 - *(float *)&v233) * this->m_twistAxis.mVec128.m128_f32[0]);
      if ( v281 > 0.0 )
        v280 = (float)((float)(this->m_relaxationFactor * this->m_twistLimitRatio) * v281) + v280;
      m_accTwistLimitImpulse = this->m_accTwistLimitImpulse;
      v283 = (float)(this->m_kTwist * v280) + m_accTwistLimitImpulse;
      _X = 0.0;
      v313 = v283;
      v284 = &v313;
      if ( v283 <= 0.0 )
        v284 = &_X;
      v285 = *v284;
      v286 = (float *)this->m_rbA;
      this->m_accTwistLimitImpulse = v285;
      v287 = this->m_twistAxis.mVec128.m128_f32[1];
      v288 = v286[69];
      v289 = v286[70];
      v290 = v286[74];
      v286 += 68;
      v291 = v285 - m_accTwistLimitImpulse;
      v292 = this->m_twistAxis.mVec128.m128_f32[2];
      v293 = (float)((float)(v288 * v287) + (float)(v289 * v292))
           + (float)(this->m_twistAxis.mVec128.m128_f32[0] * *v286);
      v294 = (float)((float)(v286[5] * v287) + (float)(v290 * v292))
           + (float)(this->m_twistAxis.mVec128.m128_f32[0] * v286[4]);
      v295 = (float)((float)(v286[9] * v287) + (float)(v286[10] * v292))
           + (float)(this->m_twistAxis.mVec128.m128_f32[0] * v286[8]);
      if ( v14->m_inverseMass != 0.0 )
      {
        v14->m_deltaLinearVelocity.mVec128.m128_f32[0] = (float)(v291 * 0.0)
                                                       + v14->m_deltaLinearVelocity.mVec128.m128_f32[0];
        v296 = (float)(v291 * 0.0) + v14->m_deltaLinearVelocity.mVec128.m128_f32[1];
        v14->m_deltaLinearVelocity.mVec128.m128_f32[2] = (float)(v291 * 0.0)
                                                       + v14->m_deltaLinearVelocity.mVec128.m128_f32[2];
        v14->m_deltaLinearVelocity.mVec128.m128_f32[1] = v296;
        v297 = (float)((float)(v14->m_angularFactor.mVec128.m128_f32[1] * v291) * v294)
             + v14->m_deltaAngularVelocity.mVec128.m128_f32[1];
        v298 = (float)((float)(v14->m_angularFactor.mVec128.m128_f32[2] * v291) * v295)
             + v14->m_deltaAngularVelocity.mVec128.m128_f32[2];
        v14->m_deltaAngularVelocity.mVec128.m128_f32[0] = v14->m_deltaAngularVelocity.mVec128.m128_f32[0]
                                                        + (float)((float)(v291 * v14->m_angularFactor.mVec128.m128_f32[0])
                                                                * v293);
        v14->m_deltaAngularVelocity.mVec128.m128_f32[1] = v297;
        v14->m_deltaAngularVelocity.mVec128.m128_f32[2] = v298;
      }
      v299 = (float *)this->m_rbB;
      v300 = this->m_twistAxis.mVec128.m128_f32[1];
      v301 = this->m_twistAxis.mVec128.m128_f32[2];
      v302 = v299[69];
      v303 = v299[70];
      v304 = v299[74];
      v299 += 68;
      v305 = -v291;
      v306 = (float)((float)(v302 * v300) + (float)(v303 * v301))
           + (float)(this->m_twistAxis.mVec128.m128_f32[0] * *v299);
      v307 = (float)((float)(v299[5] * v300) + (float)(v304 * v301))
           + (float)(this->m_twistAxis.mVec128.m128_f32[0] * v299[4]);
      v308 = (float)((float)(v299[9] * v300) + (float)(v299[10] * v301))
           + (float)(this->m_twistAxis.mVec128.m128_f32[0] * v299[8]);
      if ( v28->m_inverseMass != 0.0 )
      {
        v309 = v28->m_deltaLinearVelocity.mVec128.m128_f32[0];
        v310 = (float)(v305 * 0.0) + v28->m_deltaLinearVelocity.mVec128.m128_f32[2];
        v28->m_deltaLinearVelocity.mVec128.m128_f32[1] = (float)(v305 * 0.0)
                                                       + v28->m_deltaLinearVelocity.mVec128.m128_f32[1];
        v28->m_deltaLinearVelocity.mVec128.m128_f32[2] = v310;
        v28->m_deltaLinearVelocity.mVec128.m128_f32[0] = v309 + (float)(v305 * 0.0);
        v311 = (float)((float)(v28->m_angularFactor.mVec128.m128_f32[1] * v305) * v307)
             + v28->m_deltaAngularVelocity.mVec128.m128_f32[1];
        v312 = (float)((float)(v28->m_angularFactor.mVec128.m128_f32[2] * v305) * v308)
             + v28->m_deltaAngularVelocity.mVec128.m128_f32[2];
        v28->m_deltaAngularVelocity.mVec128.m128_f32[0] = (float)((float)(v28->m_angularFactor.mVec128.m128_f32[0] * v305)
                                                                * v306)
                                                        + v28->m_deltaAngularVelocity.mVec128.m128_f32[0];
        v28->m_deltaAngularVelocity.mVec128.m128_f32[1] = v311;
        v28->m_deltaAngularVelocity.mVec128.m128_f32[2] = v312;
      }
    }
  }
}
