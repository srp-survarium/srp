btSoftBody::Joint *__usercall btSoftBody::Joint::operator=@<eax>(
        btSoftBody::Joint *this@<ecx>,
        btSoftBody::Joint *result@<eax>)
{
  *(_QWORD *)&result->m_bodies[0].m_soft = *(_QWORD *)&this->m_bodies[0].m_soft;
  result->m_bodies[0].m_collisionObject = this->m_bodies[0].m_collisionObject;
  result->m_bodies[1] = this->m_bodies[1];
  result->m_refs[0].mVec128.m128_u64[0] = this->m_refs[0].mVec128.m128_u64[0];
  result->m_refs[0].mVec128.m128_u64[1] = this->m_refs[0].mVec128.m128_u64[1];
  result->m_refs[1] = this->m_refs[1];
  result->m_cfm = this->m_cfm;
  result->m_erp = this->m_erp;
  result->m_split = this->m_split;
  result->m_drift = this->m_drift;
  result->m_sdrift = this->m_sdrift;
  result->m_massmatrix = this->m_massmatrix;
  result->m_delete = this->m_delete;
  return result;
}
