void __fastcall vostok::render::event_query::init_query(vostok::render::event_query *this, int a2)
{
  D3D11_QUERY_DESC query_desc; // [esp+0h] [ebp-8h] BYREF

  query_desc.MiscFlags = 0;
  query_desc.Query = D3D11_QUERY_EVENT;
  (*(void (__stdcall **)(int, D3D11_QUERY_DESC *, int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x
                                                      + 96))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
    &query_desc,
    a2);
}
