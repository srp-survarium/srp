void __userpurge btSequentialImpulseConstraintSolver::setupFrictionConstraint(
        btSolverConstraint *solverConstraint@<esi>,
        btCollisionObject *colObj0@<ecx>,
        unsigned int colObj1@<eax>,
        float a4@<xmm10>,
        btSequentialImpulseConstraintSolver *this,
        btManifoldPoint *normalAxis,
        const btVector3 *solverBodyA,
        const btVector3 *solverBodyB,
        btManifoldPoint *cp,
        const btVector3 *rel_pos1,
        const btVector3 *rel_pos2,
        float relaxation,
        float desiredVelocity,
        float cfmSlip)
{
  float *v14; // edi
  btSequentialImpulseConstraintSolver *v15; // ecx
  int v16; // ebx
  __m128 v17; // xmm0
  float *v18; // ebx
  btRigidBody *FixedBody; // eax
  btRigidBody *v20; // eax
  btSimdScalar v22; // xmm0
  float v23; // xmm5_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm0_4
  float v27; // xmm5_4
  float v28; // xmm6_4
  float v29; // xmm0_4
  float v30; // xmm5_4
  float v31; // xmm6_4
  float v32; // xmm7_4
  btRigidBody_vtbl *v33; // xmm2_4
  float v34; // xmm5_4
  float v35; // xmm3_4
  float v36; // xmm0_4
  float v37; // xmm2_4
  float v38; // xmm6_4
  float v39; // xmm7_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  float v42; // xmm6_4
  float v43; // xmm5_4
  float v44; // xmm2_4
  float v45; // xmm3_4
  float v46; // xmm2_4
  float v47; // xmm0_4
  __m128 v48; // xmm2
  btVector3 *v49; // eax
  float *v50; // edi
  float v51; // xmm0_4
  float *v52; // ecx
  btVector3 *v53; // eax
  float v54; // xmm3_4
  __m128 v55; // xmm0
  float v56; // [esp+58h] [ebp-28h]
  btVector3 v57; // [esp+60h] [ebp-20h] BYREF
  __int64 v58; // [esp+70h] [ebp-10h] BYREF
  __int64 v59; // [esp+78h] [ebp-8h]

  v14 = (colObj0->m_internalType & 2) != 0 ? (float *)colObj0 : 0;
  v15 = this;
  v16 = -((*(_BYTE *)(colObj1 + 244) & 2) != 0);
  solverConstraint->m_contactNormal.mVec128.m128_u64[0] = *(_QWORD *)&this->__vftable;
  v17 = (__m128)_mm_loadl_epi64((const __m128i *)&this->m_tmpSolverContactConstraintPool.m_size);
  v18 = (float *)(colObj1 & v16);
  solverConstraint->m_contactNormal.mVec128.m128_u64[1] = v17.m128_u64[0];
  if ( v14 )
  {
    FixedBody = (btRigidBody *)v14;
  }
  else
  {
    FixedBody = btSequentialImpulseConstraintSolver::getFixedBody((btRigidBody *)this, a4);
    v15 = this;
  }
  solverConstraint->m_companionIdA = (int)FixedBody;
  if ( v18 )
  {
    v20 = (btRigidBody *)v18;
  }
  else
  {
    v20 = btSequentialImpulseConstraintSolver::getFixedBody((btRigidBody *)v15, a4);
    v15 = this;
  }
  solverConstraint->m_companionIdB = (int)v20;
  solverConstraint->m_friction = normalAxis->m_combinedFriction;
  solverConstraint->m_originalContactPoint = 0;
  v17.m128_f32[0] = 0.0;
  v22.m_vec128 = _mm_shuffle_ps(v17, v17, 0);
  solverConstraint->m_appliedImpulse = (btSimdScalar)v22.m_vec128;
  solverConstraint->m_appliedPushImpulse = (btSimdScalar)v22.m_vec128;
  v23 = solverConstraint->m_contactNormal.mVec128.m128_f32[2];
  v24 = (float)(solverBodyA->mVec128.m128_f32[1] * v23)
      - (float)(solverBodyA->mVec128.m128_f32[2] * solverConstraint->m_contactNormal.mVec128.m128_f32[1]);
  v25 = (float)(solverConstraint->m_contactNormal.mVec128.m128_f32[0] * solverBodyA->mVec128.m128_f32[2])
      - (float)(solverBodyA->mVec128.m128_f32[0] * v23);
  v26 = (float)(solverBodyA->mVec128.m128_f32[0] * solverConstraint->m_contactNormal.mVec128.m128_f32[1])
      - (float)(solverConstraint->m_contactNormal.mVec128.m128_f32[0] * solverBodyA->mVec128.m128_f32[1]);
  v57.mVec128.m128_f32[0] = v24;
  v57.mVec128.m128_f32[1] = v25;
  solverConstraint->m_relpos1CrossNormal.mVec128.m128_u64[0] = v57.mVec128.m128_u64[0];
  v57.mVec128.m128_u64[1] = LODWORD(v26);
  solverConstraint->m_relpos1CrossNormal.mVec128.m128_u64[1] = LODWORD(v26);
  if ( v14 )
  {
    v27 = (float)((float)(v14[74] * v26) + (float)(v14[73] * v25)) + (float)(v14[72] * v24);
    v28 = (float)((float)(v14[78] * v26) + (float)(v14[77] * v25)) + (float)(v14[76] * v24);
    v57.mVec128.m128_f32[0] = v14[152]
                            * (float)((float)((float)(v14[70] * v26) + (float)(v14[69] * v25)) + (float)(v14[68] * v24));
    v57.mVec128.m128_f32[1] = v14[153] * v27;
    v57.mVec128.m128_f32[2] = v14[154] * v28;
  }
  else
  {
    memset(&v57, 0, 12);
  }
  v57.mVec128.m128_i32[3] = 0;
  solverConstraint->m_angularComponentA = (btVector3)v57.mVec128;
  v29 = solverBodyB->mVec128.m128_f32[2];
  v30 = solverConstraint->m_contactNormal.mVec128.m128_f32[0];
  v31 = -solverConstraint->m_contactNormal.mVec128.m128_f32[2];
  v56 = solverBodyB->mVec128.m128_f32[1];
  v32 = v29 * (float)-solverConstraint->m_contactNormal.mVec128.m128_f32[1];
  *((float *)&v58 + 1) = -solverConstraint->m_contactNormal.mVec128.m128_f32[1];
  v33 = (btRigidBody_vtbl *)solverBodyB->mVec128.m128_i32[0];
  v34 = -v30;
  v35 = (float)(v56 * v31) - v32;
  v36 = (float)(v29 * v34) - (float)(solverBodyB->mVec128.m128_f32[0] * v31);
  v57.mVec128.m128_u64[0] = __PAIR64__(LODWORD(v36), LODWORD(v35));
  v37 = (float)(*(float *)&v33 * *((float *)&v58 + 1)) - (float)(v56 * v34);
  solverConstraint->m_relpos2CrossNormal.mVec128.m128_u64[0] = __PAIR64__(LODWORD(v36), LODWORD(v35));
  v57.mVec128.m128_u64[1] = LODWORD(v37);
  solverConstraint->m_relpos2CrossNormal.mVec128.m128_u64[1] = LODWORD(v37);
  if ( v18 )
  {
    v38 = (float)((float)(v18[74] * v37) + (float)(v18[73] * v36)) + (float)(v18[72] * v35);
    v39 = (float)((float)(v18[78] * v37) + (float)(v18[77] * v36)) + (float)(v18[76] * v35);
    v57.mVec128.m128_f32[0] = v18[152]
                            * (float)((float)((float)(v18[70] * v37) + (float)(v18[69] * v36)) + (float)(v18[68] * v35));
    v57.mVec128.m128_f32[1] = v18[153] * v38;
    v57.mVec128.m128_f32[2] = v18[154] * v39;
  }
  else
  {
    memset(&v57, 0, 12);
  }
  v57.mVec128.m128_i32[3] = 0;
  solverConstraint->m_angularComponentB = (btVector3)v57.mVec128;
  v40 = 0.0;
  v41 = 0.0;
  if ( v14 )
  {
    v42 = solverBodyA->mVec128.m128_f32[2];
    v43 = solverConstraint->m_angularComponentA.mVec128.m128_f32[1];
    v44 = solverConstraint->m_angularComponentA.mVec128.m128_f32[2];
    v45 = (float)(v42 * v43) - (float)(solverBodyA->mVec128.m128_f32[1] * v44);
    v46 = v44 * solverBodyA->mVec128.m128_f32[0];
    *(float *)&v58 = v45;
    v40 = (float)((float)((float)(*(float *)&v15->m_tmpSolverContactConstraintPool.m_size
                                * (float)((float)(solverConstraint->m_angularComponentA.mVec128.m128_f32[0]
                                                * solverBodyA->mVec128.m128_f32[1])
                                        - (float)(v43 * solverBodyA->mVec128.m128_f32[0])))
                        + (float)(*(float *)&v15->m_tmpSolverContactConstraintPool.m_allocator
                                * (float)(v46 - (float)(solverConstraint->m_angularComponentA.mVec128.m128_f32[0] * v42))))
                + (float)(*(float *)&v15->__vftable * v45))
        + v14[88];
  }
  if ( v18 )
    v41 = (float)((float)((float)(*(float *)&v15->m_tmpSolverContactConstraintPool.m_size
                                * (float)((float)(solverBodyB->mVec128.m128_f32[1]
                                                * (float)-solverConstraint->m_angularComponentB.mVec128.m128_f32[0])
                                        - (float)(solverBodyB->mVec128.m128_f32[0]
                                                * (float)-solverConstraint->m_angularComponentB.mVec128.m128_f32[1])))
                        + (float)(*(float *)&v15->m_tmpSolverContactConstraintPool.m_allocator
                                * (float)((float)(solverBodyB->mVec128.m128_f32[0]
                                                * (float)-solverConstraint->m_angularComponentB.mVec128.m128_f32[2])
                                        - (float)(solverBodyB->mVec128.m128_f32[2]
                                                * (float)-solverConstraint->m_angularComponentB.mVec128.m128_f32[0]))))
                + (float)(*(float *)&v15->__vftable
                        * (float)((float)(solverBodyB->mVec128.m128_f32[2]
                                        * (float)-solverConstraint->m_angularComponentB.mVec128.m128_f32[1])
                                - (float)(solverBodyB->mVec128.m128_f32[1]
                                        * (float)-solverConstraint->m_angularComponentB.mVec128.m128_f32[2]))))
        + v18[88];
  v47 = v41 + v40;
  v48 = (__m128)(unsigned int)cp;
  v48.m128_f32[0] = *(float *)&cp / v47;
  solverConstraint->m_jacDiagABInv = *(float *)&cp / v47;
  if ( v14 )
  {
    v49 = (btVector3 *)(v14 + 80);
    v50 = v14 + 84;
  }
  else
  {
    v57.mVec128 = (__m128)0LL;
    v49 = &v57;
    v58 = 0;
    v59 = 0;
    v50 = (float *)&v58;
  }
  v51 = (float)((float)((float)((float)((float)(solverConstraint->m_contactNormal.mVec128.m128_f32[2]
                                              * v49->mVec128.m128_f32[2])
                                      + (float)(solverConstraint->m_contactNormal.mVec128.m128_f32[1]
                                              * v49->mVec128.m128_f32[1]))
                              + (float)(v50[2] * solverConstraint->m_relpos1CrossNormal.mVec128.m128_f32[2]))
                      + (float)(v50[1] * solverConstraint->m_relpos1CrossNormal.mVec128.m128_f32[1]))
              + (float)(solverConstraint->m_contactNormal.mVec128.m128_f32[0] * v49->mVec128.m128_f32[0]))
      + (float)(solverConstraint->m_relpos1CrossNormal.mVec128.m128_f32[0] * *v50);
  if ( v18 )
  {
    v52 = v18 + 80;
    v53 = (btVector3 *)(v18 + 84);
  }
  else
  {
    v58 = 0;
    v59 = 0;
    v52 = (float *)&v58;
    v57.mVec128 = (__m128)0LL;
    v53 = &v57;
  }
  v54 = (float)((float)((float)((float)((float)((float)(solverConstraint->m_relpos2CrossNormal.mVec128.m128_f32[2]
                                                      * v53->mVec128.m128_f32[2])
                                              - (float)(solverConstraint->m_contactNormal.mVec128.m128_f32[2] * v52[2]))
                                      - (float)(solverConstraint->m_contactNormal.mVec128.m128_f32[1] * v52[1]))
                              + (float)(solverConstraint->m_relpos2CrossNormal.mVec128.m128_f32[1]
                                      * v53->mVec128.m128_f32[1]))
                      - (float)(*v52 * solverConstraint->m_contactNormal.mVec128.m128_f32[0]))
              + (float)(solverConstraint->m_relpos2CrossNormal.mVec128.m128_f32[0] * v53->mVec128.m128_f32[0]))
      + v51;
  v55 = (__m128)(unsigned int)rel_pos1;
  v55.m128_f32[0] = *(float *)&rel_pos1 - v54;
  solverConstraint->m_lowerLimit = 0.0;
  *(float *)&v58 = _mm_shuffle_ps(v55, v55, 0).m128_f32[0] * _mm_shuffle_ps(v48, v48, 0).m128_f32[0];
  LODWORD(solverConstraint->m_rhs) = v58;
  LODWORD(solverConstraint->m_cfm) = rel_pos2;
  solverConstraint->m_upperLimit = 1.0e10;
}
