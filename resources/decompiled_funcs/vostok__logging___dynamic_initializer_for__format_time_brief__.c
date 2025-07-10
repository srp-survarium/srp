int vostok::logging::_dynamic_initializer_for__format_time_brief__()
{
  vostok::logging::format_specifier::format_specifier(&vostok::logging::format_time_brief, format_specifier_time_brief);
  return atexit(vostok::logging::_dynamic_atexit_destructor_for__format_time_brief__);
}
