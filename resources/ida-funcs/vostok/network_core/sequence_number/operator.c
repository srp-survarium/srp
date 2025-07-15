BOOL __usercall vostok::network_core::sequence_number<unsigned short>::operator<@<eax>(
        vostok::network_core::sequence_number<unsigned short> *this@<ecx>,
        unsigned __int16 *a2@<eax>)
{
  unsigned __int16 v2; // ax
  unsigned __int16 m_number; // cx
  bool v4; // cf

  v2 = *a2;
  m_number = this->m_number;
  v4 = m_number < v2;
  if ( m_number > v2 )
  {
    if ( (unsigned int)v2 + 0x8000 > m_number )
      return 1;
    v4 = m_number < v2;
  }
  return v4 && (unsigned int)m_number + 0x8000 <= v2;
}


int __usercall vostok::network_core::sequence_number<unsigned short>::operator<=@<eax>(
        vostok::network_core::sequence_number<unsigned short> *this@<ecx>,
        unsigned __int16 *a2@<eax>)
{
  unsigned __int16 v2; // ax
  unsigned __int16 m_number; // cx

  v2 = *a2;
  m_number = this->m_number;
  if ( m_number < v2 )
    goto LABEL_4;
  if ( (unsigned int)v2 + 0x8000 > m_number )
    return 1;
  if ( m_number < v2 )
  {
LABEL_4:
    if ( (unsigned int)m_number + 0x8000 <= v2 )
      return 1;
  }
  return 0;
}
