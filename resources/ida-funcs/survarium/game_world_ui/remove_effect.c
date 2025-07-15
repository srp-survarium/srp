void __thiscall survarium::game_world_ui::remove_effect(
        survarium::game_world_ui *this,
        const survarium::hud_effects_enum effect_id,
        unsigned int value)
{
  Scaleform::GFx::Value pargs; // [esp+8h] [ebp-18h] BYREF

  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_value::SetUInt((survarium::flash_value *)this, (int)&pargs, value);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(effect_id + 8) + 264) + 4),
    "root.remove_effect",
    0,
    &pargs,
    1u);
  Scaleform::GFx::Value::~Value(&pargs);
}
