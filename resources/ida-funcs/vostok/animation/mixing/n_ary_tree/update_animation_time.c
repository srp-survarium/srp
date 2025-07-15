void __cdecl vostok::animation::mixing::n_ary_tree::update_animation_time(
        vostok::animation::mixing::animation_state *animation_state)
{
  vostok::resources::managed_resource *v1; // ecx
  float animation_interval_time; // xmm0_4
  const vostok::animation::mixing::animation_interval *v4; // edi
  vostok::resources::pinned_ptr_mutable<unsigned char> *v5; // ecx
  int v6; // eax
  _DWORD *v7; // eax
  vostok::resources::pinned_ptr_const<unsigned char> *v8; // ecx
  float v9; // xmm0_4
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v10; // [esp-Ch] [ebp-20h] BYREF
  _BYTE v11[12]; // [esp+4h] [ebp-10h] BYREF
  float v12; // [esp+10h] [ebp-4h]
  float v13; // [esp+1Ch] [ebp+8h]

  animation_interval_time = animation_state->animation_interval_time;
  v4 = &animation_state->event_iterator.m_animation_node->m_animation_intervals[animation_state->animation_interval_id];
  v10.m_object = v1;
  v13 = animation_interval_time + v4->m_start_time;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v10,
    &v4->m_first_view_animation);
  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
    v5,
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v11,
    v10);
  v7 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(v6 + 4) + 20) + *(_DWORD *)(v6 + 4));
  v8 = (vostok::resources::pinned_ptr_const<unsigned char> *)(v7[1] + 20 * *v7);
  v12 = (float)(*(float *)((char *)v7 + (_DWORD)v8 - 4) - *(float *)((char *)&v7[4 * *v7] + v7[1])) * 0.033333335;
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
    v8,
    (int)v11);
  v9 = v13 - animation_state->animation_time_threshold;
  if ( v9 <= 0.0 )
    v9 = 0.0;
  if ( v12 <= v9 )
    v9 = v12;
  animation_state->animation_time = v9;
}
