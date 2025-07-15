void __userpurge btSequentialImpulseConstraintSolver::setupContactConstraint(
        btSolverConstraint *solverConstraint@<esi>,
        btManifoldPoint *cp@<eax>,
        btVector3 *rel_pos1@<ecx>,
        btSequentialImpulseConstraintSolver *this,
        btCollisionObject *colObj0,
        const btContactSolverInfo *colObj1,
        btVector3 *infoGlobal,
        btVector3 *vel,
        float *rel_vel,
        btVector3 *relaxation,
        btVector3 *rel_pos2)
{
  btSequentialImpulseConstraintSolver *v12; // ecx
  btCollisionObject *v13; // edx
  unsigned int v14; // xmm0_4
  float v15; // xmm7_4
  float v16; // xmm5_4
  float v17; // xmm6_4
  float v18; // xmm4_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm5_4
  float v23; // xmm1_4
  float v24; // xmm7_4
  float v25; // xmm3_4
  float v26; // xmm5_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm5_4
  float v32; // xmm6_4
  float v33; // xmm1_4
  float v34; // xmm5_4
  float v35; // xmm6_4
  float v36; // xmm6_4
  double m_combinedFriction; // st7
  __m128 v38; // xmm1
  float m_distance1; // xmm4_4
  float v40; // xmm4_4
  __m128 m_combinedRestitution_low; // xmm1
  __m128 m_appliedImpulse_low; // xmm1
  btSimdScalar v43; // xmm1
  float v44; // xmm3_4
  float v45; // xmm1_4
  float v46; // xmm6_4
  float v47; // xmm3_4
  float v48; // xmm5_4
  float v49; // xmm4_4
  float v50; // xmm3_4
  float v51; // xmm5_4
  float v52; // xmm1_4
  float v53; // xmm4_4
  float v54; // xmm3_4
  float v55; // xmm3_4
  float v56; // xmm4_4
  float v57; // xmm7_4
  float v58; // xmm6_4
  float v59; // xmm1_4
  float v60; // xmm7_4
  float v61; // xmm3_4
  float v62; // xmm4_4
  float v63; // xmm5_4
  float v64; // xmm6_4
  float v65; // xmm7_4
  float v66; // xmm3_4
  float v67; // xmm5_4
  float *p_m_orderTmpConstraintPool; // eax
  float *p_m_ownsMemory; // ecx
  float v70; // xmm1_4
  float *m128_f32; // eax
  float *v72; // edx
  float v73; // xmm3_4
  float v74; // xmm1_4
  float m_jacDiagABInv; // xmm2_4
  float v76; // xmm1_4
  float v77; // xmm3_4
  float v78; // [esp+A0h] [ebp-38h]
  float v79; // [esp+A0h] [ebp-38h]
  float v80; // [esp+A4h] [ebp-34h]
  unsigned __int64 v81; // [esp+A8h] [ebp-30h]
  btVector3 v82; // [esp+A8h] [ebp-30h]
  unsigned __int64 v83; // [esp+A8h] [ebp-30h]
  unsigned __int64 v84; // [esp+A8h] [ebp-30h]
  __int64 v85; // [esp+A8h] [ebp-30h]
  __int64 v86; // [esp+A8h] [ebp-30h]
  unsigned __int64 v87; // [esp+A8h] [ebp-30h]
  unsigned int v88; // [esp+B0h] [ebp-28h]
  float v89; // [esp+B0h] [ebp-28h]
  unsigned __int64 v90; // [esp+B0h] [ebp-28h]
  unsigned __int64 v91; // [esp+B0h] [ebp-28h]
  unsigned __int64 v92; // [esp+B0h] [ebp-28h]
  __int64 v93; // [esp+B8h] [ebp-20h] BYREF
  unsigned __int64 v94; // [esp+C0h] [ebp-18h]
  __int64 v95; // [esp+C8h] [ebp-10h] BYREF
  unsigned __int64 v96; // [esp+D0h] [ebp-8h]

  v12 = ((int)this[1].m_tmpConstraintSizesPool.m_data & 2) != 0 ? this : 0;
  v13 = (colObj0->m_internalType & 2) != 0 ? colObj0 : 0;
  *(float *)&v81 = cp->m_positionWorldOnA.mVec128.m128_f32[0] - *(float *)&this->m_orderTmpConstraintPool.m_allocator;
  *((float *)&v81 + 1) = cp->m_positionWorldOnA.mVec128.m128_f32[1] - *(float *)&this->m_orderTmpConstraintPool.m_size;
  *(float *)&v14 = cp->m_positionWorldOnA.mVec128.m128_f32[2] - *(float *)&this->m_orderTmpConstraintPool.m_capacity;
  rel_pos1->mVec128.m128_u64[0] = v81;
  rel_pos1->mVec128.m128_u64[1] = v14;
  *(float *)&v81 = cp->m_positionWorldOnB.mVec128.m128_f32[0] - colObj0->m_worldTransform.m_origin.mVec128.m128_f32[0];
  *((float *)&v81 + 1) = cp->m_positionWorldOnB.mVec128.m128_f32[1]
                       - colObj0->m_worldTransform.m_origin.mVec128.m128_f32[1];
  *(float *)&v88 = cp->m_positionWorldOnB.mVec128.m128_f32[2] - colObj0->m_worldTransform.m_origin.mVec128.m128_f32[2];
  relaxation->mVec128.m128_u64[0] = v81;
  relaxation->mVec128.m128_u64[1] = v88;
  v15 = rel_pos1->mVec128.m128_f32[2];
  v16 = cp->m_normalWorldOnB.mVec128.m128_f32[2];
  v17 = rel_pos1->mVec128.m128_f32[1];
  v18 = cp->m_normalWorldOnB.mVec128.m128_f32[0];
  *(_DWORD *)rel_vel = clear_value;
  v19 = (float)(v17 * v16) - (float)(v15 * cp->m_normalWorldOnB.mVec128.m128_f32[1]);
  v20 = (float)(v18 * v15) - (float)(rel_pos1->mVec128.m128_f32[0] * v16);
  v21 = (float)(rel_pos1->mVec128.m128_f32[0] * cp->m_normalWorldOnB.mVec128.m128_f32[1]) - (float)(v18 * v17);
  if ( v12 )
  {
    v82.mVec128.m128_f32[1] = *(float *)&v12[4].m_orderFrictionConstraintPool.m_ownsMemory
                            * (float)((float)((float)(*(float *)&v12[2].m_tmpSolverNonContactConstraintPool.m_ownsMemory
                                                    * v21)
                                            + (float)(*(float *)&v12[2].m_tmpSolverNonContactConstraintPool.m_data * v20))
                                    + (float)(*(float *)&v12[2].m_tmpSolverNonContactConstraintPool.m_capacity * v19));
    v82.mVec128.m128_f32[0] = (float)((float)((float)(*(float *)&v12[2].m_tmpSolverNonContactConstraintPool.m_allocator
                                                    * v21)
                                            + (float)(*(float *)&v12[2].m_tmpSolverContactConstraintPool.m_ownsMemory
                                                    * v20))
                                    + (float)(*(float *)&v12[2].m_tmpSolverContactConstraintPool.m_data * v19))
                            * *(float *)&v12[4].m_orderFrictionConstraintPool.m_data;
    v82.mVec128.m128_f32[2] = *(float *)&v12[4].m_tmpConstraintSizesPool.m_allocator
                            * (float)((float)((float)(*(float *)&v12[2].m_tmpSolverContactFrictionConstraintPool.m_data
                                                    * v21)
                                            + (float)(*(float *)&v12[2].m_tmpSolverContactFrictionConstraintPool.m_capacity
                                                    * v20))
                                    + (float)(*(float *)&v12[2].m_tmpSolverContactFrictionConstraintPool.m_size * v19));
  }
  else
  {
    v82.mVec128.m128_u64[0] = 0;
    v82.mVec128.m128_i32[2] = 0;
  }
  v82.mVec128.m128_i32[3] = 0;
  solverConstraint->m_angularComponentA = (btVector3)v82.mVec128;
  v22 = cp->m_normalWorldOnB.mVec128.m128_f32[2];
  if ( v13 )
  {
    v23 = -(float)((float)(relaxation->mVec128.m128_f32[1] * v22)
                 - (float)(relaxation->mVec128.m128_f32[2] * cp->m_normalWorldOnB.mVec128.m128_f32[1]));
    v24 = -(float)((float)(relaxation->mVec128.m128_f32[0] * cp->m_normalWorldOnB.mVec128.m128_f32[1])
                 - (float)(cp->m_normalWorldOnB.mVec128.m128_f32[0] * relaxation->mVec128.m128_f32[1]));
    v25 = -(float)((float)(cp->m_normalWorldOnB.mVec128.m128_f32[0] * relaxation->mVec128.m128_f32[2])
                 - (float)(relaxation->mVec128.m128_f32[0] * v22));
    *(float *)&v83 = v13[2].m_worldTransform.m_origin.mVec128.m128_f32[0]
                   * (float)((float)((float)(*((float *)&v13[1].__vftable + 2) * v24)
                                   + (float)(*((float *)&v13[1].__vftable + 1) * v25))
                           + (float)(*(float *)&v13[1].__vftable * v23));
    *((float *)&v83 + 1) = v13[2].m_worldTransform.m_origin.mVec128.m128_f32[1]
                         * (float)((float)((float)(v13[1].m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[2] * v24)
                                         + (float)(v13[1].m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[1] * v25))
                                 + (float)(v13[1].m_worldTransform.m_basis.m_el[0].mVec128.m128_f32[0] * v23));
    v89 = v13[2].m_worldTransform.m_origin.mVec128.m128_f32[2]
        * (float)((float)((float)(v13[1].m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v24)
                        + (float)(v13[1].m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * v25))
                + (float)(v23 * v13[1].m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0]));
  }
  else
  {
    v83 = 0;
    v89 = 0.0;
  }
  solverConstraint->m_angularComponentB.mVec128.m128_u64[0] = v83;
  solverConstraint->m_angularComponentB.mVec128.m128_u64[1] = LODWORD(v89);
  v26 = 0.0;
  v27 = 0.0;
  if ( v12 )
    v26 = (float)((float)((float)(cp->m_normalWorldOnB.mVec128.m128_f32[2]
                                * (float)((float)(solverConstraint->m_angularComponentA.mVec128.m128_f32[0]
                                                * rel_pos1->mVec128.m128_f32[1])
                                        - (float)(solverConstraint->m_angularComponentA.mVec128.m128_f32[1]
                                                * rel_pos1->mVec128.m128_f32[0])))
                        + (float)(cp->m_normalWorldOnB.mVec128.m128_f32[1]
                                * (float)((float)(solverConstraint->m_angularComponentA.mVec128.m128_f32[2]
                                                * rel_pos1->mVec128.m128_f32[0])
                                        - (float)(solverConstraint->m_angularComponentA.mVec128.m128_f32[0]
                                                * rel_pos1->mVec128.m128_f32[2]))))
                + (float)((float)((float)(solverConstraint->m_angularComponentA.mVec128.m128_f32[1]
                                        * rel_pos1->mVec128.m128_f32[2])
                                - (float)(solverConstraint->m_angularComponentA.mVec128.m128_f32[2]
                                        * rel_pos1->mVec128.m128_f32[1]))
                        * cp->m_normalWorldOnB.mVec128.m128_f32[0]))
        + *(float *)&v12[2].m_orderFrictionConstraintPool.m_data;
  if ( v13 )
  {
    v28 = solverConstraint->m_angularComponentB.mVec128.m128_f32[1];
    v29 = relaxation->mVec128.m128_f32[2];
    v30 = relaxation->mVec128.m128_f32[1];
    *(float *)&v95 = -solverConstraint->m_angularComponentB.mVec128.m128_f32[0];
    v27 = (float)((float)((float)(cp->m_normalWorldOnB.mVec128.m128_f32[2]
                                * (float)((float)(v30 * *(float *)&v95)
                                        - (float)((float)-v28 * relaxation->mVec128.m128_f32[0])))
                        + (float)(cp->m_normalWorldOnB.mVec128.m128_f32[1]
                                * (float)((float)((float)-solverConstraint->m_angularComponentB.mVec128.m128_f32[2]
                                                * relaxation->mVec128.m128_f32[0])
                                        - (float)(v29 * *(float *)&v95))))
                + (float)((float)((float)((float)-v28 * v29)
                                - (float)((float)-solverConstraint->m_angularComponentB.mVec128.m128_f32[2] * v30))
                        * cp->m_normalWorldOnB.mVec128.m128_f32[0]))
        + v13[1].m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_f32[0];
  }
  solverConstraint->m_jacDiagABInv = *(float *)&clear_value / (float)(v27 + v26);
  solverConstraint->m_contactNormal = cp->m_normalWorldOnB;
  v31 = rel_pos1->mVec128.m128_f32[1];
  v32 = rel_pos1->mVec128.m128_f32[2];
  *(float *)&v84 = (float)(cp->m_normalWorldOnB.mVec128.m128_f32[2] * v31)
                 - (float)(cp->m_normalWorldOnB.mVec128.m128_f32[1] * v32);
  *(float *)&v90 = (float)(cp->m_normalWorldOnB.mVec128.m128_f32[1] * rel_pos1->mVec128.m128_f32[0])
                 - (float)(cp->m_normalWorldOnB.mVec128.m128_f32[0] * v31);
  *((float *)&v84 + 1) = (float)(cp->m_normalWorldOnB.mVec128.m128_f32[0] * v32)
                       - (float)(cp->m_normalWorldOnB.mVec128.m128_f32[2] * rel_pos1->mVec128.m128_f32[0]);
  solverConstraint->m_relpos1CrossNormal.mVec128.m128_u64[0] = v84;
  HIDWORD(v90) = 0;
  solverConstraint->m_relpos1CrossNormal.mVec128.m128_u64[1] = v90;
  v33 = -cp->m_normalWorldOnB.mVec128.m128_f32[1];
  v78 = relaxation->mVec128.m128_f32[1];
  v34 = -cp->m_normalWorldOnB.mVec128.m128_f32[0];
  *(float *)&v91 = (float)(v33 * relaxation->mVec128.m128_f32[0]) - (float)(v78 * v34);
  HIDWORD(v91) = 0;
  solverConstraint->m_relpos2CrossNormal.mVec128.m128_u64[0] = __PAIR64__(
                                                                 (float)(relaxation->mVec128.m128_f32[2] * v34)
                                                               - (float)((float)-cp->m_normalWorldOnB.mVec128.m128_f32[2]
                                                                       * relaxation->mVec128.m128_f32[0]),
                                                                 (float)((float)-cp->m_normalWorldOnB.mVec128.m128_f32[2]
                                                                       * v78)
                                                               - (float)(v33 * relaxation->mVec128.m128_f32[2]));
  solverConstraint->m_relpos2CrossNormal.mVec128.m128_u64[1] = v91;
  HIDWORD(v91) = 0;
  if ( v12 )
  {
    v35 = rel_pos1->mVec128.m128_f32[2];
    *(float *)&v85 = *(float *)&v12[2].m_orderTmpConstraintPool.m_allocator
                   + (float)((float)(*(float *)&v12[2].m_orderFrictionConstraintPool.m_allocator * v35)
                           - (float)(*(float *)&v12[2].m_orderFrictionConstraintPool.m_size
                                   * rel_pos1->mVec128.m128_f32[1]));
    *((float *)&v85 + 1) = *(float *)&v12[2].m_orderTmpConstraintPool.m_size
                         + (float)((float)(*(float *)&v12[2].m_orderFrictionConstraintPool.m_size
                                         * rel_pos1->mVec128.m128_f32[0])
                                 - (float)(*(float *)&v12[2].m_orderTmpConstraintPool.m_ownsMemory * v35));
    *(float *)&v91 = *(float *)&v12[2].m_orderTmpConstraintPool.m_capacity
                   + (float)((float)(*(float *)&v12[2].m_orderTmpConstraintPool.m_ownsMemory
                                   * rel_pos1->mVec128.m128_f32[1])
                           - (float)(*(float *)&v12[2].m_orderFrictionConstraintPool.m_allocator
                                   * rel_pos1->mVec128.m128_f32[0]));
  }
  else
  {
    v85 = 0;
    LODWORD(v91) = 0;
  }
  v93 = v85;
  v94 = v91;
  HIDWORD(v91) = 0;
  if ( v13 )
  {
    v36 = relaxation->mVec128.m128_f32[2];
    *(float *)&v86 = v13[1].m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0]
                   + (float)((float)(v13[1].m_worldTransform.m_origin.mVec128.m128_f32[1] * v36)
                           - (float)(v13[1].m_worldTransform.m_origin.mVec128.m128_f32[2]
                                   * relaxation->mVec128.m128_f32[1]));
    *((float *)&v86 + 1) = v13[1].m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]
                         + (float)((float)(v13[1].m_worldTransform.m_origin.mVec128.m128_f32[2]
                                         * relaxation->mVec128.m128_f32[0])
                                 - (float)(v13[1].m_worldTransform.m_origin.mVec128.m128_f32[0] * v36));
    *(float *)&v91 = v13[1].m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2]
                   + (float)((float)(v13[1].m_worldTransform.m_origin.mVec128.m128_f32[0]
                                   * relaxation->mVec128.m128_f32[1])
                           - (float)(v13[1].m_worldTransform.m_origin.mVec128.m128_f32[1]
                                   * relaxation->mVec128.m128_f32[0]));
  }
  else
  {
    v86 = 0;
    LODWORD(v91) = 0;
  }
  v95 = v86;
  v96 = v91;
  *(float *)&v87 = *(float *)&v93 - *(float *)&v86;
  *((float *)&v87 + 1) = *((float *)&v93 + 1) - *((float *)&v95 + 1);
  *(float *)&v92 = *(float *)&v94 - *(float *)&v91;
  infoGlobal->mVec128.m128_u64[0] = v87;
  HIDWORD(v92) = 0;
  infoGlobal->mVec128.m128_u64[1] = v92;
  m_combinedFriction = cp->m_combinedFriction;
  v38 = (__m128)cp->m_normalWorldOnB.mVec128.m128_u32[2];
  m_distance1 = cp->m_distance1;
  vel->mVec128.m128_f32[0] = (float)((float)(v38.m128_f32[0] * infoGlobal->mVec128.m128_f32[2])
                                   + (float)(cp->m_normalWorldOnB.mVec128.m128_f32[1] * infoGlobal->mVec128.m128_f32[1]))
                           + (float)(cp->m_normalWorldOnB.mVec128.m128_f32[0] * infoGlobal->mVec128.m128_f32[0]);
  v40 = m_distance1 + colObj1->m_linearSlop;
  solverConstraint->m_friction = m_combinedFriction;
  v79 = v40;
  if ( cp->m_lifeTime > colObj1->m_restingContactRestitutionThreshold
    || (m_combinedRestitution_low = (__m128)LODWORD(cp->m_combinedRestitution),
        m_combinedRestitution_low.m128_f32[0] = m_combinedRestitution_low.m128_f32[0] * vel->mVec128.m128_f32[0],
        v38 = _mm_xor_ps(m_combinedRestitution_low, (__m128)0x80000000),
        v80 = v38.m128_f32[0],
        v38.m128_f32[0] <= 0.0) )
  {
    v80 = 0.0;
  }
  if ( (colObj1->m_solverMode & 4) != 0 )
  {
    m_appliedImpulse_low = (__m128)LODWORD(cp->m_appliedImpulse);
    m_appliedImpulse_low.m128_f32[0] = m_appliedImpulse_low.m128_f32[0] * colObj1->m_warmstartingFactor;
    v43.m_vec128 = _mm_shuffle_ps(m_appliedImpulse_low, m_appliedImpulse_low, 0);
    solverConstraint->m_appliedImpulse = (btSimdScalar)v43.m_vec128;
    if ( v12 )
    {
      v44 = *(float *)&v12[2].m_orderFrictionConstraintPool.m_data;
      v45 = (float)(solverConstraint->m_contactNormal.mVec128.m128_f32[0] * v44)
          * *(float *)&v12[2].m_tmpConstraintSizesPool.m_capacity;
      v46 = solverConstraint->m_contactNormal.mVec128.m128_f32[2] * v44;
      v47 = *(float *)&v12[2].m_tmpConstraintSizesPool.m_data
          * (float)(solverConstraint->m_contactNormal.mVec128.m128_f32[1] * v44);
      v48 = v45;
      v43.m_vec128 = (__m128)solverConstraint->m_appliedImpulse.m_vec128.m128_u32[0];
      v49 = *(float *)&v12[2].m_tmpConstraintSizesPool.m_ownsMemory * v46;
      if ( *(float *)&v12[2].m_orderFrictionConstraintPool.m_data != 0.0 )
      {
        *(float *)&v12[4].m_orderTmpConstraintPool.m_size = (float)(v47 * v43.m_vec128.m128_f32[0])
                                                          + *(float *)&v12[4].m_orderTmpConstraintPool.m_size;
        *(float *)&v12[4].m_orderTmpConstraintPool.m_capacity = (float)(v49 * v43.m_vec128.m128_f32[0])
                                                              + *(float *)&v12[4].m_orderTmpConstraintPool.m_capacity;
        *(float *)&v12[4].m_orderTmpConstraintPool.m_allocator = (float)(v48 * v43.m_vec128.m128_f32[0])
                                                               + *(float *)&v12[4].m_orderTmpConstraintPool.m_allocator;
        v50 = (float)((float)(v43.m_vec128.m128_f32[0] * *(float *)&v12[4].m_orderFrictionConstraintPool.m_data)
                    * solverConstraint->m_angularComponentA.mVec128.m128_f32[0])
            + *(float *)&v12[4].m_orderTmpConstraintPool.m_ownsMemory;
        v51 = *(float *)&v12[4].m_tmpConstraintSizesPool.m_allocator * v43.m_vec128.m128_f32[0];
        v52 = solverConstraint->m_angularComponentA.mVec128.m128_f32[1]
            * (float)(*(float *)&v12[4].m_orderFrictionConstraintPool.m_ownsMemory * v43.m_vec128.m128_f32[0]);
        v53 = solverConstraint->m_angularComponentA.mVec128.m128_f32[2];
        *(float *)&v12[4].m_orderTmpConstraintPool.m_ownsMemory = v50;
        v54 = *(float *)&v12[4].m_orderFrictionConstraintPool.m_allocator + v52;
        v43.m_vec128 = (__m128)(unsigned int)v12[4].m_orderFrictionConstraintPool.m_size;
        *(float *)&v12[4].m_orderFrictionConstraintPool.m_allocator = v54;
        *(float *)&v12[4].m_orderFrictionConstraintPool.m_size = v43.m_vec128.m128_f32[0] + (float)(v53 * v51);
      }
      v40 = v79;
    }
    if ( v13 )
    {
      v55 = v13[1].m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_f32[0];
      v56 = solverConstraint->m_contactNormal.mVec128.m128_f32[1];
      v57 = solverConstraint->m_contactNormal.mVec128.m128_f32[2];
      v58 = solverConstraint->m_angularComponentB.mVec128.m128_f32[0];
      *((float *)&v95 + 1) = -solverConstraint->m_angularComponentB.mVec128.m128_f32[1];
      *(float *)&v96 = -solverConstraint->m_angularComponentB.mVec128.m128_f32[2];
      v59 = (float)(solverConstraint->m_contactNormal.mVec128.m128_f32[0] * v55)
          * v13[1].m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_f32[0];
      v60 = v57 * v55;
      v61 = v13[1].m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_f32[1] * (float)(v56 * v55);
      v62 = v13[1].m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_f32[2] * v60;
      v63 = v59;
      v64 = -v58;
      v43.m_vec128 = _mm_xor_ps((__m128)solverConstraint->m_appliedImpulse.m_vec128.m128_u32[0], (__m128)0x80000000);
      if ( v13[1].m_interpolationWorldTransform.m_basis.m_el[0].mVec128.m128_f32[0] != 0.0 )
      {
        v65 = v13[2].m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0];
        v13[2].m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1] = (float)(v61 * v43.m_vec128.m128_f32[0])
                                                                    + v13[2].m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[1];
        v13[2].m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2] = (float)(v62 * v43.m_vec128.m128_f32[0])
                                                                    + v13[2].m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[2];
        v13[2].m_worldTransform.m_basis.m_el[1].mVec128.m128_f32[0] = v65 + (float)(v63 * v43.m_vec128.m128_f32[0]);
        v66 = v13[2].m_worldTransform.m_origin.mVec128.m128_f32[0] * v43.m_vec128.m128_f32[0];
        v67 = (float)(v13[2].m_worldTransform.m_origin.mVec128.m128_f32[2] * v43.m_vec128.m128_f32[0]) * *(float *)&v96;
        v13[2].m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1] = v13[2].m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[1]
                                                                    + (float)((float)(v13[2].m_worldTransform.m_origin.mVec128.m128_f32[1]
                                                                                    * v43.m_vec128.m128_f32[0])
                                                                            * *((float *)&v95 + 1));
        v43.m_vec128 = (__m128)v13[2].m_worldTransform.m_basis.m_el[2].mVec128.m128_u32[2];
        v13[2].m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0] = (float)(v66 * v64)
                                                                    + v13[2].m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[0];
        v13[2].m_worldTransform.m_basis.m_el[2].mVec128.m128_f32[2] = v43.m_vec128.m128_f32[0] + v67;
      }
      v40 = v79;
    }
  }
  else
  {
    v38.m128_f32[0] = 0.0;
    v43.m_vec128 = _mm_shuffle_ps(v38, v38, 0);
    solverConstraint->m_appliedImpulse = (btSimdScalar)v43.m_vec128;
  }
  v43.m_vec128.m128_f32[0] = 0.0;
  solverConstraint->m_appliedPushImpulse.m_vec128 = _mm_shuffle_ps(v43.m_vec128, v43.m_vec128, 0);
  if ( v12 )
  {
    p_m_orderTmpConstraintPool = (float *)&v12[2].m_orderTmpConstraintPool;
    p_m_ownsMemory = (float *)&v12[2].m_orderTmpConstraintPool.m_ownsMemory;
  }
  else
  {
    v95 = 0;
    v96 = 0;
    p_m_orderTmpConstraintPool = (float *)&v95;
    v93 = 0;
    v94 = 0;
    p_m_ownsMemory = (float *)&v93;
  }
  v70 = (float)((float)((float)((float)((float)(solverConstraint->m_contactNormal.mVec128.m128_f32[2]
                                              * p_m_orderTmpConstraintPool[2])
                                      + (float)(solverConstraint->m_contactNormal.mVec128.m128_f32[1]
                                              * p_m_orderTmpConstraintPool[1]))
                              + (float)(p_m_ownsMemory[2] * solverConstraint->m_relpos1CrossNormal.mVec128.m128_f32[2]))
                      + (float)(p_m_ownsMemory[1] * solverConstraint->m_relpos1CrossNormal.mVec128.m128_f32[1]))
              + (float)(solverConstraint->m_contactNormal.mVec128.m128_f32[0] * *p_m_orderTmpConstraintPool))
      + (float)(*p_m_ownsMemory * solverConstraint->m_relpos1CrossNormal.mVec128.m128_f32[0]);
  if ( v13 )
  {
    m128_f32 = v13[1].m_worldTransform.m_basis.m_el[2].mVec128.m128_f32;
    v72 = v13[1].m_worldTransform.m_origin.mVec128.m128_f32;
  }
  else
  {
    v95 = 0;
    v96 = 0;
    m128_f32 = (float *)&v95;
    v93 = 0;
    v94 = 0;
    v72 = (float *)&v93;
  }
  v73 = v80
      - (float)((float)((float)((float)((float)((float)((float)(solverConstraint->m_relpos2CrossNormal.mVec128.m128_f32[2]
                                                              * v72[2])
                                                      - (float)(solverConstraint->m_contactNormal.mVec128.m128_f32[2]
                                                              * m128_f32[2]))
                                              - (float)(solverConstraint->m_contactNormal.mVec128.m128_f32[1]
                                                      * m128_f32[1]))
                                      + (float)(solverConstraint->m_relpos2CrossNormal.mVec128.m128_f32[1] * v72[1]))
                              - (float)(*m128_f32 * solverConstraint->m_contactNormal.mVec128.m128_f32[0]))
                      + (float)(solverConstraint->m_relpos2CrossNormal.mVec128.m128_f32[0] * *v72))
              + v70);
  if ( v40 <= 0.0 )
  {
    v74 = -(float)((float)(colObj1->m_erp / colObj1->m_timeStep) * v40);
  }
  else
  {
    v74 = 0.0;
    v73 = v73 - (float)(v40 / colObj1->m_timeStep);
  }
  m_jacDiagABInv = solverConstraint->m_jacDiagABInv;
  v76 = v74 * m_jacDiagABInv;
  v77 = v73 * m_jacDiagABInv;
  if ( colObj1->m_splitImpulse && v40 <= colObj1->m_splitImpulsePenetrationThreshold )
  {
    solverConstraint->m_rhsPenetration = v76;
  }
  else
  {
    v77 = v77 + v76;
    solverConstraint->m_rhsPenetration = 0.0;
  }
  solverConstraint->m_cfm = 0.0;
  solverConstraint->m_lowerLimit = 0.0;
  solverConstraint->m_rhs = v77;
  solverConstraint->m_upperLimit = 1.0e10;
}
