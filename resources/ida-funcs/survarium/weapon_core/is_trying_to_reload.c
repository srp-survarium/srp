BOOL __usercall survarium::weapon_core::is_trying_to_reload@<eax>(survarium::weapon_core *this@<ecx>, int a2@<eax>)
{
  return (*(_DWORD *)(*(_DWORD *)(a2 + 8) + 752) & 0x80) != 0
      || (*(_DWORD *)(*(_DWORD *)(a2 + 8) + 752) & 0x20) != 0 && !(*(_WORD *)(a2 + 1102) + (*(_BYTE *)(a2 + 1112) != 0))
      || *(_BYTE *)(a2 + 1116);
}
