vostok::render::res_buffer_list *__userpurge vostok::render::res_buffer_list::operator=@<eax>(
        const vostok::render::res_buffer_list *__that@<eax>,
        vostok::render::res_buffer_list *this)
{
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *m_begin; // esi
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v4; // edi
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v5; // eax
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v6; // esi
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *m_end; // [esp+14h] [ebp+8h]

  this->m_reference_count = __that->m_reference_count;
  m_begin = this->m_container.m_begin;
  v4 = __that->m_container.m_begin;
  m_end = __that->m_container.m_end;
  while ( m_begin != this->m_container.m_end )
    vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(m_begin++);
  v5 = this->m_container.m_begin;
  this->m_container.m_end = &v5[m_end - v4];
  v6 = v5;
  while ( v4 != m_end )
  {
    if ( v6 )
      vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        v6,
        v4);
    ++v4;
    ++v6;
  }
  return this;
}
