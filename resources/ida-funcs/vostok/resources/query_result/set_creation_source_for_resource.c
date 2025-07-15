void __userpurge vostok::resources::query_result::set_creation_source_for_resource(
        vostok::resources::query_result *this@<ecx>,
        int a2@<esi>,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> resource)
{
  vostok::resources::managed_resource *m_object; // edi

  m_object = resource.m_object;
  m_object->m_creation_source = vostok::resources::query_result::creation_source_for_resource(this, a2);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&resource);
}


void __userpurge vostok::resources::query_result::set_creation_source_for_resource(
        vostok::resources::query_result *this@<ecx>,
        int a2@<esi>,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> resource)
{
  resource.m_object->m_creation_source = vostok::resources::query_result::creation_source_for_resource(this, a2);
  resource.m_object->m_memory_usage_self.type = resource.m_object->m_memory_usage_self.type;
  resource.m_object->m_memory_usage_self.size = resource.m_object->m_memory_usage_self.size;
  if ( resource.m_object )
  {
    if ( !_InterlockedExchangeAdd(&resource.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &resource.m_object->vostok::resources::unmanaged_intrusive_base,
        resource.m_object);
  }
}
