void __usercall survarium::camera_director::switch_to_camera(
        survarium::camera_director *this@<esi>,
        survarium::game_camera *c@<edi>)
{
  survarium::game_camera *m_active_camera; // ecx
  bool m_is_active; // bl

  m_active_camera = this->m_active_camera;
  m_is_active = this->m_game_scene->m_is_active;
  if ( m_active_camera )
  {
    if ( m_active_camera == c )
      return;
    if ( m_is_active )
      m_active_camera->on_focus(m_active_camera, 0);
    this->m_active_camera->on_deactivate(this->m_active_camera);
  }
  this->m_active_camera = c;
  if ( c )
  {
    c->on_activate(c, this);
    if ( m_is_active )
      this->m_active_camera->on_focus(this->m_active_camera, 1);
  }
}
