void __thiscall vostok::engine::engine_world::sound(vostok::engine::engine_world *this)
{
  DWORD CurrentThreadId; // eax
  boost::function0<bool> *m_begin; // ecx
  vostok::command_line::key *v4; // ecx
  vostok::tasks *v5; // ecx
  vostok::command_line::key *v6; // [esp-4h] [ebp-10h]

  CurrentThreadId = GetCurrentThreadId();
  m_begin = (boost::function0<bool> *)g_threads.m_begin;
  g_threads.m_begin[4].m_thread_id = CurrentThreadId;
  vostok::apc::process(sound, m_begin, 1);
  v4 = v6;
  while ( !this->m_destruction_started )
  {
    vostok::resources::dispatch_callbacks(v4);
    this->m_sound_world->tick(this->m_sound_world);
    vostok::threading::yield(0xAu, v5);
  }
  vostok::apc::process(sound, (boost::function0<bool> *)v4, 1);
}
