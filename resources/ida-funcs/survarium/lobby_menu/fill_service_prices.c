void __thiscall survarium::lobby_menu::fill_service_prices(survarium::lobby_menu *this, int a2)
{
  survarium::service_prices *p_m_service_prices; // edi
  survarium::flash_value *v3; // ecx
  survarium::flash_value *v4; // ecx
  Scaleform::GFx::Value pargs; // [esp+10h] [ebp-1Ch] BYREF

  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  p_m_service_prices = &survarium::lobby_menu::lobby_client(this, a2)->m_service_prices;
  survarium::flash_value::SetUInt(v3, (int)&pargs, p_m_service_prices->reroll_cost);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 1600) + 264) + 4),
    "root.set_reroll_cost",
    0,
    &pargs,
    1u);
  survarium::flash_value::SetUInt(v4, (int)&pargs, p_m_service_prices->add_profile_cost);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 1600) + 264) + 4),
    "root.set_profile_cost",
    0,
    &pargs,
    1u);
  Scaleform::GFx::Value::~Value(&pargs);
}
