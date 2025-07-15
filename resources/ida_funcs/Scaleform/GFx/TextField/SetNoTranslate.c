void __thiscall Scaleform::GFx::TextField::SetNoTranslate(Scaleform::GFx::TextField *this, bool v)
{
  if ( v )
    this->Flags |= 8u;
  else
    this->Flags &= ~8u;
}
