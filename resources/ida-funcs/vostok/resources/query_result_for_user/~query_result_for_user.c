void __thiscall vostok::resources::query_result_for_user::~query_result_for_user(
        vostok::resources::query_result_for_user *this)
{
  void *deallocation_address; // [esp+Ch] [ebp-4h] BYREF

  this->__vftable = (vostok::resources::query_result_for_user_vtbl *)&vostok::resources::query_result_for_user::`vftable';
  if ( this->m_requery_path )
  {
    deallocation_address = this->m_requery_path;
    if ( vostok::memory::g_mt_allocator.m_use_memory_monitor )
      vostok::memory::monitor::on_free(&deallocation_address, (vostok::command_line::key *)this);
    pt3free((int)this, (char *)deallocation_address);
    this->m_requery_path = 0;
  }
  if ( this->m_mount1_path )
  {
    deallocation_address = this->m_mount1_path;
    if ( vostok::memory::g_mt_allocator.m_use_memory_monitor )
      vostok::memory::monitor::on_free(&deallocation_address, (vostok::command_line::key *)this);
    pt3free((int)this, (char *)deallocation_address);
    this->m_mount1_path = 0;
  }
  if ( this->m_mount2_path )
  {
    deallocation_address = this->m_mount2_path;
    if ( vostok::memory::g_mt_allocator.m_use_memory_monitor )
      vostok::memory::monitor::on_free(&deallocation_address, (vostok::command_line::key *)this);
    pt3free((int)this, (char *)deallocation_address);
    this->m_mount2_path = 0;
  }
  vostok::vfs::vfs_locked_iterator::clear((vostok::vfs::vfs_locked_iterator *)this, (int)&this->m_result_iterator);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_unmanaged_resource);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_managed_resource);
  vostok::resources::resource_base::~resource_base(this);
}
