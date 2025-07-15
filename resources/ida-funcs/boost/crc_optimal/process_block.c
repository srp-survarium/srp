void __userpurge boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
        boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *this@<eax>,
        char *bytes_begin@<edx>,
        char *bytes_end)
{
  unsigned __int8 v3; // cl

  for ( ; bytes_begin < bytes_end; this->rem_ ^= boost::detail::crc_table_t<32,79764919,1>::table_[v3] )
  {
    v3 = LOBYTE(this->rem_) ^ *bytes_begin;
    this->rem_ >>= 8;
    ++bytes_begin;
  }
}
