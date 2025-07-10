void __thiscall boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
        boost::crc_optimal<32,79764919,0,0,1,0> *this,
        char *bytes_begin,
        char *bytes_end)
{
  unsigned __int8 byte_index; // [esp+7h] [ebp-5h]

  while ( bytes_begin < bytes_end )
  {
    byte_index = this->rem_ ^ *bytes_begin;
    this->rem_ >>= 8;
    this->rem_ ^= boost::detail::crc_table_t<32,79764919,1>::table_[byte_index];
    ++bytes_begin;
  }
}
