void __userpurge vostok::animation::mixing::n_ary_tree_animation_time_calculator::fill_time(
        vostok::animation::mixing::n_ary_tree_animation_time_calculator *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_animation_time_calculator *a2@<esi>,
        float time_scale,
        float animation_time_before_scale_starts,
        unsigned int time_scale_start_time_in_ms)
{
  float m_animation_interval_length; // xmm0_4
  float v6; // [esp+18h] [ebp+8h]

  v6 = vostok::animation::mixing::n_ary_tree_animation_time_calculator::computed_animation_time(
         a2,
         a2->m_target_time_in_ms,
         animation_time_before_scale_starts,
         time_scale_start_time_in_ms,
         a2->m_start_time_in_ms,
         time_scale);
  m_animation_interval_length = 0.0;
  a2->m_animation_time = v6;
  if ( v6 > 0.0 )
    m_animation_interval_length = v6;
  if ( a2->m_animation_interval_length <= m_animation_interval_length )
    m_animation_interval_length = a2->m_animation_interval_length;
  a2->m_animation_time = m_animation_interval_length;
}
