void __thiscall btSoftBodyTriangleCallback::processTriangle(
        btSoftBodyTriangleCallback *this,
        btVector3 *triangle,
        int partId,
        int triangleIndex)
{
  btCollisionObject *m_triBody; // esi
  const btDispatcherInfo *m_dispatchInfoPtr; // eax
  float v7; // xmm1_4
  float v8; // xmm5_4
  float v9; // xmm3_4
  float v10; // xmm6_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm7_4
  float v14; // xmm6_4
  float v15; // xmm7_4
  float v16; // xmm6_4
  float v17; // xmm1_4
  float v18; // xmm7_4
  float v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm5_4
  float v23; // xmm7_4
  float v24; // xmm6_4
  float v25; // xmm7_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  float v31; // xmm5_4
  float v32; // xmm3_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm4_4
  float v36; // xmm2_4
  float v37; // xmm6_4
  float v38; // xmm7_4
  float v39; // xmm6_4
  float v40; // xmm1_4
  float v41; // xmm7_4
  float v42; // xmm6_4
  float v43; // xmm7_4
  float v44; // xmm5_4
  float v45; // xmm4_4
  float v46; // xmm7_4
  float v47; // xmm5_4
  float v48; // xmm7_4
  float v49; // xmm1_4
  float v50; // xmm0_4
  float v51; // xmm2_4
  float v52; // xmm0_4
  float v53; // xmm2_4
  float v54; // xmm1_4
  float v55; // xmm0_4
  float v56; // xmm2_4
  const btDispatcherInfo *v57; // eax
  float v58; // xmm5_4
  float v59; // xmm3_4
  float v60; // xmm1_4
  float v61; // xmm0_4
  float v62; // xmm4_4
  float v63; // xmm2_4
  float v64; // xmm6_4
  float v65; // xmm7_4
  float v66; // xmm6_4
  float v67; // xmm1_4
  float v68; // xmm7_4
  float v69; // xmm6_4
  float v70; // xmm7_4
  float v71; // xmm5_4
  float v72; // xmm4_4
  float v73; // xmm7_4
  float v74; // xmm5_4
  float v75; // xmm7_4
  float v76; // xmm1_4
  float v77; // xmm0_4
  float v78; // xmm2_4
  float v79; // xmm0_4
  float v80; // xmm2_4
  const btDispatcherInfo *v81; // eax
  int Index; // eax
  btTriIndex *v83; // eax
  btCollisionShape *m_childShape; // eax
  btCollisionShape *v85; // ecx
  int v86; // edi
  float v87; // xmm2_4
  float v88; // xmm7_4
  float v89; // xmm4_4
  float v90; // xmm0_4
  float v91; // xmm3_4
  float v92; // xmm6_4
  float v93; // xmm5_4
  float v94; // xmm4_4
  float v95; // xmm1_4
  long double v96; // st7
  float v97; // xmm4_4
  float v98; // xmm5_4
  float v99; // xmm1_4
  float v100; // xmm2_4
  float v101; // xmm3_4
  float v102; // xmm7_4
  float v103; // xmm7_4
  float v104; // xmm7_4
  float v105; // xmm4_4
  float v106; // xmm6_4
  float v107; // xmm7_4
  float v108; // xmm4_4
  float v109; // xmm1_4
  float v110; // xmm7_4
  float v111; // xmm1_4
  void *v112; // eax
  btConvexHullShape *v113; // ecx
  btConvexHullShape *v114; // eax
  btCollisionShape *m_collisionShape; // ecx
  btCollisionObject *v116; // eax
  int v117; // edi
  int v118; // [esp+53Ch] [ebp-E0h]
  int v119; // [esp+540h] [ebp-DCh]
  float v120; // [esp+554h] [ebp-C8h]
  float v121; // [esp+554h] [ebp-C8h]
  float v122; // [esp+554h] [ebp-C8h]
  btCollisionShape *v123; // [esp+554h] [ebp-C8h]
  float v124; // [esp+558h] [ebp-C4h]
  int v125; // [esp+558h] [ebp-C4h]
  float v126; // [esp+55Ch] [ebp-C0h] BYREF
  float v127; // [esp+560h] [ebp-BCh]
  float v128; // [esp+564h] [ebp-B8h]
  int v129; // [esp+568h] [ebp-B4h]
  float v130; // [esp+578h] [ebp-A4h]
  float v131; // [esp+57Ch] [ebp-A0h] BYREF
  float v132; // [esp+580h] [ebp-9Ch]
  float v133; // [esp+584h] [ebp-98h]
  int v134; // [esp+588h] [ebp-94h]
  btHashMap<btHashKey<btTriIndex>,btTriIndex> key; // [esp+598h] [ebp-84h] BYREF
  int v136; // [esp+5E8h] [ebp-34h]
  float v137; // [esp+5ECh] [ebp-30h]
  float v138; // [esp+5F0h] [ebp-2Ch]
  float v139; // [esp+5F4h] [ebp-28h]
  int v140; // [esp+5F8h] [ebp-24h]
  float v141; // [esp+5FCh] [ebp-20h]
  float v142; // [esp+600h] [ebp-1Ch]
  float v143; // [esp+604h] [ebp-18h]
  int v144; // [esp+608h] [ebp-14h]
  float v145; // [esp+60Ch] [ebp-10h]
  float v146; // [esp+610h] [ebp-Ch]
  float v147; // [esp+614h] [ebp-8h]
  int v148; // [esp+618h] [ebp-4h]

  m_triBody = this->m_triBody;
  key.m_next.m_capacity = (int)this->m_dispatcher;
  m_dispatchInfoPtr = this->m_dispatchInfoPtr;
  if ( m_dispatchInfoPtr
    && m_dispatchInfoPtr->m_debugDraw
    && (m_dispatchInfoPtr->m_debugDraw->getDebugMode(m_dispatchInfoPtr->m_debugDraw) & 1) != 0 )
  {
    v7 = triangle[1].mVec128.m128_f32[0];
    v8 = triangle[1].mVec128.m128_f32[2];
    v9 = m_triBody->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1];
    v10 = triangle[1].mVec128.m128_f32[1];
    v11 = m_triBody->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2];
    key.m_hashTable.m_size = (int)clear_value;
    key.m_hashTable.m_capacity = (int)clear_value;
    v12 = m_triBody->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0];
    v13 = (float)((float)((float)(v7 * v12) + (float)(v10 * v9)) + (float)(v8 * v11))
        + m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[0];
    v14 = triangle[1].mVec128.m128_f32[1];
    v126 = v13;
    v15 = (float)(m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v14)
        + (float)(m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v8);
    v16 = v7 * m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0];
    v17 = v7 * m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
    v18 = (float)(v15 + v16) + m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[1];
    v19 = triangle[1].mVec128.m128_f32[1];
    v127 = v18;
    v20 = m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v19;
    v21 = m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v8;
    v22 = triangle->mVec128.m128_f32[1];
    v23 = v20 + v21;
    v24 = triangle->mVec128.m128_f32[0];
    v120 = v23 + v17;
    v25 = m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[2];
    v128 = v120 + v25;
    v26 = triangle->mVec128.m128_f32[2];
    v27 = (float)((float)((float)(v12 * v24) + (float)(v9 * v22)) + (float)(v11 * v26))
        + m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[0];
    v28 = m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1];
    v131 = v27;
    v29 = m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1];
    v132 = (float)((float)((float)(v28 * v22)
                         + (float)(m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v26))
                 + (float)(m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v24))
         + m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[1];
    v30 = (float)((float)((float)(v29 * v22)
                        + (float)(m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v26))
                + (float)(m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0] * v24))
        + v25;
    key.m_hashTable.m_data = 0;
    *(_DWORD *)&key.m_hashTable.m_ownsMemory = 0;
    v129 = 0;
    v133 = v30;
    v134 = 0;
    this->m_dispatchInfoPtr->m_debugDraw->drawLine(
      this->m_dispatchInfoPtr->m_debugDraw,
      (const btVector3 *)&v131,
      (const btVector3 *)&v126,
      (const btVector3 *)&key.m_hashTable.m_size);
    v31 = triangle[2].mVec128.m128_f32[1];
    v32 = m_triBody->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1];
    v33 = triangle[2].mVec128.m128_f32[0];
    v34 = m_triBody->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0];
    v35 = triangle[2].mVec128.m128_f32[2];
    v36 = m_triBody->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2];
    v37 = m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2];
    v131 = (float)((float)((float)(v34 * v33) + (float)(v32 * v31)) + (float)(v36 * v35))
         + m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[0];
    v38 = (float)(m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v31) + (float)(v37 * v35);
    v39 = m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v33;
    v40 = v33 * m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
    v41 = v38 + v39;
    v42 = m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[1];
    v132 = v41 + v42;
    v43 = m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v31;
    v44 = m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v35;
    v45 = triangle[1].mVec128.m128_f32[2];
    v46 = v43 + v44;
    v47 = triangle[1].mVec128.m128_f32[1];
    v121 = v46 + v40;
    v48 = m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[2];
    v133 = v121 + v48;
    v134 = 0;
    v49 = triangle[1].mVec128.m128_f32[0];
    v50 = (float)((float)((float)(v34 * v49) + (float)(v32 * v47)) + (float)(v36 * v45))
        + m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[0];
    v51 = m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2];
    v126 = v50;
    v52 = (float)(m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v47) + (float)(v51 * v45);
    v53 = v49 * m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0];
    v54 = v49 * m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
    v55 = v52 + v53;
    v56 = m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2];
    v127 = v55 + v42;
    v57 = this->m_dispatchInfoPtr;
    v128 = (float)((float)((float)(m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v47)
                         + (float)(v56 * v45))
                 + v54)
         + v48;
    v129 = 0;
    v57->m_debugDraw->drawLine(
      v57->m_debugDraw,
      (const btVector3 *)&v126,
      (const btVector3 *)&v131,
      (const btVector3 *)&key.m_hashTable.m_size);
    v58 = triangle->mVec128.m128_f32[1];
    v59 = m_triBody->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1];
    v60 = triangle->mVec128.m128_f32[0];
    v61 = m_triBody->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0];
    v62 = triangle->mVec128.m128_f32[2];
    v63 = m_triBody->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2];
    v64 = m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2];
    v131 = (float)((float)((float)(v61 * triangle->mVec128.m128_f32[0]) + (float)(v59 * v58)) + (float)(v63 * v62))
         + m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[0];
    v65 = (float)(m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v58) + (float)(v64 * v62);
    v66 = m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v60;
    v67 = v60 * m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
    v68 = v65 + v66;
    v69 = m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[1];
    v132 = v68 + v69;
    v70 = m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v58;
    v71 = m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v62;
    v72 = triangle[2].mVec128.m128_f32[1];
    v73 = v70 + v71;
    v74 = triangle[2].mVec128.m128_f32[0];
    v122 = v73 + v67;
    v75 = m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[2];
    v133 = v122 + v75;
    v134 = 0;
    v76 = triangle[2].mVec128.m128_f32[2];
    v77 = (float)((float)((float)(v61 * v74) + (float)(v59 * v72)) + (float)(v63 * v76))
        + m_triBody->m_worldTransform.m_origin.mVec128.m128_f32[0];
    v78 = m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2];
    v126 = v77;
    v79 = (float)((float)(m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v72) + (float)(v78 * v76))
        + (float)(v74 * m_triBody->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0]);
    v80 = m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2];
    v127 = v79 + v69;
    v81 = this->m_dispatchInfoPtr;
    v128 = (float)((float)((float)(m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v72)
                         + (float)(v80 * v76))
                 + (float)(m_triBody->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0] * v74))
         + v75;
    v129 = 0;
    v81->m_debugDraw->drawLine(
      v81->m_debugDraw,
      (const btVector3 *)&v126,
      (const btVector3 *)&v131,
      (const btVector3 *)&key.m_hashTable.m_size);
  }
  key.m_hashTable.m_size = triangleIndex | (partId << 21);
  *(_DWORD *)&key.m_hashTable.m_allocator = key.m_hashTable.m_size;
  key.m_hashTable.m_capacity = 0;
  Index = btHashMap<btHashKey<btTriIndex>,btTriIndex>::findIndex(
            &this->m_shapeCache,
            (const btHashKey<btTriIndex> *)&key);
  if ( Index == -1 || (v83 = &this->m_shapeCache.m_valueArray.m_data[Index]) == 0 )
  {
    v87 = triangle->mVec128.m128_f32[1];
    v88 = triangle->mVec128.m128_f32[2];
    v89 = triangle[1].mVec128.m128_f32[1];
    v90 = triangle[2].mVec128.m128_f32[1] - v87;
    v91 = triangle[2].mVec128.m128_f32[2] - v88;
    v92 = triangle[1].mVec128.m128_f32[0] - triangle->mVec128.m128_f32[0];
    v93 = triangle[2].mVec128.m128_f32[0] - triangle->mVec128.m128_f32[0];
    v130 = triangle->mVec128.m128_f32[0];
    v94 = v89 - v87;
    v95 = triangle[1].mVec128.m128_f32[2] - v88;
    v128 = (float)(v90 * v92) - (float)(v94 * v93);
    v126 = (float)(v94 * v91) - (float)(v95 * v90);
    v127 = (float)(v95 * v93) - (float)(v91 * v92);
    v96 = sqrtf((float)((float)(v128 * v128) + (float)(v127 * v127)) + (float)(v126 * v126));
    v97 = triangle->mVec128.m128_f32[1];
    v98 = triangle->mVec128.m128_f32[2];
    v124 = 1.0 / v96;
    v99 = (float)(v126 * v124) * 0.059999999;
    v100 = (float)(v127 * v124) * 0.059999999;
    v101 = (float)(v128 * v124) * 0.059999999;
    *(float *)&key.m_valueArray.m_data = triangle[1].mVec128.m128_f32[0] + v99;
    v102 = triangle[1].mVec128.m128_f32[1];
    *(float *)&key.m_next.m_ownsMemory = v99 + v130;
    *(float *)&key.m_valueArray.m_allocator = v100 + v97;
    *(float *)&key.m_valueArray.m_ownsMemory = v102 + v100;
    v103 = triangle[1].mVec128.m128_f32[2] + v101;
    *(float *)&key.m_valueArray.m_size = v101 + v98;
    *(float *)&key.m_keyArray.m_allocator = v103;
    v104 = triangle[2].mVec128.m128_f32[0];
    key.m_valueArray.m_capacity = 0;
    key.m_keyArray.m_size = 0;
    ++gNumAlignedAllocs;
    v138 = v97 - v100;
    v141 = triangle[1].mVec128.m128_f32[0] - v99;
    v142 = triangle[1].mVec128.m128_f32[1] - v100;
    v105 = triangle[1].mVec128.m128_f32[2] - v101;
    v106 = v130 - v99;
    *(float *)&key.m_keyArray.m_capacity = v104 + v99;
    v107 = triangle[2].mVec128.m128_f32[1];
    v143 = v105;
    v108 = triangle[2].mVec128.m128_f32[0] - v99;
    v109 = triangle[2].mVec128.m128_f32[1] - v100;
    *(float *)&key.m_keyArray.m_data = v107 + v100;
    v110 = triangle[2].mVec128.m128_f32[2];
    v146 = v109;
    v111 = triangle[2].mVec128.m128_f32[2] - v101;
    *(float *)&key.m_keyArray.m_ownsMemory = v110 + v101;
    v136 = 0;
    v137 = v106;
    v139 = v98 - v101;
    v140 = 0;
    v144 = 0;
    v145 = v108;
    v147 = v111;
    v148 = 0;
    v112 = sAlignedAllocFunc(0xA0u, 16);
    if ( v112 )
    {
      v114 = btConvexHullShape::btConvexHullShape(v113, (int)v112, (const float *)&key.m_next.m_ownsMemory, v118, v119);
      v125 = (int)v114;
    }
    else
    {
      v125 = 0;
      v114 = 0;
    }
    v114->m_userPointer = m_triBody->m_rootCollisionShape->m_userPointer;
    m_collisionShape = m_triBody->m_collisionShape;
    m_triBody->m_collisionShape = v114;
    v116 = this->m_triBody;
    v130 = *(float *)&m_collisionShape;
    v117 = (*(int (__thiscall **)(int, btSoftBody *, btCollisionObject *, _DWORD))(*(_DWORD *)key.m_next.m_capacity + 4))(
             key.m_next.m_capacity,
             this->m_softBody,
             v116,
             0);
    (*(void (__thiscall **)(int, btSoftBody *, btCollisionObject *, const btDispatcherInfo *, btManifoldResult *))(*(_DWORD *)v117 + 4))(
      v117,
      this->m_softBody,
      this->m_triBody,
      this->m_dispatchInfoPtr,
      this->m_resultOut);
    (**(void (__thiscall ***)(int, _DWORD))v117)(v117, 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)key.m_next.m_capacity + 56))(key.m_next.m_capacity, v117);
    *(float *)&m_triBody->m_collisionShape = v130;
    key.m_hashTable.m_capacity = v125;
    btHashMap<btHashKey<btTriIndex>,btTriIndex>::insert(
      &key,
      &this->m_shapeCache,
      (const btHashKey<btTriIndex> *)&key,
      (const btTriIndex *)&key.m_hashTable.m_size);
  }
  else
  {
    m_childShape = v83->m_childShape;
    m_childShape->m_userPointer = m_triBody->m_rootCollisionShape->m_userPointer;
    v85 = m_triBody->m_collisionShape;
    m_triBody->m_collisionShape = m_childShape;
    v123 = v85;
    v86 = (*(int (__thiscall **)(int, btSoftBody *, btCollisionObject *, _DWORD))(*(_DWORD *)key.m_next.m_capacity + 4))(
            key.m_next.m_capacity,
            this->m_softBody,
            this->m_triBody,
            0);
    (*(void (__thiscall **)(int, btSoftBody *, btCollisionObject *, const btDispatcherInfo *, btManifoldResult *))(*(_DWORD *)v86 + 4))(
      v86,
      this->m_softBody,
      this->m_triBody,
      this->m_dispatchInfoPtr,
      this->m_resultOut);
    (**(void (__thiscall ***)(int, _DWORD))v86)(v86, 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)key.m_next.m_capacity + 56))(key.m_next.m_capacity, v86);
    m_triBody->m_collisionShape = v123;
  }
}
