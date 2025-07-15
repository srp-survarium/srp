void boost::detail::crc_table_t<32,79764919,1>::init_table()
{
  signed int v0; // edi
  unsigned __int8 v1; // al
  unsigned __int8 v2; // al
  char v3; // cl
  unsigned __int8 v4; // bl
  int v5; // esi
  unsigned int v6; // eax
  bool v7; // zf
  unsigned __int8 v8; // [esp+1h] [ebp-1h]

  if ( !`boost::detail::crc_table_t<32,79764919,1>::init_table'::`2'::did_init )
  {
    v8 = 0;
    do
    {
      v0 = 0;
      v1 = 0x80;
      do
      {
        if ( (v1 & v8) != 0 )
          v0 ^= 0x80000000;
        if ( v0 >= 0 )
          v0 *= 2;
        else
          v0 = (2 * v0) ^ 0x4C11DB7;
        v1 >>= 1;
      }
      while ( v1 );
      v2 = v8;
      v3 = 7;
      v4 = 0;
      v5 = 8;
      do
      {
        if ( (v2 & 1) != 0 )
          v4 |= 1 << v3;
        --v3;
        v2 >>= 1;
        --v5;
      }
      while ( v5 );
      v6 = boost::detail::crc_helper<32,1>::reflect(v0);
      v7 = v8++ == 0xFF;
      boost::detail::crc_table_t<32,79764919,1>::table_[v4] = v6;
    }
    while ( !v7 );
    `boost::detail::crc_table_t<32,79764919,1>::init_table'::`2'::did_init = 1;
  }
}
