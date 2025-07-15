void __usercall survarium::packet_sender::on_player_input_changed(
        survarium::packet_sender *this@<edi>,
        survarium::player_update *player_update@<esi>)
{
  vostok::network_core::udp_match_packet *v2; // ebx
  survarium::player_input *v3; // ecx

  v2 = this->m_match_client->new_packet(this->m_match_client, 70);
  survarium::player_input::serialize(v3, &player_update->input.rotation_delta, &v2->m_writer);
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&player_update->time_in_ms,
    &v2->m_writer,
    &v2->m_writer,
    ".\\player_update.cpp",
    (const char *)0x27,
    "survarium::player_update::serialize",
    "time_in_ms");
  this->m_match_client->enqueue(this->m_match_client, v2);
}
