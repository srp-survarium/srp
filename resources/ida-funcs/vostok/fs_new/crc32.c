unsigned int __usercall vostok::fs_new::crc32@<eax>(char *data@<esi>, unsigned int size, unsigned int start_value)
{
  boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> v4; // [esp+0h] [ebp-4h] BYREF

  v4.rem_ = boost::detail::crc_helper<32,1>::reflect(start_value);
  boost::detail::crc_table_t<32,79764919,1>::init_table();
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(&v4, data, &data[size]);
  return boost::detail::crc_helper<32,1>::reflect(v4.rem_);
}
