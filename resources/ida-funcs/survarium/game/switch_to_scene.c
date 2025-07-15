void __usercall survarium::game::switch_to_scene(survarium::game *this@<edi>, survarium::base_game_scene *scene@<esi>)
{
  survarium::base_game_scene *m_active_scene; // ecx

  m_active_scene = this->m_active_scene;
  if ( m_active_scene != scene )
  {
    if ( m_active_scene )
      m_active_scene->on_deactivate(m_active_scene);
    this->m_active_scene = scene;
    scene->on_activate(scene);
  }
}
