void __usercall vostok::tasks::thread_tls::thread_tls(vostok::tasks::thread_tls *this@<ecx>, int a2@<edi>)
{
  vostok::tasks::task *v2; // ecx
  vostok::threading::event_tasks_unaware *v3; // ecx
  vostok::threading::event_tasks_unaware *v4; // ecx
  vostok::threading::event_tasks_unaware *v5; // ecx

  vostok::threading::event_tasks_unaware::event_tasks_unaware(
    (vostok::threading::event_tasks_unaware *)this,
    (HANDLE *)(a2 + 64));
  *(_DWORD *)(a2 + 72) = 1;
  vostok::tasks::task::task(v2, (_DWORD *)(a2 + 144));
  vostok::threading::event_tasks_unaware::event_tasks_unaware(v3, (HANDLE *)(a2 + 240));
  vostok::threading::event_tasks_unaware::event_tasks_unaware(v4, (HANDLE *)(a2 + 248));
  vostok::threading::event_tasks_unaware::event_tasks_unaware(v5, (HANDLE *)(a2 + 256));
  *(_DWORD *)(a2 + 264) = 0;
  *(_DWORD *)(a2 + 268) = 0;
  *(_DWORD *)(a2 + 272) = 0;
  *(_DWORD *)(a2 + 276) = 0;
  *(_DWORD *)(a2 + 280) = 0;
  *(_DWORD *)(a2 + 284) = 0;
  *(_DWORD *)(a2 + 288) = 0;
  *(_DWORD *)(a2 + 292) = 0;
  *(_DWORD *)(a2 + 296) = a2 + 308;
  *(_DWORD *)(a2 + 300) = a2 + 308;
  *(_DWORD *)(a2 + 304) = a2 + 340;
  *(_BYTE *)(a2 + 308) = 0;
  *(_DWORD *)(a2 + 352) = 0;
}
