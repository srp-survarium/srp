void __thiscall vostok::animation::interpolator_size_calculator::visit(
        vostok::animation::interpolator_size_calculator *this,
        const vostok::animation::instant_interpolator *interpolator)
{
  vostok::animation::mixing::n_ary_tree_comparer *m_comparer; // eax

  m_comparer = this->m_comparer;
  if ( m_comparer )
    m_comparer->m_needed_buffer_size += 4;
  else
    this->m_size += 4;
}
