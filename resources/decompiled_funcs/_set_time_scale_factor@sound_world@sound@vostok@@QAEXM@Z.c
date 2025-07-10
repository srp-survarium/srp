void __thiscall vostok::sound::sound_world::set_time_scale_factor(vostok::sound::sound_world *this, float factor)
{
  float time_factor; // [esp+10h] [ebp-84h]
  float m_min_frequency_ratio; // [esp+14h] [ebp-80h]
  float v5; // [esp+7Ch] [ebp-18h] BYREF
  char v6; // [esp+81h] [ebp-13h]
  char v7; // [esp+82h] [ebp-12h]
  char v8; // [esp+83h] [ebp-11h]
  vostok::sound::sound_scene *i; // [esp+84h] [ebp-10h]
  vostok::sound::sound_scene *scene; // [esp+88h] [ebp-Ch]
  float min_freq_ratio; // [esp+8Ch] [ebp-8h]
  float previous_time_factor; // [esp+90h] [ebp-4h]

  v8 = 0;
  _InterlockedExchange((volatile __int32 *)&v5, this->m_time_factor.m_data.m_atomic);
  previous_time_factor = v5;
  if ( this->m_is_audio_device_exist )
    m_min_frequency_ratio = this->m_voice_factory->m_min_frequency_ratio;
  else
    m_min_frequency_ratio = *(float *)&FLOAT_0_0;
  min_freq_ratio = m_min_frequency_ratio;
  if ( m_min_frequency_ratio <= factor )
    time_factor = factor;
  else
    time_factor = *(float *)&FLOAT_0_0;
  if ( fabs(previous_time_factor - time_factor) >= 0.0000099999997 )
  {
    _InterlockedExchange(&this->m_time_factor.m_data.m_atomic, SLODWORD(time_factor));
    vostok::timing::timer::set_time_factor(&this->m_timer, time_factor);
    if ( fabs(time_factor - 0.0) >= 0.0000099999997 )
    {
      if ( this->m_is_audio_device_exist )
        vostok::sound::voice_factory::set_frequency_ratio(this->m_voice_factory, time_factor);
      if ( fabs(previous_time_factor - 0.0) < 0.0000099999997 )
      {
        for ( i = this->m_active_scenes.m_first; i; i = i->m_next )
        {
          v6 = 0;
          vostok::sound::sound_scene::resume(i);
        }
      }
    }
    else
    {
      for ( scene = this->m_active_scenes.m_first; scene; scene = scene->m_next )
      {
        v7 = 0;
        vostok::sound::sound_scene::pause(scene);
      }
    }
  }
}
