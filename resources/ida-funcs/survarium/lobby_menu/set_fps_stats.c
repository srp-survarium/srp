void __thiscall survarium::lobby_menu::set_fps_stats(survarium::lobby_menu *this, float fps, float a3)
{
  Scaleform::GFx::Value pargs; // [esp+4h] [ebp-18h] BYREF

  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_value::SetUInt((survarium::flash_value *)this, (int)&pargs, (unsigned __int16)(int)a3);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(LODWORD(fps) + 1600) + 264) + 4),
    "root.set_fps",
    0,
    &pargs,
    1u);
  Scaleform::GFx::Value::~Value(&pargs);
}
