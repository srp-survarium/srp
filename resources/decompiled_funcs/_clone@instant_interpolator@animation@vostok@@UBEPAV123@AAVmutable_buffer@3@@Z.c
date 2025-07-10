vostok::animation::instant_interpolator *__thiscall vostok::animation::instant_interpolator::clone(
        vostok::animation::instant_interpolator *this,
        vostok::mutable_buffer *buffer)
{
  vostok::animation::instant_interpolator *result; // eax

  result = (vostok::animation::instant_interpolator *)buffer->m_data;
  if ( buffer->m_data )
  {
    result->__vftable = (vostok::animation::instant_interpolator_vtbl *)&vostok::animation::instant_interpolator::`vftable';
    buffer->m_data += 4;
    buffer->m_size -= 4;
  }
  else
  {
    buffer->m_data += 4;
    buffer->m_size -= 4;
    return 0;
  }
  return result;
}
