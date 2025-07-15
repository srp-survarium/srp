void __usercall btSequentialImpulseConstraintSolver::resolveSplitPenetrationImpulseCacheFriendly(
        btRigidBody *body1@<edx>,
        btRigidBody *body2@<esi>,
        const btSolverConstraint *c@<ecx>)
{
  __m128 v3; // xmm3
  float m_jacDiagABInv; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  __m128 m_lowerLimit_low; // xmm2
  __m128 v10; // xmm1
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm4_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm0_4

  v3 = (__m128)c->m_appliedPushImpulse.m_vec128.m128_u32[0];
  m_jacDiagABInv = c->m_jacDiagABInv;
  v5 = c->m_rhsPenetration - (float)(c->m_cfm * v3.m128_f32[0]);
  v6 = (float)((float)((float)((float)((float)(body1->m_pushVelocity.mVec128.m128_f32[2]
                                             * c->m_contactNormal.mVec128.m128_f32[2])
                                     + (float)(body1->m_pushVelocity.mVec128.m128_f32[1]
                                             * c->m_contactNormal.mVec128.m128_f32[1]))
                             + (float)(body1->m_turnVelocity.mVec128.m128_f32[2]
                                     * c->m_relpos1CrossNormal.mVec128.m128_f32[2]))
                     + (float)(body1->m_turnVelocity.mVec128.m128_f32[1] * c->m_relpos1CrossNormal.mVec128.m128_f32[1]))
             + (float)(c->m_contactNormal.mVec128.m128_f32[0] * body1->m_pushVelocity.mVec128.m128_f32[0]))
     + (float)(c->m_relpos1CrossNormal.mVec128.m128_f32[0] * body1->m_turnVelocity.mVec128.m128_f32[0]);
  v7 = body2->m_pushVelocity.mVec128.m128_f32[2] * c->m_contactNormal.mVec128.m128_f32[2];
  ++gNumSplitImpulseRecoveries;
  v8 = (float)(v5 - (float)(v6 * m_jacDiagABInv))
     - (float)((float)((float)((float)((float)((float)((float)(body2->m_turnVelocity.mVec128.m128_f32[2]
                                                             * c->m_relpos2CrossNormal.mVec128.m128_f32[2])
                                                     - v7)
                                             - (float)(body2->m_pushVelocity.mVec128.m128_f32[1]
                                                     * c->m_contactNormal.mVec128.m128_f32[1]))
                                     + (float)(body2->m_turnVelocity.mVec128.m128_f32[1]
                                             * c->m_relpos2CrossNormal.mVec128.m128_f32[1]))
                             - (float)(body2->m_pushVelocity.mVec128.m128_f32[0] * c->m_contactNormal.mVec128.m128_f32[0]))
                     + (float)(body2->m_turnVelocity.mVec128.m128_f32[0] * c->m_relpos2CrossNormal.mVec128.m128_f32[0]))
             * m_jacDiagABInv);
  m_lowerLimit_low = (__m128)LODWORD(c->m_lowerLimit);
  v10 = v3;
  if ( m_lowerLimit_low.m128_f32[0] <= (float)(v3.m128_f32[0] + v8) )
  {
    v10.m128_f32[0] = v3.m128_f32[0] + v8;
    c->m_appliedPushImpulse.m_vec128 = _mm_shuffle_ps(v10, v10, 0);
  }
  else
  {
    v8 = c->m_lowerLimit - v3.m128_f32[0];
    c->m_appliedPushImpulse.m_vec128 = _mm_shuffle_ps(m_lowerLimit_low, m_lowerLimit_low, 0);
  }
  v11 = body1->m_invMass.mVec128.m128_f32[0] * c->m_contactNormal.mVec128.m128_f32[0];
  v12 = body1->m_invMass.mVec128.m128_f32[2] * c->m_contactNormal.mVec128.m128_f32[2];
  if ( body1->m_inverseMass != 0.0 )
  {
    v13 = body1->m_pushVelocity.mVec128.m128_f32[0];
    body1->m_pushVelocity.mVec128.m128_f32[1] = (float)((float)(body1->m_invMass.mVec128.m128_f32[1]
                                                              * c->m_contactNormal.mVec128.m128_f32[1])
                                                      * v8)
                                              + body1->m_pushVelocity.mVec128.m128_f32[1];
    body1->m_pushVelocity.mVec128.m128_f32[0] = v13 + (float)(v11 * v8);
    body1->m_pushVelocity.mVec128.m128_f32[2] = (float)(v12 * v8) + body1->m_pushVelocity.mVec128.m128_f32[2];
    v14 = c->m_angularComponentA.mVec128.m128_f32[1] * (float)(body1->m_angularFactor.mVec128.m128_f32[1] * v8);
    v15 = c->m_angularComponentA.mVec128.m128_f32[2] * (float)(body1->m_angularFactor.mVec128.m128_f32[2] * v8);
    body1->m_turnVelocity.mVec128.m128_f32[0] = body1->m_turnVelocity.mVec128.m128_f32[0]
                                              + (float)(c->m_angularComponentA.mVec128.m128_f32[0]
                                                      * (float)(body1->m_angularFactor.mVec128.m128_f32[0] * v8));
    body1->m_turnVelocity.mVec128.m128_f32[1] = body1->m_turnVelocity.mVec128.m128_f32[1] + v14;
    body1->m_turnVelocity.mVec128.m128_f32[2] = body1->m_turnVelocity.mVec128.m128_f32[2] + v15;
  }
  v16 = body2->m_invMass.mVec128.m128_f32[1] * COERCE_FLOAT(c->m_contactNormal.mVec128.m128_i32[1] ^ _mask__NegFloat_);
  v17 = body2->m_invMass.mVec128.m128_f32[2] * COERCE_FLOAT(c->m_contactNormal.mVec128.m128_i32[2] ^ _mask__NegFloat_);
  if ( body2->m_inverseMass != 0.0 )
  {
    body2->m_pushVelocity.mVec128.m128_f32[0] = (float)((float)(body2->m_invMass.mVec128.m128_f32[0]
                                                              * COERCE_FLOAT(
                                                                  c->m_contactNormal.mVec128.m128_i32[0]
                                                                ^ _mask__NegFloat_))
                                                      * v8)
                                              + body2->m_pushVelocity.mVec128.m128_f32[0];
    body2->m_pushVelocity.mVec128.m128_f32[1] = (float)(v16 * v8) + body2->m_pushVelocity.mVec128.m128_f32[1];
    body2->m_pushVelocity.mVec128.m128_f32[2] = (float)(v17 * v8) + body2->m_pushVelocity.mVec128.m128_f32[2];
    v18 = c->m_angularComponentB.mVec128.m128_f32[2] * (float)(body2->m_angularFactor.mVec128.m128_f32[2] * v8);
    v19 = body2->m_turnVelocity.mVec128.m128_f32[0]
        + (float)(c->m_angularComponentB.mVec128.m128_f32[0] * (float)(body2->m_angularFactor.mVec128.m128_f32[0] * v8));
    body2->m_turnVelocity.mVec128.m128_f32[1] = body2->m_turnVelocity.mVec128.m128_f32[1]
                                              + (float)(c->m_angularComponentB.mVec128.m128_f32[1]
                                                      * (float)(body2->m_angularFactor.mVec128.m128_f32[1] * v8));
    v20 = body2->m_turnVelocity.mVec128.m128_f32[2] + v18;
    body2->m_turnVelocity.mVec128.m128_f32[0] = v19;
    body2->m_turnVelocity.mVec128.m128_f32[2] = v20;
  }
}
