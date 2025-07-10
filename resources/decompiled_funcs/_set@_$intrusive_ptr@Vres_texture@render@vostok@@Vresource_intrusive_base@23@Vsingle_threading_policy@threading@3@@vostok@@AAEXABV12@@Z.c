void __userpurge vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<ecx>,
        vostok::render::res_texture **a2@<edi>,
        const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *object)
{
  vostok::render::res_texture *v3; // eax
  vostok::render::res_texture *m_object; // eax

  v3 = *a2;
  if ( *a2 != object->m_object )
  {
    if ( v3 )
    {
      if ( v3->m_reference_count-- == 1 )
        vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this);
    }
    m_object = object->m_object;
    *a2 = object->m_object;
    if ( m_object )
      ++m_object->m_reference_count;
  }
}
