vostok::fs_new::custom_operation_query *__thiscall vostok::fs_new::custom_operation_query::`scalar deleting destructor'(
        vostok::fs_new::custom_operation_query *this,
        char a2)
{
  vostok::fs_new::custom_operation_query::~custom_operation_query(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
