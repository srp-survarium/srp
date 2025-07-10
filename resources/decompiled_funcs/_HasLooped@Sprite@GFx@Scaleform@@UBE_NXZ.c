int __thiscall Scaleform::GFx::Sprite::HasLooped(Scaleform::GFx::Sprite *this)
{
  return (this->Flags >> 1) & 1;
}
