void __usercall vostok::render::backend::clear_depth_stencil(vostok::render::backend *this@<ecx>, int a2@<eax>)
{
  int v2; // ecx

  if ( s_debug_enabled_ds_clearing_value )
  {
    v2 = *(_DWORD *)(a2 + 2156);
    if ( v2 )
      (*(void (__stdcall **)(int, int, int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                           + 212))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        v2,
        3,
        1.0,
        0);
  }
}
