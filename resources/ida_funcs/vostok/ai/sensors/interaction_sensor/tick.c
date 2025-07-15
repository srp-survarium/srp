void __thiscall vostok::ai::sensors::interaction_sensor::tick(vostok::ai::sensors::interaction_sensor *this)
{
  vostok::memory::base_allocator **v1; // eax
  const vostok::math::aabb *v2; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  survarium::game_camera *v4; // ecx
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v5; // ecx
  const vostok::ai::game_object *const *v6; // eax
  survarium::game_camera *v7; // ecx
  const vostok::ai::game_object *const *v8; // eax
  int v9; // eax
  const vostok::math::float3 *v10; // eax
  vostok::math::float3 *v11; // eax
  unsigned int current_time_in_ms; // [esp+30h] [ebp-B4h]
  vostok::math::float3 v14; // [esp+34h] [ebp-B0h]
  float z; // [esp+48h] [ebp-9Ch]
  vostok::vectora_allocator<void const *> __a; // [esp+58h] [ebp-8Ch] BYREF
  vostok::memory::base_allocator **v17; // [esp+5Ch] [ebp-88h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v18; // [esp+60h] [ebp-84h] BYREF
  vostok::vectora_allocator<vostok::ai::game_object const *> allocator; // [esp+64h] [ebp-80h] BYREF
  _BYTE v20[12]; // [esp+68h] [ebp-7Ch] BYREF
  vostok::math::float3 v21; // [esp+74h] [ebp-70h] BYREF
  vostok::math::float3 v22; // [esp+80h] [ebp-64h] BYREF
  const vostok::ai::game_object *v23; // [esp+8Ch] [ebp-58h]
  _BYTE v24[24]; // [esp+90h] [ebp-54h] BYREF
  vostok::ai::sensors::sensed_object pickup_object; // [esp+A8h] [ebp-3Ch] BYREF
  const vostok::ai::game_object *const *iter; // [esp+D0h] [ebp-14h]
  vostok::vectora<vostok::ai::game_object const *> objects; // [esp+D4h] [ebp-10h] BYREF

  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)vostok::ai::g_allocator,
    &v18);
  v17 = v1;
  allocator.m_allocator = *v1;
  vostok::vectora_allocator<void const *>::vectora_allocator<void const *>(&__a, &allocator);
  stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>(
    &objects._M_impl,
    &__a);
  v2 = this->m_npc->get_aabb(this->m_npc, (vostok::math::aabb *)v24);
  vostok::ai::ai_world::get_colliding_objects(this->m_world, v2, &objects);
  stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)&objects);
  survarium::weapon_user_dead_state::finalize(v4);
  for ( iter = v6; ; ++iter )
  {
    stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
      v5,
      (int)&objects);
    survarium::weapon_user_dead_state::finalize(v7);
    if ( iter == v8 )
      break;
    v23 = 0;
    current_time_in_ms = vostok::ai::ai_world::get_current_time_in_ms(this->m_world);
    vostok::math::float3::float3(&v22, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
    *(_QWORD *)&v14.x = *(_QWORD *)v9;
    v14.z = *(float *)(v9 + 8);
    vostok::math::float3::float3(&v21, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
    v11 = this->m_npc->get_position(this->m_npc, v20, v10);
    z = v11->z;
    *(_QWORD *)&pickup_object.position.x = *(_QWORD *)&v11->x;
    pickup_object.position.z = z;
    pickup_object.direction = v14;
    pickup_object.object = v23;
    pickup_object.update_time = current_time_in_ms;
    pickup_object.type = sensed_object_type_interaction;
    LODWORD(pickup_object.confidence) = clear_value;
    vostok::ai::brain_unit::on_interacting_object(this->m_brain_unit, &pickup_object);
  }
  stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::~_Impl_vector<void const *,vostok::vectora_allocator<void const *>>((vostok::vectora<vostok::resources::request> *)&objects);
}
