void __usercall iterate_regions<regions_count>(
        char *start_address@<eax>,
        const unsigned int allocation_granularity@<edi>,
        unsigned __int64 min_buffer_size,
        regions_count *predicate)
{
  __int64 v4; // rcx
  __int64 v6; // kr00_8
  _MEMORY_BASIC_INFORMATION memory_info; // [esp+Ch] [ebp-1Ch] BYREF

  HIDWORD(v4) = 0;
  do
  {
    if ( VirtualQuery(start_address, &memory_info, 0x1Cu) )
    {
      LODWORD(v4) = memory_info.RegionSize;
      if ( memory_info.RegionSize >= min_buffer_size )
      {
        if ( memory_info.RegionSize % allocation_granularity )
          LODWORD(v4) = allocation_granularity
                      + memory_info.RegionSize
                      - memory_info.RegionSize % allocation_granularity;
        HIDWORD(v4) = (v4 + (unsigned __int64)(unsigned int)start_address) >> 32;
        start_address += v4;
        if ( (HINSTANCE__ *)memory_info.State == &_sbh_sizeHeaderList )
          ++predicate->m_region_count;
      }
      else
      {
        if ( memory_info.RegionSize % allocation_granularity )
          LODWORD(v4) = allocation_granularity
                      + memory_info.RegionSize
                      - memory_info.RegionSize % allocation_granularity;
        HIDWORD(v4) = (v4 + (unsigned __int64)(unsigned int)start_address) >> 32;
        start_address += v4;
      }
    }
    else
    {
      v6 = allocation_granularity + __PAIR64__(HIDWORD(v4), (unsigned int)start_address);
      HIDWORD(v4) = HIDWORD(v6);
      start_address = (char *)v6;
    }
  }
  while ( !HIDWORD(v4) );
}
