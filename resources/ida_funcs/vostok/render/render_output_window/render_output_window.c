void __thiscall vostok::render::render_output_window::render_output_window(
        vostok::render::render_output_window *this,
        vostok::render::render_output_window *window_configuration,
        const vostok::render::output_window_configuration *window_configurationa)
{
  vostok::render::renderer_context_targets *v4; // ecx
  vostok::render::res_render_output *render_output; // eax
  unsigned int m_object; // eax
  unsigned int v7; // edx
  int v8; // ecx
  const char *m_conflicted_key_name; // eax
  vostok::render::backend *v10; // ecx
  survarium::flash_renderer *v11; // eax
  survarium::game *m_game; // ecx
  unsigned int width; // ecx
  vostok::math::uint2 v14; // [esp-8h] [ebp-24h] BYREF
  _DWORD v15[3]; // [esp+10h] [ebp-Ch] BYREF

  vostok::resources::unmanaged_resource::unmanaged_resource(window_configuration, 1u);
  window_configuration->__vftable = (vostok::render::render_output_window_vtbl *)&vostok::render::render_output_window::`vftable';
  vostok::render::render_output_window::get_window_client_size(
    (HWND)window_configurationa->hwnd,
    &v14,
    window_configurationa->windowed);
  vostok::render::renderer_context_targets::renderer_context_targets(v4, (int)&window_configuration->m_targets, v14);
  render_output = vostok::render::resource_manager::create_render_output(
                    (vostok::render::resource_manager *)window_configurationa->windowed,
                    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                    (HWND__ *)window_configurationa->hwnd,
                    (vostok::render::res_render_output *)window_configurationa->windowed);
  window_configuration->m_output.m_object = 0;
  if ( render_output )
  {
    window_configuration->m_output.m_object = render_output;
    ++render_output->m_reference_count;
  }
  window_configuration->m_window = (HWND__ *)window_configurationa->hwnd;
  window_configuration->m_windowed = window_configurationa->windowed;
  window_configuration->m_current_size = *vostok::render::render_output_window::get_window_client_size(
                                            (HWND)window_configurationa->hwnd,
                                            v15,
                                            window_configurationa->windowed);
  if ( window_configurationa->create_flash_renderer )
  {
    m_object = (unsigned int)window_configuration->m_targets.m_family[48].target.m_object;
    v7 = (unsigned int)window_configuration->m_targets.m_family[47].target.m_object;
    if ( m_object )
      v8 = *(_DWORD *)(m_object + 16);
    else
      v8 = 0;
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    if ( *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) != v8 )
    {
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = v8;
      *((_BYTE *)m_conflicted_key_name + 163) = 1;
    }
    if ( v7 )
      v10 = *(vostok::render::backend **)(v7 + 16);
    else
      v10 = 0;
    if ( *((vostok::render::backend **)m_conflicted_key_name + 536) != v10 )
    {
      *((_DWORD *)m_conflicted_key_name + 536) = v10;
      *((_BYTE *)m_conflicted_key_name + 164) = 1;
    }
    if ( *((_DWORD *)m_conflicted_key_name + 537) )
    {
      *((_DWORD *)m_conflicted_key_name + 537) = 0;
      *((_BYTE *)m_conflicted_key_name + 165) = 1;
    }
    if ( *((_DWORD *)m_conflicted_key_name + 538) )
    {
      *((_DWORD *)m_conflicted_key_name + 538) = 0;
      *((_BYTE *)m_conflicted_key_name + 166) = 1;
    }
    vostok::render::backend::flush(v10, (int)m_conflicted_key_name);
    if ( vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
           0x10u) )
    {
      survarium::flash_renderer::flash_renderer(
        (survarium::flash_renderer *)window_configurationa->scaleform_render_queue,
        window_configurationa->scaleform_render_queue,
        (ID3D11Device *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
        (ID3D11DeviceContext *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y);
    }
    else
    {
      v11 = 0;
    }
    m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
    window_configuration->m_flash_renderer = v11;
    survarium::flash_renderer::on_reset_device(
      v11,
      window_configuration->m_current_size.x,
      window_configuration->m_current_size.y,
      (ID3D11Device *)m_game->m_game_world.m_mouse_pos.x,
      (ID3D11DeviceContext *)m_game->m_game_world.m_mouse_pos.y);
  }
  else
  {
    window_configuration->m_flash_renderer = 0;
  }
  width = window_configurationa->width;
  if ( width )
    vostok::render::render_output_window::set_size(
      width,
      (vostok::render::renderer_context_targets *)window_configurationa->height,
      window_configuration,
      !window_configurationa->windowed,
      (vostok::render::renderer_context_targets *)1);
}
