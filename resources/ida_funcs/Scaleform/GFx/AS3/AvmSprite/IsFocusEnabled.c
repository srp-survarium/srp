int __thiscall Scaleform::GFx::AS3::AvmSprite::IsFocusEnabled(
        Scaleform::GFx::AS3::AvmSprite *this,
        Scaleform::GFx::FocusMovedType fmt)
{
  if ( fmt == GFx_FocusMovedByMouse )
    return (this->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Flags
          & 1) != 0
        || this->IsStage(this);
  if ( fmt == GFx_FocusMovedByAS )
    return 1;
  else
    return ((int (__thiscall *)(Scaleform::GFx::AS3::AvmSprite *))this->Bind)(this);
}


bool __thiscall Scaleform::GFx::AS3::AvmSprite::IsFocusEnabled(char *this, Scaleform::GFx::FocusMovedType a2)
{
  return Scaleform::GFx::AS3::AvmSprite::IsFocusEnabled((Scaleform::GFx::AS3::AvmSprite *)(this - 8), a2);
}


bool __thiscall Scaleform::GFx::AS3::AvmSprite::IsFocusEnabled(char *this, Scaleform::GFx::FocusMovedType a2)
{
  return Scaleform::GFx::AS3::AvmSprite::IsFocusEnabled((Scaleform::GFx::AS3::AvmSprite *)(this - 12), a2);
}
