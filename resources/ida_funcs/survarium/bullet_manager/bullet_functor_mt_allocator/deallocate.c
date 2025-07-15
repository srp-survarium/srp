void __thiscall survarium::bullet_manager::bullet_functor_mt_allocator::deallocate(
        survarium::bullet_manager::bullet_functor_mt_allocator *this,
        survarium::bullet_manager::bullet_functor **functor)
{
  vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,72>::pointer_and_counter comperand; // [esp+1Ch] [ebp-10h]
  unsigned int exchange; // [esp+24h] [ebp-8h]

  exchange = (unsigned int)*functor;
  do
  {
    comperand.whole = (volatile __int64)this->m_bullet_functors.m_top;
    *(_DWORD *)(exchange + 72) = this->m_bullet_functors.m_top.m_pointer;
  }
  while ( vostok::threading::interlocked_compare_exchange(
            &this->m_bullet_functors.m_top.whole,
            __SPAIR64__(comperand.counter, exchange),
            comperand.whole) != comperand.whole );
  *functor = 0;
}
