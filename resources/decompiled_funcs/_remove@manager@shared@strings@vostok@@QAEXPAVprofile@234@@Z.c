void __thiscall vostok::strings::shared::manager::remove(
        vostok::strings::shared::manager *this,
        vostok::strings::shared::manager *profile,
        vostok::strings::shared::profile *profilea)
{
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator i; // [esp+14h] [ebp-18h] BYREF
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator v4; // [esp+20h] [ebp-Ch] BYREF

  vostok::threading::mutex::lock(&profile->m_mutex);
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
    (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)profilea,
    &i,
    &profile->m_storage);
  while ( i.m_value && i.m_value != profilea )
    vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
      (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator *)i.m_value,
      &v4,
      (__int64 *)&i);
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::erase(
    &profile->m_storage,
    i.m_index,
    i.m_value);
  LeaveCriticalSection((LPCRITICAL_SECTION)profile);
  vostok::strings::shared::profile::destroy(&profile->m_mutex, profilea);
}
