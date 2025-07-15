void __thiscall survarium::bullet_manager::free_bullet(
        survarium::bullet_manager *this,
        survarium::bullet_manager *bullet)
{
  survarium::bullet_manager *thisa; // [esp+0h] [ebp-38h]

  thisa = this;
  if ( this->m_engine )
  {
    this = bullet;
    if ( *((unsigned __int16 *)&bullet->m_air_resistance_epsilon + 3) != 0xFFFF )
      thisa->m_engine->detach_tracer(thisa->m_engine, (survarium::bullet *)bullet);
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::memory::delete_helper<vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>,survarium::bullet>(
    thisa->m_bullets_allocator_ref.m_variable,
    (survarium::bullet **)&bullet);
}
