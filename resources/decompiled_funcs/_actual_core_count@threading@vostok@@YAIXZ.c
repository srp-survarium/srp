unsigned int __cdecl vostok::threading::actual_core_count()
{
  _SYSTEM_INFO system_info; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(&system_info);
  return system_info.dwNumberOfProcessors;
}
