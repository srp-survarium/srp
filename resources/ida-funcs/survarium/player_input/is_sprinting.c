BOOL __usercall survarium::player_input::is_sprinting@<eax>(survarium::player_input *this@<ecx>, int a2@<eax>)
{
  int v2; // eax

  v2 = *(_DWORD *)(a2 + 8);
  return (v2 & 0x400) != 0 && (v2 & 1) != 0 && (v2 & 0x222) == 0;
}
