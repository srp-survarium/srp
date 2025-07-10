void __thiscall vostok::fs_new::query_custom_operation_args::query_custom_operation_args(
        vostok::fs_new::query_custom_operation_args *this,
        const vostok::fs_new::query_custom_operation_args *__that)
{
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this,
    this);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
    (boost::function1<void,enum vostok::handshaking_error_types_enum> *)this,
    (const boost::function1<void,enum vostok::handshaking_error_types_enum> *)__that);
  this->result = __that->result;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&this->callback,
    &this->callback.vtable);
  boost::function0<bool>::assign_to_own(
    (boost::function0<bool> *)&this->callback,
    (const boost::function0<bool> *)&__that->callback);
  this->event_to_fire_after_execute = __that->event_to_fire_after_execute;
}
