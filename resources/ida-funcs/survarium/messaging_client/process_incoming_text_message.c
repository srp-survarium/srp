void __thiscall survarium::messaging_client::process_incoming_text_message(
        survarium::messaging_client *this,
        survarium::lobby_menu *reader,
        vostok::network_core::packet_reader *readera)
{
  unsigned int *m_pointer; // eax
  messaging::client_type_enum v4; // edx
  unsigned int v5; // ecx
  unsigned __int8 *v6; // ebx
  survarium::account_list_item *y_low; // esi
  unsigned int v8; // edi
  unsigned __int8 *v9; // eax
  messaging::message_channel_enum v10; // edx
  unsigned int v11; // edi
  unsigned __int8 *v12; // esi
  unsigned int __val; // [esp+14h] [ebp-9A0h] BYREF
  messaging::send_message_params params; // [esp+18h] [ebp-99Ch] BYREF
  wchar_t w_sender_name[32]; // [esp+70h] [ebp-944h] BYREF
  char body[256]; // [esp+B0h] [ebp-904h] BYREF
  wchar_t w_text[1026]; // [esp+1B0h] [ebp-804h] BYREF

  params.message_body = (char (*)[256])body;
  m_pointer = (unsigned int *)readera->m_pointer;
  v4 = *(unsigned __int8 *)m_pointer;
  m_pointer = (unsigned int *)((char *)m_pointer + 1);
  readera->m_pointer = (const unsigned __int8 *)m_pointer;
  params.sender_type = v4;
  v5 = *m_pointer;
  v6 = (unsigned __int8 *)(m_pointer + 1);
  readera->m_pointer = (const unsigned __int8 *)(m_pointer + 1);
  params.sender_account_id = v5;
  __val = v5;
  if ( v4 != account_client_type
    || (y_low = (survarium::account_list_item *)LODWORD(reader[1].m_inverted_view_matrix.j.y),
        stlp_std::priv::__find<survarium::account_list_item *,unsigned int>(
          (survarium::account_list_item *)LODWORD(reader[1].m_inverted_view_matrix.j.x),
          y_low,
          &__val) == y_low) )
  {
    v8 = *v6;
    readera->m_pointer = v6 + 1;
    memcpy((unsigned __int8 *)params.sender_name, v6 + 1, v8);
    readera->m_pointer = &v6[v8 + 1];
    params.sender_name[v8] = 0;
    v9 = &v6[v8 + 2];
    v10 = v6[v8 + 1];
    readera->m_pointer = v9;
    params.message_channel = v10;
    v11 = *v9;
    v12 = v9 + 1;
    readera->m_pointer = v9 + 1;
    memcpy((unsigned __int8 *)body, v9 + 1, v11);
    readera->m_pointer = &v12[v11];
    body[v11] = 0;
    __val = 0;
    mbstowcs_s(&__val, w_sender_name, 0x20u, params.sender_name, 0xFFFFFFFF);
    __val = 0;
    mbstowcs_s(&__val, w_text, 0x400u, (char *)params.message_body, 0xFFFFFFFF);
    if ( params.sender_type == match_maker_server_client_type )
    {
      survarium::lobby_menu::on_match_message_arrived(
        (survarium::lobby_menu *)reader->survarium::base_game_scene::survarium::game_scene::__vftable[24].show_ui,
        w_text);
    }
    else if ( params.sender_type == stats_processor_server_client_type )
    {
      survarium::lobby_menu::on_stats_message_arrived(
        reader,
        (const wchar_t *)reader->survarium::base_game_scene::survarium::game_scene::__vftable[24].show_ui,
        w_text,
        (messaging::message_channel_enum)w_sender_name);
    }
    else
    {
      survarium::chat_handler::add_message(
        (survarium::chat_handler *)reader->m_render_scene.m_object,
        (const messaging::message_channel_enum)reader->m_render_scene.m_object,
        (const wchar_t *)params.message_channel,
        w_text);
      survarium::chat_handler::add_to_recent_list(
        (survarium::chat_handler *)reader->m_render_scene.m_object,
        w_sender_name);
    }
  }
}
