void __thiscall vostok::engine::engine_world::network(vostok::engine::engine_world *this)
{
  DWORD CurrentThreadId; // eax
  boost::function0<bool> *m_begin; // ecx
  boost::function0<bool> *v4; // ecx
  vostok::tasks *v5; // ecx
  boost::function0<bool> *v6; // [esp-4h] [ebp-10h]

  CurrentThreadId = GetCurrentThreadId();
  m_begin = (boost::function0<bool> *)g_threads.m_begin;
  g_threads.m_begin[3].m_thread_id = CurrentThreadId;
  vostok::apc::process(network, m_begin, 1);
  v4 = v6;
  while ( !this->m_destruction_started )
  {
    vostok::engine::engine_world::network_tick(this);
    vostok::threading::yield(1u, v5);
  }
  vostok::apc::process(network, v4, 1);
}
