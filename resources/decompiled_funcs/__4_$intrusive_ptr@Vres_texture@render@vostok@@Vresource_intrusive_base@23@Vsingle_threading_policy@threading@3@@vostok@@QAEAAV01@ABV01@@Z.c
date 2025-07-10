vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__usercall vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<ecx>,
        vostok::render::res_texture **a2@<edi>)
{
  vostok::render::res_texture *m_object; // ecx
  vostok::render::res_texture *v3; // eax
  vostok::render::res_texture *v4; // esi

  m_object = this->m_object;
  v3 = 0;
  if ( m_object )
  {
    v3 = m_object;
    ++m_object->m_reference_count;
  }
  v4 = *a2;
  *a2 = v3;
  if ( v4 )
  {
    if ( v4->m_reference_count-- == 1 )
      vostok::render::res_texture::destroy_impl(m_object);
  }
  return (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)a2;
}
