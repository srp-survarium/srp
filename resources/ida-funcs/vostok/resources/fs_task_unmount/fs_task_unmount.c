void __userpurge vostok::resources::fs_task_unmount::fs_task_unmount(
        vostok::resources::fs_task_unmount *this@<ecx>,
        int a2@<eax>,
        const vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *sub_fat_ptr)
{
  vostok::resources::vfs_sub_fat_resource *m_object; // eax

  vostok::resources::fs_task::fs_task((vostok::resources::fs_task *)a2, type_unmount, 0, 0);
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)a2 = &vostok::resources::fs_task_unmount::`vftable';
  *(_DWORD *)(a2 + 32) = 0;
  if ( sub_fat_ptr->m_object )
  {
    vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 32));
    m_object = sub_fat_ptr->m_object;
    *(vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *)(a2 + 32) = (vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>)sub_fat_ptr->m_object;
    if ( m_object )
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  *(_DWORD *)(a2 + 36) = 0;
}
