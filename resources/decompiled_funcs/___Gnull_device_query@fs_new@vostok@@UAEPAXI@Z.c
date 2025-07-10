vostok::fs_new::null_device_query *__thiscall vostok::fs_new::null_device_query::`scalar deleting destructor'(
        vostok::fs_new::null_device_query *this,
        char a2)
{
  this->__vftable = (vostok::fs_new::null_device_query_vtbl *)&vostok::fs_new::null_device_query::`vftable';
  this->__vftable = (vostok::fs_new::null_device_query_vtbl *)&vostok::fs_new::asynchronous_device_query::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
