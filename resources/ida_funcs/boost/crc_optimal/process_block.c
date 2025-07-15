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


void __userpurge boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>::process_block(
        boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *this@<esi>,
        unsigned __int8 *bytes_begin@<eax>,
        unsigned __int8 *bytes_end)
{
  unsigned __int8 *i; // edi
  unsigned __int8 v4; // bl
  unsigned int v5; // eax

  for ( i = bytes_begin; i < bytes_end; this->rem_ = v5 ^ boost::detail::crc_table_t<32,79764919,1>::table_[v4] )
  {
    v4 = boost::detail::crc_helper<32,1>::index(this->rem_, *i);
    v5 = boost::detail::crc_helper<32,1>::shift(this->rem_);
    this->rem_ = v5;
    ++i;
  }
}
