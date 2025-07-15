vostok::animation::mixing::binary_tree_base_node *__usercall vostok::animation::mixing::n_ary_tree_converter::create_binary_multipliers@<eax>(
        vostok::mutable_buffer *buffer@<edi>,
        vostok::animation::mixing::binary_tree_base_node *start_weight@<eax>,
        vostok::animation::mixing::n_ary_tree_converter *this)
{
  vostok::animation::mixing::binary_tree_base_node *i; // edx
  char *m_data; // ecx

  for ( i = start_weight->m_next_weight; i; start_weight = (vostok::animation::mixing::binary_tree_base_node *)m_data )
  {
    m_data = buffer->m_data;
    buffer->m_size -= 28;
    buffer->m_data = m_data + 28;
    if ( m_data )
    {
      *((_DWORD *)m_data + 1) = 0;
      *((_DWORD *)m_data + 2) = 0;
      *((_DWORD *)m_data + 3) = 0;
      *((_DWORD *)m_data + 4) = 0;
      *(_DWORD *)m_data = &vostok::animation::mixing::binary_tree_binary_operation_node::`vftable';
      *((_DWORD *)m_data + 5) = 0;
      if ( start_weight )
      {
        *((_DWORD *)m_data + 5) = start_weight;
        ++start_weight->m_reference_count;
      }
      *((_DWORD *)m_data + 6) = 0;
      *((_DWORD *)m_data + 6) = i;
      ++i->m_reference_count;
      *(_DWORD *)m_data = &vostok::animation::mixing::binary_tree_multiplication_node::`vftable';
    }
    i = i->m_next_weight;
  }
  return start_weight;
}
