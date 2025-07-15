void __userpurge vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
        vostok::animation::mixing::animation_lexeme_parameters *this@<esi>,
        vostok::mutable_buffer *buffer@<eax>,
        const vostok::animation::mixing::animation_interval *identifier,
        const vostok::animation::mixing::animation_interval *animation_intervals_begin,
        const vostok::animation::mixing::animation_interval *animation_intervals_end,
        vostok::animation::mixing::animation_lexeme *const time_driving_animation,
        vostok::animation::mixing::animation_lexeme *const weight_driving_animation)
{
  unsigned int v7; // eax
  float v9; // xmm0_4
  vostok::mutable_buffer *m_buffer; // ecx
  char *m_data; // edx
  float *p_m_start_time; // edi
  vostok::animation::mixing::animation_interval *v13; // [esp+18h] [ebp+8h]

  this->m_buffer = buffer;
  this->m_time_calculator.m_Closure.m_pthis = 0;
  this->m_time_calculator.m_Closure.m_pFunction = 0;
  this->m_time_driving_animation = 0;
  this->m_weight_driving_animation = 0;
  this->m_animation_intervals = (const vostok::animation::mixing::animation_interval *const)buffer->m_data;
  v7 = animation_intervals_begin - identifier;
  this->m_user_data = -1;
  this->m_start_animation_interval_time = 0.0;
  v9 = s_bm_current_air_resistance;
  this->m_time_synchronization_group_id = -1;
  this->m_weight_synchronization_group_id = -1;
  this->m_bones_mask = -1;
  m_buffer = this->m_buffer;
  this->m_weight_interpolator = 0;
  this->m_time_scale_interpolator = 0;
  this->m_animated_object = 0;
  this->m_start_cycle_animation_interval_id = 0;
  this->m_start_animation_interval_id = 0;
  this->m_time_scale = v9;
  this->m_playback_type = play_cyclically;
  this->m_additivity_priority = 0;
  this->m_unique_animation_id = -1;
  this->m_override_existing_animation = 0;
  this->m_is_positive_event_direction = 1;
  this->m_can_generate_events = 1;
  this->m_animation_intervals_count = v7;
  v7 *= 20;
  m_data = m_buffer->m_data;
  m_buffer->m_data += v7;
  m_buffer->m_size -= v7;
  if ( identifier != animation_intervals_begin )
  {
    v13 = (vostok::animation::mixing::animation_interval *)m_data;
    p_m_start_time = &identifier->m_start_time;
    do
    {
      if ( v13 )
        vostok::animation::mixing::animation_interval::animation_interval(
          (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)p_m_start_time
        - 3,
          v13,
          (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)p_m_start_time
        - 2,
          *p_m_start_time,
          p_m_start_time[1]);
      ++v13;
      p_m_start_time += 5;
    }
    while ( p_m_start_time - 3 != (float *)animation_intervals_begin );
  }
}
