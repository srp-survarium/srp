void __userpurge vostok::fs_new::custom_operation_query::custom_operation_query(
        vostok::fs_new::custom_operation_query *this@<esi>,
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *args@<edi>,
        vostok::memory::base_allocator *allocator@<edx>,
        const vostok::fs_new::device_file_system_no_watcher_proxy *device)
{
  vostok::fs_new::asynchronous_device_query::asynchronous_device_query(
    this,
    allocator,
    (vostok::threading::event *)args[2].functor.obj_ptr);
  this->__vftable = (vostok::fs_new::custom_operation_query_vtbl *)&vostok::fs_new::custom_operation_query::`vftable';
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    args,
    (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&this->m_args);
  this->m_args.result = (bool)args[1].vtable;
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)((char *)args + 40),
    (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&this->m_args.callback);
  this->m_args.event_to_fire_after_execute = (vostok::threading::event *)args[2].functor.obj_ptr;
  this->m_device = (vostok::fs_new::device_file_system_no_watcher_proxy)device->m_device_file_system;
  this->m_result = 0;
}
