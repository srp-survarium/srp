void __thiscall Scaleform::GFx::Sprite::SetName(Scaleform::GFx::Sprite *this, const Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::DisplayObject::SetName(this, (int)name);
  this->mDisplayList.pCachedChar = 0;
}
