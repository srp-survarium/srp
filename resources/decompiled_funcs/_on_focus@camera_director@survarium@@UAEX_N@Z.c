void __thiscall survarium::camera_director::on_focus(survarium::camera_director *this, BOOL b_focus_enter)
{
  if ( this->m_active_camera )
    this->m_active_camera->on_focus(this->m_active_camera, b_focus_enter);
}
