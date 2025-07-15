void __thiscall vostok::resources::fs_task_unmount::execute_may_destroy_this(vostok::resources::fs_task_unmount *this)
{
  int *p_m_sub_fat_ptr; // esi
  vostok::resources::vfs_sub_fat_resource *v3; // edi
  bool v4; // bl
  vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *v5; // ecx
  vostok::resources::game_resources_manager *v6; // ecx
  _BYTE *v7; // esi

  p_m_sub_fat_ptr = (int *)&this->m_sub_fat_ptr;
  vostok::resources::fs_task_unmount::unmount_children(this, this->m_sub_fat_ptr.m_object->mount_ptr.m_object);
  v3 = (vostok::resources::vfs_sub_fat_resource *)*p_m_sub_fat_ptr;
  v4 = (*(_DWORD *)(*p_m_sub_fat_ptr + 212) & 1) == 1;
  vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    v5,
    p_m_sub_fat_ptr,
    0);
  if ( v4 )
    vostok::resources::game_resources_manager::release_sub_fat(
      vostok::resources::g_game_resources_manager.m_variable,
      v3,
      v6);
  v7 = __RTCastToVoid((void **)&this->__vftable);
  ((void (__thiscall *)(vostok::resources::fs_task_unmount *, _DWORD))this->~vostok::resources::fs_task_unmount)(
    this,
    0);
  vostok::memory::g_resources_helper_allocator.call_free(
    &vostok::memory::g_resources_helper_allocator,
    v7,
    "vostok::resources::fs_task_unmount::execute_may_destroy_this",
    ".\\resources_mount_ptr.cpp",
    84u);
}
