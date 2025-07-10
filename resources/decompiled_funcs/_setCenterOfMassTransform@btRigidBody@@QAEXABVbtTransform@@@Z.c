void __usercall btRigidBody::setCenterOfMassTransform(btRigidBody *this@<ecx>, int a2@<eax>)
{
  unsigned __int64 v2; // xmm0_8
  unsigned __int64 v3; // xmm0_8
  btRigidBody *v4; // ecx

  if ( (*(_BYTE *)(a2 + 216) & 3) != 0 )
  {
    *(_QWORD *)(a2 + 80) = *(_QWORD *)(a2 + 16);
    *(_QWORD *)(a2 + 88) = *(_QWORD *)(a2 + 24);
    *(_QWORD *)(a2 + 96) = *(_QWORD *)(a2 + 32);
    *(_QWORD *)(a2 + 104) = *(_QWORD *)(a2 + 40);
    *(_QWORD *)(a2 + 112) = *(_QWORD *)(a2 + 48);
    *(_QWORD *)(a2 + 120) = *(_QWORD *)(a2 + 56);
    *(_QWORD *)(a2 + 128) = *(_QWORD *)(a2 + 64);
    v2 = *(_QWORD *)(a2 + 72);
  }
  else
  {
    *(_QWORD *)(a2 + 80) = *(_QWORD *)&this->__vftable;
    *(_QWORD *)(a2 + 88) = *((_QWORD *)&this->__vftable + 1);
    *(_QWORD *)(a2 + 96) = this->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
    *(_QWORD *)(a2 + 104) = this->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
    *(btVector3 *)(a2 + 112) = this->m_worldTransform.m_basis.m_el[1];
    *(_QWORD *)(a2 + 128) = this->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[0];
    v2 = this->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[1];
  }
  *(_QWORD *)(a2 + 136) = v2;
  *(_QWORD *)(a2 + 144) = *(_QWORD *)(a2 + 320);
  *(_QWORD *)(a2 + 152) = *(_QWORD *)(a2 + 328);
  *(_QWORD *)(a2 + 160) = *(_QWORD *)(a2 + 336);
  *(_QWORD *)(a2 + 168) = *(_QWORD *)(a2 + 344);
  *(_QWORD *)(a2 + 16) = *(_QWORD *)&this->__vftable;
  *(_QWORD *)(a2 + 24) = *((_QWORD *)&this->__vftable + 1);
  *(_QWORD *)(a2 + 32) = this->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
  *(_QWORD *)(a2 + 40) = this->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
  *(_QWORD *)(a2 + 48) = this->m_worldTransform.m_basis.m_el[1].mVec128.m128_u64[0];
  v3 = this->m_worldTransform.m_basis.m_el[1].mVec128.m128_u64[1];
  v4 = (btRigidBody *)&this->m_worldTransform.m_basis.m_el[2];
  *(_QWORD *)(a2 + 56) = v3;
  *(btVector3 *)(a2 + 64) = *(btVector3 *)&v4->__vftable;
  btRigidBody::updateInertiaTensor(v4, a2);
}
