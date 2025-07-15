void __usercall vostok::animation::animation_player::animation_player(
        vostok::animation::animation_player *this@<ecx>,
        int a2@<esi>)
{
  *(_DWORD *)(a2 + 34048) = 0;
  *(_DWORD *)(a2 + 34052) = 0;
  *(_DWORD *)(a2 + 34056) = 0;
  *(_DWORD *)(a2 + 34060) = 0;
  *(_DWORD *)(a2 + 34064) = 0;
  *(_DWORD *)(a2 + 34068) = 0;
  *(_DWORD *)(a2 + 34072) = 0;
  *(_DWORD *)(a2 + 34076) = 0;
  *(_DWORD *)(a2 + 34080) = 0;
  *(_DWORD *)(a2 + 34084) = 0;
  *(_DWORD *)(a2 + 34088) = 0;
  *(_BYTE *)(a2 + 34092) = 0;
  *(_DWORD *)(a2 + 34096) = a2 + 0x4000;
  *(_DWORD *)(a2 + 34100) = 0;
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    (vostok::mutable_buffer *)(a2 + 34104),
    (unsigned __int8 *)(a2 + 0x8000),
    0x500u);
  *(_DWORD *)(a2 + 34112) = 0;
  *(_BYTE *)(a2 + 34119) = 0;
  *(_WORD *)(a2 + 34116) = 0;
  *(_BYTE *)(a2 + 34118) = 1;
}
