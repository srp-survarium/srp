vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__userpurge vostok::render::renderer_context::get_t@<eax>(
        vostok::render::renderer_context *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *a2@<eax>,
        vostok::render::renderer_context *result,
        vostok::render::enum_render_target_index index)
{
  vostok::render::res_texture *m_object; // ecx

  m_object = result->m_targets->m_family[(_DWORD)this].texture.m_object;
  a2->m_object = 0;
  if ( m_object )
  {
    ++m_object->m_reference_count;
    a2->m_object = m_object;
  }
  return a2;
}
