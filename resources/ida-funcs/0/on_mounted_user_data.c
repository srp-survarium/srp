void __cdecl on_mounted_user_data(
        vostok::resources::intrusive_fs_task_unmount_base *out_mount,
        vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> result)
{
  vostok::resources::fs_task_unmount *m_object; // ecx
  vostok::resources::fs_task_unmount *m_reference_count; // eax
  vostok::resources::intrusive_fs_task_unmount_base *v4; // [esp+0h] [ebp-4h]

  if ( !result.m_object )
    vostok::debug::terminate("Cannot mount user_data folder. Please reinstall an application and try again.");
  _InterlockedExchangeAdd(&result.m_object->m_reference_count, 1u);
  m_object = result.m_object;
  m_reference_count = (vostok::resources::fs_task_unmount *)out_mount->m_reference_count;
  out_mount->m_reference_count = (volatile int)result.m_object;
  if ( m_reference_count )
  {
    if ( !_InterlockedExchangeAdd(&m_reference_count->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::intrusive_fs_task_unmount_base::destroy(m_reference_count, v4);
    m_object = result.m_object;
  }
  if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::intrusive_fs_task_unmount_base::destroy(result.m_object, out_mount);
}
