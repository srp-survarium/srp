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


void __usercall vostok::animation::mixing::binary_tree_animation_node::binary_tree_animation_node(
        vostok::animation::mixing::binary_tree_animation_node *this@<esi>,
        vostok::animation::mixing::animation_lexeme_parameters *parameters@<edi>)
{
  unsigned int m_animation_intervals_count; // ebp
  const vostok::animation::mixing::animation_interval *v3; // eax
  vostok::animation::instant_interpolator *v4; // eax
  const vostok::animation::base_interpolator *m_weight_interpolator; // ecx
  vostok::animation::instant_interpolator *v6; // eax
  const vostok::animation::base_interpolator *m_time_scale_interpolator; // ecx
  vostok::animation::mixing::animation_lexeme *m_weight_driving_animation; // edx
  const vostok::animation::mixing::animation_interval *v9; // [esp-4h] [ebp-10h]
  vostok::mutable_buffer *m_buffer; // [esp-4h] [ebp-10h]
  vostok::mutable_buffer *v11; // [esp-4h] [ebp-10h]
  vostok::mutable_buffer *buffer; // [esp+8h] [ebp-4h] BYREF

  buffer = 0;
  this->m_next_weight = 0;
  this->m_same_weight = 0;
  this->m_next_unique_interpolator = 0;
  this->m_reference_count = 0;
  this->__vftable = (vostok::animation::mixing::binary_tree_animation_node_vtbl *)&vostok::animation::mixing::binary_tree_animation_node::`vftable';
  this->m_time_calculator.m_Closure.m_pthis = 0;
  this->m_time_calculator.m_Closure.m_pFunction = 0;
  this->m_time_calculator = parameters->m_time_calculator;
  this->m_buffer = parameters->m_buffer;
  m_animation_intervals_count = parameters->m_animation_intervals_count;
  buffer = parameters->m_buffer;
  v9 = &stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_Start(parameters)[m_animation_intervals_count];
  v3 = stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_Start(parameters);
  this->m_animation_intervals = vostok::animation::mixing::binary_tree_animation_node::clone(buffer, v3, v9);
  if ( parameters->m_weight_driving_animation )
  {
    v4 = 0;
  }
  else
  {
    m_weight_interpolator = parameters->m_weight_interpolator;
    m_buffer = parameters->m_buffer;
    if ( m_weight_interpolator )
    {
      v4 = (vostok::animation::instant_interpolator *)m_weight_interpolator->clone(m_weight_interpolator, m_buffer);
    }
    else
    {
      buffer = (vostok::mutable_buffer *)&vostok::animation::instant_interpolator::`vftable';
      v4 = vostok::animation::instant_interpolator::clone((vostok::animation::instant_interpolator *)&buffer, m_buffer);
    }
  }
  this->m_weight_interpolator = v4;
  if ( vostok::animation::mixing::animation_lexeme_parameters::time_driving_animation(parameters) )
  {
    v6 = 0;
  }
  else
  {
    m_time_scale_interpolator = parameters->m_time_scale_interpolator;
    v11 = parameters->m_buffer;
    if ( m_time_scale_interpolator )
    {
      v6 = (vostok::animation::instant_interpolator *)m_time_scale_interpolator->clone(m_time_scale_interpolator, v11);
    }
    else
    {
      buffer = (vostok::mutable_buffer *)&vostok::animation::instant_interpolator::`vftable';
      v6 = vostok::animation::instant_interpolator::clone((vostok::animation::instant_interpolator *)&buffer, v11);
    }
  }
  this->m_time_scale_interpolator = v6;
  this->m_animated_object = parameters->m_animated_object;
  this->m_time_driving_animation = vostok::animation::mixing::animation_lexeme_parameters::time_driving_animation(parameters);
  m_weight_driving_animation = parameters->m_weight_driving_animation;
  this->m_n_ary_animation = 0;
  this->m_weight_driving_animation = m_weight_driving_animation;
  this->m_next_weight_animation.m_object = 0;
  this->m_unique_weights_count = 0;
  this->user_data = parameters->m_user_data;
  this->m_animation_intervals_count = parameters->m_animation_intervals_count;
  this->m_start_animation_interval_id = parameters->m_start_animation_interval_id;
  this->m_start_animation_interval_time = parameters->m_start_animation_interval_time;
  this->m_start_cycle_animation_interval_id = parameters->m_start_cycle_animation_interval_id;
  this->m_time_scale = parameters->m_time_scale;
  this->m_playback_type = parameters->m_playback_type;
  this->m_time_synchronization_group_id = parameters->m_time_synchronization_group_id;
  this->m_weight_synchronization_group_id = parameters->m_weight_synchronization_group_id;
  this->m_additivity_priority = parameters->m_additivity_priority;
  this->m_bones_mask = parameters->m_bones_mask;
  this->m_unique_animation_id = parameters->m_unique_animation_id;
  this->m_override_existing_animation = parameters->m_override_existing_animation;
  this->m_is_positive_event_direction = parameters->m_is_positive_event_direction;
  this->m_can_generate_user_defined_events = parameters->m_can_generate_events;
  this->m_null_weight_found = 0;
}
