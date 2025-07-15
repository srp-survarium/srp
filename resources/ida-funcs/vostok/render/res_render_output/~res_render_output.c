void __usercall vostok::render::res_render_output::~res_render_output(
        vostok::render::res_render_output *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *a2@<esi>)
{
  vostok::render::res_texture *m_object; // edi
  vostok::render::res_texture *v3; // eax
  vostok::render::res_texture *v4; // edi
  vostok::render::res_texture *v5; // eax

  m_object = a2[55].m_object;
  ((void (__stdcall *)(vostok::render::res_texture *))m_object->__vftable[1].~vostok::render::res_texture)(m_object);
  ((void (__stdcall *)(vostok::render::res_texture *))m_object->__vftable[2].~vostok::render::res_texture)(m_object);
  v3 = a2[55].m_object;
  if ( v3 )
  {
    ((void (__stdcall *)(vostok::render::res_texture *))v3->__vftable[2].~vostok::render::res_texture)(a2[55].m_object);
    a2[55].m_object = 0;
  }
  v4 = a2[54].m_object;
  ((void (__stdcall *)(vostok::render::res_texture *))v4->__vftable[1].~vostok::render::res_texture)(v4);
  ((void (__stdcall *)(vostok::render::res_texture *))v4->__vftable[2].~vostok::render::res_texture)(v4);
  v5 = a2[54].m_object;
  if ( v5 )
  {
    ((void (__stdcall *)(vostok::render::res_texture *))v5->__vftable[2].~vostok::render::res_texture)(a2[54].m_object);
    a2[54].m_object = 0;
  }
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(a2 + 56);
}
