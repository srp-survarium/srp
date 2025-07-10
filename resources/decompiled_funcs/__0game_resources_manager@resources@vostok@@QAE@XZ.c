void __usercall vostok::resources::game_resources_manager::game_resources_manager(
        vostok::resources::game_resources_manager *this@<ecx>,
        int a2@<edi>)
{
  vostok::resources::game_resources_manager_data *v2; // ecx

  *(_DWORD *)a2 = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 8), 0x2710u);
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 48) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 56), 0x2710u);
  *(_DWORD *)(a2 + 84) = 0;
  *(_DWORD *)(a2 + 88) = 0;
  vostok::resources::game_resources_manager_data::game_resources_manager_data(v2, a2 + 96);
}
