vostok::animation::fermi_interpolator *__thiscall vostok::animation::fermi_interpolator::clone(
        vostok::animation::fermi_interpolator *this,
        vostok::mutable_buffer *buffer)
{
  vostok::animation::fermi_interpolator *result; // eax

  result = (vostok::animation::fermi_interpolator *)buffer->m_data;
  if ( buffer->m_data )
  {
    result->__vftable = (vostok::animation::fermi_interpolator_vtbl *)&vostok::animation::fermi_interpolator::`vftable';
    result->m_total_transition_time = this->m_total_transition_time;
    result->m_epsilon = this->m_epsilon;
    buffer->m_data += 12;
    buffer->m_size -= 12;
  }
  else
  {
    buffer->m_data += 12;
    buffer->m_size -= 12;
    return 0;
  }
  return result;
}
