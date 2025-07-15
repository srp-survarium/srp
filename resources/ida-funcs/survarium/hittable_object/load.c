void __userpurge survarium::hittable_object::load(
        survarium::hittable_object *this@<ecx>,
        btRigidBody *a2@<ebx>,
        vostok::configs::binary_config_value *cfg_val)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  survarium::game_camera *v7; // ecx
  survarium::game_camera *v8; // ecx
  const vostok::configs::binary_config_value *v9; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v10; // ecx
  const vostok::configs::binary_config_value *v11; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v12; // ecx
  const vostok::configs::binary_config_value *v13; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v14; // ecx
  const vostok::configs::binary_config_value *v15; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v16; // ecx
  const vostok::math::float3 *v17; // edi
  vostok::math::float4x4 *v18; // eax
  const vostok::math::float4x4 *v19; // eax
  const vostok::math::float3 *v20; // eax
  vostok::configs::binary_config *v21; // eax
  vostok::physics::bt_collision_shape *v22; // eax
  vostok::physics::bt_rigid_body_construction_info *v23; // ecx
  const vostok::configs::binary_config_value *v24; // eax
  vostok::configs::binary_config_value *v25; // ecx
  const vostok::configs::binary_config_value *v26; // eax
  vostok::configs::binary_config_value *v27; // ecx
  survarium::game_camera *v28; // ecx
  survarium::game_camera *v29; // ecx
  const vostok::math::float4x4 *other_y; // [esp+4h] [ebp-370h]
  const vostok::math::float4x4 *other_z; // [esp+8h] [ebp-36Ch]
  const char *v32; // [esp+Ch] [ebp-368h]
  vostok::math::float3 v34; // [esp+1C0h] [ebp-1B4h] BYREF
  vostok::math::float4x4 v35; // [esp+1CCh] [ebp-1A8h] BYREF
  _BYTE v36[64]; // [esp+20Ch] [ebp-168h] BYREF
  vostok::math::float4x4 v37; // [esp+24Ch] [ebp-128h] BYREF
  vostok::math::float4x4 result; // [esp+28Ch] [ebp-E8h] BYREF
  char v39; // [esp+2CDh] [ebp-A7h]
  char v40; // [esp+2CEh] [ebp-A6h]
  char v41; // [esp+2CFh] [ebp-A5h]
  char v42; // [esp+2D0h] [ebp-A4h]
  char v43; // [esp+2D1h] [ebp-A3h]
  char v44; // [esp+2D2h] [ebp-A2h]
  char v45; // [esp+2D3h] [ebp-A1h]
  vostok::math::float4x4 transform; // [esp+2D4h] [ebp-A0h] BYREF
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> shape; // [esp+314h] [ebp-60h] BYREF
  vostok::physics::bt_rigid_body_construction_info info; // [esp+318h] [ebp-5Ch] BYREF
  vostok::configs::binary_config_value meshes; // [esp+34Ch] [ebp-28h] BYREF
  const char *name; // [esp+364h] [ebp-10h]
  const vostok::math::float3 *rotation; // [esp+368h] [ebp-Ch]
  const vostok::math::float3 *scale; // [esp+36Ch] [ebp-8h]
  const vostok::math::float3 *position; // [esp+370h] [ebp-4h]

  v45 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v44 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  v43 = 0;
  survarium::weapon_user_dead_state::finalize(v4);
  v42 = 0;
  survarium::weapon_user_dead_state::finalize(v5);
  v41 = 0;
  survarium::weapon_user_dead_state::finalize(v6);
  v40 = 0;
  survarium::weapon_user_dead_state::finalize(v7);
  v39 = 0;
  survarium::weapon_user_dead_state::finalize(v8);
  v9 = vostok::configs::binary_config_value::operator[](cfg_val, "full_name");
  name = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                         v10,
                         (int)v9);
  v11 = vostok::configs::binary_config_value::operator[](cfg_val, "scale");
  scale = (const vostok::math::float3 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                          v12,
                                          (int)v11);
  v13 = vostok::configs::binary_config_value::operator[](cfg_val, "rotation");
  rotation = (const vostok::math::float3 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                             v14,
                                             (int)v13);
  v15 = vostok::configs::binary_config_value::operator[](cfg_val, "position");
  position = (const vostok::math::float3 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                             v16,
                                             (int)v15);
  other_z = vostok::math::create_translation(&result, position);
  other_y = vostok::math::create_rotation(&v37, rotation);
  v17 = scale;
  v18 = vostok::math::create_scale(scale, (int)v36);
  v19 = vostok::math::operator*(&v35, v18, other_y);
  vostok::math::operator*(&transform, v19, other_z);
  meshes = *vostok::configs::binary_config_value::operator[](cfg_val, "meshes");
  vostok::math::float3::float3(&v34, COERCE_UNSIGNED_INT(1.0), COERCE_UNSIGNED_INT(1.0), 1.0);
  v21 = (vostok::configs::binary_config *)vostok::physics::create_compound_shape(&meshes, v20, v32);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>(
    (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&shape,
    v21);
  v22 = vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator->(&shape);
  vostok::resources::unmanaged_resource::set_no_delete(v22);
  vostok::physics::bt_rigid_body_construction_info::bt_rigid_body_construction_info(v23);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    &info.m_collisionShape,
    &shape);
  this->m_rigid_body = vostok::physics::create_static_rigid_body(
                         &info,
                         a2,
                         (int)v17,
                         (vostok::physics::bt_collision_shape *)v36);
  v24 = vostok::configs::binary_config_value::operator[](cfg_val, "filter_group");
  this->m_group = vostok::configs::binary_config_value::operator unsigned short(v25, (int)v24);
  v26 = vostok::configs::binary_config_value::operator[](cfg_val, "filter_mask");
  this->m_mask = vostok::configs::binary_config_value::operator unsigned short(v27, (int)v26);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v28);
  survarium::weapon_user_dead_state::finalize(v29);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&info.m_collisionShape);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&shape);
}
