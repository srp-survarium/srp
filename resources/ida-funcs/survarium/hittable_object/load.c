void __thiscall survarium::hittable_object::load(
        survarium::hittable_object *this,
        const vostok::configs::binary_config_value *cfg_val,
        vostok::configs::binary_config_value *a4)
{
  const struct btVector3 *v4; // ebx
  vostok::configs::binary_config_value *v5; // esi
  const vostok::configs::binary_config_value *v6; // eax
  const vostok::configs::binary_config_value *v7; // esi
  const vostok::configs::binary_config_value *v8; // eax
  vostok::physics::bt_rigid_body_construction_info *p_id_crc; // ecx
  vostok::physics::bt_rigid_body_construction_info *v10; // [esp-4h] [ebp-8Ch]
  vostok::physics::bt_rigid_body_construction_info construction_info; // [esp+10h] [ebp-78h] BYREF
  vostok::configs::binary_config_value v12; // [esp+60h] [ebp-28h] BYREF
  vostok::math::float3 v13; // [esp+7Ch] [ebp-Ch] BYREF

  v4 = (const struct btVector3 *)cfg_val;
  v5 = a4;
  vostok::configs::binary_config_value::operator[](a4, "full_name");
  vostok::configs::binary_config_value::operator[](v5, "scale");
  vostok::configs::binary_config_value::operator[](v5, "rotation");
  vostok::configs::binary_config_value::operator[](v5, "position");
  qmemcpy((void *)&v12, vostok::configs::binary_config_value::operator[](v5, "meshes"), sizeof(v12));
  v13.x = s_bm_current_air_resistance;
  v13.y = s_bm_current_air_resistance;
  v13.z = s_bm_current_air_resistance;
  vostok::physics::create_compound_shape(&v12, &v13);
  v7 = v6;
  v8 = 0;
  p_id_crc = v10;
  cfg_val = 0;
  if ( v7 )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&cfg_val);
    v8 = v7;
    cfg_val = v7;
    p_id_crc = (vostok::physics::bt_rigid_body_construction_info *)&v7[8].id_crc;
    _InterlockedExchangeAdd((volatile signed __int32 *)&v7[8].id_crc, 1u);
  }
  v8[10].id_crc |= 2u;
  vostok::physics::bt_rigid_body_construction_info::bt_rigid_body_construction_info(p_id_crc, (int)&construction_info);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&cfg_val,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&construction_info.m_collisionShape);
  v4->mVec128.m128_i32[1] = (int)vostok::physics::create_static_rigid_body(
                                   v4,
                                   (struct btMotionState *)&cfg_val,
                                   (struct btCollisionShape *)v7,
                                   &construction_info);
  v4->mVec128.m128_i16[6] = (__int16)vostok::configs::binary_config_value::operator[](a4, "filter_group")->data.pointer;
  v4->mVec128.m128_i16[7] = (__int16)vostok::configs::binary_config_value::operator[](a4, "filter_mask")->data.pointer;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&construction_info.m_collisionShape);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&cfg_val);
}
