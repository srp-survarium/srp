void __thiscall vostok::ai::behaviour_cook::finish_creation(
        vostok::ai::behaviour_cook *this,
        vostok::resources::query_result_for_cook *const parent,
        vostok::configs::binary_config *new_behaviour)
{
  vostok::resources::memory_usage_type *v3; // eax
  vostok::resources::unmanaged_resource *v4; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v5[2]; // [esp-4h] [ebp-30h] BYREF
  vostok::resources::memory_usage_type *memory_usage; // [esp+4h] [ebp-28h]
  vostok::ai::behaviour_cook *thisa; // [esp+8h] [ebp-24h]
  boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *v8; // [esp+24h] [ebp-8h] BYREF

  thisa = this;
  vostok::resources::memory_usage_type::memory_usage_type(
    (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *)&vostok::resources::nocache_memory,
    &v8,
    (vostok::network_core::packet_reader *)0x268,
    (vostok::network_core::packet_reader *)v5[1].m_object);
  memory_usage = v3;
  v5[0].m_object = v4;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    v5,
    new_behaviour);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(memory_usage, parent, v5[0]);
  vostok::resources::query_result_for_cook::finish_query(parent, result_success, assert_on_fail_true);
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
    &thisa->m_loaded_binary_config,
    0);
}
