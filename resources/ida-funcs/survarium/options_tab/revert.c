void __usercall survarium::options_tab::revert(survarium::options_tab *this@<ecx>, int a2@<esi>)
{
  unsigned __int8 i; // bl
  int v3; // ecx

  for ( i = 0; i < *(_BYTE *)(a2 + 4); ++i )
  {
    v3 = *(_DWORD *)(*(_DWORD *)a2 + 4 * i);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 20))(v3);
  }
}
