void __usercall vostok::animation::mixing::n_ary_tree_serializer::save_bits(
        vostok::animation::mixing::n_ary_tree_serializer *this@<eax>,
        unsigned __int8 *const pointer@<esi>)
{
  unsigned __int8 *m_bits_stream; // ebx
  vostok::animation::mixing::n_ary_tree_serializer *m_current_bit; // ecx
  unsigned int v5; // eax
  unsigned int v6; // [esp+8h] [ebp-8h]
  char v7; // [esp+Fh] [ebp-1h]

  m_bits_stream = this->m_bits_stream;
  m_current_bit = (vostok::animation::mixing::n_ary_tree_serializer *)this->m_current_bit;
  v6 = (unsigned int)m_current_bit;
  v5 = 8 * (m_bits_stream - pointer) - (_DWORD)m_current_bit - 9;
  this->m_current_bit = 7;
  this->m_bits_stream = pointer;
  LOBYTE(m_current_bit) = pointer[2];
  v7 = (char)m_current_bit;
  vostok::animation::mixing::n_ary_tree_serializer::append(m_current_bit, (int)this, v5, 0x10u);
  pointer[2] |= v7 & (unsigned __int8)((1 << (LOBYTE(this->m_current_bit) + 1)) - 1);
  this->m_bits_stream = m_bits_stream;
  this->m_current_bit = v6;
}
