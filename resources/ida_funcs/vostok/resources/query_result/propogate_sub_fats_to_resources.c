void __usercall vostok::resources::query_result::propogate_sub_fats_to_resources(
        vostok::resources::query_result *this@<ecx>,
        vostok::resources::query_result *a2@<edi>)
{
  vostok::resources::query_result::propogate_sub_fats_to_resource<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>(
    &a2->m_managed_resource,
    a2);
  vostok::resources::query_result::propogate_sub_fats_to_resource<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>(
    &a2->m_raw_managed_resource,
    a2);
  vostok::resources::query_result::propogate_sub_fats_to_resource<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>(
    &a2->m_compressed_resource,
    a2);
  vostok::resources::query_result::propogate_sub_fats_to_resource<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>(
    &a2->m_unmanaged_resource,
    a2);
}
