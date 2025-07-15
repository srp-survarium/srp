bool __thiscall Scaleform::GFx::AS3::AvmTextField::IsFocusEnabled(
        Scaleform::GFx::AS3::AvmTextField *this,
        Scaleform::GFx::FocusMovedType fmt)
{
  return fmt != GFx_FocusMovedByKeyboard
      || (unsigned __int8)Scaleform::GFx::TextField::IsReadOnly(*(Scaleform::GFx::TextField **)&this[-1].Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Flags) == 0;
}


bool __thiscall Scaleform::GFx::AS3::AvmTextField::IsFocusEnabled(char *this, Scaleform::GFx::FocusMovedType a2)
{
  return Scaleform::GFx::AS3::AvmTextField::IsFocusEnabled((Scaleform::GFx::AS3::AvmTextField *)(this - 8), a2);
}
