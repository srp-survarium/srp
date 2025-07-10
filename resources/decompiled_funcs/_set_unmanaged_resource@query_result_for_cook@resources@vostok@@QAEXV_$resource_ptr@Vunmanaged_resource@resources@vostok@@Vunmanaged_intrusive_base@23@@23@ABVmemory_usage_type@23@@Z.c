void __userpurge vostok::resources::query_result_for_cook::set_unmanaged_resource(
        const vostok::resources::memory_usage_type *memory_usage@<eax>,
        vostok::resources::query_result_for_cook *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> ptr)
{
  const vostok::resources::memory_type *type; // edx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v4; // [esp-Ch] [ebp-Ch] BYREF
  const vostok::resources::memory_type *v5; // [esp-8h] [ebp-8h]
  unsigned int size; // [esp-4h] [ebp-4h]

  type = memory_usage->type;
  size = memory_usage->size;
  v5 = type;
  v4.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v4,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&ptr);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    this,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v4.m_object,
    v5,
    size);
  if ( ptr.m_object )
  {
    if ( !_InterlockedExchangeAdd(&ptr.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &ptr.m_object->vostok::resources::unmanaged_intrusive_base,
        ptr.m_object);
  }
}
