unsigned int __fastcall vostok::network_core::packet_reader::r<unsigned int>(
        vostok::network_core::packet_reader *this,
        int a2)
{
  unsigned int *v2; // ecx
  unsigned int result; // eax

  v2 = *(unsigned int **)(a2 + 4);
  result = *v2;
  *(_DWORD *)(a2 + 4) = v2 + 1;
  return result;
}
