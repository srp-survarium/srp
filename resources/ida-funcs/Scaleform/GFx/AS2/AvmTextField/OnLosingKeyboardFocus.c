bool __thiscall Scaleform::GFx::AS2::AvmTextField::OnLosingKeyboardFocus(
        char *this,
        Scaleform::GFx::InteractiveObject *a2,
        unsigned int a3,
        Scaleform::GFx::FocusMovedType a4)
{
  return Scaleform::GFx::AS2::AvmSprite::OnLosingKeyboardFocus(
           (Scaleform::GFx::AS3::AvmButton *)(this - 24),
           a2,
           a3,
           a4);
}
