void __usercall vostok::render::backend::flush_rt(vostok::render::backend *this@<ecx>, int a2@<esi>)
{
  if ( *(_BYTE *)(a2 + 163)
     | (unsigned __int8)(*(_BYTE *)(a2 + 164) | *(_BYTE *)(a2 + 165) | *(_BYTE *)(a2 + 166) | *(_BYTE *)(a2 + 167)) )
  {
    (*(void (__stdcall **)(int, int, int, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                 + 132))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      4,
      a2 + 2140,
      *(_DWORD *)(a2 + 2156));
  }
  *(_DWORD *)(a2 + 163) = 0;
  *(_BYTE *)(a2 + 167) = 0;
}
