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
