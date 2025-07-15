void __thiscall vostok::animation::animation_collection::deserialize(
        vostok::animation::animation_collection *this,
        vostok::memory::reader *r)
{
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v4; // esi
  vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> *m_begin; // esi
  vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> *m_end; // edi
  unsigned int v7; // [esp+14h] [ebp+8h]
  unsigned int v8; // [esp+14h] [ebp+8h]

  this->m_type = *(_DWORD *)r->m_pointer;
  r->m_pointer += 4;
  m_pointer = r->m_pointer;
  v7 = *(_DWORD *)m_pointer;
  r->m_pointer = m_pointer + 4;
  this->m_random_number.m_seed = v7;
  this->m_is_cyclic_repeating = *r->m_pointer++;
  v4 = r->m_pointer;
  v8 = *(_DWORD *)v4;
  r->m_pointer = v4 + 4;
  this->m_current_animation_index = v8;
  this->m_can_repeat_successively = *r->m_pointer++;
  m_begin = this->m_animations.m_begin;
  m_end = this->m_animations.m_end;
  while ( m_begin != m_end )
  {
    m_begin->m_object->deserialize(m_begin->m_object, r);
    ++m_begin;
  }
}
