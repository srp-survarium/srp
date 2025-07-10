vostok::strings::shared::profile *__thiscall vostok::strings::shared::manager::string(
        vostok::strings::shared::manager *this,
        vostok::strings::shared::manager *value,
        const char *valuea)
{
  unsigned int m_checksum; // edi
  vostok::strings::shared::profile *m_value; // esi
  unsigned int m_length; // ecx
  vostok::strings::shared::profile *v6; // eax
  bool v7; // cf
  unsigned __int8 v8; // dl
  int v9; // eax
  vostok::strings::shared::profile *v11; // esi
  char *v12; // eax
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator i; // [esp+10h] [ebp-28h] BYREF
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator v14; // [esp+1Ch] [ebp-1Ch] BYREF
  vostok::strings::shared::profile query; // [esp+28h] [ebp-10h] BYREF

  query.m_reference_count = 0;
  if ( !valuea )
    valuea = (const char *)&buf;
  vostok::strings::shared::profile::create_temp(valuea, &query);
  vostok::threading::mutex::lock(&value->m_mutex);
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
    (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&query,
    &i,
    &value->m_storage);
  m_checksum = query.m_checksum;
  while ( 1 )
  {
    m_value = i.m_value;
    if ( !i.m_value || i.m_value->m_checksum != m_checksum )
      break;
    m_length = query.m_length;
    if ( i.m_value->m_length == query.m_length )
    {
      m_length = (unsigned int)valuea;
      v6 = i.m_value + 1;
      while ( 1 )
      {
        v7 = LOBYTE(v6->m_reference_count) < *(_BYTE *)m_length;
        if ( LOBYTE(v6->m_reference_count) != *(_BYTE *)m_length )
          break;
        if ( !LOBYTE(v6->m_reference_count) )
          goto LABEL_12;
        v8 = BYTE1(v6->m_reference_count);
        v7 = v8 < *(_BYTE *)(m_length + 1);
        if ( v8 != *(_BYTE *)(m_length + 1) )
          break;
        v6 = (vostok::strings::shared::profile *)((char *)v6 + 2);
        m_length += 2;
        if ( !v8 )
        {
LABEL_12:
          v9 = 0;
          goto LABEL_14;
        }
      }
      v9 = -v7 - (v7 - 1);
LABEL_14:
      if ( !v9 )
      {
        LeaveCriticalSection((LPCRITICAL_SECTION)value);
        return m_value;
      }
    }
    vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
      (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator *)m_length,
      &v14,
      (__int64 *)&i);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)value);
  v11 = vostok::strings::shared::profile::create(&value->m_mutex, valuea, &query);
  vostok::threading::mutex::lock(&value->m_mutex);
  v12 = (char *)&value->m_storage.m_buffer[v11->m_checksum & 0x7FFF];
  v11->next_in_hashset = *(vostok::strings::shared::profile **)v12;
  *(_DWORD *)v12 = v11;
  ++*(_UNKNOWN **)((char *)&off_20004 + (_DWORD)&value->m_storage);
  LeaveCriticalSection((LPCRITICAL_SECTION)value);
  return v11;
}
