void __thiscall vostok::sound::sound_scene::process_fade(
        vostok::sound::sound_scene *this,
        vostok::sound::sound_world *world,
        unsigned __int64 time_delta)
{
  if ( this->m_fade_state == move_forward )
  {
    this->m_volume = (double)time_delta * this->m_fade_vol_per_msec + this->m_volume;
    if ( this->m_volume >= 1.0 )
    {
      this->m_volume = FLOAT_1_0;
      this->m_fade_state = none;
    }
    if ( this->m_submix_voice )
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))this->m_submix_voice->SetVolume)(
        this->m_submix_voice,
        this->m_volume,
        0);
  }
  else if ( this->m_fade_state == move_backward )
  {
    this->m_volume = this->m_volume - (double)time_delta * this->m_fade_vol_per_msec;
    if ( this->m_volume < 0.0 || fabs(this->m_volume - 0.0) < 0.0000099999997 )
    {
      this->m_volume = *(float *)&FLOAT_0_0;
      this->m_fade_state = none;
      vostok::sound::sound_scene::pause_propagate_all_sounds(this);
      vostok::sound::sound_world::remove_scene_from_active(world, this);
      this->m_is_active = 0;
    }
    if ( this->m_submix_voice )
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))this->m_submix_voice->SetVolume)(
        this->m_submix_voice,
        this->m_volume,
        0);
  }
}
