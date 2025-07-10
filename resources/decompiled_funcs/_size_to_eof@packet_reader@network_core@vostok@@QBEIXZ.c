int __fastcall vostok::network_core::packet_reader::size_to_eof(vostok::network_core::packet_reader *this, _DWORD *a2)
{
  return *(_DWORD *)*a2 + *(_DWORD *)(*a2 + 4) - a2[1];
}
