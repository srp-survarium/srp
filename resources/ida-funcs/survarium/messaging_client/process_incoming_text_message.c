void __thiscall survarium::messaging_client::process_incoming_text_message(
        survarium::messaging_client *this,
        vostok::network_core::buffer_reader *reader,
        unsigned int __val)
{
  unsigned int v3; // ebx
  _BYTE *v4; // esi
  vostok::network_core::buffer_reader *v5; // ecx
  survarium::account_list_item *m_buffer; // esi
  survarium::account_list_item *v7; // eax
  _BYTE *v8; // esi
  vostok::network_core::buffer_reader *v9; // ecx
  survarium::chat_handler *v10; // ecx
  int v11; // esi
  int v12; // eax
  vostok::network_core::buffer_reader *v13; // [esp-4h] [ebp-1ACh]
  survarium::lobby_menu *v14; // [esp-4h] [ebp-1ACh]
  unsigned __int8 str1[324]; // [esp+10h] [ebp-198h] BYREF
  unsigned int v16; // [esp+154h] [ebp-54h]
  unsigned __int8 v17[64]; // [esp+158h] [ebp-50h] BYREF
  vostok::network_core::buffer_reader *v18; // [esp+198h] [ebp-10h]
  survarium::private_channel_tab *v19; // [esp+19Ch] [ebp-Ch]
  unsigned __int8 *v20; // [esp+1A4h] [ebp-4h]

  v3 = __val;
  v20 = str1;
  v4 = *(_BYTE **)(__val + 4);
  HIBYTE(__val) = *v4;
  v5 = (vostok::network_core::buffer_reader *)HIBYTE(__val);
  *(_DWORD *)(v3 + 4) = ++v4;
  v18 = v5;
  __val = *(_DWORD *)v4;
  *(_DWORD *)(v3 + 4) = v4 + 4;
  v16 = __val;
  if ( v5 != (vostok::network_core::buffer_reader *)5
    || (m_buffer = (survarium::account_list_item *)reader[31].m_buffer,
        v7 = stlp_std::find<survarium::account_list_item *,unsigned int>(
               (survarium::account_list_item *)reader[30].m_buffer_size,
               &__val,
               m_buffer),
        v5 = v13,
        v7 == m_buffer) )
  {
    vostok::network_core::buffer_reader::r_string(v5, (char *)v3, v17);
    v8 = *(_BYTE **)(v3 + 4);
    HIBYTE(__val) = *v8;
    *(_DWORD *)(v3 + 4) = v8 + 1;
    v19 = (survarium::private_channel_tab *)HIBYTE(__val);
    vostok::network_core::buffer_reader::r_string(v9, (char *)v3, str1);
    if ( v18 == (vostok::network_core::buffer_reader *)8 )
    {
      v11 = *((_DWORD *)reader->m_buffer + 3460);
      strstr(str1, "#mstats");
      if ( v12 )
        survarium::lobby_menu::on_stats_message_arrived(v14, v11);
    }
    else
    {
      survarium::chat_handler::add_message(
        v10,
        (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>)reader->m_pointer,
        v19,
        (const char *)str1,
        (char *)v17);
      survarium::chat_handler::add_to_recent_list((const char *)v17, (survarium::chat_handler *)reader->m_pointer);
    }
  }
}
