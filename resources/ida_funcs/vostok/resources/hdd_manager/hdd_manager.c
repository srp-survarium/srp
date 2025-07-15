void __usercall vostok::resources::hdd_manager::hdd_manager(vostok::resources::hdd_manager *this@<ecx>, int a2@<eax>)
{
  unsigned int v3; // [esp+0h] [ebp-4h]

  vostok::resources::device_manager::device_manager(this, v3);
  *(_DWORD *)a2 = &stru_95BE78.m_string.m_buffer[152];
  *(_DWORD *)(a2 + 8616) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 8624), 0x2710u);
  *(_DWORD *)(a2 + 8652) = 0;
  *(_DWORD *)(a2 + 8656) = 0;
}
