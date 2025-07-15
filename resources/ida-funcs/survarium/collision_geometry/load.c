void __thiscall survarium::collision_geometry::load(
        survarium::collision_geometry *this,
        const vostok::configs::binary_config_value *cfg_val,
        vostok::configs::binary_config_value *a4)
{
  const vostok::math::float3 *pointer; // esi
  vostok::math::float4x4 *v5; // eax
  vostok::math::float4x4 *v6; // eax
  float **v7; // eax
  float *v8; // esi
  vostok::physics::bt_collision_shape *primitive_shape; // eax
  const void ***v10; // eax
  const void **v11; // esi
  vostok::particle::particle_system_instance_impl *v12; // esi
  vostok::particle::particle_system_instance_impl *v13; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v14; // [esp-4h] [ebp-190h] BYREF
  vostok::particle::particle_system_instance_impl *epsilon; // [esp+0h] [ebp-18Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v16; // [esp+10h] [ebp-17Ch] BYREF
  vostok::math::float3_pod other; // [esp+14h] [ebp-178h] BYREF
  vostok::math::float3_pod v18; // [esp+28h] [ebp-164h] BYREF
  vostok::configs::binary_config_value v19; // [esp+34h] [ebp-158h] BYREF
  vostok::math::float4x4 v20; // [esp+4Ch] [ebp-140h] BYREF
  vostok::math::float4x4 transform; // [esp+8Ch] [ebp-100h] BYREF
  _BYTE v22[64]; // [esp+CCh] [ebp-C0h] BYREF
  vostok::math::float4x4 v23; // [esp+10Ch] [ebp-80h] BYREF
  vostok::math::float4x4 v24; // [esp+14Ch] [ebp-40h] BYREF

  vostok::configs::binary_config_value::operator[](a4, "full_name");
  pointer = (const vostok::math::float3 *)vostok::configs::binary_config_value::operator[](a4, "scale")->data.pointer;
  v16.m_object = (vostok::particle::particle_system_instance_impl *)vostok::configs::binary_config_value::operator[](
                                                                      a4,
                                                                      "rotation")->data.pointer;
  *(_QWORD *)&other.x = (unsigned int)vostok::configs::binary_config_value::operator[](a4, "position")->data.pointer;
  v16.m_object = (vostok::particle::particle_system_instance_impl *)vostok::math::create_rotation(
                                                                      (const vostok::math::float3 *)v16.m_object,
                                                                      (int)"position",
                                                                      (int)v22);
  v5 = vostok::math::create_scale(pointer, &v23);
  vostok::math::mul4x3((const vostok::math::float4x4 *)v16.m_object, v5, &v20);
  v6 = vostok::math::create_translation((const vostok::math::float3 *)LODWORD(other.x), &v24);
  vostok::math::mul4x3(v6, &v20, &transform);
  cfg_val[1].data.pointer = vostok::configs::binary_config_value::operator[](a4, "mode")->data.pointer;
  qmemcpy((void *)&v19, vostok::configs::binary_config_value::operator[](a4, "meshes"), sizeof(v19));
  if ( 24 * HIWORD(*(_DWORD *)&v19.type) / 24 == 1
    && (v7 = (float **)vostok::configs::binary_config_value::operator[](
                         (vostok::configs::binary_config_value *)v19.data.pointer,
                         "position"),
        v8 = *v7,
        v18.x = **v7,
        *(_QWORD *)&v18.elements[1] = *(_QWORD *)(v8 + 1),
        memset(&other, 0, sizeof(other)),
        vostok::math::float3_pod::is_similar(&v18, &other, 0.0000099999997)) )
  {
    qmemcpy((void *)&v19, v19.data.pointer, sizeof(v19));
    *(_QWORD *)&other.x = (int)vostok::configs::binary_config_value::operator[](&v19, "type")->data.pointer;
    v10 = (const void ***)vostok::configs::binary_config_value::operator[](&v19, "scale");
    v11 = *v10;
    v19.data.pointer = **v10;
    HIDWORD(v19.data.max_storage) = *++v11;
    epsilon = (vostok::particle::particle_system_instance_impl *)&v18;
    v19.id.pointer = (const char *)v11[1];
    v18.x = s_bm_current_air_resistance;
    v18.y = s_bm_current_air_resistance;
    v18.z = s_bm_current_air_resistance;
    primitive_shape = vostok::physics::create_primitive_shape(
                        (const vostok::math::float3 *)&v19,
                        SLODWORD(other.x),
                        (const vostok::math::float3 *)&v18);
  }
  else
  {
    other.x = s_bm_current_air_resistance;
    other.y = s_bm_current_air_resistance;
    other.z = s_bm_current_air_resistance;
    vostok::physics::create_compound_shape(&v19, (const vostok::math::float3 *)&other);
  }
  v16.m_object = 0;
  v12 = (vostok::particle::particle_system_instance_impl *)primitive_shape;
  v13 = epsilon;
  if ( primitive_shape )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v16);
    v16.m_object = v12;
    v13 = (vostok::particle::particle_system_instance_impl *)_InterlockedExchangeAdd(&v12->m_reference_count, 1u);
  }
  epsilon = (vostok::particle::particle_system_instance_impl *)&transform;
  v14.m_object = v13;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v14,
    &v16);
  *(_DWORD *)&cfg_val->type = vostok::physics::create_ghost_object(v14, (const vostok::math::float4x4 *)epsilon);
  v16.m_object->m_flags.m_flags |= 2u;
  WORD2(cfg_val[1].data.max_storage) = vostok::configs::binary_config_value::operator[](a4, "filter_group")->data.pointer;
  HIWORD(cfg_val[1].data.max_storage) = vostok::configs::binary_config_value::operator[](a4, "filter_mask")->data.pointer;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v16);
}
