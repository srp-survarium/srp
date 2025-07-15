void __userpurge btConeTwistConstraint::calcAngleInfo2(
        const btTransform *transA@<eax>,
        float *a2@<edi>,
        btConeTwistConstraint *this,
        const btTransform *transB,
        const btMatrix3x3 *invInertiaWorldA,
        const btMatrix3x3 *invInertiaWorldB)
{
  bool v6; // zf
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm7_4
  float v15; // xmm7_4
  float v16; // xmm6_4
  float v17; // xmm4_4
  float v18; // xmm3_4
  float v19; // xmm5_4
  float v20; // xmm6_4
  unsigned int v21; // xmm3_4
  unsigned int v22; // xmm4_4
  unsigned int v23; // xmm5_4
  float v24; // xmm7_4
  float v25; // xmm6_4
  float v26; // xmm7_4
  int v27; // xmm6_4
  float v28; // xmm6_4
  float v29; // xmm2_4
  __m128i v30; // xmm0
  float v31; // xmm5_4
  float v32; // xmm4_4
  float v33; // xmm3_4
  btVector3 v34; // xmm0
  float v35; // xmm7_4
  float v36; // xmm1_4
  float v37; // xmm5_4
  float v38; // xmm6_4
  float v39; // xmm1_4
  float v40; // xmm5_4
  float v41; // xmm2_4
  float v42; // xmm1_4
  float v43; // xmm5_4
  float v44; // xmm1_4
  float v45; // xmm4_4
  float v46; // xmm3_4
  float v47; // xmm1_4
  float v48; // xmm4_4
  float v49; // xmm1_4
  float v50; // xmm2_4
  float v51; // xmm1_4
  float v52; // xmm2_4
  float v53; // xmm3_4
  float v54; // xmm4_4
  float v55; // xmm5_4
  float v56; // xmm6_4
  float v57; // xmm7_4
  float v58; // xmm7_4
  btTransform *v59; // eax
  float v60; // xmm4_4
  float v61; // xmm5_4
  float v62; // xmm3_4
  float v63; // xmm2_4
  float v64; // xmm1_4
  float v65; // xmm5_4
  float v66; // xmm4_4
  float v67; // xmm4_4
  float v68; // xmm4_4
  float v69; // xmm7_4
  float v70; // xmm6_4
  __m128i v71; // xmm0
  btMatrix3x3 *v72; // ecx
  float v73; // xmm1_4
  float v74; // xmm1_4
  int v75; // xmm1_4
  long double v76; // st7
  long double v77; // st7
  btMatrix3x3 *v78; // ecx
  btMatrix3x3 *v79; // ecx
  float v80; // xmm3_4
  float v81; // xmm4_4
  float v82; // xmm1_4
  float v83; // xmm7_4
  float v84; // xmm0_4
  float v85; // xmm3_4
  float v86; // xmm4_4
  float v87; // xmm0_4
  long double v88; // st7
  float v89; // xmm3_4
  float v90; // xmm0_4
  float v91; // xmm1_4
  float v92; // xmm2_4
  long double v93; // st7
  long double v94; // st7
  unsigned int v95; // xmm0_4
  unsigned int v96; // xmm1_4
  float v97; // xmm2_4
  float m_fixThresh; // xmm0_4
  float m_swingSpan1; // xmm1_4
  float m_limitSoftness; // xmm3_4
  float v101; // xmm2_4
  float v102; // xmm0_4
  float v103; // xmm1_4
  const vostok::math::float4x4 *v104; // xmm4_4
  float v105; // xmm4_4
  float v106; // xmm5_4
  float v107; // xmm3_4
  float v108; // xmm7_4
  float v109; // xmm0_4
  float v110; // xmm4_4
  float v111; // xmm5_4
  float v112; // xmm6_4
  float v113; // xmm7_4
  float v114; // xmm2_4
  float v115; // xmm3_4
  float v116; // xmm0_4
  unsigned int v117; // xmm4_4
  float v118; // xmm5_4
  float v119; // xmm6_4
  float v120; // xmm1_4
  unsigned int v121; // xmm5_4
  float v122; // xmm6_4
  float v123; // xmm7_4
  float v124; // xmm6_4
  float v125; // xmm1_4
  float v126; // xmm6_4
  float v127; // xmm1_4
  float v128; // xmm6_4
  float v129; // xmm7_4
  float v130; // xmm1_4
  float v131; // xmm7_4
  float v132; // xmm1_4
  float v133; // xmm0_4
  float v134; // xmm2_4
  float v135; // xmm0_4
  float v136; // xmm2_4
  float v137; // xmm3_4
  float v138; // xmm2_4
  float v139; // xmm7_4
  float v140; // xmm0_4
  float v141; // xmm1_4
  float v142; // xmm2_4
  float v143; // xmm3_4
  float v144; // xmm4_4
  float v145; // xmm1_4
  float v146; // xmm6_4
  float v147; // xmm0_4
  float v148; // xmm5_4
  float v149; // xmm2_4
  float m_swingSpan2; // xmm0_4
  bool v151; // cf
  long double v152; // st7
  long double v153; // st7
  float v154; // xmm0_4
  float v155; // xmm1_4
  float v156; // xmm2_4
  float v157; // xmm1_4
  float v158; // xmm2_4
  float v159; // xmm1_4
  float v160; // xmm0_4
  float v161; // xmm1_4
  float m_twistSpan; // xmm5_4
  float v163; // xmm6_4
  float m_twistAngle; // xmm3_4
  float v165; // xmm1_4
  float v166; // xmm0_4
  float v167; // xmm2_4
  float v168; // xmm4_4
  const vostok::math::float4x4 *v169; // xmm7_4
  float v170; // xmm3_4
  float v171; // xmm4_4
  float v172; // xmm0_4
  float v173; // xmm1_4
  float v174; // xmm2_4
  float v176; // xmm1_4
  float v177; // xmm2_4
  float v178; // xmm3_4
  float v179; // xmm4_4
  float v180; // xmm0_4
  float v181; // xmm4_4
  float v182; // xmm6_4
  float v183; // xmm7_4
  float v184; // xmm6_4
  float v185; // xmm7_4
  float v186; // xmm6_4
  float v187; // xmm7_4
  float v188; // xmm0_4
  float v189; // xmm1_4
  float v190; // xmm0_4
  float v191; // xmm1_4
  float _X; // [esp+1988h] [ebp-1A4h]
  float v194; // [esp+199Ch] [ebp-190h]
  float v195; // [esp+199Ch] [ebp-190h]
  float v196; // [esp+199Ch] [ebp-190h]
  float v197; // [esp+19A0h] [ebp-18Ch]
  float v198; // [esp+19A0h] [ebp-18Ch]
  float v199; // [esp+19A4h] [ebp-188h] BYREF
  float v200; // [esp+19A8h] [ebp-184h]
  btMatrix3x3 q; // [esp+19ACh] [ebp-180h] BYREF
  float _Y; // [esp+19DCh] [ebp-150h]
  float v203; // [esp+19E0h] [ebp-14Ch] BYREF
  float v204; // [esp+19E4h] [ebp-148h]
  float v205; // [esp+19E8h] [ebp-144h]
  btMatrix3x3 qTwist; // [esp+19ECh] [ebp-140h] BYREF
  btQuaternion v207; // [esp+1A1Ch] [ebp-110h] BYREF
  btTransform trPose; // [esp+1A2Ch] [ebp-100h] BYREF
  float v209; // [esp+1A6Ch] [ebp-C0h]
  float v210; // [esp+1A70h] [ebp-BCh]
  float v211; // [esp+1A74h] [ebp-B8h]
  float v212; // [esp+1A78h] [ebp-B4h]
  __m128i v213; // [esp+1A7Ch] [ebp-B0h] BYREF
  __m128i v214; // [esp+1A8Ch] [ebp-A0h] BYREF
  __m128i v215; // [esp+1A9Ch] [ebp-90h] BYREF
  btTransform trDeltaAB; // [esp+1AACh] [ebp-80h] BYREF
  btTransform trA; // [esp+1AECh] [ebp-40h] BYREF

  v6 = !this->m_bMotorEnabled;
  *(_QWORD *)&this->m_twistLimitSign = 0;
  this->m_solveTwistLimit = 0;
  this->m_solveSwingLimit = 0;
  if ( v6 || this->m_useSolveConstraintObsolete )
  {
    btMatrix3x3::getRotation(&q, (float *)&this->m_rbAFrame, (btQuaternion *)&q);
    btMatrix3x3::getRotation(v78, (float *)transA, (btQuaternion *)&qTwist);
    trPose.m_origin.mVec128.m128_f32[0] = (float)((float)((float)(qTwist.m_el[0].mVec128.m128_f32[0]
                                                                * q.m_el[0].mVec128.m128_f32[3])
                                                        + (float)(q.m_el[0].mVec128.m128_f32[0]
                                                                * qTwist.m_el[0].mVec128.m128_f32[3]))
                                                + (float)(q.m_el[0].mVec128.m128_f32[2]
                                                        * qTwist.m_el[0].mVec128.m128_f32[1]))
                                        - (float)(qTwist.m_el[0].mVec128.m128_f32[2] * q.m_el[0].mVec128.m128_f32[1]);
    trPose.m_origin.mVec128.m128_f32[1] = (float)((float)((float)(q.m_el[0].mVec128.m128_f32[0]
                                                                * qTwist.m_el[0].mVec128.m128_f32[2])
                                                        + (float)(qTwist.m_el[0].mVec128.m128_f32[1]
                                                                * q.m_el[0].mVec128.m128_f32[3]))
                                                + (float)(q.m_el[0].mVec128.m128_f32[1]
                                                        * qTwist.m_el[0].mVec128.m128_f32[3]))
                                        - (float)(qTwist.m_el[0].mVec128.m128_f32[0] * q.m_el[0].mVec128.m128_f32[2]);
    trPose.m_origin.mVec128.m128_f32[2] = (float)((float)((float)(qTwist.m_el[0].mVec128.m128_f32[0]
                                                                * q.m_el[0].mVec128.m128_f32[1])
                                                        + (float)(qTwist.m_el[0].mVec128.m128_f32[2]
                                                                * q.m_el[0].mVec128.m128_f32[3]))
                                                + (float)(q.m_el[0].mVec128.m128_f32[2]
                                                        * qTwist.m_el[0].mVec128.m128_f32[3]))
                                        - (float)(q.m_el[0].mVec128.m128_f32[0] * qTwist.m_el[0].mVec128.m128_f32[1]);
    trPose.m_origin.mVec128.m128_f32[3] = (float)((float)((float)(q.m_el[0].mVec128.m128_f32[3]
                                                                * qTwist.m_el[0].mVec128.m128_f32[3])
                                                        - (float)(q.m_el[0].mVec128.m128_f32[0]
                                                                * qTwist.m_el[0].mVec128.m128_f32[0]))
                                                - (float)(q.m_el[0].mVec128.m128_f32[1]
                                                        * qTwist.m_el[0].mVec128.m128_f32[1]))
                                        - (float)(q.m_el[0].mVec128.m128_f32[2] * qTwist.m_el[0].mVec128.m128_f32[2]);
    btMatrix3x3::getRotation(v79, (float *)&this->m_rbBFrame, &v207);
    btMatrix3x3::getRotation(&qTwist, (float *)transB, (btQuaternion *)&qTwist);
    v210 = (float)((float)((float)(v207.m_floats[0] * qTwist.m_el[0].mVec128.m128_f32[2])
                         + (float)(qTwist.m_el[0].mVec128.m128_f32[1] * v207.m_floats[3]))
                 + (float)(v207.m_floats[1] * qTwist.m_el[0].mVec128.m128_f32[3]))
         - (float)(qTwist.m_el[0].mVec128.m128_f32[0] * v207.m_floats[2]);
    v211 = (float)((float)((float)(qTwist.m_el[0].mVec128.m128_f32[0] * v207.m_floats[1])
                         + (float)(qTwist.m_el[0].mVec128.m128_f32[2] * v207.m_floats[3]))
                 + (float)(v207.m_floats[2] * qTwist.m_el[0].mVec128.m128_f32[3]))
         - (float)(v207.m_floats[0] * qTwist.m_el[0].mVec128.m128_f32[1]);
    v209 = (float)((float)((float)(qTwist.m_el[0].mVec128.m128_f32[0] * v207.m_floats[3])
                         + (float)(v207.m_floats[0] * qTwist.m_el[0].mVec128.m128_f32[3]))
                 + (float)(v207.m_floats[2] * qTwist.m_el[0].mVec128.m128_f32[1]))
         - (float)(qTwist.m_el[0].mVec128.m128_f32[2] * v207.m_floats[1]);
    qTwist.m_el[2].mVec128.m128_f32[0] = -v210;
    qTwist.m_el[2].mVec128.m128_f32[2] = -v211;
    qTwist.m_el[2].mVec128.m128_f32[1] = -v209;
    v80 = (float)((float)((float)(trPose.m_origin.mVec128.m128_f32[0] * (float)-v211)
                        + (float)((float)-v210 * trPose.m_origin.mVec128.m128_f32[3]))
                + (float)((float)((float)((float)((float)(v207.m_floats[3] * qTwist.m_el[0].mVec128.m128_f32[3])
                                                - (float)(v207.m_floats[0] * qTwist.m_el[0].mVec128.m128_f32[0]))
                                        - (float)(v207.m_floats[1] * qTwist.m_el[0].mVec128.m128_f32[1]))
                                - (float)(v207.m_floats[2] * qTwist.m_el[0].mVec128.m128_f32[2]))
                        * trPose.m_origin.mVec128.m128_f32[1]))
        - (float)(trPose.m_origin.mVec128.m128_f32[2] * (float)-v209);
    v212 = (float)((float)((float)(v207.m_floats[3] * qTwist.m_el[0].mVec128.m128_f32[3])
                         - (float)(v207.m_floats[0] * qTwist.m_el[0].mVec128.m128_f32[0]))
                 - (float)(v207.m_floats[1] * qTwist.m_el[0].mVec128.m128_f32[1]))
         - (float)(v207.m_floats[2] * qTwist.m_el[0].mVec128.m128_f32[2]);
    trPose.m_basis.m_el[1].mVec128.m128_f32[0] = (float)((float)((float)(trPose.m_origin.mVec128.m128_f32[0] * v212)
                                                               + (float)(trPose.m_origin.mVec128.m128_f32[3]
                                                                       * (float)-v209))
                                                       + (float)((float)-v210 * trPose.m_origin.mVec128.m128_f32[2]))
                                               - (float)((float)-v211 * trPose.m_origin.mVec128.m128_f32[1]);
    trPose.m_basis.m_el[1].mVec128.m128_f32[1] = (float)((float)((float)(trPose.m_origin.mVec128.m128_f32[0]
                                                                       * (float)-v211)
                                                               + (float)((float)-v210
                                                                       * trPose.m_origin.mVec128.m128_f32[3]))
                                                       + (float)(v212 * trPose.m_origin.mVec128.m128_f32[1]))
                                               - (float)(trPose.m_origin.mVec128.m128_f32[2] * (float)-v209);
    v81 = (float)((float)((float)(trPose.m_origin.mVec128.m128_f32[1] * (float)-v209)
                        + (float)((float)-v211 * trPose.m_origin.mVec128.m128_f32[3]))
                + (float)(v212 * trPose.m_origin.mVec128.m128_f32[2]))
        - (float)(trPose.m_origin.mVec128.m128_f32[0] * (float)-v210);
    v82 = (float)((float)((float)(v212 * trPose.m_origin.mVec128.m128_f32[3])
                        - (float)(trPose.m_origin.mVec128.m128_f32[0] * (float)-v209))
                - (float)((float)-v210 * trPose.m_origin.mVec128.m128_f32[1]))
        - (float)((float)-v211 * trPose.m_origin.mVec128.m128_f32[2]);
    v83 = (float)((float)(v80 * vTwist.mVec128.m128_f32[2])
                + (float)((float)((float)((float)((float)(v212 * trPose.m_origin.mVec128.m128_f32[3])
                                                - (float)(trPose.m_origin.mVec128.m128_f32[0] * (float)-v209))
                                        - (float)(qTwist.m_el[2].mVec128.m128_f32[0]
                                                * trPose.m_origin.mVec128.m128_f32[1]))
                                - (float)((float)-v211 * trPose.m_origin.mVec128.m128_f32[2]))
                        * vTwist.mVec128.m128_f32[0]))
        - (float)((float)((float)((float)((float)(trPose.m_origin.mVec128.m128_f32[1] * (float)-v209)
                                        + (float)((float)-v211 * trPose.m_origin.mVec128.m128_f32[3]))
                                + (float)(v212 * trPose.m_origin.mVec128.m128_f32[2]))
                        - (float)(trPose.m_origin.mVec128.m128_f32[0] * qTwist.m_el[2].mVec128.m128_f32[0]))
                * vTwist.mVec128.m128_f32[1]);
    qTwist.m_el[0].mVec128.m128_f32[1] = (float)((float)((float)((float)((float)((float)(v212
                                                                                       * trPose.m_origin.mVec128.m128_f32[3])
                                                                               - (float)(trPose.m_origin.mVec128.m128_f32[0]
                                                                                       * (float)-v209))
                                                                       - (float)(qTwist.m_el[2].mVec128.m128_f32[0]
                                                                               * trPose.m_origin.mVec128.m128_f32[1]))
                                                               - (float)((float)-v211
                                                                       * trPose.m_origin.mVec128.m128_f32[2]))
                                                       * vTwist.mVec128.m128_f32[1])
                                               + (float)((float)((float)((float)((float)(trPose.m_origin.mVec128.m128_f32[1]
                                                                                       * (float)-v209)
                                                                               + (float)((float)-v211
                                                                                       * trPose.m_origin.mVec128.m128_f32[3]))
                                                                       + (float)(v212
                                                                               * trPose.m_origin.mVec128.m128_f32[2]))
                                                               - (float)(trPose.m_origin.mVec128.m128_f32[0]
                                                                       * qTwist.m_el[2].mVec128.m128_f32[0]))
                                                       * vTwist.mVec128.m128_f32[0]))
                                       - (float)(trPose.m_basis.m_el[1].mVec128.m128_f32[0] * vTwist.mVec128.m128_f32[2]);
    qTwist.m_el[0].mVec128.m128_f32[2] = (float)((float)(v82 * vTwist.mVec128.m128_f32[2])
                                               + (float)(trPose.m_basis.m_el[1].mVec128.m128_f32[0]
                                                       * vTwist.mVec128.m128_f32[1]))
                                       - (float)(v80 * vTwist.mVec128.m128_f32[0]);
    v84 = (float)((float)-(float)(trPose.m_basis.m_el[1].mVec128.m128_f32[0] * vTwist.mVec128.m128_f32[0])
                - (float)(v80 * vTwist.mVec128.m128_f32[1]))
        - (float)(v81 * vTwist.mVec128.m128_f32[2]);
    v85 = -v80;
    trPose.m_basis.m_el[1].mVec128.m128_f32[2] = v81;
    v86 = -v81;
    q.m_el[0].mVec128.m128_f32[0] = -trPose.m_basis.m_el[1].mVec128.m128_f32[0];
    trPose.m_basis.m_el[1].mVec128.m128_f32[3] = v82;
    qTwist.m_el[1].mVec128.m128_f32[3] = (float)((float)((float)(v85 * v83) + (float)(v86 * v84))
                                               + (float)(qTwist.m_el[0].mVec128.m128_f32[2] * v82))
                                       - (float)(qTwist.m_el[0].mVec128.m128_f32[1]
                                               * (float)-trPose.m_basis.m_el[1].mVec128.m128_f32[0]);
    qTwist.m_el[2].mVec128.m128_f32[3] = (float)((float)((float)(qTwist.m_el[0].mVec128.m128_f32[2]
                                                               * (float)-trPose.m_basis.m_el[1].mVec128.m128_f32[0])
                                                       + (float)(v85 * v84))
                                               + (float)(qTwist.m_el[0].mVec128.m128_f32[1] * v82))
                                       - (float)(v86 * v83);
    qTwist.m_el[0].mVec128.m128_f32[0] = (float)((float)((float)(v84 * (float)-trPose.m_basis.m_el[1].mVec128.m128_f32[0])
                                                       + (float)(v82 * v83))
                                               + (float)(v86 * qTwist.m_el[0].mVec128.m128_f32[1]))
                                       - (float)(v85 * qTwist.m_el[0].mVec128.m128_f32[2]);
    v199 = 1.0
         / sqrtf(
             (float)((float)(qTwist.m_el[0].mVec128.m128_f32[0] * qTwist.m_el[0].mVec128.m128_f32[0])
                   + (float)(qTwist.m_el[2].mVec128.m128_f32[3] * qTwist.m_el[2].mVec128.m128_f32[3]))
           + (float)(qTwist.m_el[1].mVec128.m128_f32[3] * qTwist.m_el[1].mVec128.m128_f32[3]));
    q.m_el[2].mVec128.m128_f32[0] = (float)((float)(v199 * qTwist.m_el[1].mVec128.m128_f32[3])
                                          * vTwist.mVec128.m128_f32[1])
                                  - (float)((float)(qTwist.m_el[2].mVec128.m128_f32[3] * v199)
                                          * vTwist.mVec128.m128_f32[2]);
    q.m_el[2].mVec128.m128_f32[1] = (float)((float)(qTwist.m_el[0].mVec128.m128_f32[0] * v199)
                                          * vTwist.mVec128.m128_f32[2])
                                  - (float)((float)(v199 * qTwist.m_el[1].mVec128.m128_f32[3])
                                          * vTwist.mVec128.m128_f32[0]);
    v87 = (float)((float)((float)(v199 * qTwist.m_el[1].mVec128.m128_f32[3]) * vTwist.mVec128.m128_f32[2])
                + (float)((float)(qTwist.m_el[2].mVec128.m128_f32[3] * v199) * vTwist.mVec128.m128_f32[1]))
        + (float)((float)(qTwist.m_el[0].mVec128.m128_f32[0] * v199) * vTwist.mVec128.m128_f32[0]);
    q.m_el[2].mVec128.m128_f32[2] = (float)((float)(qTwist.m_el[2].mVec128.m128_f32[3] * v199)
                                          * vTwist.mVec128.m128_f32[0])
                                  - (float)((float)(qTwist.m_el[0].mVec128.m128_f32[0] * v199)
                                          * vTwist.mVec128.m128_f32[1]);
    if ( v87 >= -0.9999998807907104 )
    {
      v94 = sqrtf((float)(v87 + *(float *)&clear_value) * 2.0);
      v199 = v94;
      trPose.m_basis.m_el[0].mVec128.m128_f32[3] = v94 * 0.5;
      v90 = q.m_el[2].mVec128.m128_f32[0] * (float)(*(float *)&clear_value / v199);
      v91 = q.m_el[2].mVec128.m128_f32[1] * (float)(*(float *)&clear_value / v199);
      v92 = q.m_el[2].mVec128.m128_f32[2] * (float)(*(float *)&clear_value / v199);
      v89 = trPose.m_basis.m_el[0].mVec128.m128_f32[3];
    }
    else if ( fabsf(vTwist.mVec128.m128_f32[2]) <= hsqt2 )
    {
      v93 = 1.0
          / sqrtf(
              (float)(vTwist.mVec128.m128_f32[1] * vTwist.mVec128.m128_f32[1])
            + (float)(vTwist.mVec128.m128_f32[0] * vTwist.mVec128.m128_f32[0]));
      v89 = 0.0;
      v92 = 0.0;
      trPose.m_basis.m_el[0].mVec128.m128_i32[3] = 0;
      q.m_el[2].mVec128.m128_f32[0] = -(vTwist.mVec128.m128_f32[1] * v93);
      v90 = q.m_el[2].mVec128.m128_f32[0];
      q.m_el[2].mVec128.m128_f32[1] = v93 * vTwist.mVec128.m128_f32[0];
      v91 = q.m_el[2].mVec128.m128_f32[1];
    }
    else
    {
      v88 = 1.0
          / sqrtf(
              (float)(vTwist.mVec128.m128_f32[2] * vTwist.mVec128.m128_f32[2])
            + (float)(vTwist.mVec128.m128_f32[1] * vTwist.mVec128.m128_f32[1]));
      v89 = 0.0;
      v90 = 0.0;
      trPose.m_basis.m_el[0].mVec128.m128_i32[3] = 0;
      q.m_el[2].mVec128.m128_f32[1] = -(vTwist.mVec128.m128_f32[2] * v88);
      v91 = q.m_el[2].mVec128.m128_f32[1];
      q.m_el[2].mVec128.m128_f32[2] = v88 * vTwist.mVec128.m128_f32[1];
      v92 = q.m_el[2].mVec128.m128_f32[2];
    }
    *(unsigned __int64 *)((char *)trPose.m_basis.m_el[0].mVec128.m128_u64 + 4) = __PAIR64__(LODWORD(v92), LODWORD(v91));
    trPose.m_basis.m_el[0].mVec128.m128_f32[0] = v90;
    v199 = 1.0
         / sqrtf((float)((float)((float)(v89 * v89) + (float)(v92 * v92)) + (float)(v91 * v91)) + (float)(v90 * v90));
    trPose.m_basis.m_el[0].mVec128.m128_f32[2] = trPose.m_basis.m_el[0].mVec128.m128_f32[2] * v199;
    trPose.m_basis.m_el[0].mVec128.m128_f32[0] = trPose.m_basis.m_el[0].mVec128.m128_f32[0] * v199;
    trPose.m_basis.m_el[0].mVec128.m128_f32[1] = trPose.m_basis.m_el[0].mVec128.m128_f32[1] * v199;
    *(float *)&v95 = (float)((float)((float)((float)(trPose.m_basis.m_el[0].mVec128.m128_f32[3] * v199)
                                           * trPose.m_basis.m_el[1].mVec128.m128_f32[0])
                                   + (float)((float)-trPose.m_basis.m_el[0].mVec128.m128_f32[1]
                                           * trPose.m_basis.m_el[1].mVec128.m128_f32[2]))
                           + (float)(trPose.m_basis.m_el[1].mVec128.m128_f32[3]
                                   * COERCE_FLOAT(trPose.m_basis.m_el[0].mVec128.m128_i32[0] ^ 0x80000000)))
                   - (float)((float)-trPose.m_basis.m_el[0].mVec128.m128_f32[2]
                           * trPose.m_basis.m_el[1].mVec128.m128_f32[1]);
    *(float *)&v96 = (float)((float)((float)((float)-trPose.m_basis.m_el[0].mVec128.m128_f32[2]
                                           * trPose.m_basis.m_el[1].mVec128.m128_f32[0])
                                   + (float)((float)-trPose.m_basis.m_el[0].mVec128.m128_f32[1]
                                           * trPose.m_basis.m_el[1].mVec128.m128_f32[3]))
                           + (float)((float)(trPose.m_basis.m_el[0].mVec128.m128_f32[3] * v199)
                                   * trPose.m_basis.m_el[1].mVec128.m128_f32[1]))
                   - (float)(trPose.m_basis.m_el[1].mVec128.m128_f32[2]
                           * COERCE_FLOAT(trPose.m_basis.m_el[0].mVec128.m128_i32[0] ^ 0x80000000));
    q.m_el[0].mVec128.m128_f32[2] = -trPose.m_basis.m_el[0].mVec128.m128_f32[2];
    v97 = (float)((float)((float)-trPose.m_basis.m_el[0].mVec128.m128_f32[2] * trPose.m_basis.m_el[1].mVec128.m128_f32[3])
                + (float)((float)(trPose.m_basis.m_el[0].mVec128.m128_f32[3] * v199)
                        * trPose.m_basis.m_el[1].mVec128.m128_f32[2]))
        + (float)(trPose.m_basis.m_el[1].mVec128.m128_f32[1]
                * COERCE_FLOAT(trPose.m_basis.m_el[0].mVec128.m128_i32[0] ^ 0x80000000));
    trPose.m_basis.m_el[0].mVec128.m128_f32[3] = trPose.m_basis.m_el[0].mVec128.m128_f32[3] * v199;
    qTwist.m_el[0].mVec128.m128_u64[0] = __PAIR64__(v96, v95);
    qTwist.m_el[0].mVec128.m128_f32[2] = v97
                                       - (float)((float)-trPose.m_basis.m_el[0].mVec128.m128_f32[1]
                                               * trPose.m_basis.m_el[1].mVec128.m128_f32[0]);
    qTwist.m_el[0].mVec128.m128_f32[3] = (float)((float)((float)(trPose.m_basis.m_el[0].mVec128.m128_f32[3]
                                                               * trPose.m_basis.m_el[1].mVec128.m128_f32[3])
                                                       - (float)(COERCE_FLOAT(
                                                                   trPose.m_basis.m_el[0].mVec128.m128_i32[0]
                                                                 ^ 0x80000000)
                                                               * trPose.m_basis.m_el[1].mVec128.m128_f32[0]))
                                               - (float)((float)-trPose.m_basis.m_el[0].mVec128.m128_f32[1]
                                                       * trPose.m_basis.m_el[1].mVec128.m128_f32[1]))
                                       - (float)((float)-trPose.m_basis.m_el[0].mVec128.m128_f32[2]
                                               * trPose.m_basis.m_el[1].mVec128.m128_f32[2]);
    v199 = 1.0
         / sqrtf(
             (float)((float)((float)(qTwist.m_el[0].mVec128.m128_f32[3] * qTwist.m_el[0].mVec128.m128_f32[3])
                           + (float)(qTwist.m_el[0].mVec128.m128_f32[2] * qTwist.m_el[0].mVec128.m128_f32[2]))
                   + (float)(*(float *)&v96 * *(float *)&v96))
           + (float)(*(float *)&v95 * *(float *)&v95));
    qTwist.m_el[0].mVec128.m128_f32[0] = qTwist.m_el[0].mVec128.m128_f32[0] * v199;
    qTwist.m_el[0].mVec128.m128_f32[1] = qTwist.m_el[0].mVec128.m128_f32[1] * v199;
    qTwist.m_el[0].mVec128.m128_f32[2] = qTwist.m_el[0].mVec128.m128_f32[2] * v199;
    m_fixThresh = this->m_fixThresh;
    qTwist.m_el[0].mVec128.m128_f32[3] = qTwist.m_el[0].mVec128.m128_f32[3] * v199;
    m_swingSpan1 = this->m_swingSpan1;
    v196 = m_swingSpan1;
    v204 = m_fixThresh;
    if ( m_swingSpan1 < m_fixThresh || this->m_swingSpan2 < m_fixThresh )
    {
      v112 = this->m_rbAFrame.m_basis.m_el[1].mVec128.m128_f32[0];
      v113 = this->m_rbAFrame.m_basis.m_el[2].mVec128.m128_f32[0];
      v114 = transA->m_basis.m_el[0].mVec128.m128_f32[2];
      v115 = transA->m_basis.m_el[0].mVec128.m128_f32[1];
      v116 = transA->m_basis.m_el[0].mVec128.m128_f32[0];
      *(float *)&v117 = (float)((float)(v115 * v112) + (float)(v114 * v113))
                      + (float)(this->m_rbAFrame.m_basis.m_el[0].mVec128.m128_f32[0]
                              * transA->m_basis.m_el[0].mVec128.m128_f32[0]);
      v118 = (float)(transA->m_basis.m_el[1].mVec128.m128_f32[2] * v113)
           + (float)(transA->m_basis.m_el[1].mVec128.m128_f32[1] * v112);
      v119 = this->m_rbAFrame.m_basis.m_el[0].mVec128.m128_f32[0];
      v120 = v119 * transA->m_basis.m_el[2].mVec128.m128_f32[0];
      *(float *)&v121 = v118 + (float)(v119 * transA->m_basis.m_el[1].mVec128.m128_f32[0]);
      v122 = this->m_rbAFrame.m_basis.m_el[1].mVec128.m128_f32[0];
      v199 = transA->m_basis.m_el[2].mVec128.m128_f32[2] * v113;
      v123 = this->m_rbAFrame.m_basis.m_el[1].mVec128.m128_f32[1];
      v124 = (float)(v199 + (float)(transA->m_basis.m_el[2].mVec128.m128_f32[1] * v122)) + v120;
      v125 = this->m_rbAFrame.m_basis.m_el[0].mVec128.m128_f32[1];
      trPose.m_basis.m_el[1].mVec128.m128_f32[2] = v124;
      v126 = (float)(v116 * v125) + (float)(v115 * v123);
      v127 = this->m_rbAFrame.m_basis.m_el[2].mVec128.m128_f32[1];
      v128 = v126 + (float)(v114 * v127);
      v129 = transA->m_basis.m_el[2].mVec128.m128_f32[2];
      q.m_el[2].mVec128.m128_f32[1] = (float)((float)(transA->m_basis.m_el[1].mVec128.m128_f32[2] * v127)
                                            + (float)(transA->m_basis.m_el[1].mVec128.m128_f32[1]
                                                    * this->m_rbAFrame.m_basis.m_el[1].mVec128.m128_f32[1]))
                                    + (float)(transA->m_basis.m_el[1].mVec128.m128_f32[0]
                                            * this->m_rbAFrame.m_basis.m_el[0].mVec128.m128_f32[1]);
      v130 = (float)((float)(v129 * this->m_rbAFrame.m_basis.m_el[2].mVec128.m128_f32[1])
                   + (float)(transA->m_basis.m_el[2].mVec128.m128_f32[1]
                           * this->m_rbAFrame.m_basis.m_el[1].mVec128.m128_f32[1]))
           + (float)(transA->m_basis.m_el[2].mVec128.m128_f32[0] * this->m_rbAFrame.m_basis.m_el[0].mVec128.m128_f32[1]);
      v131 = this->m_rbAFrame.m_basis.m_el[1].mVec128.m128_f32[2];
      q.m_el[2].mVec128.m128_f32[2] = v130;
      v132 = this->m_rbAFrame.m_basis.m_el[0].mVec128.m128_f32[2];
      trPose.m_basis.m_el[1].mVec128.m128_u64[0] = __PAIR64__(v121, v117);
      q.m_el[2].mVec128.m128_f32[0] = v128;
      q.m_el[0].mVec128.m128_f32[1] = v131;
      q.m_el[0].mVec128.m128_i32[2] = this->m_rbAFrame.m_basis.m_el[2].mVec128.m128_i32[2];
      v133 = (float)((float)(v116 * v132) + (float)(v115 * v131)) + (float)(v114 * q.m_el[0].mVec128.m128_f32[2]);
      v134 = transA->m_basis.m_el[1].mVec128.m128_f32[1];
      trPose.m_basis.m_el[0].mVec128.m128_f32[0] = v133;
      v135 = (float)((float)(transA->m_basis.m_el[1].mVec128.m128_f32[2] * q.m_el[0].mVec128.m128_f32[2])
                   + (float)(v134 * v131))
           + (float)(transA->m_basis.m_el[1].mVec128.m128_f32[0] * v132);
      v136 = transA->m_basis.m_el[2].mVec128.m128_f32[1];
      trPose.m_basis.m_el[0].mVec128.m128_f32[1] = v135;
      v137 = this->m_rbBFrame.m_basis.m_el[2].mVec128.m128_f32[0];
      v138 = v136 * v131;
      v139 = this->m_rbBFrame.m_basis.m_el[1].mVec128.m128_f32[0];
      trPose.m_basis.m_el[0].mVec128.m128_f32[2] = (float)((float)(transA->m_basis.m_el[2].mVec128.m128_f32[2]
                                                                 * q.m_el[0].mVec128.m128_f32[2])
                                                         + v138)
                                                 + (float)(transA->m_basis.m_el[2].mVec128.m128_f32[0] * v132);
      v140 = this->m_rbBFrame.m_basis.m_el[0].mVec128.m128_f32[0];
      v141 = (float)((float)(transB->m_basis.m_el[0].mVec128.m128_f32[2] * v137)
                   + (float)(transB->m_basis.m_el[0].mVec128.m128_f32[1] * v139))
           + (float)(transB->m_basis.m_el[0].mVec128.m128_f32[0] * v140);
      v142 = (float)((float)(transB->m_basis.m_el[1].mVec128.m128_f32[2] * v137)
                   + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[1] * v139))
           + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[0] * v140);
      v143 = (float)((float)(transB->m_basis.m_el[2].mVec128.m128_f32[2]
                           * this->m_rbBFrame.m_basis.m_el[2].mVec128.m128_f32[0])
                   + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[1] * v139))
           + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[0] * v140);
      v200 = (float)((float)(v143 * trPose.m_basis.m_el[1].mVec128.m128_f32[2]) + (float)(v142 * *(float *)&v121))
           + (float)(v141 * *(float *)&v117);
      v207.m_floats[2] = v143;
      v207.m_floats[0] = v141;
      v207.m_floats[1] = v142;
      _Y = (float)((float)(v143 * q.m_el[2].mVec128.m128_f32[2]) + (float)(v142 * q.m_el[2].mVec128.m128_f32[1]))
         + (float)(v141 * v128);
      q.m_el[1].mVec128.m128_f32[3] = (float)((float)(v143 * trPose.m_basis.m_el[0].mVec128.m128_f32[2])
                                            + (float)(v142 * trPose.m_basis.m_el[0].mVec128.m128_f32[1]))
                                    + (float)(v141 * trPose.m_basis.m_el[0].mVec128.m128_f32[0]);
      if ( v204 <= v196 || v204 <= this->m_swingSpan2 )
      {
        if ( v204 <= v196 )
        {
          if ( fabsf(q.m_el[1].mVec128.m128_f32[3]) >= 0.00000011920929 )
          {
            v151 = v196 < v204;
            this->m_solveSwingLimit = 1;
            if ( !v151 )
            {
              q.m_el[1].mVec128.m128_i32[3] = 0;
              v153 = atan2f(_Y, v200);
              v199 = v153;
              if ( v153 <= v196 )
              {
                if ( (float)-v196 > v199 )
                {
                  v200 = cosf(v196);
                  _Y = -sinf(v196);
                }
              }
              else
              {
                v200 = cosf(v196);
                _Y = sinf(v196);
              }
            }
          }
        }
        else if ( fabsf(_Y) >= 0.00000011920929 )
        {
          m_swingSpan2 = this->m_swingSpan2;
          v151 = m_swingSpan2 < v204;
          this->m_solveSwingLimit = 1;
          if ( !v151 )
          {
            _Y = 0.0;
            v152 = atan2f(q.m_el[1].mVec128.m128_f32[3], v200);
            v199 = v152;
            if ( v152 <= m_swingSpan2 )
            {
              if ( (float)-m_swingSpan2 > v199 )
              {
                v200 = cosf(m_swingSpan2);
                q.m_el[1].mVec128.m128_f32[3] = -sinf(m_swingSpan2);
              }
            }
            else
            {
              v200 = cosf(m_swingSpan2);
              q.m_el[1].mVec128.m128_f32[3] = sinf(m_swingSpan2);
            }
          }
        }
        v154 = (float)((float)(q.m_el[1].mVec128.m128_f32[3] * trPose.m_basis.m_el[0].mVec128.m128_f32[0])
                     + (float)(_Y * q.m_el[2].mVec128.m128_f32[0]))
             + (float)(v200 * trPose.m_basis.m_el[1].mVec128.m128_f32[0]);
        v155 = (float)((float)(trPose.m_basis.m_el[0].mVec128.m128_f32[1] * q.m_el[1].mVec128.m128_f32[3])
                     + (float)(q.m_el[2].mVec128.m128_f32[1] * _Y))
             + (float)(trPose.m_basis.m_el[1].mVec128.m128_f32[1] * v200);
        v156 = (float)((float)(trPose.m_basis.m_el[0].mVec128.m128_f32[2] * q.m_el[1].mVec128.m128_f32[3])
                     + (float)(q.m_el[2].mVec128.m128_f32[2] * _Y))
             + (float)(trPose.m_basis.m_el[1].mVec128.m128_f32[2] * v200);
        q.m_el[0].mVec128.m128_f32[2] = v156;
        q.m_el[0].mVec128.m128_f32[1] = v155;
        q.m_el[0].mVec128.m128_f32[0] = v154;
        v199 = 1.0 / sqrtf((float)((float)(v156 * v156) + (float)(v155 * v155)) + (float)(v154 * v154));
        v157 = (float)(q.m_el[0].mVec128.m128_f32[0] * v199) * v207.m_floats[2];
        v158 = (float)((float)(q.m_el[0].mVec128.m128_f32[1] * v199) * v207.m_floats[0])
             - (float)((float)(q.m_el[0].mVec128.m128_f32[0] * v199) * v207.m_floats[1]);
        q.m_el[0].mVec128.m128_f32[0] = -(float)((float)((float)(q.m_el[0].mVec128.m128_f32[2] * v199) * v207.m_floats[1])
                                               - (float)((float)(q.m_el[0].mVec128.m128_f32[1] * v199) * v207.m_floats[2]));
        q.m_el[0].mVec128.m128_i32[3] = 0;
        q.m_el[0].mVec128.m128_f32[1] = -(float)(v157
                                               - (float)((float)(q.m_el[0].mVec128.m128_f32[2] * v199) * v207.m_floats[0]));
        this->m_swingAxis.mVec128.m128_u64[0] = q.m_el[0].mVec128.m128_u64[0];
        q.m_el[0].mVec128.m128_f32[2] = -v158;
        this->m_swingAxis.mVec128.m128_u64[1] = q.m_el[0].mVec128.m128_u64[1];
        this->m_swingCorrection = sqrtf(
                                    (float)((float)(this->m_swingAxis.mVec128.m128_f32[0]
                                                  * this->m_swingAxis.mVec128.m128_f32[0])
                                          + (float)(this->m_swingAxis.mVec128.m128_f32[1]
                                                  * this->m_swingAxis.mVec128.m128_f32[1]))
                                  + (float)(this->m_swingAxis.mVec128.m128_f32[2] * this->m_swingAxis.mVec128.m128_f32[2]));
        v159 = this->m_swingAxis.mVec128.m128_f32[1];
        v160 = this->m_swingAxis.mVec128.m128_f32[2];
        qTwist.m_el[2].mVec128.m128_i32[3] = this->m_swingAxis.mVec128.m128_i32[0];
        qTwist.m_el[1].mVec128.m128_f32[3] = v159;
        v205 = v160;
        v199 = 1.0
             / sqrtf(
                 (float)((float)(qTwist.m_el[2].mVec128.m128_f32[3] * qTwist.m_el[2].mVec128.m128_f32[3])
                       + (float)(v159 * v159))
               + (float)(v160 * v160));
        v161 = v199;
        this->m_swingAxis.mVec128.m128_f32[0] = qTwist.m_el[2].mVec128.m128_f32[3] * v199;
        this->m_swingAxis.mVec128.m128_f32[1] = qTwist.m_el[1].mVec128.m128_f32[3] * v161;
        this->m_swingAxis.mVec128.m128_f32[2] = v205 * v161;
      }
      else if ( fabsf(_Y) >= 0.00000011920929 || fabsf(q.m_el[1].mVec128.m128_f32[3]) >= 0.00000011920929 )
      {
        v144 = v207.m_floats[1];
        v145 = trPose.m_basis.m_el[1].mVec128.m128_f32[1];
        v146 = v207.m_floats[0];
        v147 = (float)(v207.m_floats[1] * trPose.m_basis.m_el[1].mVec128.m128_f32[2])
             - (float)(v207.m_floats[2] * trPose.m_basis.m_el[1].mVec128.m128_f32[1]);
        v148 = trPose.m_basis.m_el[1].mVec128.m128_f32[0];
        v149 = (float)(v207.m_floats[2] * trPose.m_basis.m_el[1].mVec128.m128_f32[0])
             - (float)(trPose.m_basis.m_el[1].mVec128.m128_f32[2] * v207.m_floats[0]);
        this->m_solveSwingLimit = 1;
        q.m_el[2].mVec128.m128_f32[0] = -v147;
        q.m_el[2].mVec128.m128_i32[3] = 0;
        q.m_el[2].mVec128.m128_f32[1] = -v149;
        this->m_swingAxis.mVec128.m128_u64[0] = q.m_el[2].mVec128.m128_u64[0];
        q.m_el[2].mVec128.m128_f32[2] = -(float)((float)(v145 * v146) - (float)(v144 * v148));
        this->m_swingAxis.mVec128.m128_u64[1] = q.m_el[2].mVec128.m128_u64[1];
      }
    }
    else
    {
      v203 = 0.0;
      btConeTwistConstraint::computeConeLimitInfo((const btQuaternion *)&trPose, q.m_el, this, &v199, &v203);
      m_limitSoftness = this->m_limitSoftness;
      v101 = v203;
      v102 = v199;
      v103 = m_limitSoftness * v203;
      if ( v199 > (float)(m_limitSoftness * v203) )
      {
        v104 = clear_value;
        this->m_solveSwingLimit = 1;
        LODWORD(this->m_swingLimitRatio) = v104;
        if ( v101 > v102 && m_limitSoftness < 0.99999988 )
          this->m_swingLimitRatio = (float)(v102 - v103) / (float)(v101 - v103);
        this->m_swingCorrection = v102 - v103;
        btConeTwistConstraint::adjustSwingAxisToUseEllipseNormal(this, q.m_el);
        v105 = (float)((float)(COERCE_FLOAT(q.m_el[0].mVec128.m128_i32[1] ^ 0x80000000) * v212)
                     + (float)(v211 * COERCE_FLOAT(q.m_el[0].mVec128.m128_i32[0] ^ 0x80000000)))
             - (float)(v209 * COERCE_FLOAT(q.m_el[0].mVec128.m128_i32[2] ^ 0x80000000));
        v106 = (float)((float)(COERCE_FLOAT(q.m_el[0].mVec128.m128_i32[2] ^ 0x80000000) * v212)
                     + (float)(v209 * COERCE_FLOAT(q.m_el[0].mVec128.m128_i32[1] ^ 0x80000000)))
             - (float)(v210 * COERCE_FLOAT(q.m_el[0].mVec128.m128_i32[0] ^ 0x80000000));
        v107 = (float)((float)-(float)(v209 * COERCE_FLOAT(q.m_el[0].mVec128.m128_i32[0] ^ 0x80000000))
                     - (float)(COERCE_FLOAT(q.m_el[0].mVec128.m128_i32[1] ^ 0x80000000) * v210))
             - (float)(COERCE_FLOAT(q.m_el[0].mVec128.m128_i32[2] ^ 0x80000000) * v211);
        v108 = (float)((float)(COERCE_FLOAT(q.m_el[0].mVec128.m128_i32[2] ^ 0x80000000) * v210)
                     + (float)(v212 * COERCE_FLOAT(q.m_el[0].mVec128.m128_i32[0] ^ 0x80000000)))
             - (float)(COERCE_FLOAT(q.m_el[0].mVec128.m128_i32[1] ^ 0x80000000) * v211);
        q.m_el[2].mVec128.m128_f32[0] = (float)((float)((float)(qTwist.m_el[2].mVec128.m128_f32[1] * v107)
                                                      + (float)(v108 * v212))
                                              + (float)(qTwist.m_el[2].mVec128.m128_f32[2] * v105))
                                      - (float)(qTwist.m_el[2].mVec128.m128_f32[0] * v106);
        q.m_el[2].mVec128.m128_f32[2] = (float)((float)((float)(v108 * qTwist.m_el[2].mVec128.m128_f32[0])
                                                      + (float)(qTwist.m_el[2].mVec128.m128_f32[2] * v107))
                                              + (float)(v106 * v212))
                                      - (float)(qTwist.m_el[2].mVec128.m128_f32[1] * v105);
        q.m_el[2].mVec128.m128_i32[3] = 0;
        q.m_el[2].mVec128.m128_f32[1] = (float)((float)((float)(qTwist.m_el[2].mVec128.m128_f32[1] * v106)
                                                      + (float)(qTwist.m_el[2].mVec128.m128_f32[0] * v107))
                                              + (float)(v105 * v212))
                                      - (float)(v108 * qTwist.m_el[2].mVec128.m128_f32[2]);
        this->m_swingAxis = q.m_el[2];
        this->m_twistAxisA.mVec128.m128_u64[0] = 0;
        this->m_twistAxisA.mVec128.m128_u64[1] = 0;
        v109 = this->m_swingAxis.mVec128.m128_f32[2];
        v110 = this->m_swingAxis.mVec128.m128_f32[1];
        v111 = this->m_swingAxis.mVec128.m128_f32[0];
        this->m_kSwing = *(float *)&clear_value
                       / (float)((float)((float)((float)((float)((float)((float)((float)((float)(invInertiaWorldB->m_el[1].mVec128.m128_f32[0]
                                                                                               * v110)
                                                                                       + (float)(invInertiaWorldB->m_el[2].mVec128.m128_f32[0]
                                                                                               * v109))
                                                                               + (float)(v111
                                                                                       * invInertiaWorldB->m_el[0].mVec128.m128_f32[0]))
                                                                       * v111)
                                                               + (float)((float)((float)((float)(invInertiaWorldA->m_el[1].mVec128.m128_f32[0]
                                                                                               * v110)
                                                                                       + (float)(invInertiaWorldA->m_el[2].mVec128.m128_f32[0]
                                                                                               * v109))
                                                                               + (float)(v111
                                                                                       * invInertiaWorldA->m_el[0].mVec128.m128_f32[0]))
                                                                       * v111))
                                                       + (float)((float)((float)((float)(invInertiaWorldB->m_el[0].mVec128.m128_f32[1]
                                                                                       * v111)
                                                                               + (float)(invInertiaWorldB->m_el[1].mVec128.m128_f32[1]
                                                                                       * v110))
                                                                       + (float)(invInertiaWorldB->m_el[2].mVec128.m128_f32[1]
                                                                               * v109))
                                                               * v110))
                                               + (float)((float)((float)((float)(invInertiaWorldB->m_el[0].mVec128.m128_f32[2]
                                                                               * v111)
                                                                       + (float)(invInertiaWorldB->m_el[1].mVec128.m128_f32[2]
                                                                               * v110))
                                                               + (float)(invInertiaWorldB->m_el[2].mVec128.m128_f32[2]
                                                                       * v109))
                                                       * v109))
                                       + (float)((float)((float)((float)(invInertiaWorldA->m_el[0].mVec128.m128_f32[1]
                                                                       * v111)
                                                               + (float)(invInertiaWorldA->m_el[1].mVec128.m128_f32[1]
                                                                       * v110))
                                                       + (float)(invInertiaWorldA->m_el[2].mVec128.m128_f32[1] * v109))
                                               * v110))
                               + (float)((float)((float)((float)(invInertiaWorldA->m_el[0].mVec128.m128_f32[2] * v111)
                                                       + (float)(invInertiaWorldA->m_el[1].mVec128.m128_f32[2] * v110))
                                               + (float)(invInertiaWorldA->m_el[2].mVec128.m128_f32[2] * v109))
                                       * v109));
      }
    }
    if ( this->m_twistSpan < 0.0 )
    {
      this->m_twistAngle = 0.0;
    }
    else
    {
      btConeTwistConstraint::computeTwistLimitInfo(
        (const btQuaternion *)&qTwist,
        (btVector3 *)&v207,
        (btConeTwistConstraint *)&this->m_twistAngle,
        a2);
      m_twistSpan = this->m_twistSpan;
      v163 = this->m_limitSoftness;
      m_twistAngle = this->m_twistAngle;
      v165 = v207.m_floats[2];
      v166 = v207.m_floats[1];
      v167 = v207.m_floats[0];
      v168 = m_twistSpan * v163;
      if ( m_twistAngle > (float)(m_twistSpan * v163) )
      {
        v169 = clear_value;
        this->m_solveTwistLimit = 1;
        LODWORD(this->m_twistLimitRatio) = v169;
        if ( m_twistSpan > m_twistAngle && v163 < 0.99999988 )
          this->m_twistLimitRatio = (float)(m_twistAngle - v168) / (float)(m_twistSpan - v168);
        v170 = m_twistAngle - v168;
        v171 = v212;
        this->m_twistCorrection = v170;
        v172 = -v166;
        v173 = -v165;
        v174 = -v167;
        q.m_el[2].mVec128.m128_f32[0] = (float)((float)(v171 * v174) + (float)(v173 * v210)) - (float)(v172 * v211);
        q.m_el[2].mVec128.m128_f32[1] = (float)((float)(v211 * v174) + (float)(v172 * v171)) - (float)(v209 * v173);
        q.m_el[0].mVec128.m128_u64[0] = __PAIR64__(
                                          qTwist.m_el[2].mVec128.m128_u32[0],
                                          qTwist.m_el[2].mVec128.m128_u32[1]);
        q.m_el[2].mVec128.m128_f32[2] = (float)((float)(v173 * v171) + (float)(v209 * v172)) - (float)(v210 * v174);
        q.m_el[2].mVec128.m128_f32[3] = (float)((float)-(float)(v209 * v174) - (float)(v172 * v210))
                                      - (float)(v173 * v211);
        q.m_el[0].mVec128.m128_u64[1] = __PAIR64__(LODWORD(v171), qTwist.m_el[2].mVec128.m128_u32[2]);
        btQuaternion::operator*=((btQuaternion *)&q, (btQuaternion *)&q.m_el[2]);
        q.m_el[0].mVec128.m128_u64[0] = q.m_el[2].mVec128.m128_u64[0];
        q.m_el[0].mVec128.m128_u64[1] = q.m_el[2].mVec128.m128_u32[2];
        this->m_twistAxis.mVec128.m128_u64[0] = q.m_el[2].mVec128.m128_u64[0];
        this->m_twistAxis.mVec128.m128_u64[1] = q.m_el[0].mVec128.m128_u64[1];
        v176 = this->m_twistAxis.mVec128.m128_f32[2];
        v177 = this->m_twistAxis.mVec128.m128_f32[1];
        v178 = this->m_twistAxis.mVec128.m128_f32[0];
        v179 = invInertiaWorldA->m_el[1].mVec128.m128_f32[1];
        q.m_el[0].mVec128.m128_f32[0] = (float)((float)(invInertiaWorldA->m_el[1].mVec128.m128_f32[0] * v177)
                                              + (float)(invInertiaWorldA->m_el[2].mVec128.m128_f32[0] * v176))
                                      + (float)(v178 * invInertiaWorldA->m_el[0].mVec128.m128_f32[0]);
        v180 = (float)((float)(invInertiaWorldA->m_el[0].mVec128.m128_f32[1] * v178) + (float)(v179 * v177))
             + (float)(invInertiaWorldA->m_el[2].mVec128.m128_f32[1] * v176);
        v181 = invInertiaWorldA->m_el[1].mVec128.m128_f32[2];
        q.m_el[0].mVec128.m128_f32[1] = v180;
        v182 = invInertiaWorldB->m_el[1].mVec128.m128_f32[0];
        v183 = invInertiaWorldB->m_el[2].mVec128.m128_f32[0];
        q.m_el[0].mVec128.m128_f32[2] = (float)((float)(invInertiaWorldA->m_el[0].mVec128.m128_f32[2] * v178)
                                              + (float)(v181 * v177))
                                      + (float)(invInertiaWorldA->m_el[2].mVec128.m128_f32[2] * v176);
        v184 = (float)((float)(v182 * v177) + (float)(v183 * v176))
             + (float)(v178 * invInertiaWorldB->m_el[0].mVec128.m128_f32[0]);
        v185 = invInertiaWorldB->m_el[1].mVec128.m128_f32[1];
        q.m_el[2].mVec128.m128_f32[0] = v184;
        v186 = (float)((float)(invInertiaWorldB->m_el[0].mVec128.m128_f32[1] * v178) + (float)(v185 * v177))
             + (float)(invInertiaWorldB->m_el[2].mVec128.m128_f32[1] * v176);
        v187 = invInertiaWorldB->m_el[1].mVec128.m128_f32[2];
        q.m_el[2].mVec128.m128_f32[1] = v186;
        v188 = (float)((float)((float)((float)(v178 * q.m_el[2].mVec128.m128_f32[0])
                                     + (float)(v178 * q.m_el[0].mVec128.m128_f32[0]))
                             + (float)(v177 * v186))
                     + (float)(v176
                             * (float)((float)((float)(invInertiaWorldB->m_el[0].mVec128.m128_f32[2] * v178)
                                             + (float)(v187 * v177))
                                     + (float)(invInertiaWorldB->m_el[2].mVec128.m128_f32[2] * v176))))
             + (float)(v177 * v180);
        v167 = v207.m_floats[0];
        v189 = *(float *)&clear_value / (float)(v188 + (float)(v176 * q.m_el[0].mVec128.m128_f32[2]));
        v166 = v207.m_floats[1];
        this->m_kTwist = v189;
        v165 = v207.m_floats[2];
      }
      if ( this->m_solveSwingLimit )
      {
        v190 = -v166;
        v191 = -v165;
        q.m_el[2].mVec128.m128_f32[0] = (float)((float)(v191 * trPose.m_origin.mVec128.m128_f32[1])
                                              + (float)(trPose.m_origin.mVec128.m128_f32[3] * (float)-v167))
                                      - (float)(v190 * trPose.m_origin.mVec128.m128_f32[2]);
        q.m_el[2].mVec128.m128_f32[1] = (float)((float)(v190 * trPose.m_origin.mVec128.m128_f32[3])
                                              + (float)(trPose.m_origin.mVec128.m128_f32[2] * (float)-v167))
                                      - (float)(trPose.m_origin.mVec128.m128_f32[0] * v191);
        q.m_el[2].mVec128.m128_f32[2] = (float)((float)(v191 * trPose.m_origin.mVec128.m128_f32[3])
                                              + (float)(trPose.m_origin.mVec128.m128_f32[0] * v190))
                                      - (float)(trPose.m_origin.mVec128.m128_f32[1] * (float)-v167);
        q.m_el[0].mVec128.m128_u64[1] = trPose.m_origin.mVec128.m128_u64[1] ^ 0x80000000;
        q.m_el[2].mVec128.m128_f32[3] = (float)((float)-(float)(trPose.m_origin.mVec128.m128_f32[0] * (float)-v167)
                                              - (float)(v190 * trPose.m_origin.mVec128.m128_f32[1]))
                                      - (float)(v191 * trPose.m_origin.mVec128.m128_f32[2]);
        q.m_el[0].mVec128.m128_f32[0] = -trPose.m_origin.mVec128.m128_f32[0];
        q.m_el[0].mVec128.m128_f32[1] = -trPose.m_origin.mVec128.m128_f32[1];
        btQuaternion::operator*=((btQuaternion *)&q, (btQuaternion *)&q.m_el[2]);
        q.m_el[0].mVec128.m128_u64[0] = q.m_el[2].mVec128.m128_u64[0];
        q.m_el[0].mVec128.m128_u64[1] = q.m_el[2].mVec128.m128_u32[2];
        this->m_twistAxisA.mVec128.m128_u64[0] = q.m_el[2].mVec128.m128_u64[0];
        this->m_twistAxisA.mVec128.m128_u64[1] = q.m_el[0].mVec128.m128_u64[1];
      }
    }
  }
  else
  {
    btMatrix3x3::setRotation((btMatrix3x3 *)&this->m_qTarget, (int)&trDeltaAB);
    v8 = this->m_rbAFrame.m_origin.mVec128.m128_f32[1];
    v9 = this->m_rbAFrame.m_origin.mVec128.m128_f32[0];
    v10 = transA->m_basis.m_el[0].mVec128.m128_f32[1];
    v11 = transA->m_basis.m_el[0].mVec128.m128_f32[0];
    v12 = this->m_rbAFrame.m_origin.mVec128.m128_f32[2];
    v13 = transA->m_basis.m_el[0].mVec128.m128_f32[2];
    v14 = transA->m_basis.m_el[1].mVec128.m128_f32[2];
    q.m_el[0].mVec128.m128_f32[0] = (float)((float)((float)(transA->m_basis.m_el[0].mVec128.m128_f32[0] * v9)
                                                  + (float)(v10 * v8))
                                          + (float)(v13 * v12))
                                  + transA->m_origin.mVec128.m128_f32[0];
    q.m_el[0].mVec128.m128_f32[1] = (float)((float)((float)(transA->m_basis.m_el[1].mVec128.m128_f32[1] * v8)
                                                  + (float)(v14 * v12))
                                          + (float)(transA->m_basis.m_el[1].mVec128.m128_f32[0] * v9))
                                  + transA->m_origin.mVec128.m128_f32[1];
    v15 = this->m_rbAFrame.m_basis.m_el[0].mVec128.m128_f32[1] * transA->m_basis.m_el[2].mVec128.m128_f32[0];
    v16 = (float)(transA->m_basis.m_el[2].mVec128.m128_f32[1] * v8)
        + (float)(transA->m_basis.m_el[2].mVec128.m128_f32[2] * v12);
    v17 = this->m_rbAFrame.m_basis.m_el[2].mVec128.m128_f32[2];
    v18 = transA->m_basis.m_el[2].mVec128.m128_f32[0] * v9;
    v19 = this->m_rbAFrame.m_basis.m_el[1].mVec128.m128_f32[2];
    q.m_el[0].mVec128.m128_f32[2] = (float)(v16 + v18) + transA->m_origin.mVec128.m128_f32[2];
    v20 = this->m_rbAFrame.m_basis.m_el[0].mVec128.m128_f32[2] * transA->m_basis.m_el[2].mVec128.m128_f32[0];
    q.m_el[0].mVec128.m128_i32[3] = 0;
    *(float *)&v21 = (float)((float)(transA->m_basis.m_el[2].mVec128.m128_f32[1] * v19)
                           + (float)(transA->m_basis.m_el[2].mVec128.m128_f32[2] * v17))
                   + v20;
    *(float *)&v22 = (float)((float)(transA->m_basis.m_el[2].mVec128.m128_f32[1]
                                   * this->m_rbAFrame.m_basis.m_el[1].mVec128.m128_f32[1])
                           + (float)(transA->m_basis.m_el[2].mVec128.m128_f32[2]
                                   * this->m_rbAFrame.m_basis.m_el[2].mVec128.m128_f32[1]))
                   + v15;
    *(float *)&v23 = (float)((float)(transA->m_basis.m_el[2].mVec128.m128_f32[1]
                                   * this->m_rbAFrame.m_basis.m_el[1].mVec128.m128_f32[0])
                           + (float)(transA->m_basis.m_el[2].mVec128.m128_f32[2]
                                   * this->m_rbAFrame.m_basis.m_el[2].mVec128.m128_f32[0]))
                   + (float)(this->m_rbAFrame.m_basis.m_el[0].mVec128.m128_f32[0]
                           * transA->m_basis.m_el[2].mVec128.m128_f32[0]);
    v24 = transA->m_basis.m_el[1].mVec128.m128_f32[1];
    qTwist.m_el[2].mVec128.m128_f32[2] = (float)((float)(v24 * this->m_rbAFrame.m_basis.m_el[1].mVec128.m128_f32[2])
                                               + (float)(transA->m_basis.m_el[1].mVec128.m128_f32[2]
                                                       * this->m_rbAFrame.m_basis.m_el[2].mVec128.m128_f32[2]))
                                       + (float)(transA->m_basis.m_el[1].mVec128.m128_f32[0]
                                               * this->m_rbAFrame.m_basis.m_el[0].mVec128.m128_f32[2]);
    v25 = (float)((float)(v24 * this->m_rbAFrame.m_basis.m_el[1].mVec128.m128_f32[1])
                + (float)(transA->m_basis.m_el[1].mVec128.m128_f32[2]
                        * this->m_rbAFrame.m_basis.m_el[2].mVec128.m128_f32[1]))
        + (float)(transA->m_basis.m_el[1].mVec128.m128_f32[0] * this->m_rbAFrame.m_basis.m_el[0].mVec128.m128_f32[1]);
    v26 = transA->m_basis.m_el[1].mVec128.m128_f32[1];
    qTwist.m_el[2].mVec128.m128_f32[0] = v25;
    qTwist.m_el[2].mVec128.m128_f32[1] = (float)((float)(v26 * this->m_rbAFrame.m_basis.m_el[1].mVec128.m128_f32[0])
                                               + (float)(transA->m_basis.m_el[1].mVec128.m128_f32[2]
                                                       * this->m_rbAFrame.m_basis.m_el[2].mVec128.m128_f32[0]))
                                       + (float)(transA->m_basis.m_el[1].mVec128.m128_f32[0]
                                               * this->m_rbAFrame.m_basis.m_el[0].mVec128.m128_f32[0]);
    v203 = (float)((float)(v11 * this->m_rbAFrame.m_basis.m_el[0].mVec128.m128_f32[2])
                 + (float)(v10 * this->m_rbAFrame.m_basis.m_el[1].mVec128.m128_f32[2]))
         + (float)(v13 * this->m_rbAFrame.m_basis.m_el[2].mVec128.m128_f32[2]);
    *(float *)&v27 = (float)((float)(v11 * this->m_rbAFrame.m_basis.m_el[0].mVec128.m128_f32[1])
                           + (float)(v10 * this->m_rbAFrame.m_basis.m_el[1].mVec128.m128_f32[1]))
                   + (float)(v13 * this->m_rbAFrame.m_basis.m_el[2].mVec128.m128_f32[1]);
    *(float *)v213.m128i_i32 = (float)((float)(v11 * this->m_rbAFrame.m_basis.m_el[0].mVec128.m128_f32[0])
                                     + (float)(v10 * this->m_rbAFrame.m_basis.m_el[1].mVec128.m128_f32[0]))
                             + (float)(v13 * this->m_rbAFrame.m_basis.m_el[2].mVec128.m128_f32[0]);
    v213.m128i_i32[1] = v27;
    v213.m128i_i64[1] = LODWORD(v203);
    v28 = transB->m_basis.m_el[0].mVec128.m128_f32[1];
    v29 = this->m_rbBFrame.m_origin.mVec128.m128_f32[0];
    v214.m128i_i64[0] = __PAIR64__(qTwist.m_el[2].mVec128.m128_u32[0], qTwist.m_el[2].mVec128.m128_u32[1]);
    v214.m128i_i64[1] = qTwist.m_el[2].mVec128.m128_u32[2];
    v30 = _mm_load_si128(&v213);
    v215.m128i_i64[0] = __PAIR64__(v22, v23);
    v31 = transB->m_basis.m_el[0].mVec128.m128_f32[2];
    v32 = this->m_rbBFrame.m_origin.mVec128.m128_f32[1];
    v215.m128i_i64[1] = v21;
    v33 = this->m_rbBFrame.m_origin.mVec128.m128_f32[2];
    trA.m_basis.m_el[0] = (btVector3)v30;
    trA.m_basis.m_el[1] = (btVector3)_mm_load_si128(&v214);
    trA.m_basis.m_el[2] = (btVector3)_mm_load_si128(&v215);
    v34.mVec128 = (__m128)_mm_load_si128((const __m128i *)&q);
    q.m_el[1].mVec128.m128_f32[3] = v31;
    trA.m_origin = (btVector3)v34.mVec128;
    v34.mVec128.m128_i32[0] = transB->m_basis.m_el[0].mVec128.m128_i32[0];
    v35 = this->m_rbBFrame.m_basis.m_el[0].mVec128.m128_f32[1] * transB->m_basis.m_el[2].mVec128.m128_f32[0];
    _Y = v28;
    v36 = (float)((float)((float)(v34.mVec128.m128_f32[0] * v29) + (float)(v28 * v32)) + (float)(v31 * v33))
        + transB->m_origin.mVec128.m128_f32[0];
    v37 = transB->m_basis.m_el[1].mVec128.m128_f32[2];
    v38 = this->m_rbBFrame.m_basis.m_el[1].mVec128.m128_f32[2];
    q.m_el[2].mVec128.m128_f32[0] = v36;
    v39 = (float)(transB->m_basis.m_el[1].mVec128.m128_f32[1] * v32) + (float)(v37 * v33);
    v40 = v29 * transB->m_basis.m_el[1].mVec128.m128_f32[0];
    v41 = v29 * transB->m_basis.m_el[2].mVec128.m128_f32[0];
    v42 = (float)(v39 + v40) + transB->m_origin.mVec128.m128_f32[1];
    v43 = this->m_rbBFrame.m_basis.m_el[2].mVec128.m128_f32[2];
    q.m_el[2].mVec128.m128_f32[1] = v42;
    v44 = transB->m_basis.m_el[2].mVec128.m128_f32[1] * v32;
    v45 = transB->m_basis.m_el[2].mVec128.m128_f32[2] * v33;
    v46 = transB->m_basis.m_el[2].mVec128.m128_f32[2];
    v47 = v44 + v45;
    v48 = this->m_rbBFrame.m_basis.m_el[1].mVec128.m128_f32[1];
    v49 = (float)(v47 + v41) + transB->m_origin.mVec128.m128_f32[2];
    v50 = this->m_rbBFrame.m_basis.m_el[0].mVec128.m128_f32[2];
    q.m_el[2].mVec128.m128_f32[2] = v49;
    v51 = (float)((float)(transB->m_basis.m_el[2].mVec128.m128_f32[1] * v38) + (float)(v46 * v43))
        + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[0] * v50);
    v52 = (float)((float)(transB->m_basis.m_el[2].mVec128.m128_f32[1] * v48)
                + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[2]
                        * this->m_rbBFrame.m_basis.m_el[2].mVec128.m128_f32[1]))
        + v35;
    v53 = (float)((float)(transB->m_basis.m_el[2].mVec128.m128_f32[1]
                        * this->m_rbBFrame.m_basis.m_el[1].mVec128.m128_f32[0])
                + (float)(transB->m_basis.m_el[2].mVec128.m128_f32[2]
                        * this->m_rbBFrame.m_basis.m_el[2].mVec128.m128_f32[0]))
        + (float)(this->m_rbBFrame.m_basis.m_el[0].mVec128.m128_f32[0] * transB->m_basis.m_el[2].mVec128.m128_f32[0]);
    v54 = (float)((float)(transB->m_basis.m_el[1].mVec128.m128_f32[1] * v38)
                + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[2] * v43))
        + (float)(this->m_rbBFrame.m_basis.m_el[0].mVec128.m128_f32[2] * transB->m_basis.m_el[1].mVec128.m128_f32[0]);
    v55 = (float)((float)(transB->m_basis.m_el[1].mVec128.m128_f32[1]
                        * this->m_rbBFrame.m_basis.m_el[1].mVec128.m128_f32[1])
                + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[2]
                        * this->m_rbBFrame.m_basis.m_el[2].mVec128.m128_f32[1]))
        + (float)(this->m_rbBFrame.m_basis.m_el[0].mVec128.m128_f32[1] * transB->m_basis.m_el[1].mVec128.m128_f32[0]);
    v56 = this->m_rbBFrame.m_basis.m_el[2].mVec128.m128_f32[0];
    v203 = transB->m_basis.m_el[1].mVec128.m128_f32[1] * this->m_rbBFrame.m_basis.m_el[1].mVec128.m128_f32[0];
    v194 = (float)(v203 + (float)(transB->m_basis.m_el[1].mVec128.m128_f32[2] * v56))
         + (float)(this->m_rbBFrame.m_basis.m_el[0].mVec128.m128_f32[0] * transB->m_basis.m_el[1].mVec128.m128_f32[0]);
    v200 = (float)(v34.mVec128.m128_f32[0] * this->m_rbBFrame.m_basis.m_el[0].mVec128.m128_f32[2])
         + (float)(_Y * this->m_rbBFrame.m_basis.m_el[1].mVec128.m128_f32[2]);
    trPose.m_basis.m_el[2].mVec128.m128_f32[3] = v200
                                               + (float)(q.m_el[1].mVec128.m128_f32[3]
                                                       * this->m_rbBFrame.m_basis.m_el[2].mVec128.m128_f32[2]);
    v200 = (float)(v34.mVec128.m128_f32[0] * this->m_rbBFrame.m_basis.m_el[0].mVec128.m128_f32[1])
         + (float)(_Y * this->m_rbBFrame.m_basis.m_el[1].mVec128.m128_f32[1]);
    v57 = this->m_rbBFrame.m_basis.m_el[1].mVec128.m128_f32[0];
    v204 = v200 + (float)(q.m_el[1].mVec128.m128_f32[3] * this->m_rbBFrame.m_basis.m_el[2].mVec128.m128_f32[1]);
    qTwist.m_el[2].mVec128.m128_f32[1] = (float)((float)(v34.mVec128.m128_f32[0]
                                                       * this->m_rbBFrame.m_basis.m_el[0].mVec128.m128_f32[0])
                                               + (float)(_Y * v57))
                                       + (float)(q.m_el[1].mVec128.m128_f32[3]
                                               * this->m_rbBFrame.m_basis.m_el[2].mVec128.m128_f32[0]);
    v207.m_floats[0] = (float)((float)((float)(qTwist.m_el[2].mVec128.m128_f32[1] + v204)
                                     + trPose.m_basis.m_el[2].mVec128.m128_f32[3])
                             * 0.0)
                     + q.m_el[2].mVec128.m128_f32[0];
    v207.m_floats[1] = (float)((float)((float)(v194 + v54) + v55) * 0.0) + q.m_el[2].mVec128.m128_f32[1];
    v207.m_floats[2] = (float)((float)((float)(v52 + v51) + v53) * 0.0) + q.m_el[2].mVec128.m128_f32[2];
    v197 = (float)((float)(trDeltaAB.m_basis.m_el[1].mVec128.m128_f32[2] * v52)
                 + (float)(trDeltaAB.m_basis.m_el[2].mVec128.m128_f32[2] * v51))
         + (float)(trDeltaAB.m_basis.m_el[0].mVec128.m128_f32[2] * v53);
    q.m_el[1].mVec128.m128_f32[3] = (float)((float)(trDeltaAB.m_basis.m_el[1].mVec128.m128_f32[1] * v52)
                                          + (float)(trDeltaAB.m_basis.m_el[2].mVec128.m128_f32[1] * v51))
                                  + (float)(trDeltaAB.m_basis.m_el[0].mVec128.m128_f32[1] * v53);
    v205 = (float)((float)(trDeltaAB.m_basis.m_el[0].mVec128.m128_f32[0] * v53)
                 + (float)(trDeltaAB.m_basis.m_el[1].mVec128.m128_f32[0] * v52))
         + (float)(trDeltaAB.m_basis.m_el[2].mVec128.m128_f32[0] * v51);
    v200 = (float)((float)(trDeltaAB.m_basis.m_el[2].mVec128.m128_f32[2] * v54)
                 + (float)(trDeltaAB.m_basis.m_el[1].mVec128.m128_f32[2] * v55))
         + (float)(trDeltaAB.m_basis.m_el[0].mVec128.m128_f32[2] * v194);
    _Y = (float)((float)(trDeltaAB.m_basis.m_el[2].mVec128.m128_f32[1] * v54)
               + (float)(trDeltaAB.m_basis.m_el[1].mVec128.m128_f32[1] * v55))
       + (float)(trDeltaAB.m_basis.m_el[0].mVec128.m128_f32[1] * v194);
    qTwist.m_el[2].mVec128.m128_f32[0] = (float)((float)(trDeltaAB.m_basis.m_el[0].mVec128.m128_f32[0] * v194)
                                               + (float)(trDeltaAB.m_basis.m_el[2].mVec128.m128_f32[0] * v54))
                                       + (float)(trDeltaAB.m_basis.m_el[1].mVec128.m128_f32[0] * v55);
    qTwist.m_el[2].mVec128.m128_f32[2] = (float)((float)(trDeltaAB.m_basis.m_el[1].mVec128.m128_f32[2] * v204)
                                               + (float)(trDeltaAB.m_basis.m_el[2].mVec128.m128_f32[2]
                                                       * trPose.m_basis.m_el[2].mVec128.m128_f32[3]))
                                       + (float)(trDeltaAB.m_basis.m_el[0].mVec128.m128_f32[2]
                                               * qTwist.m_el[2].mVec128.m128_f32[1]);
    v58 = (float)((float)(trDeltaAB.m_basis.m_el[0].mVec128.m128_f32[0] * qTwist.m_el[2].mVec128.m128_f32[1])
                + (float)(trDeltaAB.m_basis.m_el[1].mVec128.m128_f32[0] * v204))
        + (float)(trDeltaAB.m_basis.m_el[2].mVec128.m128_f32[0] * trPose.m_basis.m_el[2].mVec128.m128_f32[3]);
    trPose.m_basis.m_el[2].mVec128.m128_f32[3] = (float)((float)(trDeltaAB.m_basis.m_el[1].mVec128.m128_f32[1] * v204)
                                                       + (float)(trDeltaAB.m_basis.m_el[2].mVec128.m128_f32[1]
                                                               * trPose.m_basis.m_el[2].mVec128.m128_f32[3]))
                                               + (float)(trDeltaAB.m_basis.m_el[0].mVec128.m128_f32[1]
                                                       * qTwist.m_el[2].mVec128.m128_f32[1]);
    v203 = v58;
    v59 = btTransform::inverse(&trA, &trDeltaAB);
    v60 = v59->m_origin.mVec128.m128_f32[2];
    v61 = v59->m_origin.mVec128.m128_f32[0];
    v34.mVec128.m128_i32[0] = v59->m_origin.mVec128.m128_i32[1];
    v62 = v203;
    q.m_el[0].mVec128.m128_f32[0] = (float)((float)((float)(v60 * qTwist.m_el[2].mVec128.m128_f32[2])
                                                  + (float)(v61 * v203))
                                          + (float)(v34.mVec128.m128_f32[0] * trPose.m_basis.m_el[2].mVec128.m128_f32[3]))
                                  + v207.m_floats[0];
    v63 = qTwist.m_el[2].mVec128.m128_f32[0];
    q.m_el[0].mVec128.m128_f32[1] = (float)((float)((float)(v60 * v200) + (float)(v34.mVec128.m128_f32[0] * _Y))
                                          + (float)(v61 * qTwist.m_el[2].mVec128.m128_f32[0]))
                                  + v207.m_floats[1];
    v64 = v205;
    v34.mVec128.m128_f32[0] = (float)(v34.mVec128.m128_f32[0] * q.m_el[1].mVec128.m128_f32[3]) + (float)(v61 * v205);
    v65 = v59->m_basis.m_el[2].mVec128.m128_f32[2];
    v34.mVec128.m128_f32[0] = (float)(v34.mVec128.m128_f32[0] + (float)(v60 * v197)) + v207.m_floats[2];
    v66 = v59->m_basis.m_el[1].mVec128.m128_f32[2];
    q.m_el[0].mVec128.m128_u64[1] = v34.mVec128.m128_u32[0];
    qTwist.m_el[1].mVec128.m128_f32[3] = v66;
    v34.mVec128.m128_i32[0] = v59->m_basis.m_el[0].mVec128.m128_i32[2];
    v199 = (float)((float)(v66 * q.m_el[1].mVec128.m128_f32[3]) + (float)(v34.mVec128.m128_f32[0] * v205))
         + (float)(v65 * v197);
    v67 = v59->m_basis.m_el[2].mVec128.m128_f32[1];
    qTwist.m_el[2].mVec128.m128_i32[0] = v59->m_basis.m_el[1].mVec128.m128_i32[1];
    v204 = v67;
    v68 = v59->m_basis.m_el[0].mVec128.m128_f32[1];
    v205 = (float)(qTwist.m_el[2].mVec128.m128_f32[0] * q.m_el[1].mVec128.m128_f32[3]) + (float)(v68 * v205);
    v195 = v59->m_basis.m_el[2].mVec128.m128_f32[0];
    v203 = v59->m_basis.m_el[1].mVec128.m128_f32[0];
    qTwist.m_el[2].mVec128.m128_f32[3] = v205 + (float)(v204 * v197);
    v69 = v59->m_basis.m_el[0].mVec128.m128_f32[0];
    q.m_el[1].mVec128.m128_f32[3] = (float)((float)(v64 * v59->m_basis.m_el[0].mVec128.m128_f32[0])
                                          + (float)(v203 * q.m_el[1].mVec128.m128_f32[3]))
                                  + (float)(v195 * v197);
    qTwist.m_el[2].mVec128.m128_f32[1] = v69;
    v70 = qTwist.m_el[1].mVec128.m128_f32[3];
    v205 = (float)((float)(v34.mVec128.m128_f32[0] * v63) + (float)(v65 * v200))
         + (float)(qTwist.m_el[1].mVec128.m128_f32[3] * _Y);
    qTwist.m_el[1].mVec128.m128_f32[3] = (float)((float)(v68 * v63) + (float)(v204 * v200))
                                       + (float)(qTwist.m_el[2].mVec128.m128_f32[0] * _Y);
    *(float *)v213.m128i_i32 = (float)((float)(v62 * v69) + (float)(v203 * trPose.m_basis.m_el[2].mVec128.m128_f32[3]))
                             + (float)(v195 * qTwist.m_el[2].mVec128.m128_f32[2]);
    *(float *)&v213.m128i_i32[1] = (float)((float)(v68 * v62)
                                         + (float)(qTwist.m_el[2].mVec128.m128_f32[0]
                                                 * trPose.m_basis.m_el[2].mVec128.m128_f32[3]))
                                 + (float)(v204 * qTwist.m_el[2].mVec128.m128_f32[2]);
    *(float *)&v214.m128i_i32[1] = qTwist.m_el[1].mVec128.m128_f32[3];
    *(float *)&v213.m128i_i32[2] = (float)((float)(v34.mVec128.m128_f32[0] * v62)
                                         + (float)(v70 * trPose.m_basis.m_el[2].mVec128.m128_f32[3]))
                                 + (float)(v65 * qTwist.m_el[2].mVec128.m128_f32[2]);
    v214.m128i_i64[1] = LODWORD(v205);
    v213.m128i_i32[3] = 0;
    v71 = _mm_load_si128(&v213);
    v215.m128i_i64[0] = __PAIR64__(qTwist.m_el[2].mVec128.m128_u32[3], q.m_el[1].mVec128.m128_u32[3]);
    trA.m_basis.m_el[0] = (btVector3)v71;
    *(float *)v214.m128i_i32 = (float)((float)(v63 * v69) + (float)(v195 * v200)) + (float)(v203 * _Y);
    trA.m_basis.m_el[1] = (btVector3)_mm_load_si128(&v214);
    v215.m128i_i64[1] = LODWORD(v199);
    trA.m_basis.m_el[2] = (btVector3)_mm_load_si128(&v215);
    trA.m_origin = (btVector3)_mm_load_si128((const __m128i *)&q);
    btMatrix3x3::getRotation(v72, (float *)&trA, (btQuaternion *)&q);
    q.m_el[2].mVec128.m128_u64[0] = q.m_el[0].mVec128.m128_u64[0];
    q.m_el[2].mVec128.m128_u64[1] = q.m_el[0].mVec128.m128_u32[2];
    this->m_swingAxis.mVec128.m128_u64[0] = q.m_el[0].mVec128.m128_u64[0];
    this->m_swingAxis.mVec128.m128_u64[1] = q.m_el[2].mVec128.m128_u64[1];
    v73 = this->m_swingAxis.mVec128.m128_f32[1];
    v71.m128i_i32[0] = this->m_swingAxis.mVec128.m128_i32[2];
    qTwist.m_el[2].mVec128.m128_i32[3] = this->m_swingAxis.mVec128.m128_i32[0];
    qTwist.m_el[1].mVec128.m128_f32[3] = v73;
    v205 = *(float *)v71.m128i_i32;
    v199 = 1.0
         / sqrtf(
             (float)((float)(qTwist.m_el[2].mVec128.m128_f32[3] * qTwist.m_el[2].mVec128.m128_f32[3])
                   + (float)(v73 * v73))
           + (float)(*(float *)v71.m128i_i32 * *(float *)v71.m128i_i32));
    *(float *)v71.m128i_i32 = v199;
    this->m_swingAxis.mVec128.m128_f32[0] = v199 * qTwist.m_el[2].mVec128.m128_f32[3];
    v74 = *(float *)v71.m128i_i32 * qTwist.m_el[1].mVec128.m128_f32[3];
    *(float *)v71.m128i_i32 = *(float *)v71.m128i_i32 * v205;
    this->m_swingAxis.mVec128.m128_f32[1] = v74;
    v75 = -1082130432;
    this->m_swingAxis.mVec128.m128_i32[2] = v71.m128i_i32[0];
    v198 = q.m_el[0].mVec128.m128_f32[3];
    if ( q.m_el[0].mVec128.m128_f32[3] < -1.0
      || (v75 = (int)clear_value, q.m_el[0].mVec128.m128_f32[3] > *(float *)&clear_value) )
    {
      v198 = *(float *)&v75;
    }
    v76 = acosf(v198);
    v77 = v76 + v76;
    this->m_swingCorrection = v77;
    _X = v77;
    if ( fabsf(_X) >= 0.00000011920929 )
      this->m_solveSwingLimit = 1;
  }
}
