void __thiscall survarium::base_game_scene::on_activate(survarium::base_game_scene *this)
{
  survarium::game *m_game; // eax
  vostok::sound::world_user *v3; // eax

  m_game = this->m_game;
  this->m_is_active = 1;
  v3 = m_game->m_sound_world->get_logic_world_user(m_game->m_sound_world);
  vostok::sound::world_user::set_active_sound_scene(&this->m_sound_scene, v3);
  this->m_camera_director->on_focus(this->m_camera_director, 1);
  this->m_mouse_x = 50;
  this->m_mouse_y = 50;
}
