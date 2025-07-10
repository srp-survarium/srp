bool __thiscall Scaleform::GFx::AS2::AvmSprite::CheckCandidateListLevel(
        Scaleform::GFx::AS2::AvmSprite *this,
        int level)
{
  return *((_DWORD *)&this->ASEnvironment.ThrowingValue.NV + 3) == level;
}
