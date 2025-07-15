void __thiscall survarium::collision_geometry::load(
        survarium::collision_geometry *this,
        vostok::configs::binary_config_value *cfg_val)
{
  const vostok::configs::binary_config_value *v2; // eax
  const vostok::configs::binary_config_value *v3; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  const vostok::configs::binary_config_value *v5; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  const vostok::configs::binary_config_value *v7; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v8; // ecx
  vostok::math::float4x4 *v9; // eax
  const vostok::math::float4x4 *v10; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // ecx
  const vostok::configs::binary_config_value *v12; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v13; // ecx
  const vostok::math::float3 *v14; // eax
  vostok::configs::binary_config *v15; // eax
  vostok::physics::bt_ghost_object *ghost_object; // eax
  vostok::physics::bt_collision_shape *v17; // eax
  const vostok::configs::binary_config_value *v18; // eax
  vostok::configs::binary_config_value *v19; // ecx
  unsigned __int16 v20; // ax
  const vostok::configs::binary_config_value *v21; // eax
  vostok::configs::binary_config_value *v22; // ecx
  unsigned __int16 v23; // ax
  vostok::intrusive_ptr<vostok::render::culling::portal_sector_structure,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> other_y; // [esp+4h] [ebp-350h] BYREF
  const vostok::math::float4x4 *other_z; // [esp+8h] [ebp-34Ch]
  const char *v26; // [esp+Ch] [ebp-348h]
  survarium::collision_geometry *thisa; // [esp+14h] [ebp-340h]
  int v28; // [esp+1B0h] [ebp-1A4h]
  vostok::math::float3 v29; // [esp+1B8h] [ebp-19Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+1C4h] [ebp-190h] BYREF
  vostok::math::float4x4 v31; // [esp+1E4h] [ebp-170h] BYREF
  _BYTE v32[64]; // [esp+224h] [ebp-130h] BYREF
  vostok::math::float4x4 v33; // [esp+264h] [ebp-F0h] BYREF
  vostok::math::float4x4 result; // [esp+2A4h] [ebp-B0h] BYREF
  vostok::math::float4x4 transform; // [esp+2E4h] [ebp-70h] BYREF
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> shape; // [esp+328h] [ebp-2Ch] BYREF
  vostok::configs::binary_config_value meshes; // [esp+32Ch] [ebp-28h] BYREF
  const vostok::math::float3 *rotation; // [esp+348h] [ebp-Ch]
  const vostok::math::float3 *scale; // [esp+34Ch] [ebp-8h]
  const vostok::math::float3 *position; // [esp+350h] [ebp-4h]

  thisa = this;
  v28 = 0;
  v2 = vostok::configs::binary_config_value::operator[](cfg_val, "full_name");
  vostok::fixed_string<260>::operator=<vostok::configs::binary_config_value>(&thisa->m_name, v2);
  v3 = vostok::configs::binary_config_value::operator[](cfg_val, "scale");
  scale = (const vostok::math::float3 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                          v4,
                                          (int)v3);
  v5 = vostok::configs::binary_config_value::operator[](cfg_val, "rotation");
  rotation = (const vostok::math::float3 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                             v6,
                                             (int)v5);
  v7 = vostok::configs::binary_config_value::operator[](cfg_val, "position");
  position = (const vostok::math::float3 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                             v8,
                                             (int)v7);
  other_z = vostok::math::create_translation(&result, position);
  other_y.m_object = (vostok::render::culling::portal_sector_structure *)vostok::math::create_rotation(&v33, rotation);
  v9 = vostok::math::create_scale(scale, (int)v32);
  v10 = vostok::math::operator*(&v31, v9, (const vostok::math::float4x4 *)other_y.m_object);
  vostok::math::operator*(&transform, v10, other_z);
  if ( vostok::configs::binary_config_value::value_exists(cfg_val, "meshes") )
  {
    v12 = vostok::configs::binary_config_value::operator[](cfg_val, "mode");
    thisa->m_mode = (survarium::collision_geometry::collision_geometry_mode)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                                              v13,
                                                                              (int)v12);
    meshes = *vostok::configs::binary_config_value::operator[](cfg_val, "meshes");
    stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
      (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)HIDWORD(meshes.id.max_storage),
      (int)&thisa->m_name);
    vostok::math::float3::float3(&v29, COERCE_UNSIGNED_INT(1.0), COERCE_UNSIGNED_INT(1.0), 1.0);
    v15 = (vostok::configs::binary_config *)vostok::physics::create_compound_shape(&meshes, v14, v26);
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>(
      (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&shape,
      v15);
    other_z = &transform;
    other_y.m_object = (vostok::render::culling::portal_sector_structure *)&transform;
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>(
      &other_y,
      (const vostok::intrusive_ptr<vostok::render::culling::portal_sector_structure,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&shape);
    ghost_object = vostok::physics::create_ghost_object(
                     (vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>)other_y.m_object,
                     other_z);
    thisa->m_ghost_object = ghost_object;
    v17 = vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator->(&shape);
    vostok::resources::unmanaged_resource::set_no_delete(v17);
    v18 = vostok::configs::binary_config_value::operator[](cfg_val, "filter_group");
    v20 = vostok::configs::binary_config_value::operator unsigned short(v19, (int)v18);
    thisa->m_group = v20;
    v21 = vostok::configs::binary_config_value::operator[](cfg_val, "filter_mask");
    v23 = vostok::configs::binary_config_value::operator unsigned short(v22, (int)v21);
    thisa->m_mask = v23;
    vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&shape);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game_core:", warning) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v11);
      v28 |= 1u;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\collision_geometry.cpp",
        0x2Du,
        "void __thiscall survarium::collision_geometry::load(const class vostok::configs::binary_config_value &)",
        "game_core:",
        warning,
        "invalid collision_geometry");
    }
    if ( (v28 & 1) != 0 )
    {
      v28 &= ~1u;
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v11,
        (int *)&log_callback);
    }
  }
}
