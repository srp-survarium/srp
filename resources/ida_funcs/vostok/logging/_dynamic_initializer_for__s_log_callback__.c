int __thiscall vostok::logging::_dynamic_initializer_for__s_log_callback__(
        boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *this)
{
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(this, &s_log_callback_0);
  return atexit(vostok::logging::_dynamic_atexit_destructor_for__s_log_callback__);
}
