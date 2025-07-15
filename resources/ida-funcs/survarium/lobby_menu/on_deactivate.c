void __thiscall survarium::lobby_menu::on_deactivate(survarium::lobby_menu *this)
{
  vostok::input::handler *v2; // ebx
  vostok::input::world *v3; // eax
  survarium::game *v4; // ecx
  Scaleform::GFx::Movie *m_movie; // ecx
  survarium::lobby_menu *v6; // ecx

  this->m_timer.m_backup_time_factor = this->m_timer.m_time_factor;
  this->m_timer.m_backup_time_floating_factor = this->m_timer.m_time_floating_factor;
  vostok::timing::floating_timer::set_time_factor_impl(
    (vostok::timing::floating_timer *)this,
    (int)&this->m_timer,
    0.0,
    0.0);
  survarium::base_game_scene::on_deactivate(this);
  if ( this )
    v2 = &this->vostok::input::handler;
  else
    v2 = 0;
  v3 = this->m_game->input_world(this->m_game);
  v3->remove_handler(v3, v2);
  survarium::game::deactivate_main_menu(v4, (int)this->m_game);
  m_movie = this->m_lobby_menu_ui.m_object->movie->m_movie;
  m_movie->ForceCollectGarbage(m_movie, 2u);
  if ( this->m_is_in_match_making )
    survarium::lobby_menu::show_match_making(v6, (int)this, 0);
}
