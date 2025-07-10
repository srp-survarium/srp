void __userpurge vostok::resources::managed_resource::managed_resource(
        vostok::resources::managed_resource *this@<esi>,
        vostok::resources::class_id_enum class_id@<eax>,
        unsigned int a3@<ecx>,
        unsigned int size)
{
  vostok::resources::resource_base::resource_base((vostok::resources::resource_base *)1, (int)this, class_id, 1u, a3);
  this->m_reference_count = 0;
  this->vostok::resources::managed_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags.vostok::resources::managed_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags = 0;
  this->m_node = 0;
  this->vostok::memory::managed_node_owner::__vftable = (vostok::memory::managed_node_owner_vtbl *)&vostok::memory::managed_node_owner::`vftable';
  this->m_allocator = &vostok::memory::g_resources_managed_allocator;
  this->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::managed_resource_vtbl *)&vostok::resources::managed_resource::`vftable'{for `vostok::resources::resource_base'};
  this->vostok::memory::managed_node_owner::__vftable = (vostok::memory::managed_node_owner_vtbl *)&vostok::resources::managed_resource::`vftable'{for `vostok::memory::managed_node_owner'};
  this->m_sub_fat.m_object = 0;
  this->m_sub_fat.m_parent = 0;
  this->m_next_delay_delete = 0;
  this->m_memory_usage_self.vostok::resources::resource_base::vostok::resources::resource_quality::type = &vostok::resources::managed_memory;
  this->m_memory_usage_self.size = size;
}
