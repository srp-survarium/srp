int __thiscall Scaleform::GFx::AS3::AvmSprite::GetCursorType(Scaleform::GFx::AS3::AvmSprite *this)
{
  return this->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Flags
       & 1;
}


unsigned int __thiscall Scaleform::GFx::AS3::AvmSprite::GetCursorType(char *this)
{
  return Scaleform::GFx::AS3::AvmSprite::GetCursorType((Scaleform::GFx::AS3::AvmSprite *)(this - 8));
}


unsigned int __thiscall Scaleform::GFx::AS3::AvmSprite::GetCursorType(char *this)
{
  return Scaleform::GFx::AS3::AvmSprite::GetCursorType((Scaleform::GFx::AS3::AvmSprite *)(this - 12));
}
