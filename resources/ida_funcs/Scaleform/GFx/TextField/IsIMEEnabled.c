BOOL __thiscall Scaleform::GFx::TextField::IsIMEEnabled(Scaleform::GFx::TextField *this)
{
  return (this->Flags & 0x800) == 0 && !Scaleform::GFx::TextField::IsReadOnly(this) && (this->Flags & 4) == 0;
}
