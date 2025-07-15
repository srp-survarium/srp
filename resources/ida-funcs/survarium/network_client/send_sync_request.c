void __usercall survarium::network_client::send_sync_request(survarium::network_client *this@<ecx>, int a2@<eax>)
{
  vostok::network_core::udp_match_packet *v3; // ebx
  int buffer; // [esp+Ch] [ebp-4h] BYREF

  *(_DWORD *)(a2 + 16752) = 1000
                          * vostok::timing::timer::get_elapsed_ticks((vostok::timing::timer *)(*(_DWORD *)(a2 + 24) + 40))
                          / vostok::timing::g_qpc_per_second.QuadPart;
  v3 = vostok::network::match_client::new_packet((vostok::network::match_client *)(a2 + 2696), 0x45u);
  buffer = *(_DWORD *)(a2 + 16752);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(4u, v3, (unsigned __int8 *)&buffer);
  vostok::network::match_client::enqueue((vostok::network::match_client *)(a2 + 2696), v3);
  *(_BYTE *)(a2 + 11812) = 1;
}
