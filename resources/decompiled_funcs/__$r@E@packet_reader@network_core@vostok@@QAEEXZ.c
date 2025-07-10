unsigned __int8 __fastcall vostok::network_core::packet_reader::r<unsigned char>(
        vostok::network_core::packet_reader *this,
        int a2)
{
  unsigned __int8 *v2; // ecx
  unsigned __int8 result; // al

  v2 = *(unsigned __int8 **)(a2 + 4);
  result = *v2;
  *(_DWORD *)(a2 + 4) = v2 + 1;
  return result;
}
