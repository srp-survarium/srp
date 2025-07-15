int boost::detail::crc_table_t<32,79764919,1>::init_table()
{
  int result; // eax
  unsigned int v1; // [esp+0h] [ebp-14h]
  unsigned __int8 mask; // [esp+7h] [ebp-Dh]
  int remainder; // [esp+8h] [ebp-Ch]
  unsigned __int8 dividend; // [esp+13h] [ebp-1h]

  result = `boost::detail::crc_table_t<32,79764919,1>::init_table'::`2'::did_init;
  if ( !`boost::detail::crc_table_t<32,79764919,1>::init_table'::`2'::did_init )
  {
    dividend = 0;
    do
    {
      remainder = 0;
      for ( mask = 0x80; mask; mask >>= 1 )
      {
        if ( (mask & dividend) != 0 )
          remainder ^= 0x80000000;
        if ( remainder >= 0 )
          remainder *= 2;
        else
          remainder = (unsigned int)&s_task_manager.m_task_allocator.m_task_buffer[377847] ^ (2 * remainder);
      }
      v1 = boost::detail::reflector<32>::reflect(remainder);
      boost::detail::crc_table_t<32,79764919,1>::table_[boost::detail::reflector<8>::reflect(dividend++)] = v1;
      result = dividend;
    }
    while ( dividend );
    `boost::detail::crc_table_t<32,79764919,1>::init_table'::`2'::did_init = 1;
  }
  return result;
}
