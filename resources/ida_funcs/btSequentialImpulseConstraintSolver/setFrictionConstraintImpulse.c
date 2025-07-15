void __userpurge btSequentialImpulseConstraintSolver::setFrictionConstraintImpulse(
        btRigidBody *rb0@<edx>,
        btRigidBody *rb1@<eax>,
        btSequentialImpulseConstraintSolver *this,
        btSolverConstraint *solverConstraint,
        btManifoldPoint *cp,
        const btContactSolverInfo *infoGlobal)
{
  int m_solverMode; // ebx
  int m_frictionIndex; // eax
  btSolverConstraint *v9; // ecx
  __m128 m_appliedImpulseLateral1_low; // xmm0
  float m_inverseMass; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm5_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm5_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  float v21; // xmm7_4
  float v22; // xmm5_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  int v28; // ebx
  btSolverConstraint *v29; // ecx
  __m128 m_appliedImpulseLateral2_low; // xmm0
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm0_4
  float v35; // xmm5_4
  float v36; // xmm1_4
  float v37; // xmm1_4
  float v38; // xmm3_4
  float v39; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  float v42; // xmm0_4
  float v43; // xmm0_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm3_4
  float v47; // xmm5_4
  float v48; // xmm6_4
  float v49; // xmm0_4
  float v50; // xmm4_4
  float v51; // xmm1_4
  float v52; // xmm3_4
  float v53; // xmm0_4
  btSimdScalar v54; // xmm0
  float v55; // [esp+14h] [ebp-Ch]
  float v56; // [esp+18h] [ebp-8h]
  float v57; // [esp+18h] [ebp-8h]

  m_solverMode = infoGlobal->m_solverMode;
  m_frictionIndex = solverConstraint->m_frictionIndex;
  if ( (m_solverMode & 8) != 0 )
  {
    v9 = &this->m_tmpSolverContactFrictionConstraintPool.m_data[m_frictionIndex];
    if ( (m_solverMode & 4) != 0 )
    {
      m_appliedImpulseLateral1_low = (__m128)LODWORD(cp->m_appliedImpulseLateral1);
      m_appliedImpulseLateral1_low.m128_f32[0] = m_appliedImpulseLateral1_low.m128_f32[0]
                                               * infoGlobal->m_warmstartingFactor;
      v9->m_appliedImpulse.m_vec128 = _mm_shuffle_ps(m_appliedImpulseLateral1_low, m_appliedImpulseLateral1_low, 0);
      if ( rb0 )
      {
        m_inverseMass = rb0->m_inverseMass;
        v12 = rb0->m_linearFactor.mVec128.m128_f32[0] * (float)(v9->m_contactNormal.mVec128.m128_f32[0] * m_inverseMass);
        v13 = rb0->m_linearFactor.mVec128.m128_f32[1] * (float)(v9->m_contactNormal.mVec128.m128_f32[1] * m_inverseMass);
        v14 = v9->m_contactNormal.mVec128.m128_f32[2] * m_inverseMass;
        v15 = v9->m_appliedImpulse.m_vec128.m128_f32[0];
        v16 = rb0->m_linearFactor.mVec128.m128_f32[2] * v14;
        if ( rb0->m_inverseMass != 0.0 )
        {
          v17 = rb0->m_deltaLinearVelocity.mVec128.m128_f32[0];
          rb0->m_deltaLinearVelocity.mVec128.m128_f32[1] = (float)(v13 * v15)
                                                         + rb0->m_deltaLinearVelocity.mVec128.m128_f32[1];
          rb0->m_deltaLinearVelocity.mVec128.m128_f32[2] = (float)(v16 * v15)
                                                         + rb0->m_deltaLinearVelocity.mVec128.m128_f32[2];
          rb0->m_deltaLinearVelocity.mVec128.m128_f32[0] = v17 + (float)(v12 * v15);
          v18 = v9->m_angularComponentA.mVec128.m128_f32[2] * (float)(rb0->m_angularFactor.mVec128.m128_f32[2] * v15);
          v19 = rb0->m_deltaAngularVelocity.mVec128.m128_f32[0]
              + (float)(v9->m_angularComponentA.mVec128.m128_f32[0]
                      * (float)(rb0->m_angularFactor.mVec128.m128_f32[0] * v15));
          rb0->m_deltaAngularVelocity.mVec128.m128_f32[1] = rb0->m_deltaAngularVelocity.mVec128.m128_f32[1]
                                                          + (float)(v9->m_angularComponentA.mVec128.m128_f32[1]
                                                                  * (float)(rb0->m_angularFactor.mVec128.m128_f32[1]
                                                                          * v15));
          v20 = rb0->m_deltaAngularVelocity.mVec128.m128_f32[2] + v18;
          rb0->m_deltaAngularVelocity.mVec128.m128_f32[0] = v19;
          rb0->m_deltaAngularVelocity.mVec128.m128_f32[2] = v20;
        }
      }
      if ( rb1 )
      {
        v21 = rb1->m_inverseMass;
        v55 = -v9->m_angularComponentB.mVec128.m128_f32[1];
        v56 = -v9->m_angularComponentB.mVec128.m128_f32[2];
        v22 = -v9->m_angularComponentB.mVec128.m128_f32[0];
        v23 = -v9->m_appliedImpulse.m_vec128.m128_f32[0];
        if ( v21 != 0.0 )
        {
          v24 = (float)((float)(rb1->m_linearFactor.mVec128.m128_f32[1]
                              * (float)(v9->m_contactNormal.mVec128.m128_f32[1] * v21))
                      * v23)
              + rb1->m_deltaLinearVelocity.mVec128.m128_f32[1];
          v25 = (float)((float)(rb1->m_linearFactor.mVec128.m128_f32[2]
                              * (float)(v9->m_contactNormal.mVec128.m128_f32[2] * v21))
                      * v23)
              + rb1->m_deltaLinearVelocity.mVec128.m128_f32[2];
          rb1->m_deltaLinearVelocity.mVec128.m128_f32[0] = (float)((float)(rb1->m_linearFactor.mVec128.m128_f32[0]
                                                                         * (float)(v21
                                                                                 * v9->m_contactNormal.mVec128.m128_f32[0]))
                                                                 * v23)
                                                         + rb1->m_deltaLinearVelocity.mVec128.m128_f32[0];
          rb1->m_deltaLinearVelocity.mVec128.m128_f32[1] = v24;
          rb1->m_deltaLinearVelocity.mVec128.m128_f32[2] = v25;
          v26 = (float)(rb1->m_angularFactor.mVec128.m128_f32[1] * v23) * v55;
          v27 = (float)(rb1->m_angularFactor.mVec128.m128_f32[2] * v23) * v56;
          rb1->m_deltaAngularVelocity.mVec128.m128_f32[0] = rb1->m_deltaAngularVelocity.mVec128.m128_f32[0]
                                                          + (float)((float)(v23
                                                                          * rb1->m_angularFactor.mVec128.m128_f32[0])
                                                                  * v22);
          rb1->m_deltaAngularVelocity.mVec128.m128_f32[1] = rb1->m_deltaAngularVelocity.mVec128.m128_f32[1] + v26;
          rb1->m_deltaAngularVelocity.mVec128.m128_f32[2] = rb1->m_deltaAngularVelocity.mVec128.m128_f32[2] + v27;
        }
      }
    }
    else
    {
      v9->m_appliedImpulse.m_vec128 = _mm_shuffle_ps(
                                        (__m128)*(unsigned int *)&FLOAT_0_0,
                                        (__m128)*(unsigned int *)&FLOAT_0_0,
                                        0);
    }
    v28 = infoGlobal->m_solverMode;
    if ( (v28 & 0x10) != 0 )
    {
      v29 = &this->m_tmpSolverContactFrictionConstraintPool.m_data[solverConstraint->m_frictionIndex + 1];
      if ( (v28 & 4) != 0 )
      {
        m_appliedImpulseLateral2_low = (__m128)LODWORD(cp->m_appliedImpulseLateral2);
        m_appliedImpulseLateral2_low.m128_f32[0] = m_appliedImpulseLateral2_low.m128_f32[0]
                                                 * infoGlobal->m_warmstartingFactor;
        v29->m_appliedImpulse.m_vec128 = _mm_shuffle_ps(m_appliedImpulseLateral2_low, m_appliedImpulseLateral2_low, 0);
        if ( rb0 )
        {
          v31 = rb0->m_inverseMass;
          v32 = v29->m_contactNormal.mVec128.m128_f32[1] * v31;
          v33 = v29->m_contactNormal.mVec128.m128_f32[2] * v31;
          v34 = v29->m_appliedImpulse.m_vec128.m128_f32[0];
          if ( rb0->m_inverseMass != 0.0 )
          {
            v35 = rb0->m_deltaLinearVelocity.mVec128.m128_f32[0]
                + (float)((float)(rb0->m_inverseMass * v29->m_contactNormal.mVec128.m128_f32[0]) * v34);
            rb0->m_deltaLinearVelocity.mVec128.m128_f32[1] = rb0->m_deltaLinearVelocity.mVec128.m128_f32[1]
                                                           + (float)(v32 * v34);
            v36 = rb0->m_deltaLinearVelocity.mVec128.m128_f32[2];
            rb0->m_deltaLinearVelocity.mVec128.m128_f32[0] = v35;
            rb0->m_deltaLinearVelocity.mVec128.m128_f32[2] = v36 + (float)(v33 * v34);
            v37 = (float)((float)(v34 * rb0->m_angularFactor.mVec128.m128_f32[0])
                        * v29->m_angularComponentA.mVec128.m128_f32[0])
                + rb0->m_deltaAngularVelocity.mVec128.m128_f32[0];
            v38 = rb0->m_angularFactor.mVec128.m128_f32[2] * v34;
            v39 = v29->m_angularComponentA.mVec128.m128_f32[1] * (float)(rb0->m_angularFactor.mVec128.m128_f32[1] * v34);
            v40 = v29->m_angularComponentA.mVec128.m128_f32[2];
            rb0->m_deltaAngularVelocity.mVec128.m128_f32[0] = v37;
            v41 = rb0->m_deltaAngularVelocity.mVec128.m128_f32[1] + v39;
            v42 = rb0->m_deltaAngularVelocity.mVec128.m128_f32[2] + (float)(v40 * v38);
            rb0->m_deltaAngularVelocity.mVec128.m128_f32[1] = v41;
            rb0->m_deltaAngularVelocity.mVec128.m128_f32[2] = v42;
          }
        }
        if ( rb1 )
        {
          v43 = rb1->m_inverseMass;
          v57 = -v29->m_angularComponentB.mVec128.m128_f32[2];
          v44 = v29->m_contactNormal.mVec128.m128_f32[0] * v43;
          v45 = v29->m_contactNormal.mVec128.m128_f32[1] * v43;
          v46 = v29->m_contactNormal.mVec128.m128_f32[2] * v43;
          v47 = -v29->m_angularComponentB.mVec128.m128_f32[0];
          v48 = -v29->m_angularComponentB.mVec128.m128_f32[1];
          v49 = -v29->m_appliedImpulse.m_vec128.m128_f32[0];
          if ( rb1->m_inverseMass != 0.0 )
          {
            v50 = rb1->m_deltaLinearVelocity.mVec128.m128_f32[0];
            rb1->m_deltaLinearVelocity.mVec128.m128_f32[1] = (float)(v45 * v49)
                                                           + rb1->m_deltaLinearVelocity.mVec128.m128_f32[1];
            rb1->m_deltaLinearVelocity.mVec128.m128_f32[2] = (float)(v46 * v49)
                                                           + rb1->m_deltaLinearVelocity.mVec128.m128_f32[2];
            rb1->m_deltaLinearVelocity.mVec128.m128_f32[0] = v50 + (float)(v44 * v49);
            v51 = v49 * rb1->m_angularFactor.mVec128.m128_f32[0];
            v52 = (float)(rb1->m_angularFactor.mVec128.m128_f32[2] * v49) * v57;
            rb1->m_deltaAngularVelocity.mVec128.m128_f32[1] = rb1->m_deltaAngularVelocity.mVec128.m128_f32[1]
                                                            + (float)((float)(rb1->m_angularFactor.mVec128.m128_f32[1]
                                                                            * v49)
                                                                    * v48);
            v53 = rb1->m_deltaAngularVelocity.mVec128.m128_f32[2] + v52;
            rb1->m_deltaAngularVelocity.mVec128.m128_f32[0] = (float)(v51 * v47)
                                                            + rb1->m_deltaAngularVelocity.mVec128.m128_f32[0];
            rb1->m_deltaAngularVelocity.mVec128.m128_f32[2] = v53;
          }
        }
      }
      else
      {
        v29->m_appliedImpulse.m_vec128 = _mm_shuffle_ps(
                                           (__m128)*(unsigned int *)&FLOAT_0_0,
                                           (__m128)*(unsigned int *)&FLOAT_0_0,
                                           0);
      }
    }
  }
  else
  {
    v54.m_vec128 = _mm_shuffle_ps((__m128)*(unsigned int *)&FLOAT_0_0, (__m128)*(unsigned int *)&FLOAT_0_0, 0);
    this->m_tmpSolverContactFrictionConstraintPool.m_data[m_frictionIndex].m_appliedImpulse = (btSimdScalar)v54.m_vec128;
    if ( (infoGlobal->m_solverMode & 0x10) != 0 )
      this->m_tmpSolverContactFrictionConstraintPool.m_data[solverConstraint->m_frictionIndex + 1].m_appliedImpulse = (btSimdScalar)v54.m_vec128;
  }
}
