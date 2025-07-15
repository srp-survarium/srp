void __usercall survarium::match_client::match_client(
        survarium::match_client *this@<edi>,
        vostok::network::world *world@<eax>)
{
  survarium::match_options *v2; // ecx

  vostok::network::match_client::match_client(&this->m_client, world, &this->m_packets_orderer, 0);
  this->m_packets_orderer.__vftable = (survarium::network_packets_orderer<enum vostok::match_client_message_types_enum,enum vostok::match_server_message_types_enum>_vtbl *)&survarium::network_packets_orderer<enum vostok::match_client_message_types_enum,enum vostok::match_server_message_types_enum>::`vftable';
  survarium::match_options::match_options(v2, (int)&this->m_match_options);
  this->m_last_send_queed_packets_time_in_ms = 0;
  this->m_are_there_any_packets_to_send = 0;
}
