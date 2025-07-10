void __usercall vostok::strings::shared::profile::create_temp(char *value@<eax>, unsigned int result)
{
  vostok::strings::shared::profile *v2; // ebx
  unsigned int v4; // eax
  unsigned __int8 *v5; // edi

  v2 = (vostok::strings::shared::profile *)result;
  v4 = strlen(value);
  *(_DWORD *)(result + 8) = v4;
  v5 = (unsigned __int8 *)&value[v4];
  result = boost::detail::crc_helper<32,1>::reflect(0xFFFFFFFF);
  boost::detail::crc_table_t<32,79764919,1>::init_table();
  boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&result,
    (unsigned __int8 *)value,
    v5);
  v2->m_checksum = ~result;
}
