vostok::render::res_render_output *__userpurge vostok::render::resource_manager::create_render_output@<eax>(
        vostok::render::resource_manager *this@<ecx>,
        int a2@<edi>,
        HWND__ *window,
        BOOL windowed)
{
  vostok::memory::doug_lea_allocator *v4; // esi
  char *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ecx
  char *v7; // eax
  vostok::render::res_render_output *v8; // ecx
  int v9; // eax
  int v10; // esi
  _DWORD *v11; // eax
  const char *v13; // [esp+0h] [ebp-8h]
  const char *v14; // [esp+0h] [ebp-8h]
  const char *v15; // [esp+4h] [ebp-4h]
  unsigned int savedregs; // [esp+8h] [ebp+0h]

  v4 = vostok::render::g_allocator;
  v5 = type_info::raw_name(&vostok::render::res_render_output `RTTI Type Descriptor');
  v7 = vostok::memory::doug_lea_allocator::malloc_impl(v6, (int)v4, 0xF0u, v5, v13, v15, savedregs);
  if ( v7 )
  {
    vostok::render::res_render_output::res_render_output(v8, (int)v7, window, windowed);
    v10 = v9;
  }
  else
  {
    v10 = 0;
  }
  *(_BYTE *)(v10 + 238) = 1;
  if ( *(_DWORD *)((char *)&loc_9397C + a2) >= *(_DWORD *)((char *)&loc_93980 + a2)
    && !`vostok::buffer_vector<vostok::render::res_render_output *>::push_back'::`11'::debug_macro_helper_ignore_always )
  {
    HIBYTE(windowed) = 0;
    vostok::debug::on_error(
      (bool *)&windowed + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::render::res_render_output *>::push_back",
      (const char *)0x12E,
      "buffer overflow",
      v14);
    if ( vostok::debug::is_debugger_present() || HIBYTE(windowed) )
      __debugbreak();
  }
  v11 = *(_DWORD **)((char *)&loc_9397C + a2);
  if ( v11 )
    *v11 = v10;
  *(_DWORD *)((char *)&loc_9397C + a2) += 4;
  return (vostok::render::res_render_output *)v10;
}
