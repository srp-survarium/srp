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


void __thiscall vostok::fs_new::query_custom_operation_args::query_custom_operation_args(
        vostok::fs_new::query_custom_operation_args *this,
        boost::function<bool __cdecl(vostok::fs_new::synchronous_device_interface &)> custom_operation,
        boost::function<void __cdecl(bool)> callback,
        vostok::threading::event *event_to_fire_after_execute)
{
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v4; // ecx

  boost::function<void __cdecl (void)>::function<void __cdecl (void)>((boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
    (boost::function1<void,enum vostok::handshaking_error_types_enum> *)this,
    (const boost::function1<void,enum vostok::handshaking_error_types_enum> *)&custom_operation);
  this->result = 0;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>((boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this);
  boost::function0<bool>::assign_to_own(
    (boost::function0<bool> *)&this->callback,
    (const boost::function0<bool> *)&callback);
  this->event_to_fire_after_execute = event_to_fire_after_execute;
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&custom_operation);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(v4);
}
