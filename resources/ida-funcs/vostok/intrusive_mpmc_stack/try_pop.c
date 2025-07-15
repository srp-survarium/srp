survarium::bullet_manager::bullet_functor *__thiscall vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,72>::try_pop(
        vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,72> *this)
{
  __int64 v2; // [esp-10h] [ebp-38h]
  __int64 result; // [esp+18h] [ebp-10h]

  do
  {
    result = this->m_top.whole;
    if ( !this->m_top.m_pointer )
      return 0;
    HIDWORD(v2) = HIDWORD(result) + 1;
    LODWORD(v2) = *(_DWORD *)(result + 72);
  }
  while ( vostok::threading::interlocked_compare_exchange(&this->m_top.whole, v2, result) != result );
  return (survarium::bullet_manager::bullet_functor *)result;
}
