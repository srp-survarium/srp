vostok::network::functor_response *__thiscall vostok::network::functor_response::`scalar deleting destructor'(
        vostok::network::functor_response *this,
        char a2)
{
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)&this->m_functor);
  this->__vftable = (vostok::network::functor_response_vtbl *)&vostok::network::response::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
