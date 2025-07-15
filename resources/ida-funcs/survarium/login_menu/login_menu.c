void __usercall survarium::login_menu::login_menu(
        survarium::login_menu *this@<esi>,
        vostok::network::world *g@<eax>,
        survarium::base_game_scene *a3@<ecx>)
{
  survarium::login_menu *v4; // ecx

  survarium::base_game_scene::base_game_scene(a3, this, g, 0);
  this->m_block_btn_time = 0;
  this->survarium::base_game_scene::survarium::game_scene::__vftable = (survarium::login_menu_vtbl *)&survarium::login_menu::`vftable'{for `survarium::base_game_scene'};
  this->vostok::input::handler::__vftable = (vostok::input::handler_vtbl *)&survarium::login_menu::`vftable'{for `vostok::input::handler'};
  this->m_status = login_menu_status_connected;
  this->m_login_menu_ui.m_object = 0;
  this->m_cursor_ui.m_object = 0;
  this->m_mouse_helper.m_output_window = (vostok::resources::resource_ptr<vostok::render::base_output_window,vostok::resources::unmanaged_intrusive_base> *)&g[28];
  survarium::login_menu::query_resources(v4, (const char *)this);
}
