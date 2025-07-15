void __thiscall vostok::animation::mixing::n_ary_tree_weight_transition_node::fixup(
        vostok::animation::mixing::n_ary_tree_weight_transition_node *this,
        unsigned int offset)
{
  vostok::animation::mixing::n_ary_tree_base_node *m_from; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v4; // ecx
  vostok::animation::mixing::n_ary_tree_base_node *m_to; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v6; // eax
  const vostok::animation::base_interpolator *m_interpolator; // eax
  const vostok::animation::base_interpolator *v8; // eax

  m_from = this->m_from;
  if ( m_from )
    v4 = (vostok::animation::mixing::n_ary_tree_base_node *)((char *)m_from + offset);
  else
    v4 = 0;
  m_to = this->m_to;
  this->m_from = v4;
  if ( m_to )
    v6 = (vostok::animation::mixing::n_ary_tree_base_node *)((char *)m_to + offset);
  else
    v6 = 0;
  this->m_to = v6;
  m_interpolator = this->m_interpolator;
  if ( m_interpolator )
    v8 = (const vostok::animation::base_interpolator *)((char *)m_interpolator + offset);
  else
    v8 = 0;
  this->m_interpolator = v8;
  v4->fixup(v4, offset);
  this->m_to->fixup(this->m_to, offset);
}
