char *__userpurge vostok::network_core::packet_reader::r_string<16>@<eax>(
        vostok::network_core::packet_reader *this@<ecx>,
        int a2@<esi>,
        char (*string)[16])
{
  unsigned __int8 *v3; // eax
  unsigned int v4; // edi

  v3 = *(unsigned __int8 **)(a2 + 4);
  v4 = *v3;
  *(_DWORD *)(a2 + 4) = v3 + 1;
  memcpy((unsigned __int8 *)string, v3 + 1, v4);
  *(_DWORD *)(a2 + 4) += v4;
  (*string)[v4] = 0;
  return *string;
}
