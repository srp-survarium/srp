void __usercall survarium::lobby_menu::fill_service_prices(survarium::lobby_menu *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  int v3; // eax
  survarium::flash_value reroll_cost_value; // [esp+0h] [ebp-1Ch] BYREF

  v2 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 168) + 952) + 60))(*(_DWORD *)(*(_DWORD *)(a2 + 168) + 952));
  *(_DWORD *)&reroll_cost_value.body[4] = 0;
  *(_DWORD *)reroll_cost_value.body = 0;
  *(_DWORD *)&reroll_cost_value.body[8] = *(_DWORD *)(v2 + 2144);
  v3 = *(_DWORD *)(a2 + 212);
  *(_DWORD *)&reroll_cost_value.body[4] = 4;
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(v3 + 264) + 4),
    "root.set_reroll_cost",
    0,
    (const Scaleform::GFx::Value *)&reroll_cost_value,
    1u);
  if ( (reroll_cost_value.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)reroll_cost_value.body + 8))(
      *(_DWORD *)reroll_cost_value.body,
      &reroll_cost_value,
      *(_DWORD *)&reroll_cost_value.body[8]);
}
