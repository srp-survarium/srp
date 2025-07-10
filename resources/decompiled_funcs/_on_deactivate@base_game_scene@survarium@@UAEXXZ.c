void __thiscall survarium::base_game_scene::on_deactivate(survarium::base_game_scene *this)
{
  this->m_is_active = 0;
  this->m_camera_director->on_focus(this->m_camera_director, 0);
}
