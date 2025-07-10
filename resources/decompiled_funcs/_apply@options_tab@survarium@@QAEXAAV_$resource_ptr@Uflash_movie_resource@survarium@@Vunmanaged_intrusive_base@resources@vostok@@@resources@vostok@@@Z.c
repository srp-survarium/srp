void __userpurge survarium::options_tab::apply(
        survarium::options_tab *this@<ecx>,
        int a2@<edi>,
        vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *movie)
{
  unsigned __int8 i; // bl
  int v4; // ecx
  int v5; // eax
  int v6; // eax
  vostok::console_commands::console_command *v7; // eax
  vostok::render::scene_renderer *v8; // [esp-18h] [ebp-20h]
  int v9; // [esp-10h] [ebp-18h]

  for ( i = 0; i < *(_BYTE *)(a2 + 4); ++i )
  {
    v4 = *(_DWORD *)(*(_DWORD *)a2 + 4 * i);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 16))(v4);
  }
  if ( *(_DWORD *)(a2 + 8) == 2 )
  {
    LOBYTE(v9) = 0;
    v5 = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 88);
    if ( v5 )
    {
      v9 = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 88);
      _InterlockedExchangeAdd((volatile signed __int32 *)(v5 + 208), 1u);
    }
    v6 = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 940);
    v8 = *(vostok::render::scene_renderer **)(*(_DWORD *)(*(_DWORD *)(v6 + 168) + 148) + 16);
    vostok::render::scene_renderer::end_render_options_changing(
      v8,
      (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)v8,
      (vostok::resources::resource_ptr<vostok::render::base_output_window,vostok::resources::unmanaged_intrusive_base>)(v6 + 4),
      v9,
      0,
      (volatile int *)1);
  }
  v7 = vostok::console_commands::find("cfg_save_user");
  v7->execute(v7, (const char *)&buf);
  survarium::options_tab::initialize_data((survarium::options_tab *)movie, a2, movie);
}
