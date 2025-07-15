unsigned int __cdecl vostok::strings::shared::profile::create_checksum(unsigned __int8 *begin, unsigned __int8 *end)
{
  boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> processor; // [esp+4h] [ebp-4h] BYREF

  processor.rem_ = boost::detail::crc_helper<32,1>::reflect(0xFFFFFFFF);
  boost::detail::crc_table_t<32,79764919,1>::init_table();
  boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>::process_block(&processor, begin, end);
  return ~processor.rem_;
}
