unsigned int __cdecl allocation_granularity()
{
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(&SystemInfo);
  return SystemInfo.dwAllocationGranularity;
}
