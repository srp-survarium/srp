void __thiscall survarium::game_world_ui::show_oxygene(survarium::game_world_ui *this, int b_show, bool value)
{
  Scaleform::GFx::Value pargs; // [esp+8h] [ebp-18h] BYREF

  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_value::SetBoolean((survarium::flash_value *)this, (int)&pargs, value);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(b_show + 8) + 264) + 4),
    "root.show_oxygen",
    0,
    &pargs,
    1u);
  Scaleform::GFx::Value::~Value(&pargs);
}
