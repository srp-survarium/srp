lobby::client_state_enum __usercall survarium::lobby_client::status@<eax>(
        survarium::lobby_client *this@<esi>,
        vostok::fixed_string<128> *dest@<eax>)
{
  lobby::client_state_enum result; // eax

  switch ( this->m_status )
  {
    case surf_lobby_menu:
      vostok::buffer_string::assignf(dest, "Lobby menu. %s", this->m_last_status_message.m_begin);
      result = this->m_status;
      break;
    case in_match_making_order:
      vostok::buffer_string::assignf(
        dest,
        "In match making. order[%d] %s",
        this->m_match_order_id,
        this->m_last_status_message.m_begin);
      result = this->m_status;
      break;
    case in_match_making:
      vostok::buffer_string::assignf(
        dest,
        "In match making. match [%d] order[%d] %s",
        this->m_match_id,
        this->m_match_order_id,
        this->m_last_status_message.m_begin);
      result = this->m_status;
      break;
    case in_match:
      vostok::buffer_string::assignf(
        dest,
        "Waiting for match served[%d] order[%d] %s",
        this->m_match_id,
        this->m_match_order_id,
        this->m_last_status_message.m_begin);
      goto LABEL_6;
    default:
LABEL_6:
      result = this->m_status;
      break;
  }
  return result;
}
