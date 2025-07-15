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
        const vostok::animation::mixing::animation_lexeme_parameters *parameters@<edi>)
{
  vostok::animation::mixing::animation_interval *m_animation_intervals; // ecx
  unsigned int m_animation_intervals_count; // ebx
  vostok::animation::instant_interpolator_vtbl *v4; // ebx
  int v5; // eax
  float (__thiscall *v6)(vostok::animation::base_interpolator *, float); // edx
  vostok::animation::instant_interpolator_vtbl *v7; // ecx
  vostok::animation::mixing::animation_interval *v8; // eax
  vostok::animation::instant_interpolator_vtbl *p_m_start_time; // eax
  vostok::animation::instant_interpolator *v10; // eax
  const vostok::animation::base_interpolator *m_weight_interpolator; // ecx
  vostok::animation::instant_interpolator *v12; // eax
  const vostok::animation::base_interpolator *m_time_scale_interpolator; // ecx
  vostok::mutable_buffer *m_buffer; // [esp+4h] [ebp-14h]
  vostok::mutable_buffer *v15; // [esp+4h] [ebp-14h]
  vostok::animation::instant_interpolator v16; // [esp+Ch] [ebp-Ch] BYREF
  const vostok::animation::mixing::animation_interval *interpolated_value; // [esp+10h] [ebp-8h]
  vostok::animation::mixing::animation_interval *v18; // [esp+14h] [ebp-4h]

  v16.__vftable = 0;
  this->m_next_weight = 0;
  this->m_same_weight = 0;
  this->m_next_unique_interpolator = 0;
  this->m_reference_count = 0;
  this->__vftable = (vostok::animation::mixing::binary_tree_animation_node_vtbl *)&vostok::animation::mixing::binary_tree_animation_node::`vftable';
  this->m_time_calculator.m_Closure.m_pthis = 0;
  this->m_time_calculator.m_Closure.m_pFunction = 0;
  this->m_time_calculator = parameters->m_time_calculator;
  this->m_buffer = parameters->m_buffer;
  m_animation_intervals = parameters->m_animation_intervals;
  m_animation_intervals_count = parameters->m_animation_intervals_count;
  v16.__vftable = (vostok::animation::instant_interpolator_vtbl *)parameters->m_buffer;
  interpolated_value = (const vostok::animation::mixing::animation_interval *)v16.interpolated_value;
  v4 = (vostok::animation::instant_interpolator_vtbl *)&m_animation_intervals[m_animation_intervals_count];
  v18 = m_animation_intervals;
  v5 = ((char *)v4 - (char *)m_animation_intervals) / 20;
  v6 = (float (__thiscall *)(vostok::animation::base_interpolator *, float))&interpolated_value[v5];
  v7 = v16.__vftable;
  v16.clone = (vostok::animation::base_interpolator *(__thiscall *)(vostok::animation::base_interpolator *, vostok::memory::base_allocator *))((char *)v16.clone - v5 * 20);
  v8 = v18;
  v7->interpolated_value = v6;
  if ( v8 != (vostok::animation::mixing::animation_interval *)v4 )
  {
    p_m_start_time = (vostok::animation::instant_interpolator_vtbl *)&v8->m_start_time;
    v18 = interpolated_value;
    v16.__vftable = p_m_start_time;
    do
    {
      if ( v18 )
      {
        vostok::animation::mixing::animation_interval::animation_interval(
          (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&p_m_start_time[-1].visit,
          v18,
          (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&p_m_start_time[-1].visit,
          *(float *)&p_m_start_time->interpolated_value,
          *(float *)&p_m_start_time->clone);
        p_m_start_time = v16.__vftable;
      }
      ++v18;
      p_m_start_time = (vostok::animation::instant_interpolator_vtbl *)((char *)p_m_start_time + 20);
      v16.__vftable = p_m_start_time;
    }
    while ( &p_m_start_time[-1].visit != (void (__thiscall **)(vostok::animation::base_interpolator *, vostok::animation::interpolator_comparer *, const vostok::animation::linear_interpolator *))v4 );
  }
  this->m_animation_intervals = interpolated_value;
  v10 = 0;
  if ( !parameters->m_weight_driving_animation )
  {
    m_weight_interpolator = parameters->m_weight_interpolator;
    if ( m_weight_interpolator )
    {
      v10 = (vostok::animation::instant_interpolator *)m_weight_interpolator->clone(
                                                         m_weight_interpolator,
                                                         parameters->m_buffer);
    }
    else
    {
      m_buffer = parameters->m_buffer;
      v16.__vftable = (vostok::animation::instant_interpolator_vtbl *)&vostok::animation::instant_interpolator::`vftable';
      v10 = vostok::animation::instant_interpolator::clone(&v16, m_buffer);
    }
  }
  this->m_weight_interpolator = v10;
  v12 = 0;
  if ( !parameters->m_time_driving_animation )
  {
    m_time_scale_interpolator = parameters->m_time_scale_interpolator;
    if ( m_time_scale_interpolator )
    {
      v12 = (vostok::animation::instant_interpolator *)m_time_scale_interpolator->clone(
                                                         m_time_scale_interpolator,
                                                         parameters->m_buffer);
    }
    else
    {
      v15 = parameters->m_buffer;
      v16.__vftable = (vostok::animation::instant_interpolator_vtbl *)&vostok::animation::instant_interpolator::`vftable';
      v12 = vostok::animation::instant_interpolator::clone(&v16, v15);
    }
  }
  this->m_time_scale_interpolator = v12;
  this->m_animated_object = parameters->m_animated_object;
  this->m_time_driving_animation = parameters->m_time_driving_animation;
  this->m_weight_driving_animation = parameters->m_weight_driving_animation;
  this->m_n_ary_animation = 0;
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
