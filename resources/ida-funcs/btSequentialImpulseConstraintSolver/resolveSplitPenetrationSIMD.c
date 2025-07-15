void __userpurge btSequentialImpulseConstraintSolver::resolveSplitPenetrationSIMD(
        btRigidBody *body2@<ecx>,
        const btSolverConstraint *c@<eax>,
        btRigidBody *body1)
{
  btVector3 v3; // xmm3
  __m128 v4; // xmm0
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  __m128 v7; // xmm5
  __m128 v8; // xmm3
  __m128 m_lowerLimit_low; // xmm4
  __m128 v10; // xmm6
  __m128 v11; // xmm7
  __m128 v12; // xmm1
  __m128 v13; // xmm0
  __m128 v14; // xmm5
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm1
  __m128 v18; // xmm0
  btVector3 v19; // xmm2
  __m128 v20; // xmm4
  __m128 v21; // xmm1
  btVector3 v22; // xmm0
  btVector3 v23; // xmm2

  v3.mVec128 = (__m128)c->m_contactNormal;
  v4 = _mm_mul_ps(body1->m_turnVelocity.mVec128, c->m_relpos1CrossNormal.mVec128);
  v5 = _mm_mul_ps(body1->m_pushVelocity.mVec128, v3.mVec128);
  v6 = _mm_mul_ps(body2->m_pushVelocity.mVec128, v3.mVec128);
  v7 = (__m128)c->m_appliedPushImpulse.m_vec128.m128_u32[0];
  v8 = _mm_mul_ps(c->m_relpos2CrossNormal.mVec128, body2->m_turnVelocity.mVec128);
  m_lowerLimit_low = (__m128)LODWORD(c->m_lowerLimit);
  v10 = _mm_shuffle_ps((__m128)LODWORD(c->m_jacDiagABInv), (__m128)LODWORD(c->m_jacDiagABInv), 0);
  v11 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 170), _mm_shuffle_ps(v5, v5, 85)), _mm_shuffle_ps(v5, v5, 0)),
          _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v4, v4, 170), _mm_shuffle_ps(v4, v4, 85)), _mm_shuffle_ps(v4, v4, 0)));
  v12 = _mm_shuffle_ps((__m128)LODWORD(c->m_cfm), (__m128)LODWORD(c->m_cfm), 0);
  v13 = _mm_shuffle_ps((__m128)LODWORD(c->m_rhsPenetration), (__m128)LODWORD(c->m_rhsPenetration), 0);
  ++gNumSplitImpulseRecoveries;
  v14 = _mm_shuffle_ps(v7, v7, 0);
  v15 = _mm_sub_ps(
          _mm_sub_ps(_mm_sub_ps(v13, _mm_mul_ps(v12, v14)), _mm_mul_ps(v11, v10)),
          _mm_mul_ps(
            _mm_sub_ps(
              _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 170), _mm_shuffle_ps(v8, v8, 85)), _mm_shuffle_ps(v8, v8, 0)),
              _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 170), _mm_shuffle_ps(v6, v6, 85)), _mm_shuffle_ps(v6, v6, 0))),
            v10));
  v16 = _mm_shuffle_ps(m_lowerLimit_low, m_lowerLimit_low, 0);
  v17 = _mm_add_ps(v15, v14);
  v18 = _mm_cmplt_ps(v17, v16);
  c->m_appliedImpulse.m_vec128 = _mm_or_ps(_mm_andnot_ps(v18, v17), _mm_and_ps(v18, v16));
  v19.mVec128 = (__m128)c->m_contactNormal;
  v20 = _mm_or_ps(_mm_and_ps(_mm_sub_ps(v16, v14), v18), _mm_andnot_ps(v18, v15));
  v21 = _mm_mul_ps(body2->m_invMass.mVec128, v19.mVec128);
  v22.mVec128 = _mm_add_ps(
                  _mm_mul_ps(_mm_mul_ps(body1->m_invMass.mVec128, v19.mVec128), v20),
                  body1->m_pushVelocity.mVec128);
  v23.mVec128 = (__m128)body1->m_turnVelocity;
  body1->m_pushVelocity = (btVector3)v22.mVec128;
  body1->m_turnVelocity.mVec128 = _mm_add_ps(_mm_mul_ps(c->m_angularComponentA.mVec128, v20), v23.mVec128);
  body2->m_pushVelocity.mVec128 = _mm_sub_ps(body2->m_pushVelocity.mVec128, _mm_mul_ps(v20, v21));
  body2->m_turnVelocity.mVec128 = _mm_add_ps(
                                    _mm_mul_ps(c->m_angularComponentB.mVec128, v20),
                                    body2->m_turnVelocity.mVec128);
}
