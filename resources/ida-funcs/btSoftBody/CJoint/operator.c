btSoftBody::CJoint *__thiscall btSoftBody::CJoint::operator=(
        btSoftBody::CJoint *this,
        const btSoftBody::CJoint *__that,
        btSoftBody::Joint *a3)
{
  btVector3 *m_rpos; // eax
  int v4; // ecx
  int v5; // edx
  int *v6; // edi
  int *v7; // esi

  btSoftBody::Joint::operator=(a3, &__that->btSoftBody::Joint);
  __that->m_life = (int)a3[1].__vftable;
  __that->m_maxlife = *((_DWORD *)&a3[1].__vftable + 1);
  m_rpos = __that->m_rpos;
  v4 = (char *)a3 - (char *)__that;
  v5 = 2;
  do
  {
    m_rpos->mVec128.m128_i32[0] = *(int *)((char *)m_rpos->mVec128.m128_i32 + v4);
    m_rpos->mVec128.m128_i32[1] = *(int *)((char *)&m_rpos->mVec128.m128_i32[1] + v4);
    m_rpos->mVec128.m128_i32[2] = *(int *)((char *)&m_rpos->mVec128.m128_i32[2] + v4);
    v7 = (int *)((char *)&m_rpos->mVec128.m128_i32[3] + v4);
    v6 = &m_rpos->mVec128.m128_i32[3];
    ++m_rpos;
    --v5;
    *v6 = *v7;
  }
  while ( v5 );
  __that->m_normal = a3[1].m_refs[0];
  __that->m_friction = a3[1].m_refs[1].mVec128.m128_f32[0];
  return (btSoftBody::CJoint *)__that;
}
