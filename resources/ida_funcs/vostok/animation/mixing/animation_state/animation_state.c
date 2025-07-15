void __userpurge vostok::animation::mixing::animation_state::animation_state(
        vostok::animation::mixing::animation_state *this@<ecx>,
        vostok::animation::mixing::animation_state *a2@<edi>,
        vostok::animation::mixing::n_ary_tree_animation_node *animation_node,
        unsigned int time_in_ms,
        unsigned __int16 initial_event_types,
        unsigned int animation_interval_id,
        unsigned int previous_animation_interval_id,
        float animation_interval_time,
        float animation_time_threshold,
        float weight,
        vostok::animation::subscribed_channel **channels_head,
        float is_freezed)
{
  unsigned int v12; // ebx
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v13; // ecx
  unsigned int v14; // ecx
  float v15; // xmm0_4
  double started; // st7
  char v17; // dl
  float v18; // xmm0_4
  vostok::animation::subscribed_channel **v19; // edx
  vostok::animation::mixing::animation_interval *v20; // eax
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v21; // ecx
  int v22; // ecx
  float animation_time; // xmm0_4
  float v24; // xmm1_4
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v25[5]; // [esp-4h] [ebp-20h] BYREF
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> v26; // [esp+10h] [ebp-Ch] BYREF

  v12 = animation_interval_id;
  animation_interval_id = 0;
  v25[0].m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    v25,
    (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&animation_interval_id);
  vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
    v13,
    &a2->bone_matrices_computer.pinned_animation.m_resource,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v25[0].m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&animation_interval_id);
  v14 = previous_animation_interval_id;
  a2->animation_interval_time = animation_interval_time;
  v15 = weight;
  a2->previous_animation_interval_id = v14;
  a2->animation_interval_id = v12;
  a2->weight = v15;
  started = vostok::animation::mixing::animation_interval::start_time(&animation_node->m_animation_intervals[v12]);
  v17 = LOBYTE(is_freezed);
  a2->animation_time = started + animation_interval_time;
  v18 = animation_time_threshold;
  LOWORD(v25[0].m_object) = initial_event_types;
  a2->is_freezed = v17;
  v19 = channels_head;
  a2->animation_time_threshold = v18;
  a2->are_there_any_weight_transitions = 0;
  vostok::animation::mixing::n_ary_tree_event_iterator::n_ary_tree_event_iterator(
    a2,
    v19,
    &a2->event_iterator,
    animation_node,
    time_in_ms,
    (unsigned __int16)v25[0].m_object);
  v20 = vostok::animation::mixing::animation_interval::animation(&animation_node->m_animation_intervals[v12]);
  is_freezed = 0.0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&is_freezed,
    &v20->m_animation);
  v25[0].m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    v25,
    (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&is_freezed);
  vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
    v21,
    &v26.m_resource,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v25[0].m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&is_freezed);
  v22 = *((_DWORD *)v26.m_data + 5);
  is_freezed = (float)(*(float *)&v26.m_data[20 * *(_DWORD *)&v26.m_data[v22]
                                           - 4
                                           + v22
                                           + *(_DWORD *)&v26.m_data[v22 + 4]]
                     - *(float *)&v26.m_data[16 * *(_DWORD *)&v26.m_data[v22] + v22 + *(_DWORD *)&v26.m_data[v22 + 4]])
             * 0.033333335;
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>(&v26);
  if ( animation_node->m_playback_type == play_cyclically )
  {
    animation_time = a2->animation_time;
    v24 = is_freezed;
    if ( animation_time >= is_freezed )
    {
      a2->animation_time = animation_time - is_freezed;
      a2->animation_time_threshold = v24;
    }
  }
}
