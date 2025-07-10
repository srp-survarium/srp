int vostok::logging::_dynamic_initializer_for__format_time__()
{
  vostok::logging::format_specifier::format_specifier(&vostok::logging::format_time, format_specifier_time);
  return atexit(vostok::logging::_dynamic_atexit_destructor_for__format_time__);
}
