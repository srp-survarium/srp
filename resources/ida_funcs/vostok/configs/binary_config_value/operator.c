const vostok::configs::binary_config_value *__usercall vostok::configs::binary_config_value::operator[]@<eax>(
        vostok::configs::binary_config_value *this@<ecx>,
        const int index@<eax>)
{
  return (const vostok::configs::binary_config_value *)((char *)this->data.pointer + 24 * index);
}


const vostok::configs::binary_config_value *__thiscall vostok::configs::binary_config_value::operator[](
        vostok::configs::binary_config_value *this,
        char *key)
{
  const vostok::configs::binary_config_value *pointer; // edi
  const vostok::configs::binary_config_value *v3; // ebp
  const vostok::configs::binary_config_value *v4; // edi
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
  crc = ~processor.rem_;
  LOBYTE(processor.rem_) = 0;
  v4 = stlp_std::priv::__lower_bound<vostok::configs::binary_config_value const *,unsigned int,stlp_std::priv::__less_2<vostok::configs::binary_config_value,unsigned int>,stlp_std::priv::__less_2<unsigned int,vostok::configs::binary_config_value>,int>(
         pointer,
         v3,
         &crc);
  while ( strcmp(
            key,
            (const char *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v4->id)) )
    ;
  return v4;
}


unsigned __int8 __usercall vostok::configs::binary_config_value::operator unsigned char@<al>(
        vostok::configs::binary_config_value *this@<ecx>,
        int a2@<eax>)
{
  return *(_BYTE *)a2;
}


unsigned __int16 __usercall vostok::configs::binary_config_value::operator unsigned short@<ax>(
        vostok::configs::binary_config_value *this@<ecx>,
        int a2@<eax>)
{
  return *(_WORD *)a2;
}


void __thiscall vostok::configs::binary_config_value::operator float(vostok::configs::binary_config_value *this)
{
  ;
}


BOOL __thiscall vostok::configs::binary_config_value::operator bool(vostok::configs::binary_config_value *this)
{
  return this->data.pointer != 0;
}
