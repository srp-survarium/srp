void __thiscall boost::crc_optimal<32,79764919,0,0,1,0>::crc_optimal<32,79764919,0,0,1,0>(
        boost::crc_optimal<32,79764919,0,0,1,0> *this,
        unsigned int init_rem)
{
  this->rem_ = boost::detail::reflector<32>::reflect(init_rem);
  boost::detail::crc_table_t<32,79764919,1>::init_table();
}
