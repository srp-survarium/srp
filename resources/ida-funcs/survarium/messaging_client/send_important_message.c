void __thiscall survarium::messaging_client::send_important_message(
        survarium::messaging_client *this,
        const char (*receiver_name)[64],
        int type,
        const char *text,
        char *_Src)
{
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network_core::buffer_writer *v8; // ecx
  vostok::network_core::buffer_writer *v9; // ecx
  vostok::network::tcp_packet_client *v10; // ecx
  vostok::network_core::buffer_writer *v11; // ecx
  vostok::network_core::mutable_buffer *v12; // ecx
  char _Dst[256]; // [esp+8h] [ebp-128h] BYREF
  vostok::network_core::tcp_packet v14; // [esp+108h] [ebp-28h] BYREF

  strcpy_s(_Dst, 0x100u, _Src);
  vostok::network_core::tcp_packet::tcp_packet(
    (vostok::network_core::tcp_packet *)&vostok::memory::g_mt_allocator,
    (int)&v14);
  HIBYTE(_Src) = -62;
  vostok::network_core::buffer_writer::w(
    v5,
    &v14.m_writer.serialization_operations_descriptors.m_size,
    (unsigned __int8 *)&_Src + 3,
    1u);
  _Src = 0;
  vostok::network_core::buffer_writer::w(
    v6,
    &v14.m_writer.serialization_operations_descriptors.m_size,
    (unsigned __int8 *)&_Src,
    4u);
  vostok::network_core::buffer_writer::w_string(v7, (char *)&v14.m_writer, type);
  HIBYTE(_Src) = (_BYTE)text;
  vostok::network_core::buffer_writer::w(
    v8,
    &v14.m_writer.serialization_operations_descriptors.m_size,
    (unsigned __int8 *)&_Src + 3,
    1u);
  vostok::network_core::buffer_writer::w_string(v9, (char *)&v14.m_writer, (int)_Dst);
  vostok::network::tcp_packet_client::send(v10, (const vostok::network_core::tcp_packet *)&(*receiver_name)[144], &v14);
  vostok::network_core::buffer_writer::~buffer_writer(v11, &v14.m_writer.serialization_operations_descriptors);
  vostok::network_core::mutable_buffer::~mutable_buffer(v12, &v14);
}
