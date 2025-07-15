char __userpurge vostok::fs_new::asynchronous_device_interface::query_custom_operation@<al>(
        vostok::memory::base_allocator *allocator@<eax>,
        vostok::fs_new::asynchronous_device_interface *this,
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *args)
{
  char *v4; // eax
  vostok::fs_new::custom_operation_query *v5; // eax
  vostok::fs_new::asynchronous_device_query *v6; // eax
  vostok::fs_new::custom_operation_query v8; // [esp+10h] [ebp-78h] BYREF

  if ( this->m_device_mode )
  {
    v4 = type_info::raw_name(&vostok::fs_new::custom_operation_query `RTTI Type Descriptor');
    v5 = (vostok::fs_new::custom_operation_query *)allocator->call_malloc(
                                                     allocator,
                                                     120,
                                                     v4,
                                                     "vostok::fs_new::asynchronous_device_interface::query_custom_operation",
                                                     ".\\asynchronous_device_interface_commands.cpp",
                                                     124);
    if ( !v5 )
      return 0;
    vostok::fs_new::custom_operation_query::custom_operation_query(v5, args, allocator, &this->m_device);
    if ( !v6 )
      return 0;
    vostok::fs_new::asynchronous_device_interface::push_query(this, v6);
  }
  else
  {
    vostok::fs_new::custom_operation_query::custom_operation_query(&v8, args, allocator, &this->m_device);
    vostok::fs_new::custom_operation_query::execute(&v8);
    vostok::fs_new::custom_operation_query::callback_if_needed(&v8);
    vostok::fs_new::custom_operation_query::~custom_operation_query(&v8);
  }
  return 1;
}
