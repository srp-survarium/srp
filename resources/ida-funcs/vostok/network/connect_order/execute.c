void __thiscall vostok::network::connect_order::execute(vostok::network::connect_order *this)
{
  boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
    &this->m_connector.boost::function2<void,char const *,vostok::network_core::udp_match_packet const *>,
    this->m_host,
    this->m_packet);
}
