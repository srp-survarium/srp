void __usercall survarium::login_menu::login_menu(survarium::login_menu *this@<ecx>, survarium::game *g@<eax>)
{
  survarium::login_menu *v3; // ecx

  survarium::base_game_scene::base_game_scene(this, g);
  this->survarium::base_game_scene::survarium::game_scene::__vftable = (survarium::login_menu_vtbl *)&survarium::login_menu::`vftable'{for `survarium::game_scene'};
  this->survarium::base_game_scene::survarium::engine::__vftable = (survarium::engine_vtbl *)&survarium::login_menu::`vftable'{for `survarium::engine'};
  this->vostok::input::handler::__vftable = (vostok::input::handler_vtbl *)&survarium::login_menu::`vftable';
  this->m_block_btn_time = 0;
  this->m_status = login_menu_status_connected;
  this->m_login_menu_ui.m_object = 0;
  this->m_cursor_ui.m_object = 0;
  survarium::login_menu::query_resources(v3, this);
}
