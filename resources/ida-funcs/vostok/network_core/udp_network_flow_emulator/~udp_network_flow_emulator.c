void __usercall vostok::network_core::udp_network_flow_emulator::~udp_network_flow_emulator(
        vostok::network_core::udp_network_flow_emulator *this@<ecx>,
        int a2@<esi>)
{
  _DWORD *v2; // eax
  bool v3; // zf
  _DWORD *v4; // ecx
  int v5; // eax
  _DWORD *v6; // edx
  _DWORD *v7; // edi
  _DWORD *v8; // eax
  _DWORD *v9; // [esp+8h] [ebp-8h]
  _DWORD *v10; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD **)a2;
  v9 = *(_DWORD **)(a2 + 4);
  v3 = *(_DWORD *)a2 == (_DWORD)v9;
  while ( 1 )
  {
    v10 = v2;
    if ( v3 )
      break;
    v4 = (_DWORD *)(*v2 + 36);
    v5 = *v2 + 40;
    v6 = *(_DWORD **)v5;
    if ( *(_DWORD *)v5 )
    {
      do
      {
        v7 = (_DWORD *)v6[1];
        if ( v7 )
        {
          v6[1] = v7[2];
          v7[2] = v6;
        }
        else
        {
          v7 = (_DWORD *)v6[2];
          *v6 = 0;
          v6[1] = 0;
          v6[2] = 0;
        }
        v6 = v7;
      }
      while ( v7 );
      *(_DWORD *)v5 = 0;
      *(_DWORD *)(v5 + 4) = v5;
      *(_DWORD *)(v5 + 8) = v5;
    }
    *(_DWORD *)v5 = 0;
    *(_DWORD *)(v5 + 4) = v5;
    *(_DWORD *)(v5 + 8) = v5;
    *(_DWORD *)(v5 + 12) = 0;
    v2 = v10 + 9;
    v3 = v10 + 9 == v9;
    *v4 = 0;
  }
  while ( 1 )
  {
    v8 = *(_DWORD **)a2;
    if ( *(_DWORD *)a2 == *(_DWORD *)(a2 + 4) )
      break;
    vostok::network_core::delete_udp_match_packet(
      *(vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> **)(a2 + 28),
      (vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node **)(*(_DWORD *)(a2 + 4)
                                                                                                - 36));
    *(_DWORD *)(a2 + 4) -= 36;
  }
  if ( v8 )
    (*(void (__thiscall **)(_DWORD, _DWORD *, const char *, const char *, int))(**(_DWORD **)(a2 + 8) + 24))(
      *(_DWORD *)(a2 + 8),
      v8,
      "vostok::detail::std_allocator<struct stlp_std::pair<class vostok::network_core::udp_match_packet *,struct stlp_std"
      "::pair<class boost::asio::ip::basic_endpoint<class boost::asio::ip::udp>,struct vostok::network_core::socket_handl"
      "er *> > >::deallocate",
      "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
      102);
}
