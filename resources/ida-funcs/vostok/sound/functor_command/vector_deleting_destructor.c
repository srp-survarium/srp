vostok::sound::functor_command<vostok::sound::sound_order> *__thiscall vostok::sound::functor_command<vostok::sound::sound_order>::`vector deleting destructor'(
        vostok::sound::functor_command<vostok::sound::sound_order> *this,
        char a2)
{
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)&this->m_functor);
  this->__vftable = (vostok::sound::functor_command<vostok::sound::sound_order>_vtbl *)&vostok::sound::sound_order::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


vostok::sound::functor_command<vostok::sound::sound_response> *__thiscall vostok::sound::functor_command<vostok::sound::sound_response>::`vector deleting destructor'(
        vostok::sound::functor_command<vostok::sound::sound_response> *this,
        char a2)
{
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)&this->m_functor);
  this->__vftable = (vostok::sound::functor_command<vostok::sound::sound_response>_vtbl *)&vostok::sound::sound_response::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
