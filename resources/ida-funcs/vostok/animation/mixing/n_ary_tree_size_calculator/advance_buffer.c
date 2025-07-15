void __fastcall vostok::animation::mixing::n_ary_tree_size_calculator::advance_buffer<vostok::animation::mixing::n_ary_tree_base_node *>(
        vostok::animation::mixing::n_ary_tree_size_calculator *this,
        const unsigned int count)
{
  vostok::animation::mixing::n_ary_tree_comparer *m_comparer; // eax

  m_comparer = this->m_comparer;
  if ( m_comparer )
    m_comparer->m_needed_buffer_size += 4 * count;
  else
    this->m_size += 4 * count;
}
