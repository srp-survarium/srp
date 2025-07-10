void __thiscall vostok::particle::particle_action_billboard::set_defaults(
        vostok::particle::particle_action_billboard *this,
        bool mt_alloc)
{
  vostok::particle::particle_action::set_defaults(this, mt_alloc);
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
  this->m_movie_frame_rate = default_fps_3;
  this->m_movie_start_frame = *(float *)&FLOAT_0_0;
  vostok::particle::curve_line_points<float,0>::set_defaults(&this->m_subimage_index.m_line.m_upper);
  vostok::particle::curve_line_points<float,0>::set_defaults(&this->m_subimage_index.m_line.m_lower);
}
