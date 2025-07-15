void __thiscall survarium::game_world_ui::reset_map_rotatable(survarium::game_world_ui *this, int a2)
{
  Scaleform::GFx::Value pargs; // [esp+8h] [ebp-1Ch] BYREF

  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_value::SetBoolean((survarium::flash_value *)this, (int)&pargs, !is_ui_minimap_fixed);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 8) + 264) + 4),
    "root.set_rotable",
    0,
    &pargs,
    1u);
  is_ui_minimap_fixed_old = is_ui_minimap_fixed;
  Scaleform::GFx::Value::~Value(&pargs);
}
