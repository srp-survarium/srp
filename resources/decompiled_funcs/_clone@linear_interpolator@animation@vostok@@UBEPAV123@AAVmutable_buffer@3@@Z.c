vostok::animation::linear_interpolator *__thiscall vostok::animation::linear_interpolator::clone(
        vostok::animation::linear_interpolator *this,
        vostok::mutable_buffer *buffer)
{
  vostok::animation::linear_interpolator *result; // eax

  result = (vostok::animation::linear_interpolator *)buffer->m_data;
  if ( buffer->m_data )
  {
    result->__vftable = (vostok::animation::linear_interpolator_vtbl *)&vostok::animation::linear_interpolator::`vftable';
    result->m_total_transition_time = this->m_total_transition_time;
    buffer->m_data += 8;
    buffer->m_size -= 8;
  }
  else
  {
    buffer->m_data += 8;
    buffer->m_size -= 8;
    return 0;
  }
  return result;
}
