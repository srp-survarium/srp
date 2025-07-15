unsigned __int64 __cdecl calculate_desirable_resource_arenas(
        memory_stats *stats,
        unsigned int maximum_video_share,
        const unsigned __int64 minimum_video_memory_size,
        unsigned __int64 minimum_resources_size)
{
  unsigned __int64 v5; // rax
  unsigned int current_kernel_memory_high; // ecx
  unsigned int v7; // edi
  unsigned int v8; // eax
  unsigned int current_kernel_memory; // edx
  unsigned int engine_fixed_memory; // esi
  bool v11; // cf
  unsigned int v12; // edi
  unsigned int engine_fixed_memory_high; // edx
  unsigned int v14; // eax
  unsigned int available_address_space; // ecx
  unsigned int available_address_space_high; // eax
  unsigned __int64 v17; // kr10_8
  bool does_os_use_process_address_space_for_duplicating_video_resources; // dl
  double v19; // st5
  double v20; // st6
  unsigned __int64 v21; // rax
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // kr20_8
  vostok::command_line::key *v24; // ecx
  unsigned __int64 v25; // rdi
  unsigned __int64 v27; // [esp+20h] [ebp-1Ch]
  unsigned __int64 right; // [esp+28h] [ebp-14h] BYREF
  unsigned __int64 video_memory; // [esp+30h] [ebp-Ch]
  bool v30; // [esp+47h] [ebp+Bh]

  v5 = vostok::math::min(stats->total_available_memory, stats->physical_memory);
  current_kernel_memory_high = HIDWORD(stats->current_kernel_memory);
  v7 = v5;
  v8 = HIDWORD(v5);
  current_kernel_memory = stats->current_kernel_memory;
  if ( __PAIR64__(v8, v7) < __PAIR64__(current_kernel_memory_high, current_kernel_memory) )
    goto LABEL_2;
  engine_fixed_memory = stats->engine_fixed_memory;
  v11 = v7 < current_kernel_memory;
  v12 = v7 - current_kernel_memory;
  engine_fixed_memory_high = HIDWORD(stats->engine_fixed_memory);
  v14 = v8 - (v11 + current_kernel_memory_high);
  if ( __PAIR64__(v14, v12) < __PAIR64__(engine_fixed_memory_high, engine_fixed_memory) )
    goto LABEL_2;
  v27 = __PAIR64__(v14, v12) - __PAIR64__(engine_fixed_memory_high, engine_fixed_memory);
  if ( __PAIR64__(v14, v12) - __PAIR64__(engine_fixed_memory_high, engine_fixed_memory) < __PAIR64__(
                                                                                            minimum_resources_size,
                                                                                            HIDWORD(minimum_video_memory_size))
                                                                                        + __PAIR64__(
                                                                                            minimum_video_memory_size,
                                                                                            maximum_video_share) )
    goto LABEL_2;
  available_address_space = stats->available_address_space;
  video_memory = stats->video_memory;
  available_address_space_high = HIDWORD(stats->available_address_space);
  if ( __PAIR64__(available_address_space_high, available_address_space) < __PAIR64__(
                                                                             engine_fixed_memory_high,
                                                                             engine_fixed_memory) )
    goto LABEL_2;
  v17 = __PAIR64__(available_address_space_high, available_address_space)
      - __PAIR64__(engine_fixed_memory_high, engine_fixed_memory);
  does_os_use_process_address_space_for_duplicating_video_resources = stats->does_os_use_process_address_space_for_duplicating_video_resources;
  right = v17;
  v30 = does_os_use_process_address_space_for_duplicating_video_resources;
  if ( does_os_use_process_address_space_for_duplicating_video_resources )
  {
    if ( (double)(video_memory / v17) > 0.89999998 )
    {
      v19 = (double)right * 0.89999998;
      if ( v19 < (double)__PAIR64__(minimum_video_memory_size, maximum_video_share) )
        goto LABEL_2;
      video_memory = (unsigned __int64)v19;
    }
    if ( right - video_memory < __PAIR64__(minimum_resources_size, HIDWORD(minimum_video_memory_size)) )
    {
      if ( right - __PAIR64__(minimum_resources_size, HIDWORD(minimum_video_memory_size)) < __PAIR64__(
                                                                                              minimum_video_memory_size,
                                                                                              maximum_video_share) )
        goto LABEL_2;
      video_memory = right - __PAIR64__(minimum_resources_size, HIDWORD(minimum_video_memory_size));
    }
  }
  if ( (double)(video_memory / v27) > 0.89999998 )
  {
    v20 = 0.89999998 * (double)v27;
    if ( v20 >= (double)__PAIR64__(minimum_video_memory_size, maximum_video_share) )
    {
      v21 = (unsigned __int64)v20;
      HIDWORD(video_memory) = (unsigned __int64)v20 >> 32;
      goto LABEL_18;
    }
LABEL_2:
    vostok::debug::terminate("Not enough memory to run Vostok Engine v1.0\r\n"
                             "Close all programs, increase paging file size or add memory bank and try again.");
  }
  LODWORD(v21) = video_memory;
LABEL_18:
  if ( v27 - __PAIR64__(HIDWORD(video_memory), v21) < __PAIR64__(
                                                        minimum_resources_size,
                                                        HIDWORD(minimum_video_memory_size)) )
  {
    if ( v27 - __PAIR64__(minimum_resources_size, HIDWORD(minimum_video_memory_size)) < __PAIR64__(
                                                                                          minimum_video_memory_size,
                                                                                          maximum_video_share) )
      goto LABEL_2;
    video_memory = v27 - __PAIR64__(minimum_resources_size, HIDWORD(minimum_video_memory_size));
    LODWORD(v21) = v27 - HIDWORD(minimum_video_memory_size);
  }
  HIDWORD(v21) = HIDWORD(video_memory);
  stats->video_memory_we_may_use = v21;
  if ( v30 )
    right -= v21;
  v22 = vostok::math::min(v27 - v21, right);
  right = -1;
  v23 = v22;
  if ( vostok::command_line::key::is_set_as_number<unsigned __int64>(&s_max_resources_size, &right, v24) )
  {
    v25 = right * (unsigned int)&loc_100000;
    if ( !v25 || !vostok::platform::is_address_space_or_ram_under_2_gb() )
      v25 = vostok::math::max(v25, __PAIR64__(minimum_resources_size, HIDWORD(minimum_video_memory_size)));
  }
  else
  {
    v25 = right;
  }
  return vostok::math::min(v23, v25);
}
