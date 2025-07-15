void __cdecl btCollisionWorld::rayTestSingle(
        const btTransform *rayFromTrans,
        const btTransform *rayToTrans,
        btCollisionObject *collisionObject,
        btVoronoiSimplexSolver *collisionShape,
        const btTransform *colObjWorldTransform,
        btCollisionWorld::RayResultCallback *resultCallback)
{
  btConvexInternalShape *v6; // ecx
  int v7; // eax
  float v8; // xmm0_4
  btCollisionWorld::RayResultCallback *v9; // ecx
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm4_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  int m_numVertices; // eax
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  bool v19; // cc
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm5_4
  float v23; // xmm3_4
  btCollisionWorld::RayResultCallback_vtbl *v24; // eax
  float v25; // xmm3_4
  float v26; // xmm6_4
  float v27; // xmm2_4
  float v28; // xmm7_4
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm6_4
  float v32; // xmm7_4
  float v33; // xmm6_4
  float v34; // xmm4_4
  float v35; // xmm2_4
  float v36; // xmm1_4
  float v37; // xmm7_4
  float v38; // xmm4_4
  float v39; // xmm2_4
  float v40; // xmm7_4
  float v41; // xmm1_4
  float v42; // xmm6_4
  float v43; // xmm7_4
  float v44; // xmm5_4
  float v45; // xmm3_4
  float v46; // xmm4_4
  float m_closestHitFraction; // xmm0_4
  btCollisionWorld::rayTestSingle::__l43::RayTester *v48; // ecx
  float v49; // xmm0_4
  float v50; // xmm2_4
  float v51; // xmm1_4
  float v52; // xmm5_4
  float v53; // xmm6_4
  float v54; // xmm4_4
  float v55; // xmm7_4
  float v56; // xmm6_4
  float v57; // xmm5_4
  float v58; // xmm4_4
  float v59; // xmm7_4
  float v60; // xmm5_4
  float v61; // xmm7_4
  float v62; // xmm0_4
  float v63; // xmm3_4
  float v64; // xmm1_4
  float v65; // xmm2_4
  float v66; // xmm5_4
  float v67; // xmm2_4
  float v68; // xmm5_4
  float v69; // xmm6_4
  float v70; // xmm5_4
  float v71; // xmm6_4
  float v72; // xmm5_4
  float v73; // xmm7_4
  float v74; // xmm6_4
  float v75; // xmm0_4
  float v76; // xmm4_4
  float v77; // xmm0_4
  float v78; // xmm4_4
  float v79; // xmm2_4
  float v80; // xmm3_4
  float v81; // xmm1_4
  float v82; // xmm5_4
  float v83; // xmm7_4
  float v84; // xmm6_4
  float v85; // xmm4_4
  float v86; // xmm3_4
  float v87; // xmm5_4
  float v88; // xmm6_4
  float v89; // xmm3_4
  float v90; // xmm6_4
  float v91; // xmm4_4
  float v92; // xmm3_4
  float v93; // xmm5_4
  float v94; // xmm6_4
  float v95; // xmm3_4
  float v96; // xmm6_4
  float v97; // xmm0_4
  float v98; // xmm1_4
  float v99; // xmm2_4
  float v100; // xmm6_4
  int v101; // xmm2_4
  float v102; // xmm2_4
  float v103; // xmm5_4
  float v104; // xmm6_4
  float v105; // xmm5_4
  float v106; // xmm6_4
  float v107; // xmm5_4
  float v108; // xmm6_4
  float v109; // xmm5_4
  float v110; // xmm6_4
  float v111; // xmm0_4
  float v112; // xmm3_4
  const float *v113; // edi
  int i; // esi
  const btDbvtNode *v115; // [esp-Ch] [ebp-38Ch]
  const float *v116; // [esp+0h] [ebp-380h]
  const float *v117; // [esp+0h] [ebp-380h]
  float v118; // [esp+10h] [ebp-370h]
  float v119; // [esp+10h] [ebp-370h]
  float v120; // [esp+10h] [ebp-370h]
  float v121; // [esp+10h] [ebp-370h]
  float v122; // [esp+14h] [ebp-36Ch]
  float v123; // [esp+14h] [ebp-36Ch]
  float v124; // [esp+18h] [ebp-368h] BYREF
  float v125; // [esp+1Ch] [ebp-364h] BYREF
  btSubsimplexConvexCast v126; // [esp+20h] [ebp-360h] BYREF
  btVector3 to; // [esp+30h] [ebp-350h] BYREF
  btVector3 v128; // [esp+40h] [ebp-340h] BYREF
  float v129; // [esp+54h] [ebp-32Ch] BYREF
  float v130; // [esp+58h] [ebp-328h] BYREF
  float v131; // [esp+5Ch] [ebp-324h] BYREF
  float v132; // [esp+60h] [ebp-320h] BYREF
  float v133; // [esp+64h] [ebp-31Ch] BYREF
  float v134; // [esp+68h] [ebp-318h] BYREF
  float v135; // [esp+6Ch] [ebp-314h] BYREF
  btTransform v136; // [esp+70h] [ebp-310h] BYREF
  btSubsimplexConvexCast policy; // [esp+B0h] [ebp-2D0h] BYREF
  btVector3 policy_16; // [esp+C0h] [ebp-2C0h]
  int v139; // [esp+D0h] [ebp-2B0h]
  const btDbvtNode **v140; // [esp+ECh] [ebp-294h]
  btVoronoiSimplexSolver result; // [esp+F0h] [ebp-290h] BYREF
  float v142; // [esp+330h] [ebp-50h]
  __int16 v143; // [esp+350h] [ebp-30h]

  btConvexInternalShape::btConvexInternalShape(v6, (btConvexInternalShape *)&result.m_simplexPointsQ[1]);
  v7 = *(&collisionShape->m_numVertices + 1);
  result.m_simplexPointsQ[1].mVec128.m128_i32[0] = (int)&btSphereShape::`vftable';
  result.m_simplexPointsQ[1].mVec128.m128_i32[1] = 8;
  result.m_simplexPointsQ[3].mVec128.m128_i32[0] = 0;
  result.m_simplexPointsQ[4].mVec128.m128_i32[0] = 0;
  if ( v7 >= 20 )
  {
    if ( (unsigned int)(v7 - 21) > 8 )
    {
      if ( v7 == 31 )
      {
        v48 = (btCollisionWorld::rayTestSingle::__l43::RayTester *)collisionShape->m_simplexVectorW[3].mVec128.m128_i32[0];
        policy.__vftable = (btSubsimplexConvexCast_vtbl *)collisionObject;
        policy_16.mVec128.m128_u64[0] = __PAIR64__((unsigned int)resultCallback, (unsigned int)rayToTrans);
        v140 = (const btDbvtNode **)v48;
        policy.m_simplexSolver = collisionShape;
        policy.m_convexA = (const btConvexShape *)colObjWorldTransform;
        policy.m_convexB = (const btConvexShape *)rayFromTrans;
        if ( v48 )
        {
          v49 = rayFromTrans->m_origin.mVec128.m128_f32[1] - colObjWorldTransform->m_origin.mVec128.m128_f32[1];
          v50 = rayFromTrans->m_origin.mVec128.m128_f32[2] - colObjWorldTransform->m_origin.mVec128.m128_f32[2];
          v51 = rayFromTrans->m_origin.mVec128.m128_f32[0] - colObjWorldTransform->m_origin.mVec128.m128_f32[0];
          v52 = colObjWorldTransform->m_basis.m_el[2].mVec128.m128_f32[1];
          v53 = colObjWorldTransform->m_basis.m_el[1].mVec128.m128_f32[1];
          v54 = colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[1];
          v128.mVec128.m128_f32[0] = (float)((float)(v49 * colObjWorldTransform->m_basis.m_el[1].mVec128.m128_f32[0])
                                           + (float)(v50 * colObjWorldTransform->m_basis.m_el[2].mVec128.m128_f32[0]))
                                   + (float)(v51 * colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[0]);
          v55 = (float)(v49 * v53) + (float)(v50 * v52);
          v56 = colObjWorldTransform->m_basis.m_el[2].mVec128.m128_f32[2];
          v57 = v51 * v54;
          v58 = rayFromTrans->m_basis.m_el[1].mVec128.m128_f32[2];
          v59 = v55 + v57;
          v60 = colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[2];
          v128.mVec128.m128_f32[1] = v59;
          v61 = colObjWorldTransform->m_basis.m_el[1].mVec128.m128_f32[2];
          v128.mVec128.m128_f32[2] = (float)((float)(v49 * v61) + (float)(v50 * v56)) + (float)(v51 * v60);
          v62 = rayFromTrans->m_basis.m_el[0].mVec128.m128_f32[2];
          v128.mVec128.m128_i32[3] = 0;
          v63 = rayFromTrans->m_basis.m_el[2].mVec128.m128_f32[2];
          v125 = rayFromTrans->m_basis.m_el[1].mVec128.m128_f32[1];
          v132 = (float)((float)(v58 * v61) + (float)(v62 * v60)) + (float)(v63 * v56);
          v120 = rayFromTrans->m_basis.m_el[2].mVec128.m128_f32[1];
          v64 = rayFromTrans->m_basis.m_el[0].mVec128.m128_f32[1];
          v65 = (float)((float)(v125 * v61) + (float)(v64 * v60)) + (float)(v120 * v56);
          v124 = rayFromTrans->m_basis.m_el[1].mVec128.m128_f32[0];
          v66 = colObjWorldTransform->m_basis.m_el[1].mVec128.m128_f32[2];
          v130 = v65;
          v122 = rayFromTrans->m_basis.m_el[2].mVec128.m128_f32[0];
          v67 = rayFromTrans->m_basis.m_el[0].mVec128.m128_f32[0];
          v131 = (float)((float)(v124 * v66) + (float)(v122 * v56))
               + (float)(rayFromTrans->m_basis.m_el[0].mVec128.m128_f32[0]
                       * colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[2]);
          v68 = colObjWorldTransform->m_basis.m_el[1].mVec128.m128_f32[1];
          v133 = (float)((float)(v58 * v68) + (float)(v62 * colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[1]))
               + (float)(v63 * colObjWorldTransform->m_basis.m_el[2].mVec128.m128_f32[1]);
          v69 = v125 * v68;
          v70 = colObjWorldTransform->m_basis.m_el[2].mVec128.m128_f32[1];
          v134 = (float)(v69 + (float)(v64 * colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[1]))
               + (float)(v120 * v70);
          v71 = v122 * v70;
          v72 = colObjWorldTransform->m_basis.m_el[1].mVec128.m128_f32[0];
          v73 = (float)((float)(v124 * colObjWorldTransform->m_basis.m_el[1].mVec128.m128_f32[1]) + v71)
              + (float)(v67 * colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[1]);
          v74 = colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[0];
          v75 = (float)(v62 * colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[0]) + (float)(v58 * v72);
          v76 = colObjWorldTransform->m_basis.m_el[2].mVec128.m128_f32[0];
          v135 = v75 + (float)(v63 * v76);
          v129 = v73;
          v125 = (float)((float)(v64 * v74) + (float)(v125 * v72)) + (float)(v120 * v76);
          v124 = (float)((float)(v67 * v74) + (float)(v124 * v72)) + (float)(v122 * v76);
          btMatrix3x3::setValue(
            (btMatrix3x3 *)&v124,
            (int)&v136,
            &v125,
            &v135,
            &v129,
            &v134,
            &v133,
            &v131,
            &v130,
            &v132,
            v116);
          v77 = rayToTrans->m_origin.mVec128.m128_f32[1] - colObjWorldTransform->m_origin.mVec128.m128_f32[1];
          v78 = colObjWorldTransform->m_basis.m_el[1].mVec128.m128_f32[0];
          v79 = rayToTrans->m_origin.mVec128.m128_f32[2] - colObjWorldTransform->m_origin.mVec128.m128_f32[2];
          v80 = colObjWorldTransform->m_basis.m_el[2].mVec128.m128_f32[0];
          v81 = rayToTrans->m_origin.mVec128.m128_f32[0] - colObjWorldTransform->m_origin.mVec128.m128_f32[0];
          v82 = colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[0];
          v83 = colObjWorldTransform->m_basis.m_el[1].mVec128.m128_f32[2];
          *(_QWORD *)&v126.__vftable = v128.mVec128.m128_u64[0];
          v84 = (float)(v77 * v78) + (float)(v79 * v80);
          v85 = colObjWorldTransform->m_basis.m_el[1].mVec128.m128_f32[1];
          *(_QWORD *)&v126.m_convexA = v128.mVec128.m128_u64[1];
          v86 = v81 * v82;
          v87 = colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[1];
          v88 = v84 + v86;
          v89 = colObjWorldTransform->m_basis.m_el[2].mVec128.m128_f32[1];
          v128.mVec128.m128_f32[0] = v88;
          v90 = (float)(v77 * v85) + (float)(v79 * v89);
          v91 = rayToTrans->m_basis.m_el[0].mVec128.m128_f32[2];
          v92 = v81 * v87;
          v93 = colObjWorldTransform->m_basis.m_el[2].mVec128.m128_f32[2];
          v94 = v90 + v92;
          v95 = rayToTrans->m_basis.m_el[2].mVec128.m128_f32[2];
          v128.mVec128.m128_f32[1] = v94;
          v96 = colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[2];
          v128.mVec128.m128_f32[2] = (float)((float)(v77 * v83) + (float)(v79 * v93)) + (float)(v81 * v96);
          v128.mVec128.m128_i32[3] = 0;
          v97 = rayToTrans->m_basis.m_el[1].mVec128.m128_f32[2];
          v124 = rayToTrans->m_basis.m_el[0].mVec128.m128_f32[1];
          v135 = (float)((float)(v91 * v96) + (float)(v97 * v83)) + (float)(v95 * v93);
          v123 = rayToTrans->m_basis.m_el[2].mVec128.m128_f32[1];
          v98 = rayToTrans->m_basis.m_el[1].mVec128.m128_f32[1];
          v99 = (float)((float)(v124 * v96) + (float)(v98 * v83)) + (float)(v123 * v93);
          v100 = rayToTrans->m_basis.m_el[0].mVec128.m128_f32[0];
          v129 = v99;
          v101 = rayToTrans->m_basis.m_el[2].mVec128.m128_i32[0];
          v125 = v100;
          v121 = *(float *)&v101;
          v102 = rayToTrans->m_basis.m_el[1].mVec128.m128_f32[0];
          v103 = colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[1];
          v134 = (float)((float)(v100 * colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[2]) + (float)(v102 * v83))
               + (float)(v121 * colObjWorldTransform->m_basis.m_el[2].mVec128.m128_f32[2]);
          v104 = v91 * v103;
          v105 = colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[1];
          v133 = (float)(v104 + (float)(v97 * colObjWorldTransform->m_basis.m_el[1].mVec128.m128_f32[1]))
               + (float)(v95 * colObjWorldTransform->m_basis.m_el[2].mVec128.m128_f32[1]);
          v106 = v124 * v105;
          v107 = colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[1];
          v131 = (float)(v106 + (float)(v98 * colObjWorldTransform->m_basis.m_el[1].mVec128.m128_f32[1]))
               + (float)(v123 * colObjWorldTransform->m_basis.m_el[2].mVec128.m128_f32[1]);
          v108 = v125 * v107;
          v109 = colObjWorldTransform->m_basis.m_el[2].mVec128.m128_f32[0];
          v130 = (float)(v108 + (float)(v102 * colObjWorldTransform->m_basis.m_el[1].mVec128.m128_f32[1]))
               + (float)(v121 * colObjWorldTransform->m_basis.m_el[2].mVec128.m128_f32[1]);
          v110 = colObjWorldTransform->m_basis.m_el[1].mVec128.m128_f32[0];
          v111 = (float)(v97 * v110) + (float)(v95 * v109);
          v112 = colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[0];
          v132 = v111 + (float)(v91 * colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[0]);
          v124 = (float)((float)(v98 * v110) + (float)(v123 * v109)) + (float)(v124 * v112);
          v125 = (float)((float)(v102 * v110) + (float)(v121 * v109)) + (float)(v125 * v112);
          btMatrix3x3::setValue(
            (btMatrix3x3 *)&v125,
            (int)&v136,
            &v124,
            &v132,
            &v130,
            &v131,
            &v133,
            &v134,
            &v129,
            &v135,
            v117);
          to.mVec128.m128_u64[0] = v128.mVec128.m128_u64[0];
          v115 = *v140;
          to.mVec128.m128_u64[1] = v128.mVec128.m128_u64[1];
          ___rayTest_URayTester__CL___rayTestSingle_btCollisionWorld__SAXABVbtTransform__0PAVbtCollisionObject__PBVbtCollisionShape__0AAURayResultCallback_3__Z__btDbvt__SAXPBUbtDbvtNode__ABVbtVector3__1AAURayTester__CL___rayTestSingle_btCollisionWorld__SAXABVbtTransform__2PAVbtCollisionObject__PBVbtCollisionShape__2AAURayResultCallback_5__Z__Z(
            &to,
            v115,
            (const btVector3 *)&v126,
            (btCollisionWorld::rayTestSingle::__l43::RayTester *)&policy);
        }
        else
        {
          v113 = (const float *)collisionShape->m_simplexVectorW[0].mVec128.m128_i32[0];
          for ( i = 0; i < (int)v113; ++i )
            btCollisionWorld::rayTestSingle_::_43_::RayTester::Process(v48, v113, (btCollisionObject **)&policy, i);
        }
      }
    }
    else if ( v7 == 21 )
    {
      btTransform::inverse((btTransform *)8, (int)colObjWorldTransform, &v136);
      v25 = rayFromTrans->m_origin.mVec128.m128_f32[1];
      v26 = rayFromTrans->m_origin.mVec128.m128_f32[0];
      v27 = rayFromTrans->m_origin.mVec128.m128_f32[2];
      *(float *)&v126.__vftable = (float)((float)((float)(v136.m_basis.m_el[0].mVec128.m128_f32[0] * v26)
                                                + (float)(v136.m_basis.m_el[0].mVec128.m128_f32[1] * v25))
                                        + (float)(v136.m_basis.m_el[0].mVec128.m128_f32[2] * v27))
                                + v136.m_origin.mVec128.m128_f32[0];
      v28 = (float)((float)((float)(v136.m_basis.m_el[1].mVec128.m128_f32[0] * v26)
                          + (float)(v136.m_basis.m_el[1].mVec128.m128_f32[1] * v25))
                  + (float)(v136.m_basis.m_el[1].mVec128.m128_f32[2] * v27))
          + v136.m_origin.mVec128.m128_f32[1];
      v29 = rayFromTrans->m_origin.mVec128.m128_f32[0];
      *(float *)&v126.m_simplexSolver = v28;
      v30 = (float)((float)((float)(v136.m_basis.m_el[2].mVec128.m128_f32[0] * v29)
                          + (float)(v136.m_basis.m_el[2].mVec128.m128_f32[1] * v25))
                  + (float)(v136.m_basis.m_el[2].mVec128.m128_f32[2] * rayFromTrans->m_origin.mVec128.m128_f32[2]))
          + v136.m_origin.mVec128.m128_f32[2];
      v31 = rayToTrans->m_origin.mVec128.m128_f32[2];
      *(float *)&v126.m_convexA = v30;
      v118 = rayToTrans->m_origin.mVec128.m128_f32[1];
      v32 = rayToTrans->m_origin.mVec128.m128_f32[0];
      to.mVec128.m128_f32[0] = (float)((float)((float)(v136.m_basis.m_el[0].mVec128.m128_f32[0] * v32)
                                             + (float)(v136.m_basis.m_el[0].mVec128.m128_f32[1] * v118))
                                     + (float)(v136.m_basis.m_el[0].mVec128.m128_f32[2] * v31))
                             + v136.m_origin.mVec128.m128_f32[0];
      v126.m_convexB = 0;
      to.mVec128.m128_f32[1] = (float)((float)((float)(v136.m_basis.m_el[1].mVec128.m128_f32[0] * v32)
                                             + (float)(v136.m_basis.m_el[1].mVec128.m128_f32[1] * v118))
                                     + (float)(v136.m_basis.m_el[1].mVec128.m128_f32[2] * v31))
                             + v136.m_origin.mVec128.m128_f32[1];
      to.mVec128.m128_f32[2] = (float)((float)((float)(v136.m_basis.m_el[2].mVec128.m128_f32[0] * v32)
                                             + (float)(v136.m_basis.m_el[2].mVec128.m128_f32[1] * v118))
                                     + (float)(v136.m_basis.m_el[2].mVec128.m128_f32[2] * v31))
                             + v136.m_origin.mVec128.m128_f32[2];
      to.mVec128.m128_i32[3] = 0;
      btCollisionWorld::rayTestSingle_::_33_::BridgeTriangleRaycastCallback::BridgeTriangleRaycastCallback(
        (btCollisionWorld::rayTestSingle::__l33::BridgeTriangleRaycastCallback *)&result,
        (const btVector3 *)&v126,
        &to,
        resultCallback,
        collisionObject,
        (btTriangleMeshShape *)collisionShape);
      result.m_simplexVectorW[2].mVec128.m128_i32[1] = LODWORD(resultCallback->m_closestHitFraction);
      btBvhTriangleMeshShape::performRaycast(
        (btBvhTriangleMeshShape *)collisionShape,
        &to,
        (btTriangleCallback *)&result,
        (const btVector3 *)&v126);
    }
    else
    {
      btTransform::inverse((btTransform *)8, (int)colObjWorldTransform, &v136);
      v33 = rayFromTrans->m_origin.mVec128.m128_f32[1];
      v34 = rayFromTrans->m_origin.mVec128.m128_f32[0];
      v35 = rayFromTrans->m_origin.mVec128.m128_f32[2];
      v36 = (float)((float)(v136.m_basis.m_el[0].mVec128.m128_f32[0] * v34)
                  + (float)(v136.m_basis.m_el[0].mVec128.m128_f32[1] * v33))
          + (float)(v136.m_basis.m_el[0].mVec128.m128_f32[2] * v35);
      v37 = (float)(v136.m_basis.m_el[1].mVec128.m128_f32[0] * v34)
          + (float)(v136.m_basis.m_el[1].mVec128.m128_f32[1] * v33);
      v38 = v136.m_basis.m_el[1].mVec128.m128_f32[2] * v35;
      v39 = rayFromTrans->m_origin.mVec128.m128_f32[0];
      *(float *)&v126.m_simplexSolver = (float)(v37 + v38) + v136.m_origin.mVec128.m128_f32[1];
      v40 = (float)(v136.m_basis.m_el[2].mVec128.m128_f32[0] * v39)
          + (float)(v136.m_basis.m_el[2].mVec128.m128_f32[1] * v33);
      v41 = v36 + v136.m_origin.mVec128.m128_f32[0];
      v42 = rayToTrans->m_origin.mVec128.m128_f32[2];
      *(float *)&v126.m_convexA = (float)(v40
                                        + (float)(v136.m_basis.m_el[2].mVec128.m128_f32[2]
                                                * rayFromTrans->m_origin.mVec128.m128_f32[2]))
                                + v136.m_origin.mVec128.m128_f32[2];
      v119 = rayToTrans->m_origin.mVec128.m128_f32[1];
      v43 = rayToTrans->m_origin.mVec128.m128_f32[0];
      v44 = (float)((float)((float)(v136.m_basis.m_el[0].mVec128.m128_f32[0] * v43)
                          + (float)(v136.m_basis.m_el[0].mVec128.m128_f32[1] * v119))
                  + (float)(v136.m_basis.m_el[0].mVec128.m128_f32[2] * v42))
          + v136.m_origin.mVec128.m128_f32[0];
      v45 = (float)((float)((float)(v136.m_basis.m_el[1].mVec128.m128_f32[0] * v43)
                          + (float)(v136.m_basis.m_el[1].mVec128.m128_f32[1] * v119))
                  + (float)(v136.m_basis.m_el[1].mVec128.m128_f32[2] * v42))
          + v136.m_origin.mVec128.m128_f32[1];
      v46 = (float)((float)((float)(v136.m_basis.m_el[2].mVec128.m128_f32[0] * v43)
                          + (float)(v136.m_basis.m_el[2].mVec128.m128_f32[1] * v119))
                  + (float)(v136.m_basis.m_el[2].mVec128.m128_f32[2] * v42))
          + v136.m_origin.mVec128.m128_f32[2];
      *(float *)&v126.__vftable = v41;
      v126.m_convexB = 0;
      v128.mVec128.m128_f32[0] = v44;
      v128.mVec128.m128_f32[1] = v45;
      v128.mVec128.m128_f32[2] = v46;
      v128.mVec128.m128_i32[3] = 0;
      btCollisionWorld::rayTestSingle_::_36_::BridgeTriangleRaycastCallback::BridgeTriangleRaycastCallback(
        (btCollisionWorld::rayTestSingle::__l36::BridgeTriangleRaycastCallback *)&result,
        (const btVector3 *)&v126,
        &v128,
        resultCallback,
        collisionObject,
        (btConcaveShape *)collisionShape);
      m_closestHitFraction = resultCallback->m_closestHitFraction;
      to = (btVector3)v126;
      result.m_simplexVectorW[2].mVec128.m128_f32[1] = m_closestHitFraction;
      if ( v41 > v44 )
        to.mVec128.m128_f32[0] = v44;
      if ( to.mVec128.m128_f32[1] > v45 )
        to.mVec128.m128_f32[1] = v45;
      if ( to.mVec128.m128_f32[2] > v46 )
        to.mVec128.m128_f32[2] = v46;
      if ( to.mVec128.m128_f32[3] > 0.0 )
        to.mVec128.m128_i32[3] = 0;
      policy = v126;
      if ( v44 > v41 )
        *(float *)&policy.__vftable = v44;
      if ( v45 > *(float *)&policy.m_simplexSolver )
        *(float *)&policy.m_simplexSolver = v45;
      if ( v46 > *(float *)&policy.m_convexA )
        *(float *)&policy.m_convexA = v46;
      if ( *(float *)&policy.m_convexB < 0.0 )
        policy.m_convexB = 0;
      (*(void (__thiscall **)(btVoronoiSimplexSolver *, btVoronoiSimplexSolver *, btVector3 *, btSubsimplexConvexCast *))(collisionShape->m_numVertices + 56))(
        collisionShape,
        &result,
        &to,
        &policy);
    }
  }
  else
  {
    v8 = resultCallback->m_closestHitFraction;
    v143 &= ~1u;
    v143 &= ~2u;
    v143 &= ~4u;
    v143 &= ~8u;
    v126.m_simplexSolver = (btVoronoiSimplexSolver *)&result.m_cachedP1;
    v126.m_convexA = (const btConvexShape *)&result.m_simplexPointsQ[1];
    result.m_simplexPointsQ[0].mVec128.m128_u64[0] = LODWORD(v8);
    result.m_numVertices = (int)&btConvexCast::CastResult::`vftable';
    result.m_simplexPointsQ[0].mVec128.m128_i32[2] = 0;
    v142 = FLOAT_0_000099999997;
    v126.__vftable = (btSubsimplexConvexCast_vtbl *)&btSubsimplexConvexCast::`vftable';
    v126.m_convexB = (const btConvexShape *)collisionShape;
    if ( btSubsimplexConvexCast::calcTimeOfImpact(
           &v126,
           rayFromTrans,
           rayToTrans,
           colObjWorldTransform,
           colObjWorldTransform,
           &result) )
    {
      if ( (float)((float)((float)(result.m_simplexPointsP[3].mVec128.m128_f32[0]
                                 * result.m_simplexPointsP[3].mVec128.m128_f32[0])
                         + (float)(result.m_simplexPointsP[3].mVec128.m128_f32[2]
                                 * result.m_simplexPointsP[3].mVec128.m128_f32[2]))
                 + (float)(result.m_simplexPointsP[3].mVec128.m128_f32[1]
                         * result.m_simplexPointsP[3].mVec128.m128_f32[1])) > 0.000099999997 )
      {
        v9 = resultCallback;
        if ( resultCallback->m_closestHitFraction > result.m_simplexPointsQ[0].mVec128.m128_f32[0] )
        {
          v10 = (float)((float)(rayFromTrans->m_basis.m_el[1].mVec128.m128_f32[2]
                              * result.m_simplexPointsP[3].mVec128.m128_f32[2])
                      + (float)(rayFromTrans->m_basis.m_el[1].mVec128.m128_f32[1]
                              * result.m_simplexPointsP[3].mVec128.m128_f32[1]))
              + (float)(rayFromTrans->m_basis.m_el[1].mVec128.m128_f32[0]
                      * result.m_simplexPointsP[3].mVec128.m128_f32[0]);
          v11 = (float)(rayFromTrans->m_basis.m_el[2].mVec128.m128_f32[2]
                      * result.m_simplexPointsP[3].mVec128.m128_f32[2])
              + (float)(rayFromTrans->m_basis.m_el[2].mVec128.m128_f32[1]
                      * result.m_simplexPointsP[3].mVec128.m128_f32[1]);
          v12 = rayFromTrans->m_basis.m_el[2].mVec128.m128_f32[0] * result.m_simplexPointsP[3].mVec128.m128_f32[0];
          *(float *)&v126.__vftable = (float)((float)(rayFromTrans->m_basis.m_el[0].mVec128.m128_f32[2]
                                                    * result.m_simplexPointsP[3].mVec128.m128_f32[2])
                                            + (float)(rayFromTrans->m_basis.m_el[0].mVec128.m128_f32[1]
                                                    * result.m_simplexPointsP[3].mVec128.m128_f32[1]))
                                    + (float)(rayFromTrans->m_basis.m_el[0].mVec128.m128_f32[0]
                                            * result.m_simplexPointsP[3].mVec128.m128_f32[0]);
          v126.m_convexB = 0;
          *(float *)&v126.m_convexA = v11 + v12;
          *(float *)&v126.m_simplexSolver = v10;
          result.m_simplexPointsP[3].mVec128.m128_f32[1] = v10;
          result.m_simplexPointsP[3].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v11 + v12);
          v13 = s_bm_current_air_resistance
              / fsqrt(
                  (float)((float)(*(float *)&v126.__vftable * *(float *)&v126.__vftable)
                        + (float)(*(float *)&v126.m_convexA * *(float *)&v126.m_convexA))
                + (float)(v10 * v10));
          result.m_simplexPointsP[3].mVec128.m128_f32[0] = *(float *)&v126.__vftable * v13;
          result.m_simplexPointsP[3].mVec128.m128_f32[1] = result.m_simplexPointsP[3].mVec128.m128_f32[1] * v13;
          v14 = result.m_simplexPointsP[3].mVec128.m128_f32[2] * v13;
LABEL_17:
          policy.m_simplexSolver = 0;
          result.m_simplexPointsP[3].mVec128.m128_f32[2] = v14;
          policy.__vftable = (btSubsimplexConvexCast_vtbl *)collisionObject;
          v24 = v9->__vftable;
          policy_16.mVec128 = (__m128)result.m_simplexPointsP[3];
          v139 = result.m_simplexPointsQ[0].mVec128.m128_i32[0];
          v24->addSingleResult(v9, (btCollisionWorld::LocalRayResult *)&policy, 1);
        }
      }
    }
    else
    {
      m_numVertices = collisionShape->m_numVertices;
      result.m_numVertices = (int)&btConvexCast::CastResult::`vftable';
      memset(result.m_simplexPointsQ, 0, 12);
      (*(void (__thiscall **)(btVoronoiSimplexSolver *, const btTransform *, btVector3 *, btVector3 *))(m_numVertices + 4))(
        collisionShape,
        colObjWorldTransform,
        &v128,
        &to);
      v16 = rayFromTrans->m_origin.mVec128.m128_f32[0];
      if ( v16 >= v128.mVec128.m128_f32[0] )
      {
        v17 = rayFromTrans->m_origin.mVec128.m128_f32[1];
        if ( v17 >= v128.mVec128.m128_f32[1] )
        {
          v18 = rayFromTrans->m_origin.mVec128.m128_f32[2];
          if ( v18 >= v128.mVec128.m128_f32[2]
            && to.mVec128.m128_f32[0] >= v16
            && to.mVec128.m128_f32[1] >= v17
            && to.mVec128.m128_f32[2] >= v18 )
          {
            if ( btSubsimplexConvexCast::calcTimeOfImpact(
                   &v126,
                   rayToTrans,
                   rayFromTrans,
                   colObjWorldTransform,
                   colObjWorldTransform,
                   &result) )
            {
              if ( s_bm_current_air_resistance >= result.m_simplexPointsQ[0].mVec128.m128_f32[0]
                && (float)((float)((float)(result.m_simplexPointsP[3].mVec128.m128_f32[0]
                                         * result.m_simplexPointsP[3].mVec128.m128_f32[0])
                                 + (float)(result.m_simplexPointsP[3].mVec128.m128_f32[1]
                                         * result.m_simplexPointsP[3].mVec128.m128_f32[1]))
                         + (float)(result.m_simplexPointsP[3].mVec128.m128_f32[2]
                                 * result.m_simplexPointsP[3].mVec128.m128_f32[2])) > 0.000099999997 )
              {
                v9 = resultCallback;
                v19 = resultCallback->m_closestHitFraction <= (float)(s_bm_current_air_resistance
                                                                    - result.m_simplexPointsQ[0].mVec128.m128_f32[0]);
                result.m_simplexPointsQ[0].mVec128.m128_f32[0] = s_bm_current_air_resistance
                                                               - result.m_simplexPointsQ[0].mVec128.m128_f32[0];
                if ( !v19 )
                {
                  v20 = (float)((float)(rayFromTrans->m_basis.m_el[1].mVec128.m128_f32[1]
                                      * result.m_simplexPointsP[3].mVec128.m128_f32[1])
                              + (float)(rayFromTrans->m_basis.m_el[1].mVec128.m128_f32[2]
                                      * result.m_simplexPointsP[3].mVec128.m128_f32[2]))
                      + (float)(rayFromTrans->m_basis.m_el[1].mVec128.m128_f32[0]
                              * result.m_simplexPointsP[3].mVec128.m128_f32[0]);
                  v21 = (float)(rayFromTrans->m_basis.m_el[2].mVec128.m128_f32[1]
                              * result.m_simplexPointsP[3].mVec128.m128_f32[1])
                      + (float)(rayFromTrans->m_basis.m_el[2].mVec128.m128_f32[2]
                              * result.m_simplexPointsP[3].mVec128.m128_f32[2]);
                  v22 = rayFromTrans->m_basis.m_el[2].mVec128.m128_f32[0]
                      * result.m_simplexPointsP[3].mVec128.m128_f32[0];
                  *(float *)&v126.__vftable = (float)((float)(rayFromTrans->m_basis.m_el[0].mVec128.m128_f32[1]
                                                            * result.m_simplexPointsP[3].mVec128.m128_f32[1])
                                                    + (float)(rayFromTrans->m_basis.m_el[0].mVec128.m128_f32[2]
                                                            * result.m_simplexPointsP[3].mVec128.m128_f32[2]))
                                            + (float)(rayFromTrans->m_basis.m_el[0].mVec128.m128_f32[0]
                                                    * result.m_simplexPointsP[3].mVec128.m128_f32[0]);
                  v126.m_convexB = 0;
                  *(float *)&v126.m_convexA = v21 + v22;
                  *(float *)&v126.m_simplexSolver = v20;
                  result.m_simplexPointsP[3].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v21 + v22);
                  v23 = s_bm_current_air_resistance
                      / fsqrt(
                          (float)((float)(*(float *)&v126.__vftable * *(float *)&v126.__vftable)
                                + (float)(*(float *)&v126.m_convexA * *(float *)&v126.m_convexA))
                        + (float)(v20 * v20));
                  result.m_simplexPointsP[3].mVec128.m128_f32[0] = *(float *)&v126.__vftable * v23;
                  result.m_simplexPointsP[3].mVec128.m128_f32[1] = v20 * v23;
                  v14 = result.m_simplexPointsP[3].mVec128.m128_f32[2] * v23;
                  goto LABEL_17;
                }
              }
            }
          }
        }
      }
    }
  }
}
