const vostok::render::custom_config_value *__userpurge vostok::render::custom_config_value::operator[]@<eax>(
        vostok::render::custom_config_value *this@<ecx>,
        int a2@<eax>,
        boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> key)
{
  unsigned __int8 *rem; // ebx
  const vostok::render::custom_config_value *v4; // edi
  const vostok::render::custom_config_value *v5; // ebp
  unsigned int v6; // ecx
  const vostok::render::custom_config_value *v7; // edi
  unsigned int crc; // [esp+14h] [ebp-4h] BYREF

  rem = (unsigned __int8 *)key.rem_;
  v4 = *(const vostok::render::custom_config_value **)(a2 + 4);
  v5 = &v4[*(unsigned __int16 *)(a2 + 14)];
  key.rem_ = boost::detail::crc_helper<32,1>::reflect(0xFFFFFFFF);
  boost::detail::crc_table_t<32,79764919,1>::init_table();
  boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>::process_block(&key, rem, &rem[strlen((const char *)rem)]);
  v6 = ~key.rem_;
  LOBYTE(key.rem_) = 0;
  crc = v6;
  v7 = stlp_std::priv::__lower_bound<vostok::render::custom_config_value const *,unsigned int,stlp_std::priv::__less_2<vostok::render::custom_config_value,unsigned int>,stlp_std::priv::__less_2<unsigned int,vostok::render::custom_config_value>,int>(
         v4,
         v5,
         &crc);
  while ( strcmp((const char *)rem, v7->id) )
    ;
  return v7;
}
