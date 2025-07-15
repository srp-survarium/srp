void __thiscall survarium::game::resume(survarium::game *this)
{
  float v2; // eax
  vostok::sound::world_user *v3; // ecx
  float time_floating_factor; // [esp+4h] [ebp-8h]

  this->m_is_paused = 0;
  vostok::timing::floating_timer::set_time_factor_impl(
    (vostok::timing::floating_timer *)this,
    (int)&this->m_timer,
    this->m_timer.m_backup_time_factor,
    this->m_timer.m_backup_time_floating_factor);
  time_floating_factor = this->m_last_sound_timescale_factor;
  v2 = COERCE_FLOAT(((int (*)(void))this->m_sound_world->get_logic_world_user)());
  vostok::sound::world_user::set_time_scale_factor(
    v3,
    v2,
    (boost::function<void __cdecl(void)> *)LODWORD(time_floating_factor));
}
