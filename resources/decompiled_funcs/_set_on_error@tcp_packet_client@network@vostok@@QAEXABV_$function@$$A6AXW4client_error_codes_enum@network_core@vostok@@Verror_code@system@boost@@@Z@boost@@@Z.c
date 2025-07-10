void __thiscall vostok::network::tcp_packet_client::set_on_error(
        vostok::network::tcp_packet_client *this,
        boost::function<void __cdecl(unsigned int,unsigned int)> *on_error)
{
  boost::function<void __cdecl (unsigned char,vostok::network_core::packet_reader &)>::operator=(
    on_error,
    (boost::function2<void,unsigned int,unsigned int> *)&this->m_on_error);
}
