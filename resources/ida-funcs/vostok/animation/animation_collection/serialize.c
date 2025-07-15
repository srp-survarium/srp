void __thiscall vostok::animation::animation_collection::serialize(
        vostok::animation::animation_collection *this,
        vostok::memory::writer *w)
{
  vostok::memory::writer *v2; // edi
  vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> *m_begin; // ebx
  vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> *m_end; // esi

  v2 = w;
  w->write(w, &this->m_type, 4u);
  w = (vostok::memory::writer *)this->m_random_number.m_seed;
  v2->write(v2, &w, 4u);
  v2->write(v2, &this->m_is_cyclic_repeating, 1u);
  w = (vostok::memory::writer *)this->m_current_animation_index;
  v2->write(v2, &w, 4u);
  v2->write(v2, &this->m_can_repeat_successively, 1u);
  m_begin = this->m_animations.m_begin;
  m_end = this->m_animations.m_end;
  while ( m_begin != m_end )
  {
    m_begin->m_object->serialize(m_begin->m_object, v2);
    ++m_begin;
  }
}
