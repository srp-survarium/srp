unsigned int __cdecl vostok::fs_new::crc32(char *data, unsigned int size, unsigned int start_value)
{
  boost::crc_optimal<32,79764919,0,0,1,0> processor; // [esp+Ch] [ebp-4h] BYREF

  processor.rem_ = boost::detail::reflector<32>::reflect(start_value);
  boost::detail::crc_table_t<32,79764919,1>::init_table();
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(&processor, data, &data[size]);
  return boost::detail::reflector<32>::reflect(processor.rem_);
}
