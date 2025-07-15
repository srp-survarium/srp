void __thiscall vostok::sound::sound_scene::fade_out(vostok::sound::sound_scene *this, unsigned int time_in_msec)
{
  this->m_fade_state = move_backward;
  this->m_fade_out_time = time_in_msec;
  this->m_fade_vol_per_msec = FLOAT_1_0;
  if ( time_in_msec )
    this->m_fade_vol_per_msec = 1.0 / (double)time_in_msec;
}
