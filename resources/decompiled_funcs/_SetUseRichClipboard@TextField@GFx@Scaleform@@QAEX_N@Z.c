void __thiscall Scaleform::GFx::TextField::SetUseRichClipboard(Scaleform::GFx::TextField *this, bool v)
{
  if ( v )
    this->Flags |= 0x100u;
  else
    this->Flags &= ~0x100u;
}
