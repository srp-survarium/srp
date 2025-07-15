void __usercall vostok::animation::mixing::weight_lexeme::weight_lexeme(
        vostok::animation::mixing::weight_lexeme *this@<ecx>,
        int a2@<eax>)
{
  unsigned int m_reference_count; // edx

  *(_DWORD *)(a2 + 4) = this->m_next_weight;
  *(_DWORD *)(a2 + 8) = this->m_same_weight;
  *(_DWORD *)(a2 + 12) = this->m_next_unique_interpolator;
  m_reference_count = this->m_reference_count;
  *(_DWORD *)a2 = &vostok::animation::mixing::binary_tree_weight_node::`vftable';
  *(_DWORD *)(a2 + 16) = m_reference_count;
  *(_DWORD *)(a2 + 20) = this->m_interpolator;
  *(float *)(a2 + 24) = this->m_weight;
  *(float *)(a2 + 28) = this->m_simplified_weight;
  *(_DWORD *)(a2 + 32) = this->m_buffer;
  *(_BYTE *)(a2 + 36) = 0;
  *(_DWORD *)a2 = &vostok::animation::mixing::weight_lexeme::`vftable';
}
