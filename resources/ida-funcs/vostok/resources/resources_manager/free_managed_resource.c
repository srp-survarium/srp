void __userpurge vostok::resources::resources_manager::free_managed_resource(
        vostok::resources::managed_resource *resource@<eax>,
        vostok::fixed_string<512> *a2@<ecx>,
        vostok::resources::resources_manager *this)
{
  vostok::resources::class_id_enum m_class_id; // ebx
  vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *v5; // ecx
  vostok::resources::managed_resource *v6; // ecx
  vostok::memory::managed_node *m_node; // ecx
  vostok::memory::doug_lea_allocator *v8; // ecx
  vostok::resources::vfs_sub_fat_resource *m_object; // [esp-4h] [ebp-240h]
  const char *v10; // [esp+0h] [ebp-23Ch]
  const char *v11; // [esp+0h] [ebp-23Ch]
  const char *v12; // [esp+4h] [ebp-238h]
  unsigned int v13; // [esp+8h] [ebp-234h]
  vostok::buffer_string v14[44]; // [esp+10h] [ebp-22Ch] BYREF
  vostok::resources::memory_usage_type memory_usage; // [esp+224h] [ebp-18h] BYREF
  vostok::resources::query_result *destruction_observer; // [esp+22Ch] [ebp-10h]
  char *v17; // [esp+230h] [ebp-Ch]
  vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v18; // [esp+234h] [ebp-8h] BYREF

  m_class_id = resource->m_class_id;
  vostok::fixed_string<512>::fixed_string<512>(a2, v14, (char *)uri);
  m_object = resource->m_sub_fat.m_object;
  memory_usage = resource->m_memory_usage_self;
  destruction_observer = resource->m_destruction_observer;
  vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>(
    v5,
    &v18,
    m_object);
  vostok::resources::managed_resource::set_sub_fat_resource(v6, resource, 0);
  m_node = resource->m_node;
  resource->m_node = 0;
  vostok::memory::managed_allocator::deallocate((vostok::memory::managed_allocator *)m_node);
  v17 = __RTCastToVoid((void **)&resource->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable);
  ((void (__thiscall *)(vostok::resources::managed_resource *, _DWORD))resource->~vostok::resources::resource_base)(
    resource,
    0);
  vostok::memory::doug_lea_allocator::free_impl(
    v8,
    (int)&vostok::memory::g_resources_helper_allocator,
    v17,
    v10,
    v12,
    v13);
  vostok::resources::resources_manager::after_resource_deleted(
    this,
    0,
    0,
    destruction_observer,
    &memory_usage,
    m_class_id,
    v11);
  vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v18);
}
