void __thiscall survarium::game_camera::on_activate(survarium::game_camera *this, survarium::camera_director *cd)
{
  qmemcpy((void *)&this->m_inverted_view_matrix, &cd->m_inverted_view, sizeof(this->m_inverted_view_matrix));
}
