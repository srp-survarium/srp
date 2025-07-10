vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **__usercall vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **a2@<edi>)
{
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v2; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v3; // esi

  v2 = 0;
  if ( this )
  {
    ++this[1].m_object;
    v2 = this;
  }
  v3 = *a2;
  *a2 = v2;
  if ( v3 )
  {
    if ( v3[1].m_object-- == (vostok::render::res_texture *)1 )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this);
  }
  return a2;
}
