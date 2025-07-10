void __usercall __noreturn vostok::engine::engine_world::finalize_resources(
        vostok::engine::engine_world *this@<ecx>,
        _DWORD *a2@<eax>)
{
  vostok::resources::fs_task_unmount *v3; // eax
  vostok::resources::fs_task_unmount *v4; // eax
  vostok::resources::fs_task_unmount *v5; // eax
  vostok::resources::intrusive_fs_task_unmount_base *v6; // [esp+0h] [ebp-84h]

  v3 = (vostok::resources::fs_task_unmount *)a2[165];
  a2[165] = 0;
  if ( v3 && !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::intrusive_fs_task_unmount_base::destroy(v3, v6);
  v4 = (vostok::resources::fs_task_unmount *)a2[166];
  a2[166] = 0;
  if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::intrusive_fs_task_unmount_base::destroy(v4, v6);
  v5 = (vostok::resources::fs_task_unmount *)a2[167];
  a2[167] = 0;
  if ( v5 )
  {
    if ( !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::intrusive_fs_task_unmount_base::destroy(v5, v6);
  }
  vostok::debug::terminate((char *)&buf, 0);
}
