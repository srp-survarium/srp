int vostok::logging::_dynamic_initializer_for__format_message__()
{
  vostok::logging::format_specifier::format_specifier(&vostok::logging::format_message, format_specifier_message);
  return atexit(vostok::logging::_dynamic_atexit_destructor_for__format_message__);
}
