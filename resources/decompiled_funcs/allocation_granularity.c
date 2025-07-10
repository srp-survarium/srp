unsigned int __cdecl allocation_granularity()
{
  _SYSTEM_INFO system_info; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(&system_info);
  return system_info.dwAllocationGranularity;
}
