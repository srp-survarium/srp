vostok::configs::binary_config_value *__usercall vostok::configs::binary_config_value::operator=@<eax>(
        vostok::configs::binary_config_value *this@<ecx>,
        vostok::configs::binary_config_value *result@<eax>)
{
  *result = *this;
  return result;
}


const vostok::configs::binary_config_value *__usercall vostok::configs::binary_config_value::operator[]@<eax>(
        vostok::configs::binary_config_value *this@<eax>,
        char *key@<edi>)
{
  const vostok::configs::binary_config_value *pointer; // ebx
  const vostok::configs::binary_config_value *v3; // esi
  const vostok::configs::binary_config_value *v4; // esi
  const char *v5; // ebx
  unsigned int __val; // [esp+8h] [ebp-4h] BYREF

  pointer = (const vostok::configs::binary_config_value *)this->data.pointer;
  v3 = (const vostok::configs::binary_config_value *)((char *)this->data.pointer + 24 * this->count);
  __val = boost::detail::crc_helper<32,1>::reflect(0xFFFFFFFF);
  boost::detail::crc_table_t<32,79764919,1>::init_table();
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&__val,
    key,
    &key[strlen(key)]);
  __val = ~__val;
  v4 = stlp_std::lower_bound<vostok::configs::binary_config_value const *,unsigned int>(pointer, v3, &__val);
  v5 = v4->id.pointer;
  while ( vostok::strings::compare(key, v5) )
    ;
  return v4;
}
