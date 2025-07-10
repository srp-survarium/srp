void __userpurge survarium::lobby_client::connect(
        survarium::lobby_client *this@<ecx>,
        int a2@<eax>,
        const vostok::server_connection_info *lobby_connection_info)
{
  int v3; // edx
  unsigned __int16 v4; // cx

  v3 = *(_DWORD *)(a2 + 156);
  qmemcpy((void *)(a2 + 36), lobby_connection_info, 0x80u);
  v4 = *(_WORD *)(a2 + 40);
  *(_DWORD *)(a2 + 156) = v3;
  vostok::network::tcp_packet_client::connect(
    (vostok::network::tcp_packet_client *)(a2 + 168),
    (const char *)(a2 + 42),
    v4);
}
