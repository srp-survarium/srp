void __thiscall btCompoundCollisionAlgorithm::processCollision(
        btCompoundCollisionAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        const btDispatcherInfo *dispatchInfo,
        btManifoldResult *resultOut)
{
  btCompoundCollisionAlgorithm *v5; // edi
  bool m_isSwapped; // al
  btCollisionObject *v7; // ecx
  btCollisionObject *v8; // ebx
  btCollisionShape *m_collisionShape; // eax
  btCompoundCollisionAlgorithm *m_userPointer; // ecx
  bool v11; // cc
  btPersistentManifold *m_sharedManifold; // eax
  btCollisionAlgorithm **v13; // eax
  int v14; // eax
  int v15; // eax
  btTransform *p_m_rootTransB; // ecx
  btTransform *p_m_rootTransA; // edx
  int v18; // ecx
  btCompoundLeafCallback *v19; // ecx
  int v20; // esi
  btTransform *v21; // eax
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm5_4
  float v25; // xmm0_4
  float v26; // xmm4_4
  float v27; // xmm6_4
  float v28; // xmm5_4
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm4_4
  float v32; // xmm3_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm2_4
  float v36; // xmm3_4
  float v37; // xmm1_4
  unsigned int v38; // xmm3_4
  float v39; // xmm6_4
  float v40; // xmm3_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm2_4
  float v44; // xmm5_4
  float v45; // xmm6_4
  float v46; // xmm5_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm6_4
  float v50; // xmm7_4
  float v51; // xmm6_4
  float v52; // xmm5_4
  float v53; // xmm6_4
  float v54; // xmm7_4
  float v55; // xmm6_4
  float v56; // xmm7_4
  float v57; // xmm6_4
  float v58; // xmm2_4
  btCollisionShape *v59; // ecx
  const btDbvtNode *v60; // eax
  btAlignedObjectArray<GrahamVector2> *m_data; // ecx
  int v62; // eax
  int v63; // eax
  float v64; // xmm2_4
  float v65; // xmm0_4
  float v66; // xmm1_4
  float v67; // xmm5_4
  float v68; // xmm3_4
  float v69; // xmm4_4
  float v70; // xmm0_4
  float v71; // xmm3_4
  float v72; // xmm2_4
  float v73; // xmm1_4
  float v74; // xmm6_4
  float v75; // xmm5_4
  float v76; // xmm6_4
  float v77; // xmm2_4
  float v78; // xmm2_4
  char v79; // al
  btCompoundCollisionAlgorithm *v80; // esi
  btCollisionAlgorithm *v81; // ecx
  const float *v82; // [esp+8h] [ebp-1C0h]
  int v83; // [esp+1Ch] [ebp-1ACh]
  float v84; // [esp+1Ch] [ebp-1ACh]
  int v85; // [esp+1Ch] [ebp-1ACh]
  int j; // [esp+1Ch] [ebp-1ACh]
  int i; // [esp+20h] [ebp-1A8h]
  float v88; // [esp+20h] [ebp-1A8h]
  int v89; // [esp+20h] [ebp-1A8h]
  float v90; // [esp+24h] [ebp-1A4h] BYREF
  float v91; // [esp+28h] [ebp-1A0h]
  float v92; // [esp+2Ch] [ebp-19Ch] BYREF
  btCompoundCollisionAlgorithm *v93; // [esp+30h] [ebp-198h]
  float v94; // [esp+34h] [ebp-194h]
  float v95; // [esp+38h] [ebp-190h] BYREF
  float v96; // [esp+3Ch] [ebp-18Ch] BYREF
  btCollisionObject *v97; // [esp+40h] [ebp-188h]
  float v98; // [esp+44h] [ebp-184h] BYREF
  unsigned __int64 v99; // [esp+48h] [ebp-180h] BYREF
  unsigned __int64 v100; // [esp+50h] [ebp-178h]
  char v101; // [esp+58h] [ebp-170h]
  float v102; // [esp+70h] [ebp-158h] BYREF
  float v103; // [esp+74h] [ebp-154h] BYREF
  float v104; // [esp+78h] [ebp-150h] BYREF
  btCollisionShape *v105; // [esp+7Ch] [ebp-14Ch]
  float v106; // [esp+80h] [ebp-148h] BYREF
  float v107; // [esp+84h] [ebp-144h] BYREF
  btDbvtAabbMm v108; // [esp+88h] [ebp-140h] BYREF
  float v109; // [esp+A8h] [ebp-120h]
  float v110; // [esp+ACh] [ebp-11Ch]
  float v111; // [esp+B0h] [ebp-118h]
  int v112; // [esp+B4h] [ebp-114h]
  btVector3 v113; // [esp+B8h] [ebp-110h]
  btVector3 v114; // [esp+C8h] [ebp-100h]
  int v115; // [esp+E0h] [ebp-E8h]
  float v116; // [esp+E4h] [ebp-E4h] BYREF
  btCompoundLeafCallback policy; // [esp+E8h] [ebp-E0h] BYREF
  int m_size; // [esp+104h] [ebp-C4h]
  btVector3 v119; // [esp+108h] [ebp-C0h] BYREF
  float v120[4]; // [esp+118h] [ebp-B0h] BYREF
  btDbvtAabbMm vol; // [esp+128h] [ebp-A0h] BYREF
  float v122; // [esp+148h] [ebp-80h]
  float v123; // [esp+14Ch] [ebp-7Ch]
  float v124; // [esp+150h] [ebp-78h]
  int v125; // [esp+154h] [ebp-74h]
  btTransform v126; // [esp+158h] [ebp-70h] BYREF
  _QWORD v127[2]; // [esp+198h] [ebp-30h] BYREF
  btVector3 v128; // [esp+1A8h] [ebp-20h]
  btVector3 v129; // [esp+1B8h] [ebp-10h]

  v5 = this;
  m_isSwapped = this->m_isSwapped;
  v7 = body1;
  v93 = v5;
  if ( !m_isSwapped )
    v7 = body0;
  v8 = body0;
  if ( !m_isSwapped )
    v8 = body1;
  m_collisionShape = v7->m_collisionShape;
  v97 = v7;
  m_userPointer = (btCompoundCollisionAlgorithm *)m_collisionShape[5].m_userPointer;
  v105 = m_collisionShape;
  if ( m_userPointer != (btCompoundCollisionAlgorithm *)v5->m_compoundShapeRevision )
  {
    btCompoundCollisionAlgorithm::removeChildAlgorithms(m_userPointer, (int)v5);
    btCompoundCollisionAlgorithm::preallocateChildAlgorithms(v5, body0, body1);
    m_collisionShape = v105;
  }
  v94 = *(float *)&m_collisionShape[5].m_shapeType;
  policy.m_compoundColObj = v97;
  policy.m_dispatcher = v5->m_dispatcher;
  policy.m_dispatchInfo = dispatchInfo;
  v11 = v5->m_childCollisionAlgorithms.m_size <= 0;
  policy.m_childCollisionAlgorithms = v5->m_childCollisionAlgorithms.m_data;
  m_sharedManifold = v5->m_sharedManifold;
  policy.m_otherObj = v8;
  policy.m_resultOut = resultOut;
  policy.m_sharedManifold = m_sharedManifold;
  v101 = 1;
  HIDWORD(v99) = 0;
  v100 = 0;
  v83 = 0;
  if ( !v11 )
  {
    do
    {
      v13 = &v5->m_childCollisionAlgorithms.m_data[v83];
      if ( *v13 )
      {
        (*v13)->getAllContactManifolds(*v13, (btAlignedObjectArray<btPersistentManifold *> *)&v99);
        v14 = SHIDWORD(v99);
        for ( i = 0; i < SHIDWORD(v99); v14 = SHIDWORD(v99) )
        {
          v15 = *(_DWORD *)(HIDWORD(v100) + 4 * i);
          if ( *(_DWORD *)(v15 + 1176) )
          {
            resultOut->m_manifoldPtr = (btPersistentManifold *)v15;
            if ( *(_DWORD *)(v15 + 1176) )
            {
              if ( *(btCollisionObject **)(v15 + 1168) == resultOut->m_body0 )
              {
                p_m_rootTransB = &resultOut->m_rootTransB;
                p_m_rootTransA = &resultOut->m_rootTransA;
              }
              else
              {
                p_m_rootTransB = &resultOut->m_rootTransA;
                p_m_rootTransA = &resultOut->m_rootTransB;
              }
              btPersistentManifold::refreshContactPoints(
                (btPersistentManifold *)p_m_rootTransB,
                p_m_rootTransA,
                (btPersistentManifold *)v15);
            }
            resultOut->m_manifoldPtr = 0;
          }
          ++i;
        }
        v90 = *(float *)&v14;
        if ( v14 < 0 )
        {
          if ( (v100 & 0x80000000) != 0LL )
          {
            if ( HIDWORD(v100) && v101 )
              btAlignedFreeInternal((void *)HIDWORD(v100));
            v101 = 1;
            v100 = 0;
          }
          if ( v90 < 0.0 )
          {
            v18 = 4 * LODWORD(v90);
            do
            {
              if ( v18 + HIDWORD(v100) )
                *(_DWORD *)(v18 + HIDWORD(v100)) = 0;
              v18 += 4;
            }
            while ( v18 < 0 );
          }
        }
        HIDWORD(v99) = 0;
      }
      ++v83;
    }
    while ( v83 < v5->m_childCollisionAlgorithms.m_size );
  }
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(0, (int)&v99);
  v20 = 0;
  if ( v94 == 0.0 )
  {
    v96 = *(float *)&v5->m_childCollisionAlgorithms.m_size;
    for ( j = 0; j < SLODWORD(v96); v20 += 80 )
      btCompoundLeafCallback::ProcessChildShape(
        v19,
        (btCollisionShape *)&policy,
        *(int *)((char *)&v105[2].__vftable[1].getBoundingSphere + v20),
        j++);
  }
  else
  {
    v21 = btTransform::inverse((btTransform *)v19, (int)&v97->m_worldTransform, &v126);
    v22 = v8->m_worldTransform.m_origin.mVec128.m128_f32[0];
    v23 = v8->m_worldTransform.m_origin.mVec128.m128_f32[1];
    v24 = v21->m_basis.m_el[0].mVec128.m128_f32[0];
    v25 = v8->m_worldTransform.m_origin.mVec128.m128_f32[2];
    v26 = v21->m_basis.m_el[0].mVec128.m128_f32[1];
    v27 = v22 * v21->m_basis.m_el[0].mVec128.m128_f32[0];
    v91 = v21->m_basis.m_el[0].mVec128.m128_f32[2];
    v84 = v24;
    v28 = v8->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1];
    v88 = v26;
    v29 = (float)((float)(v27 + (float)(v23 * v26)) + (float)(v25 * v91)) + v21->m_origin.mVec128.m128_f32[0];
    v30 = v21->m_basis.m_el[2].mVec128.m128_f32[1];
    v31 = v8->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2];
    v114.mVec128.m128_f32[1] = (float)((float)((float)(v21->m_basis.m_el[1].mVec128.m128_f32[1] * v23)
                                             + (float)(v21->m_basis.m_el[1].mVec128.m128_f32[2] * v25))
                                     + (float)(v21->m_basis.m_el[1].mVec128.m128_f32[0] * v22))
                             + v21->m_origin.mVec128.m128_f32[1];
    v32 = v21->m_basis.m_el[2].mVec128.m128_f32[1] * v23;
    v33 = v21->m_basis.m_el[2].mVec128.m128_f32[2] * v25;
    v34 = v21->m_basis.m_el[2].mVec128.m128_f32[0] * v22;
    v35 = v21->m_basis.m_el[2].mVec128.m128_f32[2];
    v36 = v32 + v33;
    v37 = v21->m_basis.m_el[2].mVec128.m128_f32[1];
    *(float *)&v38 = (float)(v36 + v34) + v21->m_origin.mVec128.m128_f32[2];
    v114.mVec128.m128_f32[0] = v29;
    v39 = v21->m_basis.m_el[2].mVec128.m128_f32[1] * v28;
    v114.mVec128.m128_u64[1] = v38;
    v40 = v8->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2];
    v41 = v8->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2];
    v42 = (float)((float)(v37 * v31) + (float)(v35 * v40)) + (float)(v41 * v21->m_basis.m_el[2].mVec128.m128_f32[0]);
    v43 = v8->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1];
    v98 = v28;
    v44 = v21->m_basis.m_el[2].mVec128.m128_f32[2] * v43;
    v92 = v43;
    v45 = v39 + v44;
    v46 = v8->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
    v104 = v42;
    v47 = v8->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1];
    v48 = v8->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0];
    v107 = v45 + (float)(v47 * v21->m_basis.m_el[2].mVec128.m128_f32[0]);
    v90 = v8->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0];
    v49 = v21->m_basis.m_el[2].mVec128.m128_f32[2];
    v95 = v46;
    v50 = (float)((float)(v30 * v90) + (float)(v49 * v46)) + (float)(v48 * v21->m_basis.m_el[2].mVec128.m128_f32[0]);
    v51 = v21->m_basis.m_el[1].mVec128.m128_f32[2] * v92;
    v102 = (float)((float)(v21->m_basis.m_el[1].mVec128.m128_f32[1] * v31)
                 + (float)(v21->m_basis.m_el[1].mVec128.m128_f32[2] * v40))
         + (float)(v41 * v21->m_basis.m_el[1].mVec128.m128_f32[0]);
    v52 = (float)((float)(v21->m_basis.m_el[1].mVec128.m128_f32[1] * v98) + v51)
        + (float)(v21->m_basis.m_el[1].mVec128.m128_f32[0] * v47);
    v53 = v21->m_basis.m_el[1].mVec128.m128_f32[1];
    v106 = v50;
    v54 = v21->m_basis.m_el[1].mVec128.m128_f32[2];
    v103 = v52;
    v55 = (float)(v53 * v90) + (float)(v54 * v95);
    v56 = v21->m_basis.m_el[1].mVec128.m128_f32[0];
    v96 = (float)((float)(v41 * v84) + (float)(v31 * v88)) + (float)(v40 * v91);
    v57 = v55 + (float)(v56 * v48);
    v58 = (float)((float)(v48 * v84) + (float)(v90 * v88)) + (float)(v95 * v91);
    v95 = v57;
    v92 = (float)((float)(v47 * v84) + (float)(v98 * v88)) + (float)(v92 * v91);
    v90 = v58;
    btMatrix3x3::setValue((btMatrix3x3 *)&v90, (int)&vol, &v92, &v96, &v95, &v103, &v102, &v106, &v107, &v104, v82);
    v108 = vol;
    v109 = v122;
    v110 = v123;
    v59 = v8->m_collisionShape;
    v111 = v124;
    v112 = v125;
    v113.mVec128 = v114.mVec128;
    v59->getAabb(v59, (const btTransform *)&v108, (btVector3 *)&v99, &v119);
    vol.mi.mVec128.m128_u64[0] = v99;
    v60 = *(const btDbvtNode **)LODWORD(v94);
    vol.mi.mVec128.m128_u64[1] = v100;
    vol.mx = (btVector3)v119.mVec128;
    if ( v60 )
      btDbvt::collideTV<btCompoundLeafCallback>(&vol, v60, (btCollisionShape *)&policy);
    v5 = v93;
  }
  v62 = 0;
  m_size = v5->m_childCollisionAlgorithms.m_size;
  m_data = (btAlignedObjectArray<GrahamVector2> *)m_size;
  LOBYTE(policy.m_resultOut) = 1;
  memset(&policy.m_otherObj, 0, 12);
  v85 = 0;
  if ( m_size > 0 )
  {
    v89 = 0;
    do
    {
      m_data = (btAlignedObjectArray<GrahamVector2> *)v5->m_childCollisionAlgorithms.m_data;
      if ( *((_DWORD *)&m_data->m_allocator + v62) )
      {
        v63 = (int)v105[2].__vftable + v89;
        v115 = *(_DWORD *)(v63 + 64);
        v108 = *(btDbvtAabbMm *)v97->m_worldTransform.m_basis.m_el[0].mVec128.m128_i8;
        v109 = v97->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
        v110 = v97->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1];
        v111 = v97->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2];
        v112 = v97->m_worldTransform.m_basis.m_el[2].mVec128.m128_i32[3];
        v64 = *(float *)(v63 + 52);
        v65 = *(float *)(v63 + 48);
        v66 = *(float *)(v63 + 56);
        v113.mVec128 = (__m128)v97->m_worldTransform.m_origin;
        v67 = *(float *)(v63 + 20);
        v114.mVec128.m128_f32[0] = (float)((float)((float)(v65 * v108.mi.mVec128.m128_f32[0])
                                                 + (float)(v64 * v108.mi.mVec128.m128_f32[1]))
                                         + (float)(v66 * v108.mi.mVec128.m128_f32[2]))
                                 + v113.mVec128.m128_f32[0];
        v114.mVec128.m128_f32[2] = (float)((float)((float)(v65 * v109) + (float)(v64 * v110)) + (float)(v66 * v111))
                                 + v113.mVec128.m128_f32[2];
        v68 = (float)((float)((float)(v65 * v108.mx.mVec128.m128_f32[0]) + (float)(v64 * v108.mx.mVec128.m128_f32[1]))
                    + (float)(v66 * v108.mx.mVec128.m128_f32[2]))
            + v113.mVec128.m128_f32[1];
        v69 = *(float *)(v63 + 24);
        v114.mVec128.m128_i32[3] = 0;
        v70 = *(float *)(v63 + 8);
        v114.mVec128.m128_f32[1] = v68;
        v71 = *(float *)(v63 + 40);
        v72 = *(float *)(v63 + 36);
        v96 = (float)((float)(v70 * v109) + (float)(v69 * v110)) + (float)(v71 * v111);
        v73 = *(float *)(v63 + 4);
        v90 = v72;
        v94 = v67;
        v74 = (float)(v73 * v109) + (float)(v67 * v110);
        v75 = *(float *)(v63 + 16);
        v76 = v74 + (float)(v72 * v111);
        v77 = *(float *)(v63 + 32);
        v103 = v76;
        v92 = v75;
        v91 = v77;
        v78 = *(float *)v63;
        v102 = (float)((float)(*(float *)v63 * v109) + (float)(v75 * v110)) + (float)(v91 * v111);
        v106 = (float)((float)(v70 * v108.mx.mVec128.m128_f32[0]) + (float)(v69 * v108.mx.mVec128.m128_f32[1]))
             + (float)(v71 * v108.mx.mVec128.m128_f32[2]);
        v95 = (float)((float)(v70 * v108.mi.mVec128.m128_f32[0]) + (float)(v69 * v108.mi.mVec128.m128_f32[1]))
            + (float)(v71 * v108.mi.mVec128.m128_f32[2]);
        v107 = (float)((float)(v73 * v108.mx.mVec128.m128_f32[0]) + (float)(v94 * v108.mx.mVec128.m128_f32[1]))
             + (float)(v90 * v108.mx.mVec128.m128_f32[2]);
        v104 = (float)((float)(v78 * v108.mx.mVec128.m128_f32[0]) + (float)(v75 * v108.mx.mVec128.m128_f32[1]))
             + (float)(v91 * v108.mx.mVec128.m128_f32[2]);
        v98 = (float)((float)(v73 * v108.mi.mVec128.m128_f32[0]) + (float)(v94 * v108.mi.mVec128.m128_f32[1]))
            + (float)(v90 * v108.mi.mVec128.m128_f32[2]);
        v116 = (float)((float)(v78 * v108.mi.mVec128.m128_f32[0]) + (float)(v75 * v108.mi.mVec128.m128_f32[1]))
             + (float)(v91 * v108.mi.mVec128.m128_f32[2]);
        btMatrix3x3::setValue((btMatrix3x3 *)&v116, (int)v127, &v98, &v95, &v104, &v107, &v106, &v102, &v103, &v96, v82);
        v126.m_basis.m_el[0].mVec128.m128_u64[0] = v127[0];
        v126.m_basis.m_el[0].mVec128.m128_u64[1] = v127[1];
        v126.m_basis.m_el[1] = (btVector3)v128.mVec128;
        v126.m_basis.m_el[2] = (btVector3)v129.mVec128;
        v126.m_origin = (btVector3)v114.mVec128;
        (*(void (__thiscall **)(int, btTransform *, float *, unsigned __int64 *))(*(_DWORD *)v115 + 4))(
          v115,
          &v126,
          v120,
          &v99);
        v8->m_collisionShape->getAabb(v8->m_collisionShape, &v8->m_worldTransform, &v119, &vol.mi);
        v79 = 1;
        if ( v120[0] > vol.mi.mVec128.m128_f32[0] || v119.mVec128.m128_f32[0] > *(float *)&v99 )
          v79 = 0;
        if ( v120[2] > vol.mi.mVec128.m128_f32[2] || v119.mVec128.m128_f32[2] > *(float *)&v100 )
          v79 = 0;
        if ( v120[1] > vol.mi.mVec128.m128_f32[1] || v119.mVec128.m128_f32[1] > *((float *)&v99 + 1) )
          v79 = 0;
        if ( v79 )
        {
          v5 = v93;
        }
        else
        {
          v80 = v93;
          v81 = v93->m_childCollisionAlgorithms.m_data[v85];
          ((void (__thiscall *)(btCollisionAlgorithm *, _DWORD))v81->~btCollisionAlgorithm)(v81, 0);
          v80->m_dispatcher->freeCollisionAlgorithm(v80->m_dispatcher, v80->m_childCollisionAlgorithms.m_data[v85]);
          v80->m_childCollisionAlgorithms.m_data[v85] = 0;
          v5 = v80;
        }
      }
      v89 += 80;
      v62 = ++v85;
    }
    while ( v85 < m_size );
  }
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(m_data, (int)&policy);
}
