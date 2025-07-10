void __usercall vostok::render::event_query::event_query(vostok::render::event_query *this@<ecx>, _DWORD *a2@<esi>)
{
  _DWORD v2[2]; // [esp+0h] [ebp-8h] BYREF

  *a2 = 0;
  v2[1] = 0;
  v2[0] = 0;
  (*(void (__stdcall **)(int, _DWORD *, _DWORD *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x
                                                 + 96))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
    v2,
    a2);
}
