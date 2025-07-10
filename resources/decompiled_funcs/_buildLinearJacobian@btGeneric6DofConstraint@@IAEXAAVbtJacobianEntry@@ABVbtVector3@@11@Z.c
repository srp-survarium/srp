void __userpurge btGeneric6DofConstraint::buildLinearJacobian(
        btGeneric6DofConstraint *this@<eax>,
        const btVector3 *pivotBInW@<edx>,
        btJacobianEntry *jacLinear,
        const btVector3 *normalWorld,
        const btVector3 *pivotAInW)
{
  btRigidBody *m_rbB; // eax
  float m_inverseMass; // xmm0_4
  btRigidBody *m_rbA; // ecx
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // xmm1_4
  unsigned int v12; // xmm0_4
  int v13; // xmm1_4
  int v14; // xmm1_4
  float massInvA; // [esp+1Ch] [ebp-8Ch]
  float massInvB; // [esp+20h] [ebp-88h]
  btVector3 rel_pos2; // [esp+28h] [ebp-80h] BYREF
  btVector3 rel_pos1; // [esp+38h] [ebp-70h] BYREF
  btMatrix3x3 world2B; // [esp+48h] [ebp-60h]
  btMatrix3x3 world2A; // [esp+78h] [ebp-30h]

  if ( jacLinear )
  {
    m_rbB = this->m_rbB;
    m_inverseMass = m_rbB->m_inverseMass;
    m_rbA = this->m_rbA;
    rel_pos1.mVec128.m128_f32[0] = pivotAInW->mVec128.m128_f32[0] - m_rbA->m_worldTransform.m_origin.mVec128.m128_f32[0];
    rel_pos1.mVec128.m128_f32[1] = pivotAInW->mVec128.m128_f32[1] - m_rbA->m_worldTransform.m_origin.mVec128.m128_f32[1];
    rel_pos1.mVec128.m128_f32[2] = pivotAInW->mVec128.m128_f32[2] - m_rbA->m_worldTransform.m_origin.mVec128.m128_f32[2];
    world2B.m_el[0].mVec128.m128_i32[0] = m_rbB->m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[0];
    world2B.m_el[0].mVec128.m128_i32[1] = m_rbB->m_worldTransform.m_basis.m_el[1].mVec128.m128_i32[0];
    world2B.m_el[0].mVec128.m128_u64[1] = m_rbB->m_worldTransform.m_basis.m_el[2].mVec128.m128_u32[0];
    world2B.m_el[1].mVec128.m128_i32[0] = m_rbB->m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[1];
    world2B.m_el[1].mVec128.m128_i32[1] = m_rbB->m_worldTransform.m_basis.m_el[1].mVec128.m128_i32[1];
    massInvB = m_inverseMass;
    v9 = m_rbA->m_inverseMass;
    world2B.m_el[1].mVec128.m128_u64[1] = m_rbB->m_worldTransform.m_basis.m_el[2].mVec128.m128_u32[1];
    massInvA = v9;
    v10 = pivotBInW->mVec128.m128_f32[0] - m_rbB->m_worldTransform.m_origin.mVec128.m128_f32[0];
    world2B.m_el[2].mVec128.m128_i32[0] = m_rbB->m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[2];
    world2B.m_el[2].mVec128.m128_i32[1] = m_rbB->m_worldTransform.m_basis.m_el[1].mVec128.m128_i32[2];
    v11 = m_rbB->m_worldTransform.m_basis.m_el[2].mVec128.m128_i32[2];
    rel_pos2.mVec128.m128_f32[0] = v10;
    rel_pos2.mVec128.m128_f32[1] = pivotBInW->mVec128.m128_f32[1] - m_rbB->m_worldTransform.m_origin.mVec128.m128_f32[1];
    *(float *)&v12 = pivotBInW->mVec128.m128_f32[2] - m_rbB->m_worldTransform.m_origin.mVec128.m128_f32[2];
    world2B.m_el[2].mVec128.m128_u64[1] = (unsigned int)v11;
    world2A.m_el[0].mVec128.m128_i32[0] = m_rbA->m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[0];
    world2A.m_el[0].mVec128.m128_i32[1] = m_rbA->m_worldTransform.m_basis.m_el[1].mVec128.m128_i32[0];
    world2A.m_el[0].mVec128.m128_u64[1] = m_rbA->m_worldTransform.m_basis.m_el[2].mVec128.m128_u32[0];
    world2A.m_el[1].mVec128.m128_i32[0] = m_rbA->m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[1];
    world2A.m_el[1].mVec128.m128_i32[1] = m_rbA->m_worldTransform.m_basis.m_el[1].mVec128.m128_i32[1];
    world2A.m_el[1].mVec128.m128_u64[1] = m_rbA->m_worldTransform.m_basis.m_el[2].mVec128.m128_u32[1];
    world2A.m_el[2].mVec128.m128_i32[0] = m_rbA->m_worldTransform.m_basis.m_el[0].mVec128.m128_i32[2];
    v13 = m_rbA->m_worldTransform.m_basis.m_el[1].mVec128.m128_i32[2];
    rel_pos2.mVec128.m128_u64[1] = v12;
    world2A.m_el[2].mVec128.m128_i32[1] = v13;
    v14 = m_rbA->m_worldTransform.m_basis.m_el[2].mVec128.m128_i32[2];
    rel_pos1.mVec128.m128_i32[3] = 0;
    world2A.m_el[2].mVec128.m128_u64[1] = (unsigned int)v14;
    btJacobianEntry::btJacobianEntry(jacLinear, &rel_pos1, &rel_pos2, normalWorld, massInvA, massInvB);
  }
}
