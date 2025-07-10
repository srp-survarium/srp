void __usercall btCollisionWorld::rayTestSingle(
        const btTransform *rayFromTrans@<ecx>,
        const btTransform *colObjWorldTransform@<eax>,
        const btTransform *rayToTrans,
        btCollisionObject *collisionObject,
        btBvhTriangleMeshShape *collisionShape,
        btCollisionWorld::RayResultCallback *resultCallback)
{
  int m_shapeType; // eax
  float m_closestHitFraction; // xmm0_4
  float v10; // xmm2_4
  unsigned int v11; // xmm1_4
  long double v12; // st7
  float v13; // xmm0_4
  float (__thiscall *addSingleResult)(btCollisionWorld::RayResultCallback *, btCollisionWorld::LocalRayResult *, bool); // edx
  float v15; // xmm4_4
  float v16; // xmm5_4
  float v17; // xmm3_4
  unsigned int v18; // xmm7_4
  float v19; // xmm5_4
  float v20; // xmm7_4
  float v21; // xmm3_4
  float v22; // xmm2_4
  float v23; // xmm5_4
  float v24; // xmm4_4
  float v25; // xmm3_4
  float v26; // xmm7_4
  float v27; // xmm5_4
  float v28; // xmm4_4
  float v29; // xmm7_4
  float v30; // xmm1_4
  int v31; // xmm2_4
  __m128 v32; // xmm0
  const btDbvtNode **m_bvh; // eax
  float v34; // xmm0_4
  float v35; // xmm2_4
  float v36; // xmm1_4
  float v37; // xmm3_4
  float v38; // xmm6_4
  float v39; // xmm5_4
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm6_4
  float v43; // xmm2_4
  unsigned int v44; // xmm0_4
  float v45; // xmm2_4
  float v46; // xmm0_4
  float v47; // xmm3_4
  float v48; // xmm0_4
  float v49; // xmm5_4
  float v50; // xmm1_4
  float v51; // xmm3_4
  const btDbvtNode *v52; // edx
  float v53; // xmm5_4
  float v54; // xmm2_4
  int v55; // edi
  int i; // esi
  float v57; // [esp+3280h] [ebp-334h]
  float v58; // [esp+3280h] [ebp-334h]
  btVector3 rayTo; // [esp+3284h] [ebp-330h] BYREF
  btVector3 from; // [esp+3294h] [ebp-320h] BYREF
  btSubsimplexConvexCast si128; // [esp+32A4h] [ebp-310h] BYREF
  btVector3 to; // [esp+32B4h] [ebp-300h] BYREF
  __m128i v63; // [esp+32C4h] [ebp-2F0h]
  float m_fraction; // [esp+32D4h] [ebp-2E0h]
  btTransform v65; // [esp+32E4h] [ebp-2D0h] BYREF
  _DWORD v66[16]; // [esp+3324h] [ebp-290h] BYREF
  btConvexCast::CastResult result; // [esp+3364h] [ebp-250h] BYREF
  char v68; // [esp+3424h] [ebp-190h] BYREF
  float v69; // [esp+3564h] [ebp-50h]
  __int16 v70; // [esp+3584h] [ebp-30h]

  m_shapeType = collisionShape->m_shapeType;
  v66[2] = 0;
  v66[4] = clear_value;
  v66[5] = clear_value;
  v66[6] = clear_value;
  v66[7] = 0;
  v66[0] = &btSphereShape::`vftable';
  v66[1] = 8;
  v66[8] = 0;
  v66[12] = 0;
  if ( m_shapeType >= 20 )
  {
    if ( (unsigned int)(m_shapeType - 21) > 8 )
    {
      if ( m_shapeType == 31 )
      {
        m_bvh = (const btDbvtNode **)collisionShape->m_bvh;
        to.mVec128.m128_u64[0] = __PAIR64__((unsigned int)collisionShape, (unsigned int)collisionObject);
        to.mVec128.m128_u64[1] = __PAIR64__((unsigned int)rayFromTrans, (unsigned int)colObjWorldTransform);
        v63.m128i_i64[0] = __PAIR64__((unsigned int)resultCallback, (unsigned int)rayToTrans);
        if ( m_bvh )
        {
          v34 = rayFromTrans->m_origin.mVec128.m128_f32[2] - colObjWorldTransform->m_origin.mVec128.m128_f32[2];
          v35 = rayFromTrans->m_origin.mVec128.m128_f32[1] - colObjWorldTransform->m_origin.mVec128.m128_f32[1];
          v36 = rayFromTrans->m_origin.mVec128.m128_f32[0] - colObjWorldTransform->m_origin.mVec128.m128_f32[0];
          v37 = colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[0];
          v38 = colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[1];
          rayTo.mVec128.m128_f32[0] = (float)((float)(v34 * colObjWorldTransform->m_basis.m_el[2].mVec128.m128_f32[0])
                                            + (float)(v35 * colObjWorldTransform->m_basis.m_el[1].mVec128.m128_f32[0]))
                                    + (float)(v36 * colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[0]);
          v39 = (float)(v34 * colObjWorldTransform->m_basis.m_el[2].mVec128.m128_f32[1]) + (float)(v38 * v36);
          v40 = (float)(v34 * colObjWorldTransform->m_basis.m_el[2].mVec128.m128_f32[2])
              + (float)(v36 * colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[2]);
          v41 = rayToTrans->m_origin.mVec128.m128_f32[0] - colObjWorldTransform->m_origin.mVec128.m128_f32[0];
          v42 = v35 * colObjWorldTransform->m_basis.m_el[1].mVec128.m128_f32[1];
          v43 = v35 * colObjWorldTransform->m_basis.m_el[1].mVec128.m128_f32[2];
          rayTo.mVec128.m128_f32[1] = v39 + v42;
          *(float *)&v44 = v40 + v43;
          v45 = rayToTrans->m_origin.mVec128.m128_f32[1] - colObjWorldTransform->m_origin.mVec128.m128_f32[1];
          rayTo.mVec128.m128_u64[1] = v44;
          si128 = (btSubsimplexConvexCast)_mm_load_si128((const __m128i *)&rayTo);
          v46 = rayToTrans->m_origin.mVec128.m128_f32[2] - colObjWorldTransform->m_origin.mVec128.m128_f32[2];
          rayTo.mVec128.m128_f32[0] = (float)((float)(v45 * colObjWorldTransform->m_basis.m_el[1].mVec128.m128_f32[0])
                                            + (float)(v46 * colObjWorldTransform->m_basis.m_el[2].mVec128.m128_f32[0]))
                                    + (float)(v41 * v37);
          v47 = v46 * colObjWorldTransform->m_basis.m_el[2].mVec128.m128_f32[1];
          v48 = v46 * colObjWorldTransform->m_basis.m_el[2].mVec128.m128_f32[2];
          v49 = v41 * colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[1];
          v50 = v41 * colObjWorldTransform->m_basis.m_el[0].mVec128.m128_f32[2];
          v51 = v47 + v49;
          v52 = *m_bvh;
          v53 = v45 * colObjWorldTransform->m_basis.m_el[1].mVec128.m128_f32[1];
          v54 = v45 * colObjWorldTransform->m_basis.m_el[1].mVec128.m128_f32[2];
          rayTo.mVec128.m128_f32[1] = v51 + v53;
          rayTo.mVec128.m128_f32[2] = (float)(v48 + v50) + v54;
          rayTo.mVec128.m128_i32[3] = 0;
          rayTo.mVec128 = (__m128)_mm_load_si128((const __m128i *)&rayTo);
          ___rayTest_URayTester__CA___rayTestSingle_btCollisionWorld__SAXABVbtTransform__0PAVbtCollisionObject__PBVbtCollisionShape__0AAURayResultCallback_3__Z__btDbvt__SAXPBUbtDbvtNode__ABVbtVector3__1AAURayTester__CA___rayTestSingle_btCollisionWorld__SAXABVbtTransform__2PAVbtCollisionObject__PBVbtCollisionShape__2AAURayResultCallback_5__Z__Z(
            v52,
            (const btVector3 *)&si128,
            &rayTo,
            (btCollisionWorld::rayTestSingle::__l32::RayTester *)&to);
        }
        else
        {
          v55 = collisionShape->m_localAabbMin.mVec128.m128_i32[0];
          for ( i = 0; i < v55; ++i )
            btCollisionWorld::rayTestSingle_::_32_::RayTester::Process(
              (btCollisionWorld::rayTestSingle::__l32::RayTester *)&to,
              i);
        }
      }
    }
    else if ( m_shapeType == 21 )
    {
      btTransform::inverse(colObjWorldTransform, &v65);
      v15 = rayFromTrans->m_origin.mVec128.m128_f32[1];
      v16 = rayFromTrans->m_origin.mVec128.m128_f32[0];
      v17 = rayFromTrans->m_origin.mVec128.m128_f32[2];
      from.mVec128.m128_f32[0] = (float)((float)((float)(v65.m_basis.m_el[0].mVec128.m128_f32[0] * v16)
                                               + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[1] * v15))
                                       + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[2] * v17))
                               + v65.m_origin.mVec128.m128_f32[0];
      from.mVec128.m128_f32[1] = (float)((float)((float)(v65.m_basis.m_el[1].mVec128.m128_f32[0] * v16)
                                               + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[1] * v15))
                                       + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[2] * v17))
                               + v65.m_origin.mVec128.m128_f32[1];
      *(float *)&v18 = (float)((float)((float)(v65.m_basis.m_el[2].mVec128.m128_f32[0] * v16)
                                     + (float)(v65.m_basis.m_el[2].mVec128.m128_f32[1] * v15))
                             + (float)(v65.m_basis.m_el[2].mVec128.m128_f32[2] * v17))
                     + v65.m_origin.mVec128.m128_f32[2];
      v19 = rayToTrans->m_origin.mVec128.m128_f32[1];
      from.mVec128.m128_u64[1] = v18;
      v20 = rayToTrans->m_origin.mVec128.m128_f32[0];
      v21 = rayToTrans->m_origin.mVec128.m128_f32[2];
      to.mVec128.m128_f32[0] = (float)((float)((float)(v65.m_basis.m_el[0].mVec128.m128_f32[0] * v20)
                                             + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[1] * v19))
                                     + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[2] * v21))
                             + v65.m_origin.mVec128.m128_f32[0];
      to.mVec128.m128_f32[1] = (float)((float)((float)(v65.m_basis.m_el[1].mVec128.m128_f32[0] * v20)
                                             + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[1] * v19))
                                     + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[2] * v21))
                             + v65.m_origin.mVec128.m128_f32[1];
      to.mVec128.m128_f32[2] = (float)((float)((float)(v65.m_basis.m_el[2].mVec128.m128_f32[0] * v20)
                                             + (float)(v65.m_basis.m_el[2].mVec128.m128_f32[1] * v19))
                                     + (float)(v65.m_basis.m_el[2].mVec128.m128_f32[2] * v21))
                             + v65.m_origin.mVec128.m128_f32[2];
      to.mVec128.m128_i32[3] = 0;
      btCollisionWorld::rayTestSingle_::_22_::BridgeTriangleRaycastCallback::BridgeTriangleRaycastCallback(
        &from,
        &to,
        resultCallback,
        colObjWorldTransform,
        (btCollisionWorld::rayTestSingle::__l22::BridgeTriangleRaycastCallback *)&result,
        collisionObject,
        collisionShape);
      result.m_hitTransformA.m_basis.m_el[2].mVec128.m128_i32[1] = LODWORD(resultCallback->m_closestHitFraction);
      btBvhTriangleMeshShape::performRaycast(collisionShape, (btTriangleCallback *)&result, &from, &to);
    }
    else
    {
      btTransform::inverse(colObjWorldTransform, &v65);
      v22 = rayFromTrans->m_origin.mVec128.m128_f32[1];
      v23 = rayFromTrans->m_origin.mVec128.m128_f32[0];
      v24 = rayFromTrans->m_origin.mVec128.m128_f32[2];
      v25 = (float)((float)((float)(v65.m_basis.m_el[0].mVec128.m128_f32[0] * v23)
                          + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[1] * v22))
                  + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[2] * v24))
          + v65.m_origin.mVec128.m128_f32[0];
      *(float *)&si128.m_simplexSolver = (float)((float)((float)(v65.m_basis.m_el[1].mVec128.m128_f32[0] * v23)
                                                       + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[1] * v22))
                                               + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[2] * v24))
                                       + v65.m_origin.mVec128.m128_f32[1];
      v26 = (float)((float)((float)(v65.m_basis.m_el[2].mVec128.m128_f32[0] * v23)
                          + (float)(v65.m_basis.m_el[2].mVec128.m128_f32[1] * v22))
                  + (float)(v65.m_basis.m_el[2].mVec128.m128_f32[2] * v24))
          + v65.m_origin.mVec128.m128_f32[2];
      v27 = rayToTrans->m_origin.mVec128.m128_f32[1];
      *(float *)&si128.m_convexA = v26;
      v58 = rayToTrans->m_origin.mVec128.m128_f32[0];
      si128.m_convexB = 0;
      v28 = rayToTrans->m_origin.mVec128.m128_f32[2];
      v29 = (float)((float)((float)(v65.m_basis.m_el[0].mVec128.m128_f32[0] * v58)
                          + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[1] * v27))
                  + (float)(v65.m_basis.m_el[0].mVec128.m128_f32[2] * v28))
          + v65.m_origin.mVec128.m128_f32[0];
      v30 = (float)((float)((float)(v65.m_basis.m_el[1].mVec128.m128_f32[0] * v58)
                          + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[1] * v27))
                  + (float)(v65.m_basis.m_el[1].mVec128.m128_f32[2] * v28))
          + v65.m_origin.mVec128.m128_f32[1];
      *(float *)&v31 = (float)((float)((float)(v65.m_basis.m_el[2].mVec128.m128_f32[2] * v28)
                                     + (float)(v65.m_basis.m_el[2].mVec128.m128_f32[0] * v58))
                             + (float)(v65.m_basis.m_el[2].mVec128.m128_f32[1] * v27))
                     + v65.m_origin.mVec128.m128_f32[2];
      *(float *)&si128.__vftable = v25;
      rayTo.mVec128.m128_f32[0] = v29;
      rayTo.mVec128.m128_f32[1] = v30;
      rayTo.mVec128.m128_u64[1] = (unsigned int)v31;
      btCollisionWorld::rayTestSingle_::_25_::BridgeTriangleRaycastCallback::BridgeTriangleRaycastCallback(
        (const btVector3 *)&si128,
        &rayTo,
        resultCallback,
        colObjWorldTransform,
        (btCollisionWorld::rayTestSingle::__l25::BridgeTriangleRaycastCallback *)&result,
        collisionObject,
        collisionShape);
      result.m_hitTransformA.m_basis.m_el[2].mVec128.m128_i32[1] = LODWORD(resultCallback->m_closestHitFraction);
      v32 = (__m128)_mm_load_si128((const __m128i *)&si128);
      to.mVec128 = v32;
      if ( v25 > v29 )
        to.mVec128.m128_f32[0] = v29;
      if ( to.mVec128.m128_f32[1] > v30 )
        to.mVec128.m128_f32[1] = v30;
      if ( to.mVec128.m128_f32[2] > *(float *)&v31 )
        to.mVec128.m128_i32[2] = v31;
      if ( to.mVec128.m128_f32[3] > 0.0 )
        to.mVec128.m128_i32[3] = 0;
      from.mVec128 = v32;
      if ( v29 > v25 )
        from.mVec128.m128_f32[0] = v29;
      if ( v30 > from.mVec128.m128_f32[1] )
        from.mVec128.m128_f32[1] = v30;
      if ( *(float *)&v31 > from.mVec128.m128_f32[2] )
        from.mVec128.m128_i32[2] = v31;
      if ( from.mVec128.m128_f32[3] < 0.0 )
        from.mVec128.m128_i32[3] = 0;
      collisionShape->processAllTriangles(collisionShape, (btTriangleCallback *)&result, &to, &from);
    }
  }
  else
  {
    m_closestHitFraction = resultCallback->m_closestHitFraction;
    result.m_debugDrawer = 0;
    v70 &= 0xFFF0u;
    si128.m_simplexSolver = (btVoronoiSimplexSolver *)&v68;
    result.m_fraction = m_closestHitFraction;
    si128.m_convexB = (const btConvexShape *)collisionShape;
    result.__vftable = (btConvexCast::CastResult_vtbl *)&btConvexCast::CastResult::`vftable';
    result.m_allowedPenetration = 0.0;
    v69 = FLOAT_0_000099999997;
    si128.__vftable = (btSubsimplexConvexCast_vtbl *)&btSubsimplexConvexCast::`vftable';
    si128.m_convexA = (const btConvexShape *)v66;
    if ( btSubsimplexConvexCast::calcTimeOfImpact(
           &si128,
           rayFromTrans,
           rayToTrans,
           colObjWorldTransform,
           colObjWorldTransform,
           &result)
      && (float)((float)((float)(result.m_normal.mVec128.m128_f32[2] * result.m_normal.mVec128.m128_f32[2])
                       + (float)(result.m_normal.mVec128.m128_f32[1] * result.m_normal.mVec128.m128_f32[1]))
               + (float)(result.m_normal.mVec128.m128_f32[0] * result.m_normal.mVec128.m128_f32[0])) > 0.000099999997
      && resultCallback->m_closestHitFraction > result.m_fraction )
    {
      v10 = (float)((float)(rayFromTrans->m_basis.m_el[0].mVec128.m128_f32[1] * result.m_normal.mVec128.m128_f32[1])
                  + (float)(rayFromTrans->m_basis.m_el[0].mVec128.m128_f32[2] * result.m_normal.mVec128.m128_f32[2]))
          + (float)(rayFromTrans->m_basis.m_el[0].mVec128.m128_f32[0] * result.m_normal.mVec128.m128_f32[0]);
      *(float *)&v11 = (float)((float)(rayFromTrans->m_basis.m_el[2].mVec128.m128_f32[1]
                                     * result.m_normal.mVec128.m128_f32[1])
                             + (float)(rayFromTrans->m_basis.m_el[2].mVec128.m128_f32[2]
                                     * result.m_normal.mVec128.m128_f32[2]))
                     + (float)(rayFromTrans->m_basis.m_el[2].mVec128.m128_f32[0] * result.m_normal.mVec128.m128_f32[0]);
      to.mVec128.m128_f32[1] = (float)((float)(rayFromTrans->m_basis.m_el[1].mVec128.m128_f32[1]
                                             * result.m_normal.mVec128.m128_f32[1])
                                     + (float)(rayFromTrans->m_basis.m_el[1].mVec128.m128_f32[2]
                                             * result.m_normal.mVec128.m128_f32[2]))
                             + (float)(rayFromTrans->m_basis.m_el[1].mVec128.m128_f32[0]
                                     * result.m_normal.mVec128.m128_f32[0]);
      to.mVec128.m128_u64[1] = v11;
      to.mVec128.m128_f32[0] = v10;
      result.m_normal = (btVector3)_mm_load_si128((const __m128i *)&to);
      v12 = 1.0
          / sqrtf(
              (float)((float)(*(float *)&v11 * *(float *)&v11) + (float)(to.mVec128.m128_f32[1] * to.mVec128.m128_f32[1]))
            + (float)(v10 * v10));
      v13 = to.mVec128.m128_f32[0];
      addSingleResult = resultCallback->addSingleResult;
      to.mVec128.m128_u64[0] = (unsigned int)collisionObject;
      v57 = v12;
      result.m_normal.mVec128.m128_f32[0] = v13 * v57;
      result.m_normal.mVec128.m128_f32[1] = result.m_normal.mVec128.m128_f32[1] * v12;
      result.m_normal.mVec128.m128_f32[2] = v12 * result.m_normal.mVec128.m128_f32[2];
      v63 = _mm_load_si128((const __m128i *)&result.m_normal);
      m_fraction = result.m_fraction;
      addSingleResult(resultCallback, (btCollisionWorld::LocalRayResult *)&to, 1);
    }
  }
}
