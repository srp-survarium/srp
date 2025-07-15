char __thiscall Scaleform::GFx::InteractiveObject::IsFocusRectEnabled(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::InteractiveObject *v3; // eax

  if ( (this->Flags & 0x180) != 0 )
    return (this->Flags & 0x180) == 384;
  v3 = this->GetTopParent(this, 1);
  return !v3 || v3 == this || v3->IsFocusRectEnabled(v3);
}
