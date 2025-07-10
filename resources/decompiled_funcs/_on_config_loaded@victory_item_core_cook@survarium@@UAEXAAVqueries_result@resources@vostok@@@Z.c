void __thiscall survarium::victory_item_core_cook::on_config_loaded(
        survarium::victory_item_core_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::resources::query_result *v2; // eax
  vostok::resources::query_result_for_user *v3; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  const vostok::variant<32> **v6; // eax
  vostok::configs::binary_config *v7; // ecx
  const vostok::configs::binary_config_value *root; // eax
  vostok::resources::memory_usage_type *v9; // eax
  vostok::resources::unmanaged_resource *v10; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v11[2]; // [esp-4h] [ebp-3Ch] BYREF
  vostok::resources::memory_usage_type *memory_usage; // [esp+4h] [ebp-34h]
  vostok::resources::unmanaged_resource *object; // [esp+8h] [ebp-30h]
  survarium::victory_item_core_cook *thisa; // [esp+Ch] [ebp-2Ch]
  boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *v15; // [esp+20h] [ebp-18h] BYREF
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v16; // [esp+28h] [ebp-10h] BYREF
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> cfg; // [esp+2Ch] [ebp-Ch] BYREF
  survarium::victory_item_core *object_to_cook; // [esp+30h] [ebp-8h]
  vostok::resources::query_result_for_cook *parent; // [esp+34h] [ebp-4h]

  thisa = this;
  parent = vostok::resources::queries_result::get_parent_query((vostok::resources::queries_result *)this, (int)data);
  v2 = vostok::resources::queries_result::operator[](data, 0);
  unmanaged_resource = vostok::resources::query_result_for_user::get_unmanaged_resource(
                         v3,
                         (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v2,
                         (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v16);
  vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)unmanaged_resource,
    &cfg);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v16);
  object_to_cook = thisa->create_resource(thisa);
  v6 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v5, (int)&cfg);
  root = vostok::configs::binary_config::get_root(v7, (int)v6);
  object_to_cook->load(object_to_cook, root);
  if ( object_to_cook )
    object = &object_to_cook->vostok::resources::unmanaged_resource;
  else
    object = 0;
  vostok::resources::memory_usage_type::memory_usage_type(
    (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *)&vostok::resources::nocache_memory,
    &v15,
    (vostok::network_core::packet_reader *)0x178,
    (vostok::network_core::packet_reader *)v11[1].m_object);
  memory_usage = v9;
  v11[0].m_object = v10;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    v11,
    (vostok::configs::binary_config *)object);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(memory_usage, parent, v11[0]);
  vostok::resources::query_result_for_cook::finish_query(parent, result_success, assert_on_fail_true);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&cfg);
}
