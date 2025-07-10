vostok::animation::fermi_interpolator *__thiscall vostok::animation::fermi_interpolator::clone(
        vostok::animation::fermi_interpolator *this,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *constructor)
{
  vostok::animation::fermi_interpolator *result; // eax
  vostok::mutable_buffer *m_buffer; // ecx
  vostok::mutable_buffer *v4; // ecx

  result = (vostok::animation::fermi_interpolator *)constructor->m_buffer->m_data;
  if ( result )
  {
    result->__vftable = (vostok::animation::fermi_interpolator_vtbl *)&vostok::animation::fermi_interpolator::`vftable';
    result->m_total_transition_time = this->m_total_transition_time;
    result->m_epsilon = this->m_epsilon;
    m_buffer = constructor->m_buffer;
    m_buffer->m_data += 12;
    m_buffer->m_size -= 12;
  }
  else
  {
    v4 = constructor->m_buffer;
    v4->m_data += 12;
    v4->m_size -= 12;
    return 0;
  }
  return result;
}
