void __userpurge btSoftBody::addVelocity(const btVector3 *velocity@<ecx>, int node@<eax>, btSoftBody *this)
{
  btSoftBody::Node *v3; // eax

  v3 = &this->m_nodes.m_data[node];
  if ( v3->m_im > 0.0 )
  {
    v3->m_v.mVec128.m128_f32[0] = v3->m_v.mVec128.m128_f32[0] + velocity->mVec128.m128_f32[0];
    v3->m_v.mVec128.m128_f32[1] = velocity->mVec128.m128_f32[1] + v3->m_v.mVec128.m128_f32[1];
    v3->m_v.mVec128.m128_f32[2] = velocity->mVec128.m128_f32[2] + v3->m_v.mVec128.m128_f32[2];
  }
}
