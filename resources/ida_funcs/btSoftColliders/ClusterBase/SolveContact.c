char __userpurge btSoftColliders::ClusterBase::SolveContact@<al>(
        const btGjkEpaSolver2::sResults *res@<eax>,
        btSoftColliders::ClusterBase *this,
        btSoftBody::Body ba,
        btSoftBody::Body bb,
        btSoftBody::CJoint *joint)
{
  btSoftBody::CJoint *v5; // ebx
  long double v7; // st7
  btSoftBody::Body *v8; // ecx
  const btTransform *v9; // eax
  float v10; // xmm0_4
  btSoftBody::Body *v11; // ecx
  const btTransform *v12; // eax
  float v13; // xmm0_4
  btVector3 *v14; // eax
  btVector3 *v15; // eax
  float v16; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  btCollisionObject *m_collisionObject; // edx
  btCollisionObject *v20; // eax
  float v21; // xmm7_4
  float *v22; // eax
  btSoftBody::Body *v23; // ecx
  float *v24; // eax
  float v25; // xmm3_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  const vostok::math::float4x4 *v29; // xmm2_4
  float friction; // xmm1_4
  btRigidBody *m_rigid; // ecx
  const btMatrix3x3 *v32; // eax
  float _X; // [esp+364h] [ebp-B4h]
  float iiba; // [esp+374h] [ebp-A4h]
  float iib; // [esp+374h] [ebp-A4h]
  btMatrix3x3 *iibb; // [esp+374h] [ebp-A4h]
  btVector3 v38; // [esp+378h] [ebp-A0h] BYREF
  float ima; // [esp+394h] [ebp-84h]
  unsigned __int64 v40; // [esp+398h] [ebp-80h]
  unsigned __int64 v41; // [esp+3A0h] [ebp-78h]
  btVector3 v42; // [esp+3A8h] [ebp-70h]
  btVector3 rpos; // [esp+3B8h] [ebp-60h] BYREF
  btVector3 v44; // [esp+3C8h] [ebp-50h] BYREF
  btVector3 v45; // [esp+3D8h] [ebp-40h] BYREF

  v5 = joint;
  if ( this->m_margin <= res->distance )
    return 0;
  v42.mVec128 = (__m128)res->normal;
  v7 = 1.0
     / sqrtf(
         (float)((float)(v42.mVec128.m128_f32[1] * v42.mVec128.m128_f32[1])
               + (float)(v42.mVec128.m128_f32[2] * v42.mVec128.m128_f32[2]))
       + (float)(res->normal.mVec128.m128_f32[0] * res->normal.mVec128.m128_f32[0]));
  v42.mVec128.m128_f32[0] = v42.mVec128.m128_f32[0] * v7;
  v42.mVec128.m128_f32[1] = v42.mVec128.m128_f32[1] * v7;
  v42.mVec128.m128_f32[2] = v7 * v42.mVec128.m128_f32[2];
  v9 = btSoftBody::Body::xform(v8, &ba);
  v10 = res->witnesses[0].mVec128.m128_f32[0] - v9->m_origin.mVec128.m128_f32[0];
  v9 = (const btTransform *)((char *)v9 + 48);
  rpos.mVec128.m128_f32[0] = v10;
  rpos.mVec128.m128_f32[1] = res->witnesses[0].mVec128.m128_f32[1] - v9->m_basis.m_el[0].mVec128.m128_f32[1];
  rpos.mVec128.m128_f32[2] = res->witnesses[0].mVec128.m128_f32[2] - v9->m_basis.m_el[0].mVec128.m128_f32[2];
  rpos.mVec128.m128_i32[3] = 0;
  v12 = btSoftBody::Body::xform(v11, &bb);
  v13 = res->witnesses[1].mVec128.m128_f32[0] - v12->m_origin.mVec128.m128_f32[0];
  v12 = (const btTransform *)((char *)v12 + 48);
  v44.mVec128.m128_f32[0] = v13;
  v44.mVec128.m128_f32[1] = res->witnesses[1].mVec128.m128_f32[1] - v12->m_basis.m_el[0].mVec128.m128_f32[1];
  v44.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(res->witnesses[1].mVec128.m128_f32[2] - v12->m_basis.m_el[0].mVec128.m128_f32[2]);
  if ( ba.m_rigid )
  {
    v38.mVec128 = (__m128)ba.m_rigid->m_linearVelocity;
  }
  else if ( ba.m_soft )
  {
    v38.mVec128 = (__m128)ba.m_soft->m_lv;
  }
  else
  {
    memset(&v38, 0, 12);
  }
  v14 = btSoftBody::Body::angularVelocity(&ba, &rpos, &v45);
  *(float *)&v40 = v14->mVec128.m128_f32[0] + v38.mVec128.m128_f32[0];
  *((float *)&v40 + 1) = v14->mVec128.m128_f32[1] + v38.mVec128.m128_f32[1];
  *(float *)&v41 = v14->mVec128.m128_f32[2] + v38.mVec128.m128_f32[2];
  if ( bb.m_rigid )
  {
    v38.mVec128 = (__m128)bb.m_rigid->m_linearVelocity;
  }
  else if ( bb.m_soft )
  {
    v38.mVec128 = (__m128)bb.m_soft->m_lv;
  }
  else
  {
    memset(&v38, 0, 12);
  }
  v15 = btSoftBody::Body::angularVelocity(&bb, &v44, &v45);
  v16 = v15->mVec128.m128_f32[0] + v38.mVec128.m128_f32[0];
  v17 = v15->mVec128.m128_f32[1] + v38.mVec128.m128_f32[1];
  v18 = v15->mVec128.m128_f32[2] + v38.mVec128.m128_f32[2];
  m_collisionObject = ba.m_collisionObject;
  v20 = bb.m_collisionObject;
  v21 = res->distance - this->m_margin;
  iiba = (float)((float)((float)(*((float *)&v40 + 1) - v17) * v42.mVec128.m128_f32[1])
               + (float)((float)(*(float *)&v41 - v18) * v42.mVec128.m128_f32[2]))
       + (float)((float)(*(float *)&v40 - v16) * v42.mVec128.m128_f32[0]);
  *(_QWORD *)&v5->m_bodies[0].m_soft = *(_QWORD *)&ba.m_soft;
  *(_QWORD *)&v5->m_bodies[1].m_soft = *(_QWORD *)&bb.m_soft;
  v38.mVec128.m128_f32[0] = (float)(*(float *)&v40 - v16) - (float)(v42.mVec128.m128_f32[0] * iiba);
  v38.mVec128.m128_f32[1] = (float)(*((float *)&v40 + 1) - v17) - (float)(v42.mVec128.m128_f32[1] * iiba);
  v38.mVec128.m128_f32[2] = (float)(*(float *)&v41 - v18) - (float)(v42.mVec128.m128_f32[2] * iiba);
  v5->m_bodies[0].m_collisionObject = m_collisionObject;
  v5->m_bodies[1].m_collisionObject = v20;
  v22 = (float *)btSoftBody::Body::xform((btSoftBody::Body *)this, &ba);
  *(float *)&v40 = (float)((float)(v22[4] * rpos.mVec128.m128_f32[1]) + (float)(v22[8] * rpos.mVec128.m128_f32[2]))
                 + (float)(*v22 * rpos.mVec128.m128_f32[0]);
  *((float *)&v40 + 1) = (float)((float)(v22[5] * rpos.mVec128.m128_f32[1]) + (float)(v22[9] * rpos.mVec128.m128_f32[2]))
                       + (float)(v22[1] * rpos.mVec128.m128_f32[0]);
  v41 = COERCE_UNSIGNED_INT(
          (float)((float)(v22[6] * rpos.mVec128.m128_f32[1]) + (float)(v22[10] * rpos.mVec128.m128_f32[2]))
        + (float)(v22[2] * rpos.mVec128.m128_f32[0]));
  v5->m_refs[0].mVec128.m128_u64[0] = v40;
  v5->m_refs[0].mVec128.m128_u64[1] = v41;
  v24 = (float *)btSoftBody::Body::xform(v23, &bb);
  *(float *)&v40 = (float)((float)(v24[8] * v44.mVec128.m128_f32[2]) + (float)(v24[4] * v44.mVec128.m128_f32[1]))
                 + (float)(v44.mVec128.m128_f32[0] * *v24);
  *((float *)&v40 + 1) = (float)((float)(v24[9] * v44.mVec128.m128_f32[2]) + (float)(v24[5] * v44.mVec128.m128_f32[1]))
                       + (float)(v24[1] * v44.mVec128.m128_f32[0]);
  v25 = v24[10] * v44.mVec128.m128_f32[2];
  v26 = v24[6] * v44.mVec128.m128_f32[1];
  v27 = v24[2] * v44.mVec128.m128_f32[0];
  v5->m_refs[1].mVec128.m128_u64[0] = v40;
  v28 = v25 + v26;
  v29 = clear_value;
  v5->m_refs[1].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v28 + v27);
  v5->m_rpos[0] = (btVector3)rpos.mVec128;
  v5->m_rpos[1] = (btVector3)v44.mVec128;
  *(float *)&v40 = v42.mVec128.m128_f32[0] * v21;
  *((float *)&v40 + 1) = v42.mVec128.m128_f32[1] * v21;
  v5->m_drift.mVec128.m128_u64[0] = v40;
  v5->m_drift.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v42.mVec128.m128_f32[2] * v21);
  v5->m_normal.mVec128.m128_u64[0] = v42.mVec128.m128_u64[0];
  v5->m_cfm = *(float *)&v29;
  v5->m_erp = *(float *)&v29;
  v5->m_life = 0;
  v5->m_maxlife = 0;
  v5->m_split = *(float *)&v29;
  v5->m_normal.mVec128.m128_u64[1] = v42.mVec128.m128_u64[1];
  v5->m_delete = 0;
  friction = this->friction;
  if ( (float)-(float)(friction * iiba) > (float)((float)((float)(v38.mVec128.m128_f32[2] * v38.mVec128.m128_f32[2])
                                                        + (float)(v38.mVec128.m128_f32[1] * v38.mVec128.m128_f32[1]))
                                                + (float)(v38.mVec128.m128_f32[0] * v38.mVec128.m128_f32[0])) )
    friction = *(float *)&v29;
  m_rigid = bb.m_rigid;
  v5->m_friction = friction;
  if ( m_rigid )
  {
    iib = m_rigid->m_inverseMass;
  }
  else if ( bb.m_soft )
  {
    iib = bb.m_soft->m_imass;
  }
  else
  {
    iib = 0.0;
  }
  if ( ba.m_rigid )
  {
    ima = ba.m_rigid->m_inverseMass;
  }
  else if ( ba.m_soft )
  {
    ima = ba.m_soft->m_imass;
  }
  else
  {
    ima = 0.0;
  }
  _X = iib;
  iibb = (btMatrix3x3 *)btSoftBody::Body::invWorldInertia(&bb);
  v32 = btSoftBody::Body::invWorldInertia(&ba);
  v5->m_massmatrix = *ImpulseMatrix(ima, v32, v5->m_rpos, _X, iibb, &v5->m_rpos[1]);
  return 1;
}
