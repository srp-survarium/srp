void __thiscall survarium::messaging_client::update_channel_subscriptions(
        survarium::messaging_client *this,
        _DWORD *a2)
{
  _DWORD *v2; // ebx
  int v3; // esi
  int v4; // eax
  int v5; // eax
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network::tcp_packet_client *v8; // ecx
  vostok::network_core::buffer_writer *v9; // ecx
  vostok::network_core::mutable_buffer *v10; // ecx
  vostok::network_core::tcp_packet v11; // [esp+Ch] [ebp-50h] BYREF
  _DWORD v12[10]; // [esp+34h] [ebp-28h] BYREF

  v2 = a2;
  if ( a2[34] == 3 )
  {
    v3 = a2[87];
    memset(v12, 0, 0x24u);
    v4 = a2[104];
    v12[2] = -1;
    v12[1] = v4;
    v5 = a2[86];
    v12[4] = 1;
    v12[5] = v5 != -1 ? v5 : 0;
    if ( v3 != 3 && v5 != -1 )
      v12[(v3 != 0) + 6] = v5;
    vostok::network_core::tcp_packet::tcp_packet(
      (vostok::network_core::tcp_packet *)&vostok::memory::g_mt_allocator,
      (int)&v11);
    HIBYTE(a2) = -59;
    vostok::network_core::buffer_writer::w(
      v6,
      &v11.m_writer.serialization_operations_descriptors.m_size,
      (unsigned __int8 *)&a2 + 3,
      1u);
    vostok::network_core::buffer_writer::w(
      v7,
      &v11.m_writer.serialization_operations_descriptors.m_size,
      (unsigned __int8 *)v12,
      0x24u);
    vostok::network::tcp_packet_client::send(v8, (const vostok::network_core::tcp_packet *)(v2 + 36), &v11);
    vostok::network_core::buffer_writer::~buffer_writer(v9, &v11.m_writer.serialization_operations_descriptors);
    vostok::network_core::mutable_buffer::~mutable_buffer(v10, &v11);
  }
}
