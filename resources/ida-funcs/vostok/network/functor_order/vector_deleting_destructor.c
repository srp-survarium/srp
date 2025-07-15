vostok::network::functor_order *__thiscall vostok::network::functor_order::`vector deleting destructor'(
        vostok::network::functor_order *this,
        char a2)
{
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)&this->m_functor);
  this->__vftable = (vostok::network::functor_order_vtbl *)&vostok::network::order::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
