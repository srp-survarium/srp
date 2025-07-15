void __cdecl btCollisionWorld::objectQuerySingle(
        btConvexShape *castShape,
        const btTransform *convexFromTrans,
        const btTransform *convexToTrans,
        btCollisionObject *collisionObject,
        btBvhTriangleMeshShape *collisionShape,
        const btTransform *colObjWorldTransform,
        btCollisionWorld::ConvexResultCallback *resultCallback,
        float allowedPenetration)
{
  const char *v8; // ecx
  int m_shapeType; // eax
  CProfileNode *Sub_Node; // eax
  int RecursionCounter; // ecx
  float v12; // xmm0_4
  CProfileNode *v13; // ecx
  long double v14; // st7
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm5_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  btVector3 v29; // xmm0
  void (__thiscall *v30)(struct btConvexShape *, const btTransform *, btVector3 *, btVector3 *); // edx
  CProfileNode *v31; // ecx
  float m_closestHitFraction; // xmm0_4
  long double v33; // st7
  float v34; // xmm6_4
  float v35; // xmm4_4
  float v36; // xmm3_4
  float v37; // xmm0_4
  float v38; // xmm0_4
  float v39; // xmm0_4
  float v40; // xmm6_4
  unsigned int v41; // xmm6_4
  float v42; // xmm3_4
  float v43; // xmm7_4
  float v44; // xmm1_4
  float v45; // xmm5_4
  void (__thiscall *v46)(struct btConvexShape *, const btTransform *, btVector3 *, btVector3 *); // edx
  __m128 si128; // xmm2
  float v48; // xmm0_4
  float v49; // xmm5_4
  float v50; // xmm2_4
  float v51; // xmm1_4
  btCollisionShape_vtbl *v52; // eax
  void (__thiscall *v53)(btCollisionShape *); // edx
  float v55; // xmm6_4
  float v56; // xmm5_4
  float v57; // xmm1_4
  float v58; // xmm0_4
  float v59; // xmm1_4
  float v60; // xmm7_4
  float v61; // xmm6_4
  float v62; // xmm1_4
  float v63; // xmm6_4
  float v64; // xmm7_4
  float v65; // xmm1_4
  float v66; // xmm7_4
  float v67; // xmm6_4
  float v68; // xmm1_4
  float v69; // xmm5_4
  float v70; // xmm1_4
  unsigned int v71; // xmm6_4
  float v72; // xmm5_4
  float v73; // xmm5_4
  unsigned int v74; // xmm5_4
  void (__thiscall *getAabb)(struct btConvexShape *, const btTransform *, btVector3 *, btVector3 *); // eax
  unsigned int v76; // xmm3_4
  __m128 v77; // xmm2
  float v78; // xmm0_4
  float v79; // xmm3_4
  float v80; // xmm5_4
  float v81; // xmm4_4
  float v82; // xmm2_4
  float v83; // xmm1_4
  const btDbvtNode **m_bvh; // esi
  CProfileSample *v85; // ecx
  const btDbvtNode *v86; // esi
  unsigned int v87; // [esp+79F4h] [ebp-41Ch] BYREF
  float v88; // [esp+79F8h] [ebp-418h]
  float v89; // [esp+79FCh] [ebp-414h]
  float v90; // [esp+7A00h] [ebp-410h]
  float _X; // [esp+7A04h] [ebp-40Ch]
  float v92; // [esp+7A08h] [ebp-408h]
  CProfileSample v93; // [esp+7A0Fh] [ebp-401h] BYREF
  __m128i v94; // [esp+7A10h] [ebp-400h] BYREF
  __m128i v95; // [esp+7A20h] [ebp-3F0h] BYREF
  __m128i v96; // [esp+7A30h] [ebp-3E0h] BYREF
  float v97; // [esp+7A40h] [ebp-3D0h]
  float rayTarget; // [esp+7A44h] [ebp-3CCh]
  float rayTarget_4; // [esp+7A48h] [ebp-3C8h]
  btVector3 rayTarget_12; // [esp+7A50h] [ebp-3C0h] BYREF
  btVector3 raySource_12; // [esp+7A60h] [ebp-3B0h] BYREF
  float v102; // [esp+7A7Ch] [ebp-394h]
  __int64 v103; // [esp+7A80h] [ebp-390h]
  __int64 policy_4; // [esp+7A88h] [ebp-388h]
  btCollisionWorld::objectQuerySingle::__l47::VolumeTester policy_12[2]; // [esp+7A90h] [ebp-380h] BYREF
  __m128i v106; // [esp+7AA0h] [ebp-370h] BYREF
  btContinuousConvexCollision v107; // [esp+7AB0h] [ebp-360h] BYREF
  __m128i v108; // [esp+7AD0h] [ebp-340h] BYREF
  __m128i v109; // [esp+7AE0h] [ebp-330h] BYREF
  __m128i v110; // [esp+7AF0h] [ebp-320h] BYREF
  btVector3 aabbMin; // [esp+7B00h] [ebp-310h] BYREF
  btDbvtAabbMm vol; // [esp+7B10h] [ebp-300h] BYREF
  __m128i v113; // [esp+7B30h] [ebp-2E0h]
  __m128i v114; // [esp+7B40h] [ebp-2D0h]
  btCollisionWorld::LocalConvexResult v115; // [esp+7B50h] [ebp-2C0h] BYREF
  btCollisionWorld::objectQuerySingle::__l39::BridgeTriangleConvexcastCallback result; // [esp+7B90h] [ebp-280h] BYREF
  char v117; // [esp+7C80h] [ebp-190h] BYREF
  float v118; // [esp+7DC0h] [ebp-50h]
  __int16 v119; // [esp+7DE0h] [ebp-30h]

  m_shapeType = collisionShape->m_shapeType;
  if ( m_shapeType >= 20 )
  {
    if ( (unsigned int)(m_shapeType - 21) > 8 )
    {
      if ( m_shapeType == 31 )
      {
        CProfileSample::CProfileSample((CProfileSample *)&stru_958404, &v93);
        v108.m128i_i64[0] = __PAIR64__((unsigned int)convexFromTrans, (unsigned int)castShape);
        v108.m128i_i64[1] = __PAIR64__((unsigned int)collisionObject, (unsigned int)convexToTrans);
        v109.m128i_i32[0] = (int)collisionShape;
        *(__int64 *)((char *)v109.m128i_i64 + 4) = __PAIR64__(
                                                     (unsigned int)resultCallback,
                                                     (unsigned int)colObjWorldTransform);
        *(float *)&v109.m128i_i32[3] = allowedPenetration;
        btTransform::inverse(colObjWorldTransform, (btTransform *)&v94);
        v55 = convexFromTrans->m_origin.mVec128.m128_f32[1];
        v56 = convexFromTrans->m_origin.mVec128.m128_f32[0];
        v57 = convexFromTrans->m_origin.mVec128.m128_f32[2];
        *(float *)v106.m128i_i32 = (float)((float)((float)(*(float *)v94.m128i_i32 * v56)
                                                 + (float)(*(float *)&v94.m128i_i32[1] * v55))
                                         + (float)(*(float *)&v94.m128i_i32[2] * v57))
                                 + v97;
        *(float *)&v106.m128i_i32[1] = (float)((float)((float)(*(float *)v95.m128i_i32 * v56)
                                                     + (float)(*(float *)&v95.m128i_i32[1] * v55))
                                             + (float)(*(float *)&v95.m128i_i32[2] * v57))
                                     + rayTarget;
        v58 = (float)((float)(*(float *)v96.m128i_i32 * v56) + (float)(*(float *)&v96.m128i_i32[1] * v55))
            + (float)(*(float *)&v96.m128i_i32[2] * v57);
        raySource_12.mVec128.m128_f32[0] = (float)((float)((float)(*(float *)v94.m128i_i32
                                                                 * convexToTrans->m_origin.mVec128.m128_f32[0])
                                                         + (float)(*(float *)&v94.m128i_i32[1]
                                                                 * convexToTrans->m_origin.mVec128.m128_f32[1]))
                                                 + (float)(*(float *)&v94.m128i_i32[2]
                                                         * convexToTrans->m_origin.mVec128.m128_f32[2]))
                                         + v97;
        v59 = *(float *)v95.m128i_i32 * convexToTrans->m_origin.mVec128.m128_f32[0];
        v60 = *(float *)&v95.m128i_i32[1] * convexToTrans->m_origin.mVec128.m128_f32[1];
        v61 = convexToTrans->m_origin.mVec128.m128_f32[2];
        *(float *)&v106.m128i_i32[2] = v58 + rayTarget_4;
        v106.m128i_i32[3] = 0;
        raySource_12.mVec128.m128_f32[1] = (float)((float)(v59 + v60) + (float)(*(float *)&v95.m128i_i32[2] * v61))
                                         + rayTarget;
        v62 = *(float *)v96.m128i_i32 * convexToTrans->m_basis.m_el[0].mVec128.m128_f32[2];
        raySource_12.mVec128.m128_f32[2] = (float)((float)((float)(*(float *)v96.m128i_i32
                                                                 * convexToTrans->m_origin.mVec128.m128_f32[0])
                                                         + (float)(*(float *)&v96.m128i_i32[1]
                                                                 * convexToTrans->m_origin.mVec128.m128_f32[1]))
                                                 + (float)(*(float *)&v96.m128i_i32[2]
                                                         * convexToTrans->m_origin.mVec128.m128_f32[2]))
                                         + rayTarget_4;
        v63 = convexToTrans->m_basis.m_el[1].mVec128.m128_f32[1];
        v64 = convexToTrans->m_basis.m_el[0].mVec128.m128_f32[1];
        *(float *)&policy_12[0].m_input_params = (float)(v62
                                                       + (float)(*(float *)&v96.m128i_i32[1]
                                                               * convexToTrans->m_basis.m_el[1].mVec128.m128_f32[2]))
                                               + (float)(*(float *)&v96.m128i_i32[2]
                                                       * convexToTrans->m_basis.m_el[2].mVec128.m128_f32[2]);
        v65 = *(float *)v96.m128i_i32 * v64;
        v66 = *(float *)&v96.m128i_i32[1] * v63;
        v67 = convexToTrans->m_basis.m_el[0].mVec128.m128_f32[0];
        v68 = (float)(v65 + v66)
            + (float)(*(float *)&v96.m128i_i32[2] * convexToTrans->m_basis.m_el[2].mVec128.m128_f32[1]);
        v69 = *(float *)&v96.m128i_i32[1] * convexToTrans->m_basis.m_el[1].mVec128.m128_f32[0];
        _X = convexToTrans->m_basis.m_el[1].mVec128.m128_f32[0];
        v88 = v67;
        v92 = v68;
        v70 = convexToTrans->m_basis.m_el[2].mVec128.m128_f32[0];
        *(float *)&v71 = (float)((float)(v67 * *(float *)v96.m128i_i32) + v69)
                       + (float)(*(float *)&v96.m128i_i32[2] * v70);
        v72 = convexToTrans->m_basis.m_el[0].mVec128.m128_f32[2];
        *(float *)&v87 = *(float *)v95.m128i_i32 * v72;
        v90 = v72;
        LODWORD(v103) = convexToTrans->m_basis.m_el[1].mVec128.m128_i32[2];
        *(float *)&v87 = (float)(*(float *)v95.m128i_i32 * v72) + (float)(*(float *)&v95.m128i_i32[1] * *(float *)&v103);
        v102 = convexToTrans->m_basis.m_el[2].mVec128.m128_f32[2];
        v89 = *(float *)&v87 + (float)(*(float *)&v95.m128i_i32[2] * v102);
        v73 = convexToTrans->m_basis.m_el[0].mVec128.m128_f32[1];
        *(float *)&v87 = *(float *)v95.m128i_i32 * v73;
        memset(&vol, 0, 16);
        *((float *)&policy_4 + 1) = v73;
        LODWORD(policy_4) = convexToTrans->m_basis.m_el[1].mVec128.m128_i32[1];
        *(float *)&v87 = (float)(*(float *)v95.m128i_i32 * v73)
                       + (float)(*(float *)&v95.m128i_i32[1] * *(float *)&policy_4);
        HIDWORD(v103) = convexToTrans->m_basis.m_el[2].mVec128.m128_i32[1];
        *(float *)&v87 = *(float *)&v87 + (float)(*(float *)&v95.m128i_i32[2] * *((float *)&v103 + 1));
        *(float *)&v74 = (float)((float)(v88 * *(float *)v95.m128i_i32) + (float)(*(float *)&v95.m128i_i32[1] * _X))
                       + (float)(*(float *)&v95.m128i_i32[2] * v70);
        getAabb = castShape->getAabb;
        *(float *)&v76 = (float)((float)(*(float *)&v94.m128i_i32[2] * v102) + (float)(*(float *)v94.m128i_i32 * v90))
                       + (float)(*(float *)&v94.m128i_i32[1] * *(float *)&v103);
        v102 = (float)((float)(*(float *)&v94.m128i_i32[2] * *((float *)&v103 + 1))
                     + (float)(*(float *)v94.m128i_i32 * *((float *)&policy_4 + 1)))
             + (float)(*(float *)&v94.m128i_i32[1] * *(float *)&policy_4);
        *(float *)v94.m128i_i32 = (float)((float)(v70 * *(float *)&v94.m128i_i32[2])
                                        + (float)(v88 * *(float *)v94.m128i_i32))
                                + (float)(*(float *)&v94.m128i_i32[1] * _X);
        *(float *)&v94.m128i_i32[1] = v102;
        v95.m128i_i64[1] = LODWORD(v89);
        v94.m128i_i64[1] = v76;
        *(__m128i *)&v115.m_hitCollisionObject = _mm_load_si128(&v94);
        v95.m128i_i64[0] = __PAIR64__(v87, v74);
        v115.m_hitNormalLocal = (btVector3)_mm_load_si128(&v95);
        v96.m128i_i64[0] = __PAIR64__(LODWORD(v92), v71);
        v96.m128i_i64[1] = (unsigned int)policy_12[0].m_input_params;
        v115.m_hitPointLocal = (btVector3)_mm_load_si128(&v96);
        *(__m128i *)&v115.m_hitFraction = _mm_load_si128((const __m128i *)&vol);
        getAabb(castShape, (const btTransform *)&v115, (btVector3 *)&v107, &aabbMin);
        v77 = (__m128)_mm_load_si128(&v106);
        v78 = raySource_12.mVec128.m128_f32[0];
        rayTarget_12.mVec128 = v77;
        if ( *(float *)v106.m128i_i32 > raySource_12.mVec128.m128_f32[0] )
          rayTarget_12.mVec128.m128_i32[0] = raySource_12.mVec128.m128_i32[0];
        v79 = raySource_12.mVec128.m128_f32[1];
        if ( rayTarget_12.mVec128.m128_f32[1] > raySource_12.mVec128.m128_f32[1] )
          rayTarget_12.mVec128.m128_i32[1] = raySource_12.mVec128.m128_i32[1];
        v80 = rayTarget_12.mVec128.m128_f32[2];
        v81 = raySource_12.mVec128.m128_f32[2];
        if ( rayTarget_12.mVec128.m128_f32[2] > raySource_12.mVec128.m128_f32[2] )
          v80 = raySource_12.mVec128.m128_f32[2];
        if ( rayTarget_12.mVec128.m128_f32[3] > 0.0 )
          rayTarget_12.mVec128.m128_i32[3] = 0;
        raySource_12.mVec128 = v77;
        if ( v78 <= *(float *)v106.m128i_i32 )
          v78 = raySource_12.mVec128.m128_f32[0];
        v82 = raySource_12.mVec128.m128_f32[1];
        if ( v79 > raySource_12.mVec128.m128_f32[1] )
          v82 = v79;
        v83 = raySource_12.mVec128.m128_f32[2];
        if ( v81 > raySource_12.mVec128.m128_f32[2] )
          v83 = v81;
        if ( raySource_12.mVec128.m128_f32[3] < 0.0 )
          raySource_12.mVec128.m128_i32[3] = 0;
        m_bvh = (const btDbvtNode **)collisionShape->m_bvh;
        rayTarget_12.mVec128.m128_f32[0] = *(float *)&v107.__vftable + rayTarget_12.mVec128.m128_f32[0];
        rayTarget_12.mVec128.m128_f32[1] = *(float *)&v107.m_simplexSolver + rayTarget_12.mVec128.m128_f32[1];
        rayTarget_12.mVec128.m128_f32[2] = *(float *)&v107.m_penetrationDepthSolver + v80;
        raySource_12.mVec128.m128_f32[1] = aabbMin.mVec128.m128_f32[1] + v82;
        v85 = (CProfileSample *)&v108;
        raySource_12.mVec128.m128_f32[0] = aabbMin.mVec128.m128_f32[0] + v78;
        raySource_12.mVec128.m128_f32[2] = aabbMin.mVec128.m128_f32[2] + v83;
        policy_12[0].m_input_params = (btCollisionWorld::objectQuerySingle::__l45::input_params *)&v108;
        policy_12[0].m_compoundShape = (const btCompoundShape *)collisionShape;
        if ( m_bvh )
        {
          btDbvtAabbMm::FromMM(&raySource_12, &rayTarget_12, &vol);
          v86 = *m_bvh;
          if ( v86 )
            ___collideTV_UVolumeTester__CP___objectQuerySingle_btCollisionWorld__SAXPBVbtConvexShape__ABVbtTransform__1PAVbtCollisionObject__PBVbtCollisionShape__1AAUConvexResultCallback_3_M_Z__btDbvt__QAEXPBUbtDbvtNode__ABUbtDbvtAabbMm__AAUVolumeTester__CP___objectQuerySingle_btCollisionWorld__SAXPBVbtConvexShape__ABVbtTransform__3PAVbtCollisionObject__PBVbtCollisionShape__3AAUConvexResultCallback_5_M_Z__Z(
              &vol,
              v86,
              policy_12);
        }
        CProfileSample::~CProfileSample(v85);
      }
    }
    else if ( m_shapeType == 21 )
    {
      CProfileSample::CProfileSample((CProfileSample *)&stru_9583E4, &v93);
      btTransform::inverse(colObjWorldTransform, (btTransform *)&v94);
      v15 = convexFromTrans->m_origin.mVec128.m128_f32[1];
      v16 = convexFromTrans->m_origin.mVec128.m128_f32[0];
      v17 = convexFromTrans->m_origin.mVec128.m128_f32[2];
      raySource_12.mVec128.m128_f32[0] = (float)((float)((float)(v16 * *(float *)v94.m128i_i32)
                                                       + (float)(v15 * *(float *)&v94.m128i_i32[1]))
                                               + (float)(v17 * *(float *)&v94.m128i_i32[2]))
                                       + v97;
      v18 = (float)((float)(v16 * *(float *)v95.m128i_i32) + (float)(v15 * *(float *)&v95.m128i_i32[1]))
          + (float)(v17 * *(float *)&v95.m128i_i32[2]);
      v19 = (float)(v16 * *(float *)v96.m128i_i32) + (float)(v15 * *(float *)&v96.m128i_i32[1]);
      v20 = convexToTrans->m_origin.mVec128.m128_f32[2];
      v21 = v19 + (float)(v17 * *(float *)&v96.m128i_i32[2]);
      v22 = convexToTrans->m_origin.mVec128.m128_f32[0];
      raySource_12.mVec128.m128_f32[1] = v18 + rayTarget;
      v23 = convexToTrans->m_origin.mVec128.m128_f32[1];
      rayTarget_12.mVec128.m128_f32[0] = (float)((float)((float)(v22 * *(float *)v94.m128i_i32)
                                                       + (float)(v23 * *(float *)&v94.m128i_i32[1]))
                                               + (float)(v20 * *(float *)&v94.m128i_i32[2]))
                                       + v97;
      raySource_12.mVec128.m128_f32[2] = v21 + rayTarget_4;
      rayTarget_12.mVec128.m128_f32[1] = (float)((float)((float)(v22 * *(float *)v95.m128i_i32)
                                                       + (float)(v23 * *(float *)&v95.m128i_i32[1]))
                                               + (float)(v20 * *(float *)&v95.m128i_i32[2]))
                                       + rayTarget;
      v24 = convexToTrans->m_basis.m_el[2].mVec128.m128_f32[2];
      raySource_12.mVec128.m128_i32[3] = 0;
      rayTarget_12.mVec128.m128_f32[2] = (float)((float)((float)(v22 * *(float *)v96.m128i_i32)
                                                       + (float)(v23 * *(float *)&v96.m128i_i32[1]))
                                               + (float)(v20 * *(float *)&v96.m128i_i32[2]))
                                       + rayTarget_4;
      rayTarget_12.mVec128.m128_i32[3] = 0;
      memset(&v106, 0, sizeof(v106));
      v25 = convexToTrans->m_basis.m_el[1].mVec128.m128_f32[2];
      v26 = convexToTrans->m_basis.m_el[0].mVec128.m128_f32[2];
      _X = convexToTrans->m_basis.m_el[1].mVec128.m128_f32[1];
      v90 = (float)((float)(v26 * *(float *)v96.m128i_i32) + (float)(v25 * *(float *)&v96.m128i_i32[1]))
          + (float)(v24 * *(float *)&v96.m128i_i32[2]);
      v92 = convexToTrans->m_basis.m_el[2].mVec128.m128_f32[1];
      v27 = convexToTrans->m_basis.m_el[0].mVec128.m128_f32[1];
      *(float *)&v103 = (float)((float)(v27 * *(float *)v96.m128i_i32) + (float)(_X * *(float *)&v96.m128i_i32[1]))
                      + (float)(v92 * *(float *)&v96.m128i_i32[2]);
      v87 = convexToTrans->m_basis.m_el[2].mVec128.m128_u32[0];
      v89 = convexToTrans->m_basis.m_el[1].mVec128.m128_f32[0];
      v28 = convexToTrans->m_basis.m_el[0].mVec128.m128_f32[0];
      *((float *)&v103 + 1) = (float)((float)(convexToTrans->m_basis.m_el[0].mVec128.m128_f32[0]
                                            * *(float *)v96.m128i_i32)
                                    + (float)(v89 * *(float *)&v96.m128i_i32[1]))
                            + (float)(*(float *)&v87 * *(float *)&v96.m128i_i32[2]);
      *((float *)&policy_4 + 1) = (float)((float)(v26 * *(float *)v95.m128i_i32)
                                        + (float)(v25 * *(float *)&v95.m128i_i32[1]))
                                + (float)(v24 * *(float *)&v95.m128i_i32[2]);
      *(float *)&policy_4 = (float)((float)(v27 * *(float *)v95.m128i_i32) + (float)(_X * *(float *)&v95.m128i_i32[1]))
                          + (float)(v92 * *(float *)&v95.m128i_i32[2]);
      v88 = (float)((float)(v28 * *(float *)v95.m128i_i32) + (float)(v89 * *(float *)&v95.m128i_i32[1]))
          + (float)(*(float *)&v87 * *(float *)&v95.m128i_i32[2]);
      *(float *)&v108.m128i_i32[2] = (float)((float)(v26 * *(float *)v94.m128i_i32)
                                           + (float)(v25 * *(float *)&v94.m128i_i32[1]))
                                   + (float)(v24 * *(float *)&v94.m128i_i32[2]);
      *(float *)v109.m128i_i32 = v88;
      *(__int64 *)((char *)v109.m128i_i64 + 4) = policy_4;
      v108.m128i_i32[3] = 0;
      v109.m128i_i32[3] = 0;
      v110.m128i_i32[0] = HIDWORD(v103);
      *(float *)v108.m128i_i32 = (float)((float)(v28 * *(float *)v94.m128i_i32)
                                       + (float)(v89 * *(float *)&v94.m128i_i32[1]))
                               + (float)(*(float *)&v87 * *(float *)&v94.m128i_i32[2]);
      *(float *)&v108.m128i_i32[1] = (float)((float)(v27 * *(float *)v94.m128i_i32)
                                           + (float)(_X * *(float *)&v94.m128i_i32[1]))
                                   + (float)(v92 * *(float *)&v94.m128i_i32[2]);
      vol.mi = (btVector3)_mm_load_si128(&v108);
      v29.mVec128 = (__m128)_mm_load_si128(&v109);
      v110.m128i_i32[1] = v103;
      vol.mx = (btVector3)v29.mVec128;
      v110.m128i_i64[1] = LODWORD(v90);
      v113 = _mm_load_si128(&v110);
      v114 = _mm_load_si128(&v106);
      btCollisionWorld::objectQuerySingle_::_22_::BridgeTriangleConvexcastCallback::BridgeTriangleConvexcastCallback(
        (btCollisionWorld::objectQuerySingle::__l22::BridgeTriangleConvexcastCallback *)&result,
        castShape,
        convexFromTrans,
        convexToTrans,
        resultCallback,
        collisionObject,
        collisionShape,
        colObjWorldTransform);
      v30 = castShape->getAabb;
      result.m_hitFraction = resultCallback->m_closestHitFraction;
      result.m_allowedPenetration = allowedPenetration;
      v30(castShape, (const btTransform *)&vol, &aabbMin, (btVector3 *)&v107);
      btBvhTriangleMeshShape::performConvexcast(
        &rayTarget_12,
        &aabbMin,
        (const btVector3 *)&v107,
        collisionShape,
        &result,
        &raySource_12);
      result.__vftable = (btCollisionWorld::objectQuerySingle::__l39::BridgeTriangleConvexcastCallback_vtbl *)&btTriangleCallback::`vftable';
      if ( CProfileNode::Return(v31) )
        CProfileManager::CurrentNode = CProfileManager::CurrentNode->Parent;
    }
    else if ( m_shapeType == 28 )
    {
      v107.m_convexA = castShape;
      result.m_triangleToWorld.m_basis.m_el[2].mVec128.m128_f32[2] = allowedPenetration;
      m_closestHitFraction = resultCallback->m_closestHitFraction;
      result.__vftable = (btCollisionWorld::objectQuerySingle::__l39::BridgeTriangleConvexcastCallback_vtbl *)&btConvexCast::CastResult::`vftable';
      result.m_triangleToWorld.m_basis.m_el[2].mVec128.m128_u64[0] = LODWORD(m_closestHitFraction);
      v107.__vftable = (btContinuousConvexCollision_vtbl *)&btContinuousConvexCollision::`vftable';
      v107.m_simplexSolver = 0;
      v107.m_penetrationDepthSolver = 0;
      v107.m_convexB1 = 0;
      v107.m_planeShape = (const btStaticPlaneShape *)collisionShape;
      if ( btContinuousConvexCollision::calcTimeOfImpact(
             &v107,
             convexFromTrans,
             convexToTrans,
             colObjWorldTransform,
             colObjWorldTransform,
             (btConvexCast::CastResult *)&result) )
      {
        v90 = (float)((float)(result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[1]
                            * result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[1])
                    + (float)(result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[2]
                            * result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[2]))
            + (float)(result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[0]
                    * result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[0]);
        if ( v90 > 0.000099999997
          && resultCallback->m_closestHitFraction > result.m_triangleToWorld.m_basis.m_el[2].mVec128.m128_f32[0] )
        {
          v33 = 1.0 / sqrtf(v90);
          result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[0] = result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[0]
                                                                       * v33;
          result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[1] = result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[1]
                                                                       * v33;
          result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[2] = v33
                                                                       * result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[2];
          btCollisionWorld::LocalConvexResult::LocalConvexResult(
            &result.m_triangleToWorld.m_basis.m_el[1],
            result.m_triangleToWorld.m_basis.m_el,
            &v115,
            collisionObject,
            0,
            result.m_triangleToWorld.m_basis.m_el[2].mVec128.m128_f32[0]);
          resultCallback->addSingleResult(resultCallback, &v115, 1);
        }
      }
    }
    else
    {
      btTransform::inverse(colObjWorldTransform, (btTransform *)&v94);
      v34 = convexFromTrans->m_origin.mVec128.m128_f32[1];
      v35 = convexFromTrans->m_origin.mVec128.m128_f32[2];
      v36 = convexFromTrans->m_origin.mVec128.m128_f32[0] * *(float *)v95.m128i_i32;
      v37 = convexFromTrans->m_origin.mVec128.m128_f32[0] * *(float *)v96.m128i_i32;
      raySource_12.mVec128.m128_f32[0] = (float)((float)((float)(convexFromTrans->m_origin.mVec128.m128_f32[0]
                                                               * *(float *)v94.m128i_i32)
                                                       + (float)(v34 * *(float *)&v94.m128i_i32[1]))
                                               + (float)(v35 * *(float *)&v94.m128i_i32[2]))
                                       + v97;
      raySource_12.mVec128.m128_f32[1] = (float)((float)(v36 + (float)(v34 * *(float *)&v95.m128i_i32[1]))
                                               + (float)(v35 * *(float *)&v95.m128i_i32[2]))
                                       + rayTarget;
      raySource_12.mVec128.m128_f32[2] = (float)((float)(v37 + (float)(v34 * *(float *)&v96.m128i_i32[1]))
                                               + (float)(v35 * *(float *)&v96.m128i_i32[2]))
                                       + rayTarget_4;
      v89 = convexToTrans->m_origin.mVec128.m128_f32[2];
      v87 = convexToTrans->m_origin.mVec128.m128_u32[1];
      v38 = convexToTrans->m_origin.mVec128.m128_f32[0];
      *(float *)v106.m128i_i32 = (float)((float)((float)(v38 * *(float *)v94.m128i_i32)
                                               + (float)(*(float *)&v87 * *(float *)&v94.m128i_i32[1]))
                                       + (float)(v89 * *(float *)&v94.m128i_i32[2]))
                               + v97;
      v90 = (float)(v38 * *(float *)v95.m128i_i32) + (float)(*(float *)&v87 * *(float *)&v95.m128i_i32[1]);
      *(float *)&v106.m128i_i32[1] = (float)(v90 + (float)(v89 * *(float *)&v95.m128i_i32[2])) + rayTarget;
      raySource_12.mVec128.m128_i32[3] = 0;
      *(float *)&v106.m128i_i32[2] = (float)((float)((float)(v38 * *(float *)v96.m128i_i32)
                                                   + (float)(*(float *)&v87 * *(float *)&v96.m128i_i32[1]))
                                           + (float)(v89 * *(float *)&v96.m128i_i32[2]))
                                   + rayTarget_4;
      memset(&vol, 0, 16);
      v92 = convexToTrans->m_basis.m_el[2].mVec128.m128_f32[2];
      v89 = convexToTrans->m_basis.m_el[1].mVec128.m128_f32[2];
      v39 = convexToTrans->m_basis.m_el[0].mVec128.m128_f32[2];
      v90 = (float)(v39 * *(float *)v96.m128i_i32) + (float)(v89 * *(float *)&v96.m128i_i32[1]);
      v40 = convexToTrans->m_basis.m_el[0].mVec128.m128_f32[1];
      v102 = v90 + (float)(v92 * *(float *)&v96.m128i_i32[2]);
      *(float *)&v87 = (float)(*(float *)v96.m128i_i32 * v40)
                     + (float)(*(float *)&v96.m128i_i32[1] * convexToTrans->m_basis.m_el[1].mVec128.m128_f32[1]);
      *(float *)&v41 = *(float *)&v87
                     + (float)(*(float *)&v96.m128i_i32[2] * convexToTrans->m_basis.m_el[2].mVec128.m128_f32[1]);
      v88 = convexToTrans->m_basis.m_el[0].mVec128.m128_f32[0];
      _X = *(float *)&v41;
      *(float *)&policy_4 = (float)((float)(*(float *)&v96.m128i_i32[1]
                                          * convexToTrans->m_basis.m_el[1].mVec128.m128_f32[0])
                                  + (float)(v88 * *(float *)v96.m128i_i32))
                          + (float)(*(float *)&v96.m128i_i32[2] * convexToTrans->m_basis.m_el[2].mVec128.m128_f32[0]);
      *((float *)&policy_4 + 1) = (float)((float)(v39 * *(float *)v95.m128i_i32)
                                        + (float)(v89 * *(float *)&v95.m128i_i32[1]))
                                + (float)(v92 * *(float *)&v95.m128i_i32[2]);
      *(float *)&v87 = (float)(*(float *)v95.m128i_i32 * convexToTrans->m_basis.m_el[0].mVec128.m128_f32[1])
                     + (float)(*(float *)&v95.m128i_i32[1] * convexToTrans->m_basis.m_el[1].mVec128.m128_f32[1]);
      *((float *)&v103 + 1) = *(float *)&v87
                            + (float)(*(float *)&v95.m128i_i32[2] * convexToTrans->m_basis.m_el[2].mVec128.m128_f32[1]);
      *(float *)&v103 = (float)((float)(*(float *)&v95.m128i_i32[1] * convexToTrans->m_basis.m_el[1].mVec128.m128_f32[0])
                              + (float)(*(float *)&v95.m128i_i32[2] * convexToTrans->m_basis.m_el[2].mVec128.m128_f32[0]))
                      + (float)(v88 * *(float *)v95.m128i_i32);
      v90 = (float)((float)(v39 * *(float *)v94.m128i_i32) + (float)(v89 * *(float *)&v94.m128i_i32[1]))
          + (float)(v92 * *(float *)&v94.m128i_i32[2]);
      v42 = (float)(*(float *)v94.m128i_i32 * convexToTrans->m_basis.m_el[0].mVec128.m128_f32[1])
          + (float)(*(float *)&v94.m128i_i32[1] * convexToTrans->m_basis.m_el[1].mVec128.m128_f32[1]);
      v43 = *(float *)&v94.m128i_i32[2] * convexToTrans->m_basis.m_el[2].mVec128.m128_f32[1];
      v44 = *(float *)&v94.m128i_i32[1] * convexToTrans->m_basis.m_el[1].mVec128.m128_f32[0];
      v45 = *(float *)&v94.m128i_i32[2] * convexToTrans->m_basis.m_el[2].mVec128.m128_f32[0];
      *(float *)&v108.m128i_i32[2] = v90;
      v109.m128i_i64[0] = v103;
      v109.m128i_i32[2] = SHIDWORD(policy_4);
      v110.m128i_i64[0] = __PAIR64__(v41, policy_4);
      v110.m128i_i64[1] = LODWORD(v102);
      *(float *)v108.m128i_i32 = (float)(v44 + v45) + (float)(v88 * *(float *)v94.m128i_i32);
      *(float *)&v108.m128i_i32[1] = v42 + v43;
      v108.m128i_i32[3] = 0;
      *(__m128i *)&v115.m_hitCollisionObject = _mm_load_si128(&v108);
      v109.m128i_i32[3] = 0;
      v115.m_hitNormalLocal = (btVector3)_mm_load_si128(&v109);
      v115.m_hitPointLocal = (btVector3)_mm_load_si128(&v110);
      *(__m128i *)&v115.m_hitFraction = _mm_load_si128((const __m128i *)&vol);
      btCollisionWorld::objectQuerySingle_::_39_::BridgeTriangleConvexcastCallback::BridgeTriangleConvexcastCallback(
        &result,
        castShape,
        convexFromTrans,
        convexToTrans,
        resultCallback,
        collisionObject,
        collisionShape,
        colObjWorldTransform);
      v46 = castShape->getAabb;
      result.m_hitFraction = resultCallback->m_closestHitFraction;
      result.m_allowedPenetration = allowedPenetration;
      v46(castShape, (const btTransform *)&v115, &aabbMin, (btVector3 *)&v107);
      si128 = (__m128)_mm_load_si128((const __m128i *)&raySource_12);
      *(__m128 *)&policy_12[0].m_input_params = si128;
      v48 = *(float *)v106.m128i_i32;
      if ( raySource_12.mVec128.m128_f32[0] > *(float *)v106.m128i_i32 )
        policy_12[0].m_input_params = (btCollisionWorld::objectQuerySingle::__l45::input_params *)v106.m128i_i32[0];
      if ( *(float *)&policy_12[0].m_compoundShape > *(float *)&v106.m128i_i32[1] )
        policy_12[0].m_compoundShape = (const btCompoundShape *)v106.m128i_i32[1];
      v49 = *(float *)&policy_12[1].m_input_params;
      if ( *(float *)&policy_12[1].m_input_params > *(float *)&v106.m128i_i32[2] )
        v49 = *(float *)&v106.m128i_i32[2];
      if ( *(float *)&policy_12[1].m_compoundShape > 0.0 )
        policy_12[1].m_compoundShape = 0;
      rayTarget_12.mVec128 = si128;
      if ( *(float *)v106.m128i_i32 <= raySource_12.mVec128.m128_f32[0] )
        v48 = rayTarget_12.mVec128.m128_f32[0];
      v50 = rayTarget_12.mVec128.m128_f32[1];
      if ( *(float *)&v106.m128i_i32[1] > rayTarget_12.mVec128.m128_f32[1] )
        v50 = *(float *)&v106.m128i_i32[1];
      v51 = rayTarget_12.mVec128.m128_f32[2];
      if ( *(float *)&v106.m128i_i32[2] > rayTarget_12.mVec128.m128_f32[2] )
        v51 = *(float *)&v106.m128i_i32[2];
      if ( rayTarget_12.mVec128.m128_f32[3] < 0.0 )
        rayTarget_12.mVec128.m128_i32[3] = 0;
      v52 = (btCollisionShape_vtbl *)collisionShape->__vftable;
      *(float *)&policy_12[0].m_input_params = aabbMin.mVec128.m128_f32[0] + *(float *)&policy_12[0].m_input_params;
      *(float *)&policy_12[0].m_compoundShape = aabbMin.mVec128.m128_f32[1] + *(float *)&policy_12[0].m_compoundShape;
      *(float *)&policy_12[1].m_input_params = aabbMin.mVec128.m128_f32[2] + v49;
      v53 = v52[1].~btCollisionShape;
      rayTarget_12.mVec128.m128_f32[1] = *(float *)&v107.m_simplexSolver + v50;
      rayTarget_12.mVec128.m128_f32[0] = *(float *)&v107.__vftable + v48;
      rayTarget_12.mVec128.m128_f32[2] = *(float *)&v107.m_penetrationDepthSolver + v51;
      ((void (__thiscall *)(btBvhTriangleMeshShape *, btCollisionWorld::objectQuerySingle::__l39::BridgeTriangleConvexcastCallback *, btCollisionWorld::objectQuerySingle::__l47::VolumeTester *, btVector3 *))v53)(
        collisionShape,
        &result,
        policy_12,
        &rayTarget_12);
    }
  }
  else
  {
    Sub_Node = CProfileManager::CurrentNode;
    if ( CProfileManager::CurrentNode->Name != "convexSweepConvex" )
    {
      Sub_Node = CProfileNode::Get_Sub_Node(v8);
      CProfileManager::CurrentNode = Sub_Node;
    }
    RecursionCounter = Sub_Node->RecursionCounter;
    ++Sub_Node->TotalCalls;
    Sub_Node->RecursionCounter = RecursionCounter + 1;
    if ( !RecursionCounter )
      Sub_Node->StartTime = btClock::getTimeMicroseconds(0);
    v119 &= 0xFFF0u;
    v107.m_simplexSolver = (btVoronoiSimplexSolver *)&v117;
    v107.m_penetrationDepthSolver = (btConvexPenetrationDepthSolver *)&v87;
    result.m_triangleToWorld.m_basis.m_el[2].mVec128.m128_f32[2] = allowedPenetration;
    v12 = resultCallback->m_closestHitFraction;
    v107.m_convexA = castShape;
    result.m_triangleToWorld.m_basis.m_el[2].mVec128.m128_u64[0] = LODWORD(v12);
    result.__vftable = (btCollisionWorld::objectQuerySingle::__l39::BridgeTriangleConvexcastCallback_vtbl *)&btConvexCast::CastResult::`vftable';
    v118 = FLOAT_0_000099999997;
    v87 = (unsigned int)&btGjkEpaPenetrationDepthSolver::`vftable';
    v107.__vftable = (btContinuousConvexCollision_vtbl *)&btContinuousConvexCollision::`vftable';
    v107.m_convexB1 = (const btConvexShape *)collisionShape;
    v107.m_planeShape = 0;
    if ( btContinuousConvexCollision::calcTimeOfImpact(
           &v107,
           convexFromTrans,
           convexToTrans,
           colObjWorldTransform,
           colObjWorldTransform,
           (btConvexCast::CastResult *)&result) )
    {
      _X = (float)((float)(result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[0]
                         * result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[0])
                 + (float)(result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[1]
                         * result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[1]))
         + (float)(result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[2]
                 * result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[2]);
      if ( _X > 0.000099999997
        && resultCallback->m_closestHitFraction > result.m_triangleToWorld.m_basis.m_el[2].mVec128.m128_f32[0] )
      {
        v14 = 1.0 / sqrtf(_X);
        result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[0] = result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[0]
                                                                     * v14;
        result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[1] = result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[1]
                                                                     * v14;
        result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[2] = v14
                                                                     * result.m_triangleToWorld.m_basis.m_el[0].mVec128.m128_f32[2];
        btCollisionWorld::LocalConvexResult::LocalConvexResult(
          &result.m_triangleToWorld.m_basis.m_el[1],
          result.m_triangleToWorld.m_basis.m_el,
          &v115,
          collisionObject,
          0,
          result.m_triangleToWorld.m_basis.m_el[2].mVec128.m128_f32[0]);
        resultCallback->addSingleResult(resultCallback, &v115, 1);
      }
    }
    v107.__vftable = (btContinuousConvexCollision_vtbl *)&btConvexCast::`vftable';
    v87 = (unsigned int)&btConvexPenetrationDepthSolver::`vftable';
    result.__vftable = (btCollisionWorld::objectQuerySingle::__l39::BridgeTriangleConvexcastCallback_vtbl *)&btConvexCast::CastResult::`vftable';
    if ( CProfileNode::Return(v13) )
      CProfileManager::CurrentNode = CProfileManager::CurrentNode->Parent;
  }
}
