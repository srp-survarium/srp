void __thiscall vostok::fs_new::custom_operation_query::execute(vostok::fs_new::custom_operation_query *this)
{
  bool v2; // al
  vostok::fs_new::synchronous_device_interface *v3; // ecx
  int v4[2]; // [esp+4h] [ebp-Ch] BYREF
  char v5; // [esp+Ch] [ebp-4h]

  v4[0] = 0;
  v4[1] = (int)this->m_device.m_device_file_system;
  v5 = 0;
  boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
    (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)this,
    &this->m_args.custom_operation.vtable,
    (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)v4);
  this->m_result = v2;
  vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(v3, v4);
}
