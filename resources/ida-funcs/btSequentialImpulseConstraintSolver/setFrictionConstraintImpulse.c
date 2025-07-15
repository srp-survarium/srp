void __userpurge btSequentialImpulseConstraintSolver::setFrictionConstraintImpulse(
        btRigidBody *rb0@<edx>,
        btRigidBody *rb1@<esi>,
        const btContactSolverInfo *infoGlobal@<edi>,
        __m128 a4@<xmm1>,
        btSequentialImpulseConstraintSolver *this,
        btSolverConstraint *solverConstraint,
        btManifoldPoint *cp)
{
  int m_solverMode; // eax
  btSolverConstraint *v8; // ecx
  __m128 m_appliedImpulseLateral1_low; // xmm1
  float m_inverseMass; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm7_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm4_4
  float v26; // xmm3_4
  float v27; // xmm3_4
  float v28; // xmm1_4
  int v29; // eax
  btSolverConstraint *v30; // ecx
  __m128 m_appliedImpulseLateral2_low; // xmm1
  float v32; // xmm4_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm4_4
  float v36; // xmm5_4
  float v37; // xmm3_4
  float v38; // xmm1_4
  float v39; // xmm1_4
  float v40; // xmm3_4
  float v41; // xmm4_4
  float v42; // xmm2_4
  float v43; // xmm4_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm3_4
  float v47; // xmm5_4
  float v48; // xmm7_4
  float v49; // xmm4_4
  float v50; // xmm0_4
  float v51; // xmm1_4
  float v52; // xmm0_4
  float v53; // xmm2_4
  float v54; // xmm0_4
  btSimdScalar v55; // xmm0
  float v56; // [esp+14h] [ebp-Ch]
  float v57; // [esp+18h] [ebp-8h]
  float v58; // [esp+18h] [ebp-8h]

  m_solverMode = infoGlobal->m_solverMode;
  if ( (m_solverMode & 8) != 0 )
  {
    v8 = &this->m_tmpSolverContactFrictionConstraintPool.m_data[solverConstraint->m_frictionIndex];
    if ( (m_solverMode & 4) != 0 )
    {
      m_appliedImpulseLateral1_low = (__m128)LODWORD(cp->m_appliedImpulseLateral1);
      m_appliedImpulseLateral1_low.m128_f32[0] = m_appliedImpulseLateral1_low.m128_f32[0]
                                               * infoGlobal->m_warmstartingFactor;
      v8->m_appliedImpulse.m_vec128 = _mm_shuffle_ps(m_appliedImpulseLateral1_low, m_appliedImpulseLateral1_low, 0);
      if ( rb0 )
      {
        m_inverseMass = rb0->m_inverseMass;
        v11 = v8->m_contactNormal.mVec128.m128_f32[1] * m_inverseMass;
        v12 = v8->m_contactNormal.mVec128.m128_f32[2] * m_inverseMass;
        v13 = rb0->m_linearFactor.mVec128.m128_f32[0] * (float)(v8->m_contactNormal.mVec128.m128_f32[0] * m_inverseMass);
        v14 = rb0->m_linearFactor.mVec128.m128_f32[1] * v11;
        v15 = rb0->m_linearFactor.mVec128.m128_f32[2] * v12;
        v16 = v8->m_appliedImpulse.m_vec128.m128_f32[0];
        if ( rb0->m_inverseMass != 0.0 )
        {
          v17 = rb0->m_deltaLinearVelocity.mVec128.m128_f32[0];
          rb0->m_deltaLinearVelocity.mVec128.m128_f32[2] = (float)(v15 * v16)
                                                         + rb0->m_deltaLinearVelocity.mVec128.m128_f32[2];
          rb0->m_deltaLinearVelocity.mVec128.m128_f32[1] = (float)(v14 * v16)
                                                         + rb0->m_deltaLinearVelocity.mVec128.m128_f32[1];
          rb0->m_deltaLinearVelocity.mVec128.m128_f32[0] = v17 + (float)(v13 * v16);
          v18 = v8->m_angularComponentA.mVec128.m128_f32[1] * (float)(rb0->m_angularFactor.mVec128.m128_f32[1] * v16);
          v19 = v8->m_angularComponentA.mVec128.m128_f32[2] * (float)(rb0->m_angularFactor.mVec128.m128_f32[2] * v16);
          rb0->m_deltaAngularVelocity.mVec128.m128_f32[0] = rb0->m_deltaAngularVelocity.mVec128.m128_f32[0]
                                                          + (float)(v8->m_angularComponentA.mVec128.m128_f32[0]
                                                                  * (float)(rb0->m_angularFactor.mVec128.m128_f32[0]
                                                                          * v16));
          v20 = rb0->m_deltaAngularVelocity.mVec128.m128_f32[1] + v18;
          v21 = rb0->m_deltaAngularVelocity.mVec128.m128_f32[2] + v19;
          rb0->m_deltaAngularVelocity.mVec128.m128_f32[1] = v20;
          rb0->m_deltaAngularVelocity.mVec128.m128_f32[2] = v21;
        }
      }
      if ( rb1 )
      {
        v22 = rb1->m_inverseMass;
        LODWORD(v56) = v8->m_angularComponentB.mVec128.m128_i32[1] ^ _mask__NegFloat_;
        LODWORD(v57) = v8->m_angularComponentB.mVec128.m128_i32[2] ^ _mask__NegFloat_;
        v23 = rb1->m_linearFactor.mVec128.m128_f32[1] * (float)(v8->m_contactNormal.mVec128.m128_f32[1] * v22);
        LODWORD(v24) = v8->m_angularComponentB.mVec128.m128_i32[0] ^ _mask__NegFloat_;
        LODWORD(v25) = v8->m_appliedImpulse.m_vec128.m128_i32[0] ^ _mask__NegFloat_;
        if ( v22 != 0.0 )
        {
          v26 = (float)((float)(rb1->m_linearFactor.mVec128.m128_f32[2]
                              * (float)(v8->m_contactNormal.mVec128.m128_f32[2] * v22))
                      * v25)
              + rb1->m_deltaLinearVelocity.mVec128.m128_f32[2];
          rb1->m_deltaLinearVelocity.mVec128.m128_f32[0] = (float)((float)(rb1->m_linearFactor.mVec128.m128_f32[0]
                                                                         * (float)(v22
                                                                                 * v8->m_contactNormal.mVec128.m128_f32[0]))
                                                                 * v25)
                                                         + rb1->m_deltaLinearVelocity.mVec128.m128_f32[0];
          rb1->m_deltaLinearVelocity.mVec128.m128_f32[2] = v26;
          rb1->m_deltaLinearVelocity.mVec128.m128_f32[1] = (float)(v23 * v25)
                                                         + rb1->m_deltaLinearVelocity.mVec128.m128_f32[1];
          v27 = rb1->m_deltaAngularVelocity.mVec128.m128_f32[1]
              + (float)((float)(rb1->m_angularFactor.mVec128.m128_f32[1] * v25) * v56);
          v28 = rb1->m_deltaAngularVelocity.mVec128.m128_f32[2]
              + (float)((float)(rb1->m_angularFactor.mVec128.m128_f32[2] * v25) * v57);
          rb1->m_deltaAngularVelocity.mVec128.m128_f32[0] = rb1->m_deltaAngularVelocity.mVec128.m128_f32[0]
                                                          + (float)((float)(v25
                                                                          * rb1->m_angularFactor.mVec128.m128_f32[0])
                                                                  * v24);
          rb1->m_deltaAngularVelocity.mVec128.m128_f32[1] = v27;
          rb1->m_deltaAngularVelocity.mVec128.m128_f32[2] = v28;
        }
      }
    }
    else
    {
      a4.m128_f32[0] = 0.0;
      v8->m_appliedImpulse.m_vec128 = _mm_shuffle_ps(a4, a4, 0);
    }
    v29 = infoGlobal->m_solverMode;
    if ( (v29 & 0x10) != 0 )
    {
      v30 = &this->m_tmpSolverContactFrictionConstraintPool.m_data[solverConstraint->m_frictionIndex + 1];
      if ( (v29 & 4) != 0 )
      {
        m_appliedImpulseLateral2_low = (__m128)LODWORD(cp->m_appliedImpulseLateral2);
        m_appliedImpulseLateral2_low.m128_f32[0] = m_appliedImpulseLateral2_low.m128_f32[0]
                                                 * infoGlobal->m_warmstartingFactor;
        v30->m_appliedImpulse.m_vec128 = _mm_shuffle_ps(m_appliedImpulseLateral2_low, m_appliedImpulseLateral2_low, 0);
        if ( rb0 )
        {
          v32 = rb0->m_inverseMass;
          v33 = v30->m_contactNormal.mVec128.m128_f32[1] * v32;
          v34 = v30->m_contactNormal.mVec128.m128_f32[2] * v32;
          v35 = v30->m_appliedImpulse.m_vec128.m128_f32[0];
          if ( rb0->m_inverseMass != 0.0 )
          {
            v36 = rb0->m_deltaLinearVelocity.mVec128.m128_f32[0]
                + (float)((float)(rb0->m_inverseMass * v30->m_contactNormal.mVec128.m128_f32[0]) * v35);
            v37 = rb0->m_deltaLinearVelocity.mVec128.m128_f32[1] + (float)(v33 * v35);
            v38 = rb0->m_deltaLinearVelocity.mVec128.m128_f32[2];
            rb0->m_deltaLinearVelocity.mVec128.m128_f32[1] = v37;
            rb0->m_deltaLinearVelocity.mVec128.m128_f32[0] = v36;
            rb0->m_deltaLinearVelocity.mVec128.m128_f32[2] = v38 + (float)(v34 * v35);
            v39 = (float)((float)(v35 * rb0->m_angularFactor.mVec128.m128_f32[0])
                        * v30->m_angularComponentA.mVec128.m128_f32[0])
                + rb0->m_deltaAngularVelocity.mVec128.m128_f32[0];
            v40 = rb0->m_angularFactor.mVec128.m128_f32[2] * v35;
            v41 = v30->m_angularComponentA.mVec128.m128_f32[1] * (float)(rb0->m_angularFactor.mVec128.m128_f32[1] * v35);
            v42 = v30->m_angularComponentA.mVec128.m128_f32[2];
            rb0->m_deltaAngularVelocity.mVec128.m128_f32[0] = v39;
            rb0->m_deltaAngularVelocity.mVec128.m128_f32[1] = rb0->m_deltaAngularVelocity.mVec128.m128_f32[1] + v41;
            rb0->m_deltaAngularVelocity.mVec128.m128_f32[2] = rb0->m_deltaAngularVelocity.mVec128.m128_f32[2]
                                                            + (float)(v42 * v40);
          }
        }
        if ( rb1 )
        {
          v43 = rb1->m_inverseMass;
          LODWORD(v58) = v30->m_angularComponentB.mVec128.m128_i32[2] ^ _mask__NegFloat_;
          v44 = v30->m_contactNormal.mVec128.m128_f32[0] * v43;
          v45 = v30->m_contactNormal.mVec128.m128_f32[1] * v43;
          v46 = v30->m_contactNormal.mVec128.m128_f32[2] * v43;
          LODWORD(v47) = v30->m_angularComponentB.mVec128.m128_i32[0] ^ _mask__NegFloat_;
          LODWORD(v48) = v30->m_angularComponentB.mVec128.m128_i32[1] ^ _mask__NegFloat_;
          LODWORD(v49) = v30->m_appliedImpulse.m_vec128.m128_i32[0] ^ _mask__NegFloat_;
          if ( rb1->m_inverseMass != 0.0 )
          {
            v50 = rb1->m_deltaLinearVelocity.mVec128.m128_f32[0];
            rb1->m_deltaLinearVelocity.mVec128.m128_f32[1] = (float)(v45 * v49)
                                                           + rb1->m_deltaLinearVelocity.mVec128.m128_f32[1];
            rb1->m_deltaLinearVelocity.mVec128.m128_f32[0] = v50 + (float)(v44 * v49);
            rb1->m_deltaLinearVelocity.mVec128.m128_f32[2] = (float)(v46 * v49)
                                                           + rb1->m_deltaLinearVelocity.mVec128.m128_f32[2];
            v51 = rb1->m_angularFactor.mVec128.m128_f32[2];
            v52 = (float)(rb1->m_angularFactor.mVec128.m128_f32[1] * v49) * v48;
            rb1->m_deltaAngularVelocity.mVec128.m128_f32[0] = (float)((float)(v49
                                                                            * rb1->m_angularFactor.mVec128.m128_f32[0])
                                                                    * v47)
                                                            + rb1->m_deltaAngularVelocity.mVec128.m128_f32[0];
            v53 = rb1->m_deltaAngularVelocity.mVec128.m128_f32[1] + v52;
            v54 = rb1->m_deltaAngularVelocity.mVec128.m128_f32[2] + (float)((float)(v51 * v49) * v58);
            rb1->m_deltaAngularVelocity.mVec128.m128_f32[1] = v53;
            rb1->m_deltaAngularVelocity.mVec128.m128_f32[2] = v54;
          }
        }
      }
      else
      {
        v30->m_appliedImpulse.m_vec128 = _mm_shuffle_ps((__m128)0LL, (__m128)0LL, 0);
      }
    }
  }
  else
  {
    v55.m_vec128 = _mm_shuffle_ps((__m128)*(unsigned int *)&FLOAT_0_0, (__m128)*(unsigned int *)&FLOAT_0_0, 0);
    this->m_tmpSolverContactFrictionConstraintPool.m_data[solverConstraint->m_frictionIndex].m_appliedImpulse = (btSimdScalar)v55.m_vec128;
    if ( (infoGlobal->m_solverMode & 0x10) != 0 )
      this->m_tmpSolverContactFrictionConstraintPool.m_data[solverConstraint->m_frictionIndex + 1].m_appliedImpulse = (btSimdScalar)v55.m_vec128;
  }
}
