void __thiscall vostok::sound::sound_world::set_time_scale_factor(vostok::sound::sound_world *this, float factor)
{
  float v3; // xmm0_4
  vostok::sound::sound_scene *j; // edi
  vostok::sound::sound_scene *i; // edi
  float v6; // [esp+Ch] [ebp-4h] BYREF

  _InterlockedExchange((volatile __int32 *)&v6, this->m_time_factor.m_data.m_atomic);
  v3 = 0.0;
  if ( factor > 0.0 )
  {
    v3 = retry_to_increase_quality_period_sec;
    if ( factor <= 2.0 )
      v3 = factor;
  }
  if ( fabs(v6 - v3) >= 0.0000099999997 )
  {
    this->m_timer.m_current_time = vostok::timing::timer::get_elapsed_ticks(
                                     (vostok::timing::timer *)_InterlockedExchange(
                                                                &this->m_time_factor.m_data.m_atomic,
                                                                SLODWORD(v3)),
                                     (int)&this->m_timer);
    this->m_timer.m_start_time = vostok::timing::get_QPC().QuadPart;
    this->m_timer.m_time_factor = v3;
    if ( COERCE_FLOAT(LODWORD(v3) & 0x7FFFFFFF) >= 0.0000099999997 )
    {
      if ( COERCE_FLOAT(LODWORD(v6) & 0x7FFFFFFF) < 0.0000099999997 )
      {
        for ( i = this->m_active_scenes.m_first; i; i = i->m_next )
          i->m_is_paused = 0;
      }
    }
    else
    {
      for ( j = this->m_active_scenes.m_first; j; j = j->m_next )
        j->m_is_paused = 1;
    }
  }
}
