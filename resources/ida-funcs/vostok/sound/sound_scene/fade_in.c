void __thiscall vostok::sound::sound_scene::fade_in(
        vostok::sound::sound_scene *this,
        vostok::sound::sound_world *world,
        unsigned int time_in_msec)
{
  if ( !this->m_is_active )
  {
    vostok::sound::sound_world::add_scene_to_active(world, this);
    this->m_is_active = 1;
  }
  this->m_fade_state = move_forward;
  this->m_fade_in_time = time_in_msec;
  this->m_fade_vol_per_msec = FLOAT_1_0;
  if ( time_in_msec )
    this->m_fade_vol_per_msec = 1.0 / (double)time_in_msec;
  vostok::sound::sound_scene::resume_propagate_all_sounds(this);
}
