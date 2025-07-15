int vostok::logging::_dynamic_initializer_for__format_initiator__()
{
  vostok::logging::format_specifier::format_specifier(&vostok::logging::format_initiator, format_specifier_initiator);
  return atexit(vostok::logging::_dynamic_atexit_destructor_for__format_initiator__);
}
