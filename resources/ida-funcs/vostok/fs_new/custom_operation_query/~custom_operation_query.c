void __thiscall vostok::fs_new::custom_operation_query::~custom_operation_query(
        vostok::fs_new::custom_operation_query *this)
{
  int *p_m_args; // ebx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx

  p_m_args = (int *)&this->m_args;
  this->__vftable = (vostok::fs_new::custom_operation_query_vtbl *)&vostok::fs_new::custom_operation_query::`vftable';
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)&this->m_args.callback);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v3, p_m_args);
  this->__vftable = (vostok::fs_new::custom_operation_query_vtbl *)&vostok::fs_new::asynchronous_device_query::`vftable';
}
