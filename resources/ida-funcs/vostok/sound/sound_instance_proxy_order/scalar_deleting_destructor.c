vostok::sound::sound_instance_proxy_order *__thiscall vostok::sound::sound_instance_proxy_order::`scalar deleting destructor'(
        vostok::sound::sound_instance_proxy_order *this,
        char a2)
{
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)&this->m_functor);
  this->__vftable = (vostok::sound::sound_instance_proxy_order_vtbl *)&vostok::sound::sound_order::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
