void __thiscall survarium::lobby_menu::on_deactivate(survarium::lobby_menu *this)
{
  survarium::camera_director *m_camera_director; // ecx
  vostok::input::world *v3; // eax
  survarium::game *v4; // ecx
  Scaleform::GFx::Movie *m_movie; // ecx
  int v6; // ecx

  m_camera_director = this->m_camera_director;
  this->m_is_active = 0;
  m_camera_director->on_focus(m_camera_director, 0);
  v3 = this->m_game->input_world(this->m_game);
  v3->remove_handler(v3, &this->vostok::input::handler);
  survarium::game::deactivate_main_menu(v4, (int)this->m_game);
  m_movie = this->m_lobby_menu_ui.m_object->movie->m_movie;
  m_movie->ForceCollectGarbage(m_movie, 2u);
  if ( this->m_is_in_match_making )
  {
    survarium::base_game_scene::hide_movie(this, &this->m_match_making_ui, v6);
    this->m_is_in_match_making = 0;
  }
}
