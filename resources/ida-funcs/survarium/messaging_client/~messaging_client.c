void __usercall survarium::messaging_client::~messaging_client(survarium::messaging_client *this@<ecx>, int a2@<esi>)
{
  if ( *(_DWORD *)(a2 + 352) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 360) + 24))(
      *(_DWORD *)(a2 + 360),
      *(_DWORD *)(a2 + 352));
  if ( *(_DWORD *)(a2 + 336) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 344) + 24))(
      *(_DWORD *)(a2 + 344),
      *(_DWORD *)(a2 + 336));
  if ( *(_DWORD *)(a2 + 320) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 328) + 24))(
      *(_DWORD *)(a2 + 328),
      *(_DWORD *)(a2 + 320));
  vostok::network::tcp_packet_client::~tcp_packet_client((vostok::network::tcp_packet_client *)(a2 + 144));
}
