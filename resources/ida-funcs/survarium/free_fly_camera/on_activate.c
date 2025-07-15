void __thiscall survarium::free_fly_camera::on_activate(
        survarium::free_fly_camera *this,
        survarium::camera_director *cd)
{
  unsigned int m_permanent_time_in_ms; // eax
  float v4; // xmm1_4
  float z; // xmm2_4
  float y; // xmm4_4
  float x; // xmm6_4
  unsigned int m_prev_time_ms; // [esp-4h] [ebp-1Ch]

  survarium::game_camera::on_activate(this, cd);
  m_permanent_time_in_ms = this->m_game_scene->m_game->m_permanent_time_in_ms;
  v4 = s_bm_current_air_resistance;
  this->m_prev_delta_sec = FLOAT_N1_0;
  this->m_prev_time_ms = m_permanent_time_in_ms;
  qmemcpy(&this->m_inverted_view_matrix, &cd->m_inverted_view, sizeof(this->m_inverted_view_matrix));
  this->m_inverted_view_matrix.j.x = 0.0;
  this->m_inverted_view_matrix.j.z = 0.0;
  this->m_inverted_view_matrix.j.y = v4;
  z = this->m_inverted_view_matrix.k.z;
  y = this->m_inverted_view_matrix.k.y;
  m_prev_time_ms = this->m_prev_time_ms;
  x = this->m_inverted_view_matrix.k.x;
  this->m_inverted_view_matrix.i.x = (float)(v4 * z) - (float)(0.0 * y);
  this->m_inverted_view_matrix.i.y = (float)(x * 0.0) - (float)(0.0 * z);
  this->m_inverted_view_matrix.i.z = (float)(0.0 * y) - (float)(x * v4);
  survarium::game_effect_player::reset(0, &this->m_effect_player.m_current_time_in_ms, m_prev_time_ms);
}
