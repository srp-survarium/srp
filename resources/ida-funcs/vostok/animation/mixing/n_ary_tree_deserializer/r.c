int __usercall vostok::animation::mixing::n_ary_tree_deserializer::r@<eax>(
        vostok::animation::mixing::n_ary_tree_deserializer *this@<esi>,
        unsigned int bits_to_read@<eax>)
{
  unsigned int v2; // edi
  unsigned int v3; // eax
  unsigned int v4; // edx
  unsigned __int8 m_current_bit; // cl
  unsigned __int8 v6; // bl
  int v8; // [esp+4h] [ebp-8h]
  int v9; // [esp+8h] [ebp-4h]

  v8 = 0;
  v2 = bits_to_read;
  if ( bits_to_read )
  {
    do
    {
      v3 = *this->m_bits;
      v4 = v2 + ((unsigned int)this->m_current_bit + 1 < v2 ? this->m_current_bit + 1 - v2 : 0);
      m_current_bit = this->m_current_bit;
      v9 = -((unsigned int)m_current_bit + 1 < v2 ? m_current_bit + 1 - v2 : 0);
      v6 = (m_current_bit - v4) & 7;
      this->m_current_bit = v6;
      v2 = v9;
      v8 |= (((1 << v4) - 1) & (v3 >> (m_current_bit - v4 + 1))) << v9;
      if ( v6 == 7 )
        ++this->m_bits;
    }
    while ( v9 );
  }
  return v8;
}
