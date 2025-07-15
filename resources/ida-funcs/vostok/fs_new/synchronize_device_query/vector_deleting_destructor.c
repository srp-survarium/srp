vostok::fs_new::synchronize_device_query *__thiscall vostok::fs_new::synchronize_device_query::`vector deleting destructor'(
        vostok::fs_new::synchronize_device_query *this,
        char a2)
{
  vostok::fs_new::synchronize_device_query::~synchronize_device_query(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
