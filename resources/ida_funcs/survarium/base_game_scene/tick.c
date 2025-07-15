void __thiscall survarium::base_game_scene::tick(
        survarium::base_game_scene *this,
        unsigned int __formal,
        unsigned int current_time_in_ms,
        bool is_game_paused)
{
  survarium::camera_director *m_camera_director; // eax

  m_camera_director = this->m_camera_director;
  if ( m_camera_director->m_active_camera )
    m_camera_director->m_active_camera->tick(m_camera_director->m_active_camera);
  if ( !is_game_paused )
  {
    if ( this->m_physics_world )
      this->m_physics_world->tick(this->m_physics_world, current_time_in_ms);
  }
}
