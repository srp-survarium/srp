void __usercall survarium::lobby_client::~lobby_client(survarium::lobby_client *this@<ecx>, int a2@<eax>)
{
  survarium::lobby_client *v3; // ecx
  int v4; // eax
  int v5; // eax
  void (__cdecl *v6)(int, int, int); // eax
  int v7; // eax
  void (__cdecl *v8)(int, int, int); // eax
  int v9; // eax
  void (__cdecl *v10)(int, int, int); // eax

  survarium::lobby_client::clear_initial_info(this, a2);
  survarium::lobby_client::clear_profile_info(v3, a2);
  v4 = *(_DWORD *)(a2 + 2140);
  if ( v4 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v4 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 2140) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 2140));
  if ( *(_DWORD *)(a2 + 1928) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 1936) + 24))(
      *(_DWORD *)(a2 + 1936),
      *(_DWORD *)(a2 + 1928));
  v5 = *(_DWORD *)(a2 + 368);
  if ( v5 )
  {
    if ( (v5 & 1) == 0 )
    {
      v6 = *(void (__cdecl **)(int, int, int))(v5 & 0xFFFFFFFE);
      if ( v6 )
        v6(a2 + 376, a2 + 376, 2);
    }
    *(_DWORD *)(a2 + 368) = 0;
  }
  v7 = *(_DWORD *)(a2 + 336);
  if ( v7 )
  {
    if ( (v7 & 1) == 0 )
    {
      v8 = *(void (__cdecl **)(int, int, int))(v7 & 0xFFFFFFFE);
      if ( v8 )
        v8(a2 + 344, a2 + 344, 2);
    }
    *(_DWORD *)(a2 + 336) = 0;
  }
  v9 = *(_DWORD *)(a2 + 304);
  if ( v9 )
  {
    if ( (v9 & 1) == 0 )
    {
      v10 = *(void (__cdecl **)(int, int, int))(v9 & 0xFFFFFFFE);
      if ( v10 )
        v10(a2 + 312, a2 + 312, 2);
    }
    *(_DWORD *)(a2 + 304) = 0;
  }
  vostok::network::tcp_packet_client::~tcp_packet_client((vostok::network::tcp_packet_client *)(a2 + 168));
}
