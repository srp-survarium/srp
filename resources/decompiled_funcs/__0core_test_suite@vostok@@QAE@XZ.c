void __usercall vostok::core_test_suite::core_test_suite(vostok::core_test_suite *this@<ecx>, int a2@<esi>)
{
  *(_DWORD *)a2 = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 8), 0x2710u);
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  ++s_environment.num_suites_total;
  *(_DWORD *)(a2 + 48) = a2 + 60;
  *(_DWORD *)(a2 + 52) = a2 + 60;
  *(_DWORD *)(a2 + 56) = a2 + 320;
  *(_BYTE *)(a2 + 60) = 0;
  *(_BYTE *)(a2 + 60) = 0;
  *(_BYTE *)(a2 + 320) = 92;
}
