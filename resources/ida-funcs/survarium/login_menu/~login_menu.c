void __thiscall survarium::login_menu::~login_menu(survarium::login_menu *this)
{
  survarium::flash_movie_resource *m_object; // eax
  survarium::flash_movie_resource *v3; // eax

  this->survarium::base_game_scene::survarium::game_scene::__vftable = (survarium::login_menu_vtbl *)&survarium::login_menu::`vftable'{for `survarium::game_scene'};
  this->survarium::base_game_scene::survarium::engine::__vftable = (survarium::engine_vtbl *)&survarium::login_menu::`vftable'{for `survarium::engine'};
  this->vostok::input::handler::__vftable = (vostok::input::handler_vtbl *)&survarium::login_menu::`vftable';
  m_object = this->m_cursor_ui.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_cursor_ui.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_cursor_ui.m_object);
  v3 = this->m_login_menu_ui.m_object;
  if ( v3 && !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_login_menu_ui.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_login_menu_ui.m_object);
  survarium::base_game_scene::~base_game_scene(this);
}
