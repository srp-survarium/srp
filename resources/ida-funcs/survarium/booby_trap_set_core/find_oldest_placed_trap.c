survarium::booby_trap_core *__usercall survarium::booby_trap_set_core::find_oldest_placed_trap@<eax>(
        survarium::booby_trap_set_core *this@<ecx>,
        int a2@<eax>)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  int v5; // eax
  int v6; // esi
  bool v7; // zf
  bool v8; // cl

  v2 = *(_DWORD *)(a2 + 292);
  v3 = *(_DWORD *)(a2 + 288);
  if ( v3 != v2 )
  {
    v4 = v3;
    v5 = v3 + 4;
    if ( v5 != v2 )
    {
      while ( 1 )
      {
        v6 = *(_DWORD *)(*(_DWORD *)v5 + 408);
        v7 = v6 == 0;
        if ( !v6 )
          goto LABEL_7;
        if ( !*(_DWORD *)(*(_DWORD *)v4 + 408) )
          break;
        v8 = *(_DWORD *)(*(_DWORD *)v5 + 492) < *(_DWORD *)(*(_DWORD *)v4 + 492);
LABEL_8:
        if ( v8 )
          v4 = v5;
        v5 += 4;
        if ( v5 == v2 )
          goto LABEL_11;
      }
      v7 = v6 == 0;
LABEL_7:
      v8 = !v7;
      goto LABEL_8;
    }
LABEL_11:
    v3 = v4;
  }
  return *(_DWORD *)(*(_DWORD *)v3 + 408) != 0 ? *(survarium::booby_trap_core **)v3 : 0;
}
