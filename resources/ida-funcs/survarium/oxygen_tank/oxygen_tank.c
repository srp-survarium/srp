void __usercall survarium::oxygen_tank::oxygen_tank(survarium::oxygen_tank *this@<ecx>, int a2@<eax>)
{
  survarium::inventory_item::inventory_item(this, a2, use_silent, 1);
  *(_DWORD *)(a2 + 288) = &survarium::tickable_object::`vftable';
  *(_DWORD *)(a2 + 288) = &survarium::oxygen_tank::`vftable'{for `survarium::tickable_object'};
  *(_BYTE *)(a2 + 300) = 0;
  *(_DWORD *)(a2 + 304) = 0;
  *(_DWORD *)(a2 + 308) = 0;
  *(_DWORD *)(a2 + 312) = 0;
  *(_DWORD *)a2 = &survarium::oxygen_tank::`vftable'{for `survarium::inventory_item'};
}
