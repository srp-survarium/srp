void __usercall btSequentialImpulseConstraintSolver::resolveSplitPenetrationImpulseCacheFriendly(
        btRigidBody *body1@<edx>,
        btRigidBody *body2@<esi>,
        const btSolverConstraint *c@<ecx>)
{
  __m128 v3; // xmm2
  float m_jacDiagABInv; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  __m128 m_lowerLimit_low; // xmm3
  __m128 v10; // xmm1
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm0_4

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
  v11 = body1->m_invMass.mVec128.m128_f32[1] * c->m_contactNormal.mVec128.m128_f32[1];
  v12 = body1->m_invMass.mVec128.m128_f32[2] * c->m_contactNormal.mVec128.m128_f32[2];
  if ( body1->m_inverseMass != 0.0 )
  {
    body1->m_pushVelocity.mVec128.m128_f32[0] = body1->m_pushVelocity.mVec128.m128_f32[0]
                                              + (float)((float)(body1->m_invMass.mVec128.m128_f32[0]
                                                              * c->m_contactNormal.mVec128.m128_f32[0])
                                                      * v8);
    body1->m_pushVelocity.mVec128.m128_f32[1] = (float)(v11 * v8) + body1->m_pushVelocity.mVec128.m128_f32[1];
    body1->m_pushVelocity.mVec128.m128_f32[2] = (float)(v12 * v8) + body1->m_pushVelocity.mVec128.m128_f32[2];
    v13 = c->m_angularComponentA.mVec128.m128_f32[1] * (float)(body1->m_angularFactor.mVec128.m128_f32[1] * v8);
    v14 = c->m_angularComponentA.mVec128.m128_f32[2] * (float)(body1->m_angularFactor.mVec128.m128_f32[2] * v8);
    body1->m_turnVelocity.mVec128.m128_f32[0] = body1->m_turnVelocity.mVec128.m128_f32[0]
                                              + (float)(c->m_angularComponentA.mVec128.m128_f32[0]
                                                      * (float)(body1->m_angularFactor.mVec128.m128_f32[0] * v8));
    v15 = body1->m_turnVelocity.mVec128.m128_f32[1] + v13;
    v16 = body1->m_turnVelocity.mVec128.m128_f32[2] + v14;
    body1->m_turnVelocity.mVec128.m128_f32[1] = v15;
    body1->m_turnVelocity.mVec128.m128_f32[2] = v16;
  }
  v17 = body2->m_invMass.mVec128.m128_f32[1] * (float)-c->m_contactNormal.mVec128.m128_f32[1];
  v18 = body2->m_invMass.mVec128.m128_f32[2] * (float)-c->m_contactNormal.mVec128.m128_f32[2];
  if ( body2->m_inverseMass != 0.0 )
  {
    body2->m_pushVelocity.mVec128.m128_f32[0] = (float)((float)(body2->m_invMass.mVec128.m128_f32[0]
                                                              * (float)-c->m_contactNormal.mVec128.m128_f32[0])
                                                      * v8)
                                              + body2->m_pushVelocity.mVec128.m128_f32[0];
    body2->m_pushVelocity.mVec128.m128_f32[1] = (float)(v17 * v8) + body2->m_pushVelocity.mVec128.m128_f32[1];
    body2->m_pushVelocity.mVec128.m128_f32[2] = (float)(v18 * v8) + body2->m_pushVelocity.mVec128.m128_f32[2];
    v19 = c->m_angularComponentB.mVec128.m128_f32[2] * (float)(body2->m_angularFactor.mVec128.m128_f32[2] * v8);
    v20 = body2->m_turnVelocity.mVec128.m128_f32[0]
        + (float)(c->m_angularComponentB.mVec128.m128_f32[0] * (float)(body2->m_angularFactor.mVec128.m128_f32[0] * v8));
    body2->m_turnVelocity.mVec128.m128_f32[1] = body2->m_turnVelocity.mVec128.m128_f32[1]
                                              + (float)(c->m_angularComponentB.mVec128.m128_f32[1]
                                                      * (float)(body2->m_angularFactor.mVec128.m128_f32[1] * v8));
    v21 = body2->m_turnVelocity.mVec128.m128_f32[2] + v19;
    body2->m_turnVelocity.mVec128.m128_f32[0] = v20;
    body2->m_turnVelocity.mVec128.m128_f32[2] = v21;
  }
}
