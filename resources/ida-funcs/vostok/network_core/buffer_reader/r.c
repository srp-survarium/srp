unsigned __int16 __thiscall vostok::network_core::buffer_reader::r<unsigned short>(
        vostok::network_core::buffer_reader *this)
{
  __int16 v2; // [esp+8h] [ebp-4h]

  v2 = *(_WORD *)this->m_pointer;
  this->m_pointer += 2;
  return v2;
}


BOOL __thiscall vostok::network_core::buffer_reader::r<bool>(vostok::network_core::buffer_reader *this)
{
  const unsigned __int8 *m_pointer; // esi
  unsigned __int8 v3; // [esp+Bh] [ebp-1h]

  m_pointer = this->m_pointer;
  v3 = *m_pointer;
  this->m_pointer = m_pointer + 1;
  return v3 != 0;
}
