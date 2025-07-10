int __thiscall Scaleform::GFx::AS2::AvmSprite::GetLevel(Scaleform::GFx::AS2::AvmSprite *this)
{
  return *((_DWORD *)&this->ASEnvironment.ThrowingValue.NV + 3);
}
