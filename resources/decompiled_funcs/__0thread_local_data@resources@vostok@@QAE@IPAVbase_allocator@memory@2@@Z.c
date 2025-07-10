void __userpurge vostok::resources::thread_local_data::thread_local_data(
        vostok::resources::thread_local_data *this@<ecx>,
        int a2@<esi>,
        unsigned int thread_id,
        vostok::memory::base_allocator *allocator)
{
  *(_DWORD *)a2 = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 8), 0x2710u);
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 48) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 56), 0x2710u);
  *(_DWORD *)(a2 + 84) = 0;
  *(_DWORD *)(a2 + 88) = 0;
  *(_DWORD *)(a2 + 96) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 104), 0x2710u);
  *(_DWORD *)(a2 + 132) = 0;
  *(_DWORD *)(a2 + 136) = 0;
  *(_DWORD *)(a2 + 144) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 152), 0x2710u);
  *(_DWORD *)(a2 + 180) = 0;
  *(_DWORD *)(a2 + 184) = 0;
  *(_DWORD *)(a2 + 192) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 200), 0x2710u);
  *(_DWORD *)(a2 + 228) = 0;
  *(_DWORD *)(a2 + 232) = 0;
  *(_DWORD *)(a2 + 240) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 248), 0x2710u);
  *(_DWORD *)(a2 + 276) = 0;
  *(_DWORD *)(a2 + 280) = 0;
  *(_DWORD *)(a2 + 288) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 296), 0x2710u);
  *(_DWORD *)(a2 + 324) = 0;
  *(_DWORD *)(a2 + 328) = 0;
  *(_BYTE *)(a2 + 336) = 0;
  *(_DWORD *)(a2 + 344) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 352), 0x2710u);
  *(_DWORD *)(a2 + 380) = 0;
  *(_DWORD *)(a2 + 384) = 0;
  *(_DWORD *)(a2 + 392) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 400), 0x2710u);
  *(_DWORD *)(a2 + 428) = 0;
  *(_DWORD *)(a2 + 432) = 0;
  *(_DWORD *)(a2 + 440) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 448), 0x2710u);
  *(_DWORD *)(a2 + 476) = 0;
  *(_DWORD *)(a2 + 480) = 0;
  *(_DWORD *)(a2 + 488) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 496), 0x2710u);
  *(_DWORD *)(a2 + 524) = 0;
  *(_DWORD *)(a2 + 528) = 0;
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
