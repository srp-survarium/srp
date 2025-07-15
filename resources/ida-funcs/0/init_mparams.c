int __cdecl init_mparams()
{
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  if ( !mparams.page_size )
  {
    mparams.mmap_threshold = (unsigned int)&loc_3FFFF + 1;
    mparams.trim_threshold = (unsigned int)&loc_200000;
    mparams.default_mflags = 5;
    if ( !mparams.magic )
    {
      mparams.magic = 1482184792;
      gm_.mflags = 5;
    }
    GetSystemInfo(&SystemInfo);
    mparams.page_size = SystemInfo.dwPageSize;
    mparams.granularity = SystemInfo.dwAllocationGranularity;
    if ( ((SystemInfo.dwAllocationGranularity - 1) & SystemInfo.dwAllocationGranularity) != 0
      || ((SystemInfo.dwPageSize - 1) & SystemInfo.dwPageSize) != 0 )
    {
      abort();
    }
  }
  return 0;
}
