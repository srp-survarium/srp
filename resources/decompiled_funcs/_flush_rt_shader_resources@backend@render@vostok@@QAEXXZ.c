void __thiscall vostok::render::backend::flush_rt_shader_resources(
        vostok::render::backend *this,
        vostok::render::backend *thisa)
{
  int y; // eax
  ID3D11ShaderResourceView *rv[12]; // [esp+20h] [ebp-30h] BYREF

  y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
  memset(rv, 0, sizeof(rv));
  (*(void (__stdcall **)(int, _DWORD, int, ID3D11ShaderResourceView **))(*(_DWORD *)y + 32))(y, 0, 12, rv);
  (*(void (__stdcall **)(int, _DWORD, int, ID3D11ShaderResourceView **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                       + 100))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    0,
    12,
    rv);
  (*(void (__stdcall **)(int, _DWORD, int, ID3D11ShaderResourceView **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                       + 124))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    0,
    12,
    rv);
  memset(
    (unsigned __int8 *)thisa->m_ps_textures_handler.m_tmp_buffer,
    0,
    sizeof(thisa->m_ps_textures_handler.m_tmp_buffer));
}
