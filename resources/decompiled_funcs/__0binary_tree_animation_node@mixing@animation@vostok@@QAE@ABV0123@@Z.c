void __usercall vostok::animation::mixing::binary_tree_animation_node::binary_tree_animation_node(
        vostok::animation::mixing::binary_tree_animation_node *this@<ecx>,
        int a2@<eax>)
{
  vostok::animation::mixing::binary_tree_animation_node *m_object; // edx

  *(_DWORD *)a2 = &vostok::animation::mixing::binary_tree_animation_node::`vftable';
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *)(a2 + 20) = this->m_time_calculator;
  *(_DWORD *)(a2 + 28) = this->m_buffer;
  *(_DWORD *)(a2 + 32) = this->m_animation_intervals;
  *(_DWORD *)(a2 + 36) = this->m_weight_interpolator;
  *(_DWORD *)(a2 + 40) = this->m_time_scale_interpolator;
  *(_DWORD *)(a2 + 44) = this->m_animated_object;
  *(_DWORD *)(a2 + 48) = this->m_time_driving_animation;
  *(_DWORD *)(a2 + 52) = this->m_weight_driving_animation;
  *(_DWORD *)(a2 + 56) = this->m_n_ary_animation;
  *(_DWORD *)(a2 + 60) = 0;
  m_object = this->m_next_weight_animation.m_object;
  if ( m_object )
  {
    *(_DWORD *)(a2 + 60) = m_object;
    ++m_object->m_reference_count;
  }
  *(_DWORD *)(a2 + 64) = this->m_unique_weights_count;
  *(_DWORD *)(a2 + 68) = this->user_data;
  *(_DWORD *)(a2 + 72) = this->m_animation_intervals_count;
  *(_DWORD *)(a2 + 76) = this->m_start_animation_interval_id;
  *(float *)(a2 + 80) = this->m_start_animation_interval_time;
  *(_DWORD *)(a2 + 84) = this->m_start_cycle_animation_interval_id;
  *(float *)(a2 + 88) = this->m_time_scale;
  *(_DWORD *)(a2 + 92) = this->m_playback_type;
  *(_DWORD *)(a2 + 96) = this->m_time_synchronization_group_id;
  *(_DWORD *)(a2 + 100) = this->m_weight_synchronization_group_id;
  *(_DWORD *)(a2 + 104) = this->m_additivity_priority;
  *(_DWORD *)(a2 + 108) = this->m_bones_mask;
  *(_BYTE *)(a2 + 112) = this->m_unique_animation_id;
  *(_BYTE *)(a2 + 113) = this->m_override_existing_animation;
  *(_BYTE *)(a2 + 114) = this->m_is_positive_event_direction;
  *(_BYTE *)(a2 + 115) = this->m_can_generate_user_defined_events;
  *(_BYTE *)(a2 + 116) = this->m_null_weight_found;
}
