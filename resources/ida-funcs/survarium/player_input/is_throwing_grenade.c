BOOL __usercall survarium::player_input::is_throwing_grenade@<eax>(survarium::player_input *this@<ecx>, int a2@<eax>)
{
  int v2; // eax

  v2 = *(_DWORD *)(a2 + 8);
  return (v2 & 0x2000000) != 0
      || this == (survarium::player_input *)13 && (v2 & 0x8000) != 0
      || this == (survarium::player_input *)14 && ((unsigned int)&_sbh_sizeHeaderList & v2) != 0
      || this == (survarium::player_input *)15 && ((unsigned int)&loc_20000 & v2) != 0
      || this == (survarium::player_input *)16 && (((unsigned int)&loc_3FFFF + 1) & v2) != 0
      || this == (survarium::player_input *)17 && (v2 & 0x80000) != 0
      || this == (survarium::player_input *)18 && ((unsigned int)&loc_100000 & v2) != 0;
}
