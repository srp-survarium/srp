unsigned __int16 __fastcall vostok::network_core::packet_reader::r<unsigned short>(
        vostok::network_core::packet_reader *this,
        int a2)
{
  unsigned __int16 *v2; // ecx
  unsigned __int16 result; // ax

  v2 = *(unsigned __int16 **)(a2 + 4);
  result = *v2;
  *(_DWORD *)(a2 + 4) = v2 + 1;
  return result;
}
