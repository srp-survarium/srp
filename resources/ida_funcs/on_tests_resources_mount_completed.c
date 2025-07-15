void __usercall on_tests_resources_mount_completed(
        vostok::resources::intrusive_fs_task_unmount_base *a1@<esi>,
        bool *out_completed,
        vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *out_mount,
        vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> result)
{
  vostok::resources::fs_task_unmount *m_object; // ecx
  vostok::resources::fs_task_unmount *v5; // eax
  vostok::resources::fs_task_unmount *v6; // edx
  vostok::resources::fs_task_unmount *v7; // eax
  vostok::resources::intrusive_fs_task_unmount_base *v8; // [esp-8h] [ebp-8h]

  m_object = result.m_object;
  *out_completed = 1;
  v5 = 0;
  v8 = a1;
  if ( result.m_object )
  {
    v5 = result.m_object;
    _InterlockedExchangeAdd(&result.m_object->m_reference_count, 1u);
    m_object = result.m_object;
  }
  v6 = v5;
  v7 = out_mount->m_object;
  out_mount->m_object = v6;
  if ( v7 )
  {
    if ( !_InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::intrusive_fs_task_unmount_base::destroy(v7, a1);
    m_object = result.m_object;
  }
  if ( m_object )
  {
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::intrusive_fs_task_unmount_base::destroy(result.m_object, v8);
  }
}
