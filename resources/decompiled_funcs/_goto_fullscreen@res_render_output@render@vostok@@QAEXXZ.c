void __usercall vostok::render::res_render_output::goto_fullscreen(
        vostok::render::res_render_output *this@<ecx>,
        int a2@<esi>)
{
  int v2; // edi
  int v3; // eax
  BOOL v4; // edx
  HRESULT v5; // eax
  const char *d3d11_error_string; // eax
  bool do_debug_break; // [esp+19h] [ebp-1h] BYREF

  do_debug_break = HIBYTE(this);
  if ( *(_DWORD *)(a2 + 204) )
  {
    if ( *(_DWORD *)(a2 + 220) )
    {
      if ( !*(_BYTE *)(a2 + 229) )
      {
        v2 = *((_DWORD *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_sound_scene.m_object
             + *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
               + 47));
        if ( !HIBYTE(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_ids._M_impl._M_finish)
          && (*(int (__stdcall **)(_DWORD, int, int))(**(_DWORD **)(a2 + 204) + 40))(*(_DWORD *)(a2 + 204), 1, v2) < 0 )
        {
          v3 = *(_DWORD *)(a2 + 204);
          v4 = *(_BYTE *)(a2 + 229) == 0;
          do_debug_break = 1;
          v5 = (*(int (__stdcall **)(int, BOOL, int))(*(_DWORD *)v3 + 40))(v3, v4, v2);
          d3d11_error_string = make_d3d11_error_string(v5);
          vostok::debug::on_error(
            &do_debug_break,
            process_error_true,
            (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_ids._M_impl._M_finish
          + 3,
            assert_untyped,
            "assertion_failed",
            d3d11_error_string,
            ".\\res_render_output.cpp",
            "vostok::render::res_render_output::goto_fullscreen",
            0x160u);
          if ( vostok::debug::is_debugger_present() || do_debug_break )
            __debugbreak();
        }
      }
    }
  }
}
