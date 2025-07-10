void __thiscall vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::render::res_texture *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this);
  }
}
