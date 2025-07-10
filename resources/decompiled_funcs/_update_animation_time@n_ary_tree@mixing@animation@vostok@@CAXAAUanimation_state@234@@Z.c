void __usercall vostok::animation::mixing::n_ary_tree::update_animation_time(
        vostok::animation::mixing::animation_state *animation_state@<edi>)
{
  vostok::animation::mixing::animation_interval *v1; // esi
  vostok::animation::mixing::animation_interval *v2; // eax
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v3; // ecx
  const unsigned __int8 *v4; // eax
  float v5; // xmm0_4
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v6; // [esp-4h] [ebp-20h] BYREF
  float animation_length; // [esp+8h] [ebp-14h] BYREF
  float animation_time; // [esp+Ch] [ebp-10h]
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> v9; // [esp+10h] [ebp-Ch] BYREF

  if ( !animation_state->is_freezed )
  {
    v1 = &animation_state->event_iterator.m_animation_node->m_animation_intervals[animation_state->animation_interval_id];
    animation_time = vostok::animation::mixing::animation_interval::start_time(v1)
                   + animation_state->animation_interval_time;
    v2 = vostok::animation::mixing::animation_interval::animation(v1);
    animation_length = 0.0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&animation_length,
      &v2->m_animation);
    v6.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &v6,
      (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&animation_length);
    vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
      v3,
      &v9.m_resource,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v6.m_object);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&animation_length);
    v4 = &v9.m_data[*((_DWORD *)v9.m_data + 5)];
    animation_length = (float)(*(float *)&v4[20 * *(_DWORD *)v4 - 4 + *((_DWORD *)v4 + 1)]
                             - *(float *)&v4[16 * *(_DWORD *)v4 + *((_DWORD *)v4 + 1)])
                     * 0.033333335;
    vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>(&v9);
    v5 = animation_time - animation_state->animation_time_threshold;
    if ( v5 <= 0.0 )
      v5 = 0.0;
    if ( animation_length <= v5 )
      v5 = animation_length;
    animation_state->animation_time = v5;
  }
}
