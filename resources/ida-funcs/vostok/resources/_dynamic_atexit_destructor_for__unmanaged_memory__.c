void vostok::resources::_dynamic_atexit_destructor_for__unmanaged_memory__()
{
  DeleteCriticalSection((LPCRITICAL_SECTION)&vostok::resources::unmanaged_memory.queue.vostok::threading::mutex);
}
