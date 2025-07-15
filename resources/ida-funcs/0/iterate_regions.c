void __usercall iterate_regions<regions_count>(
        char *start_address@<eax>,
        unsigned int allocation_granularity,
        const unsigned __int64 min_buffer_size,
        regions_count *predicate)
{
  unsigned int v4; // edi
  bool v6; // cf
  unsigned int v7; // eax
  unsigned __int64 v8; // kr00_8
  _MEMORY_BASIC_INFORMATION Buffer; // [esp+Ch] [ebp-1Ch] BYREF

  v4 = 0;
  do
  {
    if ( !VirtualQuery(start_address, &Buffer, 0x1Cu) )
    {
      v6 = __CFADD__(allocation_granularity, start_address);
      start_address += allocation_granularity;
LABEL_4:
      v4 += v6;
      continue;
    }
    if ( Buffer.RegionSize < min_buffer_size )
    {
      v7 = vostok::math::align_up<unsigned long>(allocation_granularity);
      v6 = __CFADD__(v7, start_address);
      start_address += v7;
      goto LABEL_4;
    }
    v8 = vostok::math::align_up<unsigned long>(allocation_granularity) + __PAIR64__(v4, (unsigned int)start_address);
    v4 = HIDWORD(v8);
    start_address = (char *)v8;
    if ( (HINSTANCE__ *)Buffer.State == &_sbh_sizeHeaderList )
      ++predicate->m_region_count;
  }
  while ( !v4 );
}


void __cdecl iterate_regions<regions_filler>(
        char *start_address,
        unsigned int allocation_granularity,
        const unsigned __int64 min_buffer_size,
        regions_filler *predicate)
{
  bool v5; // cf
  unsigned int RegionSize; // esi
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // et0
  vostok::buffer_vector<vostok::memory::platform::region> *m_regions; // [esp-8h] [ebp-4Ch]
  vostok::buffer_vector<vostok::memory::platform::region> *v11; // [esp-4h] [ebp-48h]
  _MEMORY_BASIC_INFORMATION Buffer; // [esp+Ch] [ebp-38h] BYREF
  _DWORD v13[5]; // [esp+28h] [ebp-1Ch] BYREF
  unsigned int v14; // [esp+3Ch] [ebp-8h]

  v14 = 0;
  do
  {
    if ( !VirtualQuery(start_address, &Buffer, 0x1Cu) )
    {
      v5 = __CFADD__(allocation_granularity, start_address);
      start_address += allocation_granularity;
LABEL_4:
      v14 += v5;
      continue;
    }
    RegionSize = Buffer.RegionSize;
    if ( Buffer.RegionSize < min_buffer_size )
    {
      v7 = vostok::math::align_up<unsigned long>(allocation_granularity);
      v5 = __CFADD__(v7, start_address);
      start_address += v7;
      goto LABEL_4;
    }
    v8 = vostok::math::align_up<unsigned long>(allocation_granularity);
    v9 = (v8 + __PAIR64__(v14, (unsigned int)start_address)) >> 32;
    start_address += v8;
    v14 = v9;
    if ( (HINSTANCE__ *)Buffer.State == &_sbh_sizeHeaderList )
    {
      v13[3] = 0;
      v13[2] = Buffer.BaseAddress;
      m_regions = predicate->m_regions;
      v13[0] = RegionSize;
      v13[1] = 0;
      vostok::buffer_vector<vostok::memory::platform::region>::push_back(
        v11,
        (const vostok::memory::platform::region *)m_regions,
        v13);
    }
  }
  while ( !v14 );
}
