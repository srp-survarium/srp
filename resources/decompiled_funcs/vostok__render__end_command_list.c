void __usercall vostok::render::end_command_list(IUnknown **out_empty_query_ptr@<eax>)
{
  (*(void (__stdcall **)(int, IUnknown *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                         + 112))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    *out_empty_query_ptr);
  while ( (*(int (__stdcall **)(int, IUnknown *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                        + 116))(
            `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
            *out_empty_query_ptr,
            0,
            0,
            0) )
    ;
  (*out_empty_query_ptr)->Release(*out_empty_query_ptr);
}
