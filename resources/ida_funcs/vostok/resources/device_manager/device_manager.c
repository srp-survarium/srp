void __usercall vostok::resources::device_manager::device_manager(
        vostok::resources::device_manager *this@<ecx>,
        int a2@<esi>)
{
  char v2; // [esp+7h] [ebp-1h]

  *(_DWORD *)a2 = &vostok::resources::device_manager::`vftable';
  *(_DWORD *)(a2 + 8) = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 16), 0x2710u);
  *(_DWORD *)(a2 + 40) = 4096;
  *(_DWORD *)(a2 + 44) = 0;
  *(_DWORD *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 52) = 0;
  *(_BYTE *)(a2 + 57) = v2;
  *(_DWORD *)(a2 + 60) = 0;
  *(_DWORD *)(a2 + 68) = 0;
  *(_DWORD *)(a2 + 72) = 0;
  *(_DWORD *)(a2 + 108) = 0;
  *(_DWORD *)(a2 + 116) = 0;
  *(_DWORD *)(a2 + 120) = 0;
  *(_DWORD *)(a2 + 8328) = -1;
  *(_DWORD *)(a2 + 8332) = -1;
  *(_BYTE *)(a2 + 125) = 0;
  *(_DWORD *)(a2 + 128) = 512;
  *(_BYTE *)(a2 + 8348) = 0;
  *(_DWORD *)(a2 + 8336) = a2 + 8348;
  *(_DWORD *)(a2 + 8340) = a2 + 8348;
  *(_DWORD *)(a2 + 8344) = a2 + 8608;
  *(_BYTE *)(a2 + 8608) = 92;
  *(_BYTE *)(a2 + 76) = 0;
  *(_DWORD *)(a2 + 80) = 0;
  *(_DWORD *)(a2 + 104) = 0;
}
