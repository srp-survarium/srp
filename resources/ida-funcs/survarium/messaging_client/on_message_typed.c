void __userpurge survarium::messaging_client::on_message_typed(
        survarium::chat_handler *receiver_name@<ecx>,
        int message_chanel@<eax>,
        int this,
        char *input_text)
{
  survarium::messaging_client *v4; // ebx
  bool v7; // zf
  vostok::network_core::buffer_writer *v8; // ecx
  vostok::network_core::buffer_writer *v9; // ecx
  vostok::network_core::buffer_writer *v10; // ecx
  vostok::network_core::buffer_writer *v11; // ecx
  vostok::network_core::buffer_writer *v12; // ecx
  vostok::network::tcp_packet_client *v13; // ecx
  vostok::network_core::buffer_writer *v14; // ecx
  vostok::network_core::mutable_buffer *v15; // ecx
  char _Dst[260]; // [esp+10h] [ebp-130h] BYREF
  vostok::network_core::tcp_packet v17; // [esp+114h] [ebp-2Ch] BYREF
  int v18; // [esp+13Ch] [ebp-4h]

  v4 = (survarium::messaging_client *)this;
  v7 = *(_DWORD *)(this + 136) == 3;
  v18 = message_chanel;
  if ( v7 )
  {
    survarium::chat_handler::add_message(
      receiver_name,
      *(vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(this + 4),
      (survarium::private_channel_tab *)message_chanel,
      input_text,
      (char *)(this + 280));
    if ( message_chanel == 4 )
      survarium::chat_handler::add_to_recent_list((const char *)receiver_name, v4->m_chat_handler);
    strcpy_s(_Dst, 0x100u, input_text);
    this = 0;
    switch ( message_chanel )
    {
      case 1:
        this = v4->m_localization_group_channel;
        break;
      case 3:
        return;
      case 4:
        this = 0;
        break;
      case 5:
        this = v4->m_match_channel_id_;
        v7 = this == -1;
LABEL_15:
        if ( v7 )
          return;
        break;
      default:
        if ( message_chanel > 5 )
        {
          if ( message_chanel <= 7 )
          {
            this = v4->m_match_channel_id_;
            if ( this == -1 )
              return;
            v18 = (v4->m_game_team_id != team_1) + 6;
          }
          else if ( message_chanel == 8 )
          {
            this = -1;
            v7 = v4->m_match_channel_id_ == -1;
            goto LABEL_15;
          }
        }
        break;
    }
    vostok::network_core::tcp_packet::tcp_packet(
      (vostok::network_core::tcp_packet *)&vostok::memory::g_mt_allocator,
      (int)&v17);
    HIBYTE(input_text) = -63;
    vostok::network_core::buffer_writer::w(
      v8,
      &v17.m_writer.serialization_operations_descriptors.m_size,
      (unsigned __int8 *)&input_text + 3,
      1u);
    vostok::network_core::buffer_writer::w(
      v9,
      &v17.m_writer.serialization_operations_descriptors.m_size,
      (unsigned __int8 *)&this,
      4u);
    vostok::network_core::buffer_writer::w_string(v10, (char *)&v17.m_writer, (int)receiver_name);
    HIBYTE(input_text) = v18;
    vostok::network_core::buffer_writer::w(
      v11,
      &v17.m_writer.serialization_operations_descriptors.m_size,
      (unsigned __int8 *)&input_text + 3,
      1u);
    vostok::network_core::buffer_writer::w_string(v12, (char *)&v17.m_writer, (int)_Dst);
    vostok::network::tcp_packet_client::send(v13, (const vostok::network_core::tcp_packet *)&v4->m_network_client, &v17);
    vostok::network_core::buffer_writer::~buffer_writer(v14, &v17.m_writer.serialization_operations_descriptors);
    vostok::network_core::mutable_buffer::~mutable_buffer(v15, &v17);
    return;
  }
  survarium::chat_handler::add_message(
    receiver_name,
    *(vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(this + 4),
    (survarium::private_channel_tab *)2,
    "not connected to messaging server...",
    "System");
}
