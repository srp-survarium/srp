void __usercall vostok::animation::animation_player::animation_player(
        vostok::animation::animation_player *this@<ecx>,
        int a2@<eax>)
{
  *(int *)((char *)&_sbh_sizeHeaderList.unused + a2) = 0;
  *(_DWORD *)(a2 + 65568) = 0;
  *(_DWORD *)&byte_10040[a2] = 0;
  *(_DWORD *)(a2 + 65632) = 0;
  *(_DWORD *)(a2 + 65664) = 0;
  *(_DWORD *)(a2 + 65696) = 0;
  *(_DWORD *)(a2 + 65728) = 0;
  *(_DWORD *)(a2 + 65732) = a2 + 0x8000;
  *(_DWORD *)(a2 + 65736) = 0;
  *(_DWORD *)(a2 + 65740) = a2 + 65752;
  *(_DWORD *)(a2 + 65744) = 2560;
  *(_WORD *)(a2 + 65748) = 0;
  *(_BYTE *)(a2 + 65750) = 1;
  *(_BYTE *)(a2 + 65751) = 0;
}
