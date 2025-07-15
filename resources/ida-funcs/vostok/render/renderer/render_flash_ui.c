void __thiscall vostok::render::renderer::render_flash_ui(
        vostok::render::renderer *this,
        vostok::render::render_output_window *output_window,
        int wszName)
{
  unsigned int v3; // ecx
  int v4; // edi
  int v5; // esi
  int v6; // esi
  void *v7; // esp
  const char **v8; // ebx
  int v9; // esi
  int v10; // ecx
  int z_low; // eax
  int v12; // edi
  _DWORD *v13; // esi
  vostok::render::backend *v14; // ecx
  survarium::flash_renderer *v15; // ecx
  const char *v16; // [esp+0h] [ebp-28h] BYREF
  unsigned __int8 v17; // [esp+4h] [ebp-24h]
  const char **v18; // [esp+18h] [ebp-10h]
  survarium::flash_text_manager *text_manager; // [esp+1Ch] [ebp-Ch]
  survarium::flash_movie **v20; // [esp+20h] [ebp-8h]
  unsigned int v21; // [esp+24h] [ebp-4h]

  if ( s_ui_enabled && *(_DWORD *)(wszName + 11980) )
  {
    pix_event_wrapper_dx11::pix_event_wrapper_dx11(
      (pix_event_wrapper_dx11 *)this,
      (pix_event_wrapper_dx11 *)&wszName + 3,
      (int)L"flash_renderer");
    v4 = *(_DWORD *)(*(_DWORD *)&output_window->m_targets.m_family[1].orig_name.m_buffer[28] + 16268);
    v5 = *(int *)((char *)&dword_10D20 + v4);
    text_manager = *(survarium::flash_text_manager **)((char *)&dword_10DA8 + v4);
    v6 = (v5 - *(int *)((char *)&dword_10D1C + v4)) >> 2;
    output_window = (vostok::render::render_output_window *)(4 * v6);
    v7 = alloca(4 * v6);
    v21 = 0;
    v8 = &v16;
    v20 = (survarium::flash_movie **)&v16;
    v18 = &(&v16)[v6];
    if ( v6 )
    {
      do
      {
        v9 = *(_DWORD *)(*(int *)((char *)&dword_10D1C + v4) + 4 * v21);
        if ( v8 >= v18
          && !`vostok::buffer_vector<survarium::flash_movie *>::push_back'::`11'::debug_macro_helper_ignore_always )
        {
          HIBYTE(output_window) = 0;
          vostok::debug::on_error(
            (bool *)&output_window + 3,
            process_error_true,
            0,
            "assertion_failed",
            "fatal error",
            "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
            "vostok::buffer_vector<struct survarium::flash_movie *>::push_back",
            (const char *)0x12E,
            "buffer overflow",
            v16);
          if ( vostok::debug::is_debugger_present() || HIBYTE(output_window) )
            __debugbreak();
        }
        if ( v8 )
          *v8 = *(const char **)(v9 + 264);
        v10 = *(int *)((char *)&dword_10D20 + v4) - *(int *)((char *)&dword_10D1C + v4);
        ++v8;
        ++v21;
        v3 = v10 >> 2;
      }
      while ( v21 < v3 );
    }
    z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    v12 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7440);
    v13 = (_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384);
    LOBYTE(v3) = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) != v12;
    *(_BYTE *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 117) |= v3;
    *v13 = v12;
    vostok::render::backend::clear_depth_stencil((vostok::render::backend *)v3, z_low, 3u, *(float *)&v16, v17);
    vostok::render::backend::flush(
      v14,
      LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
    survarium::flash_renderer::present(
      v15,
      *(_DWORD *)(wszName + 11980),
      v8 != (const char **)v20 ? v20 : 0,
      (Scaleform::GFx::Resource *)(((char *)v8 - (char *)v20) >> 2),
      text_manager);
    D3DPERF_EndEvent();
  }
}
