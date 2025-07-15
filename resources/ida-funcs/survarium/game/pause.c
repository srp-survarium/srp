void __thiscall survarium::game::pause(survarium::game *this)
{
  vostok::sound::world *m_sound_world; // ecx
  float v3; // eax
  vostok::sound::world_user *v4; // ecx
  float v5; // [esp+Ch] [ebp-4h] BYREF

  this->m_is_paused = 1;
  this->m_timer.m_backup_time_factor = this->m_timer.m_time_factor;
  this->m_timer.m_backup_time_floating_factor = this->m_timer.m_time_floating_factor;
  vostok::timing::floating_timer::set_time_factor_impl(
    (vostok::timing::floating_timer *)this,
    (int)&this->m_timer,
    0.0,
    0.0);
  _InterlockedExchange(
    (volatile __int32 *)&v5,
    this->m_sound_world->get_logic_world_user(this->m_sound_world)->m_owner_world->m_time_factor.m_data.m_atomic);
  m_sound_world = this->m_sound_world;
  this->m_last_sound_timescale_factor = v5;
  v3 = COERCE_FLOAT(((int (*)(void))m_sound_world->get_logic_world_user)());
  vostok::sound::world_user::set_time_scale_factor(v4, v3, COERCE_BOOST_FUNCTION_VOID_CDECL_VOID_(0.0));
}
