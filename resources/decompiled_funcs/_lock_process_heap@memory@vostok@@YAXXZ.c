void __cdecl vostok::memory::lock_process_heap()
{
  vostok::threading::mutex::lock(s_process_heap_walk.m_variable);
}
