vostok::animation::instant_interpolator *__thiscall vostok::animation::instant_interpolator::clone(
        vostok::animation::instant_interpolator *this,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *constructor)
{
  vostok::animation::instant_interpolator *result; // eax
  vostok::mutable_buffer *m_buffer; // ecx
  vostok::mutable_buffer *v4; // ecx

  result = (vostok::animation::instant_interpolator *)constructor->m_buffer->m_data;
  if ( result )
  {
    result->__vftable = (vostok::animation::instant_interpolator_vtbl *)&vostok::animation::instant_interpolator::`vftable';
    m_buffer = constructor->m_buffer;
    m_buffer->m_data += 4;
    m_buffer->m_size -= 4;
  }
  else
  {
    v4 = constructor->m_buffer;
    v4->m_data += 4;
    v4->m_size -= 4;
    return 0;
  }
  return result;
}
