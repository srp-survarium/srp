void __userpurge vostok::resources::query_result::set_creation_source_for_resource(
        vostok::resources::query_result *this@<ecx>,
        int a2@<esi>,
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> resource)
{
  vostok::resources::managed_resource *m_object; // edi

  m_object = resource.m_object;
  m_object->m_creation_source = vostok::resources::query_result::creation_source_for_resource(this, a2);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&resource);
}


void __userpurge vostok::resources::query_result::set_creation_source_for_resource(
        vostok::resources::query_result *this@<ecx>,
        int a2@<esi>,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> resource)
{
  vostok::particle::particle_system_instance_impl *m_object; // ebx
  vostok::particle::particle_system_instance_impl *v4; // edi

  m_object = resource.m_object;
  v4 = resource.m_object;
  v4->m_creation_source = vostok::resources::query_result::creation_source_for_resource(this, a2);
  v4->m_memory_usage_self.vostok::particle::particle_system_instance::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::type = m_object->m_memory_usage_self.vostok::particle::particle_system_instance::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::type;
  v4->m_memory_usage_self.size = m_object->m_memory_usage_self.size;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&resource);
}
