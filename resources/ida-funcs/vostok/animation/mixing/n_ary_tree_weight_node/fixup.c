void __thiscall vostok::animation::mixing::n_ary_tree_weight_node::fixup(
        vostok::animation::mixing::n_ary_tree_time_scale_node *this,
        const unsigned int offset)
{
  const vostok::animation::base_interpolator *m_interpolator; // eax
  const vostok::animation::base_interpolator *v3; // eax

  m_interpolator = this->m_interpolator;
  if ( m_interpolator )
    v3 = (const vostok::animation::base_interpolator *)((char *)m_interpolator + offset);
  else
    v3 = 0;
  this->m_interpolator = v3;
}
