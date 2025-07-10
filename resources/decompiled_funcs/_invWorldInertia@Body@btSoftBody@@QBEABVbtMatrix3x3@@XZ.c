const btMatrix3x3 *__thiscall btSoftBody::Body::invWorldInertia(btSoftBody::Body *this)
{
  btRigidBody *m_rigid; // eax

  if ( (`btSoftBody::Body::invWorldInertia'::`2'::`local static guard' & 1) == 0 )
  {
    `btSoftBody::Body::invWorldInertia'::`2'::`local static guard' |= 1u;
    `btSoftBody::Body::invWorldInertia'::`2'::iwi.m_el[0].mVec128.m128_u64[0] = 0;
    `btSoftBody::Body::invWorldInertia'::`2'::iwi.m_el[0].mVec128.m128_u64[1] = 0;
    `btSoftBody::Body::invWorldInertia'::`2'::iwi.m_el[1].mVec128.m128_u64[0] = 0;
    `btSoftBody::Body::invWorldInertia'::`2'::iwi.m_el[1].mVec128.m128_u64[1] = 0;
    `btSoftBody::Body::invWorldInertia'::`2'::iwi.m_el[2].mVec128.m128_u64[0] = 0;
    `btSoftBody::Body::invWorldInertia'::`2'::iwi.m_el[2].mVec128.m128_u64[1] = 0;
  }
  m_rigid = this->m_rigid;
  if ( m_rigid )
    return &m_rigid->m_invInertiaTensorWorld;
  if ( this->m_soft )
    return &this->m_soft->m_invwi;
  return &`btSoftBody::Body::invWorldInertia'::`2'::iwi;
}
