void __usercall vostok::animation::mixing::n_ary_tree::set_object_transform(
        vostok::animation::mixing::n_ary_tree_animation_node *animation_node@<eax>)
{
  vostok::animation::mixing::animation_state *m_animation_state; // ebx
  const vostok::animation::mixing::animation_interval *v3; // edx
  vostok::resources::pinned_ptr_mutable<unsigned char> *v4; // ecx
  const vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> *v5; // eax
  vostok::resources::pinned_ptr_const<unsigned char> *v6; // ecx
  bool v7; // zf
  unsigned int v8; // xmm1_4
  unsigned int v9; // xmm0_4
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v10; // [esp-4h] [ebp-74h] BYREF
  vostok::animation::current_frame_position frame_pos; // [esp+Ch] [ebp-64h] BYREF
  vostok::animation::frame f; // [esp+30h] [ebp-40h] BYREF
  float v13; // [esp+54h] [ebp-1Ch]
  float v14; // [esp+58h] [ebp-18h] BYREF
  float v15; // [esp+5Ch] [ebp-14h]
  float v16; // [esp+60h] [ebp-10h]
  vostok::math::float3 translation; // [esp+64h] [ebp-Ch] BYREF

  m_animation_state = animation_node->m_animation_state;
  v3 = &animation_node->m_animation_intervals[m_animation_state->animation_interval_id];
  memset(&frame_pos, 0, sizeof(frame_pos));
  v10.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v10,
    &v3->m_first_view_animation);
  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
    v4,
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&v14,
    v10);
  vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>(
    (vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> *)&translation,
    v5);
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
    v6,
    (int)&v14);
  vostok::animation::evaluate_frame(
    (const vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1> > *)(LODWORD(translation.y)
                                                                                                 + *(_DWORD *)(LODWORD(translation.y) + 20)),
    channel_scale_x,
    m_animation_state->animation_time * 30.0,
    &f,
    &frame_pos);
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
    (vostok::resources::pinned_ptr_const<unsigned char> *)v10.m_object,
    (int)&translation);
  v7 = !m_animation_state->are_there_any_weight_transitions;
  translation = (vostok::math::float3)f.translation;
  v13 = 0.0;
  v14 = 0.0;
  v15 = 0.0;
  if ( v7 )
  {
    v9 = LODWORD(s_bm_current_air_resistance);
    m_animation_state->bone_matrices_computer.accumulated_object_movement.translation = translation;
    v16 = *(float *)&v9;
    LODWORD(translation.x) = v9;
    LODWORD(translation.y) = v9;
    LODWORD(translation.z) = v9;
  }
  else
  {
    v8 = LODWORD(s_bm_current_air_resistance);
    m_animation_state->bone_matrices_computer.previous_object_movement.translation = translation;
    v16 = *(float *)&v8;
    m_animation_state->bone_matrices_computer.previous_object_movement.rotation.x = v13;
    m_animation_state->bone_matrices_computer.previous_object_movement.rotation.y = v14;
    m_animation_state->bone_matrices_computer.previous_object_movement.rotation.z = v15;
    m_animation_state->bone_matrices_computer.previous_object_movement.rotation.w = v16;
    LODWORD(translation.y) = v8;
    LODWORD(translation.z) = v8;
    LODWORD(m_animation_state->bone_matrices_computer.previous_object_movement.scale.x) = v8;
    m_animation_state->bone_matrices_computer.previous_object_movement.scale.y = translation.y;
    m_animation_state->bone_matrices_computer.previous_object_movement.scale.z = translation.z;
    translation.y = 0.0;
    translation.z = 0.0;
    m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.x = 0.0;
    m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.y = translation.y;
    m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.z = translation.z;
    v13 = 0.0;
    v14 = 0.0;
    v15 = 0.0;
    v16 = *(float *)&v8;
    LODWORD(translation.x) = v8;
    LODWORD(translation.y) = v8;
    LODWORD(translation.z) = v8;
  }
  m_animation_state->bone_matrices_computer.accumulated_object_movement.rotation.x = v13;
  m_animation_state->bone_matrices_computer.accumulated_object_movement.rotation.y = v14;
  m_animation_state->bone_matrices_computer.accumulated_object_movement.rotation.z = v15;
  m_animation_state->bone_matrices_computer.accumulated_object_movement.rotation.w = v16;
  m_animation_state->bone_matrices_computer.accumulated_object_movement.scale = translation;
}


void __userpurge vostok::animation::mixing::n_ary_tree::set_object_transform(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        int a2@<eax>,
        const void *animated_object,
        const vostok::math::float4x4 *object_transform)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v6; // edi
  vostok::animation::mixing::animated_object_holder *v7; // eax

  v6 = *(vostok::animation::mixing::n_ary_tree_animation_node **)(a2 + 4);
  if ( v6 )
  {
    do
    {
      if ( v6->m_animated_object == animated_object )
        vostok::animation::mixing::n_ary_tree::set_object_transform(v6);
      v6 = v6->m_next_weight_animation;
    }
    while ( v6 );
    v7 = stlp_std::priv::__find<vostok::animation::mixing::animated_object_holder *,void const *>(
           *(vostok::animation::mixing::animated_object_holder **)(a2 + 24),
           &animated_object,
           (vostok::animation::mixing::animated_object_holder *)(*(_DWORD *)(a2 + 24) + 136 * *(_DWORD *)(a2 + 36)));
    qmemcpy(v7, object_transform, 0x40u);
  }
}
