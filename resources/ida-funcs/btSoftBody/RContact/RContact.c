void __usercall btSoftBody::RContact::RContact(btSoftBody::RContact *this@<ecx>, int a2@<eax>)
{
  *(_QWORD *)a2 = *(_QWORD *)&this->m_cti.m_colObj;
  *(_QWORD *)(a2 + 8) = *((_QWORD *)&this->m_cti.m_colObj + 1);
  *(btVector3 *)(a2 + 16) = this->m_cti.m_normal;
  *(_QWORD *)(a2 + 32) = *(_QWORD *)&this->m_cti.m_offset;
  *(_QWORD *)(a2 + 40) = *((_QWORD *)&this->m_cti.m_offset + 1);
  *(_DWORD *)(a2 + 48) = this->m_node;
  *(btMatrix3x3 *)(a2 + 64) = this->m_c0;
  *(btVector3 *)(a2 + 112) = this->m_c1;
  *(float *)(a2 + 128) = this->m_c2;
  *(float *)(a2 + 132) = this->m_c3;
  *(float *)(a2 + 136) = this->m_c4;
}
