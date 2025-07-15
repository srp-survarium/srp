// attributes: thunk
char __thiscall Scaleform::GFx::AS2::AvmButton::IsTabable(Scaleform::GFx::AS2::AvmButton *this)
{
  return Scaleform::GFx::AS2::AvmCharacter::IsTabable(this);
}


char __thiscall Scaleform::GFx::AS2::AvmButton::IsTabable(char *this)
{
  return Scaleform::GFx::AS2::AvmButton::IsTabable((Scaleform::GFx::AS2::AvmButton *)(this - 24));
}
