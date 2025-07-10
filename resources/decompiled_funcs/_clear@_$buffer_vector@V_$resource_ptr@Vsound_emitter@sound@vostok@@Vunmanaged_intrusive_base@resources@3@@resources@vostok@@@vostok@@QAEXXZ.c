void __thiscall vostok::buffer_vector<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>>::clear(
        vostok::buffer_vector<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> > *this)
{
  vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> **p_m_end; // edi

  p_m_end = &this->m_end;
  vostok::buffer_vector<vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base>>::destroy(
    (vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> *)this->m_begin,
    (vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> *const *)&this->m_end);
  *p_m_end = this->m_begin;
}
