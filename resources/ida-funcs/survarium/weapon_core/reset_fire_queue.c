void __usercall survarium::weapon_core::reset_fire_queue(survarium::weapon_core *this@<ecx>, int a2@<eax>)
{
  unsigned __int8 v2; // cl
  bool v3; // zf
  __int16 v4; // dx
  unsigned __int16 v5; // dx

  v2 = *(_BYTE *)(*(unsigned __int8 *)(a2 + 1106) + *(_DWORD *)(a2 + 1096));
  if ( v2 == 0xFF )
  {
    v3 = *(_BYTE *)(a2 + 1112) == 0;
    v4 = *(_WORD *)(a2 + 1102);
    *(_WORD *)(a2 + 1104) = v4;
    if ( !v3 )
      *(_WORD *)(a2 + 1104) = v4 + 1;
  }
  else
  {
    v5 = *(_WORD *)(a2 + 1102) + (*(_BYTE *)(a2 + 1112) != 0);
    *(_WORD *)(a2 + 1104) = v5 + (v2 < v5 ? v2 - v5 : 0);
  }
}
