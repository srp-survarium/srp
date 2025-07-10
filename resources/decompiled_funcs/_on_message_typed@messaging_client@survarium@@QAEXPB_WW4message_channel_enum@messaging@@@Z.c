void __userpurge survarium::messaging_client::on_message_typed(
        wchar_t *input_text@<eax>,
        survarium::messaging_client *this,
        const wchar_t *message_chanel)
{
  const wchar_t *v3; // ebx
  wchar_t *v5; // ebp
  unsigned __int16 *v6; // eax
  survarium::messaging_client *v7; // edi
  int m_match_channel_id; // esi
  int v9; // eax
  int v10; // eax
  bool v11; // zf
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v12; // ecx
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v13; // ecx
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v14; // ecx
  unsigned __int8 v15; // kr08_1
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v16; // ecx
  bool has_direct_receiver; // [esp+10h] [ebp-1BCh] BYREF
  bool in_match[4]; // [esp+14h] [ebp-1B8h] BYREF
  vostok::network_core::tcp_packet packet; // [esp+18h] [ebp-1B4h] BYREF
  char receiver_name[32]; // [esp+28h] [ebp-1A4h] BYREF
  wchar_t w_receiver_name[32]; // [esp+48h] [ebp-184h] BYREF
  wchar_t w_sender_name[32]; // [esp+88h] [ebp-144h] BYREF
  char message_body[256]; // [esp+C8h] [ebp-104h] BYREF

  v3 = message_chanel;
  v5 = input_text;
  has_direct_receiver = *input_text == 47;
  v6 = wcsstr(input_text, L" ");
  if ( has_direct_receiver && v6 )
  {
    v5 = v6 + 1;
    wcsncpy_s((unsigned int)message_chanel, w_receiver_name, 0x20u, input_text + 1, v6 - input_text - 1);
    v7 = this;
    in_match[0] = this->m_chat_handler->m_game_ui_mode;
    v3 = (const wchar_t *)survarium::messaging_client::parse_receiver_channel(w_receiver_name, this, in_match[0]);
  }
  else
  {
    v7 = this;
  }
  if ( v3 != (const wchar_t *)4 )
    swprintf_s<32>((wchar_t (*)[32])w_receiver_name, &word_96B534);
  if ( v7->m_connection_state == client_connected )
  {
    *(_DWORD *)in_match = 0;
    mbstowcs_s((unsigned int *)in_match, w_sender_name, 0x20u, v7->m_local_name, 0xFFFFFFFF);
    survarium::chat_handler::add_message(
      (survarium::chat_handler *)w_sender_name,
      (const messaging::message_channel_enum)v7->m_chat_handler,
      v3,
      v5);
    if ( v3 == (const wchar_t *)4 )
    {
      survarium::chat_handler::add_to_recent_list(v7->m_chat_handler, w_receiver_name);
      v7 = this;
    }
    m_match_channel_id = 0;
    *(_DWORD *)in_match = 0;
    v9 = wcstombs_s((unsigned int *)in_match, message_body, 0x100u, v5, 0xFFFFFFFF);
    if ( v9 && v9 != 80 )
      strcpy_s(message_body, 0x100u, "##text conversion error##");
    *(_DWORD *)in_match = 0;
    v10 = wcstombs_s((unsigned int *)in_match, receiver_name, 0x20u, w_receiver_name, 0xFFFFFFFF);
    if ( v10 && v10 != 80 )
      strcpy_s(message_body, 0x100u, "##name conversion error##");
    switch ( (unsigned int)v3 )
    {
      case 3u:
      case 6u:
      case 7u:
        return;
      case 5u:
        m_match_channel_id = v7->m_match_channel_id_;
        v11 = m_match_channel_id == -1;
        goto LABEL_19;
      case 8u:
        m_match_channel_id = -1;
        v11 = v7->m_match_channel_id_ == -1;
LABEL_19:
        if ( !v11 )
          goto $LN1_34;
        return;
      default:
$LN1_34:
        vostok::network_core::tcp_packet::tcp_packet(&packet, &vostok::memory::g_mt_allocator);
        has_direct_receiver = -63;
        vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
          v12,
          (int)&packet,
          (unsigned __int8 *)&has_direct_receiver,
          1u);
        *(_DWORD *)in_match = m_match_channel_id;
        vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
          v13,
          (int)&packet,
          (unsigned __int8 *)in_match,
          4u);
        *(_DWORD *)in_match = strlen(receiver_name);
        has_direct_receiver = in_match[0];
        vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
          (vostok::network_core::packet<vostok::network_core::tcp_packet> *)&has_direct_receiver,
          (int)&packet,
          (unsigned __int8 *)&has_direct_receiver,
          1u);
        vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
          v14,
          (int)&packet,
          (unsigned __int8 *)receiver_name,
          in_match[0]);
        has_direct_receiver = (char)v3;
        vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
          (vostok::network_core::packet<vostok::network_core::tcp_packet> *)&has_direct_receiver,
          (int)&packet,
          (unsigned __int8 *)&has_direct_receiver,
          1u);
        v15 = strlen(message_body);
        has_direct_receiver = v15;
        vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
          v16,
          (int)&packet,
          (unsigned __int8 *)&has_direct_receiver,
          1u);
        vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
          (vostok::network_core::packet<vostok::network_core::tcp_packet> *)message_body,
          (int)&packet,
          (unsigned __int8 *)message_body,
          v15);
        vostok::network::tcp_packet_client::send(&this->m_network_client, &packet);
        if ( packet.m_buffer )
        {
          if ( packet.m_buffer != (unsigned __int8 *)3 )
            packet.m_allocator->call_free(packet.m_allocator, packet.m_buffer - 3);
        }
        break;
    }
  }
  else
  {
    survarium::chat_handler::add_message(
      v7->m_chat_handler,
      (const messaging::message_channel_enum)v7->m_chat_handler,
      (const wchar_t *)2,
      L"not connected to messaging server...");
  }
}
