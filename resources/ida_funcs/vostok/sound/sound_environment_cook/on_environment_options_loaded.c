void __thiscall vostok::sound::sound_environment_cook::on_environment_options_loaded(
        vostok::sound::sound_environment_cook *this,
        vostok::resources::queries_result *data,
        vostok::math::float4x4 *transform)
{
  vostok::render::skeleton_model_instance *v3; // eax
  vostok::render::skeleton_model_instance *v4; // eax
  vostok::render::skeleton_model_instance *v5; // eax
  vostok::render::skeleton_model_instance *v6; // eax
  vostok::sound::sound_environment *v7; // eax
  vostok::resources::unmanaged_resource *v8; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v9; // [esp-Ch] [ebp-164h] BYREF
  const vostok::resources::memory_type *v10; // [esp-8h] [ebp-160h]
  unsigned int v11; // [esp-4h] [ebp-15Ch]
  vostok::sound::sound_environment *v12; // [esp+0h] [ebp-158h]
  vostok::sound::sound_environment_cook *thisa; // [esp+4h] [ebp-154h]
  vostok::resources::query_result_for_cook *v14; // [esp+18h] [ebp-140h]
  vostok::resources::query_result_for_cook *v15; // [esp+1Ch] [ebp-13Ch]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v16; // [esp+20h] [ebp-138h]
  vostok::memory::doug_lea_allocator *v17; // [esp+2Ch] [ebp-12Ch]
  void *pointer; // [esp+30h] [ebp-128h]
  char v19; // [esp+37h] [ebp-121h]
  vostok::sound::sound_environment *v20; // [esp+38h] [ebp-120h]
  vostok::memory::doug_lea_allocator *v21; // [esp+3Ch] [ebp-11Ch]
  char **v22; // [esp+40h] [ebp-118h]
  char *v23; // [esp+44h] [ebp-114h]
  char *v24; // [esp+48h] [ebp-110h]
  char v25; // [esp+4Fh] [ebp-109h]
  char **v26; // [esp+50h] [ebp-108h]
  char *name; // [esp+54h] [ebp-104h]
  char *v28; // [esp+58h] [ebp-100h]
  char v29; // [esp+5Fh] [ebp-F9h]
  vostok::resources::unmanaged_resource *v30; // [esp+60h] [ebp-F8h]
  float v31; // [esp+64h] [ebp-F4h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v32; // [esp+68h] [ebp-F0h]
  char v33; // [esp+6Fh] [ebp-E9h]
  float v34; // [esp+70h] [ebp-E8h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v35; // [esp+74h] [ebp-E4h]
  char v36; // [esp+7Bh] [ebp-DDh]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v37; // [esp+7Ch] [ebp-DCh]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v38; // [esp+80h] [ebp-D8h]
  float v39; // [esp+84h] [ebp-D4h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v40; // [esp+88h] [ebp-D0h]
  char v41; // [esp+8Fh] [ebp-C9h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v42; // [esp+90h] [ebp-C8h]
  float v43; // [esp+94h] [ebp-C4h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v44; // [esp+98h] [ebp-C0h]
  char v45; // [esp+9Fh] [ebp-B9h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v46; // [esp+A0h] [ebp-B8h]
  float v47; // [esp+A4h] [ebp-B4h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v48; // [esp+A8h] [ebp-B0h]
  char v49; // [esp+AFh] [ebp-A9h]
  float v50; // [esp+B0h] [ebp-A8h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v51; // [esp+B4h] [ebp-A4h]
  char v52; // [esp+BBh] [ebp-9Dh]
  float v53; // [esp+BCh] [ebp-9Ch]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v54; // [esp+C0h] [ebp-98h]
  char v55; // [esp+C7h] [ebp-91h]
  float v56; // [esp+C8h] [ebp-90h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v57; // [esp+CCh] [ebp-8Ch]
  char v58; // [esp+D3h] [ebp-85h]
  float v59; // [esp+D4h] [ebp-84h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v60; // [esp+D8h] [ebp-80h]
  char v61; // [esp+DFh] [ebp-79h]
  XAUDIO2FX_REVERB_I3DL2_PARAMETERS *v62; // [esp+E0h] [ebp-78h]
  vostok::memory::doug_lea_allocator *v63; // [esp+E4h] [ebp-74h]
  vostok::configs::binary_config_value *m_root; // [esp+E8h] [ebp-70h]
  vostok::configs::binary_config *m_object; // [esp+ECh] [ebp-6Ch]
  char v66; // [esp+F3h] [ebp-65h]
  vostok::configs::binary_config *object; // [esp+F4h] [ebp-64h]
  vostok::resources::query_result_for_user *v68; // [esp+F8h] [ebp-60h]
  vostok::variant<32> *m_user_data; // [esp+FCh] [ebp-5Ch]
  vostok::resources::query_result_for_cook *m_parent_query; // [esp+100h] [ebp-58h]
  vostok::sound::sound_environment *v71; // [esp+108h] [ebp-50h]
  char v72; // [esp+10Fh] [ebp-49h]
  XAUDIO2FX_REVERB_I3DL2_PARAMETERS *v73; // [esp+110h] [ebp-48h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v74; // [esp+114h] [ebp-44h] BYREF
  char v75; // [esp+11Ah] [ebp-3Eh]
  char v76; // [esp+11Bh] [ebp-3Dh]
  vostok::sound::sound_environment *created_resource; // [esp+11Ch] [ebp-3Ch]
  vostok::render::static_model_instance_user_data model_user_data; // [esp+120h] [ebp-38h] BYREF
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> cfg; // [esp+12Ch] [ebp-2Ch] BYREF
  vostok::sound::sound_scene *scn; // [esp+130h] [ebp-28h]
  bool success; // [esp+137h] [ebp-21h]
  vostok::configs::binary_config_value root; // [esp+138h] [ebp-20h] BYREF
  XAUDIO2FX_REVERB_I3DL2_PARAMETERS *params; // [esp+150h] [ebp-8h]
  unsigned int environment_params_id; // [esp+154h] [ebp-4h] BYREF

  thisa = this;
  v76 = 0;
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>((vostok::render::stage_lights::lights_instance *)&model_user_data.sound_scene);
  m_parent_query = data->m_parent_query;
  m_user_data = m_parent_query->m_user_data;
  success = vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>(m_user_data, &model_user_data);
  v75 = 0;
  v68 = vostok::resources::queries_result::operator[](data, 0);
  boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>(
    &v74,
    &v68->m_unmanaged_resource);
  object = (vostok::configs::binary_config *)v74.m_object;
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>(
    &cfg,
    (vostok::configs::binary_config *)v74.m_object);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&v74);
  v66 = 0;
  m_object = cfg.m_object;
  m_root = cfg.m_object->m_root;
  root = *vostok::configs::binary_config_value::operator[](m_root, "environment");
  v63 = (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object;
  v62 = (XAUDIO2FX_REVERB_I3DL2_PARAMETERS *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
                                               0x34u);
  v73 = v62;
  params = v62;
  v60 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](&root, "decay_hf_ratio");
  if ( LOWORD(v60[5].m_object) == 2 )
  {
    v59 = *(float *)&v60->m_object;
  }
  else
  {
    v61 = 0;
    v59 = (float)(int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v60);
  }
  params->DecayHFRatio = v59;
  v57 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](&root, "decay_time");
  if ( LOWORD(v57[5].m_object) == 2 )
  {
    v56 = *(float *)&v57->m_object;
  }
  else
  {
    v58 = 0;
    v56 = (float)(int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v57);
  }
  params->DecayTime = v56;
  v54 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](&root, "density");
  if ( LOWORD(v54[5].m_object) == 2 )
  {
    v53 = *(float *)&v54->m_object;
  }
  else
  {
    v55 = 0;
    v53 = (float)(int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v54);
  }
  params->Density = v53;
  v51 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](&root, "diffusion");
  if ( LOWORD(v51[5].m_object) == 2 )
  {
    v50 = *(float *)&v51->m_object;
  }
  else
  {
    v52 = 0;
    v50 = (float)(int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v51);
  }
  params->Diffusion = v50;
  v48 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](&root, "hf_reference");
  if ( LOWORD(v48[5].m_object) == 2 )
  {
    v47 = *(float *)&v48->m_object;
  }
  else
  {
    v49 = 0;
    v47 = (float)(int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v48);
  }
  params->HFReference = v47;
  v46 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](&root, "reflections");
  v3 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v46);
  params->Reflections = (int)v3;
  v44 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](&root, "reflections_delay");
  if ( LOWORD(v44[5].m_object) == 2 )
  {
    v43 = *(float *)&v44->m_object;
  }
  else
  {
    v45 = 0;
    v43 = (float)(int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v44);
  }
  params->ReflectionsDelay = v43;
  v42 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](&root, "reverb");
  v4 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v42);
  params->Reverb = (int)v4;
  v40 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](&root, "reverb_delay");
  if ( LOWORD(v40[5].m_object) == 2 )
  {
    v39 = *(float *)&v40->m_object;
  }
  else
  {
    v41 = 0;
    v39 = (float)(int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v40);
  }
  params->ReverbDelay = v39;
  v38 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](&root, "room");
  v5 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v38);
  params->Room = (int)v5;
  v37 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](&root, "room_hf");
  v6 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v37);
  params->RoomHF = (int)v6;
  v35 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](&root, "room_rolloff_factor");
  if ( LOWORD(v35[5].m_object) == 2 )
  {
    v34 = *(float *)&v35->m_object;
  }
  else
  {
    v36 = 0;
    v34 = (float)(int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v35);
  }
  params->RoomRolloffFactor = v34;
  v32 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](&root, "wet_dry_mix");
  if ( LOWORD(v32[5].m_object) == 2 )
  {
    v31 = *(float *)&v32->m_object;
  }
  else
  {
    v33 = 0;
    v31 = (float)(int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v32);
  }
  params->WetDryMix = v31;
  v30 = model_user_data.sound_scene.m_object;
  scn = (vostok::sound::sound_scene *)model_user_data.sound_scene.m_object;
  v26 = (char **)vostok::configs::binary_config_value::operator[](
                   (vostok::configs::binary_config_value *)model_user_data.config,
                   "sound_environment");
  v29 = 0;
  v28 = *v26;
  name = v28;
  environment_params_id = vostok::sound::sound_scene::get_environment_params_id(scn, v28);
  if ( environment_params_id == -1 )
  {
    v22 = (char **)vostok::configs::binary_config_value::operator[](
                     (vostok::configs::binary_config_value *)model_user_data.config,
                     "sound_environment");
    v25 = 0;
    v24 = *v22;
    v23 = v24;
    vostok::sound::sound_scene::add_environment_params(scn, v24, params, &environment_params_id);
  }
  v72 = 0;
  v21 = (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object;
  v20 = (vostok::sound::sound_environment *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
                                              0x110u);
  v71 = v20;
  if ( v20 )
  {
    vostok::sound::sound_environment::sound_environment(v71, environment_params_id);
    v12 = v7;
  }
  else
  {
    v12 = 0;
  }
  created_resource = v12;
  vostok::sound::sound_scene::insert_environment(scn, v12, transform);
  v8 = vostok::sound::g_allocator.m_object;
  v17 = (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object;
  v19 = 0;
  if ( transform )
  {
    pointer = (void *)transform;
    vostok::memory::doug_lea_allocator::free_impl(v17, (void *)transform);
  }
  v11 = 272;
  v10 = &vostok::resources::nocache_memory;
  v9.m_object = v8;
  v16 = &v9;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v9,
    (vostok::configs::binary_config *)created_resource);
  v15 = data->m_parent_query;
  vostok::resources::query_result_for_cook::set_unmanaged_resource(v15, v9, v10, v11);
  v14 = data->m_parent_query;
  vostok::resources::query_result_for_cook::finish_query(v14, result_success, assert_on_fail_true);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&cfg);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&model_user_data.sound_scene);
}
