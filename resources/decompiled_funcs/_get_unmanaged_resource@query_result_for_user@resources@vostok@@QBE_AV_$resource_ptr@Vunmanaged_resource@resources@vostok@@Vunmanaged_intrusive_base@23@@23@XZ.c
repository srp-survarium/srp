vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *__usercall vostok::resources::query_result_for_user::get_unmanaged_resource@<eax>(
        vostok::resources::query_result_for_user *this@<ecx>,
        const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *a2@<eax>,
        vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *a3@<esi>)
{
  a3->m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    a3,
    a2 + 55);
  return a3;
}
