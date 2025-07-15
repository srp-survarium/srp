btSoftBody::Joint *__usercall btSoftBody::Joint::operator=@<eax>(
        btSoftBody::Joint *this@<ecx>,
        btSoftBody::Joint *result@<eax>)
{
  btSoftBody::Body *m_bodies; // edx
  int v3; // ebx
  btCollisionObject **p_m_collisionObject; // edi
  btCollisionObject **v5; // esi
  bool v6; // zf
  btVector3 *m_refs; // edx
  int *v8; // edi
  int *v9; // esi
  int v10; // [esp+Ch] [ebp-4h]
  int v11; // [esp+Ch] [ebp-4h]

  m_bodies = result->m_bodies;
  v3 = (char *)this - (char *)result;
  v10 = 2;
  do
  {
    m_bodies->m_soft = *(btSoftBody::Cluster **)((char *)&m_bodies->m_soft + v3);
    m_bodies->m_rigid = *(btRigidBody **)((char *)&m_bodies->m_rigid + v3);
    v5 = (btCollisionObject **)((char *)&m_bodies->m_collisionObject + v3);
    p_m_collisionObject = &m_bodies->m_collisionObject;
    ++m_bodies;
    v6 = v10-- == 1;
    *p_m_collisionObject = *v5;
  }
  while ( !v6 );
  m_refs = result->m_refs;
  v11 = 2;
  do
  {
    m_refs->mVec128.m128_i32[0] = *(int *)((char *)m_refs->mVec128.m128_i32 + v3);
    m_refs->mVec128.m128_i32[1] = *(int *)((char *)&m_refs->mVec128.m128_i32[1] + v3);
    m_refs->mVec128.m128_i32[2] = *(int *)((char *)&m_refs->mVec128.m128_i32[2] + v3);
    v9 = (int *)((char *)&m_refs->mVec128.m128_i32[3] + v3);
    v8 = &m_refs->mVec128.m128_i32[3];
    ++m_refs;
    v6 = v11-- == 1;
    *v8 = *v9;
  }
  while ( !v6 );
  result->m_cfm = this->m_cfm;
  result->m_erp = this->m_erp;
  result->m_split = this->m_split;
  result->m_drift = this->m_drift;
  result->m_sdrift = this->m_sdrift;
  result->m_massmatrix = this->m_massmatrix;
  result->m_delete = this->m_delete;
  return result;
}
