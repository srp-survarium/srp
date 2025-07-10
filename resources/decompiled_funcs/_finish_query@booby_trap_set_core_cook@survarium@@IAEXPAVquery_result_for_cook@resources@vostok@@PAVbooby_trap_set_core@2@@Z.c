void __thiscall survarium::booby_trap_set_core_cook::finish_query(
        survarium::booby_trap_set_core_cook *this,
        vostok::resources::query_result_for_cook *parent,
        vostok::configs::binary_config *resource)
{
  vostok::network_core::packet_reader *v3; // eax
  vostok::resources::memory_usage_type *v4; // eax
  vostok::resources::unmanaged_resource *v5; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v6; // [esp-4h] [ebp-1Ch] BYREF
  vostok::resources::memory_usage_type *memory_usage; // [esp+0h] [ebp-18h]
  survarium::booby_trap_set_core_cook *thisa; // [esp+4h] [ebp-14h]
  boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *v9; // [esp+10h] [ebp-8h] BYREF

  thisa = this;
  v3 = (vostok::network_core::packet_reader *)this->get_derived_resource_size(this);
  vostok::resources::memory_usage_type::memory_usage_type(
    (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *)&vostok::resources::nocache_memory,
    &v9,
    v3,
    (vostok::network_core::packet_reader *)memory_usage);
  memory_usage = v4;
  v6.m_object = v5;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v6,
    resource);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(memory_usage, parent, v6);
  vostok::resources::query_result_for_cook::finish_query(parent, result_success, assert_on_fail_true);
}
