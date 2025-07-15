int __cdecl get_minimum_kernel_memory()
{
  _BYTE dst[156]; // [esp+0h] [ebp-A0h] BYREF

  memset((int)dst, 0, sizeof(dst));
  *(_DWORD *)dst = 156;
  GetVersionExA((LPOSVERSIONINFOA)dst);
  if ( *(_DWORD *)&dst[4] <= 5u )
    return 0x8000000;
  if ( *(_DWORD *)&dst[4] != 6 )
    return 0x20000000;
  if ( vostok::platform::is_address_space_or_ram_under_2_gb() )
    return 0x10000000;
  if ( *(_DWORD *)&dst[8] < 2u )
    return 335544320;
  if ( *(_DWORD *)&dst[8] == 2 )
    return 0x10000000;
  if ( *(_DWORD *)&dst[8] == 3 )
    return 0x10000000;
  else
    return 0x20000000;
}
