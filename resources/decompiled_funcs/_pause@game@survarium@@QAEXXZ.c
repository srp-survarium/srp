void __thiscall survarium::game::pause(survarium::game *this)
{
  vostok::timing::timer *p_m_timer; // esi
  LARGE_INTEGER v3; // rax
  vostok::sound::world_user *v4; // eax
  vostok::sound::world_user *v5; // eax
  LARGE_INTEGER PerformanceCount; // [esp+Ch] [ebp-8h] BYREF

  p_m_timer = &this->m_timer;
  this->m_is_paused = 1;
  this->m_timer.m_backup_time_factor = this->m_timer.m_time_factor;
  this->m_timer.m_current_time = vostok::timing::timer::get_elapsed_ticks(&this->m_timer);
  if ( vostok::timing::g_cpu_supports_time_stamp )
  {
    v3.QuadPart = __rdtsc();
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    v3 = PerformanceCount;
  }
  p_m_timer->m_start_time = v3.QuadPart;
  p_m_timer->m_time_factor = 0.0;
  v4 = this->m_sound_world->get_logic_world_user(this->m_sound_world);
  this->m_last_sound_timescale_factor = vostok::sound::world_user::get_time_scale_factor(v4);
  v5 = (vostok::sound::world_user *)((int (*)(void))this->m_sound_world->get_logic_world_user)();
  vostok::sound::world_user::set_time_scale_factor(v5, 0.0);
}
