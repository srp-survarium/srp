void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::binary_tree_animation_node *node)
{
  vostok::animation::mixing::n_ary_tree_comparer *m_comparer; // eax
  vostok::animation::mixing::n_ary_tree_comparer *v3; // edx
  unsigned int m_animation_intervals_count; // eax

  m_comparer = this->m_comparer;
  if ( m_comparer )
    m_comparer->m_needed_buffer_size += 88;
  else
    this->m_size += 88;
  v3 = this->m_comparer;
  m_animation_intervals_count = node->m_animation_intervals_count;
  if ( v3 )
    v3->m_needed_buffer_size += 12 * m_animation_intervals_count;
  else
    this->m_size += 12 * m_animation_intervals_count;
}
