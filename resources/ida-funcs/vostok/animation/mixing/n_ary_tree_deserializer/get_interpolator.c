const vostok::animation::base_interpolator *__usercall vostok::animation::mixing::n_ary_tree_deserializer::get_interpolator@<eax>(
        vostok::animation::mixing::n_ary_tree_deserializer *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_deserializer *a2@<eax>)
{
  unsigned int m_interpolators_count; // eax
  unsigned int v4; // eax

  m_interpolators_count = a2->m_interpolators_count;
  if ( m_interpolators_count == 1 )
    return *a2->m_interpolators;
  if ( m_interpolators_count == 2 )
    v4 = 1;
  else
    v4 = 2;
  return a2->m_interpolators[vostok::animation::mixing::n_ary_tree_deserializer::r(a2, v4)];
}
