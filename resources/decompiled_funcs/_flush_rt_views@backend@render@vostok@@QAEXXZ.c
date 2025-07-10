void __thiscall vostok::render::backend::flush_rt_views(vostok::render::backend *this)
{
  int y; // eax
  _OWORD v2[2]; // [esp+20h] [ebp-20h] BYREF

  y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
  memset(v2, 0, sizeof(v2));
  (*(void (__stdcall **)(int, int, _OWORD *, _DWORD))(*(_DWORD *)y + 132))(y, 8, v2, 0);
}
