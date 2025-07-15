void __thiscall survarium::demo_camera::tick(survarium::demo_camera *this)
{
  survarium::object_track **p_m_track; // edi
  survarium::object_track *v3; // edi
  float in_time; // [esp+Ch] [ebp-4h]

  p_m_track = &this->m_track;
  in_time = (double)(this->m_game_scene->m_game->m_permanent_time_in_ms - this->m_start_time_ms) * 0.001;
  survarium::object_track::evaluate(this->m_track, &this->m_inverted_view_matrix, in_time);
  v3 = *p_m_track;
  if ( in_time > (double)v3->m_max_time && !v3->m_cyclic )
    survarium::camera_director::switch_to_camera(this->m_camera_director, this->m_prev_camera);
}
