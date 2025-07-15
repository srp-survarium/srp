void __thiscall btSoftBodyTriangleCallback::processTriangle(
        btSoftBodyTriangleCallback *this,
        btVector3 *triangle,
        int partId,
        int triangleIndex)
{
  btCollisionObject *m_triBody; // esi
  const btDispatcherInfo *m_dispatchInfoPtr; // eax
  float v7; // xmm2_4
  float v8; // xmm5_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm6_4
  float v15; // xmm2_4
  float v16; // xmm7_4
  float v17; // xmm6_4
  float v18; // xmm7_4
  float v19; // xmm6_4
  float v20; // xmm5_4
  float v21; // xmm7_4
  float v22; // xmm6_4
  float v23; // xmm7_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm3_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm2_4
  float v30; // xmm5_4
  float v31; // xmm4_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm2_4
  float v35; // xmm3_4
  float v36; // xmm6_4
  float v37; // xmm7_4
  float v38; // xmm6_4
  float v39; // xmm1_4
  float v40; // xmm7_4
  float v41; // xmm6_4
  float v42; // xmm7_4
  float v43; // xmm5_4
  float v44; // xmm2_4
  float v45; // xmm7_4
  float v46; // xmm5_4
  float v47; // xmm7_4
  float v48; // xmm0_4
  float v49; // xmm4_4
  float v50; // xmm0_4
  float v51; // xmm3_4
  float v52; // xmm0_4
  float v53; // xmm3_4
  float v54; // xmm2_4
  float v55; // xmm0_4
  float v56; // xmm3_4
  float v57; // xmm0_4
  float v58; // xmm3_4
  float v59; // xmm6_4
  float v60; // xmm1_4
  float v61; // xmm0_4
  float v62; // xmm4_4
  float v63; // xmm2_4
  float v64; // xmm5_4
  float v65; // xmm7_4
  float v66; // xmm6_4
  float v67; // xmm1_4
  float v68; // xmm7_4
  float v69; // xmm6_4
  float v70; // xmm7_4
  float v71; // xmm6_4
  float v72; // xmm4_4
  float v73; // xmm7_4
  float v74; // xmm6_4
  float v75; // xmm7_4
  float v76; // xmm0_4
  float v77; // xmm3_4
  float v78; // xmm0_4
  float v79; // xmm2_4
  float v80; // xmm2_4
  float v81; // xmm3_4
  const btDispatcherInfo *v82; // eax
  int Index; // eax
  btTriIndex *v84; // eax
  btCollisionShape *m_childShape; // eax
  btCollisionShape *v86; // ecx
  int v87; // edi
  float v88; // xmm5_4
  float v89; // xmm4_4
  float v90; // xmm7_4
  float v91; // xmm6_4
  float v92; // xmm2_4
  float v93; // xmm0_4
  float v94; // xmm3_4
  float v95; // xmm1_4
  float v96; // xmm4_4
  float v97; // xmm6_4
  float v98; // xmm0_4
  float v99; // xmm1_4
  float v100; // xmm3_4
  float v101; // xmm4_4
  float v102; // xmm2_4
  float v103; // xmm3_4
  float v104; // xmm1_4
  float v105; // xmm6_4
  float v106; // xmm2_4
  int v107; // xmm7_4
  float v108; // xmm7_4
  float v109; // xmm7_4
  int v110; // xmm1_4
  btConvexHullShape *v111; // eax
  btConvexHullShape *v112; // eax
  btCollisionShape *m_collisionShape; // ecx
  int v114; // edi
  btHashMap<btHashKey<btTriIndex>,btTriIndex> *v115; // ecx
  btCollisionObject *v116; // [esp+34h] [ebp-D8h]
  int v117; // [esp+3Ch] [ebp-D0h]
  float v118; // [esp+48h] [ebp-C4h]
  btCollisionShape *v119; // [esp+48h] [ebp-C4h]
  float v120; // [esp+4Ch] [ebp-C0h] BYREF
  float v121; // [esp+50h] [ebp-BCh]
  float v122; // [esp+54h] [ebp-B8h]
  int v123; // [esp+58h] [ebp-B4h]
  btCollisionShape *v124; // [esp+68h] [ebp-A4h]
  float v125; // [esp+6Ch] [ebp-A0h] BYREF
  float v126; // [esp+70h] [ebp-9Ch]
  float v127; // [esp+74h] [ebp-98h]
  int v128; // [esp+78h] [ebp-94h]
  btHashKey<btTriIndex> key; // [esp+88h] [ebp-84h] BYREF
  btTriIndex value; // [esp+8Ch] [ebp-80h] BYREF
  int v131; // [esp+94h] [ebp-78h]
  int v132; // [esp+98h] [ebp-74h]
  btDispatcher *m_dispatcher; // [esp+A0h] [ebp-6Ch]
  btCollisionShape *v134; // [esp+A8h] [ebp-64h]
  int numPoints[24]; // [esp+ACh] [ebp-60h] BYREF

  m_triBody = this->m_triBody;
  m_dispatcher = this->m_dispatcher;
  m_dispatchInfoPtr = this->m_dispatchInfoPtr;
  if ( m_dispatchInfoPtr
    && m_dispatchInfoPtr->m_debugDraw
    && (m_dispatchInfoPtr->m_debugDraw->getDebugMode(m_dispatchInfoPtr->m_debugDraw) & 1) != 0 )
  {
    v7 = triangle[1].mVec128.m128_f32[0];
    v8 = triangle[1].mVec128.m128_f32[2];
    v9 = m_triBody->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1];
    v10 = m_triBody->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0];
    v11 = m_triBody->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2];
    v12 = triangle[1].mVec128.m128_f32[1];
    v125 = (float)((float)((float)(v7 * v10) + (float)(v12 * v9)) + (float)(v8 * v11))
         + m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[0];
    v13 = (float)(m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v12)
        + (float)(m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v8);
    v14 = v7 * m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0];
    v15 = v7 * m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
    v16 = (float)(v13 + v14) + m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[1];
    v17 = triangle[1].mVec128.m128_f32[1];
    v126 = v16;
    v18 = m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v17;
    v19 = m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v8;
    v20 = triangle->mVec128.m128_f32[1];
    v21 = v18 + v19;
    v22 = triangle->mVec128.m128_f32[0];
    v118 = v21 + v15;
    v23 = m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[2];
    v127 = v118 + v23;
    v24 = triangle->mVec128.m128_f32[2];
    v25 = (float)((float)((float)(v10 * v22) + (float)(v9 * v20)) + (float)(v11 * v24))
        + m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[0];
    v26 = m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1];
    v120 = v25;
    v27 = m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1];
    v121 = (float)((float)((float)(v26 * v20)
                         + (float)(m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v24))
                 + (float)(m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v22))
         + m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[1];
    v28 = m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v24;
    v29 = m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0] * v22;
    *(float *)&value.m_PartIdTriangleIndex = s_bm_current_air_resistance;
    *(float *)&value.m_childShape = s_bm_current_air_resistance;
    v131 = 0;
    v132 = 0;
    v128 = 0;
    v122 = (float)((float)((float)(v27 * v20) + v28) + v29) + v23;
    v123 = 0;
    this->m_dispatchInfoPtr->m_debugDraw->drawLine(
      this->m_dispatchInfoPtr->m_debugDraw,
      (const btVector3 *)&v120,
      (const btVector3 *)&v125,
      (const btVector3 *)&value);
    v30 = triangle[2].mVec128.m128_f32[1];
    v31 = m_triBody->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1];
    v32 = triangle[2].mVec128.m128_f32[0];
    v33 = m_triBody->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0];
    v34 = triangle[2].mVec128.m128_f32[2];
    v35 = m_triBody->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2];
    v36 = m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2];
    v120 = (float)((float)((float)(v33 * v32) + (float)(v31 * v30)) + (float)(v35 * v34))
         + m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[0];
    v37 = (float)(m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v30) + (float)(v36 * v34);
    v38 = m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v32;
    v39 = v32 * m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
    v40 = v37 + v38;
    v41 = m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[1];
    v121 = v40 + v41;
    v42 = m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v30;
    v43 = m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v34;
    v44 = triangle[1].mVec128.m128_f32[0];
    v45 = v42 + v43;
    v46 = m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[2];
    v122 = (float)(v45 + v39) + v46;
    v47 = triangle[1].mVec128.m128_f32[1];
    v48 = (float)(v33 * v44) + (float)(v31 * v47);
    v49 = triangle[1].mVec128.m128_f32[2];
    v50 = (float)(v48 + (float)(v35 * v49)) + m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[0];
    v51 = m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2];
    v125 = v50;
    v52 = (float)(m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v47) + (float)(v51 * v49);
    v53 = v44 * m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0];
    v54 = v44 * m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
    v55 = v52 + v53;
    v56 = m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2];
    v126 = v55 + v41;
    v57 = (float)((float)((float)(m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v47)
                        + (float)(v56 * v49))
                + v54)
        + v46;
    v123 = 0;
    v127 = v57;
    v128 = 0;
    this->m_dispatchInfoPtr->m_debugDraw->drawLine(
      this->m_dispatchInfoPtr->m_debugDraw,
      (const btVector3 *)&v125,
      (const btVector3 *)&v120,
      (const btVector3 *)&value);
    v58 = m_triBody->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1];
    v59 = triangle->mVec128.m128_f32[1];
    v60 = triangle->mVec128.m128_f32[0];
    v61 = m_triBody->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0];
    v62 = triangle->mVec128.m128_f32[2];
    v63 = m_triBody->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2];
    v64 = m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[0];
    v120 = (float)((float)((float)(v61 * triangle->mVec128.m128_f32[0]) + (float)(v58 * v59)) + (float)(v63 * v62))
         + v64;
    v65 = (float)(m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v59)
        + (float)(m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v62);
    v66 = m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v60;
    v67 = v60 * m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
    v68 = (float)(v65 + v66) + m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[1];
    v69 = triangle->mVec128.m128_f32[1];
    v121 = v68;
    v70 = m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v69;
    v71 = m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v62;
    v72 = m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[2];
    v73 = v70 + v71;
    v74 = triangle[2].mVec128.m128_f32[2];
    v122 = (float)(v73 + v67) + v72;
    v75 = triangle[2].mVec128.m128_f32[1];
    v76 = (float)(v61 * triangle[2].mVec128.m128_f32[0]) + (float)(v58 * v75);
    v77 = m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v75;
    v125 = (float)(v76 + (float)(v63 * v74)) + v64;
    v78 = triangle[2].mVec128.m128_f32[0];
    v79 = m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1];
    v126 = (float)((float)(v77 + (float)(m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v74))
                 + (float)(v78 * m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0]))
         + m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[1];
    v80 = (float)(v79 * v75) + (float)(m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v74);
    v81 = m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0] * v78;
    v123 = 0;
    v82 = this->m_dispatchInfoPtr;
    v127 = (float)(v80 + v81) + v72;
    v128 = 0;
    v82->m_debugDraw->drawLine(
      v82->m_debugDraw,
      (const btVector3 *)&v125,
      (const btVector3 *)&v120,
      (const btVector3 *)&value);
  }
  value.m_childShape = 0;
  value.m_PartIdTriangleIndex = triangleIndex | (partId << 21);
  key.m_uid = value.m_PartIdTriangleIndex;
  Index = btHashMap<btHashKey<btTriIndex>,btTriIndex>::findIndex(&this->m_shapeCache, &key);
  if ( Index == -1 || (v84 = &this->m_shapeCache.m_valueArray.m_data[Index]) == 0 )
  {
    v88 = triangle->mVec128.m128_f32[0];
    v89 = triangle->mVec128.m128_f32[1];
    v90 = triangle->mVec128.m128_f32[2];
    v91 = triangle[2].mVec128.m128_f32[0];
    v92 = triangle[2].mVec128.m128_f32[2] - v90;
    v93 = triangle[2].mVec128.m128_f32[1] - v89;
    v94 = triangle[1].mVec128.m128_f32[1] - v89;
    v120 = triangle[1].mVec128.m128_f32[0] - triangle->mVec128.m128_f32[0];
    v95 = triangle[1].mVec128.m128_f32[2] - v90;
    v96 = (float)(v94 * v92) - (float)(v95 * v93);
    v97 = v91 - v88;
    v98 = (float)(v93 * v120) - (float)(v94 * v97);
    v99 = (float)(v95 * v97) - (float)(v92 * v120);
    v100 = fsqrt((float)((float)(v98 * v98) + (float)(v99 * v99)) + (float)(v96 * v96));
    v101 = (float)(v96 * (float)(s_bm_current_air_resistance / v100)) * 0.059999999;
    *(float *)&numPoints[4] = triangle[1].mVec128.m128_f32[0] + v101;
    v102 = (float)(v98 * (float)(s_bm_current_air_resistance / v100)) * 0.059999999;
    v103 = (float)(v99 * (float)(s_bm_current_air_resistance / v100)) * 0.059999999;
    v104 = triangle->mVec128.m128_f32[1];
    *(float *)&numPoints[5] = triangle[1].mVec128.m128_f32[1] + v103;
    v105 = v102;
    v106 = triangle->mVec128.m128_f32[2];
    *(float *)&numPoints[6] = triangle[1].mVec128.m128_f32[2] + v105;
    *(float *)&v107 = triangle[2].mVec128.m128_f32[0] + v101;
    *(float *)numPoints = v101 + v88;
    numPoints[8] = v107;
    v108 = triangle[2].mVec128.m128_f32[1];
    *(float *)&numPoints[1] = v103 + v104;
    *(float *)&numPoints[9] = v108 + v103;
    v109 = triangle[2].mVec128.m128_f32[2];
    *(float *)&numPoints[2] = v105 + v106;
    numPoints[3] = 0;
    numPoints[7] = 0;
    *(float *)&numPoints[10] = v109 + v105;
    numPoints[11] = 0;
    *(float *)&numPoints[13] = v104 - v103;
    *(float *)&numPoints[16] = triangle[1].mVec128.m128_f32[0] - v101;
    *(float *)&numPoints[17] = triangle[1].mVec128.m128_f32[1] - v103;
    *(float *)&numPoints[18] = triangle[1].mVec128.m128_f32[2] - v105;
    *(float *)&numPoints[20] = triangle[2].mVec128.m128_f32[0] - v101;
    *(float *)&numPoints[21] = triangle[2].mVec128.m128_f32[1] - v103;
    *(float *)&v110 = triangle[2].mVec128.m128_f32[2] - v105;
    *(float *)&numPoints[12] = v88 - v101;
    *(float *)&numPoints[14] = v106 - v105;
    numPoints[15] = 0;
    numPoints[19] = 0;
    numPoints[22] = v110;
    numPoints[23] = 0;
    v111 = (btConvexHullShape *)btAlignedAllocInternal(0xA0u);
    if ( v111 )
    {
      v112 = btConvexHullShape::btConvexHullShape((btConvexHullShape *)numPoints, v111, (int)numPoints, v117);
      v124 = v112;
    }
    else
    {
      v124 = 0;
      v112 = 0;
    }
    v112->m_userPointer = m_triBody->m_rootCollisionShape->m_userPointer;
    m_collisionShape = m_triBody->m_collisionShape;
    m_triBody->m_collisionShape = v112;
    v116 = this->m_triBody;
    v134 = m_collisionShape;
    v114 = (int)m_dispatcher->findAlgorithm(m_dispatcher, this->m_softBody, v116, 0);
    (*(void (__thiscall **)(int, btSoftBody *, btCollisionObject *, const btDispatcherInfo *, btManifoldResult *))(*(_DWORD *)v114 + 4))(
      v114,
      this->m_softBody,
      this->m_triBody,
      this->m_dispatchInfoPtr,
      this->m_resultOut);
    (**(void (__thiscall ***)(int, _DWORD))v114)(v114, 0);
    m_dispatcher->freeCollisionAlgorithm(m_dispatcher, (void *)v114);
    m_triBody->m_collisionShape = v134;
    value.m_childShape = v124;
    btHashMap<btHashKey<btTriIndex>,btTriIndex>::insert(v115, &this->m_shapeCache, &key, &value);
  }
  else
  {
    m_childShape = v84->m_childShape;
    m_childShape->m_userPointer = m_triBody->m_rootCollisionShape->m_userPointer;
    v86 = m_triBody->m_collisionShape;
    m_triBody->m_collisionShape = m_childShape;
    v119 = v86;
    v87 = (int)m_dispatcher->findAlgorithm(m_dispatcher, this->m_softBody, this->m_triBody, 0);
    (*(void (__thiscall **)(int, btSoftBody *, btCollisionObject *, const btDispatcherInfo *, btManifoldResult *))(*(_DWORD *)v87 + 4))(
      v87,
      this->m_softBody,
      this->m_triBody,
      this->m_dispatchInfoPtr,
      this->m_resultOut);
    (**(void (__thiscall ***)(int, _DWORD))v87)(v87, 0);
    m_dispatcher->freeCollisionAlgorithm(m_dispatcher, (void *)v87);
    m_triBody->m_collisionShape = v119;
  }
}
