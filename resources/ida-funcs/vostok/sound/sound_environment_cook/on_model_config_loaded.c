void __thiscall vostok::sound::sound_environment_cook::on_model_config_loaded(
        vostok::sound::sound_environment_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::configs::binary_config_value *v2; // eax
  vostok::configs::binary_config_value *v3; // eax
  const vostok::math::float4x4 *v4; // eax
  const vostok::math::float4x4 *v5; // eax
  vostok::math::float4x4 *v6; // eax
  vostok::sound::sound_environment *v7; // eax
  survarium::game_material_manager_cook *v8; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::game_material_manager_cook,vostok::resources::queries_result &,survarium::vector<survarium::game_material_manager_cook::query_ext_data> *>,boost::_bi::list3<boost::_bi::value<survarium::game_material_manager_cook *>,boost::arg<1>,boost::_bi::value<survarium::vector<survarium::game_material_manager_cook::query_ext_data> *> > > v9; // [esp-8h] [ebp-580h] BYREF
  unsigned int other_z; // [esp+8h] [ebp-570h]
  vostok::sound::sound_environment *v11; // [esp+14h] [ebp-564h]
  vostok::math::float4x4 *v12; // [esp+18h] [ebp-560h]
  vostok::sound::sound_environment_cook *thisa; // [esp+1Ch] [ebp-55Ch]
  vostok::memory::doug_lea_allocator *allocator; // [esp+20h] [ebp-558h]
  vostok::memory::detail::call_destructor_predicate call_destructor_predicate; // [esp+27h] [ebp-551h] BYREF
  vostok::sound::sound_environment *v16; // [esp+28h] [ebp-550h]
  vostok::memory::doug_lea_allocator *v17; // [esp+2Ch] [ebp-54Ch]
  vostok::resources::unmanaged_resource *v18; // [esp+30h] [ebp-548h]
  const char **v19; // [esp+34h] [ebp-544h]
  const char *v20; // [esp+38h] [ebp-540h]
  const char *v21; // [esp+3Ch] [ebp-53Ch]
  char v22; // [esp+41h] [ebp-537h]
  unsigned __int8 dst[388]; // [esp+48h] [ebp-530h] BYREF
  float v24; // [esp+1CCh] [ebp-3ACh]
  char v25; // [esp+1D3h] [ebp-3A5h]
  vostok::math::float4x4 *v26; // [esp+1D4h] [ebp-3A4h]
  vostok::memory::doug_lea_allocator *v27; // [esp+1D8h] [ebp-3A0h]
  vostok::math::float3 **v28; // [esp+1DCh] [ebp-39Ch]
  vostok::math::float3 *v29; // [esp+1E0h] [ebp-398h]
  vostok::math::float3 *v30; // [esp+1E4h] [ebp-394h]
  char v31; // [esp+1EBh] [ebp-38Dh]
  vostok::math::float3 **v32; // [esp+1ECh] [ebp-38Ch]
  vostok::math::float3 *v33; // [esp+1F0h] [ebp-388h]
  vostok::math::float3 *v34; // [esp+1F4h] [ebp-384h]
  char v35; // [esp+1FBh] [ebp-37Dh]
  vostok::math::float3 **v36; // [esp+1FCh] [ebp-37Ch]
  vostok::math::float3 *v37; // [esp+200h] [ebp-378h]
  vostok::math::float3 *v38; // [esp+204h] [ebp-374h]
  char v39; // [esp+20Bh] [ebp-36Dh]
  vostok::configs::binary_config_value *v40; // [esp+20Ch] [ebp-36Ch]
  vostok::configs::binary_config *v41; // [esp+210h] [ebp-368h]
  char v42; // [esp+217h] [ebp-361h]
  vostok::math::float3 **v43; // [esp+218h] [ebp-360h]
  vostok::math::float3 *v44; // [esp+21Ch] [ebp-35Ch]
  vostok::math::float3 *v45; // [esp+220h] [ebp-358h]
  char v46; // [esp+227h] [ebp-351h]
  vostok::configs::binary_config_value *m_root; // [esp+228h] [ebp-350h]
  vostok::configs::binary_config *m_object; // [esp+22Ch] [ebp-34Ch]
  char v49; // [esp+233h] [ebp-345h]
  vostok::variant<32> *m_user_data; // [esp+234h] [ebp-344h]
  vostok::configs::binary_config *object; // [esp+238h] [ebp-340h]
  vostok::resources::query_result_for_user *v52; // [esp+23Ch] [ebp-33Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > v53; // [esp+240h] [ebp-338h] BYREF
  void (__thiscall *f)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *, vostok::math::float4x4 *); // [esp+250h] [ebp-328h]
  int f_4; // [esp+254h] [ebp-324h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+258h] [ebp-320h] BYREF
  vostok::sound::sound_environment *v57; // [esp+280h] [ebp-2F8h]
  vostok::math::float4x4 v58; // [esp+284h] [ebp-2F4h] BYREF
  vostok::math::float4x4 v59; // [esp+2C4h] [ebp-2B4h] BYREF
  vostok::math::float4x4 left; // [esp+304h] [ebp-274h] BYREF
  vostok::math::float3 v61; // [esp+344h] [ebp-234h] BYREF
  float v62; // [esp+350h] [ebp-228h]
  vostok::math::float4x4 v63; // [esp+354h] [ebp-224h] BYREF
  vostok::math::float4x4 result; // [esp+394h] [ebp-1E4h] BYREF
  vostok::math::float3 v65; // [esp+3D4h] [ebp-1A4h] BYREF
  int v66; // [esp+3E0h] [ebp-198h]
  float v67; // [esp+3E4h] [ebp-194h]
  int v68; // [esp+3E8h] [ebp-190h]
  vostok::math::float4x4 *v69; // [esp+3ECh] [ebp-18Ch]
  char v70; // [esp+3F1h] [ebp-187h]
  char v71; // [esp+3F2h] [ebp-186h]
  char v72; // [esp+3F3h] [ebp-185h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v73; // [esp+3F4h] [ebp-184h] BYREF
  char v74; // [esp+3FBh] [ebp-17Dh]
  vostok::sound::sound_environment *created_resource; // [esp+3FCh] [ebp-17Ch]
  vostok::math::float3 min_aabb; // [esp+400h] [ebp-178h]
  vostok::math::float4x4 *transform; // [esp+40Ch] [ebp-16Ch] BYREF
  vostok::fixed_string<256> path; // [esp+410h] [ebp-168h] BYREF
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> cfg; // [esp+524h] [ebp-54h] BYREF
  vostok::render::static_model_instance_user_data model_user_data; // [esp+528h] [ebp-50h] BYREF
  vostok::math::float3 max_aabb; // [esp+534h] [ebp-44h]
  vostok::math::float3 rotation; // [esp+540h] [ebp-38h] BYREF
  vostok::sound::sound_scene *scn; // [esp+54Ch] [ebp-2Ch]
  unsigned int env_params_id; // [esp+550h] [ebp-28h]
  vostok::resources::query_result_for_cook *parent; // [esp+554h] [ebp-24h]
  bool success; // [esp+55Bh] [ebp-1Dh]
  const char *environment_name; // [esp+55Ch] [ebp-1Ch]
  vostok::math::float3 dimension; // [esp+560h] [ebp-18h] BYREF
  vostok::math::float3 position; // [esp+56Ch] [ebp-Ch]

  thisa = this;
  v74 = 0;
  v52 = vostok::resources::queries_result::operator[](data, 0);
  boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>(
    &v73,
    &v52->m_unmanaged_resource);
  object = (vostok::configs::binary_config *)v73.m_object;
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>(
    &cfg,
    (vostok::configs::binary_config *)v73.m_object);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&v73);
  v72 = 0;
  parent = data->m_parent_query;
  v71 = 0;
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>((vostok::render::stage_lights::lights_instance *)&model_user_data.sound_scene);
  m_user_data = parent->m_user_data;
  success = vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>(m_user_data, &model_user_data);
  v70 = 0;
  v49 = 0;
  m_object = cfg.m_object;
  m_root = cfg.m_object->m_root;
  v2 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                 m_root,
                                                 (const char *)&stru_962594.m_v_shaders._M_t._M_header._M_data._M_color);
  v43 = (vostok::math::float3 **)vostok::configs::binary_config_value::operator[](
                                   v2,
                                   (const char *)&stru_962594.m_v_shaders._M_t._M_key_compare);
  v46 = 0;
  v45 = *v43;
  v44 = v45;
  min_aabb = *v45;
  v42 = 0;
  v41 = cfg.m_object;
  v40 = cfg.m_object->m_root;
  v3 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                 v40,
                                                 (const char *)&stru_962594.m_v_shaders._M_t._M_header._M_data._M_color);
  v36 = (vostok::math::float3 **)vostok::configs::binary_config_value::operator[](
                                   v3,
                                   (const char *)&stru_962594.m_v_shaders._M_t._M_node_count);
  v39 = 0;
  v38 = *v36;
  v37 = v38;
  max_aabb = *v38;
  vostok::math::float3::float3(
    &dimension,
    COERCE_UNSIGNED_INT(max_aabb.x - min_aabb.x),
    COERCE_UNSIGNED_INT(max_aabb.y - min_aabb.y),
    max_aabb.z - min_aabb.z);
  v32 = (vostok::math::float3 **)vostok::configs::binary_config_value::operator[](
                                   (vostok::configs::binary_config_value *)model_user_data.config,
                                   "position");
  v35 = 0;
  v34 = *v32;
  v33 = v34;
  position = *v34;
  v28 = (vostok::math::float3 **)vostok::configs::binary_config_value::operator[](
                                   (vostok::configs::binary_config_value *)model_user_data.config,
                                   "rotation");
  v31 = 0;
  v30 = *v28;
  v29 = v30;
  rotation = *v30;
  v27 = (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object;
  v26 = (vostok::math::float4x4 *)vostok::memory::doug_lea_allocator::malloc_impl(
                                    (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
                                    0x40u);
  v69 = v26;
  if ( v26 )
    v12 = v69;
  else
    v12 = 0;
  transform = v12;
  v62 = FLOAT_2_0;
  v25 = 0;
  v24 = dimension.y / 2.0;
  v66 = *(_DWORD *)&FLOAT_0_0;
  v67 = dimension.y / 2.0;
  v68 = *(_DWORD *)&FLOAT_0_0;
  vostok::math::float3::float3(
    &v65,
    COERCE_UNSIGNED_INT(position.x + 0.0),
    COERCE_UNSIGNED_INT(position.y + (float)(dimension.y / 2.0)),
    position.z + 0.0);
  dst[67] = 0;
  vostok::math::float3::float3(
    &v61,
    COERCE_UNSIGNED_INT(dimension.x / 2.0),
    COERCE_UNSIGNED_INT(dimension.y / 2.0),
    dimension.z / 2.0);
  memset(dst, 0, 0x40u);
  *(float *)&dst[20] = v61.y;
  *(float *)dst = v61.x;
  *(float *)&dst[40] = v61.z;
  *(float *)&dst[60] = FLOAT_1_0;
  qmemcpy((void *)&left, dst, sizeof(left));
  other_z = (unsigned int)vostok::math::create_translation(&result, &v65);
  v4 = vostok::math::create_rotation(&v63, &rotation);
  v5 = vostok::math::operator*(&v59, &left, v4);
  v6 = vostok::math::operator*(&v58, v5, (const vostok::math::float4x4 *)other_z);
  qmemcpy((void *)transform, v6, sizeof(vostok::math::float4x4));
  v19 = (const char **)vostok::configs::binary_config_value::operator[](
                         (vostok::configs::binary_config_value *)model_user_data.config,
                         "sound_environment");
  v22 = 0;
  v21 = *v19;
  v20 = v21;
  environment_name = v21;
  v18 = model_user_data.sound_scene.m_object;
  scn = (vostok::sound::sound_scene *)model_user_data.sound_scene.m_object;
  env_params_id = vostok::sound::sound_scene::get_environment_params_id(
                    (vostok::sound::sound_scene *)model_user_data.sound_scene.m_object,
                    v21);
  if ( env_params_id == -1 )
  {
    vostok::fixed_string<256>::fixed_string<256>(&path);
    vostok::buffer_string::assignf(&path, "resources/sounds/environments/%s.environment", environment_name);
    f = vostok::sound::sound_environment_cook::on_environment_options_loaded;
    f_4 = 0;
    other_z = 0;
    v9 = *boost::bind<void,vostok::ai::brain_unit_cook,vostok::resources::queries_result &,vostok::ai::brain_unit *,vostok::ai::brain_unit_cook *,boost::arg<1>,vostok::ai::brain_unit *>(
            (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::game_material_manager_cook,vostok::resources::queries_result &,survarium::vector<survarium::game_material_manager_cook::query_ext_data> *>,boost::_bi::list3<boost::_bi::value<survarium::game_material_manager_cook *>,boost::arg<1>,boost::_bi::value<survarium::vector<survarium::game_material_manager_cook::query_ext_data> *> > > *)&v53,
            (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *, vostok::math::float4x4 *))(unsigned int)vostok::sound::sound_environment_cook::on_environment_options_loaded,
            (survarium::game_material_manager_cook *)thisa,
            1_2,
            transform);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      &callback,
      (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > >)v9,
      0);
    vostok::resources::query_resource(
      path.m_begin,
      binary_config_class_impl,
      &callback,
      (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object,
      0,
      parent,
      assert_on_fail_true);
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&model_user_data.sound_scene);
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&cfg);
  }
  else
  {
    v17 = (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object;
    v16 = (vostok::sound::sound_environment *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
                                                0x110u);
    v57 = v16;
    if ( v16 )
    {
      vostok::sound::sound_environment::sound_environment(v57, env_params_id);
      v11 = v7;
    }
    else
    {
      v11 = 0;
    }
    created_resource = v11;
    vostok::sound::sound_scene::insert_environment(scn, v11, transform);
    allocator = (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object;
    call_destructor_predicate = 0;
    vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::math::float4x4,vostok::memory::detail::call_destructor_predicate>(
      (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
      &transform,
      &call_destructor_predicate);
    other_z = 272;
    v9.l_.a3_.t_ = (survarium::vector<survarium::game_material_manager_cook::query_ext_data> *)&vostok::resources::nocache_memory;
    v9.l_.a1_.t_ = v8;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v9.l_,
      (vostok::configs::binary_config *)created_resource);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      parent,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v9.l_.a1_.t_,
      (const vostok::resources::memory_type *)v9.l_.a3_.t_,
      other_z);
    vostok::resources::query_result_for_cook::finish_query(parent, result_success, assert_on_fail_true);
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&model_user_data.sound_scene);
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&cfg);
  }
}
