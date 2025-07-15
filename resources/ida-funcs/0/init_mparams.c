int __cdecl init_mparams()
{
  _SYSTEM_INFO system_info; // [esp+0h] [ebp-24h] BYREF

  if ( !mparams.page_size )
  {
    mparams.mmap_threshold = 0x40000;
    mparams.trim_threshold = (unsigned int)&loc_1FFFFE + 2;
    mparams.default_mflags = 5;
    if ( !mparams.magic )
    {
      mparams.magic = 1482184792;
      gm_.mflags = 5;
    }
    GetSystemInfo(&system_info);
    mparams.page_size = system_info.dwPageSize;
    mparams.granularity = system_info.dwAllocationGranularity;
    if ( ((system_info.dwAllocationGranularity - 1) & system_info.dwAllocationGranularity) != 0
      || ((system_info.dwPageSize - 1) & system_info.dwPageSize) != 0 )
    {
      abort();
    }
  }
  return 0;
}
