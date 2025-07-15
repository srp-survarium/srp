void __thiscall vostok::particle::particle_action_billboard::set_defaults(
        vostok::particle::particle_action_billboard *this,
        bool mt_alloc)
{
  vostok::particle::particle_action_billboard *v2; // esi
  vostok::math::curve_line_ranged_float *p_m_movie_start_frame; // edi

  v2 = this;
  this->m_next.pointer = 0;
  p_m_movie_start_frame = &this->m_movie_start_frame;
  this->m_visibility = 1;
  this->m_billboard_parameters.screen_alignment = particle_screen_alignment_rectangle;
  this->m_billboard_parameters.locked_axis = particle_locked_axis_x;
  this->m_billboard_parameters.subuv_method = particle_subuv_method_linear;
  this->m_billboard_parameters.sub_image_horizontal = 0;
  this->m_billboard_parameters.sub_image_vertical = 0;
  this->m_billboard_parameters.sub_image_changes = 0;
  this->m_use_sub_uv = 0;
  this->m_sub_image_horizontal = 0;
  this->m_sub_image_vertical = 0;
  this->m_use_movie = 0;
  this->m_movie_frame_rate = default_fps_4;
  vostok::math::curve_line_ranged_base::set_defaults(&this->m_movie_start_frame.m_line);
  v2 = (vostok::particle::particle_action_billboard *)((char *)v2 + 24);
  p_m_movie_start_frame->m_evaluate_type = age_evaluate_type;
  vostok::math::curve_line_ranged_base::set_defaults((vostok::math::curve_line_ranged_base *)v2);
  v2->m_subimage_index.m_line.m_lower.curve_value_min = 0.0;
}
