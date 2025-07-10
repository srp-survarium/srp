unsigned __int64 __usercall calculate_desirable_resource_arenas@<edx:eax>(
        memory_stats *stats@<eax>,
        unsigned int maximum_video_share,
        unsigned __int64 minimum_video_memory_size,
        unsigned __int64 minimum_resources_size)
{
  unsigned __int64 v5; // kr10_8
  unsigned __int64 v6; // kr18_8
  __int64 v7; // rcx
  unsigned int available_address_space_high; // eax
  unsigned int video_memory; // edi
  unsigned int video_memory_high; // ebp
  unsigned __int64 v11; // kr28_8
  bool v12; // zf
  double v13; // st6
  double v14; // st7
  unsigned __int64 v15; // kr48_8
  unsigned int v16; // esi
  unsigned int v17; // edi
  unsigned __int64 v18; // kr60_8
  float out_value[2]; // [esp+10h] [ebp-24h] BYREF
  unsigned __int64 address_space; // [esp+18h] [ebp-1Ch]
  unsigned __int64 useful_memory; // [esp+20h] [ebp-14h]
  unsigned __int64 v23; // [esp+28h] [ebp-Ch]

  v5 = stats->physical_memory
     + (stats->total_available_memory < stats->physical_memory
      ? stats->total_available_memory - stats->physical_memory
      : 0);
  if ( v5 < stats->current_kernel_memory )
    vostok::debug::terminate("Not enough memory to run Vostok Engine v1.0\r\n"
                             "Close all programs, increase paging file size or add memory bank and try again.");
  v6 = v5 - stats->current_kernel_memory;
  if ( v6 < stats->engine_fixed_memory )
    vostok::debug::terminate("Not enough memory to run Vostok Engine v1.0\r\n"
                             "Close all programs, increase paging file size or add memory bank and try again.");
  HIDWORD(v7) = (v6 - stats->engine_fixed_memory) >> 32;
  LODWORD(useful_memory) = v6 - LODWORD(stats->engine_fixed_memory);
  if ( __PAIR64__(HIDWORD(v7), useful_memory) < __PAIR64__(minimum_resources_size, HIDWORD(minimum_video_memory_size))
                                              + __PAIR64__(minimum_video_memory_size, maximum_video_share) )
    vostok::debug::terminate("Not enough memory to run Vostok Engine v1.0\r\n"
                             "Close all programs, increase paging file size or add memory bank and try again.");
  available_address_space_high = HIDWORD(stats->available_address_space);
  video_memory = stats->video_memory;
  video_memory_high = HIDWORD(stats->video_memory);
  LODWORD(address_space) = stats->available_address_space;
  HIDWORD(address_space) = available_address_space_high;
  if ( __PAIR64__(available_address_space_high, address_space) < stats->engine_fixed_memory )
    vostok::debug::terminate("Not enough memory to run Vostok Engine v1.0\r\n"
                             "Close all programs, increase paging file size or add memory bank and try again.");
  v11 = __PAIR64__(available_address_space_high, address_space) - stats->engine_fixed_memory;
  v12 = !stats->does_os_use_process_address_space_for_duplicating_video_resources;
  address_space = v11;
  if ( !v12 )
  {
    LODWORD(out_value[1]) = ((__PAIR64__(video_memory_high, video_memory) / v11) >> 32) & 0x80000000;
    out_value[0] = 0.0;
    if ( (double)(__PAIR64__(video_memory_high, video_memory) / v11) > 0.89999998 )
    {
      LODWORD(out_value[1]) = HIDWORD(address_space) & 0x80000000;
      v13 = (double)address_space * 0.89999998;
      out_value[0] = v13;
      HIDWORD(v23) = minimum_video_memory_size & 0x80000000;
      LODWORD(v23) = 0;
      if ( v13 < (double)__PAIR64__(minimum_video_memory_size, maximum_video_share) )
        vostok::debug::terminate("Not enough memory to run Vostok Engine v1.0\r\n"
                                 "Close all programs, increase paging file size or add memory bank and try again.");
      video_memory_high = (unsigned __int64)v13 >> 32;
      video_memory = (unsigned __int64)v13;
    }
    if ( address_space - __PAIR64__(video_memory_high, video_memory) < __PAIR64__(
                                                                         minimum_resources_size,
                                                                         HIDWORD(minimum_video_memory_size)) )
    {
      video_memory_high = (address_space - __PAIR64__(minimum_resources_size, HIDWORD(minimum_video_memory_size))) >> 32;
      video_memory = address_space - HIDWORD(minimum_video_memory_size);
      if ( address_space - __PAIR64__(minimum_resources_size, HIDWORD(minimum_video_memory_size)) < __PAIR64__(minimum_video_memory_size, maximum_video_share) )
        vostok::debug::terminate("Not enough memory to run Vostok Engine v1.0\r\n"
                                 "Close all programs, increase paging file size or add memory bank and try again.");
    }
  }
  v23 = (__PAIR64__(video_memory_high, video_memory) / __PAIR64__(HIDWORD(v7), useful_memory)) & 0x8000000000000000uLL;
  if ( (double)(__PAIR64__(video_memory_high, video_memory) / __PAIR64__(HIDWORD(v7), useful_memory)) > 0.89999998 )
  {
    v14 = 0.89999998 * (double)__PAIR64__(HIDWORD(v7), useful_memory);
    out_value[0] = v14;
    HIDWORD(v23) = minimum_video_memory_size & 0x80000000;
    LODWORD(v23) = 0;
    if ( v14 < (double)__PAIR64__(minimum_video_memory_size, maximum_video_share) )
      vostok::debug::terminate("Not enough memory to run Vostok Engine v1.0\r\n"
                               "Close all programs, increase paging file size or add memory bank and try again.");
    video_memory_high = (unsigned __int64)v14 >> 32;
    video_memory = (unsigned __int64)v14;
  }
  LODWORD(v7) = useful_memory;
  LODWORD(v23) = useful_memory - video_memory;
  if ( __PAIR64__(HIDWORD(v7), useful_memory) - __PAIR64__(video_memory_high, video_memory) >= __PAIR64__(
                                                                                                 minimum_resources_size,
                                                                                                 HIDWORD(minimum_video_memory_size)) )
  {
    v15 = __PAIR64__(video_memory_high, video_memory) + 0x10000000;
  }
  else
  {
    v15 = v7 - __PAIR64__(minimum_resources_size, HIDWORD(minimum_video_memory_size));
    if ( v7 - __PAIR64__(minimum_resources_size, HIDWORD(minimum_video_memory_size)) < __PAIR64__(
                                                                                         minimum_video_memory_size,
                                                                                         maximum_video_share) )
      vostok::debug::terminate("Not enough memory to run Vostok Engine v1.0\r\n"
                               "Close all programs, increase paging file size or add memory bank and try again.");
  }
  if ( stats->does_os_use_process_address_space_for_duplicating_video_resources )
    address_space -= v15;
  out_value[0] = 0.0;
  v16 = address_space + (v7 - v15 < address_space ? useful_memory - v15 - address_space : 0);
  v17 = (address_space + (v7 - v15 < address_space ? v7 - v15 - address_space : 0)) >> 32;
  v18 = -1;
  if ( vostok::command_line::key::is_set_as_number(&s_max_resources_size, out_value) )
    v18 = vostok::math::max(
            (unsigned __int64)out_value[0] * ((unsigned int)&loc_FFFFF + 1),
            __PAIR64__(minimum_resources_size, HIDWORD(minimum_video_memory_size)));
  return v18 + (__PAIR64__(v17, v16) < v18 ? __PAIR64__(v17, v16) - v18 : 0);
}
