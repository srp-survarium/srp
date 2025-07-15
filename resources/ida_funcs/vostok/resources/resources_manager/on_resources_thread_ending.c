void __usercall vostok::resources::resources_manager::on_resources_thread_ending(
        vostok::resources::resources_manager *this@<ecx>,
        vostok::resources::resources_manager *a2@<eax>,
        double a3@<st0>)
{
  vostok::resources::fs_task_unmount *m_object; // eax
  vostok::resources::fs_task_unmount *v5; // eax
  vostok::resources::resources_manager *v6; // ecx
  vostok::resources::resources_manager *v7; // ecx
  vostok::resources::intrusive_fs_task_unmount_base *v8; // [esp+0h] [ebp-4h]

  m_object = a2->m_mounts_ptr.m_object;
  a2->m_mounts_ptr.m_object = 0;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::intrusive_fs_task_unmount_base::destroy(v8, m_object);
  v5 = a2->m_mounts_converted_ptr.m_object;
  a2->m_mounts_converted_ptr.m_object = 0;
  if ( v5 && !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::intrusive_fs_task_unmount_base::destroy(v8, v5);
  vostok::resources::finilize_game_resources_manager();
  while ( !vostok::resources::resources_manager::thread_can_exit(v6, a2) || *(_DWORD *)((char *)&loc_2053C + (_DWORD)a2) )
    vostok::resources::resources_manager::resources_thread_tick(v7, a2, a3);
}
