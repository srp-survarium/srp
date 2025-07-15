void __cdecl btCollisionWorld::objectQuerySingle(
        unsigned __int64 castShape,
        unsigned __int64 convexToTrans,
        unsigned __int64 collisionShape,
        unsigned __int64 resultCallback)
{
  int v4; // eax
  float v5; // xmm0_4
  int v6; // xmm1_4
  float v7; // xmm2_4
  int v8; // eax
  btTransform *v9; // ecx
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm1_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  int v25; // xmm2_4
  float v26; // xmm2_4
  float v27; // xmm7_4
  float v28; // xmm0_4
  int v29; // eax
  unsigned int v30; // xmm0_4
  float v31; // xmm5_4
  float v32; // xmm4_4
  float v33; // xmm3_4
  float v34; // xmm0_4
  float v35; // xmm6_4
  float v36; // xmm0_4
  float v37; // xmm4_4
  float v38; // xmm7_4
  float v39; // xmm4_4
  float v40; // xmm7_4
  float v41; // xmm7_4
  float v42; // xmm0_4
  float v43; // xmm6_4
  float v44; // xmm7_4
  float v45; // xmm6_4
  float v46; // xmm0_4
  float v47; // xmm4_4
  float v48; // xmm4_4
  float v49; // xmm6_4
  float v50; // xmm4_4
  float v51; // xmm6_4
  float v52; // xmm2_4
  float v53; // xmm1_4
  float v54; // xmm0_4
  int v55; // eax
  float v56; // xmm6_4
  float v57; // xmm5_4
  int v58; // eax
  float v59; // xmm2_4
  float v60; // xmm3_4
  float v61; // xmm1_4
  float v62; // xmm0_4
  float v63; // xmm3_4
  float v64; // xmm2_4
  float v65; // xmm1_4
  float v66; // xmm0_4
  float v67; // xmm2_4
  float v68; // xmm1_4
  float v69; // xmm4_4
  float v70; // xmm3_4
  float v71; // xmm0_4
  float v72; // xmm1_4
  float v73; // xmm2_4
  int v74; // eax
  float v75; // xmm6_4
  float v76; // xmm5_4
  const btDbvtNode **v77; // eax
  const btDbvtNode *v78; // eax
  float triangleCollisionMargin; // [esp+0h] [ebp-434h]
  float triangleCollisionMargina; // [esp+0h] [ebp-434h]
  const float *v81; // [esp+4h] [ebp-430h]
  btMatrix3x3 v82; // [esp+14h] [ebp-420h] BYREF
  btVector3 v83; // [esp+44h] [ebp-3F0h]
  float v84; // [esp+54h] [ebp-3E0h]
  float v85; // [esp+58h] [ebp-3DCh]
  float v86; // [esp+5Ch] [ebp-3D8h]
  btVector3 v87; // [esp+64h] [ebp-3D0h] BYREF
  btVector3 rayTarget; // [esp+74h] [ebp-3C0h] BYREF
  float v89; // [esp+8Ch] [ebp-3A8h] BYREF
  float v90; // [esp+90h] [ebp-3A4h] BYREF
  float v91; // [esp+94h] [ebp-3A0h] BYREF
  float v92; // [esp+98h] [ebp-39Ch] BYREF
  float v93; // [esp+9Ch] [ebp-398h] BYREF
  float v94; // [esp+A0h] [ebp-394h] BYREF
  btVector3 raySource; // [esp+A4h] [ebp-390h] BYREF
  btCollisionWorld::objectQuerySingle::__l47::VolumeTester nodeCallback; // [esp+B8h] [ebp-37Ch] BYREF
  btTriangleConvexcastCallback *p_result; // [esp+C0h] [ebp-374h]
  float v98; // [esp+C4h] [ebp-370h]
  float v99; // [esp+C8h] [ebp-36Ch]
  float v100; // [esp+CCh] [ebp-368h]
  int v101; // [esp+D0h] [ebp-364h]
  btContinuousConvexCollision v102; // [esp+D4h] [ebp-360h] BYREF
  btVector3 aabbMin; // [esp+F4h] [ebp-340h] BYREF
  btDbvtAabbMm v104; // [esp+104h] [ebp-330h] BYREF
  unsigned __int64 v105; // [esp+124h] [ebp-310h]
  unsigned __int64 v106; // [esp+12Ch] [ebp-308h]
  btDbvtAabbMm vol; // [esp+134h] [ebp-300h] BYREF
  unsigned __int64 v108; // [esp+154h] [ebp-2E0h]
  unsigned __int64 v109; // [esp+15Ch] [ebp-2D8h]
  float v110; // [esp+164h] [ebp-2D0h]
  float v111; // [esp+168h] [ebp-2CCh]
  float v112; // [esp+16Ch] [ebp-2C8h]
  int v113; // [esp+170h] [ebp-2C4h]
  btTriangleConvexcastCallback result; // [esp+174h] [ebp-2C0h] BYREF
  int v115; // [esp+254h] [ebp-1E0h]
  int v116; // [esp+258h] [ebp-1DCh]
  int v117; // [esp+25Ch] [ebp-1D8h]
  btVector3 v118; // [esp+264h] [ebp-1D0h] BYREF
  btVector3 v119; // [esp+274h] [ebp-1C0h]
  unsigned __int64 v120; // [esp+284h] [ebp-1B0h]
  unsigned __int64 v121; // [esp+28Ch] [ebp-1A8h]
  unsigned __int64 v122; // [esp+294h] [ebp-1A0h]
  unsigned __int64 v123; // [esp+29Ch] [ebp-198h]
  char v124; // [esp+2A4h] [ebp-190h] BYREF
  float v125; // [esp+3E4h] [ebp-50h]
  __int16 v126; // [esp+404h] [ebp-30h]

  v4 = *(_DWORD *)(collisionShape + 4);
  if ( v4 >= 20 )
  {
    v9 = (btTransform *)(v4 - 21);
    if ( (unsigned int)(v4 - 21) > 8 )
    {
      if ( v4 == 31 )
      {
        v104.mi.mVec128.m128_u64[0] = castShape;
        v104.mx.mVec128.m128_u64[1] = resultCallback;
        v104.mi.mVec128.m128_u64[1] = convexToTrans;
        v104.mx.mVec128.m128_u64[0] = collisionShape;
        btTransform::inverse((btTransform *)&v82.m_el[1], SHIDWORD(collisionShape), (btTransform *)&v82.m_el[1]);
        v59 = *(float *)(HIDWORD(castShape) + 52);
        v60 = *(float *)(HIDWORD(castShape) + 48);
        v61 = *(float *)(HIDWORD(castShape) + 56);
        raySource.mVec128.m128_f32[0] = (float)((float)((float)(v82.m_el[1].mVec128.m128_f32[0] * v60)
                                                      + (float)(v82.m_el[1].mVec128.m128_f32[1] * v59))
                                              + (float)(v82.m_el[1].mVec128.m128_f32[2] * v61))
                                      + v84;
        raySource.mVec128.m128_f32[1] = (float)((float)((float)(v82.m_el[2].mVec128.m128_f32[0] * v60)
                                                      + (float)(v82.m_el[2].mVec128.m128_f32[1] * v59))
                                              + (float)(v82.m_el[2].mVec128.m128_f32[2] * v61))
                                      + v85;
        v62 = (float)(v83.mVec128.m128_f32[0] * v60) + (float)(v83.mVec128.m128_f32[1] * v59);
        v63 = *(float *)(convexToTrans + 52);
        v64 = v83.mVec128.m128_f32[2] * v61;
        v65 = *(float *)(convexToTrans + 48);
        v66 = v62 + v64;
        v67 = *(float *)(convexToTrans + 56);
        v98 = (float)((float)((float)(v65 * v82.m_el[1].mVec128.m128_f32[0])
                            + (float)(v63 * v82.m_el[1].mVec128.m128_f32[1]))
                    + (float)(v67 * v82.m_el[1].mVec128.m128_f32[2]))
            + v84;
        raySource.mVec128.m128_f32[2] = v66 + v86;
        raySource.mVec128.m128_i32[3] = 0;
        v99 = (float)((float)((float)(v65 * v82.m_el[2].mVec128.m128_f32[0])
                            + (float)(v63 * v82.m_el[2].mVec128.m128_f32[1]))
                    + (float)(v67 * v82.m_el[2].mVec128.m128_f32[2]))
            + v85;
        v68 = (float)(v65 * v83.mVec128.m128_f32[0]) + (float)(v63 * v83.mVec128.m128_f32[1]);
        v69 = *(float *)(convexToTrans + 24);
        v70 = *(float *)(convexToTrans + 40);
        v100 = (float)(v68 + (float)(v67 * v83.mVec128.m128_f32[2])) + v86;
        memset(&vol, 0, 16);
        v71 = *(float *)(convexToTrans + 8);
        *(float *)&nodeCallback.m_input_params = (float)((float)(v71 * v83.mVec128.m128_f32[0])
                                                       + (float)(v69 * v83.mVec128.m128_f32[1]))
                                               + (float)(v70 * v83.mVec128.m128_f32[2]);
        v82.m_el[0].mVec128.m128_i32[2] = *(_DWORD *)(convexToTrans + 36);
        v82.m_el[0].mVec128.m128_i32[1] = *(_DWORD *)(convexToTrans + 20);
        v72 = *(float *)(convexToTrans + 4);
        v82.m_el[0].mVec128.m128_i32[0] = *(_DWORD *)convexToTrans;
        v89 = (float)((float)(v72 * v83.mVec128.m128_f32[0])
                    + (float)(v82.m_el[0].mVec128.m128_f32[1] * v83.mVec128.m128_f32[1]))
            + (float)(v82.m_el[0].mVec128.m128_f32[2] * v83.mVec128.m128_f32[2]);
        v82.m_el[0].mVec128.m128_i32[3] = *(_DWORD *)(convexToTrans + 32);
        v73 = *(float *)(convexToTrans + 16);
        v94 = (float)((float)(v73 * v83.mVec128.m128_f32[1])
                    + (float)(v82.m_el[0].mVec128.m128_f32[3] * v83.mVec128.m128_f32[2]))
            + (float)(v82.m_el[0].mVec128.m128_f32[0] * v83.mVec128.m128_f32[0]);
        v93 = (float)((float)(v71 * v82.m_el[2].mVec128.m128_f32[0]) + (float)(v69 * v82.m_el[2].mVec128.m128_f32[1]))
            + (float)(v70 * v82.m_el[2].mVec128.m128_f32[2]);
        v92 = (float)((float)(v72 * v82.m_el[2].mVec128.m128_f32[0])
                    + (float)(v82.m_el[0].mVec128.m128_f32[1] * v82.m_el[2].mVec128.m128_f32[1]))
            + (float)(v82.m_el[0].mVec128.m128_f32[2] * v82.m_el[2].mVec128.m128_f32[2]);
        v90 = (float)((float)(v73 * v82.m_el[2].mVec128.m128_f32[1])
                    + (float)(v82.m_el[0].mVec128.m128_f32[3] * v82.m_el[2].mVec128.m128_f32[2]))
            + (float)(v82.m_el[0].mVec128.m128_f32[0] * v82.m_el[2].mVec128.m128_f32[0]);
        v91 = (float)((float)(v71 * v82.m_el[1].mVec128.m128_f32[0]) + (float)(v69 * v82.m_el[1].mVec128.m128_f32[1]))
            + (float)(v70 * v82.m_el[1].mVec128.m128_f32[2]);
        v82.m_el[0].mVec128.m128_f32[1] = (float)((float)(v72 * v82.m_el[1].mVec128.m128_f32[0])
                                                + (float)(v82.m_el[0].mVec128.m128_f32[1]
                                                        * v82.m_el[1].mVec128.m128_f32[1]))
                                        + (float)(v82.m_el[0].mVec128.m128_f32[2] * v82.m_el[1].mVec128.m128_f32[2]);
        v82.m_el[0].mVec128.m128_f32[0] = (float)((float)(v73 * v82.m_el[1].mVec128.m128_f32[1])
                                                + (float)(v82.m_el[0].mVec128.m128_f32[3]
                                                        * v82.m_el[1].mVec128.m128_f32[2]))
                                        + (float)(v82.m_el[0].mVec128.m128_f32[0] * v82.m_el[1].mVec128.m128_f32[0]);
        btMatrix3x3::setValue(
          &v82,
          (int)&v82.m_el[1],
          &v82.m_el[0].mVec128.m128_f32[1],
          &v91,
          &v90,
          &v92,
          &v93,
          &v94,
          &v89,
          (const float *)&nodeCallback,
          v81);
        v118.mVec128 = (__m128)v82.m_el[1];
        v119.mVec128 = (__m128)v82.m_el[2];
        v120 = v83.mVec128.m128_u64[0];
        v74 = *(_DWORD *)castShape;
        v121 = v83.mVec128.m128_u64[1];
        v122 = vol.mi.mVec128.m128_u64[0];
        v123 = vol.mi.mVec128.m128_u64[1];
        (*(void (__thiscall **)(_DWORD, btVector3 *, btContinuousConvexCollision *, btVector3 *))(v74 + 4))(
          castShape,
          &v118,
          &v102,
          &aabbMin);
        rayTarget.mVec128 = raySource.mVec128;
        if ( raySource.mVec128.m128_f32[0] > v98 )
          rayTarget.mVec128.m128_f32[0] = v98;
        v75 = rayTarget.mVec128.m128_f32[1];
        if ( rayTarget.mVec128.m128_f32[1] > v99 )
          v75 = v99;
        v76 = rayTarget.mVec128.m128_f32[2];
        if ( rayTarget.mVec128.m128_f32[2] > v100 )
          v76 = v100;
        if ( rayTarget.mVec128.m128_f32[3] > 0.0 )
          rayTarget.mVec128.m128_i32[3] = 0;
        v87.mVec128 = raySource.mVec128;
        if ( v98 > raySource.mVec128.m128_f32[0] )
          v87.mVec128.m128_f32[0] = v98;
        if ( v99 > v87.mVec128.m128_f32[1] )
          v87.mVec128.m128_f32[1] = v99;
        if ( v100 > v87.mVec128.m128_f32[2] )
          v87.mVec128.m128_f32[2] = v100;
        if ( v87.mVec128.m128_f32[3] < 0.0 )
          v87.mVec128.m128_i32[3] = 0;
        v77 = *(const btDbvtNode ***)(collisionShape + 64);
        rayTarget.mVec128.m128_f32[0] = *(float *)&v102.__vftable + rayTarget.mVec128.m128_f32[0];
        rayTarget.mVec128.m128_f32[1] = *(float *)&v102.m_simplexSolver + v75;
        rayTarget.mVec128.m128_f32[2] = *(float *)&v102.m_penetrationDepthSolver + v76;
        v87.mVec128.m128_f32[0] = aabbMin.mVec128.m128_f32[0] + v87.mVec128.m128_f32[0];
        v87.mVec128.m128_f32[1] = aabbMin.mVec128.m128_f32[1] + v87.mVec128.m128_f32[1];
        v87.mVec128.m128_f32[2] = aabbMin.mVec128.m128_f32[2] + v87.mVec128.m128_f32[2];
        nodeCallback.m_input_params = (btCollisionWorld::objectQuerySingle::__l45::input_params *)&v104;
        nodeCallback.m_compoundShape = (const btCompoundShape *)collisionShape;
        if ( v77 )
        {
          vol.mi.mVec128.m128_u64[0] = rayTarget.mVec128.m128_u64[0];
          v78 = *v77;
          vol.mi.mVec128.m128_u64[1] = rayTarget.mVec128.m128_u64[1];
          vol.mx = (btVector3)v87.mVec128;
          if ( v78 )
            ___collideTV_UVolumeTester__CP___objectQuerySingle_btCollisionWorld__SAXPBVbtConvexShape__ABVbtTransform__1PAVbtCollisionObject__PBVbtCollisionShape__1AAUConvexResultCallback_3_M_Z__btDbvt__QAEXPBUbtDbvtNode__ABUbtDbvtAabbMm__AAUVolumeTester__CP___objectQuerySingle_btCollisionWorld__SAXPBVbtConvexShape__ABVbtTransform__3PAVbtCollisionObject__PBVbtCollisionShape__3AAUConvexResultCallback_5_M_Z__Z(
              &vol,
              v78,
              &nodeCallback);
        }
      }
    }
    else if ( v4 == 21 )
    {
      btTransform::inverse(v9, SHIDWORD(collisionShape), (btTransform *)&v82.m_el[1]);
      v10 = *(float *)(HIDWORD(castShape) + 52);
      v11 = *(float *)(HIDWORD(castShape) + 48);
      v12 = *(float *)(HIDWORD(castShape) + 56);
      raySource.mVec128.m128_f32[0] = (float)((float)((float)(v11 * v82.m_el[1].mVec128.m128_f32[0])
                                                    + (float)(v10 * v82.m_el[1].mVec128.m128_f32[1]))
                                            + (float)(v12 * v82.m_el[1].mVec128.m128_f32[2]))
                                    + v84;
      v13 = (float)((float)((float)(v11 * v82.m_el[2].mVec128.m128_f32[0])
                          + (float)(v10 * v82.m_el[2].mVec128.m128_f32[1]))
                  + (float)(v12 * v82.m_el[2].mVec128.m128_f32[2]))
          + v85;
      v14 = (float)(v11 * v83.mVec128.m128_f32[0]) + (float)(v10 * v83.mVec128.m128_f32[1]);
      v15 = *(float *)(convexToTrans + 56);
      v16 = v14 + (float)(v12 * v83.mVec128.m128_f32[2]);
      v17 = *(float *)(convexToTrans + 48);
      raySource.mVec128.m128_f32[1] = v13;
      v18 = *(float *)(convexToTrans + 52);
      rayTarget.mVec128.m128_f32[0] = (float)((float)((float)(v17 * v82.m_el[1].mVec128.m128_f32[0])
                                                    + (float)(v18 * v82.m_el[1].mVec128.m128_f32[1]))
                                            + (float)(v15 * v82.m_el[1].mVec128.m128_f32[2]))
                                    + v84;
      v19 = (float)(v17 * v82.m_el[2].mVec128.m128_f32[0]) + (float)(v18 * v82.m_el[2].mVec128.m128_f32[1]);
      v20 = (float)(v17 * v83.mVec128.m128_f32[0]) + (float)(v18 * v83.mVec128.m128_f32[1]);
      v21 = *(float *)(convexToTrans + 40);
      raySource.mVec128.m128_f32[2] = v16 + v86;
      raySource.mVec128.m128_i32[3] = 0;
      rayTarget.mVec128.m128_f32[1] = (float)(v19 + (float)(v15 * v82.m_el[2].mVec128.m128_f32[2])) + v85;
      v22 = *(float *)(convexToTrans + 24);
      rayTarget.mVec128.m128_f32[2] = (float)(v20 + (float)(v15 * v83.mVec128.m128_f32[2])) + v86;
      rayTarget.mVec128.m128_i32[3] = 0;
      v98 = 0.0;
      v99 = 0.0;
      v100 = 0.0;
      v101 = 0;
      v23 = *(float *)(convexToTrans + 8);
      v82.m_el[0].mVec128.m128_i32[0] = *(_DWORD *)(convexToTrans + 20);
      v91 = (float)((float)(v23 * v83.mVec128.m128_f32[0]) + (float)(v22 * v83.mVec128.m128_f32[1]))
          + (float)(v21 * v83.mVec128.m128_f32[2]);
      v82.m_el[0].mVec128.m128_i32[2] = *(_DWORD *)(convexToTrans + 36);
      v24 = *(float *)(convexToTrans + 4);
      v25 = *(_DWORD *)(convexToTrans + 32);
      v90 = (float)((float)(v24 * v83.mVec128.m128_f32[0])
                  + (float)(v82.m_el[0].mVec128.m128_f32[0] * v83.mVec128.m128_f32[1]))
          + (float)(v82.m_el[0].mVec128.m128_f32[2] * v83.mVec128.m128_f32[2]);
      v82.m_el[0].mVec128.m128_i32[3] = *(_DWORD *)(convexToTrans + 16);
      v82.m_el[0].mVec128.m128_i32[1] = v25;
      v26 = *(float *)convexToTrans;
      v27 = (float)((float)(*(float *)convexToTrans * v83.mVec128.m128_f32[0])
                  + (float)(v82.m_el[0].mVec128.m128_f32[3] * v83.mVec128.m128_f32[1]))
          + (float)(v82.m_el[0].mVec128.m128_f32[1] * v83.mVec128.m128_f32[2]);
      v93 = (float)((float)(v23 * v82.m_el[2].mVec128.m128_f32[0]) + (float)(v22 * v82.m_el[2].mVec128.m128_f32[1]))
          + (float)(v21 * v82.m_el[2].mVec128.m128_f32[2]);
      *(float *)&nodeCallback.m_input_params = (float)((float)(v23 * v82.m_el[1].mVec128.m128_f32[0])
                                                     + (float)(v22 * v82.m_el[1].mVec128.m128_f32[1]))
                                             + (float)(v21 * v82.m_el[1].mVec128.m128_f32[2]);
      v94 = (float)((float)(v24 * v82.m_el[2].mVec128.m128_f32[0])
                  + (float)(v82.m_el[0].mVec128.m128_f32[0] * v82.m_el[2].mVec128.m128_f32[1]))
          + (float)(v82.m_el[0].mVec128.m128_f32[2] * v82.m_el[2].mVec128.m128_f32[2]);
      v92 = v27;
      v89 = (float)((float)(v26 * v82.m_el[2].mVec128.m128_f32[0])
                  + (float)(v82.m_el[0].mVec128.m128_f32[3] * v82.m_el[2].mVec128.m128_f32[1]))
          + (float)(v82.m_el[0].mVec128.m128_f32[1] * v82.m_el[2].mVec128.m128_f32[2]);
      v82.m_el[0].mVec128.m128_f32[0] = (float)((float)(v24 * v82.m_el[1].mVec128.m128_f32[0])
                                              + (float)(v82.m_el[0].mVec128.m128_f32[0] * v82.m_el[1].mVec128.m128_f32[1]))
                                      + (float)(v82.m_el[0].mVec128.m128_f32[2] * v82.m_el[1].mVec128.m128_f32[2]);
      v82.m_el[0].mVec128.m128_f32[3] = (float)((float)(v26 * v82.m_el[1].mVec128.m128_f32[0])
                                              + (float)(v82.m_el[0].mVec128.m128_f32[3] * v82.m_el[1].mVec128.m128_f32[1]))
                                      + (float)(v82.m_el[0].mVec128.m128_f32[1] * v82.m_el[1].mVec128.m128_f32[2]);
      btMatrix3x3::setValue(
        (btMatrix3x3 *)&v82.m_el[0].m_floats[3],
        (int)&v104,
        (float *)&v82,
        (float *)&nodeCallback,
        &v89,
        &v94,
        &v93,
        &v92,
        &v90,
        &v91,
        v81);
      vol = v104;
      v108 = v105;
      v109 = v106;
      v110 = v98;
      v111 = v99;
      v112 = v100;
      v113 = v101;
      triangleCollisionMargin = ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)collisionShape + 40))(collisionShape);
      btTriangleConvexcastCallback::btTriangleConvexcastCallback(
        &result,
        (const btTransform *)HIDWORD(collisionShape),
        (const btConvexShape *)castShape,
        (const btTransform *)HIDWORD(castShape),
        (const btTransform *)convexToTrans,
        triangleCollisionMargin);
      v28 = *(float *)(resultCallback + 4);
      v116 = HIDWORD(convexToTrans);
      v115 = resultCallback;
      v29 = *(_DWORD *)castShape;
      result.m_hitFraction = v28;
      result.__vftable = (btTriangleConvexcastCallback_vtbl *)&`btCollisionWorld::objectQuerySingle'::`22'::BridgeTriangleConvexcastCallback::`vftable';
      v117 = collisionShape;
      result.m_allowedPenetration = *((float *)&resultCallback + 1);
      (*(void (__thiscall **)(_DWORD, btDbvtAabbMm *, btVector3 *, btContinuousConvexCollision *))(v29 + 4))(
        castShape,
        &vol,
        &aabbMin,
        &v102);
      nodeCallback.m_compoundShape = *(const btCompoundShape **)(collisionShape + 48);
      p_result = &result;
      nodeCallback.m_input_params = (btCollisionWorld::objectQuerySingle::__l45::input_params *)&`btBvhTriangleMeshShape::performConvexcast'::`2'::MyNodeOverlapCallback::`vftable';
      btQuantizedBvh::reportBoxCastOverlappingNodex(
        *(btQuantizedBvh **)(collisionShape + 64),
        (btNodeOverlapCallback *)&nodeCallback,
        &raySource,
        &rayTarget,
        &aabbMin,
        (const btVector3 *)&v102);
    }
    else if ( v4 == 28 )
    {
      v102.m_convexA = (const btConvexShape *)castShape;
      result.m_triangleToWorld.m_basis.m_el[2].mVec128.m128_i32[2] = HIDWORD(resultCallback);
      v30 = *(_DWORD *)(resultCallback + 4);
      result.__vftable = (btTriangleConvexcastCallback_vtbl *)&btConvexCast::CastResult::`vftable';
      result.m_triangleToWorld.m_basis.m_el[2].mVec128.m128_u64[0] = v30;
      v102.__vftable = (btContinuousConvexCollision_vtbl *)&btContinuousConvexCollision::`vftable';
      v102.m_simplexSolver = 0;
      v102.m_penetrationDepthSolver = 0;
      v102.m_convexB1 = 0;
      v102.m_planeShape = (const btStaticPlaneShape *)collisionShape;
      if ( btContinuousConvexCollision::calcTimeOfImpact(
             &v102,
             (const btTransform *)HIDWORD(castShape),
             (const btTransform *)convexToTrans,
             (const btTransform *)HIDWORD(collisionShape),
             (const btTransform *)HIDWORD(collisionShape),
             (btConvexCast::CastResult *)&result) )
      {
        v5 = (float)((float)(result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[1]
                           * result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[1])
                   + (float)(result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[2]
                           * result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[2]))
           + (float)(result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[0]
                   * result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[0]);
        if ( v5 > 0.000099999997 )
        {
          v6 = result.m_triangleToWorld.m_basis.m_el[2].mVec128.m128_i32[0];
          if ( *(float *)(resultCallback + 4) > result.m_triangleToWorld.m_basis.m_el[2].mVec128.m128_f32[0] )
          {
            v82.m_el[1].mVec128.m128_i32[1] = 0;
            goto LABEL_6;
          }
        }
      }
    }
    else
    {
      btTransform::inverse(v9, SHIDWORD(collisionShape), (btTransform *)&v82.m_el[1]);
      v31 = *(float *)(HIDWORD(castShape) + 52);
      v32 = *(float *)(HIDWORD(castShape) + 56);
      v33 = *(float *)(HIDWORD(castShape) + 48) * v82.m_el[2].mVec128.m128_f32[0];
      v34 = *(float *)(HIDWORD(castShape) + 48) * v83.mVec128.m128_f32[0];
      raySource.mVec128.m128_f32[0] = (float)((float)((float)(*(float *)(HIDWORD(castShape) + 48)
                                                            * v82.m_el[1].mVec128.m128_f32[0])
                                                    + (float)(v31 * v82.m_el[1].mVec128.m128_f32[1]))
                                            + (float)(v32 * v82.m_el[1].mVec128.m128_f32[2]))
                                    + v84;
      v35 = *(float *)(convexToTrans + 48);
      raySource.mVec128.m128_f32[1] = (float)((float)(v33 + (float)(v31 * v82.m_el[2].mVec128.m128_f32[1]))
                                            + (float)(v32 * v82.m_el[2].mVec128.m128_f32[2]))
                                    + v85;
      v36 = (float)(v34 + (float)(v31 * v83.mVec128.m128_f32[1])) + (float)(v32 * v83.mVec128.m128_f32[2]);
      v37 = *(float *)(convexToTrans + 56);
      v82.m_el[0].mVec128.m128_f32[2] = (float)(v37 * v82.m_el[1].mVec128.m128_f32[2])
                                      + (float)(v82.m_el[1].mVec128.m128_f32[0] * v35);
      v98 = (float)(v82.m_el[0].mVec128.m128_f32[2]
                  + (float)(v82.m_el[1].mVec128.m128_f32[1] * *(float *)(convexToTrans + 52)))
          + v84;
      v82.m_el[0].mVec128.m128_f32[1] = v37 * v82.m_el[2].mVec128.m128_f32[2];
      v82.m_el[0].mVec128.m128_f32[1] = (float)(v37 * v82.m_el[2].mVec128.m128_f32[2])
                                      + (float)(v82.m_el[2].mVec128.m128_f32[0] * *(float *)(convexToTrans + 48));
      v99 = (float)(v82.m_el[0].mVec128.m128_f32[1]
                  + (float)(v82.m_el[2].mVec128.m128_f32[1] * *(float *)(convexToTrans + 52)))
          + v85;
      v38 = v83.mVec128.m128_f32[0] * *(float *)(convexToTrans + 48);
      raySource.mVec128.m128_f32[2] = v36 + v86;
      raySource.mVec128.m128_i32[3] = 0;
      v39 = (float)((float)((float)(v37 * v83.mVec128.m128_f32[2]) + v38)
                  + (float)(v83.mVec128.m128_f32[1] * *(float *)(convexToTrans + 52)))
          + v86;
      v40 = v83.mVec128.m128_f32[0] * *(float *)(convexToTrans + 8);
      v100 = v39;
      v41 = v40 + (float)(v83.mVec128.m128_f32[1] * *(float *)(convexToTrans + 24));
      memset(&vol, 0, 16);
      v42 = *(float *)(convexToTrans + 20);
      v43 = *(float *)(convexToTrans + 4);
      *(float *)&nodeCallback.m_input_params = v41 + (float)(v83.mVec128.m128_f32[2] * *(float *)(convexToTrans + 40));
      v44 = v83.mVec128.m128_f32[0] * v43;
      v45 = v83.mVec128.m128_f32[1] * v42;
      v46 = *(float *)convexToTrans;
      v47 = v83.mVec128.m128_f32[2] * *(float *)(convexToTrans + 32);
      v89 = (float)(v44 + v45) + (float)(v83.mVec128.m128_f32[2] * *(float *)(convexToTrans + 36));
      v94 = (float)((float)(v83.mVec128.m128_f32[1] * *(float *)(convexToTrans + 16)) + v47)
          + (float)(v46 * v83.mVec128.m128_f32[0]);
      v48 = *(float *)(convexToTrans + 4);
      v93 = (float)((float)(v82.m_el[2].mVec128.m128_f32[0] * *(float *)(convexToTrans + 8))
                  + (float)(v82.m_el[2].mVec128.m128_f32[1] * *(float *)(convexToTrans + 24)))
          + (float)(v82.m_el[2].mVec128.m128_f32[2] * *(float *)(convexToTrans + 40));
      v49 = v82.m_el[2].mVec128.m128_f32[0] * v48;
      v50 = *(float *)(convexToTrans + 36);
      v92 = (float)(v49 + (float)(v82.m_el[2].mVec128.m128_f32[1] * *(float *)(convexToTrans + 20)))
          + (float)(v82.m_el[2].mVec128.m128_f32[2] * v50);
      v51 = *(float *)(convexToTrans + 32);
      v90 = (float)((float)(v82.m_el[2].mVec128.m128_f32[1] * *(float *)(convexToTrans + 16))
                  + (float)(v82.m_el[2].mVec128.m128_f32[2] * v51))
          + (float)(v46 * v82.m_el[2].mVec128.m128_f32[0]);
      v52 = *(float *)(convexToTrans + 4);
      v91 = (float)((float)(v82.m_el[1].mVec128.m128_f32[0] * *(float *)(convexToTrans + 8))
                  + (float)(v82.m_el[1].mVec128.m128_f32[1] * *(float *)(convexToTrans + 24)))
          + (float)(v82.m_el[1].mVec128.m128_f32[2] * *(float *)(convexToTrans + 40));
      v53 = (float)((float)(v82.m_el[1].mVec128.m128_f32[1] * *(float *)(convexToTrans + 16))
                  + (float)(v82.m_el[1].mVec128.m128_f32[2] * v51))
          + (float)(v46 * v82.m_el[1].mVec128.m128_f32[0]);
      v82.m_el[0].mVec128.m128_f32[0] = (float)((float)(v82.m_el[1].mVec128.m128_f32[0] * v52)
                                              + (float)(v82.m_el[1].mVec128.m128_f32[1] * *(float *)(convexToTrans + 20)))
                                      + (float)(v82.m_el[1].mVec128.m128_f32[2] * v50);
      v82.m_el[0].mVec128.m128_f32[3] = v53;
      btMatrix3x3::setValue(
        (btMatrix3x3 *)&v82.m_el[0].m_floats[3],
        (int)&v104,
        (float *)&v82,
        &v91,
        &v90,
        &v92,
        &v93,
        &v94,
        &v89,
        (const float *)&nodeCallback,
        v81);
      v118.mVec128 = (__m128)v104.mi;
      v119.mVec128 = (__m128)v104.mx;
      v120 = v105;
      v121 = v106;
      v122 = vol.mi.mVec128.m128_u64[0];
      v123 = vol.mi.mVec128.m128_u64[1];
      triangleCollisionMargina = ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)collisionShape + 40))(collisionShape);
      btTriangleConvexcastCallback::btTriangleConvexcastCallback(
        &result,
        (const btTransform *)HIDWORD(collisionShape),
        (const btConvexShape *)castShape,
        (const btTransform *)HIDWORD(castShape),
        (const btTransform *)convexToTrans,
        triangleCollisionMargina);
      v54 = *(float *)(resultCallback + 4);
      v116 = HIDWORD(convexToTrans);
      v115 = resultCallback;
      v55 = *(_DWORD *)castShape;
      result.m_hitFraction = v54;
      result.__vftable = (btTriangleConvexcastCallback_vtbl *)&`btCollisionWorld::objectQuerySingle'::`39'::BridgeTriangleConvexcastCallback::`vftable';
      v117 = collisionShape;
      result.m_allowedPenetration = *((float *)&resultCallback + 1);
      (*(void (__thiscall **)(_DWORD, btVector3 *, btVector3 *, btContinuousConvexCollision *))(v55 + 4))(
        castShape,
        &v118,
        &aabbMin,
        &v102);
      rayTarget.mVec128 = raySource.mVec128;
      if ( raySource.mVec128.m128_f32[0] > v98 )
        rayTarget.mVec128.m128_f32[0] = v98;
      v56 = rayTarget.mVec128.m128_f32[1];
      if ( rayTarget.mVec128.m128_f32[1] > v99 )
        v56 = v99;
      v57 = rayTarget.mVec128.m128_f32[2];
      if ( rayTarget.mVec128.m128_f32[2] > v100 )
        v57 = v100;
      if ( rayTarget.mVec128.m128_f32[3] > 0.0 )
        rayTarget.mVec128.m128_i32[3] = 0;
      v87.mVec128 = raySource.mVec128;
      if ( v98 > raySource.mVec128.m128_f32[0] )
        v87.mVec128.m128_f32[0] = v98;
      if ( v99 > v87.mVec128.m128_f32[1] )
        v87.mVec128.m128_f32[1] = v99;
      if ( v100 > v87.mVec128.m128_f32[2] )
        v87.mVec128.m128_f32[2] = v100;
      if ( v87.mVec128.m128_f32[3] < 0.0 )
        v87.mVec128.m128_i32[3] = 0;
      v58 = *(_DWORD *)collisionShape;
      rayTarget.mVec128.m128_f32[0] = aabbMin.mVec128.m128_f32[0] + rayTarget.mVec128.m128_f32[0];
      rayTarget.mVec128.m128_f32[1] = aabbMin.mVec128.m128_f32[1] + v56;
      rayTarget.mVec128.m128_f32[2] = aabbMin.mVec128.m128_f32[2] + v57;
      v87.mVec128.m128_f32[0] = *(float *)&v102.__vftable + v87.mVec128.m128_f32[0];
      v87.mVec128.m128_f32[1] = *(float *)&v102.m_simplexSolver + v87.mVec128.m128_f32[1];
      v87.mVec128.m128_f32[2] = *(float *)&v102.m_penetrationDepthSolver + v87.mVec128.m128_f32[2];
      (*(void (__thiscall **)(_DWORD, btTriangleConvexcastCallback *, btVector3 *, btVector3 *))(v58 + 56))(
        collisionShape,
        &result,
        &rayTarget,
        &v87);
    }
  }
  else
  {
    v126 &= ~1u;
    v126 &= ~2u;
    v126 &= ~4u;
    v126 &= ~8u;
    v102.m_simplexSolver = (btVoronoiSimplexSolver *)&v124;
    v102.m_penetrationDepthSolver = (btConvexPenetrationDepthSolver *)&v82;
    v102.m_convexA = (const btConvexShape *)castShape;
    result.m_triangleToWorld.m_basis.m_el[2].mVec128.m128_i32[2] = HIDWORD(resultCallback);
    result.m_triangleToWorld.m_basis.m_el[2].mVec128.m128_u64[0] = *(unsigned int *)(resultCallback + 4);
    result.__vftable = (btTriangleConvexcastCallback_vtbl *)&btConvexCast::CastResult::`vftable';
    v125 = FLOAT_0_000099999997;
    v82.m_el[0].mVec128.m128_i32[0] = (int)&btGjkEpaPenetrationDepthSolver::`vftable';
    v102.__vftable = (btContinuousConvexCollision_vtbl *)&btContinuousConvexCollision::`vftable';
    v102.m_convexB1 = (const btConvexShape *)collisionShape;
    v102.m_planeShape = 0;
    if ( btContinuousConvexCollision::calcTimeOfImpact(
           &v102,
           (const btTransform *)HIDWORD(castShape),
           (const btTransform *)convexToTrans,
           (const btTransform *)HIDWORD(collisionShape),
           (const btTransform *)HIDWORD(collisionShape),
           (btConvexCast::CastResult *)&result) )
    {
      v5 = (float)((float)(result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[0]
                         * result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[0])
                 + (float)(result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[1]
                         * result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[1]))
         + (float)(result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[2]
                 * result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[2]);
      if ( v5 > 0.000099999997 )
      {
        v6 = result.m_triangleToWorld.m_basis.m_el[2].mVec128.m128_i32[0];
        if ( *(float *)(resultCallback + 4) > result.m_triangleToWorld.m_basis.m_el[2].mVec128.m128_f32[0] )
        {
          v82.m_el[1].mVec128.m128_i32[1] = 0;
LABEL_6:
          v7 = fsqrt(v5);
          v82.m_el[1].mVec128.m128_i32[0] = HIDWORD(convexToTrans);
          result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[0] = (float)(s_bm_current_air_resistance / v7)
                                                                       * result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[0];
          result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[2] = (float)(s_bm_current_air_resistance / v7)
                                                                       * result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[2];
          result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[1] = (float)(s_bm_current_air_resistance / v7)
                                                                       * result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[1];
          v82.m_el[2].mVec128.m128_u64[0] = result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_u64[0];
          v8 = *(_DWORD *)resultCallback;
          v82.m_el[2].mVec128.m128_u64[1] = result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_u64[1];
          v83.mVec128 = (__m128)result.m_triangleToWorld.m_basis.m_el[1];
          v84 = *(float *)&v6;
          (*(void (__thiscall **)(_DWORD, btVector3 *, int))(v8 + 8))(resultCallback, &v82.m_el[1], 1);
        }
      }
    }
  }
}
