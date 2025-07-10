void __thiscall survarium::login_menu::clear_resources(survarium::login_menu *this)
{
  survarium::flash_movie_resource *m_object; // eax
  survarium::flash_movie_resource *v3; // eax
  survarium::flash_movie_resource *v4; // [esp-4h] [ebp-8h] BYREF

  if ( this->m_login_menu_ui.m_object )
  {
    v4 = 0;
    m_object = this->m_login_menu_ui.m_object;
    if ( m_object )
    {
      v4 = this->m_login_menu_ui.m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    vostok::render::game::renderer::hide_movie(
      (vostok::render::game::renderer *)&this->m_render_scene_view,
      (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)this->m_game->m_renderer,
      (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base>)&this->m_render_scene_view);
  }
  if ( this->m_cursor_ui.m_object )
  {
    v4 = 0;
    v3 = this->m_cursor_ui.m_object;
    if ( v3 )
    {
      v4 = this->m_cursor_ui.m_object;
      _InterlockedExchangeAdd(&v3->m_reference_count, 1u);
    }
    vostok::render::game::renderer::hide_movie(
      (vostok::render::game::renderer *)&v4,
      (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)this->m_game->m_renderer,
      (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base>)&this->m_render_scene_view);
  }
}
