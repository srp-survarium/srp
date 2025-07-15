vostok::strings::shared::profile *__thiscall vostok::strings::shared::manager::string(
        vostok::strings::shared::manager *this,
        char *value)
{
  unsigned int v2; // esi
  vostok::threading::mutex *v3; // ecx
  void *m_value; // esi
  vostok::threading::mutex *v6; // ecx
  vostok::memory::doug_lea_allocator *v7; // ecx
  vostok::memory::doug_lea_allocator *v8; // ecx
  unsigned int v9; // eax
  vostok::threading::mutex *v10; // ecx
  vostok::strings::shared::profile **v11; // eax
  unsigned int v12; // [esp-4h] [ebp-44h]
  vostok::strings::shared::profile *v13; // [esp+0h] [ebp-40h]
  const char *v14; // [esp+0h] [ebp-40h]
  const char *v15; // [esp+4h] [ebp-3Ch]
  unsigned int v16; // [esp+8h] [ebp-38h]
  boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> v17; // [esp+10h] [ebp-30h] BYREF
  unsigned int count; // [esp+14h] [ebp-2Ch]
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator v19; // [esp+18h] [ebp-28h] BYREF
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator v20; // [esp+24h] [ebp-1Ch] BYREF
  int v21; // [esp+30h] [ebp-10h] BYREF
  unsigned int v22; // [esp+38h] [ebp-8h]
  unsigned int v23; // [esp+3Ch] [ebp-4h]

  v21 = 0;
  if ( !value )
    value = (char *)uri;
  v22 = strlen(value);
  v17.rem_ = boost::detail::crc_helper<32,1>::reflect(0xFFFFFFFF);
  boost::detail::crc_table_t<32,79764919,1>::init_table();
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(&v17, value, &value[v22]);
  v2 = ~v17.rem_;
  v23 = ~v17.rem_;
  vostok::threading::mutex::lock(v3, &s_manager_buffer);
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
    (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&v21,
    &v19,
    (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
    v13);
  while ( v19.m_value && v19.m_value->m_checksum == v2 )
  {
    if ( v19.m_value->m_length == v22 && !vostok::strings::compare((const char *)&v19.m_value[1], value) )
    {
      m_value = v19.m_value;
      goto LABEL_10;
    }
    vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
      &v19,
      &v20);
  }
  LeaveCriticalSection(&s_manager_buffer);
  count = v22 + 1;
  vostok::threading::mutex::lock(v6, &s_manager_buffer);
  vostok::memory::doug_lea_allocator::user_current_thread_id(v7, (int)&vostok::strings::shared::g_allocator);
  m_value = vostok::memory::doug_lea_allocator::malloc_impl(
              v8,
              (int)&vostok::strings::shared::g_allocator,
              count + 16,
              "shared::string",
              v14,
              v15,
              v16);
  LeaveCriticalSection(&s_manager_buffer);
  v9 = v22;
  v12 = count;
  *((_DWORD *)m_value + 1) = 0;
  *((_DWORD *)m_value + 2) = v9;
  *((_DWORD *)m_value + 3) = v23;
  *(_DWORD *)m_value = 0;
  memcpy((unsigned __int8 *)m_value + 16, (unsigned __int8 *)value, v12);
  vostok::threading::mutex::lock(v10, &s_manager_buffer);
  v11 = &result.m_value + (*((_DWORD *)m_value + 3) & 0x7FFF);
  *((_DWORD *)m_value + 1) = *v11;
  *v11 = (vostok::strings::shared::profile *)m_value;
  ++dword_A2DC34;
LABEL_10:
  LeaveCriticalSection(&s_manager_buffer);
  return (vostok::strings::shared::profile *)m_value;
}
