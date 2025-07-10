void __usercall vostok::resources::resources_manager::save_generated_resources(
        vostok::resources::resources_manager *this@<ecx>,
        vostok::resources::resources_manager *a2@<esi>)
{
  vostok::resources::query_result *v2; // ebx
  vostok::resources::resources_manager *v3; // ecx
  vostok::resources::query_result *i; // edi

  if ( *(volatile int *)((char *)&a2->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_20471 + 3) )
  {
    vostok::threading::mutex::lock((vostok::threading::mutex *)((char *)a2 + (_DWORD)&loc_20456 + 2));
    v2 = *(vostok::resources::query_result **)((char *)&a2->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_20471 + 3);
    *(volatile int *)((char *)&a2->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_20471 + 3) = 0;
    *(_DWORD *)((char *)&loc_20478 + (_DWORD)a2) = 0;
    *(volatile int *)((char *)&a2->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_2044D + 3) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)((char *)a2 + (_DWORD)&loc_20456 + 2));
    for ( i = v2; i; i = i->m_next_in_device_manager )
      vostok::resources::resources_manager::save_generated_resource(i, v3, a2);
  }
}
