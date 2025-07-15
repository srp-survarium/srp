vostok::sound::sound_instance_proxy_order_with_data<vostok::sound::create_sound_propagator_params> *__thiscall vostok::sound::sound_instance_proxy_order_with_data<vostok::sound::create_sound_propagator_params>::`scalar deleting destructor'(
        vostok::sound::sound_instance_proxy_order_with_data<vostok::sound::create_sound_propagator_params> *this,
        char a2)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx

  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)&this->m_functor);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&this->vostok::sound::sound_instance_proxy_order::m_functor);
  this->__vftable = (vostok::sound::sound_instance_proxy_order_with_data<vostok::sound::create_sound_propagator_params>_vtbl *)&vostok::sound::sound_order::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
