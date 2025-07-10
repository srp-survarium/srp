bool __usercall vostok::render::custom_config_value::value_exists@<al>(
        vostok::render::custom_config_value *this@<ecx>,
        int a2@<eax>)
{
  const vostok::render::custom_config_value *v2; // ebx
  const vostok::render::custom_config_value *v4; // ebp
  unsigned int rem; // esi
  unsigned int v6; // esi
  const vostok::render::custom_config_value *v7; // eax
  boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> processor; // [esp+10h] [ebp-Ch] BYREF
  stlp_std::priv::__less_2<vostok::render::custom_config_value,unsigned int> __comp1[4]; // [esp+14h] [ebp-8h]
  unsigned int crc; // [esp+18h] [ebp-4h] BYREF

  v2 = *(const vostok::render::custom_config_value **)(a2 + 4);
  v4 = &v2[*(unsigned __int16 *)(a2 + 14)];
  processor.rem_ = boost::detail::crc_helper<32,1>::reflect(0xFFFFFFFF);
  boost::detail::crc_table_t<32,79764919,1>::init_table();
  boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>::process_block(
    &processor,
    (unsigned __int8 *)this,
    (unsigned __int8 *)this + strlen((const char *)this));
  rem = processor.rem_;
  LOBYTE(processor.rem_) = 0;
  __comp1[0] = 0;
  v6 = ~rem;
  crc = v6;
  v7 = stlp_std::priv::__lower_bound<vostok::render::custom_config_value const *,unsigned int,stlp_std::priv::__less_2<vostok::render::custom_config_value,unsigned int>,stlp_std::priv::__less_2<unsigned int,vostok::render::custom_config_value>,int>(
         v2,
         v4,
         &crc);
  return v7 != v4 && v7->id_crc == v6 && strcmp((const char *)this, v7->id) == 0;
}
