void __usercall vostok::resources::fs_task_unmount::execute_may_destroy_this(
        vostok::resources::fs_task_unmount *this@<ecx>,
        double a2@<st0>)
{
  vostok::resources::unmanaged_intrusive_base *v3; // ecx
  vostok::resources::vfs_sub_fat_resource *m_object; // edi
  bool v5; // bl
  _BYTE *v6; // edi

  vostok::resources::fs_task_unmount::unmount_children(this, a2, this->m_sub_fat_ptr.m_object->mount_ptr.m_object);
  m_object = this->m_sub_fat_ptr.m_object;
  v5 = (m_object->vostok::resources::unmanaged_resource::vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags.vostok::resources::unmanaged_resource::vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags
      & 1) == 1;
  this->m_sub_fat_ptr.m_object = 0;
  if ( m_object )
  {
    v3 = &m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v3, m_object);
  }
  if ( v5 )
    vostok::resources::game_resources_manager::release_sub_fat(
      vostok::resources::g_game_resources_manager.m_variable,
      m_object,
      (vostok::resources::game_resources_manager *)v3,
      a2);
  v6 = __RTCastToVoid((void **)&this->__vftable);
  ((void (__thiscall *)(vostok::resources::fs_task_unmount *, _DWORD))this->~vostok::resources::fs_task_unmount)(
    this,
    0);
  vostok::memory::g_resources_helper_allocator.call_free(&vostok::memory::g_resources_helper_allocator, v6);
}
