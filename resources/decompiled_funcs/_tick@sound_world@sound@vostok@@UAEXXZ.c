void __thiscall vostok::sound::sound_world::tick(vostok::sound::sound_world *this)
{
  vostok::sound::sound_scene *scene; // [esp+10h] [ebp-Ch]
  unsigned int current_time_in_ms; // [esp+14h] [ebp-8h]
  unsigned int time_delta; // [esp+18h] [ebp-4h]

  current_time_in_ms = 1000
                     * vostok::timing::timer::get_elapsed_ticks(&this->m_timer)
                     / vostok::timing::g_qpc_per_second.QuadPart;
  time_delta = current_time_in_ms - this->m_last_current_time_in_ms;
  vostok::sound::sound_world::process_orders(this);
  for ( scene = this->m_active_scenes.m_first; scene; scene = scene->m_next )
    vostok::sound::sound_scene::tick(scene, this, time_delta);
  vostok::sound::sound_world::try_delete_stoping_voices(this);
  this->m_last_current_time_in_ms = current_time_in_ms;
}
