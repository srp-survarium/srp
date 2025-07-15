bool __userpurge vostok::configs::binary_config_value::value_exists@<al>(
        vostok::configs::binary_config_value *this@<ecx>,
        int a2@<eax>,
        unsigned int key)
{
  char *v3; // ebx
  const vostok::configs::binary_config_value *v4; // esi
  unsigned int v5; // edi
  const vostok::configs::binary_config_value *v6; // eax
  const vostok::configs::binary_config_value *__first; // [esp+Ch] [ebp-4h]

  v3 = (char *)key;
  __first = *(const vostok::configs::binary_config_value **)a2;
  v4 = (const vostok::configs::binary_config_value *)(*(_DWORD *)a2 + 24 * *(unsigned __int16 *)(a2 + 22));
  key = boost::detail::crc_helper<32,1>::reflect(0xFFFFFFFF);
  boost::detail::crc_table_t<32,79764919,1>::init_table();
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&key,
    v3,
    &v3[strlen(v3)]);
  v5 = ~key;
  key = ~key;
  v6 = stlp_std::lower_bound<vostok::configs::binary_config_value const *,unsigned int>(__first, v4, &key);
  return v6 != v4 && v6->id_crc == v5 && vostok::strings::compare(v3, v6->id.pointer) == 0;
}
