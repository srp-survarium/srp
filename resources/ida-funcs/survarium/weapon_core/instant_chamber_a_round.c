void __usercall survarium::weapon_core::instant_chamber_a_round(survarium::weapon_core *this@<ecx>, int *a2@<esi>)
{
  int v2; // eax
  int v3; // eax

  --*((_WORD *)a2 + 551);
  v2 = *a2;
  *((_BYTE *)a2 + 1112) = 1;
  (*(void (__thiscall **)(int *))(v2 + 172))(a2);
  v3 = *(_DWORD *)(a2[2] + 752);
  if ( (v3 & 0x20) == 0 || (v3 & 0x40) != 0 )
    survarium::weapon_core::reset_fire_queue((survarium::weapon_core *)(*(_DWORD *)(a2[2] + 752) >> 5));
}
