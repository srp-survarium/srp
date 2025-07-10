void __thiscall vostok::render::render_output_window::resize(
        vostok::render::render_output_window *this,
        vostok::render::render_output_window *force_resize,
        HWND force_resizea)
{
  vostok::render::renderer_context_targets *v3; // ecx
  unsigned int v4; // edx
  const char *m_conflicted_key_name; // ebx
  vostok::render::backend *v6; // ecx
  vostok::math::uint2 v7; // [esp-10h] [ebp-2Ch]
  vostok::render::renderer_context_targets *v8; // [esp+10h] [ebp-Ch] BYREF
  unsigned int v9; // [esp+14h] [ebp-8h]

  if ( force_resize->m_windowed )
  {
    vostok::render::render_output_window::get_window_client_size(force_resize->m_window, &v8, force_resize->m_windowed);
    v3 = v8;
    if ( v8 )
    {
      v4 = v9;
      if ( v9 )
      {
        if ( (_BYTE)force_resizea
          || v8 != (vostok::render::renderer_context_targets *)force_resize->m_current_size.x
          || v9 != force_resize->m_current_size.y )
        {
          force_resize->m_current_size.x = (unsigned int)v8;
          force_resize->m_current_size.y = v4;
          v7.y = (unsigned int)force_resizea;
          v7.x = (unsigned int)&force_resize->m_targets;
          vostok::render::renderer_context_targets::resize(
            v3,
            v7,
            (vostok::math::uint2)__PAIR64__(v4, (unsigned int)v3));
          vostok::render::res_render_output::resize(
            force_resize->m_output.m_object,
            0,
            0,
            force_resize->m_output.m_object->m_windowed,
            force_resizea);
          if ( force_resize->m_flash_renderer )
          {
            m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
            vostok::render::backend::set_render_targets(
              (ID3D11RenderTargetView *)force_resize->m_targets.m_family[48].target.m_object,
              force_resize->m_targets.m_family[47].target.m_object,
              0,
              0,
              (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
            vostok::render::backend::flush(v6, (int)m_conflicted_key_name);
            survarium::flash_renderer::on_reset_device(
              force_resize->m_flash_renderer,
              force_resize->m_current_size.x,
              force_resize->m_current_size.y,
              (ID3D11Device *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
              (ID3D11DeviceContext *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y);
          }
        }
      }
    }
  }
}
