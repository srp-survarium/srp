void __thiscall vostok::animation::mixing::n_ary_tree_size_calculator::visit(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        vostok::animation::mixing::binary_tree_weight_node *node)
{
  vostok::animation::mixing::n_ary_tree_comparer *m_comparer; // eax
  vostok::animation::mixing::n_ary_tree_comparer *v3; // eax

  m_comparer = this->m_comparer;
  if ( m_comparer )
    m_comparer->m_needed_buffer_size += 12;
  else
    this->m_size += 12;
  v3 = this->m_comparer;
  if ( v3 )
    v3->m_needed_buffer_size += 4;
  else
    this->m_size += 4;
}
