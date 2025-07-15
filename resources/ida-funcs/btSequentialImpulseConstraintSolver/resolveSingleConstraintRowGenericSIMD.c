void __userpurge btSequentialImpulseConstraintSolver::resolveSingleConstraintRowGenericSIMD(
        btRigidBody *body2@<ecx>,
        const btSolverConstraint *c@<eax>,
        btSequentialImpulseConstraintSolver *this,
        btRigidBody *body1)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm3
  __m128 v7; // xmm4
  __m128 v8; // xmm6
  __m128 v9; // xmm0
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm5
  btSimdScalar v13; // xmm4
  __m128 v14; // xmm2
  btVector3 v15; // xmm4
  btVector3 v16; // xmm3
  __m128 v17; // xmm0
  __m128 v18; // xmm2
  __m128 v19; // [esp+10h] [ebp-20h]
  __m128 v20; // [esp+20h] [ebp-10h]

  v4 = _mm_mul_ps(c->m_relpos1CrossNormal.mVec128, *(__m128 *)&this[4].m_orderTmpConstraintPool.m_ownsMemory);
  v5 = _mm_mul_ps(c->m_contactNormal.mVec128, *(__m128 *)&this[4].m_orderTmpConstraintPool.m_allocator);
  v6 = _mm_mul_ps(c->m_contactNormal.mVec128, body2->m_deltaLinearVelocity.mVec128);
  v7 = _mm_mul_ps(c->m_relpos2CrossNormal.mVec128, body2->m_deltaAngularVelocity.mVec128);
  v19 = _mm_shuffle_ps((__m128)LODWORD(c->m_jacDiagABInv), (__m128)LODWORD(c->m_jacDiagABInv), 0);
  v8 = _mm_shuffle_ps(
         (__m128)c->m_appliedImpulse.m_vec128.m128_u32[0],
         (__m128)c->m_appliedImpulse.m_vec128.m128_u32[0],
         0);
  v20 = _mm_sub_ps(
          _mm_sub_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(c->m_rhs), (__m128)LODWORD(c->m_rhs), 0),
              _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(c->m_cfm), (__m128)LODWORD(c->m_cfm), 0), v8)),
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v5, v5, 170), _mm_shuffle_ps(v5, v5, 85)),
                  _mm_shuffle_ps(v5, v5, 0)),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v4, v4, 170), _mm_shuffle_ps(v4, v4, 85)),
                  _mm_shuffle_ps(v4, v4, 0))),
              v19)),
          _mm_mul_ps(
            _mm_sub_ps(
              _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 170), _mm_shuffle_ps(v7, v7, 85)), _mm_shuffle_ps(v7, v7, 0)),
              _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 170), _mm_shuffle_ps(v6, v6, 85)), _mm_shuffle_ps(v6, v6, 0))),
            v19));
  v9 = _mm_shuffle_ps((__m128)LODWORD(c->m_lowerLimit), (__m128)LODWORD(c->m_lowerLimit), 0);
  v10 = _mm_add_ps(v20, v8);
  v11 = _mm_cmplt_ps(v10, v9);
  v12 = _mm_shuffle_ps((__m128)LODWORD(c->m_upperLimit), (__m128)LODWORD(c->m_upperLimit), 0);
  v13.m_vec128 = _mm_or_ps(_mm_andnot_ps(v11, v10), _mm_and_ps(v11, v9));
  v14 = _mm_cmplt_ps(v10, v12);
  c->m_appliedImpulse = (btSimdScalar)v13.m_vec128;
  v15.mVec128 = (__m128)c->m_contactNormal;
  c->m_appliedImpulse.m_vec128 = _mm_or_ps(_mm_andnot_ps(v14, v12), _mm_and_ps(v14, c->m_appliedImpulse.m_vec128));
  v16.mVec128 = (__m128)body2->m_invMass;
  v17 = _mm_or_ps(
          _mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_sub_ps(v9, v8), v11), _mm_andnot_ps(v11, v20)), v14),
          _mm_andnot_ps(v14, _mm_sub_ps(v12, v8)));
  v18 = *(__m128 *)&this[4].m_orderTmpConstraintPool.m_ownsMemory;
  *(__m128 *)&this[4].m_orderTmpConstraintPool.m_allocator = _mm_add_ps(
                                                               _mm_mul_ps(
                                                                 _mm_mul_ps(
                                                                   *(__m128 *)&this[4].m_tmpConstraintSizesPool.m_capacity,
                                                                   v15.mVec128),
                                                                 v17),
                                                               *(__m128 *)&this[4].m_orderTmpConstraintPool.m_allocator);
  *(__m128 *)&this[4].m_orderTmpConstraintPool.m_ownsMemory = _mm_add_ps(
                                                                _mm_mul_ps(c->m_angularComponentA.mVec128, v17),
                                                                v18);
  body2->m_deltaLinearVelocity.mVec128 = _mm_sub_ps(
                                           body2->m_deltaLinearVelocity.mVec128,
                                           _mm_mul_ps(v17, _mm_mul_ps(v16.mVec128, v15.mVec128)));
  body2->m_deltaAngularVelocity.mVec128 = _mm_add_ps(
                                            _mm_mul_ps(c->m_angularComponentB.mVec128, v17),
                                            body2->m_deltaAngularVelocity.mVec128);
}
