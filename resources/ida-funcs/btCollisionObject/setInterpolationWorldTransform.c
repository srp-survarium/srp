void __usercall btCollisionObject::setInterpolationWorldTransform(btCollisionObject *this@<ecx>, btVector3 *a2@<eax>)
{
  btVector3 *v2; // eax

  v2 = a2 + 5;
  v2->mVec128.m128_i32[0] = (int)this->__vftable;
  v2->mVec128.m128_i32[1] = *((_DWORD *)&this->__vftable + 1);
  v2->mVec128.m128_i32[2] = *((_DWORD *)&this->__vftable + 2);
  v2->mVec128.m128_i32[3] = *((_DWORD *)&this->__vftable + 3);
  v2[1] = this->m_worldTransform.m_basis.m_el[0];
  v2[2] = this->m_worldTransform.m_basis.m_el[1];
  v2[3] = this->m_worldTransform.m_basis.m_el[2];
}
