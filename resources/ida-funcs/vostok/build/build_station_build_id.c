unsigned int __cdecl vostok::build::build_station_build_id()
{
  if ( !initialized_0 )
  {
    initialized_0 = 1;
    if ( sscanf_s((const char *)&s_command_line_keys_creation.m_mutex[2], "Build %d", &build_station_build_id) != 1 )
      build_station_build_id = build_id((char *)s_build_date);
  }
  return build_station_build_id;
}
