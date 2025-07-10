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
