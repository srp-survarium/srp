void __cdecl vostok::resources::_dynamic_atexit_destructor_for__managed_memory__()
{
  DeleteCriticalSection((LPCRITICAL_SECTION)&vostok::resources::managed_memory.queue.vostok::threading::mutex);
}
