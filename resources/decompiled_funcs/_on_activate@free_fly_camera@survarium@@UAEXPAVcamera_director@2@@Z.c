void __thiscall survarium::free_fly_camera::on_activate(
        survarium::free_fly_camera *this,
        survarium::camera_director *cd)
{
  const vostok::math::float4x4 *v2; // xmm1_4
  vostok::math::float4x4 *p_m_inverted_view_matrix; // edx
  unsigned int m_current_time_in_ms; // ecx
  float v6; // xmm3_4
  float z; // xmm2_4
  float y; // xmm4_4
  float x; // xmm1_4
  __int64 v10; // [esp+0h] [ebp-Ch]

  v2 = clear_value;
  p_m_inverted_view_matrix = &this->m_inverted_view_matrix;
  qmemcpy((void *)&this->m_inverted_view_matrix, &cd->m_inverted_view, sizeof(this->m_inverted_view_matrix));
  m_current_time_in_ms = this->m_game_scene->m_game->m_current_time_in_ms;
  this->m_prev_delta_sec = -1.0;
  this->m_prev_time_ms = m_current_time_in_ms;
  v6 = *(float *)&v2;
  qmemcpy((void *)p_m_inverted_view_matrix, &cd->m_inverted_view, sizeof(vostok::math::float4x4));
  this->m_inverted_view_matrix.j.x = 0.0;
  this->m_inverted_view_matrix.j.z = 0.0;
  LODWORD(this->m_inverted_view_matrix.j.y) = v2;
  z = this->m_inverted_view_matrix.k.z;
  y = this->m_inverted_view_matrix.k.y;
  x = this->m_inverted_view_matrix.k.x;
  *(float *)&v10 = (float)(v6 * z) - (float)(0.0 * y);
  *((float *)&v10 + 1) = (float)(x * 0.0) - (float)(0.0 * z);
  *(_QWORD *)&p_m_inverted_view_matrix->i.x = v10;
  p_m_inverted_view_matrix->i.z = (float)(0.0 * y) - (float)(x * v6);
}
