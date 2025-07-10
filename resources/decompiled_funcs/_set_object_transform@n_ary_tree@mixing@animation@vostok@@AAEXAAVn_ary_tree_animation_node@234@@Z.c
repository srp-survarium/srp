void __usercall vostok::animation::mixing::n_ary_tree::set_object_transform(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        float a2@<xmm4>)
{
  unsigned int m_animations_count; // ebp
  vostok::animation::mixing::animation_interval *v3; // ecx
  vostok::animation::mixing::animation_interval *v4; // eax
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v5; // ecx
  vostok::math::quaternion *v6; // ecx
  bool v7; // zf
  vostok::math::quaternion *v8; // ecx
  float v9; // xmm0_4
  _QWORD *v10; // eax
  float v11; // edx
  _QWORD *v12; // eax
  const vostok::math::float4x4 *v13; // edx
  unsigned int m_size; // eax
  float x; // xmm0_4
  _QWORD *v16; // eax
  float z; // ecx
  vostok::math::float3 v18; // [esp-4h] [ebp-88h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> object; // [esp+18h] [ebp-6Ch] BYREF
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > other; // [esp+1Ch] [ebp-68h] BYREF
  vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> pinned_animation; // [esp+28h] [ebp-5Ch] BYREF
  vostok::animation::frame f; // [esp+38h] [ebp-4Ch] BYREF
  vostok::animation::current_frame_position frame_position; // [esp+5Ch] [ebp-28h] BYREF

  m_animations_count = this->m_animations_count;
  v3 = (vostok::animation::mixing::animation_interval *)((char *)this->m_animation_states
                                                       + 12 * *(_DWORD *)(m_animations_count + 92));
  memset(&frame_position, 0, sizeof(frame_position));
  v4 = vostok::animation::mixing::animation_interval::animation(v3);
  object.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &object,
    &v4->m_animation);
  v18.z = 0.0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v18.elements[2],
    &object);
  vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
    v5,
    &other.m_resource,
    LODWORD(v18.elements[2]));
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&object);
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const>::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const>(
    &pinned_animation,
    &other);
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&other);
  vostok::animation::evaluate_frame(
    (const vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1> > *)&pinned_animation.m_data[*((_DWORD *)pinned_animation.m_data + 5)],
    &f,
    a2,
    *(float *)(m_animations_count + 108) * 30.0,
    &frame_position);
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&pinned_animation);
  *(_QWORD *)&other.m_resource.m_object = *(_QWORD *)&f.translation.x;
  v7 = *(_BYTE *)(m_animations_count + 116) == 0;
  other.m_size = LODWORD(f.translation.z);
  if ( v7 )
  {
    m_size = other.m_size;
    *(_QWORD *)(m_animations_count + 56) = *(_QWORD *)&f.translation.x;
    x = f.rotation.x;
    *(_DWORD *)(m_animations_count + 64) = m_size;
    *(_QWORD *)&v18.x = __PAIR64__(LODWORD(f.rotation.y), LODWORD(x));
    v18.z = f.rotation.z;
    vostok::math::quaternion::quaternion(v6, (float *)&pinned_animation, v18);
    *(_QWORD *)(m_animations_count + 40) = *v16;
    *(_QWORD *)(m_animations_count + 48) = v16[1];
    z = f.scale.z;
    *(_QWORD *)(m_animations_count + 68) = *(_QWORD *)&f.channels[6];
    *(float *)(m_animations_count + 76) = z;
  }
  else
  {
    v8 = (vostok::math::quaternion *)other.m_size;
    *(_QWORD *)(m_animations_count + 16) = *(_QWORD *)&f.translation.x;
    v9 = f.rotation.x;
    *(_DWORD *)(m_animations_count + 24) = v8;
    *(_QWORD *)&v18.x = __PAIR64__(LODWORD(f.rotation.y), LODWORD(v9));
    v18.z = f.rotation.z;
    vostok::math::quaternion::quaternion(v8, (float *)&pinned_animation, v18);
    *(_QWORD *)m_animations_count = *v10;
    *(_QWORD *)(m_animations_count + 8) = v10[1];
    v11 = f.scale.z;
    *(_QWORD *)(m_animations_count + 28) = *(_QWORD *)&f.channels[6];
    *(_QWORD *)(m_animations_count + 56) = 0;
    *(_DWORD *)(m_animations_count + 64) = 0;
    memset(&other, 0, sizeof(other));
    *(_QWORD *)&v18.x = 0;
    *(float *)(m_animations_count + 36) = v11;
    v18.z = 0.0;
    vostok::math::quaternion::quaternion(0, (float *)&pinned_animation, v18);
    *(_QWORD *)(m_animations_count + 40) = *v12;
    *(_QWORD *)(m_animations_count + 48) = v12[1];
    other.m_size = (unsigned int)clear_value;
    v13 = clear_value;
    other.m_resource.m_object = (vostok::resources::managed_resource *)clear_value;
    other.m_data = (const unsigned __int8 *)clear_value;
    *(_QWORD *)(m_animations_count + 68) = *(_QWORD *)&other.m_resource.m_object;
    *(_DWORD *)(m_animations_count + 76) = v13;
  }
}
