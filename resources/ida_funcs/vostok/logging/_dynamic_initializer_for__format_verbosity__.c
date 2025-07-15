int vostok::logging::_dynamic_initializer_for__format_verbosity__()
{
  vostok::logging::format_specifier::format_specifier(&vostok::logging::format_verbosity, format_specifier_verbosity);
  return atexit(vostok::logging::_dynamic_atexit_destructor_for__format_verbosity__);
}
