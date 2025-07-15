void __usercall btSequentialImpulseConstraintSolver::resolveSingleConstraintRowLowerLimit(
        btRigidBody *body1@<edx>,
        btRigidBody *body2@<esi>,
        const btSolverConstraint *c@<ecx>,
        btSequentialImpulseConstraintSolver *this)
{
  float v4; // xmm2_4
  float m_jacDiagABInv; // xmm1_4
  float v6; // xmm0_4
  __m128 m_lowerLimit_low; // xmm3
  __m128 v8; // xmm1
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm0_4

  v4 = c->m_appliedImpulse.m_vec128.m128_f32[0];
  m_jacDiagABInv = c->m_jacDiagABInv;
  v6 = (float)((float)(c->m_rhs - (float)(c->m_cfm * v4))
             - (float)((float)((float)((float)((float)((float)((float)(body1->m_deltaLinearVelocity.mVec128.m128_f32[2]
                                                                     * c->m_contactNormal.mVec128.m128_f32[2])
                                                             + (float)(body1->m_deltaLinearVelocity.mVec128.m128_f32[1]
                                                                     * c->m_contactNormal.mVec128.m128_f32[1]))
                                                     + (float)(body1->m_deltaAngularVelocity.mVec128.m128_f32[2]
                                                             * c->m_relpos1CrossNormal.mVec128.m128_f32[2]))
                                             + (float)(body1->m_deltaAngularVelocity.mVec128.m128_f32[1]
                                                     * c->m_relpos1CrossNormal.mVec128.m128_f32[1]))
                                     + (float)(c->m_contactNormal.mVec128.m128_f32[0]
                                             * body1->m_deltaLinearVelocity.mVec128.m128_f32[0]))
                             + (float)(c->m_relpos1CrossNormal.mVec128.m128_f32[0]
                                     * body1->m_deltaAngularVelocity.mVec128.m128_f32[0]))
                     * m_jacDiagABInv))
     - (float)((float)((float)((float)((float)((float)((float)(body2->m_deltaAngularVelocity.mVec128.m128_f32[2]
                                                             * c->m_relpos2CrossNormal.mVec128.m128_f32[2])
                                                     - (float)(body2->m_deltaLinearVelocity.mVec128.m128_f32[2]
                                                             * c->m_contactNormal.mVec128.m128_f32[2]))
                                             - (float)(body2->m_deltaLinearVelocity.mVec128.m128_f32[1]
                                                     * c->m_contactNormal.mVec128.m128_f32[1]))
                                     + (float)(body2->m_deltaAngularVelocity.mVec128.m128_f32[1]
                                             * c->m_relpos2CrossNormal.mVec128.m128_f32[1]))
                             - (float)(body2->m_deltaLinearVelocity.mVec128.m128_f32[0]
                                     * c->m_contactNormal.mVec128.m128_f32[0]))
                     + (float)(body2->m_deltaAngularVelocity.mVec128.m128_f32[0]
                             * c->m_relpos2CrossNormal.mVec128.m128_f32[0]))
             * m_jacDiagABInv);
  m_lowerLimit_low = (__m128)LODWORD(c->m_lowerLimit);
  v8 = (__m128)LODWORD(v4);
  if ( m_lowerLimit_low.m128_f32[0] <= (float)(v4 + v6) )
  {
    v8.m128_f32[0] = v4 + v6;
    c->m_appliedImpulse.m_vec128 = _mm_shuffle_ps(v8, v8, 0);
  }
  else
  {
    v6 = c->m_lowerLimit - v4;
    c->m_appliedImpulse.m_vec128 = _mm_shuffle_ps(m_lowerLimit_low, m_lowerLimit_low, 0);
  }
  v9 = body1->m_invMass.mVec128.m128_f32[1] * c->m_contactNormal.mVec128.m128_f32[1];
  v10 = body1->m_invMass.mVec128.m128_f32[2] * c->m_contactNormal.mVec128.m128_f32[2];
  if ( body1->m_inverseMass != 0.0 )
  {
    v11 = body1->m_deltaLinearVelocity.mVec128.m128_f32[1];
    body1->m_deltaLinearVelocity.mVec128.m128_f32[0] = body1->m_deltaLinearVelocity.mVec128.m128_f32[0]
                                                     + (float)((float)(body1->m_invMass.mVec128.m128_f32[0]
                                                                     * c->m_contactNormal.mVec128.m128_f32[0])
                                                             * v6);
    body1->m_deltaLinearVelocity.mVec128.m128_f32[1] = v11 + (float)(v9 * v6);
    body1->m_deltaLinearVelocity.mVec128.m128_f32[2] = body1->m_deltaLinearVelocity.mVec128.m128_f32[2]
                                                     + (float)(v10 * v6);
    v12 = c->m_angularComponentA.mVec128.m128_f32[1] * (float)(body1->m_angularFactor.mVec128.m128_f32[1] * v6);
    v13 = c->m_angularComponentA.mVec128.m128_f32[2] * (float)(body1->m_angularFactor.mVec128.m128_f32[2] * v6);
    body1->m_deltaAngularVelocity.mVec128.m128_f32[0] = body1->m_deltaAngularVelocity.mVec128.m128_f32[0]
                                                      + (float)(c->m_angularComponentA.mVec128.m128_f32[0]
                                                              * (float)(body1->m_angularFactor.mVec128.m128_f32[0] * v6));
    v14 = body1->m_deltaAngularVelocity.mVec128.m128_f32[1] + v12;
    v15 = body1->m_deltaAngularVelocity.mVec128.m128_f32[2] + v13;
    body1->m_deltaAngularVelocity.mVec128.m128_f32[1] = v14;
    body1->m_deltaAngularVelocity.mVec128.m128_f32[2] = v15;
  }
  v16 = body2->m_invMass.mVec128.m128_f32[1] * (float)-c->m_contactNormal.mVec128.m128_f32[1];
  v17 = body2->m_invMass.mVec128.m128_f32[2] * (float)-c->m_contactNormal.mVec128.m128_f32[2];
  if ( body2->m_inverseMass != 0.0 )
  {
    body2->m_deltaLinearVelocity.mVec128.m128_f32[0] = (float)((float)(body2->m_invMass.mVec128.m128_f32[0]
                                                                     * (float)-c->m_contactNormal.mVec128.m128_f32[0])
                                                             * v6)
                                                     + body2->m_deltaLinearVelocity.mVec128.m128_f32[0];
    body2->m_deltaLinearVelocity.mVec128.m128_f32[1] = body2->m_deltaLinearVelocity.mVec128.m128_f32[1]
                                                     + (float)(v16 * v6);
    body2->m_deltaLinearVelocity.mVec128.m128_f32[2] = body2->m_deltaLinearVelocity.mVec128.m128_f32[2]
                                                     + (float)(v17 * v6);
    v18 = c->m_angularComponentB.mVec128.m128_f32[2] * (float)(body2->m_angularFactor.mVec128.m128_f32[2] * v6);
    v19 = body2->m_deltaAngularVelocity.mVec128.m128_f32[0]
        + (float)(c->m_angularComponentB.mVec128.m128_f32[0] * (float)(body2->m_angularFactor.mVec128.m128_f32[0] * v6));
    body2->m_deltaAngularVelocity.mVec128.m128_f32[1] = body2->m_deltaAngularVelocity.mVec128.m128_f32[1]
                                                      + (float)(c->m_angularComponentB.mVec128.m128_f32[1]
                                                              * (float)(body2->m_angularFactor.mVec128.m128_f32[1] * v6));
    v20 = body2->m_deltaAngularVelocity.mVec128.m128_f32[2] + v18;
    body2->m_deltaAngularVelocity.mVec128.m128_f32[0] = v19;
    body2->m_deltaAngularVelocity.mVec128.m128_f32[2] = v20;
  }
}
