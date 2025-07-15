// attributes: thunk
bool __thiscall Scaleform::GFx::AS3::AvmSprite::OnUnloading(Scaleform::GFx::AS3::AvmSprite *this, bool mayRemove)
{
  return Scaleform::GFx::AS3::AvmDisplayObj::OnUnloading(this, mayRemove);
}


bool __thiscall Scaleform::GFx::AS3::AvmSprite::OnUnloading(char *this, bool a2)
{
  return Scaleform::GFx::AS3::AvmSprite::OnUnloading((Scaleform::GFx::AS3::AvmSprite *)(this - 40), a2);
}
