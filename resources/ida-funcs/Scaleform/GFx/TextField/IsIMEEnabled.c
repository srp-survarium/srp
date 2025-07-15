BOOL __thiscall Scaleform::GFx::TextField::IsIMEEnabled(Scaleform::GFx::TextField *this)
{
  return (this->Flags & 0x800) == 0
      && !(unsigned __int8)Scaleform::GFx::TextField::IsReadOnly(this)
      && (this->Flags & 4) == 0;
}
