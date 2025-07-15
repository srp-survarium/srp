vostok::animation::instant_interpolator *__thiscall vostok::animation::instant_interpolator::clone(
        vostok::animation::instant_interpolator *this,
        vostok::memory::base_allocator *allocator)
{
  char *v2; // eax
  vostok::animation::instant_interpolator *result; // eax

  v2 = type_info::raw_name(&vostok::animation::instant_interpolator `RTTI Type Descriptor');
  result = (vostok::animation::instant_interpolator *)allocator->call_malloc(
                                                        allocator,
                                                        4,
                                                        v2,
                                                        "vostok::animation::base_interpolator::clone_impl",
                                                        "c:\\survarium.deploy\\sources\\vostok/animation/base_interpolator_inline.h",
                                                        32);
  if ( !result )
    return 0;
  result->__vftable = (vostok::animation::instant_interpolator_vtbl *)&vostok::animation::instant_interpolator::`vftable';
  return result;
}


vostok::animation::instant_interpolator *__thiscall vostok::animation::instant_interpolator::clone(
        vostok::animation::instant_interpolator *this,
        vostok::mutable_buffer *buffer)
{
  vostok::animation::instant_interpolator *result; // eax

  result = (vostok::animation::instant_interpolator *)buffer->m_data;
  if ( buffer->m_data )
    result->__vftable = (vostok::animation::instant_interpolator_vtbl *)&vostok::animation::instant_interpolator::`vftable';
  else
    result = 0;
  buffer->m_data += 4;
  buffer->m_size -= 4;
  return result;
}


vostok::animation::instant_interpolator *__thiscall vostok::animation::instant_interpolator::clone(
        vostok::animation::instant_interpolator *this,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *constructor)
{
  vostok::animation::instant_interpolator *result; // eax
  vostok::mutable_buffer *m_buffer; // ecx

  result = (vostok::animation::instant_interpolator *)constructor->m_buffer->m_data;
  if ( result )
    result->__vftable = (vostok::animation::instant_interpolator_vtbl *)&vostok::animation::instant_interpolator::`vftable';
  else
    result = 0;
  m_buffer = constructor->m_buffer;
  m_buffer->m_data += 4;
  m_buffer->m_size -= 4;
  return result;
}
