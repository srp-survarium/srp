void __thiscall vostok::resources::resources_manager::dispatch_callbacks(
        vostok::resources::resources_manager *this,
        BOOL finalizing_thread)
{
  char CurrentThreadId; // si
  vostok::resources::resources_manager *v4; // ecx
  vostok::resources::resources_manager *v5; // ecx
  vostok::resources::resources_manager *v6; // ecx
  vostok::resources::thread_local_data *thread_local_data; // eax
  vostok::resources::query_result *v8; // ecx
  int v9; // edi
  int v10; // eax
  int v11; // esi
  vostok::resources::fs_task *v12; // eax
  vostok::resources::resources_manager *v13; // esi
  vostok::resources::query_result *v14; // ecx
  vostok::resources::query_result *v15; // eax
  vostok::intrusive_list<vostok::resources::queries_result,vostok::resources::queries_result *,36,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v16; // ecx
  vostok::resources::queries_result *v17; // eax
  vostok::resources::queries_result *v18; // ecx
  const vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v19; // [esp+0h] [ebp-18h]
  bool v20; // [esp+0h] [ebp-18h]
  vostok::resources::resources_manager *v21; // [esp+0h] [ebp-18h]
  bool v22; // [esp+4h] [ebp-14h]
  int v23; // [esp+10h] [ebp-8h]
  vostok::resources::query_result *it_querya; // [esp+14h] [ebp-4h]
  vostok::resources::query_result *it_queryb; // [esp+14h] [ebp-4h]

  CurrentThreadId = GetCurrentThreadId();
  vostok::fs_new::asynchronous_device_interface::dispatch_callbacks(*(vostok::fs_new::asynchronous_device_interface **)((char *)&loc_205F8 + (_DWORD)this));
  vostok::fs_new::asynchronous_device_interface::dispatch_callbacks(*(vostok::fs_new::asynchronous_device_interface **)((char *)&this->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_205FB + 1));
  vostok::resources::resources_manager::delete_delayed_unmanaged_resources(v4);
  vostok::resources::resources_manager::deallocate_delayed_unmanaged_resources(v5);
  thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                        v6,
                        (unsigned int)this,
                        CurrentThreadId);
  v9 = (int)thread_local_data;
  if ( thread_local_data )
  {
    thread_local_data->dispatching_callbacks = 1;
    if ( thread_local_data->to_translate_query.m_first )
    {
      vostok::threading::mutex::lock(&thread_local_data->to_translate_query.vostok::threading::mutex);
      v23 = *(_DWORD *)(v9 + 276);
      *(_DWORD *)(v9 + 276) = 0;
      *(_DWORD *)(v9 + 280) = 0;
      *(_DWORD *)(v9 + 240) = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)(v9 + 248));
      v10 = v23;
    }
    else
    {
      v10 = 0;
    }
    if ( v10 )
    {
      do
      {
        v11 = *(_DWORD *)(v10 + 608);
        vostok::resources::query_result::translate_query_if_needed(v8);
        v10 = v11;
      }
      while ( v11 );
    }
    v12 = (vostok::resources::fs_task *)vostok::intrusive_list<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_resource *,232,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
                                          (vostok::intrusive_list<vostok::resources::queries_result,vostok::resources::queries_result *,36,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)v8,
                                          v9 + 48);
    v13 = (vostok::resources::resources_manager *)finalizing_thread;
    if ( v12 )
      vostok::resources::resources_manager::dispatch_fs_tasks_callbacks(v12, finalizing_thread);
    vostok::resources::allocate_functionality::tick(&this->m_allocate_functionality, (_BYTE)this + 40);
    if ( *(_DWORD *)(v9 + 132) )
    {
      vostok::threading::mutex::lock((vostok::threading::mutex *)(v9 + 104));
      it_querya = *(vostok::resources::query_result **)(v9 + 132);
      *(_DWORD *)(v9 + 132) = 0;
      *(_DWORD *)(v9 + 136) = 0;
      *(_DWORD *)(v9 + 96) = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)(v9 + 104));
      v15 = it_querya;
      v13 = (vostok::resources::resources_manager *)finalizing_thread;
    }
    else
    {
      v15 = 0;
    }
    vostok::resources::resources_manager::create_resources<vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>(
      v15,
      v14,
      v13,
      v19,
      v22);
    v17 = vostok::intrusive_list<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_resource *,232,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
            v16,
            v9);
    vostok::resources::resources_manager::dispatch_query_callbacks(v17, v18, v13, v20);
    if ( *(_DWORD *)(v9 + 524) )
    {
      vostok::threading::mutex::lock((vostok::threading::mutex *)(v9 + 496));
      it_queryb = *(vostok::resources::query_result **)(v9 + 524);
      *(_DWORD *)(v9 + 524) = 0;
      *(_DWORD *)(v9 + 528) = 0;
      *(_DWORD *)(v9 + 488) = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)(v9 + 496));
      vostok::resources::resources_manager::dispatch_tasks_finished_callback(it_queryb, v21);
    }
    else
    {
      vostok::resources::resources_manager::dispatch_tasks_finished_callback(0, v21);
    }
    *(_BYTE *)(v9 + 548) = 0;
  }
}
