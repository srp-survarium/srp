void __userpurge vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::create_state(
        ID3D11RasterizerState **ppIState@<esi>,
        int a2@<ecx>,
        unsigned int a3@<ebx>,
        vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC> *this,
        D3D11_RASTERIZER_DESC desc)
{
  int x; // eax
  HRESULT v6; // eax
  const char *d3d11_error_string; // eax
  bool do_debug_break; // [esp+19h] [ebp-1h] BYREF

  do_debug_break = HIBYTE(a2);
  if ( !ignore_always_28
    && (*(int (__stdcall **)(int, vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC> **, ID3D11RasterizerState **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x + 88))(
         `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
         &this,
         ppIState) < 0 )
  {
    x = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x;
    do_debug_break = 1;
    v6 = (*(int (__stdcall **)(int, vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC> **, ID3D11RasterizerState **))(*(_DWORD *)x + 88))(
           x,
           &this,
           ppIState);
    d3d11_error_string = make_d3d11_error_string(v6);
    vostok::debug::on_error(
      a3,
      &do_debug_break,
      process_error_true,
      &ignore_always_28,
      assert_untyped,
      "assertion_failed",
      d3d11_error_string,
      ".\\state_cache.cpp",
      "vostok::render::state_cache<struct ID3D11RasterizerState,struct D3D11_RASTERIZER_DESC>::create_state",
      0x30u);
    if ( vostok::debug::is_debugger_present() || do_debug_break )
      __debugbreak();
  }
}
