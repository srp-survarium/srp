int __usercall survarium::weapon_core::reload_break_pred@<eax>(survarium::weapon_core *this@<ecx>, int a2@<eax>)
{
  int v2; // ecx
  int result; // eax

  if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 304) + 24) + 32) == 3 )
    return 1;
  v2 = *(_DWORD *)(a2 + 8);
  result = 0;
  if ( !*(_BYTE *)(v2 + 764) )
    return 1;
  return result;
}
