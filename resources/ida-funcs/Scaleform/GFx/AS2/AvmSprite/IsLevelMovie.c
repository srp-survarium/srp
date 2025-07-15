BOOL __thiscall Scaleform::GFx::AS2::AvmSprite::IsLevelMovie(Scaleform::GFx::AS2::AvmSprite *this)
{
  return *((_DWORD *)&this->ASEnvironment.ThrowingValue.NV + 3) >= 0;
}
