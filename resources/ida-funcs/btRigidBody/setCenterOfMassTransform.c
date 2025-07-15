void __usercall btRigidBody::setCenterOfMassTransform(btRigidBody *this@<ecx>, int a2@<eax>)
{
  btVector3 *v2; // esi
  int *v3; // esi

  if ( (*(_BYTE *)(a2 + 216) & 3) != 0 )
  {
    *(_DWORD *)(a2 + 80) = *(_DWORD *)(a2 + 16);
    *(_DWORD *)(a2 + 84) = *(_DWORD *)(a2 + 20);
    *(_DWORD *)(a2 + 88) = *(_DWORD *)(a2 + 24);
    *(_DWORD *)(a2 + 92) = *(_DWORD *)(a2 + 28);
    *(_DWORD *)(a2 + 96) = *(_DWORD *)(a2 + 32);
    *(_DWORD *)(a2 + 100) = *(_DWORD *)(a2 + 36);
    *(_DWORD *)(a2 + 104) = *(_DWORD *)(a2 + 40);
    *(_DWORD *)(a2 + 108) = *(_DWORD *)(a2 + 44);
    *(_DWORD *)(a2 + 112) = *(_DWORD *)(a2 + 48);
    *(_DWORD *)(a2 + 116) = *(_DWORD *)(a2 + 52);
    *(_DWORD *)(a2 + 120) = *(_DWORD *)(a2 + 56);
    *(_DWORD *)(a2 + 124) = *(_DWORD *)(a2 + 60);
    v2 = (btVector3 *)(a2 + 64);
  }
  else
  {
    *(_DWORD *)(a2 + 80) = this->__vftable;
    *(_DWORD *)(a2 + 84) = *((_DWORD *)&this->__vftable + 1);
    *(_DWORD *)(a2 + 88) = *((_DWORD *)&this->__vftable + 2);
    *(_DWORD *)(a2 + 92) = *((_DWORD *)&this->__vftable + 3);
    *(_QWORD *)(a2 + 96) = this->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
    *(_QWORD *)(a2 + 104) = this->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
    *(btVector3 *)(a2 + 112) = this->m_worldTransform.m_basis.m_el[1];
    v2 = &this->m_worldTransform.m_basis.m_el[2];
  }
  *(_DWORD *)(a2 + 128) = v2->mVec128.m128_i32[0];
  v3 = &v2->mVec128.m128_i32[1];
  *(_DWORD *)(a2 + 132) = *v3++;
  *(_DWORD *)(a2 + 136) = *v3;
  *(_DWORD *)(a2 + 140) = v3[1];
  *(_DWORD *)(a2 + 144) = *(_DWORD *)(a2 + 320);
  *(_DWORD *)(a2 + 148) = *(_DWORD *)(a2 + 324);
  *(_DWORD *)(a2 + 152) = *(_DWORD *)(a2 + 328);
  *(_DWORD *)(a2 + 156) = *(_DWORD *)(a2 + 332);
  *(_DWORD *)(a2 + 160) = *(_DWORD *)(a2 + 336);
  *(_DWORD *)(a2 + 164) = *(_DWORD *)(a2 + 340);
  *(_DWORD *)(a2 + 168) = *(_DWORD *)(a2 + 344);
  *(_DWORD *)(a2 + 172) = *(_DWORD *)(a2 + 348);
  *(_DWORD *)(a2 + 16) = this->__vftable;
  *(_DWORD *)(a2 + 20) = *((_DWORD *)&this->__vftable + 1);
  *(_DWORD *)(a2 + 24) = *((_DWORD *)&this->__vftable + 2);
  *(_DWORD *)(a2 + 28) = *((_DWORD *)&this->__vftable + 3);
  *(_QWORD *)(a2 + 32) = this->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
  *(_QWORD *)(a2 + 40) = this->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
  *(btVector3 *)(a2 + 48) = this->m_worldTransform.m_basis.m_el[1];
  *(btVector3 *)(a2 + 64) = this->m_worldTransform.m_basis.m_el[2];
  btRigidBody::updateInertiaTensor(this, a2);
}
