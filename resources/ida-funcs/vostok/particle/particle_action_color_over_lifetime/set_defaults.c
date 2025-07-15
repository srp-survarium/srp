void __thiscall vostok::particle::particle_action_color_over_lifetime::set_defaults(
        vostok::particle::particle_action_color_over_lifetime *this,
        bool mt_alloc)
{
  this->m_next.pointer = 0;
  this->m_visibility = 1;
  this->m_color_over_life.m_points.pointer = 0;
  this->m_color_over_life.m_num_rows = 0;
  this->m_color_over_life.m_num_columns = 0;
  this->m_color_over_life.m_evaluate_type = age_evaluate_type;
}
