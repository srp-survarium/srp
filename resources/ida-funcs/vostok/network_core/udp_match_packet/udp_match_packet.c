void __usercall vostok::network_core::udp_match_packet::udp_match_packet(
        vostok::network_core::udp_match_packet *this@<ecx>,
        int a2@<eax>)
{
  *(_BYTE *)(a2 + 16) = -1;
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 52) = 0;
  *(_DWORD *)(a2 + 44) = a2 + 40;
  *(_DWORD *)(a2 + 48) = a2 + 40;
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 64) = -1;
  *(_DWORD *)(a2 + 68) = -1;
  *(_DWORD *)(a2 + 60) = 0;
  *(_DWORD *)(a2 + 92) = 0;
  *(_DWORD *)(a2 + 96) = 0;
  *(_WORD *)(a2 + 100) = -1;
  *(_WORD *)(a2 + 104) = -1;
  *(_BYTE *)(a2 + 106) = 0;
  *(_BYTE *)(a2 + 103) = -1;
  *(_BYTE *)(a2 + 107) = 63;
  *(_DWORD *)(a2 + 1324) = 0;
  *(_DWORD *)(a2 + 1332) = 1214;
  *(_DWORD *)(a2 + 1336) = 12;
  *(_DWORD *)(a2 + 1328) = a2 + 108;
  *(_DWORD *)(a2 + 1340) = 0;
  *(_DWORD *)(a2 + 1348) = 0;
  *(_DWORD *)(a2 + 1352) = 0;
  *(_BYTE *)(a2 + 1356) = -1;
  *(_DWORD *)(a2 + 1360) = a2 + 1324;
  **(_BYTE **)(a2 + 1328) = 0;
}
