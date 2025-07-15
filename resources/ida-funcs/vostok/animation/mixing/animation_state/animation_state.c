void __userpurge vostok::animation::mixing::animation_state::animation_state(
        unsigned int animation_interval_id@<eax>,
        vostok::resources::pinned_ptr_mutable<unsigned char> *a2@<ecx>,
        vostok::animation::mixing::animation_state *this,
        vostok::animation::mixing::n_ary_tree_animation_node *animation_node,
        unsigned int time_in_ms,
        unsigned __int16 initial_event_types,
        unsigned int previous_animation_interval_id,
        float animation_interval_time,
        float animation_time_threshold,
        float weight,
        bool is_freezed,
        vostok::resources::managed_resource *disabled_channel_ids_at_start_time)
{
  const vostok::animation::mixing::animation_interval *v13; // edi
  vostok::resources::managed_resource *v14; // ecx
  vostok::resources::pinned_ptr_mutable<unsigned char> *v15; // ecx
  int v16; // eax
  _DWORD *v17; // eax
  vostok::resources::pinned_ptr_const<unsigned char> *v18; // ecx
  float animation_time; // xmm0_4
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v20; // [esp-4h] [ebp-1Ch] BYREF
  _BYTE v21[12]; // [esp+Ch] [ebp-Ch] BYREF
  float v22; // [esp+40h] [ebp+28h]

  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
    a2,
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&this->bone_matrices_computer.pinned_animation,
    0);
  v20.m_object = disabled_channel_ids_at_start_time;
  this->previous_animation_interval_id = previous_animation_interval_id;
  this->animation_interval_id = animation_interval_id;
  this->animation_interval_time = animation_interval_time;
  this->weight = weight;
  this->animation_time = animation_node->m_animation_intervals[animation_interval_id].m_start_time
                       + animation_interval_time;
  this->animation_time_threshold = animation_time_threshold;
  this->are_there_any_weight_transitions = 0;
  this->is_freezed = is_freezed;
  vostok::animation::mixing::n_ary_tree_event_iterator::n_ary_tree_event_iterator(
    &this->event_iterator,
    this,
    animation_node,
    time_in_ms,
    initial_event_types,
    (const unsigned __int8)v20.m_object);
  v13 = &animation_node->m_animation_intervals[animation_interval_id];
  v20.m_object = v14;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v20,
    &v13->m_first_view_animation);
  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
    v15,
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v21,
    v20);
  v17 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(v16 + 4) + 20) + *(_DWORD *)(v16 + 4));
  v18 = (vostok::resources::pinned_ptr_const<unsigned char> *)(v17[1] + 20 * *v17);
  v22 = (float)(*(float *)((char *)v17 + (_DWORD)v18 - 4) - *(float *)((char *)&v17[4 * *v17] + v17[1])) * 0.033333335;
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
    v18,
    (int)v21);
  if ( animation_node->m_playback_type == play_cyclically )
  {
    animation_time = this->animation_time;
    if ( animation_time >= v22 )
    {
      this->animation_time = animation_time - v22;
      this->animation_time_threshold = v22;
    }
  }
}
