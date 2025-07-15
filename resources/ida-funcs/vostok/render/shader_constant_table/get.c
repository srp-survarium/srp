vostok::render::shader_constant *__userpurge vostok::render::shader_constant_table::get@<eax>(
        vostok::render::shader_constant_table *this@<ecx>,
        int a2@<eax>,
        char *name)
{
  int v3; // edi
  int v4; // eax
  int v5; // eax
  vostok::threading::mutex *v6; // edi
  vostok::render::shader_constant_table *v8; // [esp-4h] [ebp-38h]
  vostok::strings::shared::profile *v9; // [esp+0h] [ebp-34h]
  vostok::strings::shared::profile *v10; // [esp+0h] [ebp-34h]
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator v11; // [esp+Ch] [ebp-28h] BYREF
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator v12; // [esp+18h] [ebp-1Ch] BYREF
  int v13; // [esp+24h] [ebp-10h]
  vostok::threading::mutex *mutex; // [esp+28h] [ebp-Ch] BYREF
  int v15; // [esp+2Ch] [ebp-8h]
  bool v16; // [esp+33h] [ebp-1h]

  v3 = *(_DWORD *)(a2 + 4);
  v4 = *(_DWORD *)(a2 + 8);
  v15 = v3;
  v13 = v4;
  if ( v3 == v4 )
    return 0;
  while ( 1 )
  {
    vostok::shared_string::shared_string(
      (vostok::shared_string *)this,
      (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&mutex,
      name);
    v5 = *(_DWORD *)(v3 + 16);
    v6 = mutex;
    v16 = *(_DWORD *)(v5 + 32) == (_DWORD)mutex;
    if ( mutex )
    {
      this = (vostok::render::shader_constant_table *)_InterlockedExchangeAdd(
                                                        (volatile signed __int32 *)mutex,
                                                        0xFFFFFFFF);
      if ( !this )
      {
        vostok::threading::mutex::lock(0, &s_manager_buffer);
        vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
          (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v6,
          &v12,
          (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
          v9);
        while ( v12.m_value && (vostok::threading::mutex *)v12.m_value != v6 )
          vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
            &v12,
            &v11);
        vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::erase(
          (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
          v12.m_index,
          v12.m_value);
        LeaveCriticalSection(&s_manager_buffer);
        vostok::strings::shared::profile::destroy(v6, v10);
        this = v8;
      }
    }
    if ( v16 )
      break;
    v15 += 24;
    if ( v15 == v13 )
      return 0;
    v3 = v15;
  }
  return (vostok::render::shader_constant *)v15;
}
