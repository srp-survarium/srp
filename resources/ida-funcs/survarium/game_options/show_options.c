void __thiscall survarium::game_options::show_options(survarium::game_options *this, int b_val, bool value)
{
  Scaleform::GFx::Value pargs; // [esp+8h] [ebp-18h] BYREF

  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_value::SetBoolean((survarium::flash_value *)this, (int)&pargs, value);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(b_val + 12) + 264) + 4),
    "root.show_settings",
    0,
    &pargs,
    1u);
  Scaleform::GFx::Value::~Value(&pargs);
}
