void __thiscall survarium::demo_camera::on_activate(survarium::demo_camera *this, survarium::camera_director *cd)
{
  float v3; // xmm1_4
  float z; // xmm2_4
  float y; // xmm4_4
  float x; // xmm6_4

  survarium::game_camera::on_activate(this, cd);
  v3 = s_bm_current_air_resistance;
  this->m_start_time_ms = this->m_game_scene->m_game->m_current_time_in_ms;
  qmemcpy(&this->m_inverted_view_matrix, &cd->m_inverted_view, sizeof(this->m_inverted_view_matrix));
  this->m_inverted_view_matrix.j.x = 0.0;
  this->m_inverted_view_matrix.j.z = 0.0;
  this->m_inverted_view_matrix.j.y = v3;
  z = this->m_inverted_view_matrix.k.z;
  y = this->m_inverted_view_matrix.k.y;
  x = this->m_inverted_view_matrix.k.x;
  this->m_inverted_view_matrix.i.x = (float)(v3 * z) - (float)(0.0 * y);
  this->m_inverted_view_matrix.i.y = (float)(x * 0.0) - (float)(0.0 * z);
  this->m_inverted_view_matrix.i.z = (float)(0.0 * y) - (float)(x * v3);
}
