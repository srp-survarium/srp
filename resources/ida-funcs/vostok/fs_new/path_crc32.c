unsigned int __usercall vostok::fs_new::path_crc32@<eax>(const char *data@<esi>, int size, unsigned int start_value)
{
  int v3; // edi
  int v4; // eax
  char v5; // dl
  boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> v7; // [esp+4h] [ebp-4h] BYREF

  v7.rem_ = boost::detail::crc_helper<32,1>::reflect(start_value);
  boost::detail::crc_table_t<32,79764919,1>::init_table();
  v3 = 0;
  v4 = -1;
  if ( size > 0 )
  {
    do
    {
      v5 = data[v3];
      if ( v5 == 47 || v5 == 92 )
      {
        if ( v4 != -1 )
        {
          boost::crc_optimal<32,79764919,0,0,1,0>::process_block(&v7, (char *)&data[v4], (char *)&data[v3]);
          v4 = -1;
        }
      }
      else if ( v4 == -1 )
      {
        v4 = v3;
      }
      ++v3;
    }
    while ( v3 < size );
    if ( v4 != -1 )
      boost::crc_optimal<32,79764919,0,0,1,0>::process_block(&v7, (char *)&data[v4], (char *)&data[v3]);
  }
  return boost::detail::crc_helper<32,1>::reflect(v7.rem_);
}
