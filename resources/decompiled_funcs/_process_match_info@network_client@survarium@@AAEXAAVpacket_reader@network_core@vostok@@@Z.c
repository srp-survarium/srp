void __userpurge survarium::network_client::process_match_info(
        vostok::network_core::packet_reader *reader@<esi>,
        survarium::network_client *this)
{
  survarium::match_options *p_m_match_options; // edi

  p_m_match_options = &this->match_client(this)->m_match_options;
  survarium::match_options::deserialize(p_m_match_options, reader);
  this->match_client(this)->m_match_options.received_players_count = 0;
}
