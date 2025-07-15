void __userpurge btConvexPlaneCollisionAlgorithm::collideSingleContact(
        btCollisionObject *body0@<eax>,
        btCollisionObject *body1@<ecx>,
        btConvexPlaneCollisionAlgorithm *this,
        btMatrix3x3 *perturbeRot,
        btManifoldResult *dispatchInfo,
        btManifoldResult *resultOut)
{
  btCollisionObject *v7; // eax
  btCollisionShape *m_collisionShape; // ebx
  float *v9; // edi
  float *p_m_worldTransform; // esi
  float *v11; // eax
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm7_4
  float v16; // xmm4_4
  float v17; // xmm6_4
  float v18; // xmm1_4
  float v19; // xmm6_4
  float v20; // xmm1_4
  float v21; // xmm6_4
  float v22; // xmm7_4
  float v23; // xmm6_4
  float v24; // xmm1_4
  float v25; // xmm6_4
  unsigned int v26; // xmm4_4
  float v27; // xmm5_4
  unsigned int v28; // xmm2_4
  unsigned int v29; // xmm3_4
  float *v30; // eax
  float v31; // xmm3_4
  float v32; // xmm4_4
  float v33; // xmm0_4
  float v34; // xmm5_4
  float v35; // xmm1_4
  float v36; // xmm7_4
  float v37; // xmm2_4
  float v38; // xmm6_4
  float v39; // xmm7_4
  float v40; // xmm6_4
  float v41; // xmm7_4
  float v42; // xmm6_4
  float v43; // xmm7_4
  float v44; // xmm6_4
  float v45; // xmm7_4
  void (__thiscall *v46)(btCollisionShape *); // edx
  float v47; // xmm0_4
  float v48; // xmm3_4
  float v49; // xmm4_4
  float v50; // xmm0_4
  float v51; // xmm7_4
  float v52; // xmm1_4
  float v53; // xmm5_4
  float v54; // xmm4_4
  btPersistentManifold *m_manifoldPtr; // eax
  float v56; // xmm2_4
  float v57; // xmm3_4
  float v58; // xmm1_4
  float v59; // xmm0_4
  float v60; // xmm5_4
  float v61; // xmm4_4
  float m_contactBreakingThreshold; // xmm1_4
  float v63; // xmm2_4
  float v64; // xmm1_4
  void (__thiscall *addContactPoint)(struct btManifoldResult *, const btVector3 *, const btVector3 *, float); // edx
  float v66; // xmm4_4
  float v67; // xmm3_4
  float v68; // xmm4_4
  float v69; // xmm7_4
  float v70; // xmm3_4
  float v71; // xmm2_4
  __m128i v72; // xmm0
  float v73; // [esp+3B4h] [ebp-100h]
  float v74; // [esp+3B4h] [ebp-100h]
  float v75; // [esp+3B8h] [ebp-FCh]
  float v76; // [esp+3BCh] [ebp-F8h]
  float v77; // [esp+3C0h] [ebp-F4h]
  float v78; // [esp+3C4h] [ebp-F0h]
  float v79; // [esp+3C4h] [ebp-F0h]
  unsigned int v80; // [esp+3C8h] [ebp-ECh]
  float v81; // [esp+3C8h] [ebp-ECh]
  float v82; // [esp+3D0h] [ebp-E4h]
  float v83; // [esp+3D0h] [ebp-E4h]
  btTransform m_worldTransform; // [esp+3D4h] [ebp-E0h] BYREF
  __m128i v85; // [esp+414h] [ebp-A0h] BYREF
  float v86; // [esp+424h] [ebp-90h] BYREF
  float v87; // [esp+428h] [ebp-8Ch]
  float v88; // [esp+42Ch] [ebp-88h]
  int v89; // [esp+430h] [ebp-84h]
  float v90; // [esp+434h] [ebp-80h]
  float v91; // [esp+438h] [ebp-7Ch]
  float v92; // [esp+43Ch] [ebp-78h]
  float v93; // [esp+440h] [ebp-74h]
  float v94; // [esp+444h] [ebp-70h]
  float v95; // [esp+448h] [ebp-6Ch]
  float v96; // [esp+44Ch] [ebp-68h]
  float v97; // [esp+450h] [ebp-64h]
  float v98; // [esp+454h] [ebp-60h]
  float v99; // [esp+458h] [ebp-5Ch]
  float v100; // [esp+45Ch] [ebp-58h]
  float v101; // [esp+460h] [ebp-54h]
  btTransform v102; // [esp+464h] [ebp-50h] BYREF
  float v103; // [esp+4A4h] [ebp-10h] BYREF
  float v104; // [esp+4A8h] [ebp-Ch]
  float v105; // [esp+4ACh] [ebp-8h]

  v7 = body1;
  if ( this->m_isSwapped )
    body1 = body0;
  else
    v7 = body0;
  m_collisionShape = v7->m_collisionShape;
  v9 = (float *)body1->m_collisionShape;
  m_worldTransform = v7->m_worldTransform;
  p_m_worldTransform = (float *)&body1->m_worldTransform;
  v11 = (float *)btTransform::inverse(&body1->m_worldTransform, &v102);
  v12 = v11[1];
  v13 = *v11;
  v14 = v11[2];
  v15 = v11[6];
  v86 = (float)((float)((float)(m_worldTransform.m_origin.mVec128.m128_f32[0] * *v11)
                      + (float)(m_worldTransform.m_origin.mVec128.m128_f32[1] * v12))
              + (float)(m_worldTransform.m_origin.mVec128.m128_f32[2] * v14))
      + v11[12];
  v16 = m_worldTransform.m_origin.mVec128.m128_f32[0] * v11[8];
  v87 = (float)((float)((float)(v11[5] * m_worldTransform.m_origin.mVec128.m128_f32[1])
                      + (float)(v15 * m_worldTransform.m_origin.mVec128.m128_f32[2]))
              + (float)(m_worldTransform.m_origin.mVec128.m128_f32[0] * v11[4]))
      + v11[13];
  v17 = v11[10];
  v88 = (float)((float)((float)(v11[9] * m_worldTransform.m_origin.mVec128.m128_f32[1])
                      + (float)(v17 * m_worldTransform.m_origin.mVec128.m128_f32[2]))
              + v16)
      + v11[14];
  v18 = (float)((float)(v11[9] * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2])
              + (float)(v17 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]))
      + (float)(v11[8] * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]);
  v19 = v11[10] * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1];
  v91 = v18;
  v20 = (float)((float)(v11[9] * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]) + v19)
      + (float)(v11[8] * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1]);
  v21 = v11[10] * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
  v100 = v20;
  v82 = (float)((float)(v11[9] * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0]) + v21)
      + (float)(v11[8] * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0]);
  v22 = v11[4];
  v23 = v11[6] * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1];
  v99 = (float)((float)(v11[5] * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2])
              + (float)(v11[6] * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]))
      + (float)(m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2] * v22);
  v24 = (float)((float)(v11[5] * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]) + v23)
      + (float)(m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v11[4]);
  v25 = v11[6] * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
  v94 = v24;
  v96 = (float)((float)(v11[5] * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0]) + v25)
      + (float)(v22 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0]);
  v90 = (float)((float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v12)
              + (float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] * v14))
      + (float)(m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2] * v13);
  v101 = (float)((float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v12)
               + (float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] * v14))
       + (float)(m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v13);
  v98 = (float)((float)(v13 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0])
              + (float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] * v12))
      + (float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0] * v14);
  btMatrix3x3::setRotation(perturbeRot, (int)&v102);
  *(float *)&v26 = (float)((float)(v102.m_basis.m_el[0].mVec128.m128_f32[2]
                                 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0])
                         + (float)(v102.m_basis.m_el[1].mVec128.m128_f32[2]
                                 * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]))
                 + (float)(v102.m_basis.m_el[2].mVec128.m128_f32[2]
                         * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]);
  v27 = (float)((float)(v102.m_basis.m_el[0].mVec128.m128_f32[1] * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0])
              + (float)(v102.m_basis.m_el[1].mVec128.m128_f32[1] * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]))
      + (float)(v102.m_basis.m_el[2].mVec128.m128_f32[1] * m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]);
  *(float *)&v80 = (float)((float)(v102.m_basis.m_el[0].mVec128.m128_f32[2]
                                 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0])
                         + (float)(v102.m_basis.m_el[1].mVec128.m128_f32[2]
                                 * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]))
                 + (float)(v102.m_basis.m_el[2].mVec128.m128_f32[2]
                         * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2]);
  v78 = (float)((float)(v102.m_basis.m_el[0].mVec128.m128_f32[1] * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0])
              + (float)(v102.m_basis.m_el[1].mVec128.m128_f32[1] * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]))
      + (float)(v102.m_basis.m_el[2].mVec128.m128_f32[1] * m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2]);
  *(float *)&v28 = (float)((float)(v102.m_basis.m_el[1].mVec128.m128_f32[1]
                                 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1])
                         + (float)(v102.m_basis.m_el[2].mVec128.m128_f32[1]
                                 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]))
                 + (float)(v102.m_basis.m_el[0].mVec128.m128_f32[1]
                         * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0]);
  m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] = (float)((float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0]
                                                                       * v102.m_basis.m_el[0].mVec128.m128_f32[0])
                                                               + (float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1]
                                                                       * v102.m_basis.m_el[1].mVec128.m128_f32[0]))
                                                       + (float)(m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2]
                                                               * v102.m_basis.m_el[2].mVec128.m128_f32[0]);
  *(float *)&v29 = (float)((float)(v102.m_basis.m_el[1].mVec128.m128_f32[0]
                                 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1])
                         + (float)(v102.m_basis.m_el[2].mVec128.m128_f32[0]
                                 * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]))
                 + (float)(v102.m_basis.m_el[0].mVec128.m128_f32[0]
                         * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0]);
  m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] = v78;
  m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2] = (float)((float)(v102.m_basis.m_el[1].mVec128.m128_f32[2]
                                                                       * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1])
                                                               + (float)(v102.m_basis.m_el[2].mVec128.m128_f32[2]
                                                                       * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2]))
                                                       + (float)(v102.m_basis.m_el[0].mVec128.m128_f32[2]
                                                               * m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0]);
  m_worldTransform.m_basis.m_el[1].mVec128.m128_u64[1] = v80;
  m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0] = __PAIR64__(v28, v29);
  m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[3] = 0;
  m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0] = (float)((float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0]
                                                                       * v102.m_basis.m_el[0].mVec128.m128_f32[0])
                                                               + (float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]
                                                                       * v102.m_basis.m_el[1].mVec128.m128_f32[0]))
                                                       + (float)(m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]
                                                               * v102.m_basis.m_el[2].mVec128.m128_f32[0]);
  m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] = v27;
  m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[1] = v26;
  v30 = (float *)btTransform::inverse(&m_worldTransform, &v102);
  v31 = p_m_worldTransform[10];
  v32 = p_m_worldTransform[6];
  v33 = p_m_worldTransform[2];
  v79 = p_m_worldTransform[5];
  v76 = p_m_worldTransform[9];
  v34 = (float)((float)(v30[9] * v32) + (float)(v30[10] * v31)) + (float)(v33 * v30[8]);
  v35 = p_m_worldTransform[1];
  v73 = v30[10] * p_m_worldTransform[8];
  v36 = v30[9];
  v77 = p_m_worldTransform[8];
  v97 = (float)((float)(v36 * v79) + (float)(v30[10] * v76)) + (float)(v35 * v30[8]);
  v75 = p_m_worldTransform[4];
  v37 = *p_m_worldTransform;
  v38 = (float)(v73 + (float)(v36 * v75)) + (float)(*p_m_worldTransform * v30[8]);
  v39 = v30[6];
  v95 = v38;
  v40 = (float)((float)(v30[5] * v32) + (float)(v39 * v31)) + (float)(v33 * v30[4]);
  v41 = v30[6] * v76;
  v93 = v40;
  v42 = (float)((float)(v30[5] * v79) + v41) + (float)(v35 * v30[4]);
  v43 = v30[5] * v75;
  v92 = v42;
  v44 = (float)((float)(v30[6] * v77) + v43) + (float)(v37 * v30[4]);
  v81 = v30[2];
  v45 = v30[1];
  v74 = (float)((float)(v33 * *v30) + (float)(v32 * v45)) + (float)(v31 * v81);
  v46 = m_collisionShape->__vftable[1].~btCollisionShape;
  v47 = -v9[12];
  v48 = -v9[13];
  v49 = -v9[14];
  *(float *)v85.m128i_i32 = (float)((float)(v48
                                          * (float)((float)((float)(v35 * *v30) + (float)(v79 * v45))
                                                  + (float)(v76 * v81)))
                                  + (float)(v49 * v74))
                          + (float)(v47 * (float)((float)((float)(v37 * *v30) + (float)(v75 * v45)) + (float)(v77 * v81)));
  *(float *)&v85.m128i_i32[2] = (float)((float)(v47 * v95) + (float)(v48 * v97)) + (float)(v49 * v34);
  *(float *)&v85.m128i_i32[1] = (float)((float)(v48 * v92) + (float)(v49 * v93)) + (float)(v47 * v44);
  v85.m128i_i32[3] = 0;
  ((void (__thiscall *)(btCollisionShape *, float *, __m128i *))v46)(m_collisionShape, &v103, &v85);
  v50 = (float)((float)((float)(v104 * v101) + (float)(v105 * v90)) + (float)(v103 * v98)) + v86;
  v51 = v9[12];
  v52 = (float)((float)((float)(v104 * v94) + (float)(v105 * v99)) + (float)(v103 * v96)) + v87;
  v53 = v9[13];
  v54 = v9[14];
  m_manifoldPtr = this->m_manifoldPtr;
  v56 = (float)((float)((float)(v52 * v53)
                      + (float)((float)((float)((float)((float)(v104 * v100) + (float)(v105 * v91)) + (float)(v103 * v82))
                                      + v88)
                              * v54))
              + (float)(v51 * v50))
      - v9[16];
  v57 = (float)((float)((float)((float)(v104 * v100) + (float)(v105 * v91)) + (float)(v103 * v82)) + v88)
      - (float)(v54 * v56);
  v58 = v52 - (float)(v53 * v56);
  v59 = v50 - (float)(v51 * v56);
  v60 = p_m_worldTransform[5];
  *(float *)v85.m128i_i32 = (float)((float)((float)(p_m_worldTransform[2] * v57) + (float)(p_m_worldTransform[1] * v58))
                                  + (float)(v59 * *p_m_worldTransform))
                          + p_m_worldTransform[12];
  *(float *)&v85.m128i_i32[1] = (float)((float)((float)(p_m_worldTransform[6] * v57) + (float)(v60 * v58))
                                      + (float)(p_m_worldTransform[4] * v59))
                              + p_m_worldTransform[13];
  v61 = (float)((float)(p_m_worldTransform[10] * v57) + (float)(p_m_worldTransform[9] * v58))
      + (float)(p_m_worldTransform[8] * v59);
  m_contactBreakingThreshold = m_manifoldPtr->m_contactBreakingThreshold;
  v83 = v56;
  *(float *)&v85.m128i_i32[2] = v61 + p_m_worldTransform[14];
  v85.m128i_i32[3] = 0;
  dispatchInfo->m_manifoldPtr = m_manifoldPtr;
  if ( m_contactBreakingThreshold > v56 )
  {
    v63 = v9[13];
    v64 = v9[14];
    addContactPoint = dispatchInfo->addContactPoint;
    v66 = p_m_worldTransform[6];
    v86 = (float)((float)(p_m_worldTransform[1] * v63) + (float)(p_m_worldTransform[2] * v64))
        + (float)(v51 * *p_m_worldTransform);
    v67 = (float)(p_m_worldTransform[5] * v63) + (float)(v66 * v64);
    v68 = v51 * p_m_worldTransform[4];
    v69 = v51 * p_m_worldTransform[8];
    v87 = v67 + v68;
    v70 = p_m_worldTransform[9] * v63;
    v71 = p_m_worldTransform[10] * v64;
    v89 = 0;
    v72 = _mm_load_si128(&v85);
    v88 = (float)(v70 + v71) + v69;
    v85 = v72;
    ((void (__stdcall *)(float *, __m128i *, _DWORD))addContactPoint)(&v86, &v85, LODWORD(v83));
  }
}
