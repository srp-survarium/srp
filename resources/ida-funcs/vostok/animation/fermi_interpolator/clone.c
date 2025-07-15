vostok::animation::fermi_interpolator *__thiscall vostok::animation::fermi_interpolator::clone(
        vostok::animation::fermi_interpolator *this,
        vostok::memory::base_allocator *allocator)
{
  char *v3; // eax
  vostok::animation::fermi_interpolator *result; // eax

  v3 = type_info::raw_name(&vostok::animation::fermi_interpolator `RTTI Type Descriptor');
  result = (vostok::animation::fermi_interpolator *)allocator->call_malloc(
                                                      allocator,
                                                      12,
                                                      v3,
                                                      "vostok::animation::base_interpolator::clone_impl",
                                                      "c:\\survarium.deploy\\sources\\vostok/animation/base_interpolator_inline.h",
                                                      32);
  if ( !result )
    return 0;
  result->__vftable = (vostok::animation::fermi_interpolator_vtbl *)&vostok::animation::fermi_interpolator::`vftable';
  result->m_total_transition_time = this->m_total_transition_time;
  result->m_epsilon = this->m_epsilon;
  return result;
}


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
  }
  else
  {
    result = 0;
  }
  buffer->m_data += 12;
  buffer->m_size -= 12;
  return result;
}


vostok::animation::fermi_interpolator *__thiscall vostok::animation::fermi_interpolator::clone(
        vostok::animation::fermi_interpolator *this,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *constructor)
{
  vostok::animation::fermi_interpolator *result; // eax
  vostok::mutable_buffer *m_buffer; // ecx

  result = (vostok::animation::fermi_interpolator *)constructor->m_buffer->m_data;
  if ( result )
  {
    result->__vftable = (vostok::animation::fermi_interpolator_vtbl *)&vostok::animation::fermi_interpolator::`vftable';
    result->m_total_transition_time = this->m_total_transition_time;
    result->m_epsilon = this->m_epsilon;
  }
  else
  {
    result = 0;
  }
  m_buffer = constructor->m_buffer;
  m_buffer->m_data += 12;
  m_buffer->m_size -= 12;
  return result;
}
