void __thiscall vostok::network_core::udp_match_client::on_error(
        vostok::network_core::udp_match_client *this,
        vostok::network_core::client_error_codes_enum __formal,
        const boost::system::error_code a3)
{
  vostok::network_core::udp_match_connection::instant_disconnect(
    &this->m_connection,
    (boost::function4<void,unsigned int,float,float,char const *> *)1);
}
