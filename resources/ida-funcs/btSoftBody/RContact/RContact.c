void __usercall btSoftBody::RContact::RContact(
        btSoftBody::RContact *this@<eax>,
        const btSoftBody::RContact *__that@<edx>)
{
  qmemcpy(this, __that, 0x34u);
  this->m_c0 = __that->m_c0;
  this->m_c1 = __that->m_c1;
  this->m_c2 = __that->m_c2;
  this->m_c3 = __that->m_c3;
  this->m_c4 = __that->m_c4;
}
