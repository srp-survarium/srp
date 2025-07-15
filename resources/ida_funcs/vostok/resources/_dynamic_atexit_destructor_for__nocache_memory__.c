void __cdecl vostok::resources::_dynamic_atexit_destructor_for__nocache_memory__()
{
  DeleteCriticalSection((LPCRITICAL_SECTION)&vostok::resources::nocache_memory.queue.vostok::threading::mutex);
}
