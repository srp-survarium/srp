void __usercall survarium::artefact_base::decrement_amount(survarium::artefact_base *this@<ecx>, int a2@<esi>)
{
  survarium::inventory_item *v2; // ecx

  if ( *(_WORD *)(a2 + 296) != 0xFFFF )
  {
    v2 = (survarium::inventory_item *)*(unsigned __int16 *)(a2 + 280);
    LOWORD(v2) = (_WORD)v2 - 1;
    survarium::inventory_item::set_amount(v2, a2);
  }
  if ( *(_WORD *)(a2 + 280) )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)a2 + 116))(a2);
    *(_DWORD *)(a2 + 312) = *(_DWORD *)(a2 + 288);
    *(_DWORD *)(a2 + 300) = 3;
  }
  else
  {
    survarium::inventory::remove_item(
      *(survarium::inventory **)(a2 + 272),
      *(const survarium::profile_slot_enum *)(a2 + 276));
  }
}
