void __usercall vostok::strings::shared::manager::collect_garbage(
        vostok::strings::shared::manager *this@<ecx>,
        int a2@<esi>)
{
  remove_predicate v2; // [esp+0h] [ebp-4h] BYREF

  vostok::threading::mutex::lock((vostok::threading::mutex *)a2);
  v2.m_mutex = (vostok::threading::mutex *)a2;
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::clear<remove_predicate>(
    (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)(a2 + 24),
    (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)(a2 + 24),
    &v2);
  LeaveCriticalSection((LPCRITICAL_SECTION)a2);
}
