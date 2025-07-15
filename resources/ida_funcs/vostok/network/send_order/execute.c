void __thiscall vostok::network::send_order::execute(vostok::network::send_order *this)
{
  boost::function1<void,vostok::ai::sensors::sensed_object const &>::operator()(
    (boost::function1<void,vostok::ai::sensors::sensed_object const &> *)&this->m_sender,
    (const vostok::ai::sensors::sensed_object *)this->m_packet);
}
