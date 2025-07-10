void __thiscall survarium::game::resume(survarium::game *this)
{
  vostok::sound::world_user *v2; // eax
  float factor; // [esp+0h] [ebp-Ch]

  this->m_is_paused = 0;
  vostok::timing::timer::resume((vostok::timing::timer *)this, (int)&this->m_timer);
  factor = this->m_last_sound_timescale_factor;
  v2 = (vostok::sound::world_user *)((int (*)(void))this->m_sound_world->get_logic_world_user)();
  vostok::sound::world_user::set_time_scale_factor(v2, factor);
}
