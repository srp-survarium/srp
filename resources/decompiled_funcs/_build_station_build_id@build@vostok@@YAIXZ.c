unsigned int __cdecl vostok::build::build_station_build_id()
{
  if ( !initialized_0 )
  {
    initialized_0 = 1;
    if ( sscanf_s((char *)&vostok::memory::g_crt_allocator.m_arena_start, "Build %d", &build_station_build_id) != 1 )
      build_station_build_id = build_id(s_build_date);
  }
  return build_station_build_id;
}
