void __thiscall survarium::bullet_manager::bullet_functor_mt_allocator::bullet_functor_mt_allocator(
        survarium::bullet_manager::bullet_functor_mt_allocator *this,
        survarium::bullet_manager::bullet_functor *buffer,
        unsigned int buffer_size)
{
  vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,72>::pointer_and_counter comperand; // [esp+18h] [ebp-20h]
  survarium::bullet_manager::bullet_functor *i; // [esp+34h] [ebp-4h]

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  this->m_bullet_functors.m_top.whole = 0;
  this->m_buffer = buffer;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  for ( i = buffer; i != &buffer[buffer_size / 0x58]; ++i )
  {
    do
    {
      comperand.whole = (volatile __int64)this->m_bullet_functors.m_top;
      i->next = this->m_bullet_functors.m_top.m_pointer;
    }
    while ( vostok::threading::interlocked_compare_exchange(
              &this->m_bullet_functors.m_top.whole,
              __SPAIR64__(comperand.counter, (unsigned int)i),
              comperand.whole) != comperand.whole );
  }
}
