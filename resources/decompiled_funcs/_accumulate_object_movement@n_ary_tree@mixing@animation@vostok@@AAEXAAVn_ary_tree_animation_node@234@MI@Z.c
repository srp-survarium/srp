void __userpurge vostok::animation::mixing::n_ary_tree::accumulate_object_movement(
        vostok::animation::mixing::n_ary_tree_animation_node *animation_node@<ecx>,
        unsigned int time_in_ms@<eax>,
        float a3@<xmm4>,
        vostok::animation::mixing::n_ary_tree *this,
        const float animation_interval_time)
{
  void (__thiscall *accept)(struct vostok::animation::mixing::n_ary_tree_n_ary_operation_node *, vostok::animation::mixing::n_ary_tree_visitor *); // edx
  vostok::animation::mixing::animation_state *m_animation_state; // ebp
  vostok::animation::mixing::animation_interval *v8; // eax
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v9; // ecx
  const vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1> > *v10; // ecx
  vostok::math::quaternion *v11; // ecx
  float v12; // xmm2_4
  float v13; // xmm7_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float w; // xmm4_4
  float v21; // xmm5_4
  vostok::resources::managed_resource *y_low; // xmm3_4
  float z; // xmm3_4
  float v24; // xmm7_4
  float v25; // xmm3_4
  float v26; // xmm4_4
  float v27; // xmm5_4
  float v28; // xmm3_4
  float y; // xmm4_4
  float v30; // xmm3_4
  float v31; // xmm6_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  __int64 v34; // xmm0_8
  float v35; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v36; // [esp+8h] [ebp-BCh] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> object[3]; // [esp+1Ch] [ebp-A8h] BYREF
  float v38; // [esp+28h] [ebp-9Ch]
  float x; // [esp+2Ch] [ebp-98h]
  __int64 v40; // [esp+30h] [ebp-94h]
  __int64 v41; // [esp+38h] [ebp-8Ch]
  __int64 v42; // [esp+40h] [ebp-84h] BYREF
  __int64 v43; // [esp+48h] [ebp-7Ch]
  vostok::animation::frame f; // [esp+50h] [ebp-74h] BYREF
  vostok::animation::mixing::n_ary_tree_weight_calculator weight_calculator; // [esp+74h] [ebp-50h] BYREF
  vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> pinned_animation; // [esp+94h] [ebp-30h] BYREF
  vostok::animation::current_frame_position frame_position; // [esp+A0h] [ebp-24h] BYREF

  accept = animation_node->accept;
  m_animation_state = animation_node->m_animation_state;
  weight_calculator.m_current_time_in_ms = time_in_ms;
  weight_calculator.__vftable = (vostok::animation::mixing::n_ary_tree_weight_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_calculator::`vftable';
  weight_calculator.m_animation = animation_node;
  weight_calculator.m_result = 0;
  weight_calculator.m_recursion_level = 0;
  memset(&weight_calculator.m_weight, 0, 9);
  ((void (__stdcall *)(vostok::animation::mixing::n_ary_tree_weight_calculator *))accept)(&weight_calculator);
  m_animation_state->weight = weight_calculator.m_weight;
  LODWORD(m_animation_state->animation_interval_time) = this;
  vostok::animation::mixing::n_ary_tree::update_animation_time(m_animation_state);
  v8 = vostok::animation::mixing::animation_interval::animation(&animation_node->m_animation_intervals[m_animation_state->animation_interval_id]);
  object[0].m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    object,
    &v8->m_animation);
  v36.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v36,
    object);
  vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
    v9,
    &object[1],
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v36.m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(object);
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const>::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const>(
    &pinned_animation,
    (const vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > *)&object[1]);
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&object[1]);
  v36.m_object = (vostok::resources::managed_resource *)&frame_position;
  v10 = (const vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1> > *)&pinned_animation.m_data[*((_DWORD *)pinned_animation.m_data + 5)];
  memset(&frame_position, 0, sizeof(frame_position));
  vostok::animation::evaluate_frame(v10, &f, a3, m_animation_state->animation_time * 30.0, &frame_position);
  vostok::math::quaternion::quaternion(v11, (float *)&v42, *(vostok::math::float3 *)&f.channels[3]);
  v12 = f.translation.z - m_animation_state->bone_matrices_computer.previous_object_movement.translation.z;
  v13 = *(float *)&v42;
  v14 = m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.x
      + (float)(f.translation.x - m_animation_state->bone_matrices_computer.previous_object_movement.translation.x);
  m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.y = m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.y
                                                                                      + (float)(f.translation.y
                                                                                              - m_animation_state->bone_matrices_computer.previous_object_movement.translation.y);
  v15 = m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.z + v12;
  m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.x = v14;
  v16 = *((float *)&v43 + 1);
  m_animation_state->bone_matrices_computer.accumulated_object_movement.translation.z = v15;
  v40 = *(_QWORD *)&m_animation_state->bone_matrices_computer.previous_object_movement.rotation.x;
  v41 = *(_QWORD *)&m_animation_state->bone_matrices_computer.previous_object_movement.rotation.vector.elements[2];
  v17 = (float)((float)((float)(*((float *)&v41 + 1) * v16) - (float)(v13 * (float)-*(float *)&v40))
              - (float)(*((float *)&v42 + 1) * (float)-*((float *)&v40 + 1)))
      - (float)(*(float *)&v43 * COERCE_FLOAT(v41 ^ 0x80000000));
  LODWORD(v38) = v41 ^ 0x80000000;
  v18 = (float)((float)((float)(v13 * *((float *)&v41 + 1))
                      + (float)(*((float *)&v42 + 1) * COERCE_FLOAT(v41 ^ 0x80000000)))
              + (float)(v16 * (float)-*(float *)&v40))
      - (float)(*(float *)&v43 * (float)-*((float *)&v40 + 1));
  v19 = (float)((float)((float)(v16 * (float)-*((float *)&v40 + 1)) - (float)(v13 * COERCE_FLOAT(v41 ^ 0x80000000)))
              + (float)(*((float *)&v42 + 1) * *((float *)&v41 + 1)))
      + (float)(*(float *)&v43 * (float)-*(float *)&v40);
  w = m_animation_state->bone_matrices_computer.accumulated_object_movement.rotation.w;
  v21 = (float)((float)((float)(v16 * COERCE_FLOAT(v41 ^ 0x80000000))
                      + (float)(*(float *)&v42 * (float)-*((float *)&v40 + 1)))
              - (float)(*((float *)&v42 + 1) * (float)-*(float *)&v40))
      + (float)(*(float *)&v43 * *((float *)&v41 + 1));
  y_low = (vostok::resources::managed_resource *)LODWORD(m_animation_state->bone_matrices_computer.accumulated_object_movement.rotation.y);
  x = m_animation_state->bone_matrices_computer.accumulated_object_movement.rotation.x;
  object[0].m_object = y_low;
  z = m_animation_state->bone_matrices_computer.accumulated_object_movement.rotation.z;
  *((float *)&v41 + 1) = (float)((float)((float)(w * v17) - (float)(x * v18))
                               - (float)(*(float *)&object[0].m_object * v19))
                       - (float)(z * v21);
  *(float *)&v40 = (float)((float)((float)(z * v19) + (float)(x * v17)) + (float)(w * v18))
                 - (float)(*(float *)&object[0].m_object * v21);
  v24 = z;
  v25 = (float)((float)(z * v17) + (float)(*(float *)&object[0].m_object * v18)) - (float)(x * v19);
  *((float *)&v40 + 1) = (float)((float)((float)(*(float *)&object[0].m_object * v17) - (float)(v24 * v18))
                               + (float)(x * v21))
                       + (float)(w * v19);
  *(_QWORD *)&m_animation_state->bone_matrices_computer.accumulated_object_movement.rotation.x = v40;
  v26 = w * v21;
  v27 = f.scale.z;
  v28 = v25 + v26;
  y = f.scale.y;
  *(float *)&v41 = v28;
  v30 = f.scale.x;
  *(_QWORD *)&m_animation_state->bone_matrices_computer.accumulated_object_movement.rotation.vector.elements[2] = v41;
  v31 = m_animation_state->bone_matrices_computer.accumulated_object_movement.scale.x;
  v32 = v30 / m_animation_state->bone_matrices_computer.previous_object_movement.scale.x;
  v33 = (float)(v27 / m_animation_state->bone_matrices_computer.previous_object_movement.scale.z)
      * m_animation_state->bone_matrices_computer.accumulated_object_movement.scale.z;
  m_animation_state->bone_matrices_computer.accumulated_object_movement.scale.y = (float)(y
                                                                                        / m_animation_state->bone_matrices_computer.previous_object_movement.scale.y)
                                                                                * m_animation_state->bone_matrices_computer.accumulated_object_movement.scale.y;
  v34 = *(_QWORD *)&f.translation.x;
  v35 = f.translation.z;
  m_animation_state->bone_matrices_computer.accumulated_object_movement.scale.z = v33;
  m_animation_state->bone_matrices_computer.accumulated_object_movement.scale.x = v31 * v32;
  *(_QWORD *)&m_animation_state->bone_matrices_computer.previous_object_movement.translation.x = v34;
  *(_QWORD *)&m_animation_state->bone_matrices_computer.previous_object_movement.rotation.x = v42;
  *(_QWORD *)&m_animation_state->bone_matrices_computer.previous_object_movement.rotation.vector.elements[2] = v43;
  *(_QWORD *)&object[1].m_object = __PAIR64__(LODWORD(y), LODWORD(v30));
  v38 = v27;
  *(_QWORD *)&m_animation_state->bone_matrices_computer.previous_object_movement.scale.x = __PAIR64__(
                                                                                             LODWORD(y),
                                                                                             LODWORD(v30));
  m_animation_state->bone_matrices_computer.previous_object_movement.translation.z = v35;
  m_animation_state->bone_matrices_computer.previous_object_movement.scale.z = v27;
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&pinned_animation);
}
