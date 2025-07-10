void __thiscall vostok::animation::interpolator_size_calculator::visit(
        vostok::animation::interpolator_size_calculator *this,
        const vostok::animation::linear_interpolator *interpolator)
{
  vostok::animation::mixing::n_ary_tree_comparer *m_comparer; // eax

  m_comparer = this->m_comparer;
  if ( m_comparer )
    m_comparer->m_needed_buffer_size += 8;
  else
    this->m_size += 8;
}
