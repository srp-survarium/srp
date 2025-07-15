void __userpurge btSequentialImpulseConstraintSolver::resolveSingleConstraintRowGenericSIMD(
        btRigidBody *body2@<ecx>,
        const btSolverConstraint *c@<eax>,
        btSequentialImpulseConstraintSolver *this,
        btRigidBody *body1)
{
  btVector3 v4; // xmm3
  __m128 v5; // xmm0
  __m128 v6; // xmm2
  __m128 v7; // xmm3
  __m128 v8; // xmm1
  __m128 v9; // xmm6
  __m128 v10; // xmm4
  __m128 v11; // xmm1
  __m128 v12; // xmm0
  __m128 v13; // xmm5
  btSimdScalar v14; // xmm3
  __m128 v15; // xmm1
  btVector3 v16; // xmm3
  btVector3 v17; // xmm2
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  __m128 v20; // [esp+0h] [ebp-20h]
  __m128 v21; // [esp+10h] [ebp-10h]

  v4.mVec128 = (__m128)c->m_contactNormal;
  v5 = _mm_mul_ps(c->m_relpos1CrossNormal.mVec128, *(__m128 *)&this[4].m_tmpSolverContactFrictionConstraintPool.m_size);
  v6 = _mm_mul_ps(v4.mVec128, *(__m128 *)&this[4].m_tmpSolverNonContactConstraintPool.m_capacity);
  v7 = _mm_mul_ps(v4.mVec128, body2->m_deltaLinearVelocity.mVec128);
  v8 = _mm_mul_ps(c->m_relpos2CrossNormal.mVec128, body2->m_deltaAngularVelocity.mVec128);
  v20 = _mm_shuffle_ps((__m128)LODWORD(c->m_jacDiagABInv), (__m128)LODWORD(c->m_jacDiagABInv), 0);
  v9 = _mm_shuffle_ps(
         (__m128)c->m_appliedImpulse.m_vec128.m128_u32[0],
         (__m128)c->m_appliedImpulse.m_vec128.m128_u32[0],
         0);
  v21 = _mm_sub_ps(
          _mm_sub_ps(
            _mm_sub_ps(
              _mm_shuffle_ps((__m128)LODWORD(c->m_rhs), (__m128)LODWORD(c->m_rhs), 0),
              _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(c->m_cfm), (__m128)LODWORD(c->m_cfm), 0), v9)),
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v6, v6, 170), _mm_shuffle_ps(v6, v6, 85)),
                  _mm_shuffle_ps(v6, v6, 0)),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v5, v5, 170), _mm_shuffle_ps(v5, v5, 85)),
                  _mm_shuffle_ps(v5, v5, 0))),
              v20)),
          _mm_mul_ps(
            _mm_sub_ps(
              _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 170), _mm_shuffle_ps(v8, v8, 85)), _mm_shuffle_ps(v8, v8, 0)),
              _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 170), _mm_shuffle_ps(v7, v7, 85)), _mm_shuffle_ps(v7, v7, 0))),
            v20));
  v10 = _mm_shuffle_ps((__m128)LODWORD(c->m_lowerLimit), (__m128)LODWORD(c->m_lowerLimit), 0);
  v11 = _mm_add_ps(v21, v9);
  v12 = _mm_cmplt_ps(v11, v10);
  v13 = _mm_shuffle_ps((__m128)LODWORD(c->m_upperLimit), (__m128)LODWORD(c->m_upperLimit), 0);
  v14.m_vec128 = _mm_or_ps(_mm_andnot_ps(v12, v11), _mm_and_ps(v12, v10));
  v15 = _mm_cmplt_ps(v11, v13);
  c->m_appliedImpulse = (btSimdScalar)v14.m_vec128;
  v16.mVec128 = (__m128)c->m_contactNormal;
  c->m_appliedImpulse.m_vec128 = _mm_or_ps(_mm_andnot_ps(v15, v13), _mm_and_ps(v15, c->m_appliedImpulse.m_vec128));
  v17.mVec128 = (__m128)body2->m_invMass;
  v18 = _mm_or_ps(
          _mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_sub_ps(v10, v9), v12), _mm_andnot_ps(v12, v21)), v15),
          _mm_andnot_ps(v15, _mm_sub_ps(v13, v9)));
  v19 = *(__m128 *)&this[4].m_tmpSolverContactFrictionConstraintPool.m_size;
  *(__m128 *)&this[4].m_tmpSolverNonContactConstraintPool.m_capacity = _mm_add_ps(
                                                                         _mm_mul_ps(
                                                                           _mm_mul_ps(
                                                                             *(__m128 *)&this[4].m_orderTmpConstraintPool.m_ownsMemory,
                                                                             v16.mVec128),
                                                                           v18),
                                                                         *(__m128 *)&this[4].m_tmpSolverNonContactConstraintPool.m_capacity);
  *(__m128 *)&this[4].m_tmpSolverContactFrictionConstraintPool.m_size = _mm_add_ps(
                                                                          _mm_mul_ps(
                                                                            c->m_angularComponentA.mVec128,
                                                                            v18),
                                                                          v19);
  body2->m_deltaLinearVelocity.mVec128 = _mm_sub_ps(
                                           body2->m_deltaLinearVelocity.mVec128,
                                           _mm_mul_ps(v18, _mm_mul_ps(v17.mVec128, v16.mVec128)));
  body2->m_deltaAngularVelocity.mVec128 = _mm_add_ps(
                                            _mm_mul_ps(c->m_angularComponentB.mVec128, v18),
                                            body2->m_deltaAngularVelocity.mVec128);
}
