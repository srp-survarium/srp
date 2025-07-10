void __thiscall btCompoundCollisionAlgorithm::processCollision(
        btCompoundCollisionAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        const btDispatcherInfo *dispatchInfo,
        btManifoldResult *resultOut)
{
  btCollisionObject *v5; // ebx
  btCollisionObject *v7; // edi
  btCollisionShape *m_collisionShape; // eax
  btCompoundCollisionAlgorithm *m_userPointer; // ecx
  const btDbvtNode **m_shapeType; // edx
  btDispatcher *m_dispatcher; // eax
  btCompoundCollisionAlgorithm *v12; // ecx
  btCollisionAlgorithm **m_data; // edx
  void *v14; // eax
  int v15; // edx
  bool v16; // cc
  btCollisionAlgorithm **v17; // eax
  bool v18; // zf
  btCollisionAlgorithm **v19; // eax
  int v20; // ecx
  int i; // edi
  int v22; // eax
  btTransform *p_m_rootTransB; // ecx
  btTransform *p_m_rootTransA; // edx
  int v25; // edi
  int v26; // ecx
  float *v27; // eax
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm7_4
  float v32; // xmm6_4
  float v33; // xmm5_4
  float v34; // xmm6_4
  float v35; // xmm4_4
  float v36; // xmm3_4
  float v37; // xmm1_4
  unsigned int v38; // xmm3_4
  float v39; // xmm2_4
  float v40; // xmm6_4
  float v41; // xmm3_4
  float v42; // xmm0_4
  unsigned int v43; // xmm5_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm7_4
  float v47; // xmm6_4
  float v48; // xmm7_4
  float v49; // xmm6_4
  float v50; // xmm7_4
  unsigned int v51; // xmm6_4
  const btDbvtNode *v52; // eax
  int v53; // edi
  int v54; // esi
  btCollisionShape_vtbl *v55; // ecx
  float v56; // xmm1_4
  float v57; // xmm2_4
  float *v58; // eax
  float v59; // xmm0_4
  int v60; // ecx
  int v61; // xmm3_4
  float v62; // xmm4_4
  float v63; // xmm0_4
  float v64; // xmm3_4
  unsigned int v65; // xmm5_4
  float v66; // xmm1_4
  float v67; // xmm2_4
  __m128i v68; // xmm0
  __m128i v69; // xmm0
  char v70; // al
  btCollisionAlgorithm *v71; // ecx
  const btDbvtNode **v72; // [esp+1304h] [ebp-188h]
  int v73; // [esp+1304h] [ebp-188h]
  btCollisionObject *v74; // [esp+1308h] [ebp-184h]
  float v75; // [esp+1308h] [ebp-184h]
  float v76; // [esp+1308h] [ebp-184h]
  int v78; // [esp+1310h] [ebp-17Ch]
  float v79; // [esp+1310h] [ebp-17Ch]
  int v80; // [esp+1310h] [ebp-17Ch]
  float v81; // [esp+1314h] [ebp-178h]
  float v82; // [esp+1314h] [ebp-178h]
  float v83; // [esp+1318h] [ebp-174h]
  float v84; // [esp+1318h] [ebp-174h]
  float v85; // [esp+131Ch] [ebp-170h]
  float v86; // [esp+131Ch] [ebp-170h]
  unsigned int v87; // [esp+1324h] [ebp-168h]
  int m_size; // [esp+1324h] [ebp-168h]
  float v89; // [esp+1328h] [ebp-164h]
  __m128i v90; // [esp+132Ch] [ebp-160h] BYREF
  int v91; // [esp+133Ch] [ebp-150h]
  float v92; // [esp+1358h] [ebp-134h]
  btCollisionShape *v93; // [esp+135Ch] [ebp-130h]
  int v94; // [esp+1360h] [ebp-12Ch]
  float v95; // [esp+1364h] [ebp-128h]
  unsigned int v96; // [esp+1368h] [ebp-124h]
  __m128i si128; // [esp+136Ch] [ebp-120h] BYREF
  __m128i v98; // [esp+137Ch] [ebp-110h]
  __m128i v99; // [esp+138Ch] [ebp-100h]
  __m128i m_origin; // [esp+139Ch] [ebp-F0h]
  __m128i v101; // [esp+13ACh] [ebp-E0h] BYREF
  btCompoundLeafCallback policy; // [esp+13BCh] [ebp-D0h] BYREF
  btDbvtAabbMm vol; // [esp+13DCh] [ebp-B0h] BYREF
  __m128i v104; // [esp+13FCh] [ebp-90h] BYREF
  __m128i v105; // [esp+140Ch] [ebp-80h] BYREF
  __m128i v106; // [esp+141Ch] [ebp-70h] BYREF
  __m128i v107; // [esp+142Ch] [ebp-60h] BYREF
  __m128i v108; // [esp+143Ch] [ebp-50h] BYREF
  btTransform v109; // [esp+144Ch] [ebp-40h] BYREF

  v5 = body1;
  if ( this->m_isSwapped )
  {
    v7 = body0;
    v74 = body0;
  }
  else
  {
    v5 = body0;
    v74 = body1;
    v7 = body1;
  }
  m_collisionShape = v5->m_collisionShape;
  m_userPointer = (btCompoundCollisionAlgorithm *)m_collisionShape[5].m_userPointer;
  v93 = m_collisionShape;
  if ( m_userPointer != (btCompoundCollisionAlgorithm *)this->m_compoundShapeRevision )
  {
    btCompoundCollisionAlgorithm::removeChildAlgorithms(m_userPointer, (int)this);
    btCompoundCollisionAlgorithm::preallocateChildAlgorithms(this, body0, body1);
    v7 = v74;
    m_collisionShape = v93;
  }
  m_shapeType = (const btDbvtNode **)m_collisionShape[5].m_shapeType;
  m_dispatcher = this->m_dispatcher;
  policy.m_dispatchInfo = dispatchInfo;
  v12 = this;
  policy.m_dispatcher = m_dispatcher;
  v72 = m_shapeType;
  m_data = this->m_childCollisionAlgorithms.m_data;
  policy.m_sharedManifold = this->m_sharedManifold;
  v14 = 0;
  policy.m_childCollisionAlgorithms = m_data;
  v15 = 0;
  v16 = this->m_childCollisionAlgorithms.m_size <= 0;
  policy.m_compoundColObj = v5;
  policy.m_otherObj = v7;
  policy.m_resultOut = resultOut;
  LOBYTE(v91) = 1;
  memset((char *)v90.m128i_i64 + 4, 0, 12);
  v78 = 0;
  if ( !v16 )
  {
    do
    {
      v17 = v12->m_childCollisionAlgorithms.m_data;
      v18 = v17[v15] == 0;
      v19 = &v17[v15];
      if ( !v18 )
      {
        (*v19)->getAllContactManifolds(*v19, (btAlignedObjectArray<btPersistentManifold *> *)&v90);
        v20 = v90.m128i_i32[1];
        for ( i = 0; i < v20; ++i )
        {
          v22 = *(_DWORD *)(v90.m128i_i32[3] + 4 * i);
          if ( *(_DWORD *)(v22 + 1176) )
          {
            resultOut->m_manifoldPtr = (btPersistentManifold *)v22;
            if ( *(_DWORD *)(v22 + 1176) )
            {
              if ( *(btCollisionObject **)(v22 + 1168) == resultOut->m_body0 )
              {
                p_m_rootTransB = &resultOut->m_rootTransB;
                p_m_rootTransA = &resultOut->m_rootTransA;
              }
              else
              {
                p_m_rootTransB = &resultOut->m_rootTransA;
                p_m_rootTransA = &resultOut->m_rootTransB;
              }
              btPersistentManifold::refreshContactPoints((btPersistentManifold *)v22, p_m_rootTransA, p_m_rootTransB);
              v20 = v90.m128i_i32[1];
            }
            resultOut->m_manifoldPtr = 0;
          }
        }
        v25 = v20;
        if ( v20 < 0 )
        {
          if ( v90.m128i_i32[2] < 0 )
          {
            if ( v90.m128i_i32[3] && (_BYTE)v91 )
            {
              ++gNumAlignedFree;
              sAlignedFreeFunc((void *)v90.m128i_i32[3]);
            }
            LOBYTE(v91) = 1;
            v90.m128i_i64[1] = 0;
          }
          if ( v25 < 0 )
          {
            v26 = 4 * v25;
            do
            {
              if ( v26 + v90.m128i_i32[3] )
                *(_DWORD *)(v26 + v90.m128i_i32[3]) = 0;
              v26 += 4;
            }
            while ( v26 < 0 );
          }
        }
        v7 = v74;
        v12 = this;
        v90.m128i_i32[1] = 0;
        v15 = v78;
      }
      v78 = ++v15;
    }
    while ( v15 < v12->m_childCollisionAlgorithms.m_size );
    v14 = (void *)v90.m128i_i32[3];
  }
  if ( v14 && (_BYTE)v91 )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(v14);
    v12 = this;
  }
  if ( v72 )
  {
    v27 = (float *)btTransform::inverse(&v5->m_worldTransform, &v109);
    v28 = v7->m_worldTransform.m_origin.mVec128.m128_f32[0];
    v29 = v7->m_worldTransform.m_origin.mVec128.m128_f32[1];
    v30 = v7->m_worldTransform.m_origin.mVec128.m128_f32[2];
    v31 = v7->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1];
    v32 = v28 * *v27;
    v89 = v27[2];
    v79 = *v27;
    v33 = v27[9];
    v94 = *((int *)v27 + 1);
    v34 = (float)((float)(v32 + (float)(v29 * *(float *)&v94)) + (float)(v30 * v89)) + v27[12];
    v35 = v7->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2];
    *(float *)&v101.m128i_i32[1] = (float)((float)((float)(v27[5] * v29) + (float)(v27[6] * v30)) + (float)(v27[4] * v28))
                                 + v27[13];
    v36 = (float)(v27[9] * v29) + (float)(v27[10] * v30);
    v37 = v27[10];
    *(float *)&v38 = (float)(v36 + (float)(v27[8] * v28)) + v27[14];
    v39 = v27[9] * v31;
    *(float *)v101.m128i_i32 = v34;
    v40 = v7->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1];
    v101.m128i_i64[1] = v38;
    v41 = v7->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2];
    v81 = v31;
    v42 = v7->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2];
    v83 = v40;
    *(float *)&v43 = (float)((float)(v33 * v35) + (float)(v37 * v41)) + (float)(v42 * v27[8]);
    v44 = v7->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1];
    *(float *)&v87 = (float)(v39 + (float)(v27[10] * v40)) + (float)(v44 * v27[8]);
    v75 = v7->m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
    v45 = v7->m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0];
    v85 = v7->m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0];
    v46 = v27[6] * v41;
    *(float *)&v96 = (float)((float)(v27[9] * v85) + (float)(v27[10] * v75)) + (float)(v45 * v27[8]);
    v47 = (float)((float)(v27[5] * v35) + v46) + (float)(v27[4] * v42);
    v48 = v27[6] * v83;
    v95 = v47;
    v49 = (float)((float)(v27[5] * v81) + v48) + (float)(v27[4] * v44);
    v50 = v27[6] * v75;
    v92 = v49;
    *(float *)&v51 = (float)((float)(v27[5] * v85) + v50) + (float)(v27[4] * v45);
    vol.mi.mVec128.m128_f32[1] = (float)((float)(v44 * v79) + (float)(v81 * *(float *)&v94)) + (float)(v83 * v89);
    vol.mi.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT((float)((float)(v42 * v79) + (float)(v35 * *(float *)&v94)) + (float)(v41 * v89));
    vol.mx.mVec128.m128_u64[1] = LODWORD(v95);
    vol.mi.mVec128.m128_f32[0] = (float)((float)(v45 * v79) + (float)(v85 * *(float *)&v94)) + (float)(v75 * v89);
    si128 = _mm_load_si128((const __m128i *)&vol);
    v104.m128i_i64[0] = __PAIR64__(v87, v96);
    vol.mx.mVec128.m128_u64[0] = __PAIR64__(LODWORD(v92), v51);
    v98 = _mm_load_si128((const __m128i *)&vol.mx);
    v104.m128i_i64[1] = v43;
    v99 = _mm_load_si128(&v104);
    m_origin = _mm_load_si128(&v101);
    v7->m_collisionShape->getAabb(
      v7->m_collisionShape,
      (const btTransform *)&si128,
      (btVector3 *)&v90,
      (btVector3 *)&v105);
    v52 = *v72;
    vol.mi = (btVector3)_mm_load_si128(&v90);
    vol.mx = (btVector3)_mm_load_si128(&v105);
    if ( v52 )
      btDbvt::collideTV<btCompoundLeafCallback>(&vol, v52, &policy);
  }
  else
  {
    v53 = 0;
    m_size = v12->m_childCollisionAlgorithms.m_size;
    if ( m_size > 0 )
    {
      v73 = 0;
      do
      {
        btCompoundLeafCallback::ProcessChildShape(
          &policy,
          v53,
          *(btCollisionShape **)((char *)&v93[2].__vftable[1].getBoundingSphere + v73));
        v73 += 80;
        ++v53;
      }
      while ( v53 < m_size );
    }
    v7 = v74;
  }
  v54 = 0;
  v94 = this->m_childCollisionAlgorithms.m_size;
  if ( v94 > 0 )
  {
    v80 = 0;
    do
    {
      if ( this->m_childCollisionAlgorithms.m_data[v54] )
      {
        v55 = v93[2].__vftable;
        v56 = *(float *)((char *)&v55->serializeSingleShape + v80);
        v57 = *(float *)((char *)&v55->serialize + v80);
        si128 = (__m128i)v5->m_worldTransform.m_basis.m_el[0];
        v98 = (__m128i)v5->m_worldTransform.m_basis.m_el[1];
        v99 = (__m128i)v5->m_worldTransform.m_basis.m_el[2];
        v58 = (float *)((char *)v55 + v80);
        m_origin = (__m128i)v5->m_worldTransform.m_origin;
        v59 = *(float *)((char *)&v55[1].~btCollisionShape + v80);
        *(float *)v101.m128i_i32 = (float)((float)((float)(v57 * *(float *)si128.m128i_i32)
                                                 + (float)(v56 * *(float *)&si128.m128i_i32[1]))
                                         + (float)(v59 * *(float *)&si128.m128i_i32[2]))
                                 + *(float *)m_origin.m128i_i32;
        v60 = *(int *)((char *)&v55[1].getBoundingSphere + v80);
        *(float *)&v101.m128i_i32[2] = (float)((float)((float)(v59 * *(float *)&v99.m128i_i32[2])
                                                     + (float)(v57 * *(float *)v99.m128i_i32))
                                             + (float)(v56 * *(float *)&v99.m128i_i32[1]))
                                     + *(float *)&m_origin.m128i_i32[2];
        *(float *)&v61 = (float)((float)((float)(v57 * *(float *)v98.m128i_i32)
                                       + (float)(v56 * *(float *)&v98.m128i_i32[1]))
                               + (float)(v59 * *(float *)&v98.m128i_i32[2]))
                       + *(float *)&m_origin.m128i_i32[1];
        v62 = v58[6];
        v101.m128i_i32[3] = 0;
        v63 = v58[2];
        v101.m128i_i32[1] = v61;
        v64 = v58[10];
        *(float *)&v65 = (float)((float)(v63 * *(float *)v99.m128i_i32) + (float)(v62 * *(float *)&v99.m128i_i32[1]))
                       + (float)(v64 * *(float *)&v99.m128i_i32[2]);
        v86 = v58[9];
        v76 = v58[5];
        v66 = v58[1];
        v82 = v58[8];
        v84 = v58[4];
        v67 = *v58;
        v92 = (float)((float)(*v58 * *(float *)v99.m128i_i32) + (float)(v84 * *(float *)&v99.m128i_i32[1]))
            + (float)(v82 * *(float *)&v99.m128i_i32[2]);
        v95 = (float)((float)(v63 * *(float *)v98.m128i_i32) + (float)(v62 * *(float *)&v98.m128i_i32[1]))
            + (float)(v64 * *(float *)&v98.m128i_i32[2]);
        *(float *)&v96 = (float)((float)(v66 * *(float *)v98.m128i_i32) + (float)(v76 * *(float *)&v98.m128i_i32[1]))
                       + (float)(v86 * *(float *)&v98.m128i_i32[2]);
        *(float *)&v106.m128i_i32[1] = (float)((float)(v66 * *(float *)si128.m128i_i32)
                                             + (float)(v76 * *(float *)&si128.m128i_i32[1]))
                                     + (float)(v86 * *(float *)&si128.m128i_i32[2]);
        *(float *)&v106.m128i_i32[2] = (float)((float)(v63 * *(float *)si128.m128i_i32)
                                             + (float)(v62 * *(float *)&si128.m128i_i32[1]))
                                     + (float)(v64 * *(float *)&si128.m128i_i32[2]);
        *(float *)v106.m128i_i32 = (float)((float)(v67 * *(float *)si128.m128i_i32)
                                         + (float)(v84 * *(float *)&si128.m128i_i32[1]))
                                 + (float)(v82 * *(float *)&si128.m128i_i32[2]);
        v106.m128i_i32[3] = 0;
        *(float *)v107.m128i_i32 = (float)((float)(v67 * *(float *)v98.m128i_i32)
                                         + (float)(v84 * *(float *)&v98.m128i_i32[1]))
                                 + (float)(v82 * *(float *)&v98.m128i_i32[2]);
        v107.m128i_i32[1] = v96;
        v68 = _mm_load_si128(&v106);
        v107.m128i_i64[1] = LODWORD(v95);
        v109.m_basis.m_el[0] = (btVector3)v68;
        v69 = _mm_load_si128(&v107);
        *(float *)v108.m128i_i32 = v92;
        v109.m_basis.m_el[1] = (btVector3)v69;
        *(float *)&v108.m128i_i32[1] = (float)((float)(v66 * *(float *)v99.m128i_i32)
                                             + (float)(v76 * *(float *)&v99.m128i_i32[1]))
                                     + (float)(v86 * *(float *)&v99.m128i_i32[2]);
        v108.m128i_i64[1] = v65;
        v109.m_basis.m_el[2] = (btVector3)_mm_load_si128(&v108);
        v109.m_origin = (btVector3)_mm_load_si128(&v101);
        (*(void (__thiscall **)(int, btTransform *, btDbvtAabbMm *, __m128i *))(*(_DWORD *)v60 + 4))(
          v60,
          &v109,
          &vol,
          &v90);
        v7->m_collisionShape->getAabb(
          v7->m_collisionShape,
          &v7->m_worldTransform,
          (btVector3 *)&v105,
          (btVector3 *)&policy);
        v70 = 1;
        if ( vol.mi.mVec128.m128_f32[0] > *(float *)&policy.m_compoundColObj
          || *(float *)v105.m128i_i32 > *(float *)v90.m128i_i32 )
        {
          v70 = 0;
        }
        if ( vol.mi.mVec128.m128_f32[2] > *(float *)&policy.m_dispatcher
          || *(float *)&v105.m128i_i32[2] > *(float *)&v90.m128i_i32[2] )
        {
          v70 = 0;
        }
        if ( vol.mi.mVec128.m128_f32[1] > *(float *)&policy.m_otherObj
          || *(float *)&v105.m128i_i32[1] > *(float *)&v90.m128i_i32[1]
          || !v70 )
        {
          v71 = this->m_childCollisionAlgorithms.m_data[v54];
          ((void (__thiscall *)(btCollisionAlgorithm *, _DWORD))v71->~btCollisionAlgorithm)(v71, 0);
          this->m_dispatcher->freeCollisionAlgorithm(this->m_dispatcher, this->m_childCollisionAlgorithms.m_data[v54]);
          this->m_childCollisionAlgorithms.m_data[v54] = 0;
        }
      }
      v80 += 80;
      ++v54;
    }
    while ( v54 < v94 );
  }
}
