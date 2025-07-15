void __thiscall vostok::animation::animation_collection::deserialize(
        vostok::animation::animation_collection *this,
        vostok::memory::reader *r)
{
  const unsigned __int8 *m_pointer; // eax
  unsigned int v3; // edx
  const unsigned __int8 *v4; // eax
  unsigned int v5; // edx
  vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> *m_begin; // edi
  vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> *i; // ebx

  this->m_type = *(_DWORD *)r->m_pointer;
  r->m_pointer += 4;
  m_pointer = r->m_pointer;
  v3 = *(_DWORD *)m_pointer;
  r->m_pointer = m_pointer + 4;
  this->m_random_number.m_seed = v3;
  this->m_is_cyclic_repeating = *r->m_pointer++;
  v4 = r->m_pointer;
  v5 = *(_DWORD *)v4;
  r->m_pointer = v4 + 4;
  this->m_current_animation_index = v5;
  this->m_can_repeat_successively = *r->m_pointer++;
  m_begin = this->m_animations.m_begin;
  for ( i = this->m_animations.m_end; m_begin != i; ++m_begin )
    m_begin->m_object->deserialize(m_begin->m_object, r);
}
