bool __thiscall Scaleform::GFx::AS3::AvmSprite::IsLevelMovie(Scaleform::GFx::AS3::AvmSprite *this)
{
  return this->pDispObj->pParent == 0;
}


bool __thiscall Scaleform::GFx::AS3::AvmSprite::IsLevelMovie(char *this)
{
  return Scaleform::GFx::AS3::AvmSprite::IsLevelMovie((Scaleform::GFx::AS3::AvmSprite *)(this - 40));
}
