void __thiscall Scaleform::GFx::TextField::SetHtml(Scaleform::GFx::TextField *this, bool v)
{
  if ( v )
    this->Flags |= 2u;
  else
    this->Flags &= ~2u;
}
