void __thiscall vostok::resources::query_result::~query_result(vostok::resources::query_result *this)
{
  vostok::vfs::base_node<1> *v2; // eax
  char *m_request_path; // eax

  this->__vftable = (vostok::resources::query_result_vtbl *)&vostok::resources::query_result::`vftable';
  vostok::resources::query_result::clear_reference(this);
  if ( (this->m_flags & 0x800) != 0 )
  {
    v2 = vostok::vfs::node_cast<vostok::vfs::physical_file_mount_root_node,vostok::vfs::base_node,1>(this->m_fat_it.m_node);
    ((void (__thiscall *)(vostok::vfs::base_node<1> *, vostok::vfs::base_node<1> *, const char *, const char *, int))v2->m_next_overlapped.pointer->m_mount_root.pointer->async_device.pointer)(
      v2->m_next_overlapped.pointer,
      v2,
      "vostok::vfs::destroy_temp_physical_node",
      ".\\virtual_file_system.cpp",
      562);
    this->m_fat_it.m_hashset = 0;
    this->m_fat_it.m_node = 0;
    this->m_fat_it.m_link_target = 0;
    this->m_fat_it.m_type = type_number;
    _InterlockedAnd(&this->m_flags, 0xFFFFF7FF);
  }
  if ( (this->m_flags & 0x400) != 0 )
  {
    m_request_path = this->m_request_path;
    if ( m_request_path )
    {
      this->m_user_allocator->call_free(
        this->m_user_allocator,
        m_request_path,
        "vostok::resources::query_result::~query_result",
        ".\\resources_query_result_finalization.cpp",
        345u);
      this->m_request_path = 0;
    }
    _InterlockedAnd(&this->m_flags, 0xFFFFFBFF);
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_raw_managed_resource);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_compressed_resource);
  vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_sub_fat);
  vostok::resources::query_result_for_cook::~query_result_for_cook(this);
}
