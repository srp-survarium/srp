void __userpurge vostok::resources::thread_local_data::thread_local_data(
        vostok::resources::thread_local_data *this@<ecx>,
        int a2@<edi>,
        unsigned int thread_id,
        vostok::memory::base_allocator *allocator)
{
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v4; // ecx
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v5; // ecx
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v6; // ecx
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v7; // ecx
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v8; // ecx
  vostok::threading::mutex_tasks_unaware *v9; // ecx
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v10; // ecx
  vostok::threading::mutex_tasks_unaware *v11; // ecx
  vostok::threading::mutex_tasks_unaware *v12; // ecx
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v13; // ecx

  *(_DWORD *)a2 = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    (vostok::threading::mutex_tasks_unaware *)this,
    (_RTL_CRITICAL_SECTION *)(a2 + 8));
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
    v4,
    a2 + 48);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
    v5,
    a2 + 96);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
    v6,
    a2 + 144);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
    v7,
    a2 + 192);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
    v8,
    a2 + 240);
  *(_DWORD *)(a2 + 288) = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(v9, (_RTL_CRITICAL_SECTION *)(a2 + 296));
  *(_DWORD *)(a2 + 324) = 0;
  *(_DWORD *)(a2 + 328) = 0;
  *(_BYTE *)(a2 + 336) = 0;
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
    v10,
    a2 + 344);
  *(_DWORD *)(a2 + 392) = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(v11, (_RTL_CRITICAL_SECTION *)(a2 + 400));
  *(_DWORD *)(a2 + 428) = 0;
  *(_DWORD *)(a2 + 432) = 0;
  *(_DWORD *)(a2 + 440) = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(v12, (_RTL_CRITICAL_SECTION *)(a2 + 448));
  *(_DWORD *)(a2 + 476) = 0;
  *(_DWORD *)(a2 + 480) = 0;
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
    v13,
    a2 + 488);
  *(_DWORD *)(a2 + 536) = 0;
  *(_DWORD *)(a2 + 540) = 0;
  *(_DWORD *)(a2 + 544) = 0;
  *(_BYTE *)(a2 + 548) = 0;
  *(_DWORD *)(a2 + 552) = 0;
  *(_DWORD *)(a2 + 556) = 0;
  *(_BYTE *)(a2 + 572) = 0;
  *(_DWORD *)(a2 + 560) = a2 + 572;
  *(_DWORD *)(a2 + 564) = a2 + 572;
  *(_DWORD *)(a2 + 568) = a2 + 604;
  *(_DWORD *)(a2 + 604) = allocator;
  *(_DWORD *)(a2 + 608) = thread_id;
  *(_DWORD *)(a2 + 612) = 0;
  *(_DWORD *)(a2 + 616) = 0;
  *(_DWORD *)(a2 + 620) = 0;
}
