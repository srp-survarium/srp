void __thiscall vostok::render::backend::clear_render_targets(
        vostok::render::backend *this,
        vostok::render::backend *color,
        vostok::math::color colora)
{
  ID3D11RenderTargetView **m_targets; // esi
  int v4; // edi
  float color_elements[4]; // [esp+4h] [ebp-10h] BYREF

  if ( s_debug_enabled_rt_clearing_value )
  {
    color_elements[0] = (double)colora.r * 0.0039215689;
    color_elements[1] = (double)colora.g * 0.0039215689;
    color_elements[2] = (double)colora.b * 0.0039215689;
    m_targets = color->m_targets;
    v4 = 4;
    color_elements[3] = 0.0039215689 * (double)colora.a;
    do
    {
      if ( *m_targets )
        (*(void (__stdcall **)(int, ID3D11RenderTargetView *, float *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                      + 200))(
          `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
          *m_targets,
          color_elements);
      ++m_targets;
      --v4;
    }
    while ( v4 );
  }
}
