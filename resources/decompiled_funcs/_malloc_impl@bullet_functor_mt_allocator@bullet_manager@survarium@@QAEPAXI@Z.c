survarium::bullet_manager::bullet_functor *__thiscall survarium::bullet_manager::bullet_functor_mt_allocator::malloc_impl(
        survarium::bullet_manager::bullet_functor_mt_allocator *this,
        survarium::game_camera *size)
{
  _BYTE *v2; // eax
  survarium::game_camera *v3; // ecx
  survarium::bullet_manager::bullet_functor *v6; // [esp+18h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v2 )
    survarium::weapon_user_dead_state::finalize(size);
  v6 = vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,72>::try_pop(&this->m_bullet_functors);
  survarium::weapon_user_dead_state::finalize(v3);
  return v6;
}
