void __usercall vostok::render::index_buffer::unlock(vostok::render::index_buffer *this@<ecx>, _DWORD *a2@<eax>)
{
  a2[2] += a2[4];
  (*(void (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                             + 60))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    *(_DWORD *)(*a2 + 4),
    0);
}
