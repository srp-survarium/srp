void __userpurge survarium::game_material_manager_cook::on_configs_loaded(
        survarium::game_material_manager_cook *this@<ecx>,
        float a2@<xmm0>,
        vostok::resources::queries_result *data)
{
  vostok::resources::query_result *v3; // eax
  vostok::resources::query_result_for_user *v4; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // eax
  vostok::resources::query_result *v6; // eax
  vostok::resources::query_result_for_user *v7; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v8; // eax
  vostok::resources::unmanaged_resource *v9; // ecx
  survarium::game_material_manager *v10; // eax
  vostok::resources::query_result_for_cook *v11; // eax
  vostok::resources::queries_result *v12; // ecx
  vostok::resources::query_result_for_cook *v13; // eax
  vostok::resources::queries_result *v14; // ecx
  vostok::resources::query_result_for_cook *parent_query; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v16; // ecx
  const vostok::variant<32> **v17; // eax
  vostok::configs::binary_config *v18; // ecx
  vostok::configs::binary_config_value *root; // eax
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v20; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v21; // ecx
  const vostok::variant<32> **v22; // eax
  vostok::configs::binary_config *v23; // ecx
  vostok::configs::binary_config_value *v24; // eax
  vostok::resources::query_result_for_cook *v25; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v26; // [esp-Ch] [ebp-54h] BYREF
  const vostok::resources::memory_type *v27; // [esp-8h] [ebp-50h]
  char *v28; // [esp-4h] [ebp-4Ch]
  unsigned int v29; // [esp+0h] [ebp-48h]
  survarium::game_material_manager *v30; // [esp+4h] [ebp-44h]
  survarium::game_material_manager_cook *thisa; // [esp+8h] [ebp-40h]
  void *_Where; // [esp+18h] [ebp-30h]
  vostok::memory::doug_lea_allocator *f; // [esp+1Ch] [ebp-2Ch]
  survarium::game_material_manager *v34; // [esp+2Ch] [ebp-1Ch]
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v35; // [esp+30h] [ebp-18h] BYREF
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v36; // [esp+34h] [ebp-14h] BYREF
  char v37; // [esp+3Bh] [ebp-Dh]
  survarium::game_material_manager *manager; // [esp+3Ch] [ebp-Ch]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> mtrl_cfg; // [esp+40h] [ebp-8h] BYREF
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> pairs_cfg; // [esp+44h] [ebp-4h] BYREF

  thisa = this;
  v37 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = vostok::resources::queries_result::operator[](data, 0);
  unmanaged_resource = vostok::resources::query_result_for_user::get_unmanaged_resource(
                         v4,
                         (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v3,
                         (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v36);
  vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)unmanaged_resource,
    &mtrl_cfg);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v36);
  v6 = vostok::resources::queries_result::operator[](data, 1u);
  v8 = vostok::resources::query_result_for_user::get_unmanaged_resource(
         v7,
         (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v6,
         (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v35);
  vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)v8,
    &pairs_cfg);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v35);
  f = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(
             (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
             0x140u);
  v34 = (survarium::game_material_manager *)operator new(0x140u, _Where);
  if ( v34 )
  {
    survarium::game_material_manager::game_material_manager(v34);
    v30 = v10;
  }
  else
  {
    v30 = 0;
  }
  manager = v30;
  if ( v30 )
  {
    v28 = (char *)320;
    v27 = &vostok::resources::nocache_memory;
    v26.m_object = v9;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v26,
      (vostok::configs::binary_config *)manager);
    parent_query = vostok::resources::queries_result::get_parent_query(v14, (int)data);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(parent_query, v26, v27, (unsigned int)v28);
    v28 = "materials";
    v17 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v16, (int)&mtrl_cfg);
    root = (vostok::configs::binary_config_value *)vostok::configs::binary_config::get_root(v18, (int)v17);
    v20 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](root, v28);
    survarium::game_material_manager_cook::create_game_materials(thisa, a2, manager, v20);
    v28 = "pairs";
    v22 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v21, (int)&pairs_cfg);
    v24 = (vostok::configs::binary_config_value *)vostok::configs::binary_config::get_root(v23, (int)v22);
    v28 = (char *)vostok::configs::binary_config_value::operator[](v24, v28);
    v27 = (const vostok::resources::memory_type *)manager;
    v25 = vostok::resources::queries_result::get_parent_query((vostok::resources::queries_result *)manager, (int)data);
    survarium::game_material_manager_cook::create_game_material_pairs(
      thisa,
      a2,
      v25,
      (survarium::game_material_manager *const)v27,
      (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v28);
    vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&pairs_cfg);
    vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&mtrl_cfg);
  }
  else
  {
    v11 = vostok::resources::queries_result::get_parent_query((vostok::resources::queries_result *)v9, (int)data);
    vostok::resources::query_result_for_cook::set_out_of_memory(
      (vostok::resources::query_result_for_cook *)&vostok::resources::unmanaged_memory,
      (int)v11,
      (vostok::resources::memory_type *)0x140,
      v29);
    v13 = vostok::resources::queries_result::get_parent_query(v12, (int)data);
    vostok::resources::query_result_for_cook::finish_query(v13, result_out_of_memory, assert_on_fail_true);
    vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&pairs_cfg);
    vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&mtrl_cfg);
  }
}
