void __usercall vostok::render::shader_constant_buffer::update(
        vostok::render::shader_constant_buffer *this@<ecx>,
        int a2@<esi>)
{
  if ( *(_BYTE *)(a2 + 100) )
  {
    if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 96) )
      (*(void (__stdcall **)(int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                                 + 192))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        *(_DWORD *)(a2 + 96),
        0,
        0,
        *(_DWORD *)(a2 + 88),
        0,
        0);
    *(_BYTE *)(a2 + 100) = 0;
  }
}
