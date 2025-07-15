void __usercall vostok::render::render_target::~render_target(vostok::render::render_target *this@<ecx>, int a2@<edi>)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( !*(_DWORD *)(a2 + 8) )
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst->m_render_target_video_memory -= *(_DWORD *)(a2 + 48);
  v2 = *(_DWORD *)(a2 + 20);
  if ( v2 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 8))(*(_DWORD *)(a2 + 20));
    *(_DWORD *)(a2 + 20) = 0;
  }
  v3 = *(_DWORD *)(a2 + 12);
  if ( v3 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v3 + 8))(*(_DWORD *)(a2 + 12));
    *(_DWORD *)(a2 + 12) = 0;
  }
  v4 = *(_DWORD *)(a2 + 16);
  if ( v4 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v4 + 8))(*(_DWORD *)(a2 + 16));
    *(_DWORD *)(a2 + 16) = 0;
  }
  if ( *(_DWORD *)(a2 + 28) )
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      0,
      (vostok::render::res_texture *)(a2 + 28));
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 28));
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)(a2 + 4));
}
