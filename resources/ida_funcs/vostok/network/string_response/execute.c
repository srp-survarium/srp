void __thiscall vostok::network::string_response::execute(vostok::network::string_order *this)
{
  if ( this->m_string1 )
  {
    if ( this->m_string2 )
      boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::operator()(
        (boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *> *)&this->m_functor2,
        (const vostok::ai::brain_unit *)this->m_string0,
        (const vostok::ai::npc *)this->m_string1,
        (const vostok::ai::weapon *)this->m_string2);
    else
      boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
        (boost::function2<void,char const *,vostok::network_core::udp_match_packet const *> *)&this->m_functor1,
        this->m_string0,
        (const vostok::network_core::udp_match_packet *)this->m_string1);
  }
  else
  {
    boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
      (boost::function1<void,char const *> *)this->m_string0,
      &this->m_functor0.vtable,
      this->m_string0);
  }
}
