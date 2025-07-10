void __thiscall survarium::game_world::on_deactivate(survarium::game_world *this)
{
  survarium::camera_director *m_camera_director; // ecx
  vostok::input::world *v3; // eax
  survarium::game *v4; // ecx
  Scaleform::GFx::Movie *m_movie; // ecx

  m_camera_director = this->m_camera_director;
  this->m_is_active = 0;
  m_camera_director->on_focus(m_camera_director, 0);
  v3 = this->m_game->input_world(this->m_game);
  v3->remove_handler(v3, &this->vostok::input::handler);
  survarium::game::deactivate_main_menu(v4);
  m_movie = this->game_ui.m_game_hud_ui.m_object->movie->m_movie;
  m_movie->ForceCollectGarbage(m_movie, 2u);
}
