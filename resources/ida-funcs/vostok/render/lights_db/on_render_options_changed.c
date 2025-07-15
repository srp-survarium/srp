void __userpurge vostok::render::lights_db::on_render_options_changed(
        vostok::render::lights_db *this@<ecx>,
        vostok::render::light ***a2@<eax>,
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> force_recreate_buffers)
{
  vostok::render::light **v3; // esi
  vostok::render::light **v4; // edi
  vostok::render::light *v5; // ecx
  unsigned int i; // eax

  v3 = *a2;
  v4 = a2[1];
  while ( v3 != v4 )
  {
    vostok::render::light::on_render_options_changed(*v3);
    v5 = 0;
    for ( i = 656; i < 0x2A8; i += 4 )
    {
      v5->need_refresh_static_shadows[(_DWORD)*v3] = 1;
      *(_DWORD *)((char *)*v3 + i - 24) = 0;
      *(unsigned int *)((char *)&(*v3)->m_reference_count + i) = 0;
      v5 = (vostok::render::light *)((char *)v5 + 1);
    }
    (*v3)->m_force_refresh = 1;
    vostok::render::light::try_create_static_shadow_buffers(v5, (int)*v3, force_recreate_buffers);
    v3 += 2;
  }
}
