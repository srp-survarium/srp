void __thiscall survarium::booby_trap_core_cook::on_subresources_loaded(
        survarium::booby_trap_core_cook *this,
        vostok::resources::queries_result *data,
        vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config)
{
  survarium::game_camera *v3; // ecx
  vostok::resources::query_result *v4; // eax
  vostok::resources::query_result_for_user *v5; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v7; // ecx
  const vostok::variant<32> **v8; // eax
  vostok::configs::binary_config *v9; // ecx
  vostok::configs::binary_config_value *root; // eax
  const vostok::configs::binary_config_value *v11; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v12; // ecx
  const vostok::variant<32> **v13; // eax
  vostok::configs::binary_config *v14; // ecx
  const vostok::configs::binary_config_value *v15; // eax
  vostok::configs::binary_config *v16; // ecx
  vostok::resources::queries_result *v17; // ecx
  vostok::resources::query_result_for_cook *parent_query; // eax
  survarium::booby_trap_core *v19; // [esp-8h] [ebp-2Ch]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> v20; // [esp-4h] [ebp-28h] BYREF
  survarium::booby_trap_core_cook *thisa; // [esp+4h] [ebp-20h]
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v22; // [esp+14h] [ebp-10h] BYREF
  char v23; // [esp+1Ah] [ebp-Ah]
  char v24; // [esp+1Bh] [ebp-9h]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> aabb; // [esp+1Ch] [ebp-8h] BYREF
  survarium::booby_trap_core *resource; // [esp+20h] [ebp-4h]

  thisa = this;
  v24 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v23 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  v4 = vostok::resources::queries_result::operator[](data, 0);
  unmanaged_resource = vostok::resources::query_result_for_user::get_unmanaged_resource(
                         v5,
                         (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v4,
                         (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v22);
  vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)unmanaged_resource,
    &aabb);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v22);
  resource = thisa->new_derived_resource(thisa);
  v8 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v7, (int)&config);
  root = (vostok::configs::binary_config_value *)vostok::configs::binary_config::get_root(v9, (int)v8);
  v11 = vostok::configs::binary_config_value::operator[](root, "data");
  resource->load(&resource->survarium::collision_sensor, v11);
  v13 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v12, (int)&aabb);
  v15 = vostok::configs::binary_config::get_root(v14, (int)v13);
  survarium::booby_trap_core::load_aabb(resource, v15);
  v20.m_object = v16;
  boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
    &v20,
    &config);
  v19 = resource;
  parent_query = vostok::resources::queries_result::get_parent_query(v17, (int)data);
  ((void (__thiscall *)(survarium::booby_trap_core_cook *, vostok::resources::query_result_for_cook *, survarium::booby_trap_core *, vostok::configs::binary_config *))thisa->query_for_derived_resources)(
    thisa,
    parent_query,
    v19,
    v20.m_object);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&aabb);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&config);
}
