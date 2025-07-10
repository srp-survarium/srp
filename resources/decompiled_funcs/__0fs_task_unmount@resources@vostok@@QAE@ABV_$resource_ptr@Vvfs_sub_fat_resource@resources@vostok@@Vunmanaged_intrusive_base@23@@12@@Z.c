void __userpurge vostok::resources::fs_task_unmount::fs_task_unmount(
        vostok::resources::fs_task_unmount *this@<ecx>,
        int a2@<esi>,
        const vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *sub_fat_ptr)
{
  vostok::resources::vfs_sub_fat_resource *m_object; // eax

  *(_DWORD *)a2 = &vostok::resources::fs_task::`vftable';
  *(_DWORD *)(a2 + 4) = 0;
  *(_BYTE *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 5;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = GetCurrentThreadId();
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)a2 = &vostok::resources::fs_task_unmount::`vftable';
  *(_DWORD *)(a2 + 32) = 0;
  m_object = sub_fat_ptr->m_object;
  if ( sub_fat_ptr->m_object )
  {
    *(_DWORD *)(a2 + 32) = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  *(_DWORD *)(a2 + 36) = 0;
}
