bool __thiscall vostok::configs::binary_config_value::value_exists(
        vostok::configs::binary_config_value *this,
        char *key)
{
  const vostok::configs::binary_config_value *pointer; // ebx
  const vostok::configs::binary_config_value *v3; // ebp
  unsigned int rem; // esi
  unsigned int v5; // esi
  vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v6; // eax
  boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> processor; // [esp+10h] [ebp-8h] BYREF
  unsigned int crc; // [esp+14h] [ebp-4h] BYREF

  pointer = (const vostok::configs::binary_config_value *)this->data.pointer;
  v3 = (const vostok::configs::binary_config_value *)((char *)this->data.pointer + 24 * this->count);
  processor.rem_ = boost::detail::crc_helper<32,1>::reflect(0xFFFFFFFF);
  boost::detail::crc_table_t<32,79764919,1>::init_table();
  boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>::process_block(
    &processor,
    (unsigned __int8 *)key,
    (unsigned __int8 *)&key[strlen(key)]);
  rem = processor.rem_;
  LOBYTE(processor.rem_) = 0;
  v5 = ~rem;
  crc = v5;
  v6 = (vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)stlp_std::priv::__lower_bound<vostok::configs::binary_config_value const *,unsigned int,stlp_std::priv::__less_2<vostok::configs::binary_config_value,unsigned int>,stlp_std::priv::__less_2<unsigned int,vostok::configs::binary_config_value>,int>(pointer, v3, &crc);
  return v6 != (vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v3
      && v6[4].m_object == (vostok::sound::encoded_sound_interface *)v5
      && strcmp(
           key,
           (const char *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr(v6 + 2)) == 0;
}
