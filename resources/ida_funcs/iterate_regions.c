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


void __usercall iterate_regions<regions_filler>(
        const unsigned int start_address@<eax>,
        unsigned int allocation_granularity,
        unsigned __int64 min_buffer_size,
        regions_filler *predicate)
{
  __int64 v4; // kr00_8
  unsigned int RegionSize; // ecx
  unsigned int v6; // eax
  vostok::buffer_vector<vostok::memory::platform::region> *m_regions; // eax
  vostok::memory::platform::region *m_end; // ecx
  __int64 BaseAddress; // [esp+18h] [ebp-2Ch]
  _MEMORY_BASIC_INFORMATION memory_info; // [esp+24h] [ebp-20h] BYREF

  v4 = start_address;
  do
  {
    if ( VirtualQuery((LPCVOID)v4, &memory_info, 0x1Cu) )
    {
      RegionSize = memory_info.RegionSize;
      if ( memory_info.RegionSize >= min_buffer_size )
      {
        v6 = memory_info.RegionSize;
        if ( memory_info.RegionSize % allocation_granularity )
          v6 = allocation_granularity + memory_info.RegionSize - memory_info.RegionSize % allocation_granularity;
        v4 += v6;
        if ( (HINSTANCE__ *)memory_info.State == &_sbh_sizeHeaderList )
        {
          m_regions = predicate->m_regions;
          BaseAddress = (unsigned int)memory_info.BaseAddress;
          m_end = predicate->m_regions->m_end;
          if ( m_end )
          {
            m_end->size = memory_info.RegionSize;
            *(_QWORD *)&m_end->address = BaseAddress;
          }
          ++m_regions->m_end;
        }
      }
      else
      {
        if ( memory_info.RegionSize % allocation_granularity )
          RegionSize = allocation_granularity + memory_info.RegionSize - memory_info.RegionSize % allocation_granularity;
        v4 += RegionSize;
      }
    }
    else
    {
      v4 += allocation_granularity;
    }
  }
  while ( !HIDWORD(v4) );
}
