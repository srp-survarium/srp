void __userpurge vostok::animation::mixing::n_ary_tree_animation_time_calculator::fill_time(
        vostok::animation::mixing::n_ary_tree_animation_time_calculator *this@<esi>,
        unsigned int time_scale_start_time_in_ms@<ecx>,
        float time_scale,
        float animation_time_before_scale_starts)
{
  float v4; // xmm0_4
  float m_animation_interval_length; // xmm1_4
  float time_scalea; // [esp+14h] [ebp+4h]

  time_scalea = vostok::animation::mixing::n_ary_tree_animation_time_calculator::computed_animation_time(
                  this,
                  this->m_target_time_in_ms,
                  animation_time_before_scale_starts,
                  time_scale_start_time_in_ms,
                  this->m_start_time_in_ms,
                  time_scale);
  v4 = time_scalea;
  this->m_animation_time = time_scalea;
  if ( time_scalea <= 0.0 )
    v4 = 0.0;
  m_animation_interval_length = this->m_animation_interval_length;
  if ( m_animation_interval_length <= v4 )
    this->m_animation_time = m_animation_interval_length;
  else
    this->m_animation_time = v4;
}
