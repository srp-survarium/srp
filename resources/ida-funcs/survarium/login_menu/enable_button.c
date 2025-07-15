void __thiscall survarium::login_menu::enable_button(survarium::login_menu *this, int value, bool valuea)
{
  Scaleform::GFx::Value v3; // [esp+8h] [ebp-18h] BYREF

  v3.pObjectInterface = 0;
  v3.Type = VT_Undefined;
  survarium::flash_value::SetBoolean((survarium::flash_value *)this, (int)&v3, valuea);
  Scaleform::GFx::Movie::SetVariable(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(value + 252) + 264) + 4),
    "root.sign_in_btn.enabled",
    &v3,
    SV_Sticky);
  Scaleform::GFx::Value::~Value(&v3);
}
