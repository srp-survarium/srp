void __usercall vostok::resources::game_resources_manager::game_resources_manager(
        vostok::resources::game_resources_manager *this@<ecx>,
        int a2@<edi>)
{
  vostok::threading::mutex_tasks_unaware *v2; // ecx
  vostok::threading::mutex_tasks_unaware *v3; // ecx
  vostok::timing::timer *v4; // ecx
  vostok::timing::timer *v5; // ecx

  *(_DWORD *)a2 = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    (vostok::threading::mutex_tasks_unaware *)this,
    (_RTL_CRITICAL_SECTION *)(a2 + 8));
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 48) = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(v2, (_RTL_CRITICAL_SECTION *)(a2 + 56));
  *(_DWORD *)(a2 + 84) = 0;
  *(_DWORD *)(a2 + 88) = 0;
  *(_DWORD *)(a2 + 96) = 0;
  *(_DWORD *)(a2 + 104) = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(v3, (_RTL_CRITICAL_SECTION *)(a2 + 112));
  *(_DWORD *)(a2 + 140) = 0;
  *(_DWORD *)(a2 + 144) = 0;
  *(_DWORD *)(a2 + 152) = 0;
  *(_DWORD *)(a2 + 156) = a2 + 152;
  *(_DWORD *)(a2 + 160) = a2 + 152;
  *(_DWORD *)(a2 + 164) = 0;
  *(_DWORD *)(a2 + 168) = 1;
  *(_DWORD *)(a2 + 172) = 0;
  vostok::timing::timer::timer(v4, (LARGE_INTEGER *)(a2 + 176));
  vostok::timing::timer::start(v5, (LARGE_INTEGER *)(a2 + 176));
}
