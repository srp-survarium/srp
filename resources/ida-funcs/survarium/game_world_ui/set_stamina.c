void __userpurge survarium::game_world_ui::set_stamina(
        survarium::game_world_ui *this@<ecx>,
        float a2@<xmm0>,
        float thisa)
{
  Scaleform::GFx::Value pargs; // [esp+Ch] [ebp-1Ch] BYREF

  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_value::SetNumber((survarium::flash_value *)this, (int)&pargs, a2 * 0.0099999998);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(LODWORD(thisa) + 8) + 264) + 4),
    "root.set_stamina",
    0,
    &pargs,
    1u);
  Scaleform::GFx::Value::~Value(&pargs);
}
