bool __thiscall Scaleform::GFx::AS2::AvmTextField::IsFocusEnabled(
        Scaleform::GFx::AS2::AvmTextField *this,
        Scaleform::GFx::FocusMovedType fmt)
{
  if ( fmt != GFx_FocusMovedByMouse )
    return 1;
  return !(unsigned __int8)Scaleform::GFx::TextField::IsReadOnly((Scaleform::GFx::TextField *)this->pDispObj)
      || Scaleform::GFx::TextField::IsSelectable((Scaleform::GFx::TextField *)this->pDispObj);
}


bool __thiscall Scaleform::GFx::AS2::AvmTextField::IsFocusEnabled(char *this, Scaleform::GFx::FocusMovedType a2)
{
  return Scaleform::GFx::AS2::AvmTextField::IsFocusEnabled((Scaleform::GFx::AS2::AvmTextField *)(this - 24), a2);
}
