void __usercall vostok::resources::resources_manager::resources_thread_tick(
        vostok::resources::resources_manager *this@<ecx>,
        vostok::resources::resources_manager *a2@<eax>,
        double a3@<st0>)
{
  vostok::resources::game_resources_manager *v4; // ecx
  DWORD CurrentThreadId; // eax
  vostok::resources::resources_manager *v6; // ecx
  vostok::resources::thread_local_data *thread_local_data; // eax
  vostok::resources::resources_manager *v8; // ecx
  bool v9; // zf
  vostok::intrusive_list<vostok::resources::queries_result,vostok::resources::queries_result *,36,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v10; // ecx
  vostok::resources::query_result *v11; // eax
  vostok::resources::fs_task *v12; // esi
  vostok::resources::resources_manager *v13; // ecx
  vostok::resources::resources_manager *v14; // ecx
  vostok::resources::resources_manager *v15; // ecx
  vostok::resources::query_result *v16; // ecx
  vostok::resources::fs_task *v17; // eax
  vostok::resources::query_result *v18; // ecx
  vostok::resources::query_result *v19; // ecx
  vostok::resources::resources_manager *v20; // ecx
  vostok::resources::resources_manager *v21; // ecx
  vostok::resources::device_manager **v22; // esi
  vostok::resources::resources_manager *v23; // ecx
  vostok::resources::resources_manager *v24; // ecx
  vostok::resources::resources_manager *v25; // ecx
  LARGE_INTEGER *v26; // esi
  unsigned __int64 v27; // rax
  vostok::timing::timer *LowPart; // ecx
  LARGE_INTEGER v29; // rax
  bool do_init_new_queries_with_unlocked_fat_it; // [esp+Dh] [ebp-1Bh]
  bool has_fs_dispatch_callbacks; // [esp+Eh] [ebp-1Ah]
  bool has_fs_dispatch_callbacksa; // [esp+Eh] [ebp-1Ah]
  bool has_fs_tasks; // [esp+Fh] [ebp-19h]
  vostok::resources::fs_task *fs_sub_tasks; // [esp+10h] [ebp-18h]
  vostok::resources::fs_task *fs_sub_tasksa; // [esp+10h] [ebp-18h]
  vostok::resources::query_result *queries_with_unlocked_fat_it; // [esp+14h] [ebp-14h]
  vostok::resources::query_result *new_inorder_queries; // [esp+18h] [ebp-10h]
  vostok::resources::query_result *queries_with_locked_fat_itb; // [esp+1Ch] [ebp-Ch]
  vostok::resources::query_result *queries_with_locked_fat_it; // [esp+1Ch] [ebp-Ch]
  vostok::resources::query_result *queries_with_locked_fat_ita; // [esp+1Ch] [ebp-Ch]
  LARGE_INTEGER PerformanceCount; // [esp+20h] [ebp-8h] BYREF

  vostok::fs_new::asynchronous_device_interface::dispatch_callbacks(*(vostok::fs_new::asynchronous_device_interface **)((char *)&loc_205F8 + (_DWORD)a2));
  vostok::fs_new::asynchronous_device_interface::dispatch_callbacks(*(vostok::fs_new::asynchronous_device_interface **)((char *)&a2->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_205FB + 1));
  vostok::vfs::virtual_file_system::dispatch_callbacks((vostok::vfs::virtual_file_system *)((char *)&loc_20600
                                                                                          + (_DWORD)a2));
  if ( vostok::resources::g_game_resources_manager.m_initialized )
    vostok::resources::game_resources_manager::tick(v4, vostok::resources::g_game_resources_manager.m_variable, a3);
  if ( *(_DWORD *)((char *)&loc_201B0 + (_DWORD)a2)
    || (do_init_new_queries_with_unlocked_fat_it = 1,
        *(volatile int *)((char *)&a2->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_201B0 + 4)) )
  {
    do_init_new_queries_with_unlocked_fat_it = 0;
  }
  CurrentThreadId = GetCurrentThreadId();
  thread_local_data = vostok::resources::resources_manager::get_thread_local_data(v6, a2, CurrentThreadId, 0);
  if ( !thread_local_data || (has_fs_dispatch_callbacks = 1, !thread_local_data->ready_fs_tasks.m_first) )
    has_fs_dispatch_callbacks = 0;
  has_fs_tasks = *(_DWORD *)((char *)&loc_2053C + (_DWORD)a2) != 0;
  if ( !vostok::intrusive_list<vostok::vfs::vfs_mount,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,20,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy>::empty(&a2->m_vfs.scheduled_to_unmount)
    || *(int *)((char *)&dword_201B8 + (_DWORD)a2)
    || (v8 = *(vostok::resources::resources_manager **)((char *)&a2->m_fs_tasks_execute_on_current_tick
                                                      + (_DWORD)&loc_201B0
                                                      + 4)) != 0
    || (v9 = !has_fs_dispatch_callbacks, has_fs_dispatch_callbacksa = 1, !v9) )
  {
    has_fs_dispatch_callbacksa = 0;
  }
  vostok::resources::resources_manager::init_new_autoselect_quality_queries(v8, (int)a2, a3);
  if ( do_init_new_queries_with_unlocked_fat_it && *(_DWORD *)((char *)&loc_2027C + (_DWORD)a2) )
  {
    vostok::threading::mutex::lock((vostok::threading::mutex *)((char *)&loc_20260 + (_DWORD)a2));
    queries_with_locked_fat_itb = *(vostok::resources::query_result **)((char *)&loc_2027C + (_DWORD)a2);
    *(_DWORD *)((char *)&loc_2027C + (_DWORD)a2) = 0;
    *(volatile int *)((char *)&a2->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_2027E + 2) = 0;
    *(volatile int *)((char *)&a2->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_20257 + 1) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)((char *)&loc_20260 + (_DWORD)a2));
    v11 = queries_with_locked_fat_itb;
  }
  else
  {
    v11 = 0;
  }
  queries_with_unlocked_fat_it = v11;
  if ( *(volatile int *)((char *)&a2->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_2024B + 1) )
  {
    vostok::threading::mutex::lock((vostok::threading::mutex *)((char *)&loc_20230 + (_DWORD)a2));
    queries_with_locked_fat_it = *(vostok::resources::query_result **)((char *)&a2->m_fs_tasks_execute_on_current_tick
                                                                     + (_DWORD)&loc_2024B
                                                                     + 1);
    *(volatile int *)((char *)&a2->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_2024B + 1) = 0;
    *(volatile int *)((char *)&a2->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_2024D + 3) = 0;
    *(volatile int *)((char *)&a2->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_20227 + 1) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)((char *)&loc_20230 + (_DWORD)a2));
    v10 = (vostok::intrusive_list<vostok::resources::queries_result,vostok::resources::queries_result *,36,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)queries_with_locked_fat_it;
  }
  else
  {
    queries_with_locked_fat_it = 0;
  }
  if ( *(volatile int *)((char *)&a2->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_202D9 + 3) )
  {
    vostok::threading::mutex::lock((vostok::threading::mutex *)((char *)&loc_202C0 + (_DWORD)a2));
    new_inorder_queries = *(vostok::resources::query_result **)((char *)&a2->m_fs_tasks_execute_on_current_tick
                                                              + (_DWORD)&loc_202D9
                                                              + 3);
    *(volatile int *)((char *)&a2->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_202D9 + 3) = 0;
    *(volatile int *)((char *)&a2->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_202DE + 2) = 0;
    *(_DWORD *)((char *)&loc_202B8 + (_DWORD)a2) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)((char *)&loc_202C0 + (_DWORD)a2));
  }
  else
  {
    new_inorder_queries = 0;
  }
  if ( *(_DWORD *)((char *)&loc_2056C + (_DWORD)a2) )
  {
    vostok::threading::mutex::lock((vostok::threading::mutex *)((char *)boost::detail::function::functor_manager_common<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::engine::world,bool>,boost::_bi::list2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<bool>>>>::manage_small
                                                              + (_DWORD)a2));
    fs_sub_tasks = *(vostok::resources::fs_task **)((char *)&loc_2056C + (_DWORD)a2);
    *(_DWORD *)((char *)&loc_2056C + (_DWORD)a2) = 0;
    *(volatile int *)((char *)&a2->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_2056C + 4) = 0;
    *(volatile int *)((char *)&a2->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_20546 + 2) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)((char *)boost::detail::function::functor_manager_common<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::engine::world,bool>,boost::_bi::list2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<bool>>>>::manage_small
                                            + (_DWORD)a2));
  }
  else
  {
    fs_sub_tasks = 0;
  }
  if ( (has_fs_dispatch_callbacksa || fs_sub_tasks)
    && (v10 = (vostok::intrusive_list<vostok::resources::queries_result,vostok::resources::queries_result *,36,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)_InterlockedExchange(&a2->m_fs_tasks_execute_on_current_tick, 1),
        has_fs_dispatch_callbacksa) )
  {
    v12 = (vostok::resources::fs_task *)vostok::intrusive_list<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_resource *,232,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
                                          v10,
                                          (int)a2 + (_DWORD)&loc_20517 + 1);
    if ( v12 )
      goto LABEL_33;
  }
  else
  {
    v12 = 0;
  }
  if ( !fs_sub_tasks )
  {
    v10 = (vostok::intrusive_list<vostok::resources::queries_result,vostok::resources::queries_result *,36,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)a2;
    _InterlockedExchange(&a2->m_fs_tasks_execute_on_current_tick, 0);
  }
LABEL_33:
  vostok::resources::resources_manager::delete_delayed_managed_resources(
    (vostok::resources::resources_manager *)v10,
    (int)a2);
  vostok::resources::resources_manager::delete_delayed_unmanaged_resources(v13, a2);
  vostok::resources::resources_manager::deallocate_delayed_unmanaged_resources(v14, a2);
  if ( has_fs_dispatch_callbacksa )
    vostok::resources::resources_manager::execute_fs_tasks(a2, v12);
  vostok::resources::resources_manager::execute_fs_sub_tasks(fs_sub_tasks, v15, a2);
  if ( a2->m_fs_tasks_execute_on_current_tick )
  {
    v16 = (vostok::resources::query_result *)a2;
    _InterlockedExchange(&a2->m_fs_tasks_execute_on_current_tick, 0);
  }
  if ( do_init_new_queries_with_unlocked_fat_it
    && *(_DWORD *)((char *)&loc_202AC + (_DWORD)a2)
    && !a2->m_num_cook_registrators )
  {
    if ( *(_DWORD *)((char *)&loc_202AC + (_DWORD)a2) )
    {
      vostok::threading::mutex::lock((vostok::threading::mutex *)((char *)&loc_20290 + (_DWORD)a2));
      fs_sub_tasksa = *(vostok::resources::fs_task **)((char *)&loc_202AC + (_DWORD)a2);
      *(_DWORD *)((char *)&loc_202AC + (_DWORD)a2) = 0;
      *(volatile int *)((char *)&a2->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_202AF + 1) = 0;
      *(_DWORD *)((char *)&loc_20288 + (_DWORD)a2) = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)((char *)&loc_20290 + (_DWORD)a2));
      v17 = fs_sub_tasksa;
    }
    else
    {
      v17 = 0;
    }
    v16 = queries_with_unlocked_fat_it;
    if ( queries_with_unlocked_fat_it )
      queries_with_unlocked_fat_it->m_next_in_device_manager = (vostok::resources::query_result *)v17;
    else
      queries_with_unlocked_fat_it = (vostok::resources::query_result *)v17;
  }
  vostok::resources::resources_manager::init_new_queries(new_inorder_queries, v16, a2);
  vostok::resources::resources_manager::init_new_queries(queries_with_locked_fat_it, v18, a2);
  if ( do_init_new_queries_with_unlocked_fat_it )
    vostok::resources::resources_manager::init_new_queries(queries_with_unlocked_fat_it, v19, a2);
  vostok::resources::resources_manager::dispatch_callbacks(a2, 0);
  vostok::resources::allocate_functionality::tick(&a2->m_allocate_functionality, &a2->m_allocate_functionality, 0);
  vostok::resources::resources_manager::dispatch_allocated_raw_resources(v20, (int)a2);
  v22 = *(vostok::resources::device_manager ***)((char *)&a2->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_201FF
                                                                                                 + 1);
  for ( queries_with_locked_fat_ita = *(vostok::resources::query_result **)((char *)&loc_20204 + (_DWORD)a2);
        v22 != (vostok::resources::device_manager **)queries_with_locked_fat_ita;
        ++v22 )
  {
    vostok::resources::device_manager::update(*v22);
  }
  vostok::resources::resources_manager::dispatch_created_resources(v21, (int)a2);
  vostok::resources::resources_manager::dispatch_decompressed_resources(v23, (int)a2);
  vostok::resources::resources_manager::save_generated_resources(v24, a2);
  vostok::resources::resources_manager::delete_name_registry_entries(v25, (int)a2);
  v26 = (LARGE_INTEGER *)((char *)nullsub_153 + (_DWORD)a2);
  v27 = 1000 * vostok::timing::timer::get_elapsed_ticks((vostok::timing::timer *)((char *)nullsub_153 + (_DWORD)a2));
  LowPart = (vostok::timing::timer *)vostok::timing::g_qpc_per_second.LowPart;
  if ( (unsigned int)(v27 / vostok::timing::g_qpc_per_second.QuadPart) >= 0x3E8 )
  {
    if ( vostok::timing::g_cpu_supports_time_stamp )
    {
      v29.QuadPart = __rdtsc();
    }
    else
    {
      QueryPerformanceCounter(&PerformanceCount);
      v29 = PerformanceCount;
    }
    v26[1] = v29;
    v26->LowPart = 0;
    v26->HighPart = 0;
  }
  if ( do_init_new_queries_with_unlocked_fat_it && (has_fs_dispatch_callbacksa || !has_fs_tasks) )
  {
    *((_BYTE *)&loc_205E8 + (_DWORD)a2) = 0;
  }
  else
  {
    if ( !*((_BYTE *)&loc_205E8 + (_DWORD)a2) )
    {
      *((_BYTE *)&loc_205E8 + (_DWORD)a2) = 1;
      vostok::timing::timer::start(
        LowPart,
        (LARGE_INTEGER *)((char *)stlp_std::priv::__unguarded_partition<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>
                        + (_DWORD)a2));
    }
    SetEvent(*(HANDLE *)((char *)&dword_203D0 + (_DWORD)a2));
  }
}
