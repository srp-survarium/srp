void __thiscall survarium::lobby_menu::set_total_players_count(
        survarium::lobby_menu *this,
        unsigned int count,
        unsigned int value)
{
  Scaleform::GFx::Value pargs; // [esp+8h] [ebp-18h] BYREF

  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_value::SetUInt((survarium::flash_value *)this, (int)&pargs, value);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(count + 1600) + 264) + 4),
    "root.ranking_set_players_total_count",
    0,
    &pargs,
    1u);
  Scaleform::GFx::Value::~Value(&pargs);
}
