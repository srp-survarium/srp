int vostok::logging::_dynamic_initializer_for__format_thread_id__()
{
  vostok::logging::format_specifier::format_specifier(&vostok::logging::format_thread_id, format_specifier_thread_id);
  return atexit(vostok::logging::_dynamic_atexit_destructor_for__format_thread_id__);
}
