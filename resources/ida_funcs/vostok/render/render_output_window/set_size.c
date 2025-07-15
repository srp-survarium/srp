void __userpurge vostok::render::render_output_window::set_size(
        unsigned int width@<ecx>,
        vostok::render::renderer_context_targets *height@<eax>,
        vostok::render::render_output_window *this,
        bool fullscreen,
        vostok::render::renderer_context_targets *force_resize)
{
  vostok::render::backend *v7; // ecx

  if ( width
    && height
    && ((_BYTE)force_resize
     || width != this->m_current_size.x
     || height != (vostok::render::renderer_context_targets *)this->m_current_size.y
     || this->m_windowed != !fullscreen) )
  {
    this->m_current_size.x = width;
    this->m_windowed = !fullscreen;
    this->m_current_size.y = (unsigned int)height;
    vostok::render::renderer_context_targets::create_targets(
      force_resize,
      (int)&this->m_targets,
      (vostok::math::uint2)__PAIR64__(width, (unsigned int)force_resize),
      height);
    vostok::render::res_render_output::set_size(
      (vostok::render::res_render_output *)force_resize,
      this->m_output.m_object,
      width,
      (unsigned int)height,
      fullscreen,
      (HWND)force_resize);
    if ( this->m_flash_renderer )
    {
      vostok::render::backend::set_render_targets(
        (ID3D11RenderTargetView *)this->m_targets.m_family[48].target.m_object,
        this->m_targets.m_family[47].target.m_object,
        0,
        0,
        (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
      vostok::render::backend::flush(
        v7,
        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
      survarium::flash_renderer::on_reset_device(
        this->m_flash_renderer,
        this->m_current_size.x,
        this->m_current_size.y,
        (ID3D11Device *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
        (ID3D11DeviceContext *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y);
    }
  }
}
