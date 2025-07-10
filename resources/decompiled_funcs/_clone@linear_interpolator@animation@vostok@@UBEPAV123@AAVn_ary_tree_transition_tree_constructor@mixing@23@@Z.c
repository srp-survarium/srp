vostok::animation::linear_interpolator *__thiscall vostok::animation::linear_interpolator::clone(
        vostok::animation::linear_interpolator *this,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *constructor)
{
  vostok::animation::linear_interpolator *result; // eax
  vostok::mutable_buffer *m_buffer; // ecx
  vostok::mutable_buffer *v4; // ecx

  result = (vostok::animation::linear_interpolator *)constructor->m_buffer->m_data;
  if ( result )
  {
    result->__vftable = (vostok::animation::linear_interpolator_vtbl *)&vostok::animation::linear_interpolator::`vftable';
    result->m_total_transition_time = this->m_total_transition_time;
    m_buffer = constructor->m_buffer;
    m_buffer->m_data += 8;
    m_buffer->m_size -= 8;
  }
  else
  {
    v4 = constructor->m_buffer;
    v4->m_data += 8;
    v4->m_size -= 8;
    return 0;
  }
  return result;
}
