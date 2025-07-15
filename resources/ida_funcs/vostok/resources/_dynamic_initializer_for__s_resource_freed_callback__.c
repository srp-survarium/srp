int vostok::resources::_dynamic_initializer_for__s_resource_freed_callback__()
{
  return atexit(vostok::resources::_dynamic_atexit_destructor_for__s_resource_freed_callback__);
}
