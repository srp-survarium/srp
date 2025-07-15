unsigned __int64 __cdecl get_minimum_kernel_memory()
{
  _OSVERSIONINFOEXA os_version_info; // [esp+0h] [ebp-9Ch] BYREF

  memset((int)&os_version_info, 0, sizeof(os_version_info));
  os_version_info.dwOSVersionInfoSize = 156;
  GetVersionExA((LPOSVERSIONINFOA)&os_version_info);
  if ( os_version_info.dwMajorVersion == 5 )
    return 0x8000000;
  if ( os_version_info.dwMajorVersion != 6 )
    return 0x20000000;
  if ( os_version_info.dwMinorVersion )
    return 0x20000000;
  return 402653184;
}
