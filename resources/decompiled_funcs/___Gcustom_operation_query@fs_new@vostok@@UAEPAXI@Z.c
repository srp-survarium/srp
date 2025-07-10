vostok::fs_new::custom_operation_query *__thiscall vostok::fs_new::custom_operation_query::`scalar deleting destructor'(
        vostok::fs_new::custom_operation_query *this,
        char a2)
{
  boost::function4<float,char const *,char const *,float,float> *p_m_args; // [esp+8h] [ebp-Ch]

  this->__vftable = (vostok::fs_new::custom_operation_query_vtbl *)&vostok::fs_new::custom_operation_query::`vftable';
  p_m_args = (boost::function4<float,char const *,char const *,float,float> *)&this->m_args;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)&this->m_args,
    (int *)&this->m_args.callback);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear(p_m_args);
  this->__vftable = (vostok::fs_new::custom_operation_query_vtbl *)&vostok::fs_new::asynchronous_device_query::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
