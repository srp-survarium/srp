void __usercall vostok::render::res_render_output::update_targets(
        vostok::render::res_render_output *this@<ecx>,
        int a2@<eax>)
{
  HRESULT v3; // eax
  const char *d3d11_error_string; // eax
  HRESULT v5; // esi
  vostok::render::res_render_output *v6; // ecx
  const char *v7; // eax
  bool do_debug_break; // [esp+25h] [ebp-5h] BYREF
  ID3D11Texture2D *buffer; // [esp+26h] [ebp-4h] BYREF

  v3 = (*(int (__stdcall **)(_DWORD, _DWORD, GUID *, ID3D11Texture2D **))(**(_DWORD **)(a2 + 204) + 36))(
         *(_DWORD *)(a2 + 204),
         0,
         &_GUID_6f15aaf2_d208_4e89_9ab4_489535d34f9c,
         &buffer);
  if ( !LOBYTE(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_ids._M_impl._M_end_of_storage._M_data)
    && v3 < 0 )
  {
    do_debug_break = 1;
    d3d11_error_string = make_d3d11_error_string(v3);
    vostok::debug::on_error(
      &do_debug_break,
      process_error_true,
      (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_ids._M_impl._M_end_of_storage,
      assert_untyped,
      "assertion_failed",
      d3d11_error_string,
      ".\\res_render_output.cpp",
      "vostok::render::res_render_output::update_targets",
      0x16Bu);
    if ( vostok::debug::is_debugger_present() || do_debug_break )
      __debugbreak();
  }
  v5 = (*(int (__stdcall **)(int, ID3D11Texture2D *, _DWORD, int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x
                                                                 + 36))(
         `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
         buffer,
         0,
         a2 + 208);
  buffer->Release(buffer);
  if ( !BYTE1(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_ids._M_impl._M_end_of_storage._M_data)
    && v5 < 0 )
  {
    do_debug_break = 1;
    v7 = make_d3d11_error_string(v5);
    vostok::debug::on_error(
      &do_debug_break,
      process_error_true,
      (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_ids._M_impl._M_end_of_storage._M_data
    + 1,
      assert_untyped,
      "assertion_failed",
      v7,
      ".\\res_render_output.cpp",
      "vostok::render::res_render_output::update_targets",
      0x16Fu);
    if ( vostok::debug::is_debugger_present() || do_debug_break )
      __debugbreak();
  }
  vostok::render::res_render_output::update_depth_stencil_buffer(v6, a2);
}
