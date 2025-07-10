survarium::animation_space_vertex_id *__cdecl survarium::animation_space_graph::get_movement(
        survarium::animation_space_vertex_id *result,
        vostok::animation::animation_player *player,
        const survarium::animation_space_vertex *left_animation,
        const survarium::animation_space_vertex *right_animation,
        float left_weight)
{
  vostok::animation::animation_player *v5; // ecx
  void *v6; // esp
  vostok::animation::mixing::animation_lexeme_parameters *v7; // ecx
  const vostok::animation::mixing::animation_interval *v8; // esi
  const vostok::animation::mixing::animation_interval *i; // edi
  vostok::animation::mixing::animation_lexeme_parameters *v10; // eax
  vostok::mutable_buffer **v11; // edi
  vostok::animation::mixing::animation_lexeme *v12; // ecx
  vostok::animation::mixing::weight_lexeme *v13; // ecx
  const vostok::animation::mixing::animation_interval *m_animation_intervals; // esi
  const vostok::animation::mixing::animation_interval *v15; // edi
  vostok::animation::mixing::weight_lexeme *v16; // eax
  vostok::animation::mixing::multiplication_lexeme *v17; // eax
  vostok::animation::mixing::expression *v18; // eax
  const vostok::math::float4x4 *v19; // eax
  vostok::animation::mixing::binary_tree_base_node *m_object; // ecx
  vostok::animation::subscribed_channel **v22; // eax
  vostok::animation::animation_player *v23; // ecx
  vostok::animation::mixing::n_ary_tree *v24; // ecx
  vostok::math::float4x4 *v25; // ecx
  vostok::math::float3 *angles_xyz; // eax
  __int64 v27; // xmm0_8
  float z; // eax
  __int64 *v29; // eax
  __int64 v30; // xmm0_8
  __int64 v31; // xmm1_8
  __int64 v32; // xmm2_8
  float v33; // eax
  vostok::animation::mixing::animation_lexeme *v34; // ecx
  vostok::animation::mixing::animation_lexeme *v35; // ecx
  vostok::math::quaternion v37[1025]; // [esp-4h] [ebp-41D8h] BYREF
  vostok::animation::mixing::animation_lexeme v38; // [esp+4018h] [ebp-1BCh] BYREF
  float v39[4]; // [esp+40A0h] [ebp-134h] BYREF
  vostok::animation::mixing::animation_lexeme v40; // [esp+40B0h] [ebp-124h] BYREF
  vostok::animation::mixing::weight_lexeme right; // [esp+4138h] [ebp-9Ch] BYREF
  vostok::animation::mixing::animation_lexeme_parameters v42; // [esp+4160h] [ebp-74h] BYREF
  float v43; // [esp+41BCh] [ebp-18h] BYREF
  vostok::animation::mixing::expression expression; // [esp+41C0h] [ebp-14h] BYREF
  vostok::mutable_buffer buffer; // [esp+41C8h] [ebp-Ch] BYREF

  vostok::animation::animation_player::reset(v5, player, 0);
  v6 = alloca(0x4000);
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    &buffer,
    (unsigned __int8 *)&v37[0].vector.elements[3],
    0x4000u);
  v42.m_buffer = &buffer;
  memset((void *)&v42.m_time_calculator, 0, 16);
  *(_QWORD *)&v42.m_animation_intervals = (unsigned int)buffer.m_data;
  *(_QWORD *)&v42.m_time_scale_interpolator = 0;
  *(_QWORD *)&v42.m_animation_intervals_count = vostok::animation::mixing::animation_lexeme_parameters::animation_intervals_count(&left_animation->animation);
  *(_QWORD *)&v42.m_time_synchronization_group_id = -1;
  LODWORD(v37[0].z) = left_animation;
  *(_QWORD *)&v42.m_start_animation_interval_id = 0;
  *(_QWORD *)&v42.m_time_scale = (unsigned int)clear_value;
  *(_QWORD *)&v42.m_additivity_priority = 0xFFFFFFFF00000000uLL;
  *(_DWORD *)&v42.m_unique_animation_id = 16843007;
  vostok::animation::mixing::animation_lexeme_parameters::create_animation_intervals(
    v7,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v42);
  *(_QWORD *)&v42.m_time_synchronization_group_id = 0;
  vostok::animation::mixing::binary_tree_animation_node::binary_tree_animation_node(&v40, &v42);
  v40.vostok::animation::mixing::base_lexeme::m_buffer = v42.m_buffer;
  v40.m_cloned = 0;
  v40.__vftable = (vostok::animation::mixing::animation_lexeme_vtbl *)&vostok::animation::mixing::animation_lexeme::`vftable';
  v40.m_cloned_instance.m_object = 0;
  vostok::animation::mixing::animation_lexeme::cloned_in_buffer(
    (vostok::animation::mixing::animation_lexeme *)v42.m_buffer,
    (vostok::animation::mixing::base_lexeme *)&v40);
  v8 = &v42.m_animation_intervals[v42.m_animation_intervals_count];
  for ( i = v42.m_animation_intervals; i != v8; ++i )
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&i->m_animation);
  expression.m_lexeme = (vostok::animation::mixing::base_lexeme *)&vostok::animation::instant_interpolator::`vftable';
  right.m_interpolator = vostok::animation::instant_interpolator::clone(
                           (vostok::animation::instant_interpolator *)&expression.m_lexeme,
                           &buffer);
  memset(&right.m_next_weight, 0, 16);
  right.m_weight = left_weight;
  right.m_simplified_weight = left_weight;
  right.m_buffer = &buffer;
  right.m_cloned = 0;
  right.__vftable = (vostok::animation::mixing::weight_lexeme_vtbl *)&vostok::animation::mixing::weight_lexeme::`vftable';
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    (vostok::animation::mixing::animation_lexeme_parameters *)&buffer,
    (int)&v42,
    &buffer,
    &right_animation->animation,
    (vostok::animation::mixing::base_lexeme *)&v40,
    0,
    (vostok::animation::mixing::animation_lexeme *const)LODWORD(v37[0].w));
  v11 = (vostok::mutable_buffer **)v10;
  vostok::animation::mixing::binary_tree_animation_node::binary_tree_animation_node(&v38, v10);
  v38.vostok::animation::mixing::base_lexeme::m_buffer = *v11;
  v38.m_cloned = 0;
  v38.__vftable = (vostok::animation::mixing::animation_lexeme_vtbl *)&vostok::animation::mixing::animation_lexeme::`vftable';
  v38.m_cloned_instance.m_object = 0;
  vostok::animation::mixing::animation_lexeme::cloned_in_buffer(v12, (vostok::animation::mixing::base_lexeme *)&v38);
  m_animation_intervals = v42.m_animation_intervals;
  v15 = &v42.m_animation_intervals[v42.m_animation_intervals_count];
  if ( v42.m_animation_intervals != v15 )
  {
    do
    {
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&m_animation_intervals->m_animation);
      ++m_animation_intervals;
    }
    while ( m_animation_intervals != v15 );
  }
  v16 = vostok::animation::mixing::weight_lexeme::cloned_modified_lexeme(
          v13,
          (int)&right,
          *(float *)&clear_value - right.m_weight);
  LODWORD(v37[0].z) = vostok::animation::mixing::operator*<vostok::animation::mixing::animation_lexeme,vostok::animation::mixing::weight_lexeme>(
                        &v38,
                        v16);
  v17 = vostok::animation::mixing::operator*<vostok::animation::mixing::animation_lexeme,vostok::animation::mixing::weight_lexeme>(
          &v40,
          &right);
  v18 = (vostok::animation::mixing::expression *)vostok::animation::mixing::operator+<vostok::animation::mixing::multiplication_lexeme,vostok::animation::mixing::multiplication_lexeme>(
                                                   v17,
                                                   (vostok::animation::mixing::multiplication_lexeme *)LODWORD(v37[0].z));
  vostok::animation::mixing::expression::expression(v18, &expression);
  v19 = vostok::math::float4x4::identity((vostok::math::float4x4 *)&v42.m_animation_intervals);
  vostok::animation::animation_player::set_target_and_tick(player, v19, &expression, 0);
  m_object = expression.m_node.m_object;
  if ( expression.m_node.m_object )
  {
    if ( expression.m_node.m_object->m_reference_count-- == 1 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))m_object->~vostok::animation::mixing::binary_tree_base_node)(
        m_object,
        0);
  }
  v22 = (vostok::animation::subscribed_channel **)vostok::math::floor(
                                                    (float)((float)((float)(*(float *)&clear_value - left_weight)
                                                                  * right_animation->length)
                                                          + (float)(left_animation->length * left_weight))
                                                  * 1000.0);
  vostok::animation::animation_player::tick(v23, (int)player, v22);
  vostok::animation::mixing::n_ary_tree::get_object_transform(
    v24,
    &player->m_mixing_tree,
    (vostok::math::float4x4 *)&v42.m_weight_driving_animation,
    0);
  angles_xyz = vostok::math::float4x4::get_angles_xyz(v25, &v43, (float *)&v42.m_weight_driving_animation);
  v27 = *(_QWORD *)&angles_xyz->x;
  z = angles_xyz->z;
  *(_QWORD *)&v37[0].x = v27;
  v37[0].z = z;
  vostok::math::quaternion::quaternion(v37, v39, *(vostok::math::float3 *)&v37[0].x);
  v30 = *v29;
  v31 = v29[1];
  v32 = *(_QWORD *)&v42.m_time_synchronization_group_id;
  v33 = *(float *)&v42.m_additivity_priority;
  *(_QWORD *)&result->rotation.x = v30;
  *(_QWORD *)&result->rotation.vector.elements[2] = v31;
  *(_QWORD *)&result->translation.x = v32;
  result->translation.z = v33;
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v34, (int)&v38);
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v35, (int)&v40);
  return result;
}
