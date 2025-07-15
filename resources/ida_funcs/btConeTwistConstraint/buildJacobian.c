void __usercall btConeTwistConstraint::buildJacobian(btConeTwistConstraint *this@<ecx>, float *m128_f32@<edi>)
{
  bool v3; // zf
  float *m_rbA; // eax
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float *m_rbB; // eax
  float v16; // xmm3_4
  float v17; // xmm5_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  long double v21; // st7
  long double v22; // st7
  long double v23; // st7
  btJacobianEntry *m_jac; // edx
  btRigidBody *v25; // eax
  btRigidBody *v26; // ecx
  int v27; // xmm0_4
  float jointAxisa; // [esp+2B8h] [ebp-F8h]
  float jointAxisb; // [esp+2B8h] [ebp-F8h]
  float jointAxisc; // [esp+2B8h] [ebp-F8h]
  btVector3 *jointAxis; // [esp+2B8h] [ebp-F8h]
  float v32; // [esp+2BCh] [ebp-F4h]
  float v33; // [esp+2BCh] [ebp-F4h]
  int v34; // [esp+2BCh] [ebp-F4h]
  btVector3 rel_pos1; // [esp+2C0h] [ebp-F0h] BYREF
  btJacobianEntry *v36; // [esp+2DCh] [ebp-D4h]
  btVector3 rel_pos2; // [esp+2E0h] [ebp-D0h] BYREF
  __m128i _X; // [esp+2F0h] [ebp-C0h] BYREF
  float v39; // [esp+300h] [ebp-B0h]
  float v40; // [esp+304h] [ebp-ACh]
  float v41; // [esp+308h] [ebp-A8h]
  float v42; // [esp+310h] [ebp-A0h]
  float v43; // [esp+314h] [ebp-9Ch]
  float v44; // [esp+318h] [ebp-98h]
  float m_inverseMass; // [esp+328h] [ebp-88h]
  float massInvA; // [esp+32Ch] [ebp-84h]
  float v47; // [esp+330h] [ebp-80h]
  float v48; // [esp+334h] [ebp-7Ch]
  float v49; // [esp+338h] [ebp-78h]
  float v50; // [esp+340h] [ebp-70h]
  float v51; // [esp+344h] [ebp-6Ch]
  float v52; // [esp+348h] [ebp-68h]
  btMatrix3x3 world2B; // [esp+350h] [ebp-60h]
  btMatrix3x3 world2A; // [esp+380h] [ebp-30h]

  if ( this->m_useSolveConstraintObsolete )
  {
    v3 = !this->m_angularOnly;
    this->m_appliedImpulse = 0.0;
    this->m_accTwistLimitImpulse = 0.0;
    this->m_accSwingLimitImpulse = 0.0;
    memset(&rel_pos1, 0, sizeof(rel_pos1));
    this->m_accMotorImpulse.mVec128.m128_u64[0] = 0;
    this->m_accMotorImpulse.mVec128.m128_u64[1] = rel_pos1.mVec128.m128_u64[1];
    if ( v3 )
    {
      m_rbA = (float *)this->m_rbA;
      v5 = this->m_rbAFrame.m_origin.mVec128.m128_f32[2];
      v6 = this->m_rbAFrame.m_origin.mVec128.m128_f32[1];
      v7 = m_rbA[10];
      v8 = m_rbA[5] * v6;
      v9 = m_rbA[6] * v5;
      m_rbA += 4;
      v10 = this->m_rbBFrame.m_origin.mVec128.m128_f32[2];
      v11 = this->m_rbBFrame.m_origin.mVec128.m128_f32[1];
      v12 = (float)((float)(v8 + v9) + (float)(this->m_rbAFrame.m_origin.mVec128.m128_f32[0] * *m_rbA)) + m_rbA[12];
      v13 = (float)((float)((float)(m_rbA[5] * v6) + (float)(v7 * v5))
                  + (float)(this->m_rbAFrame.m_origin.mVec128.m128_f32[0] * m_rbA[4]))
          + m_rbA[13];
      v14 = (float)((float)((float)(m_rbA[9] * v6) + (float)(m_rbA[10] * v5))
                  + (float)(this->m_rbAFrame.m_origin.mVec128.m128_f32[0] * m_rbA[8]))
          + m_rbA[14];
      m_rbB = (float *)this->m_rbB;
      v16 = m_rbB[5];
      v17 = m_rbB[6];
      m_rbB += 4;
      jointAxisa = this->m_rbBFrame.m_origin.mVec128.m128_f32[0];
      v18 = (float)((float)((float)(v16 * v11) + (float)(v17 * v10)) + (float)(jointAxisa * *m_rbB)) + m_rbB[12];
      v19 = (float)((float)((float)(m_rbB[5] * v11) + (float)(m_rbB[6] * v10)) + (float)(jointAxisa * m_rbB[4]))
          + m_rbB[13];
      v20 = (float)((float)((float)(m_rbB[9] * v11) + (float)(m_rbB[10] * v10)) + (float)(jointAxisa * m_rbB[8]))
          + m_rbB[14];
      v47 = v12;
      v48 = v13;
      v50 = v18;
      v51 = v19;
      v52 = v20;
      v49 = v14;
      rel_pos1.mVec128.m128_f32[0] = v18 - v12;
      rel_pos1.mVec128.m128_f32[1] = v19 - v13;
      rel_pos1.mVec128.m128_f32[2] = v20 - v14;
      if ( (float)((float)((float)(rel_pos1.mVec128.m128_f32[2] * rel_pos1.mVec128.m128_f32[2])
                         + (float)(rel_pos1.mVec128.m128_f32[1] * rel_pos1.mVec128.m128_f32[1]))
                 + (float)(rel_pos1.mVec128.m128_f32[0] * rel_pos1.mVec128.m128_f32[0])) <= 0.00000011920929 )
      {
        _X.m128i_i64[0] = (unsigned int)clear_value;
        _X.m128i_i64[1] = 0;
      }
      else
      {
        v21 = 1.0
            / sqrtf(
                (float)((float)(rel_pos1.mVec128.m128_f32[2] * rel_pos1.mVec128.m128_f32[2])
                      + (float)(rel_pos1.mVec128.m128_f32[1] * rel_pos1.mVec128.m128_f32[1]))
              + (float)(rel_pos1.mVec128.m128_f32[0] * rel_pos1.mVec128.m128_f32[0]));
        rel_pos2.mVec128.m128_i32[3] = 0;
        rel_pos2.mVec128.m128_f32[0] = rel_pos1.mVec128.m128_f32[0] * v21;
        rel_pos2.mVec128.m128_f32[1] = rel_pos1.mVec128.m128_f32[1] * v21;
        rel_pos2.mVec128.m128_f32[2] = v21 * rel_pos1.mVec128.m128_f32[2];
        _X = _mm_load_si128((const __m128i *)&rel_pos2);
      }
      if ( fabsf(*(float *)&_X.m128i_i32[2]) <= hsqt2 )
      {
        jointAxisc = (float)(*(float *)&_X.m128i_i32[1] * *(float *)&_X.m128i_i32[1])
                   + (float)(*(float *)_X.m128i_i32 * *(float *)_X.m128i_i32);
        v23 = sqrtf(jointAxisc);
        v41 = 0.0;
        v33 = 1.0 / v23;
        v40 = v33 * *(float *)_X.m128i_i32;
        v39 = -(float)(*(float *)&_X.m128i_i32[1] * v33);
        v42 = -(float)((float)(v33 * *(float *)_X.m128i_i32) * *(float *)&_X.m128i_i32[2]);
        v43 = v39 * *(float *)&_X.m128i_i32[2];
        v44 = v33 * jointAxisc;
      }
      else
      {
        jointAxisb = (float)(*(float *)&_X.m128i_i32[2] * *(float *)&_X.m128i_i32[2])
                   + (float)(*(float *)&_X.m128i_i32[1] * *(float *)&_X.m128i_i32[1]);
        v22 = sqrtf(jointAxisb);
        v39 = 0.0;
        v32 = 1.0 / v22;
        v41 = *(float *)&_X.m128i_i32[1] * v32;
        v42 = v32 * jointAxisb;
        v40 = -(float)(*(float *)&_X.m128i_i32[2] * v32);
        v43 = -(float)((float)(*(float *)&_X.m128i_i32[1] * v32) * *(float *)_X.m128i_i32);
        v44 = v40 * *(float *)_X.m128i_i32;
      }
      m_jac = this->m_jac;
      jointAxis = (btVector3 *)&_X;
      v36 = this->m_jac;
      v34 = 3;
      do
      {
        if ( m_jac )
        {
          v25 = this->m_rbB;
          v26 = this->m_rbA;
          m_inverseMass = v25->m_inverseMass;
          massInvA = v26->m_inverseMass;
          rel_pos2.mVec128.m128_f32[0] = v50 - v25->m_worldTransform.m_origin.mVec128.m128_f32[0];
          rel_pos2.mVec128.m128_f32[1] = v51 - v25->m_worldTransform.m_origin.mVec128.m128_f32[1];
          rel_pos2.mVec128.m128_f32[2] = v52 - v25->m_worldTransform.m_origin.mVec128.m128_f32[2];
          rel_pos1.mVec128.m128_f32[0] = v47 - v26->m_worldTransform.m_origin.mVec128.m128_f32[0];
          rel_pos1.mVec128.m128_f32[1] = v48 - v26->m_worldTransform.m_origin.mVec128.m128_f32[1];
          rel_pos1.mVec128.m128_f32[2] = v49 - v26->m_worldTransform.m_origin.mVec128.m128_f32[2];
          world2B.m_el[0].mVec128.m128_i32[0] = v25->m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[0];
          world2B.m_el[0].mVec128.m128_i32[1] = v25->m_worldTransform.m_basis.m_el[1].mVec128.m128_i32[0];
          world2B.m_el[0].mVec128.m128_u64[1] = v25->m_worldTransform.m_basis.m_el[2].mVec128.m128_u32[0];
          world2B.m_el[1].mVec128.m128_i32[0] = v25->m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[1];
          world2B.m_el[1].mVec128.m128_i32[1] = v25->m_worldTransform.m_basis.m_el[1].mVec128.m128_i32[1];
          world2B.m_el[1].mVec128.m128_u64[1] = v25->m_worldTransform.m_basis.m_el[2].mVec128.m128_u32[1];
          world2B.m_el[2].mVec128.m128_i32[0] = v25->m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[2];
          world2B.m_el[2].mVec128.m128_i32[1] = v25->m_worldTransform.m_basis.m_el[1].mVec128.m128_i32[2];
          world2B.m_el[2].mVec128.m128_u64[1] = v25->m_worldTransform.m_basis.m_el[2].mVec128.m128_u32[2];
          world2A.m_el[0].mVec128.m128_i32[0] = v26->m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[0];
          world2A.m_el[0].mVec128.m128_i32[1] = v26->m_worldTransform.m_basis.m_el[1].mVec128.m128_i32[0];
          world2A.m_el[0].mVec128.m128_u64[1] = v26->m_worldTransform.m_basis.m_el[2].mVec128.m128_u32[0];
          world2A.m_el[1].mVec128.m128_i32[0] = v26->m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[1];
          world2A.m_el[1].mVec128.m128_i32[1] = v26->m_worldTransform.m_basis.m_el[1].mVec128.m128_i32[1];
          world2A.m_el[1].mVec128.m128_u64[1] = v26->m_worldTransform.m_basis.m_el[2].mVec128.m128_u32[1];
          world2A.m_el[2].mVec128.m128_i32[0] = v26->m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[2];
          m128_f32 = v26->m_invInertiaLocal.mVec128.m128_f32;
          world2A.m_el[2].mVec128.m128_i32[1] = v26->m_worldTransform.m_basis.m_el[1].mVec128.m128_i32[2];
          v27 = v26->m_worldTransform.m_basis.m_el[2].mVec128.m128_i32[2];
          rel_pos2.mVec128.m128_i32[3] = 0;
          rel_pos1.mVec128.m128_i32[3] = 0;
          world2A.m_el[2].mVec128.m128_u64[1] = (unsigned int)v27;
          btJacobianEntry::btJacobianEntry(m_jac, &rel_pos1, &rel_pos2, jointAxis, massInvA, m_inverseMass);
          m_jac = v36;
        }
        ++jointAxis;
        ++m_jac;
        v3 = v34-- == 1;
        v36 = m_jac;
      }
      while ( !v3 );
    }
    btConeTwistConstraint::calcAngleInfo2(
      &this->m_rbA->m_worldTransform,
      m128_f32,
      this,
      &this->m_rbB->m_worldTransform,
      &this->m_rbA->m_invInertiaTensorWorld,
      &this->m_rbB->m_invInertiaTensorWorld);
  }
}
