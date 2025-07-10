void __thiscall vostok::render::radiance_volume::end_render_to_cells(
        vostok::render::radiance_volume *this,
        vostok::render::radiance_volume *thisa)
{
  const char *m_conflicted_key_name; // esi
  int v3; // eax
  survarium::game *m_game; // edx

  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  vostok::render::backend::reset_render_targets(
    (vostok::render::backend *)this,
    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  v3 = *((_DWORD *)m_conflicted_key_name + 547);
  m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
  *((_BYTE *)m_conflicted_key_name + 167) |= *((_DWORD *)m_conflicted_key_name + 539) != v3;
  *((_DWORD *)m_conflicted_key_name + 539) = v3;
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)m_game->m_game_world.m_mouse_pos.y + 176))(
    m_game->m_game_world.m_mouse_pos.y,
    1,
    &thisa->m_saved_viewport);
}
