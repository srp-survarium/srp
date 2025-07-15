vostok::render::shader_constant_table *__thiscall vostok::render::shader_constant_table::operator=(
        vostok::render::shader_constant_table *this,
        const vostok::render::shader_constant_table *__that,
        const vostok::render::shader_constant *m_pointer)
{
  const vostok::render::shader_constant *v3; // ebx
  const vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *m_host; // eax

  v3 = m_pointer;
  __that->m_reference_count = *(_DWORD *)&m_pointer->m_slot.m_class_id;
  m_pointer = (const vostok::render::shader_constant *)v3->m_source.m_pointer;
  vostok::buffer_vector<vostok::render::shader_constant>::assign<vostok::render::shader_constant const *>(
    &__that->m_table,
    (const vostok::render::shader_constant *)HIDWORD(v3->m_slot.m_value),
    &m_pointer);
  m_host = (const vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v3[32].m_host;
  m_pointer = (const vostok::render::shader_constant *)*((_DWORD *)&v3[32].m_host + 1);
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::assign<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> const *>(
    &__that->m_const_buffers,
    m_host,
    (const vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *const *)&m_pointer);
  __that->m_is_registered = v3[38].m_source.m_size;
  return (vostok::render::shader_constant_table *)__that;
}
