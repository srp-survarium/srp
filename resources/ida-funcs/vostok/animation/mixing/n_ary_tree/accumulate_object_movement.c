void __userpurge vostok::animation::mixing::n_ary_tree::accumulate_object_movement(
        vostok::animation::mixing::n_ary_tree_animation_node *animation_node@<eax>,
        vostok::animation::mixing::n_ary_tree *this,
        unsigned int animation_interval_time,
        const unsigned int time_in_ms)
{
  vostok::resources::pinned_ptr_const<unsigned char> *v6; // ebx
  vostok::resources::managed_resource *m_object; // ecx
  bool v8; // zf
  const vostok::animation::mixing::animation_interval *v9; // edi
  vostok::resources::pinned_ptr_mutable<unsigned char> *v10; // ecx
  const vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> *v11; // eax
  vostok::resources::pinned_ptr_const<unsigned char> *v12; // ecx
  float v13; // xmm2_4
  vostok::math::quaternion *v14; // ecx
  vostok::resources::pinned_ptr_const<unsigned char> *v15; // ecx
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  vostok::math::quaternion *p_m_data; // ebx
  vostok::math::quaternion *v20; // eax
  vostok::math::quaternion *v21; // eax
  vostok::math::quaternion *v22; // eax
  float x; // xmm3_4
  float *p_w; // esi
  vostok::resources::pinned_ptr_const<unsigned char> *v25; // ecx
  float *v26; // eax
  float y; // xmm4_4
  float z; // xmm5_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v31; // [esp-4h] [ebp-CCh] BYREF
  vostok::animation::current_frame_position frame_pos; // [esp+Ch] [ebp-BCh] BYREF
  vostok::math::quaternion v33; // [esp+30h] [ebp-98h] BYREF
  vostok::math::quaternion v34; // [esp+40h] [ebp-88h] BYREF
  vostok::animation::mixing::n_ary_tree_weight_calculator v35; // [esp+50h] [ebp-78h] BYREF
  vostok::math::quaternion v36; // [esp+74h] [ebp-54h] BYREF
  vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> v37; // [esp+84h] [ebp-44h] BYREF
  vostok::animation::frame f; // [esp+90h] [ebp-38h] BYREF
  vostok::math::quaternion v39; // [esp+B4h] [ebp-14h] BYREF
  vostok::resources::pinned_ptr_const<unsigned char> *m_animation_state; // [esp+C4h] [ebp-4h]

  m_animation_state = (vostok::resources::pinned_ptr_const<unsigned char> *)animation_node->m_animation_state;
  v6 = m_animation_state;
  vostok::animation::mixing::n_ary_tree_weight_calculator::n_ary_tree_weight_calculator(
    &v35,
    animation_node,
    animation_interval_time);
  animation_node->accept(animation_node, &v35);
  v8 = BYTE1(v6[9].m_size) == 0;
  v6[8].m_size = LODWORD(v35.m_weight);
  if ( v8 )
  {
    v31.m_object = (vostok::resources::managed_resource *)v6;
    v6[8].m_data = (const unsigned __int8 *)this;
    vostok::animation::mixing::n_ary_tree::update_animation_time((vostok::animation::mixing::animation_state *)v31.m_object);
    m_object = v31.m_object;
  }
  v9 = &animation_node->m_animation_intervals[v6[7].m_size];
  v31.m_object = m_object;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v31,
    &v9->m_first_view_animation);
  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
    v10,
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&v39.vector.elements[1],
    v31);
  vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>(
    &v37,
    v11);
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
    v12,
    (int)&v39.y);
  v13 = *(float *)&v6[9].m_resource.m_object * 30.0;
  memset(&frame_pos, 0, sizeof(frame_pos));
  vostok::animation::evaluate_frame(
    (const vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1> > *)&v37.m_data[*((_DWORD *)v37.m_data + 5)],
    channel_scale_x,
    v13,
    &f,
    &frame_pos);
  vostok::math::quaternion::quaternion(v14, &v36.x, *(vostok::math::float3 *)&f.channels[3]);
  v15 = m_animation_state;
  v16 = *(float *)&v6[4].m_size;
  v17 = (float)(f.translation.y - *(float *)&m_animation_state[1].m_size) + *(float *)&v6[5].m_resource.m_object;
  v18 = (float)(f.translation.z - *(float *)&m_animation_state[2].m_resource.m_object) + *(float *)&v6[5].m_data;
  p_m_data = (vostok::math::quaternion *)&v6[3].m_data;
  p_m_data[1].x = v16 + (float)(f.translation.x - *(float *)&m_animation_state[1].m_data);
  p_m_data[1].y = v17;
  p_m_data[1].z = v18;
  v20 = vostok::math::conjugate((const vostok::math::quaternion *)v15, &v39);
  v21 = vostok::math::operator*(v20, &v36, &v34);
  v22 = vostok::math::operator*(p_m_data, v21, &v33);
  x = f.scale.x;
  p_m_data->x = v22->x;
  p_m_data->y = v22->y;
  p_m_data->z = v22->z;
  p_w = &v22->w;
  v25 = m_animation_state;
  v26 = (float *)&m_animation_state[2].m_data;
  p_m_data->w = *p_w;
  y = f.scale.y;
  z = f.scale.z;
  v29 = f.scale.y / v26[1];
  v30 = f.scale.z / v26[2];
  p_m_data[1].w = (float)(x / *v26) * p_m_data[1].w;
  p_m_data[2].x = p_m_data[2].x * v29;
  p_m_data[2].y = p_m_data[2].y * v30;
  v39.w = f.translation.z;
  *(_QWORD *)&v25[1].m_data = *(_QWORD *)&f.translation.x;
  v25[2].m_resource.m_object = (vostok::resources::managed_resource *)LODWORD(v39.w);
  *(_QWORD *)&v25->m_resource.m_object = *(_QWORD *)&v36.x;
  *(_QWORD *)&v25->m_size = *(_QWORD *)&v36.vector.elements[2];
  *(_QWORD *)&v39.vector.elements[1] = __PAIR64__(LODWORD(y), LODWORD(x));
  v39.w = z;
  *v26 = x;
  *(_QWORD *)(v26 + 1) = *(_QWORD *)&v39.vector.elements[2];
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
    v25,
    (int)&v37);
}
