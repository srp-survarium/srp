unsigned int __cdecl vostok::fs_new::path_crc32(const char *data, signed int size, unsigned int start_value)
{
  int cur_index; // [esp+10h] [ebp-Ch]
  int start_index; // [esp+14h] [ebp-8h]
  boost::crc_optimal<32,79764919,0,0,1,0> processor; // [esp+18h] [ebp-4h] BYREF

  processor.rem_ = boost::detail::reflector<32>::reflect(start_value);
  boost::detail::crc_table_t<32,79764919,1>::init_table();
  start_index = -1;
  for ( cur_index = 0; cur_index < size; ++cur_index )
  {
    if ( data[cur_index] == 47 || data[cur_index] == 92 )
    {
      if ( start_index != -1 )
      {
        boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
          &processor,
          (char *)&data[start_index],
          (char *)&data[cur_index]);
        start_index = -1;
      }
    }
    else if ( start_index == -1 )
    {
      start_index = cur_index;
    }
  }
  if ( start_index != -1 )
    boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
      &processor,
      (char *)&data[start_index],
      (char *)&data[cur_index]);
  return boost::detail::reflector<32>::reflect(processor.rem_);
}
