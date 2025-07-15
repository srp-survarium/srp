survarium::bullet_manager::bullet_functor *__thiscall vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,76>::try_pop(
        vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,76> *this,
        volatile signed __int64 *a2)
{
  volatile signed __int64 *i; // edi
  int v3; // esi
  signed __int64 v5; // [esp+14h] [ebp-8h]

  for ( i = a2; ; i = a2 )
  {
    v3 = *(_DWORD *)i;
    if ( !*(_DWORD *)i )
      break;
    v5 = *i;
    if ( _InterlockedCompareExchange64(i, __SPAIR64__(*((_DWORD *)i + 1) + 1, *(_DWORD *)(v3 + 76)), v5) == v5 )
      return (survarium::bullet_manager::bullet_functor *)v3;
  }
  return 0;
}
