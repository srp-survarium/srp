int vostok::memory::_dynamic_initializer_for__g_mt_allocator__()
{
  return atexit(vostok::memory::_dynamic_atexit_destructor_for__g_mt_allocator__);
}
