void __userpurge vostok::animation::mixing::n_ary_tree_deserializer::decode_data(
        vostok::animation::mixing::n_ary_tree_deserializer *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_deserializer *a2@<eax>,
        vostok::network_core::buffer_reader *data_buffer)
{
  unsigned int v5; // eax
  unsigned __int8 *v6; // ecx
  unsigned int *m_end; // eax
  vostok::animation::mixing::n_ary_tree_deserializer *i; // ecx
  vostok::animation::mixing::n_ary_tree_intrusive_base *m_object; // edx
  float *v10; // eax
  float *j; // ecx
  float v12; // xmm0_4
  unsigned int v13; // eax
  const unsigned __int8 *m_bits; // [esp+Ch] [ebp-8h]
  const unsigned __int8 *m_pointer; // [esp+10h] [ebp-4h]
  unsigned __int8 m_current_bit; // [esp+1Fh] [ebp+Bh]

  m_pointer = data_buffer->m_pointer;
  a2->m_bits = m_pointer;
  a2->m_current_bit = 7;
  v5 = vostok::animation::mixing::n_ary_tree_deserializer::r(a2, 0x10u);
  m_bits = a2->m_bits;
  m_current_bit = a2->m_current_bit;
  v5 += 16;
  v6 = (unsigned __int8 *)&data_buffer->m_pointer[v5 >> 3];
  a2->m_bits = v6;
  LOBYTE(v6) = 7 - (v5 & 7);
  a2->m_current_bit = (unsigned __int8)v6;
  vostok::animation::mixing::n_ary_tree_deserializer::decode_times_in_ms_impl(
    (vostok::animation::mixing::n_ary_tree_deserializer *)v6,
    a2);
  m_end = a2->m_times_in_ms.m_end;
  for ( i = (vostok::animation::mixing::n_ary_tree_deserializer *)a2->m_times_in_ms.m_begin;
        i < (vostok::animation::mixing::n_ary_tree_deserializer *)m_end;
        i = (vostok::animation::mixing::n_ary_tree_deserializer *)((char *)i + 4) )
  {
    m_object = i->m_result.m_object;
    i->m_result.m_object = (vostok::animation::mixing::n_ary_tree_intrusive_base *)*--m_end;
    *m_end = (unsigned int)m_object;
  }
  vostok::animation::mixing::n_ary_tree_deserializer::decode_floats_impl(i, a2);
  v10 = a2->m_floats.m_end;
  for ( j = a2->m_floats.m_begin; j < v10; ++j )
  {
    v12 = *j;
    *j = *--v10;
    *v10 = v12;
  }
  v13 = a2->m_bits - m_pointer;
  if ( a2->m_current_bit != 7 )
    ++v13;
  data_buffer->m_pointer += v13;
  a2->m_current_bit = m_current_bit;
  a2->m_bits = m_bits;
}
