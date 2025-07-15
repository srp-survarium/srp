void __userpurge survarium::messaging_client::read_important_message(
        survarium::messaging_client *this@<ecx>,
        int a2@<eax>,
        unsigned int message_id,
        vostok::messaging::important_message_answer answer)
{
  int v5; // eax
  int v6; // ecx
  unsigned int v7; // eax
  unsigned __int8 *v8; // ecx
  vostok::network_core::buffer_writer *v9; // ecx
  vostok::network_core::buffer_writer *v10; // ecx
  vostok::network_core::buffer_writer *v11; // ecx
  vostok::network::tcp_packet_client *v12; // ecx
  vostok::network_core::buffer_writer *v13; // ecx
  vostok::network_core::mutable_buffer *v14; // ecx
  vostok::network_core::tcp_packet v15; // [esp+Ch] [ebp-2Ch] BYREF
  unsigned __int8 v16; // [esp+37h] [ebp-1h] BYREF

  v5 = *(_DWORD *)(a2 + 404);
  v6 = *(_DWORD *)(a2 + 408);
  while ( v5 != v6 && *(_DWORD *)(v5 + 144) != message_id )
    v5 += 152;
  if ( debug_macro_helper_ignore_always_41 || v5 != v6 )
  {
    v8 = *(unsigned __int8 **)(a2 + 408);
    if ( (unsigned __int8 *)(v5 + 152) != v8 )
      stlp_std::priv::__copy_trivial((unsigned __int8 *)(v5 + 152), v8, (unsigned __int8 *)v5);
    *(_DWORD *)(a2 + 408) -= 152;
    vostok::network_core::tcp_packet::tcp_packet(
      (vostok::network_core::tcp_packet *)&vostok::memory::g_mt_allocator,
      (int)&v15);
    v16 = -58;
    vostok::network_core::buffer_writer::w(v9, &v15.m_writer.serialization_operations_descriptors.m_size, &v16, 1u);
    vostok::network_core::buffer_writer::w(
      v10,
      &v15.m_writer.serialization_operations_descriptors.m_size,
      (unsigned __int8 *)&message_id,
      4u);
    HIBYTE(message_id) = answer;
    vostok::network_core::buffer_writer::w(
      v11,
      &v15.m_writer.serialization_operations_descriptors.m_size,
      (unsigned __int8 *)&message_id + 3,
      1u);
    vostok::network::tcp_packet_client::send(v12, (const vostok::network_core::tcp_packet *)(a2 + 144), &v15);
    vostok::network_core::buffer_writer::~buffer_writer(v13, &v15.m_writer.serialization_operations_descriptors);
    vostok::network_core::mutable_buffer::~mutable_buffer(v14, &v15);
  }
  else
  {
    v7 = occurances_left_23;
    if ( occurances_left_23 == -1 )
      v7 = 10;
    occurances_left_23 = v7 - 1;
    if ( v7 )
    {
      HIBYTE(message_id) = 0;
      vostok::debug::on_error(
        (bool *)&message_id + 3,
        process_error_false,
        (bool *)"found != m_important_messages.end()",
        ".\\messaging_client_process_messagess.cpp",
        "survarium::messaging_client::read_important_message",
        (const char *)0xDC);
      if ( vostok::debug::is_debugger_present() || HIBYTE(message_id) )
        __debugbreak();
    }
  }
}
