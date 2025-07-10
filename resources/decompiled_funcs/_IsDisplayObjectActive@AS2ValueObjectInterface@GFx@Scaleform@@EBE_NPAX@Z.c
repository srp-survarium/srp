BOOL __thiscall Scaleform::GFx::AS2ValueObjectInterface::IsDisplayObjectActive(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata)
{
  return Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot) != 0;
}
