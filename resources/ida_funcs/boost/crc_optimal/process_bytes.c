void __thiscall boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(
        boost::crc_optimal<32,79764919,0,0,1,0> *this,
        char *buffer,
        unsigned int byte_count)
{
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(this, buffer, &buffer[byte_count]);
}
