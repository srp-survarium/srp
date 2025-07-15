void __usercall survarium::inventory::drop_carried_item(survarium::inventory *this@<ecx>, int a2@<eax>)
{
  int v2; // ecx
  int v3; // ecx

  v2 = *(_DWORD *)(a2 + 4 * *(_DWORD *)(a2 + 372) + 272);
  if ( v2 )
    v3 = v2 - 16;
  else
    v3 = 0;
  (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(a2 + 376) + 4))(*(_DWORD *)(a2 + 376), v3);
}
