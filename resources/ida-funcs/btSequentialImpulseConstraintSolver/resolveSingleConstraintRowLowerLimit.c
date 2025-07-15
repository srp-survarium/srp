void __usercall btSequentialImpulseConstraintSolver::resolveSingleConstraintRowLowerLimit(
        btRigidBody *body1@<edx>,
        btRigidBody *body2@<esi>,
        const btSolverConstraint *c@<ecx>,
        btSequentialImpulseConstraintSolver *this)
{
  float v4; // xmm3_4
  float m_jacDiagABInv; // xmm1_4
  float v6; // xmm0_4
  __m128 m_lowerLimit_low; // xmm2
  __m128 v8; // xmm1
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm0_4

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
  v9 = body1->m_invMass.mVec128.m128_f32[2] * c->m_contactNormal.mVec128.m128_f32[2];
  if ( body1->m_inverseMass != 0.0 )
  {
    v10 = body1->m_deltaLinearVelocity.mVec128.m128_f32[0]
        + (float)((float)(body1->m_invMass.mVec128.m128_f32[0] * c->m_contactNormal.mVec128.m128_f32[0]) * v6);
    body1->m_deltaLinearVelocity.mVec128.m128_f32[1] = body1->m_deltaLinearVelocity.mVec128.m128_f32[1]
                                                     + (float)((float)(body1->m_invMass.mVec128.m128_f32[1]
                                                                     * c->m_contactNormal.mVec128.m128_f32[1])
                                                             * v6);
    body1->m_deltaLinearVelocity.mVec128.m128_f32[0] = v10;
    body1->m_deltaLinearVelocity.mVec128.m128_f32[2] = body1->m_deltaLinearVelocity.mVec128.m128_f32[2]
                                                     + (float)(v9 * v6);
    v11 = c->m_angularComponentA.mVec128.m128_f32[1] * (float)(body1->m_angularFactor.mVec128.m128_f32[1] * v6);
    v12 = c->m_angularComponentA.mVec128.m128_f32[2] * (float)(body1->m_angularFactor.mVec128.m128_f32[2] * v6);
    body1->m_deltaAngularVelocity.mVec128.m128_f32[0] = body1->m_deltaAngularVelocity.mVec128.m128_f32[0]
                                                      + (float)(c->m_angularComponentA.mVec128.m128_f32[0]
                                                              * (float)(body1->m_angularFactor.mVec128.m128_f32[0] * v6));
    body1->m_deltaAngularVelocity.mVec128.m128_f32[1] = body1->m_deltaAngularVelocity.mVec128.m128_f32[1] + v11;
    body1->m_deltaAngularVelocity.mVec128.m128_f32[2] = body1->m_deltaAngularVelocity.mVec128.m128_f32[2] + v12;
  }
  v13 = body2->m_invMass.mVec128.m128_f32[1] * COERCE_FLOAT(c->m_contactNormal.mVec128.m128_i32[1] ^ _mask__NegFloat_);
  v14 = body2->m_invMass.mVec128.m128_f32[2] * COERCE_FLOAT(c->m_contactNormal.mVec128.m128_i32[2] ^ _mask__NegFloat_);
  if ( body2->m_inverseMass != 0.0 )
  {
    body2->m_deltaLinearVelocity.mVec128.m128_f32[0] = (float)((float)(body2->m_invMass.mVec128.m128_f32[0]
                                                                     * COERCE_FLOAT(
                                                                         c->m_contactNormal.mVec128.m128_i32[0]
                                                                       ^ _mask__NegFloat_))
                                                             * v6)
                                                     + body2->m_deltaLinearVelocity.mVec128.m128_f32[0];
    body2->m_deltaLinearVelocity.mVec128.m128_f32[1] = body2->m_deltaLinearVelocity.mVec128.m128_f32[1]
                                                     + (float)(v13 * v6);
    body2->m_deltaLinearVelocity.mVec128.m128_f32[2] = body2->m_deltaLinearVelocity.mVec128.m128_f32[2]
                                                     + (float)(v14 * v6);
    v15 = c->m_angularComponentB.mVec128.m128_f32[2] * (float)(body2->m_angularFactor.mVec128.m128_f32[2] * v6);
    v16 = body2->m_deltaAngularVelocity.mVec128.m128_f32[0]
        + (float)(c->m_angularComponentB.mVec128.m128_f32[0] * (float)(body2->m_angularFactor.mVec128.m128_f32[0] * v6));
    body2->m_deltaAngularVelocity.mVec128.m128_f32[1] = body2->m_deltaAngularVelocity.mVec128.m128_f32[1]
                                                      + (float)(c->m_angularComponentB.mVec128.m128_f32[1]
                                                              * (float)(body2->m_angularFactor.mVec128.m128_f32[1] * v6));
    v17 = body2->m_deltaAngularVelocity.mVec128.m128_f32[2] + v15;
    body2->m_deltaAngularVelocity.mVec128.m128_f32[0] = v16;
    body2->m_deltaAngularVelocity.mVec128.m128_f32[2] = v17;
  }
}
